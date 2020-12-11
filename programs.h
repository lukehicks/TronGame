#ifndef PROGRAMS_H
#define PROGRAMS_H

#include <SFML/Graphics.hpp>
#include "settings.h"

using namespace sf;

struct Program
{ 
	int x;
	int y;
	int dir;

  	Color color;
	  
  	Program (Color c)
  	{
		x=rand() % WIDTH;
		y=rand() % HEIGHT;
		color=c;
		dir=rand() % 4;
	}

	void tick()
	{
		if (dir==0) y+=1;
		if (dir==1) x-=1;
		if (dir==2) x+=1;
		if (dir==3) y-=1;

		if (x>=WIDTH) x=0;  if (x<0) x=WIDTH-1;
		if (y>=HEIGHT) y=0;  if (y<0) y=HEIGHT-1;
	}

	Vector3f getColor()
	{return Vector3f(color.r,color.g,color.b);}
};

#endif