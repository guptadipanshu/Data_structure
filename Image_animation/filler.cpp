/**
 * @file filler.cpp
 * Implementation of functions in the filler namespace. Heavily based on
 * old MP4 by CS225 Staff, Fall 2010.
 * 
 * @author Chase Geigle
 * @date Fall 2012
 */
#include "filler.h"
#include <vector>
#include <algorithm> 
#include <iostream>
using namespace std;
animation filler::dfs::fillSolid( PNG & img, int x, int y, 
        RGBAPixel fillColor, int tolerance, int frameFreq ) {
    /**
     * @todo Your code here! You should replace the following line with a
     *  correct call to fill with the correct colorPicker parameter.
     */
	solidColorPicker color(fillColor);
	return filler::dfs::fill(img, x, y, color, tolerance, frameFreq);
}

animation filler::dfs::fillGrid( PNG & img, int x, int y, 
        RGBAPixel gridColor, int gridSpacing, int tolerance, int frameFreq ) {
    /**
     * @todo Your code here! You should replace the following line with a
     *  correct call to fill with the correct colorPicker parameter.
     */
	gridColorPicker color(gridColor,gridSpacing);
	return filler::dfs::fill(img, x, y, color, tolerance, frameFreq);
}

animation filler::dfs::fillGradient( PNG & img, int x, int y, 
        RGBAPixel fadeColor1, RGBAPixel fadeColor2, int radius, 
        int tolerance, int frameFreq ) {
    /**
     * @todo Your code here! You should replace the following line with a
     *  correct call to fill with the correct colorPicker parameter.
     */
	gradientColorPicker color(fadeColor1,fadeColor2,radius,x,y);
	return filler::dfs::fill(img, x, y, color, tolerance, frameFreq);
}

animation filler::dfs::fill( PNG & img, int x, int y, 
        colorPicker & fillColor, int tolerance, int frameFreq ) {
    /**
     * @todo Your code here! You should replace the following line with a
     *  correct call to filler::fill with the correct template parameter
     *  indicating the ordering structure to be used in the fill.
     */
    return  filler::fill<Stack>(img, x, y, fillColor, tolerance, frameFreq);;
}

animation filler::bfs::fillSolid( PNG & img, int x, int y, 
        RGBAPixel fillColor, int tolerance, int frameFreq ) {
    /**
     * @todo Your code here! You should replace the following line with a
     *  correct call to fill with the correct colorPicker parameter.
     */
	solidColorPicker color(fillColor);
	return filler::bfs::fill(img, x, y, color, tolerance, frameFreq);
}

animation filler::bfs::fillGrid( PNG & img, int x, int y, 
        RGBAPixel gridColor, int gridSpacing, int tolerance, int frameFreq ) {
    /**
     * @todo Your code here! You should replace the following line with a
     *  correct call to fill with the correct colorPicker parameter.
     */
    	gridColorPicker color(gridColor,gridSpacing);
	return filler::bfs::fill(img, x, y, color, tolerance, frameFreq);
	
}

animation filler::bfs::fillGradient( PNG & img, int x, int y, 
        RGBAPixel fadeColor1, RGBAPixel fadeColor2, int radius, 
        int tolerance, int frameFreq ) {
    /**
     * @todo Your code here! You should replace the following line with a
     *  correct call to fill with the correct colorPicker parameter.
     */
    	gradientColorPicker color(fadeColor1,fadeColor2,radius,x,y);
	return filler::bfs::fill(img, x, y, color, tolerance, frameFreq);
}

animation filler::bfs::fill( PNG & img, int x, int y, 
        colorPicker & fillColor, int tolerance, int frameFreq ) {
    /**
     * @todo Your code here! You should replace the following line with a
     *  correct call to filler::fill with the correct template parameter
     *  indicating the ordering structure to be used in the fill.
     */
	return filler::fill<Queue>(img, x, y, fillColor, tolerance, frameFreq);
    
}
/**
     * @todo You need to implement this function!
     *
     * This is the basic description of a flood-fill algorithm: Every fill
     * algorithm requires an ordering structure, which is passed to this
     * function via its template parameter. For a breadth-first-search
     * fill, that structure is a Queue, for a depth-first-search, that
     * structure is a Stack. To begin the algorithm, you simply place the
     * given point in the ordering structure. Then, until the structure is
     * empty, you do the following:
     *
     * 1.     Remove a point from the ordering structure. 
     *
     *        If it has not been processed before and if its color is
     *        within the tolerance distance (up to and **including**
     *        tolerance away in square-RGB-space-distance) to the original
     *        point's pixel color [that is, \f$(currentRed - OriginalRed)^2 +
              (currentGreen - OriginalGreen)^2 + (currentBlue -
              OriginalBlue)^2 \leq tolerance\f$], then: 
     *        1.    indicate somehow that it has been processed (do not mark it
     *              "processed" anywhere else in your code) 
     *        2.    change its color in the image using the appropriate
     *              colorPicker
     *        3.    add all of its neighbors to the ordering structure, and 
     *        4.    if it is the appropriate frame, send the current PNG to the
     *              animation (as described below).
     * 2.     When implementing your breadth-first-search and
     *        depth-first-search fills, you will need to explore neighboring
     *        pixels in some order.
     *
     *        While the order in which you examine neighbors does not matter
     *        for a proper fill, you must use the same order as we do for
     *        your animations to come out like ours! The order you should put
     *        neighboring pixels **ONTO** the queue or stack is as follows:
     *        **RIGHT(+x), DOWN(+y), LEFT(-x), UP(-y). IMPORTANT NOTE: *UP*
     *        here means towards the top of the image, so since an image has
     *        smaller y coordinates at the top, this is in the *negative y*
     *        direction. Similarly, *DOWN* means in the *positive y*
     *        direction.** To reiterate, when you are exploring (filling out)
     *        from a given pixel, you must first try to fill the pixel to
     *        it's RIGHT, then the one DOWN from it, then to the LEFT and
     *        finally UP. If you do them in a different order, your fill may
     *        still work correctly, but your animations will be different
     *        from the grading scripts!
     * 3.     For every k pixels filled, **starting at the kth pixel**, you
     *        must add a frame to the animation, where k = frameFreq. 
     *
     *        For example, if frameFreq is 4, then after the 4th pixel has
     *        been filled you should add a frame to the animation, then again
     *        after the 8th pixel, etc.  You must only add frames for the
     *        number of pixels that have been filled, not the number that
     *        have been checked. So if frameFreq is set to 1, a pixel should
     *        be filled every frame.
     */

template <template <class T> class OrderingStructure>
animation filler::fill( PNG & img, int x, int y,
        colorPicker & fillColor, int tolerance, int frameFreq ) {
    	animation output;
 	OrderingStructure<RGBAPixel*> frame;
        OrderingStructure<int> input_x;
        OrderingStructure<int> input_y;	
	input_x.add(x);
	input_y.add(y);
	frame.add(img(x,y));
	std::vector<RGBAPixel*> myvector ;
	vector<RGBAPixel*>::iterator it;
	it=myvector.begin();
	int added=0;
	int counter=0;
	//myvector.insert ( it , img(x,y));
	int curr_x;
	int curr_y;
	RGBAPixel s = *img(x,y);
	//cout<<"FrameFrequency"<<frameFreq<<"\n";
	while(!frame.isEmpty())
	{	counter++;
		curr_x=input_x.remove();
		curr_y=input_y.remove();	
		//cout<<"Pop for curr_x"<<curr_x<<"  curr_y"<<curr_y<<"\n";	
		RGBAPixel *curr_frame=frame.remove();
		//cout<<"Data"<<curr_frame->green<<curr_frame->blue<<curr_frame->red<<"\n";
		int calc_tol=pow((curr_frame->green-s.green),2)+pow((curr_frame->blue-s.blue),2)+pow((curr_frame->red-s.red),2);
		//cout<<"calc_tol "<<calc_tol<<" tolerance"<<tolerance<<"\n";		
		if(calc_tol<=tolerance)
		{	//cout<<"Here\n";
			if(!(std::find(myvector.begin(), myvector.end(), curr_frame)!=myvector.end()))	//use find from stl to check if elements are processed		
			{	//cout<<"Add for curr_x"<<curr_x<<"  curr_y"<<curr_y<<"\n";			
				added++;
				it=myvector.begin();
				myvector.insert (it,curr_frame);//mark data as processed
				*curr_frame=fillColor(curr_x,curr_y);//1.b call color picker 
				img(curr_x,curr_y)->red=curr_frame->red;
				img(curr_x,curr_y)->blue=curr_frame->blue;
				img(curr_x,curr_y)->green=curr_frame->green;
				if(curr_x+1<img.width())
				{				
					input_x.add(curr_x+1);//right
					input_y.add(curr_y);//right
				//	cout<<"Push curr_x"<<curr_x+1<<"  curr_y"<<curr_y<<"\n";
					frame.add(img(curr_x+1,curr_y));//right	
				}
				if(curr_y+1<img.height())
				{
					input_x.add(curr_x);//down
					input_y.add(curr_y+1);//down
				//	cout<<"Push curr_x"<<curr_x<<"  curr_y"<<curr_y+1<<"\n";
					frame.add(img(curr_x,curr_y+1));//down				
				}
				if(curr_x-1>=0)
				{
					input_x.add(curr_x-1);//left
					input_y.add(curr_y);//left
				//	cout<<"Push curr_x"<<curr_x-1<<"  curr_y"<<curr_y<<"\n";
					frame.add(img(curr_x-1,curr_y));//left		
				}
				if(curr_y-1>=0)
				{
					input_x.add(curr_x);//up
					input_y.add(curr_y-1);//up
				//	cout<<"Push curr_x"<<curr_x<<"  curr_y"<<curr_y-1<<"\n";	
					frame.add(img(curr_x,curr_y-1));//up
				}
				if(added%frameFreq==0)
				{	//added=0;
					//cout<<"adding frame\n";
					output.addFrame(img);
				}
			}
			
			
	
		}
		
	}
	//cout<<"Counter"<<counter<<"\n";
    return output;
}
