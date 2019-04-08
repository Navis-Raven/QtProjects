#include "ChainList.h"

ChainList::ChainList(int max, bool autoPopOutFirstIn) : m_autoPopOutFirstIn(autoPopOutFirstIn)
{
	if(max < 5)
	{
		m_max = 5;
	}
	else
	{
		m_max = max;
	}

	m_handler = new ChainListElem();
	m_header = m_handler;
	m_elemCount = 0;
}


ChainList::~ChainList()
{
	while(!isVoid())
	{
		popOutFirstIn();
	}
	delete m_handler;
}

bool ChainList::exists(QUrl const& url)
{
	ChainListElem* currentElem = m_handler->nextElem();

	while (currentElem != nullptr)
	{
		if(currentElem->chainLine()->url().toString() == url.toString())
		{		
			return true;
		}
		else
		{
			currentElem = currentElem->nextElem();
		}
	}

	return false;
}

int ChainList::remove(ChainLine chainLine)
{
	ChainListElem* currentElem = m_handler->nextElem();
	ChainListElem* previousElem = m_handler;
	int removedCounter = 0;
	while(currentElem != nullptr)
	{
		if(*(currentElem->chainLine()) == chainLine)
		{
			ChainListElem* nextElem = currentElem->nextElem();
			if(currentElem == m_header) m_header = previousElem;
			previousElem->setNextElem(nextElem);
			delete currentElem;
			currentElem = nextElem;
			m_elemCount--;
			removedCounter++;
		}
		else
		{
			previousElem = currentElem;
			currentElem = currentElem->nextElem();
		}
	}

	return removedCounter;
}

ChainLine ChainList::popOutFirstIn()
{
	ChainLine retChainLine;
	
	if(!isVoid())
	{
		ChainListElem* firstIn = m_handler->nextElem();
		retChainLine = *firstIn->chainLine();
		if (firstIn == m_header) m_header = m_handler;
		ChainListElem* secondIn = firstIn->nextElem();
		
		delete firstIn;
		m_handler->setNextElem(secondIn);

		m_elemCount--;
	}

	return retChainLine;
}


int ChainList::max() const
{
	return m_max;
}

int ChainList::elemCount() const
{
	return m_elemCount;
}

ChainListElem* ChainList::header() const
{
	return m_header;
}

bool ChainList::isVoid()
{
	return (m_handler == m_header);
}

QAction* ChainList::append(ChainLine const& chainLine)
{
	remove(chainLine);

	if(m_elemCount >= m_max)
	{
		if(m_autoPopOutFirstIn)
		{
			while(m_elemCount >= m_max)
			{
				popOutFirstIn();
			}
		}
		else
		{
			return nullptr;
		}
	}


	ChainListElem* newElem = new ChainListElem(chainLine);
	
	//On remplace l'adresse du nextElem de l'ancien header 
	m_header->setNextElem(newElem);
	
	//On attribue le nouveau header
	m_header = newElem;

	m_elemCount++;

	//On retourne l'action de l'élément ajouté (surtout pas chainLine->action(), car chainLine sera détruit et son pointeur action avec)
	return m_header->chainLine()->action();
}
