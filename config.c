#include "config.h"

Timer_A_ContinuousModeConfig mainLoopTimerConfig = {
        TIMER_A_CLOCKSOURCE_ACLK,           // ACLK Clock Source
        TIMER_A_CLOCKSOURCE_DIVIDER_1,      // ACLK/1 = 32.768khz
        TIMER_A_TAIE_INTERRUPT_ENABLE,      // Enable Overflow ISR
        TIMER_A_DO_CLEAR,                   // Clear Counter
};

Timer_A_UpModeConfig servoTimerPWMConfig = {
       TIMER_A_CLOCKSOURCE_SMCLK,              // SMCLK = 3 MhZ
       TIMER_A_CLOCKSOURCE_DIVIDER_12,         // SMCLK/12 = 250 KhZ
       20000,                                  // 40 ms tick period
       TIMER_A_TAIE_INTERRUPT_DISABLE,         // Disable Timer interrupt
       TIMER_A_CCIE_CCR0_INTERRUPT_DISABLE,    // Disable CCR0 interrupt
       TIMER_A_DO_CLEAR                        // Clear value
};
