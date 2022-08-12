#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED
#include "Setter.h"

/*__________________________________________________Structure for different objects.___________________________________________________*/

struct Object
{
	int x, y;
	int dim_x, dim_y;
	int value;
	bool state;
	bool taken;
	int image;



	Object(int _x, int _y, int _dim_x, int _dim_y, int _value, bool _state)
	{
	
		x = _x;
		y = _y;
		dim_x = _dim_x;
		dim_y = _dim_y;
		value = _value;
		state = _state;
	}

	Object(int _x, int _y, int _dim_x, int _dim_y, bool _state, bool _taken)
	{
		x = _x;
		y = _y;
		dim_x = _dim_x;
		dim_y = _dim_y;
		state = _state;
		taken = _taken;
	}

	
} medikit(482, 370, 40, 43, 10, false), energy(600, 370, 60, 67, 30, false), shield(1000, 370, 55, 65, 1, false) ;

// changing medikit position

void positionMedikit()
{
	if (level == 1) //for level 1
	{
		medikit.x = rand() % (1520 - medikit.dim_x);
		medikit.y = 70 + rand() % 260;
		medikit.state = true;
	}

	else if (level == 2) //for level 2
	{
		medikit.x = rand() % (1520 - medikit.dim_x);
		medikit.y = 350 + rand() % 395;
		medikit.state = true;
	}
}

void positionEnergy()
{
	static int recall = 0;

	if (level == 1) //for level 1
	{
		if (recall % 4 == 0)
		{
			energy.state = false;
		}

		if (recall % 12 == 0)
		{
			energy.x = rand() % (1520 - energy.dim_x);
			energy.y = 70 + rand() % 260;
			energy.state = true;
		}
	}
	else if (level == 2) //for level 2
	{
		if (recall % 4 == 0)
		{
			energy.state = false;
		}

		if (recall % 12 == 0)
		{
			energy.x = rand() % (1520 - energy.dim_x);
			energy.y = 350 + rand() % 375;
			energy.state = true;
		}
	}

	recall++;

	if (recall >= 120)
	{
		recall = 0;
	}
}

// for changing shield position
void shieldPositionChange()
{
	static int recall = 0;

	if (level == 1) //for level 1
	{
		if (recall % 40 == 0)
		{
			shield.state = false;
		}

		if (recall % 120 == 0)
		{
			shield.x = rand() % (1520 - shield.dim_x);
			shield.y = 70 + rand() % 260;
			shield.state = true;
		}
	}
	else if (level == 2) //for level 2
	{
		if (recall % 40 == 0)
		{
			shield.state = false;
		}

		if (recall % 120 == 0)
		{
			shield.x = rand() % (1520 - shield.dim_x);
			shield.y = 350 + rand() % 375;
			shield.state = true;
		}
	}

	recall++;

	if (recall >= 1200)
	{
		recall = 0;
	}
}

#endif 
