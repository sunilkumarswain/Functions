/* Given a positive integer number n, your task is to calculate the difference between the product of its digits and the sum of its digits. */
#include <stdio.h>

int productSumDiff(int );

int productSumDiff(int n)
{
    int rem, product = 1, sum = 0;
    while(n > 9)
    {
        rem = n%10;
        printf("Got remainder:%d\n", rem);
        product *= rem;
        sum += rem;
        n /= 10;
        printf("Got new number:%d\n", n);
    }
    sum += n;
    return (product - sum);
}

void funcExer6()
{
	 int res, num = 1010;
	 res = productSumDiff(num);
    	 printf("%d\n", res);
}
