#include<stdio.h>
int s[101], n, m;
void bkt(int k)
{
int i, v;
for(v = s[k-1]+1; v <= n; v++)
{
s[k] = v;
if(k == m)
{
for(i = 1; i <= k; i++)
printf("%d ", s[i]);
printf("\n");
}
else
bkt(k+1);
}
}
int main()
{
printf("n = ");
scanf("%d", &n);
printf("m = ");
scanf("%d", &m);
bkt(1);
return 0;
}
