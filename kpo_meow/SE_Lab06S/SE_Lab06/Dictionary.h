#pragma once
#define DICTNAMEMAXSIZE		20  //максимальный размер имени словар€
#define DICTMAXSIZE			100 //макисмальан€ емкость словар€
#define ENTRYNAMEMAXSIZE	30  //максимальна€ длина имени в словаре

#define THROW01 "Create: превышен размер словар€"
#define THROW02 "Create: превышен размер максимальной емкости словар€"
#define THROW03 "AddEntry: переполнение словар€"
#define THROW04 "AddEntry: дублирование идентификатора"
#define THROW05 "GetEntry: не найдне элемент"
#define THROW06 "DelEntry: не найден элемент"
#define THROW07 "UpdEntry: не найден элемент"
#define THROW08 "UpdEntry: дублирование идентификатора"

namespace Dictionary
{
	struct Entry  //элемент словар€
	{
		int id;                      //идентификатор
		char name[ENTRYNAMEMAXSIZE]; //символьна€ информаци€
	};
	struct Instance  //экземпл€р словар€
	{
		char name[ENTRYNAMEMAXSIZE]; //название словар€
		int maxsize = DICTMAXSIZE;   //макисмальан€ емкость словар€
		int size;          //текущий размер словар€ < DICTMAXSIZE
		int cnt = 0;
		Entry* dictionary; //массив элементов словар€
	};

	Instance Create(        //создать словарь
		const char* name,   //им€ словар€
		int size            //емкость словар€ < DICTNAMEMAXSIZE
	);
	void addEntry(      //добавить элемент словар€
		Instance& inst, //экзампл€р словар€
		Entry ed        //элемент словр€
	);
	void DelEntry(      //удалить элемент словар€
		Instance& inst, //экзампл€р словар€
		int id          //инентификатор удал€емого элемента
	);
	void UpdEntry(      //изменить элемент словар€
		Instance& inst, //экзампл€р словар€
		int id,         //инентификатор измен€емого элемента
		Entry new_ed    //новый элемент словар€
	);
	Entry GetEntry(     //получить эдмент словар€
		Instance& inst, //экзампл€р словар€
		int id          //инентификатор получамого элемента
	);
	void Print(Instance& d);  //печатать словарь
	void Delete(Instance& d); //удалить словарь
};