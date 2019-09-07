#pragma once
#include "screen.h"
#include "gameobject.h"
#include <math.h>

int destroy_enemy;
int draw_boss;

void Renderer_initialize();
void Renderer_Render();
void Renderer_destroy();
void draw_image();
void render_ingame();
void render_title();