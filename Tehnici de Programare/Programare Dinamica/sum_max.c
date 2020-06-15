#include <stdio.h>
#include <stdlib.h>

int maxim (int a, int b)
{
	return a>b ? a:b;
}

int main()
{
	int n , i , j , t[100][100], smax[100][100];
	FILE *f;
	f=fopen("triunghi.txt","r");
	fscanf(f,"%d", &n);
	for ( i=0; i<n ; i++)
		for (j=0; j<= i ; j++)
			fscanf(f,"%d", &t[i][j]);
	fclose(f);

	for (i=0; i<n ; i++)
		smax[n-1][i] = t[n-1][i];

	for (i = n-2; i>= 0 ; i--)
		for ( j=0; j <= i ;j++)
			smax[i][j] = t[i][j] + maxim(smax[i+1][j], smax[i+1][j+1]);
	printf("Suma maxima: %d \n", smax[0][0]);
	printf("\n Traseul cu suma maxima:\n");
	j=0;
	for (i=0; i<n-1 ; i++)
	{
		printf("t[%d][%d] ->", i ,j);
		if (smax[i+1][j+1] > smax[i+1][j]) 
			j++;
	}
	printf("t[%d][%d]\n",i,j);
	return 0;
}

