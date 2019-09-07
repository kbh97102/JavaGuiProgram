#pragma once
#include "gameobject.h"
#pragma comment(lib,"winmm.lib") 

//����
MCI_OPEN_PARMS Sound_Open;
MCI_PLAY_PARMS Sound_Play;
MCI_STATUS_PARMS Sound_Status;
UINT wDeviceID;

DWORD sound1_stat;
DWORD sound2_stat;
int sound1_id;
int sound2_id;

//�Լ�
void load_soundFile(); //�뷡 ��ü�� ������
DWORD get_sound(LPCTSTR path);


void sound_play(int sound_index);
void sound_pause(int sound_index);
