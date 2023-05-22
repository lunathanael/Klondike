#ifndef INIT_H
#define INIT_H

#include "types.h"

#include <random>
#include <ctime>
#include <algorithm>


extern const void Init_all() {
	//random_seed = time(NULL);
	srand(unsigned(time(NULL)));
	return;
}




#endif

