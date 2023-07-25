
#include <AccelStepper.h>

#define stepPin 2 //Passo eixo X
#define dirPin 5 // Direção eixo X
#define stepMotor 3 //Passo eixo Y
#define dirMotor 6

// Define some steppers and the pins the will use
AccelStepper stepper1(AccelStepper::DRIVER, stepPin, dirPin);
AccelStepper stepper2(AccelStepper::DRIVER, stepMotor, dirMotor);

void setup()
{  
    stepper1.setMaxSpeed(4000.0);
    stepper1.setAcceleration(4000.0);
    stepper1.moveTo(4000);
    
    stepper2.setMaxSpeed(100.0);
    stepper2.setAcceleration(100.0);
    stepper2.moveTo(100);
}

void loop()
{
    // Change direction at the limits
    if (stepper1.distanceToGo() == 0)
  stepper1.moveTo(-stepper1.currentPosition());
    if (stepper2.distanceToGo() == 0)
  stepper2.moveTo(-stepper2.currentPosition());
    stepper1.run();
    stepper2.run();
}
