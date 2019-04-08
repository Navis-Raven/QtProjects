#pragma once

#include "ChainListElem.h"

class ChainList
{
	public:
		ChainList(int max, bool autoPopOutFirstIn = true);
		~ChainList();
		bool exists(QUrl const& url);
		QAction* append(ChainLine const& chainLine);
		int remove(ChainLine chainLine);
		ChainLine popOutFirstIn();
		int max() const;
		int elemCount() const;
		ChainListElem* header() const;
		bool isVoid();

	private:
		int m_max;
		int m_elemCount;
		bool m_autoPopOutFirstIn;
		ChainListElem* m_handler;
		ChainListElem* m_header;
};

