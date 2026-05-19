#ifndef TYPES_H
#define TYPES_H

// All other struct headers are included in struct.h for convenience
// (since all structs must be defined before function definitions in the code).
// When adding a new file in struct/, make sure to includle it here too.
// The order matters tho, so make sure not to include a struct file that
// depends on one introduced after it or it won't compile.

#include "struct/math.h"
#include "struct/player.h"
#include "struct/class.h"

#endif

