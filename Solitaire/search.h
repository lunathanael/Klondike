#ifndef SEARCH_H
#define SEARCH_H

#include "types.h"


bool Move_hint(GAMESTATE * gamestate, bool output=true);
bool Search_helper_function(GAMESTATE* gamestate, bool output=false);






#endif