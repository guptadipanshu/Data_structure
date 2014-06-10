#ifndef SCENE_H
#define SCENE_H
#include "png.h"
#include "image.h"
class Scene : public Image
{
    public :
		int max;
		Image ** img_pointers;
		int * img_x;
		int * img_y;
		Image ** img_pointers2;
		int * img_x2;
		int * img_y2;
		//Image * scene_output;
		Image * getpicture (int index) const;
		~Scene ();
		/* Member Functions */		
		Scene (int size);
		Scene (const Scene &source);
		void changelayer (int index, int newindex);
		void translate (int index, int xcoord, int ycoord);
		void addpicture (const char *FileName, int index, int x, int y);
		Image drawscene () const;
		void deletepicture (int index);	
		const Scene & operator= (const Scene &source);
		void changemaxlayers (int newmax);	
		/*
		
		
		*/
   private: void copy(const Scene & source);
	    void clear();
	    
};




#endif
