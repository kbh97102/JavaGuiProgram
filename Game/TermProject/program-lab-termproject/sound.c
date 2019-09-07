#include "sound.h"

void load_soundfile() {
	sound_open.lpstrElementName = L".\\sound\\test.mp3";
	sound_open.lpstrDeviceType = L"mpegvideo";
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&sound_open);
	soundfile[BackgrondMusic] = sound_open.wDeviceID;

	sound_open2.lpstrElementName = L".\\sound\\GameOver.mp3";
	sound_open2.lpstrDeviceType = L"mpegvideo";
	mciSendCommand(1, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&sound_open2);
	soundfile[Effect_gameOver] = sound_open2.wDeviceID;

	sound_open3.lpstrElementName = L".\\sound\\GameWin.mp3";
	sound_open3.lpstrDeviceType = L"mpegvideo";
	mciSendCommand(2, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&sound_open3);
	soundfile[Effect_gameWin] = sound_open3.wDeviceID;

	sound_open4.lpstrElementName = L".\\sound\\TitleSound.mp3";
	sound_open4.lpstrDeviceType = L"mpegvideo";
	mciSendCommand(3, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&sound_open4);
	soundfile[Title_Bgm] = sound_open4.wDeviceID;
}

void play_backgrondMusic() {
	mciSendCommand(soundfile[BackgrondMusic], MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&sound_open);
}
void pause_backgrondMusic() {
	mciSendCommand(soundfile[BackgrondMusic], MCI_PAUSE, MCI_NOTIFY, (DWORD)(LPVOID)&sound_open);
}
void stop_backgrondMusic() {
	mciSendCommand(soundfile[BackgrondMusic], MCI_STOP, MCI_NOTIFY, (DWORD)(LPVOID)&sound_open);
	mciSendCommand(soundfile[BackgrondMusic], MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)&sound_open);
}

void play_effect_gameOver() {
	mciSendCommand(soundfile[Effect_gameOver], MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&sound_open2);
}
void stop_effect_gameOver() {
	mciSendCommand(soundfile[Effect_gameOver], MCI_STOP, MCI_NOTIFY, (DWORD)(LPVOID)&sound_open2);
	mciSendCommand(soundfile[Effect_gameOver], MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)&sound_open2);
}

void play_effect_gameWin() {
	mciSendCommand(soundfile[Effect_gameWin], MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&sound_open3);
}
void stop_effect_gameWin() {
	mciSendCommand(soundfile[Effect_gameWin], MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&sound_open3);
	mciSendCommand(soundfile[Effect_gameWin], MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)&sound_open3);
}

void play_titleSound(){
	mciSendCommand(soundfile[Title_Bgm], MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&sound_open4);
}
void stop_titleSound(){
	mciSendCommand(soundfile[Title_Bgm], MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&sound_open4);
	mciSendCommand(soundfile[Title_Bgm], MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)&sound_open4);
}