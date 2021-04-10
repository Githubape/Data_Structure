/*
作者:Sa
文件描述:
顺序表接口类声明
2021 4.10  17:00
*/

#pragma once
#include <iostream>
#include "linear_Table.h"
using namespace std;

class Sequential_table :
	public linear_table<int *,int,int>
{
public:
	int MaxSize;

	Sequential_table(int max);
	virtual void creatTable(int len);
	virtual bool insertElement(int ele,int pos);
	virtual bool deleteElement(int sym,int &data);
	virtual void show();
	virtual int searchElement(int ele);
};

