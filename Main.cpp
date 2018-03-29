#include "Header.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int task, exit;
	do
	{
		task = TaskNumb();
		switch (task)
		{
			case 1:
			{
				
				/*1.	Описать структуру с именем NOTE1, содержащую поля :
				a.Name – фамилия и инициалы
					b.TELE – номер телефона
					c.DATE – дата рождения(год, месяц, число)

					Написать программу, выполняющую :
					•	ввод с клавиатуры данных в массив BLOCK, состоящий из 9 элементов типа NOTE1,
					записи должны быть упорядочены по инициалам;
				•	вывод на экран информации о людях, чьи дни рождения приходятся на месяц, 
					значение которого введено с клавиатуры; если такого человека нет – выдать сообщение.*/

				NOTE1 BLOCK[9];
				int countOfPeople = 9, month;
				RandomPeoplesName(BLOCK, &countOfPeople);
				DateFilling(BLOCK, &countOfPeople);
				RandomePhoneNumb(BLOCK, &countOfPeople);
				do
				{
					printf("Введите дату месяца - ");
					scanf_s("%d", &month);
				} while (month <1 || month > 12);
				if (MonthReturn(BLOCK, &countOfPeople, &month) == 0)
					printf("Нет людей, родившихся в %d-й месяц\n", month);
				exit = Exit();
				if (exit == 0)
					return 0;
			} break;
			case 2:
			{
				/*2.	Описать структуру с именем TOVAR, содержащую поля :
				a.название товара;
				b.количество единиц товара;
				c.стоимость товара;
				d.дата поступления товара в виде структуры(год, месяц, день).

					Написать функции :
				•	создания массива SPISOK не более чем из 10 записей(структур) данных о товарах(ввод данных с клавиатуры);
				•	вычисления средней стоимости товара;
				•	расположения записей по возрастанию стоимости товаров;
				•	вывода сведений о товарах, поступивших более 10 месяцев назад.*/
				int countOfGoods = 4 + rand() % 6;
				TOVAR *goods;
				goods = (TOVAR*)calloc(countOfGoods, sizeof(TOVAR));
				if (goods == NULL)
				{
					printf("ERROR\n");
					EXIT_FAILURE;
				}
				GoodsName(goods, &countOfGoods);
				DateFilling2(goods, &countOfGoods);
				GoodsCount(goods, &countOfGoods);
				GoodsCost(goods, &countOfGoods);
				GoodsSort(goods, &countOfGoods);
				GoodsPrint(goods, &countOfGoods);
				free(goods);
				exit = Exit();
				if (exit == 0)
					return 0;
			} break;

			case 3:
			{
				/*3.	Описать структуру с именем MARSHRUT, содержащую поля :
				a.номер маршрута;
				b.начальный пункт маршрута;
				c.конечный пункт маршрута;
				d.длина маршрута.
					Написать функции :
				•	создания массива не более чем из 10 записей(структур) сведений о маршрутах(ввод данных с клавиатуры);
				•	определения маршрута с максимальной длиной;
				•	расположения записей по возрастанию номеров маршрутов;
				•	вывода сведений о маршрутах, которые начинаются или заканчиваются в пункте, название которого вводится с клавиатуры.*/
				int countOfRoutes = 4 + rand() % 4;
				printf("Кол-во маршрутов - %d\n", countOfRoutes);
				ROUTE * route;
				route = (ROUTE*)calloc(countOfRoutes, sizeof(ROUTE));
				if (route == NULL)
				{
					printf("ERROR\n");
					EXIT_FAILURE;
				}
				RouteNumb(route, &countOfRoutes);
				RouteDeparture(route, &countOfRoutes);
				RoutesLength(route, &countOfRoutes);
				RoutesSort(route, &countOfRoutes);
				RoutesPrint(route, &countOfRoutes);
				free(route);
				exit = Exit();
				if (exit == 0)
					return 0;
			} break;

			case 4:
			{
				/*4.	Описать структуру с именем ABON, содержащую поля :
				a.фамилия и инициалы абонента;
				b.номер телефона;
				c.дата подключения телефона в виде структуры(год, месяц, день);
				d.начисленная сумма оплаты;
				e.сумма на счету абонента
					Написать функции :
				•	создания массива не более чем из 12 записей(структур) данных об абонентах(ввод данных с клавиатуры);
				•	расположения записей по алфавиту(с учетом инициалов для абонентов с одинаковыми фамилиями;
				•	добавить 20 гр.на счета абонентов, которых подключили более 10 лет назад;
				•	вывода сведений об абонентах, у которых сумма на счету отрицательная после вычета начислений;
				•	вывода сведений об абоненте, номер телефона которого вводится с клавиатуры*/
				int countOfPeople = 4 + rand() % 4;
				printf("Кол-во людей - %d\n", countOfPeople);
				ABON * abonent;
				abonent = (ABON*)calloc(countOfPeople, sizeof(ABON));
				if (abonent == NULL)
				{
					printf("ERROR\n");
					EXIT_FAILURE;
				}
				RandomPeoplesName2(abonent, &countOfPeople);
				RandomePhoneNumb2(abonent, &countOfPeople);
				DateFilling3(abonent, &countOfPeople);
				AbonDebt(abonent, &countOfPeople);
				AbonSum(abonent, &countOfPeople);
				AbonSumAdd(abonent, &countOfPeople);
				AbonSort(abonent, &countOfPeople);
				AbonPrint(abonent, &countOfPeople);
				AbontPrintDetail(abonent, &countOfPeople);
				free(abonent);
				exit = Exit();
				if (exit == 0)
					return 0;
			} break;
		}
	} while (task > 0);
}