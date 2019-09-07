#pragma once
#include "etc.h"
#include "keyboard.h"
#include "title.h"
#include "sound.h"

#define Sqrt2 1.14142

#define User 0 
#define Boss 1
#define Item_dmg 2
#define User_bullet 3
#define Boss_bullet 8

#define Max_bullet 5

#define Win 1
#define Lost 2

#define Init_boss_life 300
#define Init_boss_dmg 10
#define Init_user_life 30
#define Init_user_dmg 5
#define User_Speed 0.5

typedef struct xy_collect {
	double minX;
	double minY;
	double maxX;
	double maxY;
}xy_collect;

typedef struct bullet {
	double bullet_xpos;
	double bullet_ypos;
	BOOL is_exist;
}bullet;

typedef struct dmgup {
	double xpos;
	double ypos;
	BOOL is_exist;
}dmgup;

dmgup item_dmgup;
bullet user_bullet[Max_bullet];
bullet boss_bullet[Max_bullet];
xy_collect xy_gather[20];

double user_bullet_yoffset;
double boss_bullet_yoffset;
double xoffset;
double yoffset;
double boss_xoffset;
long now;
long current_invincTime;
long change_color;
long startTime;
long start_deltaTime;
void update_init();
void set_xy();
BOOL is_colide(int index1, int index2);

void moving();
void draw_user();
void draw_boss();
void erase_boss();
void erase_user();
void move_pattern_boss();

void draw_boss_bullet(int index);
void erase_boss_bullet(int index);
void draw_user_bullet(int index);
void erase_user_bullet(int index);
void draw_dmgup();
void erase_dmgup();

void Ingame();
void check_game();
void object_init();