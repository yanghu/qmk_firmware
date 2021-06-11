
#include_next <board.h>

#ifdef STM32_HSECLK
#    undef STM32_HSECLK
#endif
#define STM32_HSECLK 8000000U
