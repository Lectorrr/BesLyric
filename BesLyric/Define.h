/*
	BesLyric  һ�� �����򵥡�����ʵ�õ� ר�������������������ֹ�����ʵ� �������������
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
* @file       CodeFile.h
* @version    v1.0      
* @author     BensonLaur   
* @date       2017/05/19
* 
* Describe    ������ ���ֱ����ļ� �Ĳ���	
*/

#pragma once
#include "stdafx.h"
using namespace std;

enum ENCODING_TYPE			//�ļ���������
{
	ASCII,						
	UNICODE_LITTLE_ENDIAN,
	UNICODE_BIG_ENDIAN,
	UTF_8,
	OTHER
};