#include "timer.h"  //timer ������ ������ long ���ڰ� ����

long timer_array[SIZE];

long get_current_time() {
	return clock();
}

void set_time_stamp(int index_position) {
	timer_array[index_position] = get_current_time();
}

long get_delta_time(int index_position) {  //set_time_stamp���� ���� �������� ����ð� ��
	return get_current_time() - timer_array[index_position];
}
