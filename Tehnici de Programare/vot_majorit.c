#include <stdio.h>
#include <stdlib.h>


int bruteForceMajority(int n, int *a)
{	
    for (int i = 0; i < n; i++) {
	
        int nr = 1;
	
        for (int j = 0; j < n; j++) {
	
            if (a[j]==a[i])
	
                nr++;
	
        }
	
        if  (nr > n / 2)
	
            return a[i];      
	
    }
	
    return -1;
	
}

int main()
{
	int n,*v,sol,i;
	FILE* f;
	f=fopen("vot.txt","r");
	fscanf(f,"%d",&n);
	v=malloc(n*sizeof(int));
	for (i=0; i<n; i++)
		fscanf(f, "%d" , &v[i]);
	sol=bruteForceMajority(n,v);
	if (sol != -1)  
		printf("DA \n %d \n", sol);
	else 
		printf("\n Nu\n");
	free(v);
	fclose(f);
	return 0;
}
