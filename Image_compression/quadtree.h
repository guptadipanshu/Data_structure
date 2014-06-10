// **************************************************************
// *		   
// *  quadtree.h
// *		   
// *  Quadtree class
// *		   
// *  CS 225 Spring 2008
// *		   
// **************************************************************

#ifndef QUADTREE_H
#define QUADTREE_H

#include "png.h"

class Quadtree
{
	public:
		Quadtree();

	Quadtree(const PNG &source, int resolution);

	Quadtree(Quadtree const &other);

	~Quadtree();

	Quadtree const & operator=(Quadtree const &other);

	void buildTree(PNG const &source, int resolution);

	RGBAPixel getPixel(int x, int y) const;

	PNG decompress() const;

	void clockwiseRotate();

	void prune(int tolerance);

	int pruneSize(int tolerance) const;

	int idealPrune(int numLeaves) const;


		
	private:

	// A simple class representing a single node of a Quadtree.
	// You may want to add to this class; in particular, it could probably
	// use a constructor or two...
	int res;
	class QuadtreeNode
	{
		
		public:
		QuadtreeNode* nwChild;  // pointer to northwest child
		QuadtreeNode* neChild;  // pointer to northeast child
		QuadtreeNode* swChild;  // pointer to southwest child
		QuadtreeNode* seChild;
		int x_cod;
		int y_cod;
		  // pointer to southeast child
		QuadtreeNode()
		{
			element=RGBAPixel();
			nwChild=NULL;
			neChild=NULL;
			swChild=NULL;
			seChild=NULL;	
			x_cod=-1;
			y_cod=-1;	
				
		}
		QuadtreeNode(const RGBAPixel &data)
		{
			element=data;
			nwChild=NULL;
			neChild=NULL;
			swChild=NULL;
			seChild=NULL;
			y_cod=-1;
			x_cod=-1;		
		}
		RGBAPixel element;  // the pixel stored as this node's "data"
		
	};
	QuadtreeNode *_copy(const QuadtreeNode* node);	
	QuadtreeNode* root;    // pointer to root of quadtree
	void clear(QuadtreeNode * &curr);
	void copy(const Quadtree & source);
	void buildtree_helper(QuadtreeNode *& curr,PNG const & source,int res,int x,int y);
	QuadtreeNode *getPixelHelper(int x,int y,int resol,QuadtreeNode * curr) const;
	void decompress_helper(QuadtreeNode * curr,PNG &image,int x,int y,int currRes) const;
	void clockwiseRotatehelper(QuadtreeNode * &curr,int cres);
	int get_pruneSize(QuadtreeNode * curr,int tol) const; 
	void prune_helper(QuadtreeNode * &curr,int tol) ; 
	bool calc_tol(QuadtreeNode * curr,QuadtreeNode *child,int tol) const;
	int idealPrune_helper(QuadtreeNode *node,int n) const;
	/**** Functions added for testing/grading                ****/
	/**** Do not remove this line or copy its contents here! ****/
	#include "quadtree_given.h"
};

#endif
