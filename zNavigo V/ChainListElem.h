#pragma once
#include "ChainLine.h"

class ChainListElem
{
	public:
		ChainListElem();
		ChainListElem(ChainLine const& chainLine, ChainListElem* nextElem = nullptr);
		~ChainListElem();
		bool isHandler() const;
		ChainLine* chainLine() const;
		ChainListElem* nextElem() const;
		static int elemCount();
		void setChainLine(ChainLine* chainLine);
		void setNextElem(ChainListElem* nextElem);
		
	private:
		ChainLine* m_chainLine;
		ChainListElem* m_nextElem;
		bool m_isHandler;
		static int m_elemCount;
};


