/* WARNING: Do not include any other libraries here,
 * otherwise you will get an error while running test.py
 * You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 *
 * Using printf will interfere with our script capturing the execution results.
 * At this point, you can only test correctness with ./btest.
 * After confirming everything is correct in ./btest, remove the printf
 * and run the complete tests with test.py.
 */

 /*
 * bitAnd - x & y using only ~ and |
 * Example: bitAnd(4, 5) = 4
 * Legal ops: ~ |
 * Max ops: 7
 * Difficulty: 1
 */
int bitAnd(int x, int y) {
    int aTemp,answer;
    aTemp = ~x | ~y;
    answer= ~aTemp;
    return answer;
}

/*
 * bitXor - x ^ y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 7
 *   Difficulty: 1
 */
int bitXor(int x, int y) {
    int aOR,aAND, answer;
    aOR = ~x & ~y;
    aOR =~aOR;
    aAND = x&y;
    answer = aOR & ~aAND;
    return answer;
}

/*
 * samesign - Determines if two integers have the same sign.
 *   0 is not positive, nor negative
 *   Example: samesign(0, 1) = 0, samesign(0, 0) = 1
 *            samesign(-4, -5) = 1, samesign(-4, 5) = 0
 *   Legal ops: >> << ! ^ && if else &
 *   Max ops: 12
 *   Difficulty: 2
 *
 * Parameters:
 *   x - The first integer.
 *   y - The second integer.
 *
 * Returns:
 *   1 if x and y have the same sign , 0 otherwise.
 */
int samesign(int x, int y) {
    if (!x && !y){
        return 1;
    }else if(!x){
        return 0;
    }else if(!y){
        return 0;
    }
    x >>= 31;
    y >>= 31;
    return !(x^y);
}

/*
 * logtwo - Calculate the base-2 logarithm of a positive integer using bit
 *   shifting. (Think about bitCount)
 *   Note: You may assume that v > 0
 *   Example: logtwo(32) = 5
 *   Legal ops: > < >> << |
 *   Max ops: 25
 *   Difficulty: 4
 */
int logtwo(int v) {
    int testlength;
    int number=0;
    testlength = (v>>16) > 0;
    testlength = testlength<<4;
    number = number|testlength;
    v = v>>testlength;
    testlength = (v>>8) > 0;
    testlength = testlength<<3;
    number = number|testlength;
    v = v>>testlength;
    testlength = (v>>4) > 0;
    testlength = testlength<<2;
    number = number|testlength;
    v = v>>testlength;
    testlength = (v>>2) > 0;
    testlength = testlength<<1;
    number = number|testlength;
    v = v>>testlength;
    testlength = (v>>1) > 0;
    number = number|testlength;
    return number;
}

/*
 *  byteSwap - swaps the nth byte and the mth byte
 *    Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *              byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *    Note: You may assume that 0 <= n <= 3, 0 <= m <= 3
 *    Legal ops: ! ~ & ^ | + << >>
 *    Max ops: 17
 *    Difficulty: 2
 */
int byteSwap(int x, int n, int m) {
    int nShift = n<<3;
    int mShift = m<<3;
    int mask= (0xFF<<nShift)|(0xFF<<mShift);
    int answer = (x & ~mask)|(((x>>nShift)&0xFF)<<mShift)|(((x>>mShift)&0xFF)<<nShift);
    return answer;
}

/*
 * reverse - Reverse the bit order of a 32-bit unsigned integer.
 *   Example: reverse(0xFFFF0000) = 0x0000FFFF reverse(0x80000000)=0x1 reverse(0xA0000000)=0x5
 *   Note: You may assume that an unsigned integer is 32 bits long.
 *   Legal ops: << | & - + >> for while ! ~ (You can define unsigned in this function)
 *   Max ops: 30
 *   Difficulty: 3
 */
unsigned reverse(unsigned v) {
    unsigned reversed=0;
    int n=32;
    while(n){
        reversed=reversed<<1;
        reversed=reversed+(v&1);
        v=v>>1;
        n=n-1;
    }
    return reversed;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Note: You can assume that 0 <= n <= 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Difficulty: 3
 */
int logicalShift(int x, int n) {
    int mask;
    mask=((1<<31)>>n)<<1;
    x=x>>n;
    mask=~mask;
    x=x&mask;
    return x;
}

/*
 * leftBitCount - returns count of number of consective 1's in left-hand (most) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12,
 *             leftBitCount(0xFE00FF0F) = 7
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Difficulty: 4
 */
int leftBitCount(int x) {
    x=~x;
    int num=0;
    int verify=0;
    verify=!!(x>>16);
    verify=verify<<4;
    num+=verify;
    x = x >> verify;
    verify=!!(x>>8);
    verify=verify<<3;
    num+=verify;
    x = x >>verify;
    verify=!!(x>>4);
    verify=verify<<2;
    num+=verify;
    x = x >> verify;
    verify=!!(x>>2);
    verify=verify<<1;
    num+=verify;
    x = x >> verify;
    verify=!!(x>>1);
    num+=verify;
    x = x >> verify;
    verify = !!x;
    num+=verify;    
    return 32+(~num)+1;
}

/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but it is to be interpreted as
 *   the bit-level representation of a single-precision floating point values.
 *   Legal ops: if else while for & | ~ + - >> << < > ! ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned float_i2f(int x) {
    unsigned s = x&0x80000000;
    unsigned m;
    unsigned e=31;
    unsigned top;
    if (!x) return 0;
    m = x;
    if (x < 0) m = ~x + 1;     
    while (!(m>>e)) e = e-1;   
    top = m << (31-e);
    m = top >> 8;
    unsigned remain = top&0xFF;
    unsigned odd = m&1;
    remain = remain + 0x7F + odd;
    m = m + (remain>>8);
    return s|(((e+127)<<23)+(m-0x800000));
}

/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: & >> << | if > < >= <= ! ~ else + ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatScale2(unsigned uf) {
    unsigned e = uf & 0x7F800000;
    unsigned s = uf & 0x80000000;
    if ((uf&0x7FFFFFFF) == 0){
        return uf;
    }
    if ((uf & 0x7F800000) == 0x7F800000){
        return uf;
    }
    if (e == 0){
        return s | ((uf&0x7FFFFFFF)<<1);
    }
    if (e == 0x7F000000){
        return s | 0x7F800000;
    }
    /*unsigned addition= uf&0x007FFFFF;弃用*/
    uf = uf + 0x00800000;
    return uf;
}

/*
 * float64_f2i - Convert a 64-bit IEEE 754 floating-point number to a 32-bit signed integer.
 *   The conversion rounds towards zero.
 *   Note: Assumes IEEE 754 representation and standard two's complement integer format.
 *   Parameters:
 *     uf1 - The lower 32 bits of the 64-bit floating-point number.
 *     uf2 - The higher 32 bits of the 64-bit floating-point number.
 *   Returns:
 *     The converted integer value, or 0x80000000 on overflow, or 0 on underflow.
 *   Legal ops: >> << | & ~ ! + - > < >= <= if else
 *   Max ops: 60
 *   Difficulty: 3
 */
int float64_f2i(unsigned uf1, unsigned uf2) {
    unsigned s = uf2>>31;    
    unsigned e = (uf2>>20)&0x7FF;
    unsigned m;
    if (e > 1053){
        return 0x80000000;
    }
    if (e < 1023){
        return 0;
    }
    unsigned rightmove = 1075 - e; /*1075=1023+52*/
    unsigned high= (uf2 & 0x000FFFFF) | 0x00100000;
    unsigned low = uf1;
    if (rightmove > 31){
        m = high >> (rightmove - 32);
    }else{
        m = (high<< (32 - rightmove)) | (low >> rightmove);  /*这里high的高位不会被截去，high是32-12+1=21位，而rightmove至少为1075-1053=22,最多移10位*/
    }
    if(!!s){
        m = ~m +1;
    }
    return m;
    
}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: < > <= >= << >> + - & | ~ ! if else &&
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatPower2(int x) {
    unsigned m;
    if (x > 127){
        m = 0x7F800000;
    }else if(x > -127){
        m = (x+127) << 23;
    }else if(x > -150){
        m = 1<<(149 + x);
    }else{
        m = 0;
    }
    return m;
}
