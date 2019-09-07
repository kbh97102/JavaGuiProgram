#pragma once
#include "etc.h"
#include "game.h"

#define VK_W 'W'
#define VK_A 'A'
#define VK_S 'S'
#define VK_D 'D'
#define VK_P 'P'
#define VK_O 'O'
#define VK_J 0x4A
#define VK_X 'X'
#define VK_C 'C'
#define VK_V 'V'

#define Key_Num 255


#define w 0
#define a 1
#define s 2
#define d 3
#define j 4
enum key_stat {
	nonpress,
	press,
	hold,
	unpress
};

enum key_stat key_set[Key_Num];
enum key_stat get_keystat(int key_cord);

void get_keyinput();
