#pragma once
#include "keyboard.h"
#include "gameobject.h"
#include "screen.h"
#include "timer.h"
#include "sound.h"
#include "render.h"

#define SPEED 10
#define SQRT2  1.4142

typedef struct min_max_XY {
	double minX, minY;
	double maxX, maxY;
}min_max_xy;

min_max_xy xy_collection[50];

double xoffset;
double yoffset;
float delta;
long ingame_timer;

void update(long delta_time);
void update_init();

void update_title();
void update_ingame();
void gameplay_init();
int is_collide(int image_index1, int image_index2);
void set_xy_collection();
void ingame_timer_init();
