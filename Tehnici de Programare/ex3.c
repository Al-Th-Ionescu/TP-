#include <stdio.h>
#include <stdlib.h>

int f(int x)
{
	if (x==0) return 0;
	else return (f(x-1)+3*x-1);
	
}

int main()
{int x ,val;
scanf("%d",&x);
val =f(x);
printf("\n'\n%d",val);
}