#include "ChainListElem.h"

int ChainListElem::m_elemCount = 0;

ChainListElem::ChainListElem() : m_nextElem(nullptr), m_isHandler(true)
{
	m_chainLine = new ChainLine();
	m_elemCount = 0;
}

ChainListElem::ChainListElem(ChainLine const& chainLine, ChainListElem* nextElem) : m_nextElem(nextElem), m_isHandler(false)
{
	m_chainLine = new ChainLine(chainLine);
	m_elemCount++;
}

ChainListElem::~ChainListElem()
{
	delete m_chainLine;
	//On ne détruit surtout pas m_nextElem !
	m_elemCount--;
}

bool ChainListElem::isHandler() const
{
	return m_isHandler;
}

int ChainListElem::elemCount()
{
	return m_elemCount;
}

ChainLine* ChainListElem::chainLine() const
{
	return m_chainLine;
}

void ChainListElem::setChainLine(ChainLine* chainLine)
{
	m_chainLine = chainLine;
}

ChainListElem* ChainListElem::nextElem() const
{
	return m_nextElem;
}

void ChainListElem::setNextElem(ChainListElem* nextElem)
{
	m_nextElem = nextElem;
}
