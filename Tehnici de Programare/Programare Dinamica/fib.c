#include <stdio.h>
#include <stdlib.h>

unsigned long long int fib(int n)
{
	unsigned long long int i;
	unsigned long long int f[101];
	f[1]=0;
	f[2]=1;
	for (i = 3 ; i <= n ; i++)
		f[i]= f[i-2] + f[i-1];
	return f[n];
}

int main()
{
	unsigned long long int n;
	printf("n=");
	scanf("%llu",&n);
	printf("\n %llu \n",fib(n));
	return 0;
}
