// funcExer1.c
#include <stdio.h>
#include "function.h" //This file has max_users initialized

//int max_users = 200; /* This is an error as extern variable you are re-initializing */

void funcExer2()
{
	printf("%s, Max users allowed: %d\n", __func__, max_users);  // using the extern variable it will print 100 the initialized value
	max_users++; /* incrementing an extern variable is fine */
}

void greet() {
    printf("%s, Hello from utils.c!\n", __func__);
}

