#include "keyboard.h"


void init_keyboard(){

}
void key_pollinput() {
	for (int i = 0; i < KEYNUM; i++) {
		if (GetAsyncKeyState(i) & 0x8000) {//어떤 조건 만족시 작동이 될때마다 알려주는 함수
			if (key_set[i] == Nonpress)
				key_set[i] = Press;
			else if (key_set[i] == Press)
				key_set[i] = Hold;
		}
		else if (!GetAsyncKeyState(i)) {
			if (key_set[i] == Press || key_set[i] == Hold)
				key_set[i] = Release;
			else if (key_set[i] == Release)
				key_set[i] = Nonpress;
		}

	}
}
enum key_status get_keystatus(int key_cord) {
	return key_set[key_cord];  //특정 키의 상태 반환
}