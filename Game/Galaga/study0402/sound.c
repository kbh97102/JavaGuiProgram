#include "sound.h"


void load_soundFile() {
	wDeviceID = 0;
	sound1_id = 1; //0부터아님 1부터
	sound2_id = 2;
	sound1_stat = get_sound(L".\\sound\\boss1.mp3");
	//sound1_stat = mciSendCommand(sound1_id, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&Sound_Play);
	sound2_stat = get_sound(L".\\sound\\boss2.mp3");
	//sound2_stat = mciSendCommand(sound1_id, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&Sound_Play);
}

DWORD get_sound(LPCTSTR path){
	DWORD Result;
	Sound_Open.lpstrDeviceType = L"MPEGVideo";
	Sound_Open.lpstrElementName = path;
	Result = mciSendCommand(wDeviceID, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&Sound_Open);
	if (Result)
		return Result;
	wDeviceID = Sound_Open.wDeviceID;
	Sound_Play.dwCallback = (DWORD)window;
	if (Result)
		return Result;
	return 0;
}

void sound_play(int sound_index) {
	if (sound_index == sound1_id) {
		sound1_stat = mciSendCommand(sound_index, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&Sound_Play);
	}
	if (sound_index == sound2_id) {
		sound2_stat = mciSendCommand(sound_index, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&Sound_Play);
	}
}
void sound_pause(int sound_index) {
	if (sound_index == sound1_id) {
		sound1_stat = mciSendCommand(sound_index, MCI_PAUSE, MCI_NOTIFY, (DWORD)(LPVOID)&Sound_Play);
	}
	if (sound_index == sound2_id) {
		sound2_stat = mciSendCommand(sound_index, MCI_PAUSE, MCI_NOTIFY, (DWORD)(LPVOID)&Sound_Play);
	}
}