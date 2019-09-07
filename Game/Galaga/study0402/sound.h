#pragma once
#include "gameobject.h"
#pragma comment(lib,"winmm.lib") 

//변수
MCI_OPEN_PARMS Sound_Open;
MCI_PLAY_PARMS Sound_Play;
MCI_STATUS_PARMS Sound_Status;
UINT wDeviceID;

DWORD sound1_stat;
DWORD sound2_stat;
int sound1_id;
int sound2_id;

//함수
void load_soundFile(); //노래 전체를 가져옴
DWORD get_sound(LPCTSTR path);


void sound_play(int sound_index);
void sound_pause(int sound_index);
