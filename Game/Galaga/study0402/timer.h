#include <time.h>
#include "updater.h"

#define LastRenderTime 1
#define LastUpdateTime 2
#define LastIngameTime 3
#define SIZE 10


long get_current_time();

void set_time_stamp(int position); //�������ð����

long get_delta_time(int position);

