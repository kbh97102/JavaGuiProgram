#include "keyboard.h"

void get_keyinput() {
	if (GetAsyncKeyState(VK_W) & 0X8000) {
		if (key_set[w] == nonpress)
			key_set[w] = press;
		else if (key_set[w] == press)
			key_set[w] = hold;
	}
	else if (!GetAsyncKeyState(VK_W)) {
		if (key_set[w] == press || key_set[w] == hold) {
			key_set[w] = unpress;
		}
		else if (key_set[w] == unpress) {
			key_set[w] = nonpress;
		}
	}
	if (GetAsyncKeyState(VK_A) & 0X8000) {
		if (key_set[a] == nonpress)
			key_set[a] = press;
		else if (key_set[a] == press)
			key_set[a] = hold;
	}
	else if (!GetAsyncKeyState(VK_A)) {
		if (key_set[a] == press || key_set[a] == hold) {
			key_set[a] = unpress;
		}
		else if (key_set[a] == unpress) {
			key_set[a] = nonpress;
		}
	}
	if (GetAsyncKeyState(VK_S) & 0X8000) {
		if (key_set[s] == nonpress)
			key_set[s] = press;
		else if (key_set[s] == press)
			key_set[s] = hold;
	}
	else if (!GetAsyncKeyState(VK_S)) {
		if (key_set[s] == press || key_set[s] == hold) {
			key_set[s] = unpress;
		}
		else if (key_set[s] == unpress) {
			key_set[s] = nonpress;
		}
	}
	if (GetAsyncKeyState(VK_D) & 0X8000) {
		if (key_set[d] == nonpress)
			key_set[d] = press;
		else if (key_set[d] == press)
			key_set[d] = hold;
	}
	else if (!GetAsyncKeyState(VK_D)) {
		if (key_set[d] == press || key_set[d] == hold) {
			key_set[d] = unpress;
		}
		else if (key_set[d] == unpress) {
			key_set[d] = nonpress;
		}
	}
	if (GetAsyncKeyState(VK_J) & 0X8000) {
		if (key_set[j] == nonpress)
			key_set[j] = press;
		else if (key_set[j] == press)
			key_set[j] = hold;
	}
	else if (!GetAsyncKeyState(VK_J)) {
		if (key_set[j] == press || key_set[j] == hold) {
			key_set[j] = unpress;
		}
		else if (key_set[j] == unpress) {
			key_set[j] = nonpress;
		}
	}
}

enum key_stat get_keystat(int key_cord) {
	return key_set[key_cord];
}








