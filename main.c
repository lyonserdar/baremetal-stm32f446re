#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning                                                                       \
    "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "main.h"
#include "stm32f446re.h"
#include "stm32f446re_gpio.h"
#include <stdio.h>

// semihosting init function
extern void initialise_monitor_handles(void);

int main(void) {

  initialise_monitor_handles();

  printf("Project compiled successfully\n");

  while (1)
    ;
}
