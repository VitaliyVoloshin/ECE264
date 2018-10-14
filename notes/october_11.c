//=============================================================================
//== FILENAME:          "october_11.c"
//== WRITTEN BY:        Andrew St. Pierre 
//== LAST MODIFIED:     11/10/2018 13:35:55
//=============================================================================

//===========================
//== THE WHY
//===========================
// GOOD READ: End-to-End Arguments in System Design
// LINK: "http://web.mit.edu/Saltzer/www/publications/endtoend/endtoend.pdf"

// Why C? Because... It is the #4 most popular programming language and many 
// of the other languages are based on it... ex. C# or C++


//===========================
//== BITWISE OPERATION 
//===========================
// Compression-> lossless compression 
//  Why? prevent waste in network usage
//  How? encode in ASCII (8-bits per letter)
//      In english, which letters appear most often?
//          a,e,i,o,u
//      In english, which letters appear less often?
//          z,q,x
//      Make common cases faster. Make rare cases correct.
//      Use few bits for common characters. Use more bits for rare.
//      GOAL: use fewer bits
//  ex.      
//        0/  \1        So, 0->a, 100->c, 101->d, 110->q 111->x
//        a    \
//          0/   \1
//          /     \
//        0/ \1 0/ \1
//        c  d  q   x

//===========================
//== Image processing (pg 385) 
//===========================
//  __________
//  | HEADER |  <= how many bytes to read, run check using checkHeaderValid()
//  |--------|
//  |        |  
//  |  DATA  |   
//  |        |  - Why read header and data seperately? Because the header tells
//  |        |    us how much data to read. 2 seperate fread()'s'
//  |________|

// Debugging programs dealing with images/bmp
//  To read a file as hexadecimal or bits, use:
//      $   xxd -b | less
//      $   xxd  | less


//===========================
//== Dynamic Structures 
//===========================
// concept: allocate memory when needed
//          release memory when no longer needed
// characteristics: 
//  1. fixed numer
//  2. after program starts
//  3. you never know the size

typedef struct listnode
{
    struct listnode * next;
    data; // self refering
    // ...
} Node;


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
