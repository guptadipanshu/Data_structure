/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */
	 			
#include <iostream>
#include <map>
#include "maptiles.h"

using namespace std;

MosaicCanvas * mapTiles(SourceImage const & theSource, vector<TileImage> const & theTiles)
{
    /**
     * @todo Implement this function!
     */
     int n_rows=theSource.getRows();
     int n_columns=theSource.getColumns();
     vector< Point<3> > kd_tree;
     std::map<Point<3>,TileImage> mymap;
     
     MosaicCanvas * mosaic = new MosaicCanvas(n_rows,n_columns);
     for(int it=0;it<theTiles.size();it++)
     {
     
     	RGBAPixel avg_color=theTiles.at(it).getAverageColor();
     	Point<3> t(avg_color.red,avg_color.green,avg_color.blue);
     	mymap[t]=theTiles.at(it);
     	kd_tree.push_back(t);
     	
     }
  
    KDTree<3> tree(kd_tree);
     //get the tiles avg color
     for(int i=0;i<n_rows;i++)
     {
     	for(int j=0;j<n_columns;j++)
     	{
     	    RGBAPixel pixel_ret=theSource.getRegionColor(i,j);	
     	    // convert pixel to points to make query
     	    Point<3> t(pixel_ret.red,pixel_ret.green,pixel_ret.blue);
     	    Point<3> nearest_point=tree.findNearestNeighbor(t);
     	    mosaic->setTile(i,j,mymap[nearest_point]);
     	}
     }
	return mosaic;
}
