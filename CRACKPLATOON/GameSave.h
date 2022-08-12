#ifndef GAMESAVE_H_INCLUDED
#define GAMESAVE_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS

#include "Setter.h" 
#include <iostream>

using namespace std;

struct GameSave 
{
	int menu_option;
	int level ;
	int show_plane ;
	int kill ;

	GameSave(){
	
	
	}
	
	GameSave(int mo, int lev , int sp, int k ) 
	{
		menu_option=mo;
		level=lev;
		show_plane=sp;
		kill=k; 
	}
	
	void reAssign(int mo, int lev , int sp, int k ) 
	{
		menu_option=mo;
		level=lev;
		show_plane=sp;
		kill=k; 
	}
}game_save(0,0,0,0); 

void saveGame()
{
	FILE *fp = fopen("game_data.bin", "wb");

	game_save.reAssign(menu_option, level, show_plane, soldier.kill);


	fwrite(&game_save, sizeof(struct GameSave), 1, fp);
	

	fclose(fp);
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
void loadGame()
{
	FILE *fp = fopen("game_data.bin", "rb");

	if (fp == NULL)
	{
		
		menu_option = 6;
		welcome = 1;
		level=0;
		show_plane= 0;
         soldier.kill = 0;
	}
	else
	{
		GameSave game_save_temp;

		while (fread(&game_save_temp, sizeof(struct GameSave), 1, fp) == 1)
		{
			menu_option = game_save_temp.menu_option;
			level = game_save_temp.level;
			show_plane = game_save_temp.show_plane;
			soldier.kill = game_save_temp.kill;
		}

		fclose(fp);
	}
}




void eraseGame()
{
	FILE *fp = fopen("game_data.bin", "wb");

	game_save.reAssign(6, 0, 0, 0);

	fwrite(&game_save, sizeof(struct GameSave), 1, fp);

	fclose(fp);
}
#endif