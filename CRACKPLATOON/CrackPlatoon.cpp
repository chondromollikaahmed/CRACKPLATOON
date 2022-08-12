#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include "iGraphics.h"
#include "Setter.h"
#include "ImageSet.h"
#include "Soldier.h" 
#include "Opposition.h" 
#include "Object.h" 
#include "InRange.h"
#include "Action.h"
#include "Background.h"
#include "Menu.h"
#include "Music.h"
#include "LevelOne.h"
#include "LevelTwo.h"
#include "GameSave.h"
#include "KillTrack.h"
#include "GameOver.h"
#include "Intro.h"
#pragma comment (lib, "User32.lib")



using namespace std;
bool travel;
int temp;
int x, y ;

void iDraw()
{
	iClear();
	
	
	// for menu showing 
	
	if (menu_option >= 0 && menu_option <= 5)
	{
		showMenu(); 
	}

	else if(welcome == 1)
	{

		Intro();
	}
	
	else if (level == 1)
	{
		levelOne(); 
	}

  
  else if (show_plane== 1)
	{
		iShowImage(0, 0, scrW, scrH, screen);

		if (!plane_taken)
		{
			iShowImage(1240, 34, 240, 100, plane[0]);
			showSoldierOne();
		}
		else
		{
			iShowImage(0, 0, scrW, scrH, finish);
			iShowImage(1200, 15, 200, 178, plane[1]);
		}
	}

 
 
 else if (level == 2)
	{
		levelTwo();
		
	}
 

  gameOver();
 
 if (pause)
	{
		iShowImage(0, 0, scrW, scrH, pause_screen);
	}
 
 
 
  
 
 } 
 
 
 void iMouseMove(int mx, int my)
{
   x=mx ;
   y=my;
} 







void iPassiveMouse(int mx, int my)
{
	if (!pause)
	{
		if (menu_option >= 0 && menu_option <= 5)
		{
			if (mx >= 552 && mx <= 968 && my >= 490 && my <= 547)
			{
				highlight_index = 0;
			}
			else if (mx >= 552 && mx <= 968 && my >= 429 && my <= 486)
			{
				highlight_index = 1;
			}
			else if (mx >= 552 && mx <= 968 && my >= 368 && my <= 426)
			{
				highlight_index = 2;
			}
			else if (mx >= 552 && mx <= 968 && my >= 305 && my <= 364)
			{
				highlight_index = 3;
			}
			else if (mx >= 552 && mx <= 968 && my >= 244 && my <= 302)
			{
				highlight_index = 4;
			}
			else if (mx >= 552 && mx <= 968 && my >= 181 && my <= 240)
			{
				highlight_index = 5;
			}
			else
			{
				highlight_index = 6;
			}

			//new game && continue
			if (menu_option == 1)
			{
				if (mx >= 552 && mx <= 968 && my >= 490 && my <= 547)
				{
					mission_highlight_index = 0;
				}
				else if (mx >= 552 && mx <= 968 && my >= 429 && my <= 486)
				{
					mission_highlight_index = 1;
				}
				else
				{
					mission_highlight_index = 2;
				}
			}

			//back highlight
			if (mx >= 552 && mx <= 968 && my >= 60 && my <= 116)
			{
				back_highlight_index = menu_option - 1;
			}
			else
			{
				back_highlight_index = 5;
			}

			game_over_highlight_index = 3;
		}

		//For highlighting home button in game over screen.
		else if (game_over)
		{
			if (mx >= 552 && mx <= 968 && my >= 60 && my <= 116)
			{
				game_over_highlight_index = game_over_index;
			}
			else
			{
				game_over_highlight_index = 3;
			}
		}

	}
}


void iMouse(int button, int state, int mx, int my)
{
	if (!pause)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		{

			if (menu_option >= 0 && menu_option <= 5) //screen on menu page 
			{
				selectMenuOption(mx, my);
			}
			/*
					level = 1; 
					saveGame///// 
			*/
			else if (show_plane== 1 && plane_taken)
			{
				if (mx >= 630 && mx <= 882 && my >= 468 && my <= 645)
				{
					level = 2; 
					show_plane= 0; //
                    saveGame(); 
				}
			}
			/* 
			
			
			,,,,
			
			*/

			if (game_over_index == 0 || game_over_index == 1 || game_over_index == 2) 
			{
				if (game_over_index == 1 || game_over_index == 2) 
				{
					activateTextBox(mx, my); 
				}

				
				if (mx >= 552 && mx <= 968 && my >= 60 && my <= 116)
				{
					menu_option = 0; 
					controlMusic(true); 
					music_playing = false;

					level = 0;
					show_plane= 0;
                    soldier.kill = 0;
					soldier.health = 100;
					soldier_distance = 0;
					plane_taken = false;

					soldier.x = 160;

					helicopter.x = 160;
					helicopter.y = 520;

					jump = false;
					jumping = false;
					jumping_height = 0;

					
					soldier.condition = 0;

					game_over = false;
					soldier_rank = 0;
					game_over_index = 3;
					/* https://www.tutorialspoint.com/c_standard_library/c_function_memset.htm#:~:text=Description,to%2C%20by%20the%20argument%20str.
					
					*/
					memset(kill_track.name, NULL, sizeof(kill_track.name)); 
					name_index = 0;
				}
			}
		}

		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{
          //////will check further 
		}
	}
}




void iKeyboard(unsigned char key)
{
	if (!pause)
	{
		if (field_active) 
		{
			inputName(key);
		}

		if (key == '\r')
		{
			if (field_active && game_over && soldier_rank != 0) 
			{
				field_active = false; 
				saveKill();
				memset(kill_track.name, NULL, sizeof(kill_track.name)); 
				name_index = 0;
				soldier.health = 100;
				soldier.kill = 0;
				game_over = false;
				menu_option = 0;
			}
		}

		if (key == ' ')
		{
			fire = true;
		}

		if (key == 'e' || key == 'E')
		{
			/*
		 if (show_plane== 1)
			{
				if (soldier.x + soldier.extended_x + 35 >= 1320 && soldier.x + soldier.extended_x + soldier.dimension_x - 35 <= 1480)
				{
					plane_taken = true;
				}
			}
			*/
		}

		if (key == 'm' || key == 'M')
		{
			if (!field_active)
			{
				if (!mute)
				{
					controlMusic(false);
					mute = true;
				}
				else
				{
					mute = false;
					controlMusic(true);
				}
			}
		}

		if (key == 's' || key == 'S')
		{
			if ((level == 1 || level == 2) && shield_count > 0)
			{
				if (!active_shield)
				{
					active_shield = true;
				}
				else
				{
					active_shield = false;
				}
			}
		}

		
	if (key == 'p' || key == 'P')
	{
		if (welcome!=0|| level != 0 || show_plane != 0)
		{
			if (!pause)
			{
				pause = true;

				iPauseTimer(t_ten);
				iPauseTimer(t_twenty);
				iPauseTimer(t_forty);
				iPauseTimer(t_hund);
				iPauseTimer(t_one_sec);
				iPauseTimer(t_five_sec);
			}
			else
			{
				pause = false;
				iResumeTimer(t_ten);
				iResumeTimer(t_twenty);
				iResumeTimer(t_forty);
				iResumeTimer(t_hund);
				iResumeTimer(t_one_sec);
				iResumeTimer(t_five_sec);

				
          
			}
		}
	}
	if(key=='f')
		fall=true;







	if (key == 'c')
		{
			travel = true;
			
		}

		else if (travel)
		{
			
			if (key == '1')
			{
			
				welcome = 1;
				level = 0;
				show_plane = 0;
				menu_option = 6;
				game_over = false;
			}

			if (key == '2')
			{
				level = 1;
				welcome = 0;
				show_plane = 0;
				menu_option = 6;
				game_over = false;
			}

			if (key == '3')
			{
				show_plane = 1;
				welcome = 0;
				level = 0;
				menu_option = 6;
				game_over = false;

				intro.x = 160;
				intro.y = 30;
			}

			if (key == '4')
			{
				welcome = 0;
				level = 1;
				show_plane = 0;
				menu_option = 6;
				soldier.kill+=5;
				game_over = false;
			}

			if (key == '5')
			{
				welcome = 0;
				level = 2;
				show_plane = 0;
				menu_option = 6;
				soldier.kill+=6;
				game_over = false;
			}

			if (key == '6')
			{
				level = 2;
				welcome = 0;
				show_plane = 0;
				menu_option = 6;
				game_over = false;

				shield_count = 0;
				active_shield = false;

				helicopter.x = 160;
				helicopter.y = 520;
			}

			travel = false;
		}
	}













}




void iSpecialKeyboard(unsigned char key)
{
	if (!pause)
	{
		if (key == GLUT_KEY_LEFT)
		{
		
		/*
			if (show_plane == 1) 
			{
				if (jumping_height == 0)
				{
					soldier.condition = 3;
				}

				if (soldier.x > -34)
				{
					soldier.x -= 4;
				}

				changeAttackBackImage();
			}
			*/

			if (level == 1) 
			{
				if (jumping_height == 0)
				{
					soldier.condition = 3;
				}

				if (soldier.x > -34)
				{
					soldier.x -= 3;
				}

				soldier_distance--;

				moveBackgroundBack();
				changeAttackBackImage();
			}

			if (level == 2 && helicopter.x + helicopter.extDim_x > 15) 
			{
				plane_direction = 1;
			}
		}

		if (key == GLUT_KEY_RIGHT)
		{
		/*
			if ( show_plane == 1) 
			{
				if (jumping_height == 0)
				{
					soldier.condition = 2;
				}

				if (intro_soldier.x < 1395)
				{
					soldier.x += 4;
				}

				changeRunningImage();
			}
*/
			if (level == 1) 
			{
				if (jumping_height == 0)
				{
					soldier.condition = 2;
				}

				if (soldier.x < 1485)
				{
					if (soldier.x < 1100)
					{
						soldier.x += 3;
					}
					else
					{
						soldier.x += 8;
					}

					soldier_distance++;
				}
				else
				{
					soldier.x = -125;
				}

				moveBackground();
				changeAttackImage();
			}

			if (level == 2 && helicopter.x + helicopter.extDim_x + helicopter.dim_x < 1505) 
			{
				plane_direction = 2;
			}
		}

		if (key == GLUT_KEY_UP)
		{
		/*
			if (show_plane== 1) 
			{
				if (soldier.condition <= 3)
				{
					soldier.condition += 4;
				}

				if (!jump)
				{
					jump = true;
					jumping = true;
				}
			}
*/
			if (level == 1) 
			{
				if (soldier.condition <= 3)
				{
					soldier.condition += 4;
				}

				if (!jump)
				{
					jump = true;
					jumping = true;
				}
			}

			if (level == 2 && helicopter.y + helicopter.extDim_y + helicopter.dim_y < 777) 
			{
				plane_direction = 3;
			}
		}

		if (key == GLUT_KEY_DOWN)
		{
			if (level == 2 && helicopter.y + helicopter.extDim_y > 15) 
			{
				plane_direction = 4;
			}
		}

		if (key == GLUT_KEY_HOME)
		{
			
			menu_option = 0; 
			controlMusic(true); 
			music_playing = false;

			level = 0;
			show_plane= 0;

			soldier.kill = 0;
			soldier.health = 100;
			soldier_distance = 0;
			shield_count = 0;
			active_shield = false;
			plane_taken = false;

			soldier.x = 160;

			helicopter.x = 160;
			helicopter.y = 520;

			jump = false;
			jumping = false;
			jumping_height = 0;

		
			soldier.condition = 0;

		


			game_over = false;
			soldier_rank = 0;
			game_over_index = 3;
			memset(kill_track.name, NULL, sizeof(kill_track.name)); 
			name_index = 0;
		}
	}

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
}









void func1()
{

	if (level == 1)
	{
		changeEnemyPosition();
		changeBombPosition();
	}

	if (level == 1 || level == 2 || explosion)
	{
		changeFire();
	}

	if (level == 2)
	{
		changeBackgroundTwo3();
		changeEnemyPosition2();

		if (plane_direction > 0)
		{
			movePlane();
		}
	}
}

void func2()
{
	if ( level == 1 || show_plane == 1)
	{
		Jump();
	}

	if (level == 2)
	{
		changeBackgroundTwo2();
	}
}

void func3()
{
	if (level == 1 || level == 2)
	{
		moveIcon();
	}

	if (level == 2)
	{
		changeBackgroundTwo1();
	}
}

void func4()
{
	if ( level == 1 || show_plane == 1)
	{
		changeIdleImage();
	}

	if (level == 1 || level == 2)
	{
		shieldPositionChange();
	}

	if (level == 2)
	{
		changePlaneImage();
	}
}

void func5()
{
	if (level == 1 || level == 2)
	{
		positionEnergy();
	}

}

void func6()
{
	if (level == 1 || level == 2)
	{
		positionMedikit();
	}

	if (level == 2)
	{
		enemyFire(); // something might need to be added 
	}
}


void chngIntro()
{
	 if(welcome == 1)
	 {
		 dx+=15;
		 
		 if(dx>=1200||fall&&count1==0)
	      { 
			  intro.x=dx;
			  intro.y=dy;
           parashow=true;
		   count1++;
	      }
	 }

	 

}















	

// codes starts from here 
int main()
{
	t_ten= iSetTimer(10, func1);
	t_twenty= iSetTimer(20, func2);
	t_forty= iSetTimer(40, func3);
	t_hund = iSetTimer(100, func4);
	t_one_sec = iSetTimer(1000, func5);
	t_five_sec = iSetTimer(5000, func6);
	temp=iSetTimer(5,chngIntro);

	iInitialize(scrW, scrH,"CRACK PLATOON ©™⁰ ⁰ ¹");

	setImage();

	controlMusic(true); 

	iStart();


	return 0;
}


