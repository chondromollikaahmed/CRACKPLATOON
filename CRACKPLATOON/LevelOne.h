#ifndef LEVELONE_H_INCLUDED 
#define LEVEL_ONE_H_INCLUDED 



// following function will do all the codes of level one 

void levelOne()
{

	showBackgroundOne(); // background 
    showSoldierOne(); //character 

	/*Firing from front.*/
	if (fire && (soldier.condition == 0 || soldier.condition == 2 || soldier.condition == 4 || soldier.condition == 6))
	{
		iShowImage(bullet_x, soldier.y + jumping_height + 70, 20, 10, bullet_image);

		if (!pause)  // bullet won't change its position if on pause 
		{
			bullet_x += 10;
		}

		if (bullet_x > 1520)
		{
			fire = false;
			bullet_x = soldier.x + 110;
		}

		/*Fire, enemy collision.*/

		if (fire && police_one1.state && checkRange(police_one1.x, police_one1.y, 190, 135, bullet_x, soldier.y, 20, 10))
		{
			if (soldier.condition != 4 && soldier.condition != 6 && soldier.condition != 5 && soldier.condition != 7)
			{
				soldier.kill += 1;
				fire = false;
				police_one1.x = 1580 + rand() % 120;
				bullet_x = soldier.x + 110;
			}
		}

		if (fire && police_one2.state && checkRange(police_one2.x, police_one2.y, 180, 135, bullet_x, soldier.y, 20, 10))
		{
			if (soldier.condition != 4 && soldier.condition != 6 && soldier.condition != 5 && soldier.condition != 7)
			{
				soldier.kill += 1;
				fire = false;
				police_one2.x = 1580 + rand() % 420;
				bullet_x = soldier.x + 110;
			}
		}

		if (fire && police_one3.state && checkRange(police_one3.x, police_one3.y, 180, 135, bullet_x, soldier.y, 20, 10))
		{
			if (soldier.condition != 4 && soldier.condition != 6 && soldier.condition != 5 && soldier.condition != 7)
			{
				soldier.kill += 1;
				fire = false;
				police_one3.x = 1580 + rand() % 120;
				bullet_x = soldier.x + 110;
			}
		}
	}

	/*Firing from back.*/

	if (fire && (soldier.condition == 1 || soldier.condition == 3 || soldier.condition == 5 || soldier.condition == 7))
	{
		iShowImage(bullet_back_x, soldier.y + jumping_height + 40, 20, 10, bullet_back_image);

		if (!pause) 
		{
			bullet_back_x -= 10;
		}

		if (bullet_back_x < -20)
		{
			fire = false;
			bullet_back_x = soldier.x;
		}


		if (fire && police_one1.state && checkRange(police_one1.x, police_one1.y, 190, 135, bullet_back_x + 150, soldier.y, 20, 10))
		{
			if (soldier.condition != 4 && soldier.condition != 6 && soldier.condition != 5 && soldier.condition != 7)
			{
				soldier.kill += 1;
				fire = false;
				police_one1.x = 1580 + rand() % 120;
				bullet_back_x = soldier.x - 110;
			}
		}

		if (fire && police_one2.state && checkRange(police_one2.x, police_one2.y, 180, 135, bullet_back_x + 150, soldier.y, 20, 10))
		{
			if (soldier.condition != 4 && soldier.condition != 6 && soldier.condition != 5 && soldier.condition != 7)
			{
				soldier.kill += 1;
				fire = false;
				police_one2.x = 1580 + rand() % 420;
				bullet_back_x = soldier.x - 110;
			}
		}

		if (fire && police_one3.state && checkRange(police_one3.x, police_one3.y, 180, 135, bullet_back_x + 150, soldier.y, 20, 10))
		{
			if (soldier.condition != 4 && soldier.condition != 6 && soldier.condition != 5 && soldier.condition != 7)
			{
				soldier.kill += 1;
				fire = false;
				police_one3.x = 1580 + rand() % 120;
				bullet_back_x = soldier.x - 110;
			}
		}
	}

	/*__________________________________Showing health gem, checking collision & counting health kill.________________________________*/

	if (medikit.x % 2 == 0 || medikit.x % 3 == 0)
	{
		if (medikit.state)
		{
			iShowImage(medikit.x, medikit.y, medikit.dim_x, medikit.dim_y, medikit.image);

			if (checkRange(soldier.x + soldier.extDim_x, soldier.y + soldier.extDim_y + jumping_height, 80, 130, medikit.x, medikit.y, medikit.dim_x, medikit.dim_y))
			{
				if (soldier.health <= 90)
				{
					soldier.health += medikit.value;
				}

				medikit.state = false;
			}
		}
	}

	if (energy.state)
	{
		iShowImage(energy.x, energy.y, energy.dim_x, energy.dim_y, energy.image);

		if (checkRange(soldier.x + soldier.extDim_x, soldier.y + soldier.extDim_y + jumping_height, 80, 130, energy.x, energy.y, energy.dim_x, energy.dim_y))
		{
			if (soldier.health <= 70)
			{
				soldier.health += energy.value;
			}
			else
			{
				soldier.health = 100;
			}

			energy.state = false;
		}
	}

// shield 

	if (shield.state)
	{
		iShowImage(shield.x, shield.y, shield.dim_x, shield.dim_y, shield.image);

		if (checkRange(soldier.x + soldier.extDim_x, soldier.y + soldier.extDim_y + jumping_height, 80, 130, shield.x, shield.y, shield.dim_x, shield.dim_y))
		{
			if (shield_count <= 9)
			{
				shield_count++;
			}

			shield.state = false;
		}
	}

	//Showing shield sign
	if (active_shield)
	{
		iShowImage(soldier.x + 62, soldier.y + 26 + jumping_height, 40, 47, shield.image);
	}



	showEnemyOne();

	bomb_state=true;
	if (bomb_state)
	{
		iShowImage(bomb_x, 75, 60, 70, bomb_image);

		if (soldier.visible && checkRange(soldier.x + soldier.extDim_x, soldier.y + soldier.extDim_y + jumping_height, soldier.dim_x, soldier.dim_y, bomb_x, 75, 60, 70) && soldier.condition < 4)
		{
			if (soldier.health >= 20)
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
			}
			else
			{
				if (!active_shield)
				{
					soldier.health = 0;
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
			}

			explosion_x = bomb_x - 100;
			//bomb_state = false;
			bomb_x = 1520 + rand() % 304;
		}
	}

	if (explosion)
	{
		showExplosion(explosion_x, 70);
	}

	soldierEnemyCollision();



	showNumber(675, 720, 35, soldier.kill);
	iShowImage(590, 703, 80, 80, icon[icon_index]);
	iShowImage(40, 720, 252, 50, health_bar[soldier.health / 10]);
	iShowImage(40, 660, 252, 50, shield_bar[shield_count]);
	//iShowImage(40, 600, 252, 50, "");


	if (soldier.kill>= 20)
	{
		//Resetting conditions.
		show_plane = 0;
		level = 2;

		soldier.health = 100;
		soldier_distance = 0;
		shield_count = 0;
		active_shield = false;

		soldier.x = 160;

		saveGame(); //To save the game progress.
	}
}

#endif