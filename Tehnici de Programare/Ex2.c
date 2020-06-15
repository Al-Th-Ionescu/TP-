#include <stdio.h>
#include <stdlib.h>

int F(int n)
{
	if(n==0) return 0;
	else 
		if ((n%10)>F(n/10)) 
			return n%10;
	else
	       	return F(n/10);
}

int main()
{
	int val;
	val=F(38423);
	printf("%d",val);
}
