unsigned long combT(TheType *a, unsigned long c){
if ( c%power(16,6)/power(16,5)==7 || c%power(16,6)/power(16,5)==8 )
    return c;     //фуллхаус или каре
TheType *b=a;
char i,n=1,k=1;
sortM(b);

    //ищем наш любимый флеш:
    // i - цвет, n - счетчик одинаковых цветов подряд, k - счетчик не обнуляется
i=b->f%10;
b=b->l;
while(b&&n<5){
    k++;
    if(i==b->f%10) n++;
    else {n=1; i=b->f%10;}
    b=b->l;
}
if (n<5) return c; //noFlush
//else:
unsigned long C=((((16*5+readF(a,k-5)/10+1)*16+readF(a,k-4)/10+1)*16+readF(a,k-3)/10+1)*16+readF(a,k-2)/10+1)*16+readF(a,k-1)/10+1;
if (C-c==power(16,5)){//StreetFlash
  C+=3*power(16,6);
  if(C%power(16,5)/power(16,4)==12)
    C+=16^5; //K.O.
  }

return C;
}

    /*Комбинации:
0    0 СтК
1    1 Пара
2   10 Парапар
3   11 Тройка
4  100 Стрит
5  101 Флеш        x
6- 110 ФуллХаус
7- 111 Каре
8 1000 СтритФлеш   x
9 1001 =☺ -> Royal x

 усл обзн: [5]~[16^5], [4]~[16^4], т.д.
 Строение переменной:
 xxxx xxxx Koмб Кар1 Кар2 Кар3 Кар4 Кар5
 %8/7 %7/6 %6/5 %5/4 %4/3 %3/2 %2/1 %1/0
*/

 //Удобночитаемый вывод:
 void ShowMeComb(unsigned long c){
 char i;
 switch (c/power(16,5)) {
 case 0:  printf("High Card "); break;
 case 1:  printf("Pair "); break;
 case 2:  printf("Two Pairs "); break;
 case 3:  printf("Kind of a Three "); break;
 case 4:  printf("Street "); break;
 case 5:  printf("Flash "); break;
 case 6:  printf("Full House "); break;
 case 7:  printf("Quads "); break;
 case 8:  printf("StreetFlash "); break;
 case 9:  printf("Royal Flash "); break;
 default: printf("GOT ERROR \"%d\" IN \"CASE\"",c/power(16,5));
 }
 for(i=0;i<5;i++)
 printf("%3d",c%power(16,(5-i))/power(16,(4-i))-1);
 printf("\n\n");
 }

unsigned long street(TheType *b){
TheType *a;
char i,n,k,ar[5];
sortV(b);
if(b->f/10==12)
    writeF(0-1,b,number(b));
a=b;
k=1;
n=0;
i=b->f/10;
while(b->l&&k<5){
    if((b=b->l)->f/10==i);
    else if(b->f/10==i+1) {ar[k-1]=readF(a,n); k++; i++;}
    else {k=1;i=b->f/10;}
    n++;
}
if(a->f/10==12) delLast(a);
if(k=5)
    if(ar[0]>5) return (((((4*16+ar[0]/10+1)*16+ar[1]/10+1)*16+ar[2]/10+1)*16+ar[3]/10+1)*16+ar[4]/10+1);
    else return (((((4*16+ar[0]/10+1)*16+ar[1]/10+1)*16+ar[2]/10+1)*16+ar[3]/10+1)*16+ar[4]/10+1);
else return 0;
}
