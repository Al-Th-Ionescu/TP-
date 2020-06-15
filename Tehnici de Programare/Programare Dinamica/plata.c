#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i , j ,P , v[101], nrmin[101] , pred[101];
	FILE *f;
	f=fopen("monede.txt","r");
	fscanf(f,"%d", &n);
	for (i = 0; i <n ; i++)
		fscanf(f,"%d", &v[i]);
	fscanf(f,"%d", &P);
	fclose(f);

	for ( i = 0; i <= P ; i++)
	{ 
		nrmin[i]=P+1;
		pred[i] = -1;
	}
	nrmin[0] = 0;
	for ( i = 1 ; i <= P ; i++)
		for (j = 0 ; j < n ; j++)
			if (1+ nrmin[i-v[j]] < nrmin[i] )
			{
				nrmin[i] = 1 + nrmin[i-v[j]];
				pred[i]= v[j];
			}
	if (nrmin[P] == P +1 )
		printf("Suma %d nu poate fi platita!", P);
	else
	{
		printf("Suma %d se poate plati folosind minim %d monede ! \n", P, nrmin[P]);
		printf("O modalitate optima de plata a sumei %d : \n", P);
		for (i= P; pred[i] != -1 ; i = i -pred[i])
			printf("%d", pred[i]);
	}
	return 0;
}
