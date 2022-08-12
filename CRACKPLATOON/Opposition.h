#ifndef OPPOSITION_H_INCLUDED 
#define OPPOSITION_H_INCLUDED 

#include "Inrange.h" 

#include<stdio.h> 

struct Opposition 
{
	int x,y ;
	int dim_x , dim_y; 
	int image[20];
	int index;
	int value;
	bool state ;
	
	
	
	
	
	Opposition( int x1, int y1, int dim1_x,int dim1_y,int val, int ind , bool stat ) 
	  {
		x=x1;
		y=y1;
		dim_x=dim1_x; 
		dim_y=dim1_y;
		value=val;
		index=ind; 
		state=stat; 
		}
		Opposition( int x1, int y1,int val, int ind , bool stat ) 
	  {
		x=x1;
		y=y1;
		value=val;
		index=ind; 
		state=stat; 
		}
		
		void reassign( int x1, int y1,int val, int ind , bool stat ) 
	  {
		x=x1;
		y=y1;
		value=val;
		index=ind; 
		state=stat; 
		}
		
	 }police_one1(1720,68,10,0,true),police_one2(1620,68,10,0,true),police_one3(1520,68,10,0,true), police_two1(1720,655,10,0,true),police_two2(1720,600,10,0,true),police_two3(1720,555,10,0,true);
	  
		// for showing the enemy on screen level one 
		
void showEnemyOne()
{
	iShowImage(police_one1.x, police_one1.y, 190, 135, police_one2.image[police_one2.index]);
	iShowImage(police_one2.x, police_one2.y, 180, 135, police_one1.image[police_one1.index]);
	iShowImage(police_one3.x, police_one3.y, 170, 135, police_one3.image[police_one3.index]);

	if (police_one1.x <= 1430)
	{
		police_one1.state = true;
	}
	else
	{
		police_one1.state = false;
	}

	if (police_one2.x <= 1430)
	{
		police_one2.state = true;
	}
	
	
	
	else
	{
		police_one2.state = false;
	}

	if (police_one3.x <= 1430)
	{
		police_one3.state = true;
	}
	else
	{
		police_one3.state = false;
	}
}


void changeEnemyPosition()
{
	static int recall = 0;

	if (recall % 2== 0)
	{
		police_one1.x -= 3;

		if (police_one1.x <= -130)
		{
			police_one1.x = 1520;
		}
	}

	if (recall % 2 == 0)
	{
		police_one2.x -= 3;

		if (police_one2.x <= -130)
		{
			police_one2.x = 1520;
		}
	}

	if (recall % 2 == 0)
	{
		police_one3.x -= 4;

		if (police_one3.x <= -130)
		{
			police_one3.x = 1520;
		}
	}

	//for changing the image index of enemy 

	if (recall % 3 == 0)
	{
		police_one2.index++;

		if (police_one2.index > 5)
		{
			police_one2.index = 0;
		}
	}

	if (recall % 4 == 0)
	{
		police_one1.index++;

		if (police_one1.index > 8)
		{
			police_one1.index = 0;
		}
	}

	if (recall % 5 == 0)
	{
		police_one3.index++;

		if (police_one3.index > 8)
		{
			police_one3.index = 0;
		}
	}

	recall++;

	if (recall >= 2520)
	{
		recall = 0;
	}
}

void soldierEnemyCollision()
{
	/*Crossing from front.*/

	if (checkRange(police_one1.x, police_one1.y, 190, 135, soldier.x + soldier.extDim_x, soldier.y + soldier.extDim_y, soldier.dim_x, soldier.dim_y))
	{
		if (soldier.condition != 4 && soldier.condition != 6 && soldier.condition != 5 && soldier.condition != 7)
		{
			if (!active_shield)
			{
				if (soldier.health >= 10)
				{
					soldier.health -= 10;
				}
				else
				{
					soldier.health = 0;
				}
			}
			else
			{
				shield_count--;
				if (shield_count <= 0)
				{
					active_shield = false;
				}
			}
			police_one1.state = false;
			police_one1.x = 1580 + rand() % 120;
		}
	}




	if (checkRange(police_one2.x, police_one2.y, 180, 135, soldier.x + soldier.extDim_x, soldier.y + soldier.extDim_y, soldier.dim_x, soldier.dim_y))
	{
		if (soldier.condition != 4 && soldier.condition != 6 && soldier.condition != 5 && soldier.condition != 7)
		{
			if (!active_shield)
			{
				if (soldier.health >= 10)
				{
					soldier.health -= 10;
				}
				else
				{
					soldier.health = 0;
				}
			}
			else
			{
				shield_count--;
				if (shield_count <= 0)
				{
					active_shield = false;
				}
			}
			police_one2.state = false;
			police_one2.x = 1580 + rand() % 420;
		}
	}

	if (checkRange(police_one3.x, police_one3.y, 180, 135, soldier.x + soldier.extDim_x, soldier.y + soldier.extDim_y, soldier.dim_x, soldier.dim_y))
	{
		if (soldier.condition != 4 && soldier.condition != 6 && soldier.condition != 5 && soldier.condition != 7)
		{
			if (!active_shield)
			{
				if (soldier.health >= 10)
				{
					soldier.health -= 10;
				}
				else
				{
					soldier.health = 0;
				}
			}
			else
			{
				shield_count--;
				if (shield_count <= 0)
				{
					active_shield = false;
				}
			}
			police_one3.state = false;
			police_one3.x = 1580 + rand() % 120;
		}
	}

	/*Crossing from back.*/

	if (checkRange(police_one1.x, police_one1.y, 190, 135, soldier.x + soldier.extDim_x, soldier.y + soldier.extDim_y, soldier.dim_x, soldier.dim_y))
	{
		if (soldier.condition != 4 && soldier.condition != 6 && soldier.condition != 5 && soldier.condition != 7)
		{
			if (!active_shield)
			{
				if (soldier.health >= 10)
				{
					soldier.health -= 10;
				}
				else
				{
					soldier.health = 0;
				}
			}
			else
			{
				shield_count--;
				if (shield_count <= 0)
				{
					active_shield = false;
				}
			}
			police_one1.state = false;
			police_one1.x = 1580 + rand() % 120;
		}
	}





	if (checkRange(police_one3.x, police_one3.y, 180, 135, soldier.x + soldier.extDim_x, soldier.y + soldier.extDim_y, soldier.dim_x, soldier.dim_y))
	{
		if (soldier.condition != 4 && soldier.condition != 6 && soldier.condition != 5 && soldier.condition != 7)
		{
			if (!active_shield)
			{
				if (soldier.health >= 10)
				{
					soldier.health -= 10;
				}
				else
				{
					soldier.health = 0;
				}
			}
			else
			{
				shield_count--;
				if (shield_count <= 0)
				{
					active_shield = false;
				}
			}
			police_one3.state = false;
			police_one3.x = 1580 + rand() % 420;
		}
	}

	if (checkRange(police_one2.x, police_one2.y, 180, 135, soldier.x + soldier.extDim_x, soldier.y + soldier.extDim_y, soldier.dim_x, soldier.dim_y))
	{
		if (soldier.condition != 4 && soldier.condition != 6 && soldier.condition != 5 && soldier.condition != 7)
		{
			if (!active_shield)
			{
				if (soldier.health >= 10)
				{
					soldier.health -= 10;
				}
				else
				{
					soldier.health = 0;
				}
			}
			else
			{
				shield_count--;
				if (shield_count <= 0)
				{
					active_shield = false;
				}
			}
			police_one2.state = false;
			police_one2.x = 1580 + rand() % 120;
		}
	}
}

// level two enemy to show

void showEnemyTwo()
{
	iShowImage(police_two1.x, police_two1.y, 140, 95, enemy_image_level2);
	iShowImage(police_two3.x, police_two3.y, 140, 95, enemy_image_level2);
	iShowImage(police_two2.x, police_two2.y, 140, 95, enemy_image_level2);

	
	if (police_two1.x <= 1450)
	{
		police_two1.state = true;
		//when enemy will be able on screen 
	}
	else
	{
		police_two1.state = false;
	}

	if (police_two2.x <= 1450)
	{
		police_two2.state = true;
	}
	else
	{
		police_two2.state = false;
	}

	if (police_two3.x <= 1450)
	{
		police_two3.state = true;
	}
	else
	{
		police_two3.state = false;
	}
}

void changeEnemyPosition2() {

	static int recall = 0;

	if (recall % 1 == 0)
	{
		police_two1.x -= 2;

		if (police_two1.x <= -140)
		{
			police_two1.x = 1520 + rand() % 200;
			police_two1.y = 352 + rand() % 340;
		}
	}

	if (recall % 2 == 0)
	{
		police_two2.x -= 3;

		if (police_two2.x <= -140)
		{
			police_two2.x = 1520 + rand() % 200;
			police_two2.y = 352 + rand() % 340;
		}
	}

	if (recall % 3 == 0)
	{
		police_two3.x -= 3;

		if (police_two3.x <= -140)
		{
			police_two3.x = 1520 + rand() % 200;
			police_two3.y = 352 + rand() % 340;
		}
	}

	recall++;

	if (recall >= 2520)
	{
		recall = 0;
	}
}
// when collution occurred .


void changeFire()
{
	if (fire_index < 19)
	{
		fire_index++;
	}
	else
	{
		fire_index = 0;
		explosion = false;
		exploded1 = false;
		exploded2 = false;
		exploded3 = false;
		exploded4 = false;
		exploded5 = false;
		exploded6 = false;
	}
}











void showExplosion(int x, int y)
{
	iShowImage(x, y, 140, 140, fire_image[fire_index]);

	if (fire_index >= 19)
	{
		explosion = false;
		exploded1 = false;
		exploded2 = false;
		exploded3 = false;
		exploded4 = false;
		exploded5 = false;
		exploded6 = false;
	}
}





void fireEnemyCollision2()
{
	
	
	/*For enemy one.*/
	if (police_two1.state && checkRange(bullet_x, bullet_y, 20, 20, police_two1.x, police_two1.y + 6, 140, 89))
	{
		fire = false;
		soldier.kill += 1;

		bullet_x = helicopter.x + 110;

		explosion = true;
		exploded1 = true;
		explosion_x = police_two1.x;
		explosion_y = police_two1.y;

		police_two1.x = 1520 + rand() % 200;
		police_two1.y = 352 + rand() % 340;
	}

	if (exploded1)
	{
		showExplosion(explosion_x, explosion_y);
	}






	/*For enemy two.*/
	if (police_two2.state && checkRange(bullet_x, bullet_y, 20, 20, police_two2.x, police_two2.y + 6, 140, 89))
	{
		fire = false;
		soldier.kill += 1;

		bullet_x = helicopter.x + 110;

		explosion = true;
		exploded2 = true;
		explosion_x = police_two2.x;
		explosion_y = police_two2.y;

		police_two2.x = 1520 + rand() % 200;
		police_two2.y = 352 + rand() % 340;
	}

	if (exploded2)
	{
		showExplosion(explosion_x, explosion_y);
	}

	/*For enemy three.*/
	if (police_two3.state && checkRange(bullet_x, bullet_y, 20, 20, police_two3.x, police_two3.y + 6, 140, 89))
	{
		fire = false;
		soldier.kill += 1;

		bullet_x = helicopter.x + 110;

		explosion = true;
		exploded3 = true;
		explosion_x = police_two3.x;
		explosion_y = police_two3.y;

		police_two3.x = 1520 + rand() % 200;
		police_two3.y = 352 + rand() % 340;
	}

	if (exploded3)
	{
		showExplosion(explosion_x, explosion_y);
	}
} 



// setting up bomb 




//Function for bomb showing timer.


void bombRandom()
{
	static int recall = 0;

	if (recall % 3 == 0)
	{
		bomb_random = rand() % 400;
		
	}

	recall++;

	if (recall >= 300)
	{
		recall = 0;
	}
}

void changeBombPosition()
{
	{
		bomb_x -= 6;
	}

	if (bomb_x < -50)
	{
		bomb_x = 1520 + rand() % 3040;
	}
}

//antifire set

void enemyFire()
{
	antifire = rand() % 1000;

	antibullet1_x = police_two1.x + 10;
	antibullet2_x = police_two2.x + 10;
	antibullet3_x = police_two3.x + 10;

	hit1 = true;
	hit2 = true;
	hit3 = true;
}


void enemyFireL1()
{
	antifire = rand() % 1000;

	antibullet1_x = police_one1.x + 10;
	antibullet2_x = police_one2.x + 10;
	antibullet3_x = police_one3.x + 10;

}





void soldierEnemyCollision2()
{
	/*For enemy one.*/
	if (police_two1.state && checkRange(helicopter.x + helicopter.extDim_x, helicopter.y + helicopter.extDim_y, helicopter.dim_x, helicopter.dim_y, police_two1.x, police_two1.y + 6, 140, 89))
	{
		if (!active_shield)
		{
			soldier.health -= 20;
		}
		else
		{
			shield_count--;
			if (shield_count <= 0)
			{
				active_shield = false;
			}
		}

		explosion = true;
		exploded4 = true;
		explosion_x = helicopter.x + 80;
		explosion_y = helicopter.y + 40;

		police_two1.y = 352 + rand() % 340;
		police_two1.x = 1520 + rand() % 200;
	}

	if (exploded4)
	{
		showExplosion(explosion_x, explosion_y);
	}

	/*For enemy two.*/
	if (police_two2.state && checkRange(helicopter.x + helicopter.extDim_x, helicopter.y + helicopter.extDim_y, helicopter.dim_x, helicopter.dim_y, police_two2.x, police_two2.y + 6, 140, 89))
	{
		if (!active_shield)
		{
			soldier.health -= 20;
		}
		else
		{
			shield_count--;
			if (shield_count <= 0)
			{
				active_shield = false;
			}
		}

		explosion = true;
		exploded5 = true;
		explosion_x = helicopter.x + 80;
		explosion_y = helicopter.y + 40;

		police_two2.y = 352 + rand() % 340;
		police_two2.x = 1520 + rand() % 200;
	}

	if (exploded5)
	{
		showExplosion(explosion_x, explosion_y);
	}

	/*For enemy three.*/
	
	
	
	
	if (police_two3.state && checkRange(helicopter.x + helicopter.extDim_x, helicopter.y + helicopter.extDim_y, helicopter.dim_x, helicopter.dim_y, police_two3.x, police_two3.y + 6, 140, 89))
	{
		
		
		
		if (!active_shield)
		{
			soldier.health -= 20;
		}
		else
		{
			shield_count--;
			if (shield_count <= 0)
			{
				active_shield = false;
			}
		}





		explosion = true;
		exploded6 = true;
		explosion_x = helicopter.x + 80;
		explosion_y = helicopter.y + 40;

		police_two3.x = 1520 + rand() % 200;
		police_two3.y = 352 + rand() % 340;
	}

	if (exploded6)
	{
		showExplosion(explosion_x, explosion_y);
	}
}


#endif 

	