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
				
				/*1.	������� ��������� � ������ NOTE1, ���������� ���� :
				a.Name � ������� � ��������
					b.TELE � ����� ��������
					c.DATE � ���� ��������(���, �����, �����)

					�������� ���������, ����������� :
					�	���� � ���������� ������ � ������ BLOCK, ��������� �� 9 ��������� ���� NOTE1,
					������ ������ ���� ����������� �� ���������;
				�	����� �� ����� ���������� � �����, ��� ��� �������� ���������� �� �����, 
					�������� �������� ������� � ����������; ���� ������ �������� ��� � ������ ���������.*/

				NOTE1 BLOCK[9];
				int countOfPeople = 9, month;
				RandomPeoplesName(BLOCK, &countOfPeople);
				DateFilling(BLOCK, &countOfPeople);
				RandomePhoneNumb(BLOCK, &countOfPeople);
				do
				{
					printf("������� ���� ������ - ");
					scanf_s("%d", &month);
				} while (month <1 || month > 12);
				if (MonthReturn(BLOCK, &countOfPeople, &month) == 0)
					printf("��� �����, ���������� � %d-� �����\n", month);
				exit = Exit();
				if (exit == 0)
					return 0;
			} break;
			case 2:
			{
				/*2.	������� ��������� � ������ TOVAR, ���������� ���� :
				a.�������� ������;
				b.���������� ������ ������;
				c.��������� ������;
				d.���� ����������� ������ � ���� ���������(���, �����, ����).

					�������� ������� :
				�	�������� ������� SPISOK �� ����� ��� �� 10 �������(��������) ������ � �������(���� ������ � ����������);
				�	���������� ������� ��������� ������;
				�	������������ ������� �� ����������� ��������� �������;
				�	������ �������� � �������, ����������� ����� 10 ������� �����.*/
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
				/*3.	������� ��������� � ������ MARSHRUT, ���������� ���� :
				a.����� ��������;
				b.��������� ����� ��������;
				c.�������� ����� ��������;
				d.����� ��������.
					�������� ������� :
				�	�������� ������� �� ����� ��� �� 10 �������(��������) �������� � ���������(���� ������ � ����������);
				�	����������� �������� � ������������ ������;
				�	������������ ������� �� ����������� ������� ���������;
				�	������ �������� � ���������, ������� ���������� ��� ������������� � ������, �������� �������� �������� � ����������.*/
				int countOfRoutes = 4 + rand() % 4;
				printf("���-�� ��������� - %d\n", countOfRoutes);
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
				/*4.	������� ��������� � ������ ABON, ���������� ���� :
				a.������� � �������� ��������;
				b.����� ��������;
				c.���� ����������� �������� � ���� ���������(���, �����, ����);
				d.����������� ����� ������;
				e.����� �� ����� ��������
					�������� ������� :
				�	�������� ������� �� ����� ��� �� 12 �������(��������) ������ �� ���������(���� ������ � ����������);
				�	������������ ������� �� ��������(� ������ ��������� ��� ��������� � ����������� ���������;
				�	�������� 20 ��.�� ����� ���������, ������� ���������� ����� 10 ��� �����;
				�	������ �������� �� ���������, � ������� ����� �� ����� ������������� ����� ������ ����������;
				�	������ �������� �� ��������, ����� �������� �������� �������� � ����������*/
				int countOfPeople = 4 + rand() % 4;
				printf("���-�� ����� - %d\n", countOfPeople);
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