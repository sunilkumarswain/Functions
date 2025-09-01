#include <stdio.h>

#define MAX(A,B) (((A) > (B)) ? (A) : (B))
/*
* If year%4==0 and year%100==0 then
*     print leap year
* else if year%400==0 then
*     print leap year
* else
*     print common year 
*/
#define CHECKLEAP(year) ((year%4 == 0 && year%100 != 0) ? printf("The given year is leap year\n") : (year%400 == 0) ? printf("The given year is leap year\n") : printf("The given year is common year\n"))
#define EVENODD(num) ((num%2 == 0) ? printf("The number is EVEN\n") : printf("The number is ODD\n"))

void funcExer7()
{
	int a1 = 100, a2 = 300;
	printf("Max between %d and %d is:%d\n", a1, a2, MAX(a1,a2));
	int a3 = 101;
	EVENODD(a3);
	int a4 = 2016;
	CHECKLEAP(a4);
}

