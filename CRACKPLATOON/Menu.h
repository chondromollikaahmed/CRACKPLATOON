#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "GameSave.h"
#include "Music.h"
#include "KillTrack.h"



void selectMenuOption(int menu_x, int menu_y)
{
	if (menu_option == 0 && !game_over && level != 1 && level != 2)
	{
		if (menu_x >= 552 && menu_x <= 968 && menu_y >= 490 && menu_y <= 547)
		{
			menu_option = 1; //mission menu 
		}

		if (menu_x >= 552 && menu_x <= 968 && menu_y >= 429 && menu_y <= 486)
		{
			menu_option = 2; 
		}

		if (menu_x >= 552 && menu_x <= 968 && menu_y >= 368 && menu_y <= 426)
		{
			menu_option = 3; //
		}

		if (menu_x >= 552 && menu_x <= 968 && menu_y >= 305 && menu_y <= 364)
		{
			menu_option = 4; //
		}

		if (menu_x >= 552 && menu_x <= 968 && menu_y >= 244 && menu_y <= 302)
		{
			menu_option = 5; //
		}

		if (menu_x >= 552 && menu_x <= 968 && menu_y >= 181 && menu_y <= 240)
		{
			exit(0); //For exit.
		}
	}
	
	
	else if (menu_option == 1)
	{
		if (menu_x >= 552 && menu_x <= 968 && menu_y >= 490 && menu_y <= 547)
		{
			welcome = 1; //new game 
			menu_option = 6; // stopping 

			eraseGame(); //for erasing saved game 

			controlMusic(true); //For playing sound.
		}
		
	 if (menu_x >= 552 && menu_x <= 968 && menu_y >= 429 && menu_y <= 486)
		{
			loadGame();

 //

			controlMusic(true); 

//
		}
	}
	
	if (menu_option >= 1 && menu_option <= 5 && level != 1 && level != 2)
	{
		if (menu_x >= 552 && menu_x <= 968 && menu_y >= 60 && menu_y <= 116)
		{
			menu_option = 0; //To go back.
		}
	}
}


void showMenu()
{

	iShowImage(0, 0, scrW, scrH, menu_image[menu_option]);






 /*


select option with iMouse () 

.*/

	if (menu_option == 0 && highlight_index <= 5 && highlight_index >= 0)
	{
		iShowImage(0, 0, scrW, scrH, menu_highlight_image[highlight_index]);
	}

	else if (menu_option == 1 && mission_highlight_index <= 1 && mission_highlight_index >= 0)
	{
		iShowImage(0, 0, scrW, scrH, mission_highlight_image[mission_highlight_index]);
	}

	if (menu_option >= 1 && menu_option <= 5 && back_highlight_index >= 0 && back_highlight_index <= 4)
	{
		iShowImage(0, 0, scrW, scrH, back_highlight_image[back_highlight_index]);
	}

	if (menu_option == 2) 
	{
		showKillTracks(); // kill list
	}
}



#endif 