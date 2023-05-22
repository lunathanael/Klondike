#ifndef SEARCH_H
#define SEARCH_H

#include "types.h"


bool Move_hint(TABLE* gamestate, bool output=true);
bool Search_helper_function(TABLE* gamestate, bool output=false);






#endif