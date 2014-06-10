#include"image.h"
#include"iostream"
using namespace std;
void Image::flipleft() {

int input_width=width();
int input_height=height();
int inx=input_width-1;
int iny=0;
for (int xi =0; xi<input_width/2; xi++)
    		{
       		 for (int yi = 0; yi <input_height; yi++)
        		{
			 int red_temp=operator()(xi,yi)->red;
			 operator()(xi,yi)->red=operator()(inx,iny)->red;
			 operator()(inx,iny)->red=red_temp;
			/* change geeen pixels*/	
       			 int green_temp=operator()(xi,yi)->green;
			 operator()(xi,yi)->green=operator()(inx,iny)->green;
			 operator()(inx,iny)->green=green_temp;
			/* change blue pixels*/	
			 int blue_temp=operator()(xi,yi)->blue;
			 operator()(xi,yi)->blue=operator()(inx,iny)->blue;
			 operator()(inx,iny)->blue=blue_temp;	
			 iny++;
			 if(iny==input_height)
				{
					inx--;
					iny=0;				
				}			
			}
		}
		
 
}	

void Image::adjustbrightness(int r,int g, int b){
size_t input_width=width();
size_t input_height=height();
for (size_t xi =0; xi<input_width; xi++) 
	{
		for (size_t yi =0; yi<input_height; yi++)
			{
			   
			   if(operator()(xi,yi)->red+r<0) 
                           operator()(xi,yi)->red=0;
			   else if(operator()(xi,yi)->red+r>255) 
                           operator()(xi,yi)->red=255;
			   else
			   operator()(xi,yi)->red=operator()(xi,yi)->red+r;
			   /* green pixel*/
			   
			   
			   if(operator()(xi,yi)->green+g<0) 
			   operator()(xi,yi)->green=0;	
			   else if(operator()(xi,yi)->green+g>255) 
			   operator()(xi,yi)->green=255;	
			   else
			   operator()(xi,yi)->green=operator()(xi,yi)->green+g;	
			/* blue pixel*/
			   
			   if(operator()(xi,yi)->blue+b<0)
			   operator()(xi,yi)->blue=0;
			   else if(operator()(xi,yi)->blue+b>255) 
			   operator()(xi,yi)->blue=255;		
			   else
			   operator()(xi,yi)->blue=operator()(xi,yi)->blue+b;	
			}
	}
							
}

void Image::invertcolors(){
int input_width=width();
int input_height=height();
for (int xi =0; xi<input_width; xi++) 
	{
		for (int yi =0; yi<input_height; yi++)
			{
			   
			   operator()(xi,yi)->red=255-operator()(xi,yi)->red;

			   
			   operator()(xi,yi)->green=255-operator()(xi,yi)->green;

			  
			   operator()(xi,yi)->blue= 255-operator()(xi,yi)->blue;
			}
	}

}	

