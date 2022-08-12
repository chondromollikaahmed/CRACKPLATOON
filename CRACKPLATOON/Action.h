#ifndef ACTION_H_INCLUDED 
#define ACTION_H_INCLUDED 

#include "Setter.h"  

/* level one 
changing character action 
when idle 
*/ 
void changeIdleImage()
{
	soldier_idle_index++; //facing right side 
	 if(soldier_idle_index>6)
	{
		soldier_idle_index=0;
	}
	soldier_idleback_index++ ; // facing left side 
	
	if(soldier_idleback_index >5) 
	{
		soldier_idleback_index=0; 
	}
}

// while running image 

void changeAttackImage() 
{ 
	static int change =0;
	if(change%2==0) 
	 {
		soldier_attack_index++; 
	} 
	if(soldier_attack_index>5) 
	 {
		soldier_attack_index=0;
	}
	
	change++ ; 
	if(change>=20) 
	 {
		change=0;
	}
}

void changeAttackBackImage()
{ 
	static int change =0;
	if(change%2==0) 
	{
		soldier_attackback_index ++ ;
	}
	if(soldier_attackback_index>5)
	{
		soldier_attackback_index=0;
	}
	change++; 
	
	if(change>=20)
	{
		change = 0;
	}
}

// function for jumping 
// we will use timer function 
// this function will only work when up key will be pressed 

void Jump()
{
	if(jump) // if the player already in jum it will be true 
	{
		if (jumping) //While jumping is true (when the up key is pressed). It will be false when the soldier reaches his maximum jump height.
		{
			jumping_height += 5;

			if (jumping_height >= JUMPLIMIT)
			{
				jumping = false; //The soldier has reached his maximum jump height.
			}

			if (soldier_jumping_index < 7) //When jumping up.
			{
				soldier_jumping_index++;
			}
		}
		else //This is for when soldier his falling down from his maximum jump height.
		{
			jumping_height -= 5;

			if (jumping_height <= 0)
			{
				jump = false; //soldier has come down to the ground.
				jumping_height = 0;

				if (soldier.condition == 4 || soldier.condition == 6)
				{
					soldier.condition = 0;
				
				}
				else if (soldier.condition == 5 || soldier.condition == 7)
				{
					soldier.condition = 1;
				
				}
			}

			if (soldier_jumping_index > 0) //When coming down.
			{
				soldier_jumping_index--;
			}
		}
	}

}

//for showing soldier

void showSoldierOne()
{
	if (soldier.condition == 0) //If standing.
	{
		iShowImage(soldier.x, soldier.y, 160, 160, soldier.image_idle[soldier_idle_index]); /*Showing idle images from an array.
		The image index is being changed by calling void changeIdleImage() from a timer when no key is pressed.*/
	}

	else if (soldier.condition == 1) //If standing backward.
	{
		iShowImage(soldier.x, soldier.y, 160, 160, soldier.image_idleback[soldier_idleback_index]); /*Showing backward idle images from an array.
		The image index is being changed by calling void changeIdleImage() from a timer when no key is pressed.*/
	}

	else if (soldier.condition == 2) //If attack.
	{
		iShowImage(soldier.x, soldier.y, 160, 160, soldier.image_attack[soldier_attack_index]); /*Showing attack images from an array.
		The image index is being changed by calling void changeAttackImage() from void iSpecialKeyboard() when no right key is pressed.*/

		soldier.condition_changer++;
		if (soldier.condition_changer >= 200)
		{
			soldier.condition_changer = 0;
			soldier.condition = 0;
		}
	}

	else if (soldier.condition == 3) //If attack backward.
	{
		iShowImage(soldier.x, soldier.y, 160, 160, soldier.image_attackback[soldier_attackback_index]); /*Showing attack backward images from an array.
		The image index is being changed by calling void changeAttackBackImage() from void iSpecialKeyboard() when left key is pressed.*/

		soldier.condition_changer++;
		if (soldier.condition_changer >= 200)
		{
			soldier.condition_changer = 0;
			soldier.condition = 1;
		}
	}

	else if (soldier.condition == 4 || soldier.condition == 6) //If jumping.
	{
		iShowImage(soldier.x, soldier.y + jumping_height, 160, 160, soldier.image_jumping[soldier_jumping_index]); /*Showing jumping images from an array.
		The image index is being changed by calling void Jump() from void iSpecialKeyboard() when up key is pressed.*/
	}

	else if (soldier.condition == 5 || soldier.condition == 7) //If jumping back.
	{
		iShowImage(soldier.x, soldier.y + jumping_height, 160, 160, soldier.image_jumpingback[soldier_jumping_index]); /*Showing jumping back images from an array.
		The image index is being changed by calling void Jump() from void iSpecialKeyboard() when up key is pressed.*/
	}

	//If the soldier is on the screen.
	if (soldier.x >= 40 && soldier.x <= 1360)
	{
		soldier.visible = true;
	}
	else
	{
		soldier.visible = false;
	}
}

// for level to fly with plane 
void changePlaneImage()
{
	soldier_plane_index++;

	if (soldier_plane_index > 7)
	{
		soldier_plane_index = 0;
	}
}

void movePlane()
{
	static int call = 0;

	if (plane_direction == 1)
	{
		if (helicopter.x + helicopter.extDim_x >= 3)
		{
			helicopter.x -= 4;
		}
	}
	if (plane_direction == 2)
	{
		if (helicopter.x + helicopter.extDim_x + helicopter.dim_x <= 1517)
		{
			helicopter.x += 4;
		}
	}
	if (plane_direction == 3)
	{
		if (helicopter.y + helicopter.extDim_y + helicopter.dim_y <= 789)
		{
			helicopter.y += 4;
		}
	}
	if (plane_direction == 4)
	{
		if (helicopter.y + helicopter.extDim_y >= 3)
		{
			helicopter.y -= 4;
		}
	}

	call++;

	if (call >= 75)
	{
		plane_direction = 0;
		call = 0;
	}
}

#endif 

	