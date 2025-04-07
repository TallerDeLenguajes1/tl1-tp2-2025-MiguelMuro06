// codigo a completar
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 20
int main (){

int i;
double vt[N];
srand(time(NULL));
for(i = 0;i<N; i++)
{
*(vt +i)=1+rand()%100;
printf("El número en vt[%d] es: %.2f\n", i, *(vt + i));
}
return 0;
}