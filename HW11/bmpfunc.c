#include "bmpfunc.h"
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#ifdef TEST_FUNCGIVEN
int RGB2Gray(unsigned char red, unsigned char green, unsigned char blue){
	// this is a commonly used formula
	int gray = 0.2989 * red + 0.5870 * green + 0.1140 * blue;
	return gray;
}
#endif

#ifdef TEST_IMGTOGRAY
BMPImage * ImgToGray(BMPImage * image)
{
    // Grab width and height from image header
    int width = (image->header).width;
	int height = (image->header).height;

	// Allocate memory for the gray image
    BMPImage * gray_image = NULL;
    gray_image = (BMPImage *)malloc(sizeof(BMPImage));
    if(gray_image == NULL) return NULL;

    // Images have same headers
    gray_image->header = image->header;
	
	// Assign the the imagesize as height * width
	(gray_image->header).imagesize = width*height*3; 
	
	// Check for data allocation fail
	if((gray_image->data = (unsigned char *)malloc(sizeof(unsigned char)*(gray_image->header).imagesize)) == NULL)
    {  BMP_Free(gray_image);  }
	
	// Run loop for all pixels using height and width
	int pixel=0;
    for(pixel=0; pixel<(gray_image->header).imagesize; pixel+=3)
    {
        // Convert each pixel of all channels to gray using RGB2GRAY function
        unsigned char gray_val = RGB2Gray(image->data[pixel+(uint8_t)2],
                                          image->data[pixel+(uint8_t)1],	
                                          image->data[pixel]);
        
        // Assign values to all pixels of gray_image (same to all)
        gray_image->data[pixel+(uint8_t)2] = gray_val;
        gray_image->data[pixel+(uint8_t)1] = gray_val;
        gray_image->data[pixel] = gray_val;
    }

    // Return the gray image
    return gray_image;
}
#endif

#ifdef TEST_ADAPTIVETHRESHOLDING
BMPImage * AdaptiveThresholding(BMPImage * grayImage, int radius, int epsilon){
 	// allocate space for the image
	// the image has the same size(height and width)
	// therefore the header has to stay the same

	adaptive->header = grayImage->header;
	// (gray_image->header).imagesize = (gray_image->header).width*(gray_image->header).height;
	if ((adaptive->data = malloc(sizeof(unsigned char)*(adaptive->header).imagesize)) == NULL) {
		fprintf(stderr, "Error allocating memory\n");
		free(adaptive);
		return NULL;
	}

	int pixel=0;
	//Run a nested loop for all elements using height and width
        //Find the maximum of top row, bottom rpw, left column and right column using radius
	/*int toprow = MAX(0, row-radius);
     	 int bottomrow = MIN(height-1, row+radius);
     	 int leftcol = MAX(0, col-radius);
     	 int rightcol = MIN(width-1, col+radius);*/
    	//Calculate the avergage of all pixels
	//Run loop from toprow to bottom row
	//Inside which run a loop from left column to right column
		//calculate the location of each pixel using (row2*width + col2)*3;
         	//add all data values at every location point in data
		//keep a counter for averaging
	//Outside the second nested loop: 
	//calculate averge (using int)
	//check if average-epsilon is greater than grayImage->data[at that pixel point]
	//then assign adaptive thresholding image data as 0(black) for data value at pixel, pixel+1, pixel+2
     
        // else if average is lower then color shall be white(255) for data value at pixel, pixel+1, pixel+
//return the image after adaptive thresholding
}
#endif
