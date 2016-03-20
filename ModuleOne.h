typedef struct TheStruct{
char f;   //field
void *l;  //link
} TheType;

const TheSize = sizeof(TheType);

int number(TheType *a){                         //Shows the count of cards in array
int n=0;
while (a&&++n)
    a=a->l;
return n;
}
void create(TheType *b){                        //Makes nice 52 card array
char i,j;

for (i=0;i<=12;i++)
    for (j=0;j<=3;j++){
       b->f=i*10+j;
       if(13*j+i<51){
          b->l=malloc(TheSize);
          (b=b->l)->l=NULL;
       }
    }
}
void crempty(TheType *a){                       //Makes pure 52 cards array
char i;
for (i=0;i<51;i++){
    a->f=0;
    a=(a->l=malloc(TheSize));
    }
a->f=0;
a->l=NULL;
}
void del(TheType *a){                           //FREEs tha array
if(a->l)
    del(a->l);
free(a);
}

void delLast(TheType *a){//DTima is programmer:) //FREEs the last element
TheType *b;
b=a->l;
if(b->l)
    delLast(b);
else{
    free(b);
    a->l=NULL;
}
}

char readF(TheType *a, char pos){               //Shows the element from 'a' on 'pos'
int i;
for(i=0;i<pos;i++)
    a=a->l;
return a->f;
}
void writeF(char dost, TheType *a, char pos){   //Puts card 'dost' in 'a' on 'pos' place
int j;
for(j=0;j<pos;j++)
if ((a->l)!=NULL)  //Dima is programmer:) GUT PROGGER
    a=a->l;
else {
    a=(a->l=malloc(TheSize));
    a->f=255;
    a->l=NULL;
}
a->f=dost;
}

void vivod(TheType *a){                         //Prints array
while(a){
  printf("%6d%2d",a->f/10,a->f%10);   //!! fuck it !!
  a=a->l;// dostoinstvo^   ^mast
}
printf("\n");
}
TheType* H(TheType *a){                         //Hash
TheType *b;
char i,j,h,m;
//creating new array
b=malloc(TheSize);
b->l=NULL;
crempty(b);

//Computing non-zero variables
h=m=0;
while (!(h*m)){
h = rand() % 52;
m = rand() % 52;
}
//The Hash
for (i=0;i<=51;i++){
  j=(h*i+m) % 52;// standart hash: multiply and plussing some random elements
  while (readF(b,j)!=0)
    j=(j+1) % 52;
  writeF(readF(a,i),b,j);
}

//Deleting trash
del(a);
return b;
}

//STEPEN
unsigned long power(unsigned long x, char n){
if(n)
return x*=power(x,n-1);
else
return 1;
}
