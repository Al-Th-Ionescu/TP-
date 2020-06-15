#include<stdio.h>
#include<stdlib.h>
//structura Spectacol permite memorarea informațiilor despre un
//spectacol: numărul de ordine inițial (ID), ora de început (ts)
//și ora de terminare (tf) – ambele ore fiind memorate în minute
//față de miezul nopții
typedef struct
{
int ID, ts, tf;
}Spectacol;
//funcție comparator utilizată pentru a sorta un tablou cu elemente
//de tip Spectacol în ordinea crescătoare a orelor de terminare
int cmpSpectacole(const void *p, const void *q)
{
return ((Spectacol*)p)->tf - ((Spectacol*)q)->tf;
}
int main()
{
//n = numărul de spectacole date, k = numărul maxim de
//spectacole programate, iar hs, ms, hf, mf = variabile
//utilizate pentru a citi un interval orar de forma hh:mm-hh:mm
int i, k, n, hs, ms, hf, mf;
//S = spectacolele date, P = spectacolele planificate
Spectacol S[100], P[100];
//datele de intrare se citesc din fișierul "spectacole.txt"
//care conține pe prima linie numărul de spectacole n, iar pe
//fiecare din următoarele n linii câte un interval de
//desfășurare al unui spectacol (de forma hh:mm-hh:mm)
FILE *fin = fopen("spectacole.txt", "r");
fscanf(fin, "%d", &n);
for(i = 0; i < n; i++)
{
fscanf(fin, "%d:%d-%d:%d", &hs, &ms, &hf, &mf);
//ID-ul unui spectacol este numărul său de ordine inițial
S[i].ID = i + 1;
//ora de început și ora de terminare se transformă în minute
//față de miezul nopții
S[i].ts = hs * 60 + ms;
S[i].tf = hf * 60 + mf;
}
fclose(fin);
//sortăm spectacolele în ordinea crescătoare a orelor de
//terminare
qsort(S, n, sizeof(Spectacol), cmpSpectacole);
//planificăm primul spectacol, deci numărul k al spectacolelor
//planificate devine 1
P[0] = S[0];
k = 1;
//pentru fiecare spectacol rămas, verificăm dacă începe după
//ultimul spectacol programat și, în caz afirmativ, îl adăugăm
//și pe el în planificarea optimă
for(i = 1; i < n; i++)
if(S[i].ts >= P[k-1].tf)
P[k++] = S[i];
//afișăm soluția optimă determinată
printf("O planificare cu numar maxim de %d spectacole:\n", k);
for(i = 0; i < k; i++)
printf("S%d -> %02d:%02d-%02d:%02d\n", P[i].ID,
P[i].ts/60, P[i].ts%60, P[i].tf/60, P[i].tf%60);
return 0;
}
