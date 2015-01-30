/* 
 * Bit-Level Data Representation Lab
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#include "btest.h"
#include <limits.h>

/*
 * Instructions to Students:
 *
 * STEP 1: Fill in the following struct with your identifying info.
 */
team_struct team =
{
  /* Team name: Replace with either:
     Your login ID if working as a one person team
     or, ID1+ID2 where ID1 is the login ID of the first team member
     and ID2 is the login ID of the second team member */
  "millerc5+morganml", 
  /* Student name 1: Replace with the full name of first team member */
  "CJ Miller",
  /* Login ID 1: Replace with the login ID of first team member */
  "millerc5",
  
  /* The following should only be changed if there are two team members */
  /* Student name 2: Full name of the second team member */
  "Max Morgan",
  /* Login ID 2: Login ID of the second team member */
  "morganml"
};

#if 0
/*
 * STEP 2: Read the following instructions carefully.
 */
 	
You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

CODING RULES:
 
Replace the "return" statement in each function with one
or more lines of C code that implements the function. Your code 
must conform to the following style:
 
int Funct(arg1, arg2, ...) {
  /* brief description of how your implementation works */
  int var1 = Expr1;
  ...
  int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
  return ExprR;
}

Each "Expr" is an expression using ONLY the following:
1. Integer constants 0 through 255 (0xFF), inclusive. You are
   not allowed to use big constants such as 0xffffffff.
2. Function arguments and local variables (no global variables).
3. Unary integer operations ! ~
4. Binary integer operations & ^ | + << >>
    
Some of the problems restrict the set of allowed operators even further.
Each "Expr" may consist of multiple operators. You are not restricted to
one operator per line.

You are expressly forbidden to:
1. Use any control constructs such as if, do, while, for, switch, etc.
2. Define or use any macros.
3. Define any additional functions in this file.
4. Call any functions.
5. Use any other operations, such as &&, ||, -, or ?:
6. Use any form of casting.
 
You may assume that your machine:
1. Uses 2s complement, 32-bit representations of integers.
2. Performs right shifts arithmetically.
3. Has unpredictable behavior when shifting an integer by more
   than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
/*
 * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
 */
int pow2plus1(int x) {
  /* exploit ability of shifts to compute powers of 2 */
  return (1 << x) + 1;
}

/*
 * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
 */
int pow2plus4(int x) {
  /* exploit ability of shifts to compute powers of 2 */
  int result = (1 << x);
  result += 4;
  return result;
}


NOTES:
1. Use the dlc (data lab checker) compiler (described in the handout) to 
   check the legality of your solutions.
2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
   that you are allowed to use for your implementation of the function. 
   The max operator count is checked by dlc. Note that '=' is not 
   counted; you may use as many of these as you want without penalty.
3. Use the btest test harness to check your functions for correctness.
4. The maximum number of ops for each function is given in the
   header comment for each function. If there are any inconsistencies 
   between the maximum ops in the writeup and in this file, consider
   this file the authoritative source.

              }
#endif

/*
 * STEP 3: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest test harness to check that your solutions produce 
 *      the correct answers. Watch out for corner cases around Tmin and Tmax.
 */

/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int
bitNor(int x, int y) {
  //DeMorgan's law
  return ~x&~y;
}

/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 2
 */
int
bitXor(int x, int y) {
  //DeMorgan's law 2x
  return ~( ~(x&~y) & ~(~x&y) );
}

/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int
isNotEqual(int x, int y) {
  //Takes the symetric difference which will only return bitwise 1 if they are not equal 
  // so when we '!' it if it was zero then we know the numbers were equal. Then we flip 
  // it again as we have the reverse.
  return !!(x^y);
}

/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int
getByte(int x, int n) {
  //Masks for the last byte then shifts x to the right after multiplying n by 2^3.
  return 0x000000ff & (x >> (n << 3));
}

/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */

int
copyLSB(int x) {
  //Shifts the first bit to the MSB spot then shifts its all the way to the right. And the shift 
  // will pull in 1s if it was 1 and 0 if it was zero.
  return   (x << 31) >> 31;
}

/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 1 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3 
 */
int
logicalShift(int x, int n) {
  //Shifts X right n times then masks using 1 shifted left 31 times 0x8000000 then shift it right 
  // the name n times - 1.
  return (x >> n) & ~(((0x1 << 31) >> n) << 1);
}

/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int
bitCount(int x) {
  // Creation of Masks
  int zeroOneZeroOne = (((((((((((((5 << 4) + 5) << 4) + 5) << 4) + 5) << 4) + 5) << 4) + 5) << 4) + 5) << 4) + 5;  // 0x55555555
  int zeroZeroOneOne = (((((((((((((3 << 4) + 3) << 4) + 3) << 4) + 3) << 4) + 3) << 4) + 3) << 4) + 3) << 4) + 3;  // 0x33333333
  int zeroZeroZeroOne = ((((((1 << 8) + 1) << 8) + 1) << 8) + 1); // 0x11111111
  int FOFOFOF = ((((((0xF << 8) + 0xF) << 8) + 0xF) << 8) + 0xF); // 0x11111111

  //Basicly we have shifting x right one then seeing what was in the two spots that there is a 1 in 5.
  // This would make numbers like 0010 which have one bit when shift left the 1 is in the correct spot.
  // And it does that for every nible.
  x = x + (~((x >> 1) & zeroOneZeroOne) + 1 );
  // Now we find how many there are in each byte;
  x = (x & zeroZeroOneOne) + ((x >> 2) & zeroZeroOneOne);
  // Shift it again and then only take the final numbers. and then shift that over 24.
  return ((x + (x >> 4) & FOFOFOF) * zeroZeroZeroOne) >> 24;

  //Taken from a question on SoF (http://stackoverflow.com/questions/9093323/efficient-bitwise-operations-for-counting-bits-or-find-the-rightleft-most-ones)
  // Take it futher by explaining why it works.
}

/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int
bang(int x) {
  //Basicly all the lines above cut the number and half and keep if any 1 that was in it and keep shifting
  // it right so all the ones combine to a singal 1. Then we flip it via xOr (if it was 1) and and that with 1.
  // to see if it was zero so if it was it return 1 if zero.
  int temp = (x >> 16) | x;
  temp = ( temp >> 8) | temp;
  temp = ( temp >> 4) | temp;
  temp = ( temp >> 2) | temp;
  return (((temp >> 1) | temp) ^ 1) & 1;
}

/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 4 
 */
int
leastBitPos(int x) {
  //By fliping its value all the zero before the LSB turn into 1 then by adding one they all flip to zero and the
  // place where the LSB is filled with a zero. Then we just AND that with the orignal number.
  return x & (~x + 1);
}

/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int
tmax(void) {
  //Take one and turn it into 0x80000000. Then flip that which turns into 0x7FFFFFFF.
  return ~(1<<31);
}

/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int
isNonNegative(int x) {
  //If a number is negative then the 32ed bit is 1 so just move that to the far right then Logical not whitch will
  // make the One (if negative) a zero, or vice-versa
  return !(x>>31);
}

/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int
isGreater(int x, int y) {
  // Xor bitwise.
  int temp = x ^ y;
  // Use the diffenece and then shift that threw the entire mask (temp) to the right.
  temp = temp | temp >> 1;
  temp = temp | temp >> 2;
  temp = temp | temp >> 4;
  temp = temp | temp >> 8;
  temp = temp | temp >> 16;

  // We take our mask and flip it then or with 0x80000000
  temp = temp & (~(temp >> 1) | (1<<31));
  //Then we flip the numbers if they are negative by xOr with 0x80000000 for the first value and then the reverse of that
  // for y. Then we and the values togeather. Then and that with our mask.
  temp = temp & ( x ^ (1<<31)) & (y ^ (~(1<<31)));
  // Then just need to double bang it as its not in 0 or 1 format.
  return !!temp;
}

/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int
divpwr2(int x, int n) {
    //Takes x then takes the sign of x and will become 0xFFFFFFFF if odd or 0x0 if even. Then it finds
    // the bit at the last posistion of the shift and add its to 0xFFFFFFFF which will mask all bits past n
    // and adds those bits to the orignal number so that when we shift right n times it does not rounding
    // correctly.

    //      X   |   Sign Of X | Bit of N | 0xFFFFFFF
    //      |       |               |           |
    //      V       V               V           V
    return (x + ((x >> 31) &    ((1 << n) +    ~0))) >> n;

    // Pre Simplified equation using 17 Ops.
//  return (((x >> n )) & ((~x)>>31)) + (((x >> n) + (1&(!!(x&( (~(1<<31))>>(31-n) ))  )))  & (x>>31));
}

/* 
 * absVal - absolute value of x (except returns TMin for TMin)
 *   Example: absVal(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int
absVal(int x) {
  //Takes the numebr and adds it to itself but after taking the sign bit and AND it with itself or NOT AND with itself
  // which effectivly one will always be zero for positive and the other zero if the orignal number was negative.
  return ((~x+1) & (x>>31)) + (x & ~(x>>31));
}

/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20bt
 *   Rating: 3
 */
int
addOK(int x, int y) {
  //Tests each case and compares its sign to with what it should be. Ie '-' + '-' is still negative and positive is still positive.
 
  return !(((x>>31)&(y>>31)&!((x+y)>>31))|(!(x>>31)&!(y>>31)&((x+y)>>31)));
}
