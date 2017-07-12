/*
	BesLyric  一款 操作简单、功能实用的 专门用于制作网易云音乐滚动歌词的 歌词制作软件。
    Copyright (C) 2017  BensonLaur

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
* @file       Define.h
* 
* Describe    定义了 程序使用的一些结构
*/

#pragma once
#include "stdafx.h"
#include <string>
using namespace std;

/* 宏定义 */
#ifdef _DEBUG

#define UPDATE_LOOP  0			/* 是否在启动时更新程序 */

#else

#define UPDATE_LOOP  1

#endif



/* 结构定义 */

//在制作歌词页面 和 滚动预览 页面中，需要选择音乐路径，歌词路径，输出路径等信息
//该结构用于存储 路径名 以及 是否已被选择的状态
typedef struct _PATH_STATE
{	
	TCHAR nameOfPath[_MAX_PATH];
	bool isInited;
}PATH_STATE; 



enum ENCODING_TYPE			//文件编码类型
{
	ASCII,						
	UNICODE_LITTLE_ENDIAN,
	UNICODE_BIG_ENDIAN,
	UTF_8,
	OTHER
};


/* 全局变量定义 */
static const SStringW VERSION_NUMBER = L"2.0.1";		//版本号（注意每次更改版本号时需要更改2处，1处是这里，1处是 BesLyric.rc 中的Version）

static const wstring  LINK_VERSION_LOG= L"http://files.cnblogs.com/files/BensonLaur/versionLog.zip";			//链接，指向版本日志文件
static const wstring  LINK_LAST_VERSION_INFO= L"http://files.cnblogs.com/files/BensonLaur/lastVersion.zip";		//链接，指向最后版本信息的文件
static const wstring  LINK_LAST_EXE= L"http://files.cnblogs.com/files/BensonLaur/BesLyricExe.zip";				//链接，指向最新的 EXE文件

static const string LINK_SEND_LOGIN = "http://beslyric.320.io/BesBlog/beslyric/login.action";

static const string FILE_NAME_LAST_VERSION_INFO = "version";					//文件名，从 LINK_LAST_VERSION_INFO 下载下来储存的文件
static const string FILE_NAME_LAST_EXE_TEMP = "BesLyric";						//文件名，从 LINK_LAST_EXE 下载下来储存的文件
static const string SETTING_FILE_NAME = "setting";								//文件名，储存设置

//制作歌词页面 的路径 与选择状态
static PATH_STATE PATH_STATE_1[] = 
{
	{_T("音乐文件"),false},
	{_T("歌词文件"),false},
	{_T("输出路径"),false}
};

//滚动预览页面 的路径 与选择状态
static PATH_STATE PATH_STATE_2[] = 
{
	{_T("音乐文件"),false},
	{_T("歌词文件"),false}
};

