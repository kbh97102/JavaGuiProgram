#pragma once
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>


// 색상 정의 
#define BLACK 0
#define BLUE1 1
#define GREEN1 2
#define CYAN1 3
#define RED1 4
#define MAGENTA1 5
#define YELLOW 16
#define GRAY1 7
#define GRAY2 8
#define BLUE2 9
#define GREEN2 10
#define CYAN2 11
#define RED2 12
#define MAGENTA2 13
#define YELLOW2 14
#define WHITE 15


#define Scr_width 60
#define Scr_height 50
#define Scr_x1 0
#define Scr_y1 0
#define Scr_x2 100  //수정
#define Scr_y2 100 //수정


typedef struct User {
	int life;
	double xpos;
	double ypos;
	int dmg;
	int invinc_time;
}User;
typedef struct Boss {
	int life;
	double xpos;
	double ypos;
	int dmg;
	int fire_term;
	int current_term;
}Boss;

User user1;
Boss boss1;
int is_running;
long now;
long uptime;
char * scr_shape;

void removeCursor(void);
void gotoxy(int x, int y);
void textcolor(int fg_color, int bg_color);
void cls(int bg_color, int text_color);
void draw_box(int x1, int y1, int x2, int y2, char *ch);

