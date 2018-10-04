//=============================================================================
//== FILENAME:          "october_4.c"
//== WRITTEN BY:        Andrew St. Pierre
//== LAST MODIFIED:     Thursday, October 4, 2018
//=============================================================================

//===========================
//== CONVERTING NUMBER BASES
//===========================
//
// Decimal (base-10) to any base N system
//   1. Divide the decimal number by the value of the new base
//   2. Get the remainder from step 1 as the rightmost digit (LSB) of new num
//   3. Divide the quotient of the previous divide by the neew base
//   4. Record the remainder from step 3 as the next rightmost digt of new num
//   N. Repeat steps 3,4 until the quotient becomes zero in step 3
//   5. The last remainder thus obtained is the MSB of new based num
//
//  Example:
//      Convert 4_BASE(10) to base 2 (binary).
//       STEP:                          NEW NUMBER:
//       4/2=2, remainder 0             __0
//       2/2=1, remainder 0             _00
//       1/2=0, remainder 1             100
//      RESULT: 0x100
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//===========================
//== BIT MASKING (colors)
//===========================
// Sign bit is the left most bit in a binary number. 
//  If sign bit == 1, number assumes negative value
//  Else, number assumes positive value
 
// NOTE: must use unsigned char when completing assignment 10
 
// Bit masking:
//  mask:           |1|1|0|0| |0|0|0|0| 
//  oneyte:         |x|y|a|b| |c|d|e|f| 
//  first2bits:     |x|y|0|0| |0|0|0|0| 
unsigned char onebyte;
fread(&onebyte, 1, 1, fptr);
unsigned char mask = 0xc0;
unsigned char first2bits = onebyte & mask;

// IMAGE MODIFICATION OF COLORS (FILTERS)
//  ---------------------------------------------------------
//  R                   G                   B
//  |0|0|0|0|0|0|0|0|   |0|0|0|0|0|0|0|0|   |0|0|0|0|0|0|0|0| 
unsigned char red;
unsigned char green;
unsigned char blue;
// read from file
unsigned char mask = 0xc0;
unsigned char red2bits = red & mask;
unsigned char green2bits = green & mask;
unsigned char blue2bits = blue & mask;

// shift bits right, ex. |1|1|0|0|0|0|0|0| => |0|0|1|1|0|0|0|0| 
green2bits >>= 2;   // green2bits = green2bits >> 2;

//  |A|B|0|0|0|0|0|0| red2bits
//  |0|0|C|D|0|0|0|0| green2bits
//  |0|0|0|0|E|F|0|0| blue2bits
//  |0|0|0|0|0|0|G|H| secondred2bits
unsigned char newbyte = red2bits | green2bits | blue2bits | secondred2bits;
//  |A|B|C|D|E|F|G|H| newbyte

// common mistake:
unsigned char mask = 0x80;                  // |1|0|0|0|0|0|0|0|
unsigned char firstbit = 0xFF&mask;         // |1|0|0|0|0|0|0|0|
if (firstbit == 1) { /* WILL NEVER REACH HERE BECAUSE BYTE == 128 */ }
// should use: if(firstbit != 0) because then the first bit MUST (recall mask)

//===========================
//== IMAGE MANIPULATION
//===========================
// BMP IMAGE STRUCTURE:
// ------------------------------------
// header       -> metadata (size,w,h,bits,etc)
// ------------------------------------
// data pixel   -> 

// When working with a BMP image, first scan the header for information
// about how to handle this image. (size, colors, etc)
// THEN, scan the data. (2 passes (at least))

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
