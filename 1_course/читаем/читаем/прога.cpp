#include <stdio.h>
#include <stdlib.h>

void vvod(char *ar, int &n);
bool bolshe(char a[], int na, char b[], int nb);
bool ravno(char a[], int na, char b[], int nb);
void pervl(char a[], int na, char b[], int nb, char l[], int &nl);
void nol(char *ar, int &m, int n);
void vichitanie(char a[], int &n, char b[], int &m);

int main()
{
    char
    a[1000], // Делимое
    b[1000], // Делитель
    c[1000], // Частное
    m[1000], // Вычитаемое
    l[1000]; // Остаток
    int
    na,nb,nc,nm,nl; // Число цифр
    int i,j,start;
    
    printf("„Ґ«Ґ­ЁҐ\n\n");
    // Инициализация
    vvod(a,na);
    printf("/\n\n");
    vvod(b,nb);
    nc = 0;
    c[0] = 0;  // В случае деления на большее число
    // Первая цифра
    pervl(a,na,b,nb,l,nl);
    for (i=0; i<nb; i++)
      m[i] = b[i];
    nm = nb;
    start = nl;
    if (!(ravno(l,nl,a,na) && bolshe(b,nb,a,na))) {
      for (i=0; bolshe(l,nl,m,nm) || ravno(l,nl,m,nm); i++)
        vichitanie(l,nl,m,nm);
      c[nc] = i;
      }
    nc++;
    // Следуущие цифры
    for (i=start; i<na; i++) {
      l[nl] = a[i]; nl++;
      while(l[0]==0) {
        for(j=0; j<nl-1; j++)
        l[j]=l[j+1];
        if(nl!=1) nl--; else break;
        }
      for (j=0; bolshe(l,nl,m,nm) || ravno(l,nl,m,nm); j++)
      vichitanie(l,nl,m,nm);
      c[nc] = j; nc++;
      }
    // Ответ
    printf("ЋвўҐв: ");
    for (i=0; i<nc; i++)
      printf("%d",c[i]);
    printf("\n");
    printf("Ћбв в®Є: ");
    for (i=0; i<nl; i++)
      printf("%d",l[i]);
    // Пауза
    printf("\n\n");
    system("PAUSE");
    
    return 0;
}
// ----------------------------------------------------------------------------
//Ввод данных
void vvod(char *ar, int  &n)
{
 	int i=0;
 	
 	printf("‚ўҐ¤ЁвҐ зЁб«®: ");
 	ar[i]=getchar();
 	while(ar[i]!='\n') {
      ar[i]-=48;
      i++;
      ar[i]=getchar();
      }
	n=i;
	printf("\n");
}
// Больше
bool bolshe(char a[], int na, char b[], int nb)
{
    int i;
    
    if (na>nb) return true;
    else if (nb>na) return false;
    else
      for (i=0; i<na; i++)
      if (a[i]>b[i]) return true;
      else if (b[i]>a[i]) return false;
    
    return false;
}
// Равно
bool ravno(char a[], int na, char b[], int nb)
{
    int i;
    
    if (na!=nb) return false;
    else
      for (i=0; i<na; i++)
      if (a[i]!=b[i]) return false;
    
    return true;
}
// Первое вычитаемое
void pervl(char a[], int na, char b[], int nb, char l[], int &nl)
{
    int i;
    
    if (bolshe(b,nb,a,na)) {
       for (i=0; i<na; i++)
         l[i] = a[i];
       nl = na;
      } else {
    for (i=0; i<nb; i++) 
      l[i] = a[i];
    nl = nb;
    if (bolshe(b,nb,l,nl)) {
      l[nl] = a[nl];
      nl++;
      }
    }
}
// Дополняем нулями
void nol(char *ar, int &m, int n)
{
 	int i,j;
 	
	for(i=0; i<n-m; i++)
	  for(j=n-1; j>0; j--)
        ar[j]=ar[j-1];
	
    for(i=0; i<n-m; i++)
      ar[i]=0;
    
    m=n;	
}
// Вычитание
void vichitanie(char *a, int &n, char *b, int &m)
{
    char c[1000];
    int i,j,o;
    
    //Дополняем нулями
    if(n>m) nol(b,m,n);
    else if(n<m) nol(a,n,m);
    //Обнуляем резултат
    for(i=0; i<n; i++)
      c[i]=0;
   //Вычитание
    o=0;
    for(j=n-1; j>=0; j--) {
      c[j] += a[j] - b[j] + o;
 	    o=0;
      if(c[j]<0) {
        o=-1;
        c[j]=10 + c[j];
        }
      }
    //Избавляемся от ведущих нулей
    while(c[0]==0) {
      for(j=0; j<n-1; j++)
        c[j]=c[j+1];
      if(n!=1) n--; else break;
      }
    while(b[0]==0) {
      for(j=0; j<m-1; j++)
        b[j]=b[j+1];
      if(m!=1) m--; else break;
      }
    //Вывод результата
    for(i=0; i<n; i++)
      a[i] = c[i];
}