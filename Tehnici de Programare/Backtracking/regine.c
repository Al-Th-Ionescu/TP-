#include <stdio.h>
#include <stdlib.h>

int s[101], n ;

int sol (int k)
{
	int i;
	for (i=1 ; i <k ; i++)
		if (s[k] == s[i] || abs(s[k] - s[i] ) == abs (k-i))
			return 0;
	return 1;
}

void bkt (int k)
{
	int i,v ;
	for (v=1;  v<= n ; v++)
	{ 
		s[k] = v;
		if (sol(k) == 1)
			if (k ==n)
			{ 
				for (i=1; i <=k; i++)
					printf("%d ",s[i]);
				printf("\n");
			}
			else
				bkt(k+1);
	}
}

int main()
{
	printf("n=");
	scanf("%d", &n);
	bkt(1);
	return 0;
}
	