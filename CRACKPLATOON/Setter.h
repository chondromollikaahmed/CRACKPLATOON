#ifndef SETTER_H_INCLUDED 
#define SETTER_H_INCLUDED 
#include "Soldier.h"
 

#define scrW 1520 
#define scrH 792

/*
setting up the timer */

int t_ten ,t_twenty , t_forty , t_hund , t_one_sec , t_five_sec ;
int level;

/* setting up the location of menu images with char array */


int menu_image[7] ; //to save the value of mwnu image which was returned from iLoadimage

int menu_option =0; 

int highlight_index =6 ;

int mission_highlight_index= 3;
int back_highlight_index=5; 

int back_highlight_image[6] ;

int menu_highlight_image[7] ; 

int mission_highlight_image[3];

char menu_image_location[][40] ={ "menu\\menu.png", "menu\\mission.png", "menu\\most_kills.png", "menu\\story.png", "menu\\controls.png", "menu\\about.png" }; 


char menu_highlight_image_location[][40] = { "menu\\highlight\\1.png", "menu\\highlight\\2.png", "menu\\highlight\\3.png", "menu\\highlight\\4.png", "menu\\highlight\\5.png", "menu\\highlight\\6.png" };


/* for playing music */ 

bool play_music= true ; // 
bool mute = false ; 
bool music_playing = false ; 

/* setting icon file of health , vest ... */ 

int health_bar[12];
char health_bar_image[12][33] = { "others\\icons\\health_bar000.png", "others\\icons\\health_bar001.png",
"others\\icons\\health_bar002.png", "others\\icons\\health_bar003.png", "others\\icons\\health_bar004.png",
"others\\icons\\health_bar005.png", "others\\icons\\health_bar006.png", "others\\icons\\health_bar007.png",
"others\\icons\\health_bar008.png", "others\\icons\\health_bar009.png", "others\\icons\\health_bar010.png" };

//shield setting
int shield_bar[12]; 
bool active_shield = false ;
int shield_count= 0; 
char shield_bar_image[12][33] = { "others\\icons\\shield_bar000.png", "others\\icons\\shield_bar001.png",
"others\\icons\\shield_bar002.png", "others\\icons\\shield_bar003.png", "others\\icons\\shield_bar004.png",
"others\\icons\\shield_bar005.png", "others\\icons\\shield_bar006.png", "others\\icons\\shield_bar007.png",
"others\\icons\\shield_bar008.png", "others\\icons\\shield_bar009.png", "others\\icons\\shield_bar010.png" };

// power bar 
int power_bar[5];

int score_kill[5];
int kill_index = 0;

//custom number 

int digit_x, digit_y;
int digit[6];
int digit_image[11];
char digit_image_location[11][23] = { "others\\numbers\\0.png", "others\\numbers\\1.png",
"others\\numbers\\2.png", "others\\numbers\\3.png", "others\\numbers\\4.png",
"others\\numbers\\5.png", "others\\numbers\\6.png", "others\\numbers\\7.png",
"others\\numbers\\8.png", "others\\numbers\\9.png" };
//collusion -atack 
int fire_image[21];
int fire_index = 0;

int explosion_x;
int explosion_y;

bool explosion = false;
bool exploded1 = false;
bool exploded2 = false;
bool exploded3 = false;
bool exploded4 = false;
bool exploded5 = false;
bool exploded6 = false;
char fire_image_location[21][40] = { "others\\fire\\fire_001_01.png", "others\\fire\\fire_001_02.png",
"others\\fire\\fire_001_03.png", "others\\fire\\fire_001_04.png", "others\\fire\\fire_001_05.png",
"others\\fire\\fire_001_06.png", "others\\fire\\fire_001_07.png", "others\\fire\\fire_001_08.png",
"others\\fire\\fire_001_09.png", "others\\fire\\fire_001_10.png", "others\\fire\\fire_001_11.png",
"others\\fire\\fire_001_12.png", "others\\fire\\fire_001_13.png", "others\\fire\\fire_001_14.png",
"others\\fire\\fire_001_15.png", "others\\fire\\fire_001_16.png", "others\\fire\\fire_001_17.png",
"others\\fire\\fire_001_18.png", "others\\fire\\fire_001_19.png", "others\\fire\\fire_001_20.png" };


// setting up background 

/* level one */ 
  /* background for level one */ 
  int bg_one0;

int bg_one1[2];
int bg_one1_x[] = { 0, 2512 }, bg_one1_y[] = { 0, 0 };

int bg_one2[2];
int bg_one2_x[] = { 0, 2512 }, bg_one2_y[] = { 0, 0 };

int bg_one3[2];
int bg_one3_x[] = { 0, 2512 }, bg_one3_y[] = { 0, 0 }; 

// .... 
int level_one ; 
int soldier_distance ;
/* if any extra object added  




*/

// character level_one 

// soldier 
int soldier_idle_index = 0;
char soldier_idle_image[10][40] = { "level_one\\soldier\\Idle_000.png", "level_one\\soldier\\Idle_001.png",
"level_one\\soldier\\Idle_002.png", "level_one\\soldier\\Idle_003.png", "level_one\\soldier\\Idle_004.png",
"level_one\\soldier\\Idle_005.png", "level_one\\soldier\\Idle_006.png", "level_one\\soldier\\Idle_007.png" };

int soldier_idleback_index=0;
char soldier_idleback_image[10][40]= { "level_one\\soldier\\IdleBack_000.png", "level_one\\soldier\\IdleBack_001.png",
"level_one\\soldier\\IdleBack_002.png", "level_one\\soldier\\IdleBack_003.png", "level_one\\soldier\\IdleBack_004.png",
"level_one\\soldier\\IdleBack_005.png", "level_one\\soldier\\IdleBack_006.png", "level_one\\soldier\\IdleBack_007.png" };

int soldier_attack_index=0; 
int soldier_attackback_index=0; 

char soldier_attack_image[8][50] = { "level_one\\soldier\\Attack_000.png", "level_one\\soldier\\Attack_001.png",
"level_one\\soldier\\Attack_002.png", "level_one\\soldier\\Attack_003.png", "level_one\\soldier\\Attack_004.png",
"level_one\\soldier\\Attack_005.png"};

char soldier_attackback_image[8][50] = { "level_one\\soldier\\AttackBack_000.png", "level_one\\soldier\\AttackBack_001.png",
"level_one\\soldier\\AttackBack_002.png", "level_one\\soldier\\AttackBack_003.png", "level_one\\soldier\\AttackBack_004.png",
"level_one\\soldier\\AttackBack_005.png" };

char soldier_jumping_image[8][50] = { "level_one\\soldier\\Jump_000.png", "level_one\\soldier\\Jump_001.png",
"level_one\\soldier\\Jump_002.png", "level_one\\soldier\\Jump_003.png", "level_one\\soldier\\Jump_004.png",
"level_one\\soldier\\Jump_005.png", "level_one\\soldier\\Jump_006.png", "level_one\\soldier\\Jump_007.png" };

char soldier_jumpingback_image[8][50] = { "level_one\\soldier\\JumpBack_000.png", "level_one\\soldier\\JumpBack_001.png",
"level_one\\soldier\\JumpBack_002.png", "level_one\\soldier\\JumpBack_003.png", "level_one\\soldier\\JumpBack_004.png",
"level_one\\soldier\\JumpBack_005.png", "level_one\\soldier\\JumpBack_006.png", "level_one\\soldier\\JumpBack_007.png" };

int soldier_jumping_index = 0;

// ... 
#define JUMPLIMIT 130
bool jumping = false ; 
bool jump= false ;
int jumping_height= 0; 


// fireing 

bool fire = false;
int bullet_image;
int bullet_back_image;
int bullet_x = soldier.x + 90;
int bullet_back_x = soldier.x;

// enemy section 

int enemy_image ;

char enemy1_image_location[][50] = { "level_one\\enemy\\police_3\\Attack_000.png", "level_one\\enemy\\police_3\\Attack_001.png", "level_one\\enemy\\police_3\\Attack_002.png",
"level_one\\enemy\\police_3\\Attack_003.png", "level_one\\enemy\\police_3\\Attack_004.png", "level_one\\enemy\\police_3\\Attack_005.png", "level_one\\enemy\\police_3\\Attack_006.png",
"level_one\\enemy\\police_3\\Attack_007.png", "level_one\\enemy\\police_3\\Attack_008.png" ,"level_one\\enemy\\police_3\\Attack_009.png"};

char enemy2_image_location[][50] = { "level_one\\enemy\\police_3\\Attack_000.png", "level_one\\enemy\\police_3\\Attack_001.png", "level_one\\enemy\\police_3\\Attack_002.png",
"level_one\\enemy\\police_3\\Attack_003.png", "level_one\\enemy\\police_3\\Attack_004.png", "level_one\\enemy\\police_3\\Attack_005.png", "level_one\\enemy\\police_3\\Attack_006.png",
"level_one\\enemy\\police_3\\Attack_007.png", "level_one\\enemy\\police_3\\Attack_008.png" ,"level_one\\enemy\\police_3\\Attack_009.png"};


char enemy3_image_location[][50] = { "level_one\\enemy\\police_3\\Attack_000.png", "level_one\\enemy\\police_3\\Attack_001.png", "level_one\\enemy\\police_3\\Attack_002.png",
"level_one\\enemy\\police_3\\Attack_003.png", "level_one\\enemy\\police_3\\Attack_004.png", "level_one\\enemy\\police_3\\Attack_005.png", "level_one\\enemy\\police_3\\Attack_006.png",
"level_one\\enemy\\police_3\\Attack_007.png", "level_one\\enemy\\police_3\\Attack_008.png" ,"level_one\\enemy\\police_3\\Attack_009.png"};


// bomb set 
int bomb_image;
int bomb_x = 1620;
int bomb_random = 3;
bool bomb_state = false;

// setting up background for level two 
int bg_two0;

int bg_two1[2];
int bg_two1_x[] = { 0, 2512 }, bg_two1_y[] = { 0, 0 };

int bg_two2[2];
int bg_two2_x[] = { 0, 2512 }, bg_two2_y[] = { 0, 0 };

int bg_two3[2];
int bg_two3_x[] = { 0, 2512 }, bg_two3_y[] = { 0, 0 };

// soldier on plane 

char soldier_plane_image[9][50] = { "level_two\\soldier\\plane_0000.png", "level_two\\soldier\\plane_0001.png", "level_two\\soldier\\plane_0002.png",
"level_two\\soldier\\plane_0003.png", "level_two\\soldier\\plane_0004.png", "level_two\\soldier\\plane_0005.png", "level_two\\soldier\\plane_0006.png",
"level_two\\soldier\\plane_0006.png", "level_two\\soldier\\plane_0007.png" };

int soldier_plane_index = 0;
int plane_direction = 0;

int enemy_image_level2;

int antibullet1_x;
int antibullet2_x;
int antibullet3_x;

bool hit1,hit2,hit3; 

bool crash1, crash2, crash3;

// game over 
bool game_over=false;
int game_over_image[3] ;
int game_over_index=3; 

int bullet_y;

int game_over_highlight_index = 3;
int game_over_highlight_image[4];

int soldier_rank = 0;
int star_image[6];
int star_index;


bool field_active = false;
int name_index = 0; 
//pause resume 
bool pause = false;
int pause_screen;

// screen on interval 

int screen;
int plane[3];
int show_plane=0;
int finish ; 
bool plane_taken =false ; 

int antifire ;
// 
int icon[2];
int icon_index = 0;

int welcome;
bool fall;


#endif 
