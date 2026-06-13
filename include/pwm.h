// PWM (Pulse Width Modulation) control module for Rolex Ice watch.
// Controls brightness of LED on pin PB1.

#ifndef ROLEX_ICE_INCLUDE_PWM_H_
#define ROLEX_ICE_INCLUDE_PWM_H_

// Sets PWM value for LED brightness on pin PB1.
// Parameters:
//   pwm_value: PWM duty cycle (0-255, where 255 is maximum brightness).
void SetPwmPb1(int pwm_value);

#endif  // BINARYCLOCK_INCLUDE_PWM_H_