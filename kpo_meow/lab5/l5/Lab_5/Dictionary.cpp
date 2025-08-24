#include "Dictionary.h"
#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace Dictionary;
using namespace std;

Instance Dictionary::Create(const char* name, int size)
{
	Instance NewDict;
	if (strlen(name) > ENTRYNAMEMAXSIZE)
	{
		throw THROW01; //"Create: превышен размер словаря" 
	}
	if (NewDict.maxsize < size)
	{
		throw THROW02; //"Create: превышен размер максимальной ескости словаря"
	}
	strcpy_s(NewDict.name, name);
	NewDict.size = size;
	NewDict.dictionary = new Entry[size]; //выделение памяти для заданного размера словаря
	return NewDict;
}
void Dictionary::addEntry(Instance& inst, Entry ed)
{
	int cnt = inst.cnt;
	if (cnt >= inst.size)
	{
		throw THROW03;   //"AddEntry: переполнение словаря"
	}
	else
	{
		inst.dictionary[cnt] = ed;
	}
	for (int i = 0; i < cnt; i++)
	{
		if (inst.dictionary[i].id == ed.id) throw THROW04; //"AddEntry: дублирование идентификатора"
	}
	inst.cnt++;
}
void Dictionary::DelEntry(Instance& inst, int id)
{
	bool isFound = false;
	for (int i = 0; i < inst.cnt; i++)
	{
		if (inst.dictionary[i].id == id)
		{
			isFound = true;
			for (int j = i; j < inst.cnt; j++)
			{
				inst.dictionary[j] = inst.dictionary[j + 1];
			}
			inst.cnt--;
			break;
		}
	}
	if (!isFound) throw THROW06; //"DelEntry: не найден элемент"
}
Entry Dictionary::GetEntry(Instance& inst, int id)
{
	bool isFound = false;
	for (int i = 0; i < inst.cnt; i++)
	{
		if (inst.dictionary[i].id == id)
		{
			cout << inst.dictionary[i].name << endl;
			return inst.dictionary[i];
		}
	}
	if (!isFound) throw THROW05; //"GetEntry: не найдне элемент"
}
void Dictionary::UpdEntry(Instance& inst, int id, Entry new_ed)
{
	bool isFound = false;
	for (int i = 0; i < inst.cnt; i++)
	{
		if (inst.dictionary[i].id == id)
		{
			for (int j = i; j < inst.cnt; j++)
			{
				if (new_ed.id == inst.dictionary[j].id) throw THROW08; //"UpdEntry: дублирование идентификатора"
			}
			isFound = true;

			inst.dictionary[i].id = new_ed.id;
			strcpy_s(inst.dictionary[i].name, new_ed.name);
			break;
		}
		else if (new_ed.id == inst.dictionary[i].id) throw THROW08; //"UpdEntry: дублирование идентификатора"
	}
	if (!isFound)
	{
		throw THROW07; //"UpdEntry: не найден элемент"
	}
}
void Dictionary::Print(Instance& d)
{

	cout << endl << "--------" << d.name << "--------" << endl;
	for (int i = 0; i < d.cnt; i++)
	{
		cout <<  d.dictionary[i].id
			<< " " << d.dictionary[i].name << endl << endl;
	}
}
void Dictionary::Delete(Instance& inst)
{
	delete[] inst.dictionary;
}