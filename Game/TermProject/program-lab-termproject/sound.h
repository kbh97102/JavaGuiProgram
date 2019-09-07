#pragma once
#pragma comment(lib,"winmm.lib")
#include "etc.h"
#include <Mmsystem.h>

#define BackgrondMusic 0
#define Effect_gameOver 1
#define Effect_gameWin 2
#define Title_Bgm 3
MCI_OPEN_PARMS sound_open;
MCI_OPEN_PARMS sound_open2;
MCI_OPEN_PARMS sound_open3;
MCI_OPEN_PARMS sound_open4;

int soundfile[4];

void load_soundfile();

void play_backgrondMusic();
void pause_backgrondMusic();
void stop_backgrondMusic();

void play_effect_gameOver();
void play_effect_gameWin();

void stop_effect_gameOver();
void stop_effect_gameWin();

void play_titleSound();
void stop_titleSound();