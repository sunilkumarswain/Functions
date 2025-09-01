// funcExer1.c
#include <stdio.h>

#include "function.h"

int max_users = 100;  // actual definition (memory is allocated here) goes to data segment

void funcExer1()
{
	printf("%s, Max users allowed: %d\n", __func__, max_users);  // using the extern variable
	max_users++;
	max_users++;
	printf("%s, now max_users will print: %d\n", __func__, max_users); /* here max_users will print 102 */
	greet(); /* Using extern as function */
}
