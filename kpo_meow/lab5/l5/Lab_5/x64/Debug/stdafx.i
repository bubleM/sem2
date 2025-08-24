#line 1 "D:\\учёба\\2СЕМ\\КПО\\ЛБ\\5\\Lab_5 — копия\\Lab_5\\stdafx.cpp"
#line 1 "D:\\учёба\\2СЕМ\\КПО\\ЛБ\\5\\Lab_5 — копия\\Lab_5\\stdafx.h"
#pragma once
#line 1 "D:\\учёба\\2СЕМ\\КПО\\ЛБ\\5\\Lab_5 — копия\\Lab_5\\Dictionary.h"
#pragma once














namespace Dictionary
{
	struct Entry  
	{
		int id;                      
		char name[30]; 
	};
	struct Instance  
	{
		char name[30]; 
		int maxsize = 100;   
		int size;          
		int cnt = 0;
		Entry* dictionary; 
	};

	Instance Create(        
		const char* name,   
		int size            
	);
	void addEntry(      
		Instance& inst, 
		Entry ed        
	);
	void DelEntry(      
		Instance& inst, 
		int id          
	);
	void UpdEntry(      
		Instance& inst, 
		int id,         
		Entry new_ed    
	);
	Entry GetEntry(     
		Instance& inst, 
		int id          
	);
	void Print(Instance& d);  
	void Delete(Instance& d); 
};
#line 3 "D:\\учёба\\2СЕМ\\КПО\\ЛБ\\5\\Lab_5 — копия\\Lab_5\\stdafx.h"










#line 2 "D:\\учёба\\2СЕМ\\КПО\\ЛБ\\5\\Lab_5 — копия\\Lab_5\\stdafx.cpp"
