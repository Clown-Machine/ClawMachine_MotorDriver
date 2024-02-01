#include "claw_machine.h"

ClawMachine_t Claw_INIT(Cart_t cart_a, Cart_t cart_b, Stepper_t whinch) {
    ManualMode_t data = (ManualMode_t){};

    return (ClawMachine_t){
        .cart_a = cart_a,
        .cart_b = cart_b,
        .whinch = whinch,
        .gripper = Servo_INIT(),
        .mode = (Mode_t){
            .tag = MANUAL_MODE,
            .data.manual_mode = data,
        },
    };
}

void Claw_setTargetMode(ClawMachine_t * clawMachine, Position_t position) {
    Claw_setManualMode(clawMachine, 0, 0, 0, 0);

    TargetMode_t data = (TargetMode_t) {
       .target = position
    };

    clawMachine->mode = (Mode_t) {
        .tag = TARGET_MODE,
        .data = data,
    };
}

void Claw_setManualMode(ClawMachine_t * clawMachine, speed_t speed_a, speed_t speed_b, speed_t speed_whinch, speed_t speed_gripper) {
    clawMachine->mode = (Mode_t) {
        .tag = MANUAL_MODE,
        .data = 0
    };

    Cart_setSpeed_Percentage(&clawMachine->cart_a, speed_a);
    Cart_setSpeed_Percentage(&clawMachine->cart_b, speed_b);
    Stepper_setSpeed_Percentage(&clawMachine->whinch, speed_whinch);
    Servo_setSpeed(&clawMachine->gripper, speed_gripper);
}

Position_t Claw_getCurrentPosition(ClawMachine_t * clawMachine) {
    return (Position_t) {
        clawMachine->cart_a.position,
        clawMachine->cart_b.position
    };
}

int Claw_tryMove(ClawMachine_t * clawMachine) {
    if (clawMachine->mode.tag == TARGET_MODE) {
        int res1 = Cart_goTo(&clawMachine->cart_b, clawMachine->mode.data.target_mode.target.x);
        int res2 = Cart_goTo(&clawMachine->cart_a, clawMachine->mode.data.target_mode.target.y);

        return res1 && res2;
    }
    else {
        Cart_tryMove(&clawMachine->cart_a);
        Cart_tryMove(&clawMachine->cart_b);

        Stepper_tryMove(&clawMachine->whinch);
        Servo_tryMove(&clawMachine->gripper);
        return 0; // todo: capire cosa ritornare
    }
}
