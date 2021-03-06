/**
 * @file main.cpp
 * A simple C++ program that manipulates an image.
 */
#include <algorithm>
#include <iostream>

#include "rgbapixel.h"
#include "png.h"

using namespace std;

/**
 * This function accepts a PNG object, two integer coordinates and a color, and
 * proceeds to draw a horizontal line across the image at the y coordinate and
 * a vertical line down the image at the x coordinage using the given color.
 * The modified PNG is then returned.
 *
 * @param original A PNG object which holds the image data to be modified.
 * @param centerX The center x coordinate of the crosshair which is to be drawn.
 * @param centerY The center y coordinate of the crosshair which is to be drawn.
 * @param color The color of the lines to be drawn.
 *
 * @return The image on which a crosshair has been drawn.
 */
PNG drawCrosshairs(PNG original, int centerX, int centerY, RGBAPixel color)
{
    /// This function is already written for you so you can see how to
    /// interact with our PNG class.
    for (size_t x = 0; x < original.width(); x++)
        *original(x, centerY) = color;

    for (size_t y = 0; y < original.height(); y++)
        *original(centerX, y) = color;

    return original;
}

/**
 * This function brightens a rectangle of a PNG, increasing the components
 * (red, green, blue) of each pixel by the given amount. You must account
 * for potential overflow issues (color components can only store numbers
 * between 0 and 255). If you attempt to store a value greater than 255
 * into a color component, the result will wrap around (and you won't be
 * able to check if it was greater than 255).
 *
 * @param original A PNG object which holds the image data to be modified.
 * @param amount The integer amount by which to increase each pixel's
 * components.
 *
 * @return The brightened image.
 */
PNG brighten(PNG original, int amount)
{
    /// You can assume amount is positive.
    for (size_t yi = 0; yi < original.height(); yi++)
    {
        for (size_t xi = 0; xi < original.width(); xi++)
        {
            /// Your code here!
		int blue = original(xi, yi)->blue;
		int green = original(xi, yi)->green;
		int red = original(xi, yi)->red;
		if(red+amount<255)
		original(xi,yi)->red= red+amount;
		else
		original(xi,yi)->red= 255;		
        
		if(blue+amount<255)
		original(xi,yi)->blue= blue+amount;
		else
		original(xi,yi)->blue= 255;

		if(green+amount<255)
		original(xi,yi)->green= green+amount;
		else
		original(xi,yi)->green= 255;
	}
    }
    return original;
}

/**
 * This function blends, or averages, two PNGs together. That is, each pixel in
 * the returned image consists of the averaged components (red, green, blue) of
 * the two input images.
 *
 * @param firstImage  The first of the two PNGs to be averaged together.
 * @param secondImage The second of the two PNGs to be averaged together.
 *
 * @return The averaged image.
 */
PNG blendImages(PNG firstImage, PNG secondImage)
{
    /// Your code here!
	  for (size_t yi = 0; yi < firstImage.height(); yi++)
    		{
       		 for (size_t xi = 0; xi < firstImage.width(); xi++)
        		{
				int c1 = firstImage(xi, yi)->red;
		                int c2 = secondImage(xi, yi)->red;
				int c3=(c1+c2)/2;
				firstImage(xi,yi)->red= c3;
				 c1 = firstImage(xi, yi)->blue;
		                 c2 = secondImage(xi, yi)->blue;
				 c3=(c1+c2)/2;
				firstImage(xi,yi)->blue= c3;	
				c1 = firstImage(xi, yi)->green;
		                 c2 = secondImage(xi, yi)->green;
				 c3=(c1+c2)/2;
				firstImage(xi,yi)->green= c3;

			}
		}
    return firstImage;
}


/**
 * The main function in this program (the starting point of the execution of our
 * code).
 *
 * @return An integer indicating whether execution was successful.
 */
int main()
{
    // Open a new PNG image from the file sample.png.
    PNG image("sample.png");

    // Open a new PNG image from the file overlay.png.
    PNG overlay("overlay.png");

    // Brighten the image read from overlay.png.
    overlay = brighten(overlay, 128);

    // Blend sample.png and overlay.png together.
    image = blendImages(image, overlay);

    // Create a new RGBAPixel color for drawCrosshairs which is cyan.
    RGBAPixel cyanColor;
    cyanColor.red = 0;
    cyanColor.green = 255;
    cyanColor.blue = 255;

    // Draw two crosshairs on the image.
    image = drawCrosshairs(image, 400, 330, cyanColor);
    image = drawCrosshairs(image, 620, 424, cyanColor);

    // Save the modified image to a file called output.png, overwriting the file
    // if it already exists.
    image.writeToFile("output.png");

    return 0;
}
