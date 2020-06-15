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

void interclasare(int* t, int st, int mij, int dr)
{
	int i=st, j = mij+1, k=0, *aux;
	aux= malloc((dr-st+1) * sizeof(int));
	while(i <= mij && j <=dr)
		if (t[i] <= t[j])
			aux[k++] = t[i++];
		else
			aux[k++] = t[j++];
	while (i <= mij) 
		aux[k++] = t[i++];
	while (j <=dr)
		aux[k++] = t[j++];
	k=0;
	for (i=st; i <= dr; i++)
		t[i] = aux[k++];
	free(aux);
}

void mergesort(int* t, int st, int dr)
{
	int mij;
	if (st < dr)
	{
		mij = (st+dr)/2;
		mergesort(t,st,mij);
		mergesort(t,mij+1,dr);
		interclasare(t,st,mij,dr);
	}
}

int main()
{
	int* v;
	int n,i;
	printf("Dati numarul de elemente:");
	scanf("%d", &n);
	printf("\n");
	v=malloc(n*sizeof(int));
	citire_vector(v,n);
	mergesort(v, 0, n-1);
	for (i = 0; i < n ; i++)
		printf(" %d ", v[i]);
	printf("\n");
	free(v);
}
	
