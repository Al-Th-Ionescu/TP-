#include <stdio.h>
#include <stdlib.h>

int s[101] , n , v[101] , P , nrs;

int suma (int k)
{
	int i , scrt=0;
	for (i= 1 ; i <=  k ; i++)
		scrt = scrt + s[i] * v[i];
	return scrt;
}

void bkt (int k)
{
	int i, m, scrt;
	for ( m= 0 ; m <= P/v[k] ; m++)
	{
		s[k]= m;
		scrt= suma(k);
		if (scrt <= P)
		       if (scrt==P)	
		{
			nrs ++;
			printf(" %3d. %d$ = ", nrs, P);
			for (i= 1 ; i <=k ; i++)
				if (s[i] >0)
					printf("%dx%d$+", s[i] , v[i]);
				printf("\b \n");
		}
		else
			if (k<n)
				bkt(k+1);
	}
}

int main()
{
	int i;
	printf("Numarul de monede: ");
	scanf("%d",&n);
	printf("Valorile monedelor:\n");
	for (i=1; i<=n ;i++)
	{
		printf("v[%d] = ", i);
		scanf("%d", &v[i]);
	}
	printf("Suma de plata: ");
	scanf("%d", &P);
	
	printf ("\n Modalitatile de plata: \n");
	bkt(1);
	
	if (nrs == 0)
		printf("Niciuna");
	return 0;
}
