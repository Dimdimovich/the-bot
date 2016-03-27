#include <stdio.h>
#include <stdlib.h>
#include "ModuleOne.h"
#include "ModuleTwo.h"
#include "ModuleThree.h" //-didn't work :(
//#include "Tims ModuleThree.h"

void test(){


    TheType *a,*b,*c;
    char i=1,k;
    unsigned long j;

    srand(time(NULL)); //shuffling "random" table (every time it is same)

    a=malloc(TheSize);
    a->l=NULL;

    create(a);
    vivod(a);
    a=H(H(H(a)));
    
    printf("\nAfter \"H\"\n");
    vivod(a);

    printf("\n");

    b=seven(a,i);
    vivod(b);
    /*
    c=b;
    c->f=10;//3  cherv
    (c=c->l)->f=20;//4  cherv
    (c=c->l)->f=33;//5  kresty
    (c=c->l)->f=41;//6  bubny
    (c=c->l)->f=50;//7  cherv
    (c=c->l)->f=83;//10 kresty
    (c=c->l)->f=13;//3  kresty
*/
    
    ShowMeComb(comb(b));
    vivod(b);



    del(a);


 }
