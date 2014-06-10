#include"scene.h"
#include"image.h"
#include <iostream>
using namespace std;


Scene::Scene(int size){
		
	max=size;
	//scene_output=new Image();
	img_pointers= new Image*[max];
	img_x= new int[max];
	img_y= new int[max];
	for( int i=0; i<max; i++)
		{
						
			img_pointers[i] = NULL;
			img_x[i]=-1;
			img_y[i]=-1;
		}

}	



Scene::Scene(const Scene & source)
{ if(this!=&source)
	{
		
		copy(source);
	}

}

void changemaxlayers (int newmax);

Scene::~Scene(){
 clear();
}


void Scene::addpicture(const char *FileName, int index, int x, int y)
{

if(index>=max||index<0)
	cout << "index out of bounds" << endl;
else
	{
		Image * myImage = new Image();
		myImage->readFromFile(FileName);
		img_pointers[index] = myImage;
		img_x[index]=x;
		img_y[index]=y;
		//cout<< img_pointers[index]<<" x cooordinate"<<img_x[index]<< index<<endl;
		//img_pointers[index-1]->writeToFile("mytester.png");
	}

}	

Image Scene::drawscene()const
{
int max_height=0, max_width=0,height=0,width=0,i=0;
Image  scene_output;
scene_output=Image();
for(i=0;i<max;i++)
	{	
		if(img_pointers[i]!=NULL)
		{
		height=img_pointers[i]->height();
		width=img_pointers[i]->width();
		height+=img_y[i];
		width+=img_x[i];
		//cout<<"read"<<i<<" "<<height<<" "<< width<<endl;	
		if(height>=max_height) 
		{
			max_height=height;
		}
		if(width>=max_width)
		{
			max_width=width;
		}
		
		}
		
	}
(scene_output).resize(max_width, max_height);
 /*for(int c1=0;c1<max_width;c1++)
	{
		for(int c2=0;c2<max_height;c2++)
			{
				scene_output->operator()(c1,c2)->red=255;
				scene_output->operator()(c1,c2)->blue=255;
				scene_output->operator()(c1,c2)->green=255;
			}
	}
*/
for(i=0;i<max;i++)
{
	if(img_pointers[i]!=NULL)
     	{	//cout<<"max"<<max_height<<"start y "<<img_y[i]<<endl;
		//cout<<"width"<<max_width<<"start x "<<img_x[i]<<endl;
		//cout<<endl;
		int input_height=img_pointers[i]->height();
		int input_width=img_pointers[i]->width();
		int start_x=0;
		int start_y=0;
		
		for (int xi =img_x[i]; xi<max_width; xi++) 
			{	
				
				for (int yi =img_y[i]; yi<max_height; yi++)
					{
			   
			   		
						scene_output.operator()(xi,yi)->red=img_pointers[i]->operator()(start_x,start_y)->red;
						scene_output.operator()(xi,yi)->green=img_pointers[i]->operator()(start_x,start_y)->green;
						scene_output.operator()(xi,yi)->blue=img_pointers[i]->operator()(start_x,start_y)->blue;
						start_y++;
						if(start_y==input_height)
						{
							start_x++;
							start_y=0;
							break;
						}
						
					}
					if(start_x==input_width)
							break;
					
			}
                       
				
	}	
}		
//cout<<endl<<endl;		
     	 		
  return scene_output;
}



void Scene::changelayer	(int index, int newindex){
if(index<0 || index >=max || newindex<0 || newindex >= max)
	cout <<"invalid index" << endl;
else if (newindex==index)
  { }
else 
	{
	if(img_pointers[newindex]!=NULL)		
		{	delete img_pointers[newindex];
			img_pointers[newindex]=NULL;
		}
		Image *image= img_pointers[index];
		img_pointers[newindex]=image;
		img_pointers[index]=NULL;	
		img_x[newindex]=img_x[index];
		img_y[newindex]=img_y[index];		
	}
}

void Scene:: translate (int index, int xcoord, int ycoord){
if(index<0 || index >=max ||img_pointers[index]==NULL)
cout <<"invalid index" << endl; 
else if(img_x[index]==-1 || img_y[index]==-1)
{}
else
	{	
			
		img_x[index]=xcoord;
		img_y[index]=ycoord;
		
	}
}
	


Image * Scene::getpicture(int 	index)const
{
if(index<0 || index >=max ||img_pointers[index]==NULL)
	cout <<"invalid index" << endl;
else if(img_pointers[index]!=NULL)
	{      // cout<<"send";
		return img_pointers[index];
	}
//cout<<"null";
return NULL;		

}


void Scene::deletepicture(int 	index)
{
if(index<0 || index >=max )
	cout << "invalid index" << endl;
else if (img_pointers[index]!=NULL)
	{	
		delete img_pointers[index];
		img_pointers[index]=NULL;
	}		
}	

const Scene & Scene::operator=(const Scene & source){
 if(this!=&source)
	{
		clear();		
		copy(source);
			
	}
	return *(this);
}	

void Scene::copy(const Scene & source)
{	max=source.max;
	
	//scene_output=new Image();
	img_pointers= new Image*[max];
	img_x= new int[max];
	img_y= new int[max];
	for( int i=0; i<max; i++)
	{	if(source.img_pointers[i]!=NULL)
		{
			Image * myimage= new Image(*source.img_pointers[i]);
			img_pointers[i] = myimage;
		}
		else
			img_pointers[i]=NULL;
		img_x[i]=source.img_x[i];
		img_y[i]=source.img_y[i];
	}
	//*scene_output=drawscene();
}
void Scene:: clear(){
 for(int i=0;i<max;i++)
	{
		if(img_pointers[i]!=NULL)
		delete (img_pointers[i]);
	}
delete []img_pointers;
img_pointers=NULL;
//cout<<" WE FREE ";
 delete [] img_x;
 delete [] img_y;
 //delete scene_output;
//scene_output=NULL;
img_x=NULL;
img_y=NULL;
}


void Scene::changemaxlayers (int newmax){

	if(newmax>max)
	{
	int temp_max=max;
	max=newmax;
	img_pointers2= new Image*[newmax];
	img_x2= new int[newmax];
	img_y2= new int[newmax];
	int i=0;
	for(;i<temp_max;i++)
		{
			if(img_pointers[i]!=NULL)
			{			
			Image * myimage= new Image(*img_pointers[i]);
			img_pointers2[i] = myimage;
			img_x2[i]=img_x[i];
			img_y2[i]=img_y[i];
			}
			else
			{
			img_pointers2[i] =NULL ;
			img_x2[i]=-1;
			img_y2[i]=-1;
			}	
		}
	for(;i<newmax;i++)
		{
			img_pointers2[i] =NULL ;
			img_x2[i]=-1;
			img_y2[i]=-1;
		}
	for(int i=0;i<temp_max;i++)
	{
		if(img_pointers[i]!=NULL)
		delete (img_pointers[i]);
	}
	delete []img_pointers;
 	delete []img_x;
 	delete [] img_y;
	img_pointers= new Image*[newmax];
	img_x= new int[newmax];
	img_y= new int[newmax];
	i=0;
	for(;i<newmax;i++)
		{
			if(img_pointers2[i]!=NULL)
			{			
			Image * myimage= new Image(*img_pointers2[i]);
			img_pointers[i] = myimage;
			img_x[i]=img_x2[i];
			img_y[i]=img_y2[i];
			}
			else
			{
			img_pointers[i] =NULL ;
			img_x[i]=-1;
			img_y[i]=-1;
			}
		}
	for(;i<newmax;i++)
		{
			img_pointers[i] =NULL ;
			img_x[i]=-1;
			img_y[i]=-1;
		}
	for(int i=0;i<newmax;i++)
	{
		if(img_pointers2[i]!=NULL)
		delete (img_pointers2[i]);
	}
	delete []img_pointers2;
 	delete []img_x2;
 	delete [] img_y2;
	}
else
	{
		int flag=0;
		if(newmax>=0)
		{
		for(int i=newmax;i<max;i++)
		{
			if(img_pointers[i]!=NULL)
			{
				flag=-1;
				break;			
			}
		}
		}
		else
		flag=-1;
		if(flag==-1 ||  newmax<0)		
		cout << "invalid newmax" << endl;
		else
		max=newmax;	
	}
}
