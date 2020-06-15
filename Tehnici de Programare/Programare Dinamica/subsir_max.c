#include <stdio.h>
#include <stdlib.h>

int n, t[100], lmax[100], pred[100];

int maxim(int a, int b)
{
	return a>b ? a:b; 
}

void afisare(int i)
{
	if ( i!= -1)
	{
		afisare(pred[i]);
		printf("%d ", t[i]);
	}
}

int main()
{
	int i,j ,pmax;
	FILE *f;
	f=fopen("sir.txt","r");
	fscanf(f,"%d", &n);
	for (i =0; i<n;i++)
		fscanf(f,"%d", &t[i]);
	fclose(f);

	lmax[0]=1;
	pred[0]=-1;
	for (i=1; i<n;i++)
	{
		lmax[i]=1;
		pred[i]=-1;
		for (j=0; j<i ; j++)
			if (t[i] >= t[j] && 1+lmax[j] >lmax[i])
			{
				lmax[i] = 1 + lmax[j];
				pred[i] = j;
			}
	}
	pmax = 0;
	for (i = 1; i < n; i++)
		if (lmax[i] > lmax[pmax])
			pmax = i;
	printf("Lungimea maxima a unui subsir crescator: %d \n", lmax[pmax]);
	printf("Un subsir crescator maximal: \n");
	afisare(pmax);
	printf("\n");
	return 0;
}
