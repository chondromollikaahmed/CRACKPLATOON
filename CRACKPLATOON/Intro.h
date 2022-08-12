#ifndef INTRO_H_INCLUDED
#define INTRO_H_INCLUDED
bool soldiershow;

int dx=50,dy=600;
bool parashow;
int count1=0;
#include "Soldier.h"
int airplane ,set,parasoot;



void Intro()
{

	 parasoot=iLoadImage("intro\\parasoot.png");
	 airplane=iLoadImage("intro\\airplane.png");
		showBackgroundOne();


	iShowImage(dx,dy,200,200,airplane);
	 
	if(parashow)
	{
	iShowImage(intro.x,intro.y,200,200,parasoot);
	    intro.x+=20;
		intro.y-=20;
	}


	if(intro.x>=1450|| intro.y<200)
	{
		welcome=0;
		level=1;
		dx=50;
		dy=600;
		intro.x=50;
		intro.y=600;
		parashow=false;
		fall=false;
		count1=0;

	}
	
}  























































#endif