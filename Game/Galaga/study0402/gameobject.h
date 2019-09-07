#pragma once

#include <windows.h>
#include <stdlib.h>

#define Title 0
#define Ingame 1
#define Setting 2
#define User 2
#define Boss 3
#define Enemy2 4
#define Background 5

HDC front_dc;
HDC back_dc;
HBITMAP back_buffer;
HWND window;
int gameobject_imagecount;
int image1;
int image2;
int image3;
int image4;
int image5;
int image6;
int isgame_exit;

int next_position_xpos;
int next_position_ypos;

typedef struct image_object {
	HDC img;
	HBITMAP bitmap;
	int width, height;
	double Xposition, Yposition;
}image_object; //이미지


image_object *imageArray[5000];

void gameobject_init(void);
int gameobject_imgload(LPCWSTR path);
void gameobject_destroy();


int current_scene; //미리정의된 값을 넣기, #define title 0 

int image2_right_xpos;
int image3_right_xpos;

//c언어 xxyy 이미지 충돌 검색 
