#include <stdio.h>
#include <stdlib.h>
//structura Proiect permite stocarea informațiilor despre un
//proiect, ID-ul fiind numărul său de ordine inițial
typedef struct
{
int ID, termen;
float profit;
}Proiect;
//funcție comparator utilizată pentru a sorta un tablou cu elemente
//de tip Proiect în ordinea descrescătoare a profiturilor
int cmpProiecte(const void *a, const void *b)
{
Proiect pa = *(Proiect*)a;
Proiect pb = *(Proiect*)b;
if(pa.profit < pb.profit)
return 1;
if(pa.profit > pb.profit)
return -1;
return 0;
}
int main()
{
//n = numărul de proiecte, zmax = maximul termenelor limită
int n, zmax, i, j;
//pmax = profitul maxim obținut de echipă
float pmax;
//p = tablou care conține informațiile despre cele n proiecte
//z = tablou care conține planificarea optimă (cu câștig maxim)
Proiect *p, *z;
FILE *f;
//citirea datelor din fișierul de intrare
f = fopen("proiecte.in", "r");
fscanf(f,"%d", &n);
//alocăm dinamic tabloul p, în care vom memora informațiile
//despre cele n proiecte
p = (Proiect*)malloc(n * sizeof(Proiect));
//în timpul citirii informațiilor despre proiecte, calculăm
//maximul termenelor limită în variabila zmax
zmax = 0;
for(i = 0; i < n; i++)
{
p[i].ID = i + 1;
fscanf(f, "%d %f", &p[i].termen, &p[i].profit);
if(p[i].termen > zmax)
zmax = p[i].termen;
}
fclose(f);
//în tabloul z vom planifica proiectele pe zile, iar zilele
//posibile sunt 1,2,...,zmax, deci îl alocăm cu zmax+1 elemente
//am utilizat funcția calloc pentru a inițializa toate câmpurile
//fiecărui element de tip structură cu valori nule
z = (Proiect*)calloc(zmax+1, sizeof(Proiect));
//sortăm proiectele descrescător după profituri
qsort(p, n, sizeof(Proiect), cmpProiecte);
//inițializăm profitul maxim pmax care poate obținut de echipă
pmax = 0;
//încercăm să planificăm fiecare proiect cât mai târziu posibil,
//dar fără a-i depăși termenul limită, deci căutăm prima zi
//liberă începând cu termenul său limită
for(i = 0; i < n; i++)
for(j = p[i].termen; j >= 1; j--)
//dacă z[j].ID este 0, înseamnă că nu am planificat
//niciun proiect în ziua respectivă (ID-urile
//proiectelor sunt cuprinse între 1 și n), deci ziua
//respectivă este liberă
if(z[j].ID == 0)
{
z[j] = p[i];
pmax = pmax + p[i].profit;
//este esențial să ne oprim după ce planificăm
//un proiect într-o anumită zi j, altfel el va
//fi planificat și în toate zilele 1,2,...,j-1
//care sunt libere!!!
break;
}
//scriem planificarea optimă în fișierul text de ieșire
f = fopen("proiecte.out", "w");
for(i = 1; i <= zmax; i++)
if(z[i].ID != 0)
fprintf(f, "Ziua %d: Proiectul %d - %.2f RON\n",
i, z[i].ID, z[i].profit);
fprintf(f, "\nProfitul maxim al echipei: %.2f RON", pmax);
fclose(f);
//eliberăm cele două tablouri alocate dinamic
free(p);
free(z);
return 0;
}
