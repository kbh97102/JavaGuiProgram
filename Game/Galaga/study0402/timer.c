#include "timer.h"  //timer 관련은 무조건 long 인자값 제외

long timer_array[SIZE];

long get_current_time() {
	return clock();
}

void set_time_stamp(int index_position) {
	timer_array[index_position] = get_current_time();
}

long get_delta_time(int index_position) {  //set_time_stamp에서 찍은 시작점과 현재시간 비교
	return get_current_time() - timer_array[index_position];
}
