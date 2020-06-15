#include <stdio.h>
#include <stdlib.h>

void citire_vector(int* v,int n)
{
	int i;
	
	for (i =0 ; i<n ; i++)
	{
		printf("\nElementul v[%d] =", i);
		scanf("%d",&v[i]);
	}
}

int divide(int* v, int st, int dr )
{
	int   mij;
	if (st == dr) 
		return v[st];
	else
	{
		mij =(st +dr)/2;
		return divide(v,st,mij) + divide(v,mij+1,dr);
	}
}

int main()
{
int *v , n, sum =0;
printf("Introduceti numarul de elemente:");
	scanf("%d", &n);
	v=malloc(n*sizeof(int));
citire_vector(v,n);
sum = divide(v, 0 ,n-1);
 for (int i =0 ; i <n ; i++)
	 printf ("\n  v[%d] = %d \n \n",i, v[i]);
printf("\n\nSuma elementelor este: %d \n",sum);
free(v);
}
