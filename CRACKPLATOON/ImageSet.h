#ifndef IMAGESET_H_INCLUDED 
#define IMAGESET_H_INCLUDED 
#include "Object.h"
#include "Opposition.h"



void setImage()
{ 
	
	
	
	
	
	for (int i = 0; i <= 9; i++)
	{
		digit_image[i] = iLoadImage(digit_image_location[i]);
	}

	
	// 
	
	
	medikit.image = iLoadImage("others\\icons\\medikit.png");
	energy.image = iLoadImage("others\\icons\\energy.png");
	shield.image = iLoadImage("others\\icons\\shield.png");
	
	
	
	
	
	
	for (int i = 0; i <= 5; i++)
	{
		menu_image[i] = iLoadImage(menu_image_location[i]);
	}

	for (int i = 0; i <= 5; i++)
	{
		menu_highlight_image[i] = iLoadImage(menu_highlight_image_location[i]);
	}



	mission_highlight_image[0] = iLoadImage("menu\\highlight\\new_game.png");
	mission_highlight_image[1] = iLoadImage("menu\\highlight\\continue.png");

	back_highlight_image[0] = iLoadImage("menu\\highlight\\back\\1.png");
	back_highlight_image[1] = iLoadImage("menu\\highlight\\back\\2.png");
	back_highlight_image[2] = iLoadImage("menu\\highlight\\back\\3.png");
	back_highlight_image[3] = iLoadImage("menu\\highlight\\back\\4.png");
	back_highlight_image[4] = iLoadImage("menu\\highlight\\back\\5.png");






for (int i = 0; i <= 10; i++)
	{
		health_bar[i] = iLoadImage(health_bar_image[i]);
	}

	for (int i = 0; i <= 10; i++)
	{
		shield_bar[i] = iLoadImage(shield_bar_image[i]);
	}

/* 








*/

    icon[0] = iLoadImage("others\\icons\\gun000.png");
	icon[1] = iLoadImage("others\\icons\\gun001.png");




for (int i = 0; i <= 19; i++)
	{
		fire_image[i] = iLoadImage(fire_image_location[i]);
	}
	
	
	
	//secondary 
	
	screen = iLoadImage("others\\screens\\land_screen.png");
	plane[0] = iLoadImage("others\\objects\\plane0.png");
	plane[1] = iLoadImage("others\\objects\\plane1.png");
	finish = iLoadImage("others\\screens\\finish.png");


// level one bg

bg_one0 = iLoadImage("level_one\\background\\bg_one0.png");

	bg_one1[0] = iLoadImage("level_one\\background\\bg_one1.png");
	bg_one1[1] = iLoadImage("level_one\\background\\bg_one1.png");

	bg_one2[0] = iLoadImage("level_one\\background\\bg_one2.png");
	bg_one2[1] = iLoadImage("level_one\\background\\bg_one2.png");

	bg_one3[0] = iLoadImage("level_one\\background\\bg_one3.png");
	bg_one3[1] = iLoadImage("level_one\\background\\bg_one3.png");


/*

extra 
object 
if need 


*/

// level one character
for (int i = 0; i <= 7; i++)
	{
		soldier.image_idle[i] = iLoadImage(soldier_idle_image[i]);
	}

	for (int i = 0; i <= 7; i++)
	{
		soldier.image_idleback[i] = iLoadImage(soldier_idleback_image[i]);
	}


	for (int i = 0; i <= 5; i++)
	{
		soldier.image_attack[i] = iLoadImage(soldier_attack_image[i]);
	}

	for (int i = 0; i <= 5; i++)
	{
		soldier.image_attackback[i] = iLoadImage(soldier_attackback_image[i]);
	}

	for (int i = 0; i <= 7; i++)
	{
		soldier.image_jumping[i] = iLoadImage(soldier_jumping_image[i]);
	}


	for (int i = 0; i <= 7; i++)
	{
		soldier.image_jumpingback[i] = iLoadImage(soldier_jumpingback_image[i]);
	}




//bullet 

bullet_image = iLoadImage("level_one\\arms\\bullet.png");
	bullet_back_image = iLoadImage("level_one\\arms\\bullet_back.png");
	
	
	
	// opponent 
	
	
for (int i = 0; i <=9; i++)
	{
		police_one1.image[i] = iLoadImage(enemy1_image_location[i]);
	}



	for (int i = 0; i <=9; i++)
	{
		police_one2.image[i] = iLoadImage(enemy2_image_location[i]);
	}

	

	for (int i = 0; i <=9; i++)
	{
		police_one3.image[i] = iLoadImage(enemy3_image_location[i]);
	}



// bg lev __2 

bg_two0 = iLoadImage("level_two\\background\\bg_two0.png");

	bg_two1[0] = iLoadImage("level_two\\backgroung\\bg_two1.png");
	bg_two1[1] = iLoadImage("level_two\\background\\bg_two1.png");

	bg_two2[0] = iLoadImage("level_two\\backgroung\\bg_two2.png");
	bg_two2[1] = iLoadImage("level_two\\background\\bg_two2.png");

	bg_two3[0] = iLoadImage("level_two\\background\\bg_two3.png");
	bg_two3[1] = iLoadImage("level_two\\background\\bg_two3.png");

enemy_image_level2 = iLoadImage("level_two\\enemy\\enemy_000.png");
	bomb_image = iLoadImage("level_one\\enemy\\bomb.png");

	for (int i = 0; i <= 7; i++)
	{
		helicopter.image_plane[i] = iLoadImage(soldier_plane_image[i]);
	}
	
	
	//game over 
	
	game_over_image[0] = iLoadImage("game_over\\failed0.png");
	game_over_image[1] = iLoadImage("game_over\\failed1.png");
	game_over_image[2] = iLoadImage("game_over\\failed2.png");

	game_over_highlight_image[0] = iLoadImage("game_over\\highlight\\failed0.png");
	game_over_highlight_image[1] = iLoadImage("game_over\\highlight\\failed1.png");
	game_over_highlight_image[2] = iLoadImage("game_over\\highlight\\failed2.png");

	// pause 
	

	pause_screen = iLoadImage("others\\screens\\pause.png");
}


#endif


