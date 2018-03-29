#include "Header.h"


int TaskNumb()
{
	printf("Введите номер задания - ");
	int task;
	scanf_s("%d", &task);
	return task;
}

int Exit()
{
	int exit;
	printf("\nДля выхода введите 0\n--- ");
	scanf_s("%d", &exit);
	return exit;
}

void FromIntToChar(int * from, char * to, int  length)
{
	for (int i = 0; i < length; i++)
	{
		to[i] = (char)from[i];
	}
	to[0] = toupper(to[0]);
	to[length] = '\0';
}

void RandomPeoplesName(NOTE1 * people, int * countOfPeople)
{	
	int lName[15], fName[2], mName[2];
	for (int j = 0; j < *countOfPeople; j++)
	{
		int length = 5 + rand() % 5;
		for (int i = 0; i < length; i++)
		{
			lName[i] = 97 + rand() % 25;
		}
		for (int i = 0; i < 1; i++)
		{
			fName[i] = 97 + rand() % 25;
		}
		for (int i = 0; i < 1; i++)
		{
			mName[i] = 97 + rand() % 25;
		}
		FromIntToChar(lName, people[j].Names.lName, length);
		FromIntToChar(fName, people[j].Names.fName, 1);
		FromIntToChar(mName, people[j].Names.mName, 1);
	}
}


void DateFilling(NOTE1 *day, int * count)
{
	for (int i = 0; i < *count; i++)
	{
		day[i].DATE.year = 1900 + rand() % 117;
		if ((day[i].DATE.year % 4 == 0 && day[i].DATE.year % 100 == 0) || day[i].DATE.year % 400 == 0)
		{
			day[i].DATE.month = 1 + rand() % 12;
			if (day[i].DATE.month == 1 || day[i].DATE.month == 3 || day[i].DATE.month == 5 || day[i].DATE.month == 7 ||
				day[i].DATE.month == 8 || day[i].DATE.month == 10 || day[i].DATE.month == 12)
				day[i].DATE.day = 1 + rand() % 31;
			else if (day[i].DATE.month == 4 || day[i].DATE.month == 6 || day[i].DATE.month == 9 || day[i].DATE.month == 11)
				day[i].DATE.day = 1 + rand() % 30;
			else if (day[i].DATE.month == 2)
				day[i].DATE.day = 1 + rand() % 29;
		}
		else
		{
			day[i].DATE.month = 1 + rand() % 12;
			if (day[i].DATE.month == 1 || day[i].DATE.month == 3 || day[i].DATE.month == 5 || day[i].DATE.month == 7 || day[i].DATE.month == 8 || 
				day[i].DATE.month == 10 || day[i].DATE.month == 12)
				day[i].DATE.day = 1 + rand() % 31;
			else if (day[i].DATE.month == 4 || day[i].DATE.month == 6 || day[i].DATE.month == 9 || day[i].DATE.month == 11)
				day[i].DATE.day = 1 + rand() % 30;
			else if (day[i].DATE.month == 2)
				day[i].DATE.day = 1 + rand() % 28;
		}
	}
}

void RandomePhoneNumb(NOTE1 * people, int * countofPeople)
{	
	int n;
	for (int i = 0; i < *countofPeople; i++)
	{
		n = 0 + rand() % 3;
		switch (n)
		{
		case 0: people[i].TELE.code = 707;
			break;
		case 1: people[i].TELE.code = 777;
			break;
		case 2: people[i].TELE.code = 775;
			break;
		case 3: people[i].TELE.code = 771;
			break;
		
		default: printf("ERROR\n");
			break;
		}
		people[i].TELE.numb = 100 + rand() % 899;
		people[i].TELE.numb2 = 10 + rand() % 89;
		people[i].TELE.numb3 = 10 + rand() % 89;
	}
}

int MonthReturn(NOTE1 * people, int * countOfPeople, int * month)
{	
	int index = 1;
	for (int i = 0; i < *countOfPeople; i++)
	{
		if (people[i].DATE.month == *month)
		{
			printf("%d)--> %s %s.%s, %d.%d.%d\n\tТел: +7(%d) %d %d %d\n",
				index, people[i].Names.lName, people[i].Names.fName, people[i].Names.mName,
				people[i].DATE.day, people[i].DATE.month, people[i].DATE.year, people[i].TELE.code, 
				people[i].TELE.numb, people[i].TELE.numb2, people[i].TELE.numb3);
			index++;
		}
	}
	if (index == 1)
		return 0;
}

void GoodsName(TOVAR * goods, int * countOfGoods)
{	
	int name[20], length;
	for (int i = 0; i < *countOfGoods; i++)
	{
		length = 6 + rand() % 10;
		for (int j = 0; j < length; j++)
		{
			name[j] = 97 + rand() % 26;
		}
		FromIntToChar(name, goods[i].name, length);
	}
}

void GoodsCount(TOVAR * goods, int * countOfGoods)
{
	for (int i = 0; i < *countOfGoods; i++)
	{
		goods[i].count = 200 + rand() % 600;
	}
}

void GoodsCost(TOVAR * goods, int * countOfGoods)
{
	for (int i = 0; i < *countOfGoods; i++)
	{
		goods[i].cost = 20 + rand() % 100;
	}
}

void GoodsSort(TOVAR * goods, int * countOfGoods)
{
	TOVAR temp;
	for (int i = 0; i < *countOfGoods; i++)
	{
		for (int j = *countOfGoods - 1; j > 0; j--)
		{
			if (goods[j].cost < goods[j - 1].cost)
			{
				temp = goods[j - 1];
				goods[j - 1] = goods[j];
				goods[j] = temp;
			}
		}
	}
}

void GoodsPrint(TOVAR * goods, int * countOfGoods)
{	
	int index = 1;
	for (int i = 0; i < *countOfGoods; i++)
	{
		if ((goods[i].date.year <= 2017 && goods[i].date.month < 5) || goods[i].date.year == 2017 && (goods[i].date.month >= 1 && goods[i].date.month <=5)
			|| goods[i].date.year <= 2016)
		{
			printf("%d)\tНаименование:%s\n\tДата получения:%d.%d.%d\n\tКол-во ед.товара: %d\n\tЦена за ед: %d\n\tОбщая цена: %d\n",
				index, goods[i].name, goods[i].date.day, goods[i].date.month, goods[i].date.year,
				goods[i].count, goods[i].cost, (goods[i].count* goods[i].cost));
			index++;
		}
	}
	if (index == 1)
		printf("Нет товара старше 10 месяецев\n");
}

void DateFilling2(TOVAR *day, int * count)
{
	for (int i = 0; i < *count; i++)
	{
		day[i].date.year = 1900 + rand() % 117;
		if ((day[i].date.year % 4 == 0 && day[i].date.year % 100 == 0) || day[i].date.year % 400 == 0)
		{
			day[i].date.month = 1 + rand() % 12;
			if (day[i].date.month == 1 || day[i].date.month == 3 || day[i].date.month == 5 || day[i].date.month == 7 ||
				day[i].date.month == 8 || day[i].date.month == 10 || day[i].date.month == 12)
				day[i].date.day = 1 + rand() % 31;
			else if (day[i].date.month == 4 || day[i].date.month == 6 || day[i].date.month == 9 || day[i].date.month == 11)
				day[i].date.day = 1 + rand() % 30;
			else if (day[i].date.month == 2)
				day[i].date.day = 1 + rand() % 29;
		}
		else
		{
			day[i].date.month = 1 + rand() % 12;
			if (day[i].date.month == 1 || day[i].date.month == 3 || day[i].date.month == 5 || day[i].date.month == 7 || day[i].date.month == 8 ||
				day[i].date.month == 10 || day[i].date.month == 12)
				day[i].date.day = 1 + rand() % 31;
			else if (day[i].date.month == 4 || day[i].date.month == 6 || day[i].date.month == 9 || day[i].date.month == 11)
				day[i].date.day = 1 + rand() % 30;
			else if (day[i].date.month == 2)
				day[i].date.day = 1 + rand() % 28;
		}
	}
}

void RouteNumb(ROUTE * route, int * countOfRoutes)
{
	for (int i = 0; i < *countOfRoutes; i++)
	{
		route[i].numb = 10 + rand() % 989;
	}
}

void RouteDeparture(ROUTE * route, int * countOfRoutes)
{
	int from[15], length;
	for (int i = 0; i < *countOfRoutes; i++)
	{
		length = 5 + rand() % 6;
		for (int j = 0; j < length; j++)
		{
			from[j] = 97 + rand() % 26;
		}
		FromIntToChar(from, route[i].departure, length);
		length = 5 + rand() % 6;
		for (int j = 0; j < length; j++)
		{
			from[j] = 97 + rand() % 26;
		}
		FromIntToChar(from, route[i].destination, length);
	}
}

void RoutesLength(ROUTE * route, int * countOfRoutes)
{
	for (int i = 0; i < *countOfRoutes; i++)
	{
		route[i].length = 1000 + rand() % 6000;
	}
}

void RoutesSort(ROUTE * route, int * countOfRoutes)
{
	ROUTE temp;
	for (int i = 0; i < *countOfRoutes; i++)
	{
		for (int j = *countOfRoutes - 1; j > 0; j--)
		{
			if (route[j].length < route[j - 1].length)
			{
				temp = route[j - 1];
				route[j - 1] = route[j];
				route[j] = temp;
			}
		}
	}
}

void RoutesPrint(ROUTE * route, int * countOfRoutes)
{	
	int max = route[0].length, index = 0;
	for (int i = 0; i < *countOfRoutes; i++)
	{
		printf("%d)--> Номер Маршрута: %d\nМаршрут: %s --- %s. Расстояние: %d\n",
			i + 1, route[i].numb, route[i].departure, route[i].destination, route[i].length);
		if (route[i].length > max)
		{
			max = route[i].length;
			index = i;
		}
	}
	printf("\nМаршрут с максимальной длино в %d км. - %s --- %s\n", max, route[index].departure, route[index].destination);
}

void RandomPeoplesName2(ABON * people, int * countOfPeople)
{
	int lName[15], fName[2], mName[2];
	for (int j = 0; j < *countOfPeople; j++)
	{
		int length = 5 + rand() % 5;
		for (int i = 0; i < length; i++)
		{
			lName[i] = 97 + rand() % 25;
		}
		for (int i = 0; i < 1; i++)
		{
			fName[i] = 97 + rand() % 25;
		}
		for (int i = 0; i < 1; i++)
		{
			mName[i] = 97 + rand() % 25;
		}
		FromIntToChar(lName, people[j].Names.lName, length);
		FromIntToChar(fName, people[j].Names.fName, 1);
		FromIntToChar(mName, people[j].Names.mName, 1);
	}
}

void RandomePhoneNumb2(ABON * people, int * countofPeople)
{
	int n;
	for (int i = 0; i < *countofPeople; i++)
	{
		n = 0 + rand() % 3;
		switch (n)
		{
		case 0: people[i].TELE.code = 707;
			break;
		case 1: people[i].TELE.code = 777;
			break;
		case 2: people[i].TELE.code = 775;
			break;
		case 3: people[i].TELE.code = 771;
			break;

		default: printf("ERROR\n");
			break;
		}
		people[i].TELE.numb = 100 + rand() % 899;
		people[i].TELE.numb2 = 10 + rand() % 89;
		people[i].TELE.numb3 = 10 + rand() % 89;
	}
}

void DateFilling3(ABON *day, int * count)
{
	for (int i = 0; i < *count; i++)
	{
		day[i].date.year = 2000 + rand() % 18;
		if ((day[i].date.year % 4 == 0 && day[i].date.year % 100 == 0) || day[i].date.year % 400 == 0)
		{
			day[i].date.month = 1 + rand() % 12;
			if (day[i].date.month == 1 || day[i].date.month == 3 || day[i].date.month == 5 || day[i].date.month == 7 ||
				day[i].date.month == 8 || day[i].date.month == 10 || day[i].date.month == 12)
				day[i].date.day = 1 + rand() % 31;
			else if (day[i].date.month == 4 || day[i].date.month == 6 || day[i].date.month == 9 || day[i].date.month == 11)
				day[i].date.day = 1 + rand() % 30;
			else if (day[i].date.month == 2)
				day[i].date.day = 1 + rand() % 29;
		}
		else
		{
			day[i].date.month = 1 + rand() % 12;
			if (day[i].date.month == 1 || day[i].date.month == 3 || day[i].date.month == 5 || day[i].date.month == 7 || day[i].date.month == 8 ||
				day[i].date.month == 10 || day[i].date.month == 12)
				day[i].date.day = 1 + rand() % 31;
			else if (day[i].date.month == 4 || day[i].date.month == 6 || day[i].date.month == 9 || day[i].date.month == 11)
				day[i].date.day = 1 + rand() % 30;
			else if (day[i].date.month == 2)
				day[i].date.day = 1 + rand() % 28;
		}
	}
}

void AbonDebt(ABON *abonent, int *countofPeople)
{
	for (int i = 0; i < *countofPeople; i++)
	{
		abonent[i].debt = 100 + rand() % 2000;
	}
}

void AbonSum(ABON *abonent, int *countofPeople)
{
	for (int i = 0; i < *countofPeople; i++)
	{
		abonent[i].sum = 200 + rand() % 1500;
	}
}

void AbonSort(ABON *abonent, int *countofPeople)
{
	ABON temp;
	for (int i = 0; i < *countofPeople; i++)
	{
		for (int j = *countofPeople - 1; j > 0; j--)
		{	
			if (abonent[j].Names.lName == abonent[j - 1].Names.lName)
			{
				if ((int)abonent[j].Names.fName[0] < (int)abonent[j - 1].Names.fName[0])
				{
					temp = abonent[j - 1];
					abonent[j - 1] = abonent[j];
					abonent[j] = temp;
				}
			}
			else if ((int)abonent[j].Names.lName[0] < (int)abonent[j - 1].Names.lName[0])
			{
				temp = abonent[j - 1];
				abonent[j - 1] = abonent[j];
				abonent[j] = temp;
			}
			
		}
	}
}

void AbonSumAdd(ABON *abonent, int *countofPeople)
{
	for (int i = 0; i < *countofPeople; i++)
	{
		if (abonent[i].date.year <= 2008)
		{
			abonent[i].sum += 2000;
			printf("%s получает 2000тг\n", abonent[i].Names.lName);
		}
			
	}
}

void AbonPrint(ABON *abonent, int *countofPeople)
{
	printf("\nСписок абонентов\n");
	for (int i = 0; i < *countofPeople; i++)
	{
		printf("%d) --> %s %s.%s\n", i + 1, abonent[i].Names.lName, abonent[i].Names.fName, abonent[i].Names.mName);
	}
}

void AbontPrintDetail(ABON *abonent, int *countofPeople)
{
	printf("\nСписок абонентов с задолженностью\n");
	for (int i = 0; i < *countofPeople; i++)
	{
		if ((abonent[i].sum - abonent[i].debt) < 0)
		{
			printf("%d) --> %s %s.%s\nТел номер:+7 (%d) %d %d %d\nВместе с нами с %d.%d.%dг.\nСумма долга - %d\n\n", 
				i + 1, abonent[i].Names.lName, abonent[i].Names.fName, abonent[i].Names.mName,
			abonent[i].TELE.code, abonent[i].TELE.numb, abonent[i].TELE.numb2, abonent[i].TELE.numb3, 
				abonent[i].date.day, abonent[i].date.month, abonent[i].date.year, (abonent[i].sum - abonent[i].debt));
		}
	}
}