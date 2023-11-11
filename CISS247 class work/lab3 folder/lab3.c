#include <stdio.h>

/* compute the bit-wise AND of two integers, using only the ~ and | */
int func1(int x, int y){
	return ~(~x | ~y);
}
/*compute the bit-wise exclusive-or of two integers, using only the ~ and & operators */
int func2(int x, int y){
	return ~(~(x & ~y) & ~(~x & y));
}
/*  return 1 if any odd-numbered bit in an integer is set to 1, and return 0 otherwise. (The least significant bit is bit number 0). */
int func3(int x){
int mask = 0xAA | (0xAA << 8) | (0xAA << 16) | (0xAA << 24);
	 return !!(x & mask);
}
/* return 1 if all the odd-numbered bits in an integer are set to 1, and return 0 otherwise. */
int func4(int x){
    int mask = 0xAA | (0xAA << 8) | (0xAA << 16) | (0xAA << 24);
   
	return !((x & mask) ^ mask);
}

int main(){

int x=19,y=18;
printf("func1(19,18) = %d\n",func1(x,y));//Test Function 1

 x=1,y=3;
printf("func2(1,3) = %d\n",func2(x,y));//Test Function 2

 x=0x11;
printf("func3(0x11) = %d\n",func3(x));//Test Function 3

x=0xAAAAAAAA;
printf("Func4(0xFFFFFFFD) = %x\n",func4(x));//Test Function 4

return 0;

}
