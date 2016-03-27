unsigned long IsStreet(TheType *a){ // input sortV "SEVEN()"
    char i,j=0; //<- just count
    char n=number(a); //n=7 or n=8
    if (readF(a,0)/10 == 12) writeF(-10,a,n++); //may be wheel
    for (i=0; i < n-1; i++) { //just the street
        if (j == 4) {
            if (n == 8) delLast(a);
            return (4*16+readF(a,i-4)/10+1)*16*16*16*16;  //street already !check enough 16? ENOUGH!
            }
        if ((readF(a,i)/10 - readF(a,i+1)/10) == 1) j++; //may be street, I believe this
        else
            if (readF(a,i)/10 == (readF(a,i+1)/10)) ; //may be street, may be no...
            else j=0; //:( ohh... street! where are you???
    }
    if (n == 8) delLast(a);
    return 0;// no wheel, no street :(
    }


unsigned long comb(TheType *a){ // input "SEVEN()"
    unsigned long c=0; //buf
    char i,j;
    sortV(a);
    char n=number(a);//  n==7
    /*
    c=IsStreet(a);
    if (c) return c; // if below failed
    */
    if (c=IsStreet(a)) return c; //!check
    for (i=0; i<n; i++) {
        if ((i+1<n)&&(readF(a,i)/10)==(readF(a,i+1)/10))
            if ((i+2<n)&&(readF(a,i+1)/10)==(readF(a,i+2)/10))
                if ((i+3<n)&&(readF(a,i+2)/10)==(readF(a,i+3)/10)){          //care
                    if (i!=0)
                        c=(readF(a,0)/10);
                    else
                        c=(readF(a,i+4)/10);
                    return ((((7*16+(readF(a,i)/10+1))*16+c+1)*16+0)*16+0)*16+0;
                }          // care     card4        card+1
                else {                                                       //three
                    c=(3*16+readF(a,i)/10+1)*16;
                    //three   card3
                    for (j=0; (j<i)&&(j<2); j++) {
                        c=(c+readF(a,j)/10+1)*16;
                    }

                    for (j=i+3; (i<2)&&(j-3)<2; j++) {
                        c=(c+readF(a,j)/10+1)*16;
                    }
                    return (c+0)*16+0; //three

                }
            else {                                                           //pare
                c=(1*16+readF(a,i)/10+1)*16;
                for (j=0; (j<i)&&(j<3); j++) {
                    c=(c+readF(a,j)/10+1)*16;
                }
                for (j=i+2; (i<3)&&(j-2)<3; j++) {
                    c=(c+readF(a,j)/10+1)*16;
                }
                return c+1;                                                  //couple
            }
        else ;
    }
    return c;
}
 //Удобночитаемый вывод: by Tim
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



