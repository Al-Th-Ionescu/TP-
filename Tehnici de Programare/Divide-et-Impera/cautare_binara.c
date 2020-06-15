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

int cautare_binara(int* v, int st, int dr, int x)
{   
	int mij;
	if (st>dr)
		return -1;
	else 
	{
		mij = (st+dr)/2;
		if (x == v[mij])
			return mij;
		else if (x < v[mij])
			return cautare_binara(v,st, mij ,x);
		else
			return cautare_binara(v, mij+1, dr ,x);
	}
}
int main ()
{
	int *v, n,q,x;
	printf("Dati numarul de termeni:");
	scanf("%d", &n);
	printf("\n");
	citire_vector(v,n);
	printf("\nDati numarul cautat:");
	scanf("%d", &x);
	q = cautare_binara(v, 0, n-1, x);
	if (q != -1)
		printf("Numarul %d se gaseste in vector \n", x);
	else
		printf("Numarul %d NU se gaseste in vector \n",x);
}
