#include<stdio.h>
#include<stdlib.h>
//structura Obiect permite memorarea informațiilor despre un obiect
//ID-ul unui obiect este numărul său de ordine inițial
typedef struct
{
float castig, greutate;
int ID;
}Obiect;
//funcție comparator utilizată pentru a sorta un tablou cu elemente
//de tip Obiect în ordinea descrescătoare a câștigurilor unitare
int cmpObiecte(const void *a, const void *b)
{
Obiect pa = *(Obiect*)a;
Obiect pb = *(Obiect*)b;
if(pa.castig/pa.greutate < pb.castig/pb.greutate)
return 1;
if(pa.castig/pa.greutate > pb.castig/pb.greutate)
return -1;
return 0;
}
int main()
{
//n = numărul de obiecte
int i, n;
//G = capacitatea maximă a rucsacului
//total = câștigul total (maxim)
//p = fracțiunea care se va încărca din ultimul obiect care
//poate fi selectat pentru a umple complet rucsacul
float G, total, p;
//ob = obiectele date
Obiect ob[1000];
//datele de intrare se vor citi din fișierul text "obiecte.txt"
//care conține pe prima linie numărul n de obiecte, pe
//următoarele n linii sunt informațiile despre cele n obiecte
//sub forma "greutate câștig", iar pe ultima linie se găsește
//capacitatea maximă G a rucsacului
FILE* fin = fopen("rucsac.txt", "r");
fscanf(fin, "%d", &n);
for(i = 0; i < n; i++)
{
fscanf(fin, "%f %f", &ob[i].greutate, &ob[i].castig);
ob[i].ID = i+1;
}
fscanf(fin, "%f", &G);
fclose(fin);
//sortam obiectele descrescător în funcție de câștigul unitar
qsort(ob, n, sizeof(Obiect), cmpObiecte);
//inițializăm câștigul total (maxim) cu 0
total = 0;
for (i = 0; i < n; i++)
//dacă obiectul curent ob[i] încape complet în rucsac,
//îl încărcăm, după care actualizăm câștigul total și
//spațiul liber din rucsac
if (ob[i].greutate <= G)
{
printf("Obiectul %d -> 100%%\n", ob[i].ID);
total = total + ob[i].castig;
G = G - ob[i].greutate;
}
//dacă obiectul curent ob[i] nu încape complet în rucsac,
//calculăm fracțiunea din el pe care trebuie să o încărcăm
//pentru a umple complet rucsacul, actualizăm câștigul
//total și algoritmul se termină
else
{
p = G / ob[i].greutate;
printf("Obiectul %d -> %.2f%%\n", ob[i].ID, p*100);
total = total + p*ob[i].castig;
break;
}
//afișăm câștigul total (maxim) pe care l-am obținut
printf("Castig total: %.2f\n", total);
return 0;
}
