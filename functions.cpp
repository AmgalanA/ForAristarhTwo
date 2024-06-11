#include "functions.h"
int start_speed(int previous, int countinious) {
	int speed;
	if (countinious > previous) {
		speed = 300;
	}
	else {
		speed = -300;
	}
	return speed;
}

