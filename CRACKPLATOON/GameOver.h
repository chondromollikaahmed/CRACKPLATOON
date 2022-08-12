#ifndef GAMEOVER_H_INCLUDED
#define GAMEOVER_H_INCLUDED


#include "KillTrack.h"
#include "Music.h"



void checkRank()
{

	FILE *fp = fopen("kill_tracks.bin", "rb");

	if (fp == NULL)
	{
		if (soldier.kill > 0)
		{
			soldier_rank = 1;
			game_over_index = 1;
			star_index = 0;
		}
		else
		{
			soldier_rank = 0;
			game_over_index = 0;
		}
	}

	else
	{
		KillTrack kill_track_temp;
		int i = 1;

		while (fread(&kill_track_temp, sizeof(struct KillTrack), 1, fp) == 1)
		{
			if (soldier.kill > kill_track_temp.kill)
			{
				soldier_rank = i;
				break;
			}

			i++;
		}

		if (soldier_rank == 0) //If the file has less then five high kills saved and the new kill is not higher than any of them.
		{
			if (i > 5)
			{
				game_over_index = 0;
			}
			else
			{
				soldier_rank = i;
				game_over_index = 2;
				star_index = soldier_rank - 1;
			}
		}

		else if (soldier_rank == 1)
		{
			game_over_index = 1;
			star_index = 0;
		}

		else if (soldier_rank >= 2 && soldier_rank <= 5)
		{
			game_over_index = 2;
			star_index = soldier_rank - 1;
		}

		fclose(fp);
	}
}


void gameOver()
{
	if (soldier.health <= 0 && menu_option != 0) //Checking if the game is over.
	{
		game_over = true;

		//Resetting conditions.
		level = 0;
		show_plane= 0;

		soldier.health = 100;
		soldier_distance = 0;
		shield_count = 0;
		active_shield = false;

		soldier.x = 160;

		helicopter.x = 160;
		helicopter.y = 520;

		jump = false;
		jumping = false;
		jumping_height = 0;
		soldier.condition = 0;
		eraseGame(); 
	}

	if (game_over)
	{

		if (!music_playing)
		{
			controlMusic(true);
			music_playing = true;
		}

		level = 0;
		soldier.health = 0;
		kill_track.kill = soldier.kill;

		checkRank(); 

		iShowImage(0, 0, scrW, scrH, game_over_image[game_over_index]); 
		if (game_over_highlight_index <= 2)
		{
			iShowImage(0, 0, scrW, scrH, game_over_highlight_image[game_over_index]); 
		}

		//Shows the kill on the game over screen.
		char kill_string[20];
		sprintf(kill_string, "%d", soldier.kill);
		iSetColor(255, 0, 0);
		iText(790, 409, kill_string, GLUT_BITMAP_TIMES_ROMAN_24);

		if (game_over_index != 0) //If the soldier has acquired a position in the high kill list.
		{
			//iShowImage(0, 0, 0, 0, star_image[star_index]); 

			setSoldierName(); 
		}
	}
}

#endif // !GAMEOVER_H_INCLUDED
