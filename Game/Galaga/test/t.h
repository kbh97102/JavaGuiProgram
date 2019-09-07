#pragma once

#include <windows.h>
#include <stdlib.h>

#define scr_width 540
#define scr_height 960

#define SPEED 1
#define Square_Root_2  1.4142 / 2

HDC front_dc;
HDC back_dc;
HBITMAP back_buffer;
HWND window;
int gameobject_imagecount;
int image1;
int isgame_exit;


typedef struct image_object {
	HDC img;
	HBITMAP bitmap;
	int width, height;
	double Xposition, Yposition;
}image_object; //¿ÃπÃ¡ˆ

//typedef struct bullet {
//	int enemy_bullet_index_imagearray;
//	double bullet_xpos, bullet_ypos;
//}enemy_bullet;
//typedef struct bullet {
//	int my_bullet_index_imagearray;
//	double bullet_xpos, bullet_ypos;
//}my_bullet;
typedef struct user {
	int user_index_imagearray;
	int life;
	double user_xpos, user_ypos;
}user_stat;
typedef struct enemy {
	int enemy_index_imagearray;
	int life;
	double enemy_xpos, enemy_ypos;
}enemy_stat;

#define num_enemy 5

user_stat user1;
enemy_stat enemy[num_enemy];

void user_init();
void enemy_init();

image_object *imageArray[5000];

void gameobject_init(void);
int gameobject_imgload(LPCWSTR path);
void gameobject_destroy();
