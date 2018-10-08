#include "hw10.h"
#ifdef TEST_MAINFUNC
int main(int argc, char **argv)
{
    // Check the arguments (if argc != 3)
        // argv[1] == path to input file image name
            // If open fail, print issue, return exit_failiure
        // argv[2] == path to output file image name
            // If fail, free memory, return exit_failiure   
    
    // Call BMP_Open()
        // Call BMPHeader_Valid() to check BMP image
    
    // Call ImgToGray()
        // Call RGB2Gray() to obtain colors
        // NOTE: R==B==G for all pixels in output
  
    // Check for errors after calling adaptive threshold

    // Call BMP_Write() to write the greyscale image to file
    
    // Free all the images
	return EXIT_SUCCESS;
}

#endif
