/*
	BesLyric  一款 操作简单、功能实用的 专门用于制作网易云音乐滚动歌词的 歌词制作软件。
    Copyright (C) 2017  
	Author: BensonLaur <BensonLaur@163.com>
	Author:

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
* @file       LyricPlayer.h
* 
* Describe    LyricPlayer类，定义了 歌词滚动播放页面处理 歌词播放事务的接口
*/

#pragma once
#include "stdafx.h"
#include "MusicPlayer.h"
#include "LrcHandler.h"
#include "../utility/WinFile.h"

#include <vector>
using namespace std;

class TimeLineInfo;

/*
*	@brief 歌词播放器，存储和处理 歌词滚动预览过程 中使用到的数据
*/
class LyricPlayer
{
public:
	LyricPlayer();

	//设置各个路径
	//设置音乐路径时，传入播放音乐需要的 消息宿主窗口的句柄
	void setMusicPath(LPCTSTR pathName,HWND hostWnd);
	
	void setLyricPath(LPCTSTR pathName);

	//重置 LyricPlayer的 歌词数据为空
	void reloadPlayer();

	//播放歌曲与滚动歌词 预览开始
	bool playingStart(SHostWnd *wnd);

	//预览结束
	void playingEnd(SHostWnd *wnd);

	//如果快进或者后退都会导致，当前行发生变化，故需要先更新再取值
	void updateCurLine();

	//当前是否在第0行的位置
	bool isCurrentZeroLine();

	//从文件获取带时间信息的每行歌词的集合向量
	vector<TimeLineInfo> getLyricWithLineInfo(File& lyricFile);

private:
	//播放音乐
	bool playMusic();

	//停止音乐
	void stopMusic();

public:
	TCHAR m_szMusicPathName[_MAX_PATH];			/*存放 选择 的2个从界面选择的路径名*/
	TCHAR m_szLyricPathName[_MAX_PATH];

	vector<TimeLineInfo> m_vLineInfo;		/* 储存带时间信息的歌词的每一行的具体信息 （第一行储存位置为 0 不是 1*/

	int				m_nCurLine;				/* 当前时间行 所在行数 (第一行为：1 不是 0)*/
	int				m_nTotalLine;			/* 带时间信息的 总行数（不包括空行，但包括有时间但是没歌词的行） */
	
	MusicPlayer		m_musicPlayer;			/* 负责歌词滚动预览过程中音乐的播放 */
};