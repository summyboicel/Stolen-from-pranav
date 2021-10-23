#include "../include/main.h"
#include  "../include/autonomous.h"




void leftBtn(){

}
void centerBtn(){

}
void rightBtn(){

}
void initialize() {
	pros::lcd::initialize();

	pros::lcd::register_btn0_cb(leftBtn);
	pros::lcd::register_btn1_cb(centerBtn);
	pros::lcd::register_btn2_cb(rightBtn);
	Clamp.set_brake_mode(MOTOR_BRAKE_HOLD);
  autonSelector();

	//autonSelector();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
  switch(selected){
     case 0:
		 	disabledAuton();
     case 1:
		 	pop();
     case 2:

     case 3:

     case 4:

     case 5:

     case 6:

     case 7:

		 case 8:
     	skills();
   }
}

const int NUM_HEIGHTS = 3;
const int height1 = 0;
const int height2 = 700;
const int height3 = 1500;


const int heights[NUM_HEIGHTS] = {height1, height2,height3};
const int heights2[NUM_HEIGHTS] = {0, 700,1800};


void opcontrol() {
	Clamp.tare_position();
  int goalHeight = 0;
  while (true){
		double power = control.get_analog(ANALOG_LEFT_Y);
		double turn = control.get_analog(ANALOG_LEFT_X);
		driverControl(2*power+turn, 2*power-turn);
		if (up.changedToPressed()){
			Clamp.move_absolute(800, 100);
		}
		if (down.changedToPressed()){
			Clamp.move_absolute(0, 100);
		}
    if (RUp.changedToPressed() && goalHeight < NUM_HEIGHTS - 1) {
      goalHeight++;
      liftControl->setTarget(heights[goalHeight]);
    } else if (RDown.changedToPressed() && goalHeight > 0) {
      goalHeight--;
      liftControl->setTarget(heights[goalHeight]);
    }
		if (LUp.changedToPressed() && goalHeight < NUM_HEIGHTS - 1) {
      goalHeight++;
      fourbar->setTarget(heights2[goalHeight]);
    } else if (LDown.changedToPressed() && goalHeight > 0) {
      goalHeight--;
      fourbar->setTarget(heights2[goalHeight]);
    }
    pros::delay(20);
  }
}
