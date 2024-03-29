#ifndef CONFIG_H
#define CONFIG_H

#include "msp.h"
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

#define CART_A_DX_IN1 GPIO_PORT_P2, GPIO_PIN4
#define CART_A_DX_IN2 GPIO_PORT_P5, GPIO_PIN6
#define CART_A_DX_IN3 GPIO_PORT_P6, GPIO_PIN6
#define CART_A_DX_IN4 GPIO_PORT_P6, GPIO_PIN7

#define CART_A_SX_IN1 GPIO_PORT_P6, GPIO_PIN4
#define CART_A_SX_IN2 GPIO_PORT_P6, GPIO_PIN5
#define CART_A_SX_IN3 GPIO_PORT_P4, GPIO_PIN6
#define CART_A_SX_IN4 GPIO_PORT_P1, GPIO_PIN5

#define CART_B_DX_IN1 GPIO_PORT_P5, GPIO_PIN5
#define CART_B_DX_IN2 GPIO_PORT_P5, GPIO_PIN4
#define CART_B_DX_IN3 GPIO_PORT_P4, GPIO_PIN7
#define CART_B_DX_IN4 GPIO_PORT_P4, GPIO_PIN5

#define CART_B_SX_IN1 GPIO_PORT_P2, GPIO_PIN3
#define CART_B_SX_IN2 GPIO_PORT_P5, GPIO_PIN1
#define CART_B_SX_IN3 GPIO_PORT_P3, GPIO_PIN5
#define CART_B_SX_IN4 GPIO_PORT_P3, GPIO_PIN7

#define WHINCH_IN1 GPIO_PORT_P1, GPIO_PIN7
#define WHINCH_IN2 GPIO_PORT_P5, GPIO_PIN0
#define WHINCH_IN3 GPIO_PORT_P5, GPIO_PIN2
#define WHINCH_IN4 GPIO_PORT_P3, GPIO_PIN6

#define SERVO_MAX_POSITION 480
#define SERVO_MIN_POSITION 200

#define SERVO_MAX_SPEED_DELAY 2
#define SERVO_MIN_SPEED_DELAY 32

extern Timer_A_ContinuousModeConfig mainLoopTimerConfig;
extern Timer_A_UpModeConfig servoTimerPWMConfig;

#endif
