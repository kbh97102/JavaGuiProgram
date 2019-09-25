#include <stdio.h>

#define m 10

void main() {
	char test[m];
	int c = 0;

	for (int i = 0; i < m; i++) {
		if (test[i] == 'l') {
			c++;
		}
	}
}