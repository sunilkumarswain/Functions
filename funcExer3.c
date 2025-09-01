#include <stdio.h>
#include "function.h"

void stat_func(void);
void stat_func1();
static void stat_func2();

int val2 = 90;
static int value1;

void funcExer3()
{
	int count = 0;
	for(count = 0; count < 4; count++)
	{
		printf("Now at iteration %d\n",count);
		printf("=========================\n");
		stat_func();
	}
	static int uninitialized; /* An uninitialized static variable */
	printf("Uninitialized static variable is always set to %d\n",uninitialized);
	stat_func1();
	call_fun();
}

void stat_func()
{
	int loc_var = 0; /* This value always set to 0 everytime function is called */
	static int stat_var = 0; /* Here this value keeps incrementing after every call though it is set to 0 */
	stat_var++;
	loc_var++;
	printf("Now loc_var value is %d \n",loc_var);
	printf("Now stat_var value is %d \n",stat_var);
	/* printf("Static variable value %d\n",value); */
	/* This will give error as value is declared later in the file */
	//printf("Static variable val %d\n",val);
	printf("variable val2 %d\n",val2);
	printf("Static variable is %d\n",value1);
}
static int value;
int val = 89;
void stat_func1()
{
	printf("Static variable value %d\n",value);
	printf("Global variable val %d\n",val);
	printf("Global variable val2 %d\n",val2);
	printf("Static variable is %d\n",value1);
}
static void stat_func2()
{
	printf("Hello World\n");
}

