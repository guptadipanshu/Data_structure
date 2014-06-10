// **************************************************************
// *		   
// *  quadtree.cpp
// *		   
// *  Quadtree class
// *		   
// *  CS 225 Spring 2008
// *		   
// **************************************************************

#include "quadtree.h"
#include <iostream>
#include <vector>
#include <algorithm> 
#include <math.h>  
using namespace std;
Quadtree::Quadtree ()
{
	root=NULL;
	QuadtreeNode();
}	
Quadtree::Quadtree(const PNG & source, int resolution)
{ buildTree(source,resolution);	}
/*copy constructor*/
Quadtree::Quadtree(Quadtree const &other)
{	if(other.root!=NULL) 
	copy(other);
	else
	root=NULL; 
}

/*destructor*/
Quadtree::~Quadtree()	
{ clear(root);    }


void Quadtree::copy(const Quadtree & other)
{	
	//root=new QuadtreeNode();
	//root->element=other.root->element;
	res=other.res;
	root=_copy(other.root);
}

Quadtree::QuadtreeNode * Quadtree::_copy(const QuadtreeNode* node)
{	QuadtreeNode * temp=new QuadtreeNode();
	if(node!=NULL)
	{	//temp=new QuadtreeNode(); 
		if(node->neChild!=NULL)
			temp->neChild=_copy(node->neChild);
		if(node->nwChild!=NULL)
			temp->nwChild=_copy(node->nwChild);
		if(node->seChild!=NULL)
			temp->seChild=_copy(node->seChild);
		if(node->swChild!=NULL)			
			temp->swChild=_copy(node->swChild);	
	}
	temp->element=node->element;
	temp->x_cod=node->x_cod;
	temp->y_cod=node->y_cod;
	return temp;
}
void Quadtree::clear(QuadtreeNode *&curr)
{
	if(curr!=NULL)
	{
		clear(curr->neChild);
		curr->neChild=NULL;
		clear(curr->seChild);
		curr->seChild=NULL;
		clear(curr->swChild);
		curr->swChild=NULL;
		clear(curr->nwChild);
		curr->nwChild=NULL;
		delete curr;
		curr=NULL;
	}
	
}
/*equal*/
Quadtree const & Quadtree::operator=(Quadtree const &other)	
{	
	if(other.root==NULL)
	{
		clear(this->root);
		root=NULL;
		return *(this);
	}
	if(this!=&other)
	{
		clear(this->root);		
		copy(other);
			
	}
	return *(this);	
}	

/*buildTree*/
void Quadtree::buildTree ( PNG const & source,int resolution)
{	//if(root!=NULL)
	//clear(root);
	res=resolution;
	root=new QuadtreeNode();
	
	buildtree_helper(root,source,resolution,0,0);
	//cout<<"red\t"<<source(0,0)->red<<"\n";
			
}
void Quadtree::buildtree_helper(QuadtreeNode *& curr,PNG const & source,int resolution,int x,int y)
{
	curr->x_cod=x;
	curr->y_cod=y;
	if(resolution!=1)
	{	//output->nwChild->x_cod=x;
		//output->nwChild->y_cod=y;
	//output->element.red=((source(x,y)->red+source(x+1,y)->red+source(x,y+1)->red+source(x+1,y+1)->red)/4);
	//output->element.blue=((source(x,y)->blue+source(x+1,y)->blue+source(x,y+1)->blue+source(x+1,y+1)->blue)/4);
	//output->element.green=((source(x,y)->green+source(x+1,y)->green+source(x,y+1)->green+source(x+1,y+1)->green)/4);
	//output->element.alpha=((source(x,y)->alpha+source(x+1,y)->alpha+source(x,y+1)->alpha+source(x+1,y+1)->alpha)/4);	
		curr->nwChild = new QuadtreeNode;
		curr->neChild = new QuadtreeNode;
		curr->swChild = new QuadtreeNode;
		curr->seChild = new QuadtreeNode;
		buildtree_helper(curr->nwChild,source,resolution/2,x,y);
		//output->neChild->x_cod=x+resolution/2;
		//output->neChild->y_cod=y;
		buildtree_helper(curr->neChild,source,resolution/2,x+resolution/2,y);
		//output->swChild->x_cod=x;
		//output->swChild->y_cod=y+resolution/2;
		buildtree_helper(curr->swChild,source,resolution/2,x,y+resolution/2);
		//output->seChild->x_cod=x+resolution/2;
		//output->seChild->y_cod=y+resolution/2;
		buildtree_helper(curr->seChild,source,resolution/2,x+resolution/2,y+resolution/2);	
curr->element.red=(curr->nwChild->element.red+curr->swChild->element.red+curr->seChild->element.red+curr->neChild->element.red)/4;
curr->element.blue=(curr->nwChild->element.blue+curr->swChild->element.blue+curr->seChild->element.blue+curr->neChild->element.blue)/4;
curr->element.green=(curr->nwChild->element.green+curr->swChild->element.green+curr->seChild->element.green+curr->neChild->element.green)/4;
curr->element.alpha=(curr->nwChild->element.alpha+curr->swChild->element.alpha+curr->seChild->element.alpha+curr->neChild->element.alpha)/4;
	
			
	}
	else
	{
		curr->element=*source(x,y);
		
		/*output->nwChild=new QuadtreeNode(*source(x, y));
		output->nwChild->x_cod=x;
		output->nwChild->y_cod=y;
		output->neChild=new QuadtreeNode(*source(x+1, y));
		output->neChild->x_cod=x+1;
		output->neChild->y_cod=y;
		output->swChild=new QuadtreeNode(*source(x, y+1));
		output->swChild->x_cod=x;
		output->swChild->y_cod=y+1;
		output->seChild=new QuadtreeNode(*source(x+1, y+1));
		output->seChild->x_cod=x+1;
		output->seChild->y_cod=y+1;
	output->element.red=((source(x,y)->red+source(x+1,y)->red+source(x,y+1)->red+source(x+1,y+1)->red)/4);
	output->element.blue=((source(x,y)->blue+source(x+1,y)->blue+source(x,y+1)->blue+source(x+1,y+1)->blue)/4);
	output->element.green=((source(x,y)->green+source(x+1,y)->green+source(x,y+1)->green+source(x+1,y+1)->green)/4);
	output->element.alpha=((source(x,y)->alpha+source(x+1,y)->alpha+source(x,y+1)->alpha+source(x+1,y+1)->alpha)/4);	
		*/
	}
	//return output;
}
/*getPixel*/
RGBAPixel Quadtree::getPixel(int x, int y) const
{
	RGBAPixel color;
	if((x>res && y>res) || (root==NULL) || x<0 || y<0)
		return color;
	QuadtreeNode * temp=getPixelHelper(x,y,res,root);
	color=temp->element;	
	return color;
}
Quadtree::QuadtreeNode * Quadtree::getPixelHelper( int x,int y,int currRes,QuadtreeNode * curr) const
{ 
	
	if (curr->nwChild==NULL && curr->neChild == NULL && curr->seChild==NULL && curr->swChild==NULL ) // found the Node we want
	{
		return curr;
	}
	else //recurrsion continues
	{
		QuadtreeNode* wanted;
			int factor=currRes/2;
			if(x<currRes/2 && y<currRes/2) //nw
				wanted = getPixelHelper(x,y,currRes/2,curr->nwChild);
			
			else if(x<currRes/2 && y>=currRes/2) //ne child
				wanted = getPixelHelper(x,y-currRes/2,currRes/2,curr->swChild);
			
			
			else if(x>=currRes/2 && y<currRes/2)//sw child
				wanted = getPixelHelper(x-currRes/2,y,currRes/2,curr->neChild);

			else if (x>=currRes/2 && y>=currRes/2)// se child
				wanted = getPixelHelper(x-currRes/2,y-currRes/2,currRes/2,curr->seChild);
		return wanted;
		
	}
}

/*Decompress*/
PNG Quadtree::decompress() const
{
	/*
	if(root!=NULL)
	{
		PNG image(res,res);
		 for(int i=0;i<res;i++)
		{
			for(int j=0;j<res;j++)
			 *image(i,j)=getPixel(i,j);
		}
	return image;
	}
	else
	{		
		PNG image;
		return image;	
	}
	*/	
	
	if(root!=NULL)
	{
				
		PNG image(res,res);
		decompress_helper(root,image,0,0,res);
		return image;	
	}
	else 
	{		
		PNG default_image;
		return default_image;
	}
	
	
	
}

void Quadtree::decompress_helper(QuadtreeNode * curr,PNG &image,int x,int y,int currRes) const
{
	if(curr->nwChild==NULL && curr->neChild == NULL && curr->seChild==NULL && curr->swChild==NULL)
	{	
		
		
			for(int i=x;i<x+currRes;i++)
			{
				for(int j=y;j<y+currRes;j++)
			 		{
			 			*image(i,j)=curr->element;	
						//currRes=currRes/2;
					}
			}
		
		
	}
	else
	{
		
		decompress_helper(curr->nwChild,image,x,y,currRes/2);
		decompress_helper(curr->neChild,image,x+currRes/2,y,currRes/2);
		decompress_helper(curr->swChild,image,x,y+currRes/2,currRes/2);
		decompress_helper(curr->seChild,image,x+currRes/2,y+currRes/2,currRes/2);
		
	}
}











/*5.2 */


void Quadtree::clockwiseRotate()	
{
	clockwiseRotatehelper(root,res);
}
void Quadtree::clockwiseRotatehelper(QuadtreeNode *& curr,int cres)
{	//cout<<"call\n";
	if(curr==NULL)
		return;
	if(curr->nwChild==NULL && curr->neChild == NULL && curr->seChild==NULL && curr->swChild==NULL )
		return;
	else
	{
		QuadtreeNode* temp = curr->neChild;
		
		curr->neChild = curr->nwChild;
		curr->neChild->x_cod=curr->nwChild->x_cod;
		curr->neChild->y_cod=curr->nwChild->y_cod;
		
		curr->nwChild = curr->swChild;
		curr->nwChild->x_cod=curr->swChild->x_cod;
		curr->nwChild->y_cod=curr->swChild->y_cod;
		
		curr->swChild = curr->seChild;
		curr->swChild->x_cod=curr->neChild->y_cod;
		curr->swChild->x_cod=curr->neChild->x_cod;
		
		curr->seChild = temp;
		curr->seChild->x_cod=temp->x_cod;
		curr->seChild->y_cod=temp->y_cod;
		
		
		
		clockwiseRotatehelper(curr->neChild,0);
		clockwiseRotatehelper(curr->nwChild,0);
		clockwiseRotatehelper(curr->swChild,0);
		clockwiseRotatehelper(curr->seChild,0);
	}
}
void Quadtree::prune(int tolerance)
{
	if(root!=NULL)
		prune_helper(root,tolerance);
}

bool Quadtree:: calc_tol(QuadtreeNode * curr,QuadtreeNode *child,int tol) const
{
	if(child->nwChild==NULL)
	{	int diff=pow((curr->element.red-child->element.red),2)+pow((curr->element.green-child->element.green),2)+pow((curr->element.blue-child->element.blue),2);
	if(diff<=tol)
		return true;
	else
		return false;	
	}
	bool v1=calc_tol(curr,child->nwChild,tol);
	bool v2=calc_tol(curr,child->neChild,tol);
	bool v3=calc_tol(curr,child->swChild,tol);
	bool v4=calc_tol(curr,child->seChild,tol);
	return v1 && v2 && v3 && v4 ;
}

void Quadtree::prune_helper(QuadtreeNode *& curr,int tol)
{
	if(curr!=NULL && curr->nwChild!=NULL)
	{
		
		if((calc_tol(curr,curr->nwChild,tol) && calc_tol(curr,curr->neChild,tol) && calc_tol(curr,curr->seChild,tol) && calc_tol(curr,curr->swChild,tol)))
		//if(calc_tol(curr)<=tol)
		{
			clear(curr->nwChild);
			clear(curr->neChild);
			clear(curr->swChild);
			clear(curr->seChild);
			
		}
		else
		{
			prune_helper(curr->nwChild,tol);
			prune_helper(curr->neChild,tol);
			prune_helper(curr->swChild,tol);
			prune_helper(curr->seChild,tol);
			

			//prune_helper(curr,tol);
			
		}
	}
	else
		return;
}
int Quadtree::pruneSize	(int tolerance)	const
{
	if(root==NULL)
	return 0;
	int size=0;
	if(tolerance<0)
	 size= get_pruneSize(root,0);
	else
	 size= get_pruneSize(root,tolerance);
	return size;
}
int Quadtree::get_pruneSize(QuadtreeNode *curr,int tol) const
{
	if(curr->nwChild==NULL)
		return 1;
	if(curr!=NULL && curr->nwChild!=NULL)
	{	
		if((calc_tol(curr,curr->nwChild,tol) && calc_tol(curr,curr->neChild,tol) && calc_tol(curr,curr->seChild,tol) && calc_tol(curr,curr->swChild,tol)))
		{
			return 1;
		}
		else
		return get_pruneSize(curr->nwChild,tol)+get_pruneSize(curr->neChild,tol)+get_pruneSize(curr->swChild,tol)+get_pruneSize(curr->seChild,tol);
	}
	else 
		return 0;		
}
int Quadtree::idealPrune(int numLeaves) const
{ 
	int tol=idealPrune_helper(root,numLeaves);
	return tol;
}
int Quadtree::idealPrune_helper(QuadtreeNode *curr,int n) const
{
	int mid,tol=0;
	int first=0;
	int last=255*255*3;
	int found=0;
	while((first<last))
	{
		mid=(first+last)/2;
		//cout<<"mid  "<<mid<<"\n";
		//cout<<"pruneSize(mid)"<<pruneSize(mid)<<"\n";
		int k=pruneSize(mid);
		if(k>n)
		{	
			first=mid+1;
			
		}
		else if(k<n)
		{	//cout<<"more\n";
			last=mid-1;
		}
		else 
		{
			last=mid;
			found=1;
			break;
		}
	}
	if(found==1)
	tol=last;
	else
	tol=first;
	while(1)
	{	//cout<<"asdas"<<tol<<"\n";
		int n2=pruneSize(tol);
		if(n2>n)
		break;
		tol--;
	}
	return tol+1;
	
}
