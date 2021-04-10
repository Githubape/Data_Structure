/*
作者:Sa
文件描述:
线性表接口类声明
2021 4.10  17:00
*/

#pragma once
template  <typename T,typename E,typename S>
class linear_table
{
public:
	
	int length;
	T datas;

	virtual void creatTable(int len) = 0;
	virtual bool insertElement(E ele,int pos) = 0;
	virtual bool deleteElement(S sym,E &data) = 0;
	virtual int searchElement(E ele) = 0;
	virtual void show() = 0;
	int getLengeh()
	{
		return length;
	}
};