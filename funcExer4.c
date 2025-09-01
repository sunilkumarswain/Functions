#include <stdio.h>

//extern int value1; /* This will give error as value1 is a static variable in file stat.c */
//extern void stat_func2(); /* This will give error as stat_func2 is a static function in file stat.c */
extern int val;
extern int val2;

void call_fun()
{
	printf("The value of val1 is %d\n",val);
	printf("The value of val2 is %d\n",val2);
}

