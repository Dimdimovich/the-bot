TheType* seven(TheType *a, char gambler){
TheType *arr, *b;
char i;
arr=malloc(TheSize);
b=arr;
b->f=readF(a,0);
for(i=1;i<5;i++){
  b=(b->l=malloc(TheSize));
  b->f=readF(a,i);
}
for(i+=2*(gambler-1);i<5+2*gambler;i++){
  b=(b->l=malloc(TheSize));
  b->f=readF(a,i);
}
  b->l=NULL;
return arr;
};

void sortV(TheType *a){                         //Sort by value
    char i,j,k=0,n=number(a),l;

    for(k=0;k<n;k++)
        for(i=0;i<k;i++)
            if(readF(a,i)<readF(a,k)){
                l=readF(a,k);
                for(j=k-1;j>=i;j--)
                    writeF(readF(a,j),a,j+1);
                writeF(l,a,i);
            }
}

void sortM(TheType *a){                         //Sort by type (MACTb)
    char i,j,k=0,n=number(a),l;

    for(k=0;k<n;k++)
        for(i=0;i<k;i++)
            if(readF(a,i)%10<readF(a,k)%10){
                l=readF(a,k);
                for(j=k-1;j>=i;j--)
                    writeF(readF(a,j),a,j+1);
                writeF(l,a,i);
            }
}
