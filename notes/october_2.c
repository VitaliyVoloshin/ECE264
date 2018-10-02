/******************************************************************************
 * FILENAME:        "october_2.c" 
 * WRITTEN BY:      Andrew St. Pierre
 * LAST MODIFIED:   Tuesday, October 2, 2018
 * ***************************************************************************/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// ===============
// strlen() usage
// ===============
int strlen(char * s)
{
    // iterates through array until null terminator '\0'
    int len = 0;
    while(s != '\0')
    {
        s++;
        len++;
    }
    return len;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// ===============
// strcpy() usage
// ===============
void use_strcpy(void)
{
    char * name2;
    // NOTE: + 1 to the strlen to account for '\0'
    name2 = malloc(sizeof(char)*(strlen("Colleen")+1);
    strcpy(name2, "Colleen");
    for(int i=0; i<strlen("Colleen"); i++)
    {  printf("%c",name2[i]);  }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// COMMON MISTAKES ===========================================================
// 1. do not have enough space because strlen() does not count '\0'
// 2. strdup() forget to free
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// =======================
// Other string functions 
// =======================
// strstr()     => finds the first occur of substr needle in str haystack
// strrstr()    => does strstr, but starts searching reverse orders
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// Example use of strstr()
char * p = strstr(str1, str2);
if(p != NULL) p++;
p = strstr(p,str2);
return NULL;
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// NOTE: buffer overflow attack, first computer virus
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// C's minimum unit is a byte (8-bits)
//   one bit => either 0 or 1
// read / write at least one byte
// ===========================================================================
//  ie. R-G-B colors for one pixel
//      RED         GREEN       BLUE
//      1-byte      1-byte      1-byte
//
//      EACH PIXEL == 24-bits, or 3 bytes
//      post-compression... a pixel can be just 8-bits
//
//             BITMASKING:
//       RED                  GREEN                BLUE
//      |8|7|6|5|4|3|2|1|0|  |8|7|6|5|4|3|2|1|0|  |8|7|6|5|4|3|2|1|0| 
//      |1|1|1|0|0|0|0|0|0|  |1|1|1|0|0|0|0|0|0|  |1|1|1|0|0|0|0|0|0| 
//      |8|7|6|0|0|0|0|0|0|  |8|7|6|0|0|0|0|0|0|  |8|7|6|0|0|0|0|0|0| 
//
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/










