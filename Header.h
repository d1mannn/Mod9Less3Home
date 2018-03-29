#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <Windows.h>
#include "Struct.h"

int TaskNumb();
void FromIntToChar(int * from, char * to, int  length);

void RandomPeoplesName(NOTE1 * people, int * countOfPeople);
void DateFilling(NOTE1 *day, int * count);
void RandomePhoneNumb(NOTE1 * people, int * countofPeople);
int MonthReturn(NOTE1 * people, int * countOfPeople, int * month);

int Exit();
void GoodsName(TOVAR * goods, int * countOfGoods);
void GoodsCount(TOVAR * goods, int * countOfGoods);
void GoodsCost(TOVAR * goods, int * countOfGoods);
void GoodsSort(TOVAR * goods, int * countOfGoods);
void GoodsPrint(TOVAR * goods, int * countOfGoods);
void DateFilling2(TOVAR *day, int * count);

void RouteNumb(ROUTE * route, int * countOfRoutes);
void RouteDeparture(ROUTE * route, int * countOfRoutes);
void RoutesLength(ROUTE * route, int * countOfRoutes);
void RoutesSort(ROUTE * route, int * countOfRoutes);
void RoutesPrint(ROUTE * route, int * countOfRoutes);

void RandomPeoplesName2(ABON * people, int * countOfPeople);
void RandomePhoneNumb2(ABON * people, int * countofPeople);
void DateFilling3(ABON *day, int * count);
void AbonDebt(ABON *abonent, int *countofPeople);
void AbonSum(ABON *abonent, int *countofPeople);
void AbonSumAdd(ABON *abonent, int *countofPeople);
void AbonPrint(ABON *abonent, int *countofPeople);
void AbontPrintDetail(ABON *abonent, int *countofPeople);
void AbonSort(ABON *abonent, int *countofPeople);