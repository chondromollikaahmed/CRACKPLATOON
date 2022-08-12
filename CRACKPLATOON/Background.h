#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED
#include "Setter.h"


#include <iostream>
using namespace std;

// for level one 

void changeBackgroundOne1()
{
	for (int i = 0; i < 2; i++)
	{
		bg_one1_x[i] -= 1;     // when in left 
		if (bg_one1_x[i] + 2512 < 0) //if out of frame 
			bg_one1_x[i] = bg_one1_x[(i + 1) % 2] + 2511;
	}
}


// second moving background

void changeBackgroundOne2()
{
	for (int i = 0; i < 2; i++)
	{
		bg_one2_x[i] -= 1; //when in left 
		if (bg_one2_x[i] + 2512 < 0) //if out of frame
			bg_one2_x[i] = bg_one2_x[(i + 1) % 2] + 2510;
	}
}







void changeBackgroundOne3()
{
	for (int i = 0; i < 2; i++)
	{
		bg_one3_x[i] -= 2; //                      left slide
		if (bg_one3_x[i] + 2512 < 0) //out of frame
		{
			bg_one3_x[i] = bg_one3_x[(i + 1) % 2] + 2510;
		}

		//other obj. moving with bg 
		medikit.x -= 1;
		energy.x -= 1;
		shield.x -= 1;

		police_one1.x -= 1;
		police_one2.x -= 1;
		police_one3.x -= 1;

		

		bomb_x--;
	}
}






// for moving backward 


void changeBackgroundOneBack1()
{
	for (int i = 0; i < 2; i++)
	{
		bg_one1_x[i] += 1; 
		if (bg_one1_x[i] > 2512) 
			bg_one1_x[i] = bg_one1_x[(i + 1) % 2] - 2511;
	}
}

//inner second 
void changeBackgroundOneBack2()
{
	for (int i = 0; i < 2; i++)
	{
		bg_one2_x[i] += 1; //when in right slide
		if (bg_one2_x[i] > 2512) //if   out of frame
			bg_one2_x[i] = bg_one2_x[(i + 1) % 2] - 2510;
	}
}

//front 
void changeBackgroundOneBack3()
{
	for (int i = 0; i < 2; i++)
	{
		bg_one3_x[i] += 2; 
		if (bg_one3_x[i] > 2512) 
		{
			bg_one3_x[i] = bg_one3_x[(i + 1) % 2] - 2510;
		}

		//
		medikit.x += 1;
		energy.x += 1;
		shield.x += 1;

		police_one1.x += 1;
		police_one2.x += 1;
		police_one3.x += 1;


		bomb_x++;
	}
}































// to move background 

// this will be used when right key will be pressed 
void moveBackground()
{
	if (level == 1)
	{
		changeBackgroundOne1();
		for (int i = 0; i < 4; i++)
		{
			changeBackgroundOne2();
		}
		for (int i = 0; i < 6; i++)
		{
			changeBackgroundOne3();
		}
	}
}




// when left key will be pressed 

void moveBackgroundBack()
{
	if (level == 1)
	{
		changeBackgroundOneBack1();
		for (int i = 0; i < 4; i++)
		{
			changeBackgroundOneBack2();
		}
		for (int i = 0; i < 6; i++)
		{
			changeBackgroundOneBack3();
		}
	}
}







// for loading the image 

void showBackgroundOne()
{   cout<<"sky"<<endl;

	iShowImage(0, 0, 2512, scrH, bg_one0); //still sky 
	for (int i = 0; i < 2; i++)
	{
		cout<<"moon"<<endl;
		iShowImage(bg_one1_x[i], 0, 1250, scrH, bg_one1[i]); //moon
	}
	for (int i = 0; i < 2; i++)
	{   
		cout<<"middle"<<endl;
		iShowImage(bg_one2_x[i], 0, 2512, scrH, bg_one2[i]); //middle 
	}
	for (int i = 0; i < 2; i++)
	{
		cout<<"ground"<<endl;
		iShowImage(bg_one3_x[i], 0, 2512, scrH, bg_one3[i]); //ground image 
	}
}




// level two 




void changeBackgroundTwo1()
{
	for (int i = 0; i < 2; i++)
	{
		bg_two1_x[i] -= 1; 
		if (bg_two1_x[i] + 2512 < 0) 
			bg_two1_x[i] = bg_two1_x[(i + 1) % 2] + 2511;
	}
}


void changeBackgroundTwo2()
{
	for (int i = 0; i < 2; i++)
	{
		bg_two2_x[i] -= 1; 
		if (bg_two2_x[i] + 2512 < 0) 
			bg_two2_x[i] = bg_two2_x[(i + 1) % 2] + 2510;
	}
}


void changeBackgroundTwo3()
{
	for (int i = 0; i < 2; i++)
	{
		bg_two3_x[i] -= 2; 
		if (bg_two3_x[i] + 2512 < 0) 
		{
			bg_two3_x[i] = bg_two3_x[(i + 1) % 2] + 2510;
		}

		//medikit , energy if need = .x -1 
	}
}




void moveBackground2()
{
	if (level == 1)
	{
		changeBackgroundTwo1();
		for (int i = 0; i < 4; i++)
		{
			changeBackgroundTwo2();
		}
		for (int i = 0; i < 6; i++)
		{
			changeBackgroundTwo3();
		}
	}
}











void showBackground2()
{
	iShowImage(0, 0, 2512, scrH, bg_two0); //sky
	for (int i = 0; i < 2; i++)
	{
		iShowImage(bg_two1_x[i], 0, 2512, scrH, bg_two1[1]); //cloud
	}
	for (int i = 0; i < 2; i++)
	{
		iShowImage(bg_two2_x[i], 0, 2512, scrH, bg_two2[1]); //middle
	}
	for (int i = 0; i < 2; i++)
	{
		iShowImage(bg_two3_x[i], 0, 2512, scrH, bg_two3[1]); //ground
	}
}

#endif 




