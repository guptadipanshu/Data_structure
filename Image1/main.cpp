#include <algorithm>
#include <iostream>
#include<stdio.h>
#include "rgbapixel.h"
#include "png.h"

int main()
{
PNG input_image("in.png");
int input_width=input_image.width();
int input_height=input_image.height();
PNG output_image(input_width,input_height);
//int output_width=output_image.width();
//int output_height=output_image.height();
RGBAPixel cyanColor;
int inx=0;
int iny=0;

for (int yi = input_height; yi >0; yi--)
    		{
       		 for (int xi = input_width; xi>0; xi--)
        		{
				output_image(xi-1,yi-1)->red=input_image(inx,iny)->red;
				output_image(xi-1,yi-1)->blue=input_image(inx,iny)->blue;
				output_image(xi-1,yi-1)->green=input_image(inx,iny)->green;
				//output_image(output_width,output_height)->green=input_image(xi,yi)->green;
				//output_image(output_width,output_height)->blue=input_image(xi,yi)->blue;
				
				inx++;
									
				
				if(inx==input_width)
				{
					inx=0;
					iny++;
				}
			}
		}
		
		output_image.writeToFile("out.png");
return 0;
}
