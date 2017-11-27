#pragma once

#include "stdafx.h"


//拓展控件，使得 SHeaderCtrl的每一个item宽度 能够随着窗口变化而改变
class CLyricListView: public SMCListView
{
    SOUI_CLASS_NAME(LyricListView, L"lyriclistview")

protected:

	//在窗口大小发生改变时，改变每一个项的宽度
	void OnSize(UINT nType, CSize size)
	{
		SHDITEM item;
		item.mask = 0 | SHDI_TEXT| SHDI_WIDTH| SHDI_LPARAM| SHDI_SORTFLAG| SHDI_ORDER;
		//item.cchTextMax = MAX_BUFFER_SIZE/2;
		
		int count = m_pHeader->GetItemCount();
		vector<SHDITEM> items(count,item);			//存储项信息	
		
		//获取项的信息
		for(int i=0; i<count; i++)
		{
			m_pHeader->GetItem(i, &items[i]);	
			items[i].text.SetCtxProvider(this);
			items[i].text.TranslateText();		//获得执行翻译得到翻译文本
		}

		//设置修改后的各个项的宽度
		items[0].cx = 30;
		items[3].cx = 100;
		items[4].cx = 200;

		int nWidthLeft = (size.cx - 30 - items[0].cx - items[3].cx - items[4].cx);
		items[1].cx = nWidthLeft * 2 / 3;
		items[2].cx = nWidthLeft * 1 / 3;

		//删除原来所有的项
		m_pHeader->DeleteAllItems();
		
		//添加修改宽度后的项
		for(int i=0; i<count; i++)
			m_pHeader->InsertItem(i,items[i].text.GetText(), items[i].cx, items[i].stFlag, items[i].lParam);

		SMCListView::OnSize(nType, size);
	}


	 SOUI_MSG_MAP_BEGIN()
            MSG_WM_SIZE(OnSize)
     SOUI_MSG_MAP_END()
};