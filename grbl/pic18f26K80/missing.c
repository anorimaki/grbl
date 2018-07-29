#include "missing.h"
#include <math.h>


int32_t lround( float x )
{
#if 0
  return (x<0.0) ? x-0.5 : x+0.5;
#else
  return (int32_t)round(x);
#endif
}

