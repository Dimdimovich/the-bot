Functions:
1. ModuleOne

1.1 The Structure
typedef struct TheStruct{
char f=255;   //field
void *l=NULL;  //link
} TheType;

1.2 const TheSize = sizeof(TheType);
Size of "The Structure" unit

1.3 int number(TheType *a);
Length of array

1.4 void create(TheType *b);
Creation of an 52card "nice" array

1.5 void crempty(TheType *a);
Creation of an 52card empty array

1.6 void delLast(TheType *a);
Destroy the last element in array

1.7 char readF(TheType *a, char pos);
Read from array << a[pos] >>

1.8 void writeF(char dost, TheType *a, char pos);
Puts card 'dost' in 'a' on 'pos' place
creates if not exist
rewrites if exist

1.9 vivod(TheType *a);
Prints array

1.10 TheType* H(TheType *a);
Hashs "H" from "a"

1.11 unsigned long power(unsigned long x, char n);
Power (10^3=1000)

2. ModuleTwo

2.1 TheType* seven(TheType *a, char gambler);
Returns 5 common & 2 "gambler"'s cards from "a" in array "seven"

2.2 void sortV(TheType *a);
Sort by Value

2.3 void sortM(TheType *a);
Sort by type (MACTb)

3. ModuleThree

3.1 unsigned long IsStreet(TheType *a);
Returns (street || 0)
needs sortV "seven()"

3.2 unsigned long comb(TheType *a);
returns any combination in a numeric type, coded in bytes:

Main byte:
0: Oldest card
1: Pair
2: Two Pairs
3: Set
4: Street
5: Flush
6: Full House
7: Care
8: Street-Flush
9: Royal Flush

Other bytes:
Cards that are worth to be known.

P.S.
Card is also byte: [0-12][0-3]
                  Volume  MACTb