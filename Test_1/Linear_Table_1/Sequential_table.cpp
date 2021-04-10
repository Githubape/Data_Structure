#include "Sequential_table.h"

Sequential_table::Sequential_table(int max)
{
	datas = NULL;
	length = 0;
	MaxSize = max;
}

void Sequential_table::creatTable(int len)
{
	if (len > MaxSize)
	{
		cout << "outsize-error" << endl;
		return;
	}
	datas = new int[MaxSize];
	length = len;
	cout << "input " << len << " data" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << "the " << i+1 << "th:  " ;
		cin >> datas[i];
	}
}

void Sequential_table::show()
{
	for (int i = 0; i < length; i++)
		cout << i+1<<":   "<<datas[i] << endl;
	cout << endl <<"len:  " <<length << endl;
}

bool Sequential_table::insertElement(int ele,int pos)
{
	if (pos<1 || pos>length + 1)
		return false;
	if (length >= MaxSize)
		return false;


	for (int i = length; i > pos - 1; i--)
	{
		datas[i] = datas[i - 1];
	}
	datas[pos - 1] = ele;
	length++;
	return true;
}


bool Sequential_table::deleteElement(int sym,int &data)
{
	if (sym<1 || sym>length)
		return false;


	data = datas[sym - 1];
	for (int i = sym-1; i < length - 1; i++)
	{
		datas[i] = datas[i + 1];
	}
	length--;
	return true;
}

int Sequential_table::searchElement(int ele)
{

	for (int i = 0; i < length; i++)
	{
		if (datas[i] == ele)
			return i+1;
	}
	return -1;
}