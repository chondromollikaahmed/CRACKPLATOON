#ifndef LEVELTWO_H_INCLUDED
#define LEVELTWO_H_INCLUDED



void levelTwo()
{
showBackground2(); // background


	iShowImage(helicopter.x, helicopter.y, 216, 180, helicopter.image_plane[soldier_plane_index]);


	if (medikit.x % 2 == 0 || medikit.x % 3 == 0)
	{
		if (medikit.state)
		{
			iShowImage(medikit.x, medikit.y, medikit.dim_x, medikit.dim_y, medikit.image);

			if (checkRange(helicopter.x + helicopter.extDim_x, helicopter.y + helicopter.extDim_y, helicopter.dim_x, helicopter.dim_y, medikit.x, medikit.y, 40, 43))
			{
				medikit.state = false;

				if (soldier.health <= 90)
				{
					soldier.health += 10;
				}
			}
		}
	}

	if (energy.state)
	{
		iShowImage(energy.x, energy.y, energy.dim_x, energy.dim_y, energy.image);

		if (checkRange(helicopter.x + helicopter.extDim_x, helicopter.y + helicopter.extDim_y, helicopter.dim_x, helicopter.dim_y, energy.x, energy.y, energy.dim_x, energy.dim_y))
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



	if (shield.state)
	{
		iShowImage(shield.x, shield.y, shield.dim_x, shield.dim_y, shield.image);

		if (checkRange(helicopter.x + helicopter.extDim_x, helicopter.y + helicopter.extDim_y, helicopter.dim_x, helicopter.dim_y, shield.x, shield.y, shield.dim_x, shield.dim_y))
		{
			if (shield_count <= 9)
			{
				shield_count++;
			}

			shield.state = false;
		}
	}

	//Showing shield sign.
	if (active_shield)
	{
		iShowImage(helicopter.x + 82, helicopter.y + 48, 50, 59, shield.image);
	}



	if (fire)
	{
		bullet_y = helicopter.y + 63;
		iShowImage(bullet_x, bullet_y, 20, 10, bullet_image);

		if (!pause) 
		{
			bullet_x += 10;
		}

		if (bullet_x > 1520)
		{
			fire = false;
			bullet_x = helicopter.x + 120;
		}

		fireEnemyCollision2();
	}


	showEnemyTwo();

	

	soldierEnemyCollision2();


	//For enemy one.
	if (antifire % 3 != 0 && police_two1.state)
	{
		if (hit1)
		{
			iShowImage(antibullet1_x, police_two1.y + 20, 20, 10, bullet_back_image);

			if (!pause) 
			{
				antibullet1_x -= 8;
			}

			//fire collisions
			if (checkRange(helicopter.x + helicopter.extDim_x, helicopter.y + helicopter.extDim_y, helicopter.dim_x, helicopter.dim_y, antibullet1_x, police_two1.y + 20, 20, 10))
			{
				if (!active_shield)
				{
					soldier.health -= 10;
				}
				else
				{
					shield_count--;
					if (shield_count <= 0)
					{
						active_shield = false;
					}
				}
				hit1 = false;
			}
		}

		if (antibullet1_x <= 0)
		{
			hit1 = false;
			antibullet1_x = police_two1.x + 10;
		}
	}

	//For enemy two.
	if (antifire % 4 != 0 && police_two2.state)
	{
		
		if (hit2)
		{
			iShowImage(antibullet2_x, police_two2.y + 20, 20, 10, bullet_back_image);

			if (!pause) //Bullet doesn't move when game is paused.
			{
				antibullet2_x -= 7;
			}

		
		
		
		
			if (checkRange(helicopter.x + helicopter.extDim_x, helicopter.y + helicopter.extDim_y, helicopter.dim_x, helicopter.dim_y, antibullet2_x, police_two2.y + 20, 20, 10))
			{
				if (!active_shield)
				{
					soldier.health -= 10;
				}
				else
				{
					shield_count--;
					if (shield_count <= 0)
					{
						active_shield = false;
					}
				}
				hit2 = false;
			}
		}

		if (antibullet2_x <= 0)
		{
			hit2 = false;
			antibullet2_x = police_two2.x + 10;
		}
	}

	//For enemy three.
	if (antifire % 5 != 0 && police_two3.state)
	{
		
		if (hit3)
		{
			iShowImage(antibullet3_x, police_two3.y + 20, 20, 10, bullet_back_image);

			if (!pause) 
			{
				antibullet3_x -= 6;
			}

			if (checkRange(helicopter.x + helicopter.extDim_x, helicopter.y + helicopter.extDim_y, helicopter.dim_x, helicopter.dim_y, antibullet3_x, police_two3.y + 20, 20, 10))
			{
				if (!active_shield)
				{
					soldier.health -= 10;
				}
				else
				{
					shield_count--;
					if (shield_count <= 0)
					{
						active_shield = false;
					}
				}
				hit3 = false;
			}
		}

		if (antibullet3_x <= 0)
		{
			hit3 = false;
			antibullet3_x = police_two3.x + 10;
		}
	}

	

	showNumber(675, 720, 35, soldier.kill);
	iShowImage(590, 703, 80, 80, icon[icon_index]);
	iShowImage(40, 720, 252, 50, health_bar[soldier.health / 10]);
	iShowImage(40, 660, 252, 50, shield_bar[shield_count]);
}

#endif 
