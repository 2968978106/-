#include "driver/mcpwm.h"
void setup() {
  //选用MCPWM_UNIT_1来初始化gpio口
  mcpwm_gpio_init(MCPWM_UNIT_1,MCPWM1A,15);

  mcpwm_config_t servo_pwm_config;
  servo_pwm_config.frequency = 50;
  servo_pwm_config.cmpr_a = 0;
  servo_pwm_config.duty_mode = MCPWM_DUTY_MODE_0;
  servo_pwm_config.counter_mode = MCPWM_UP_COUNTER;
    
  //使用以上设置配置PWM1A
  mcpwm_init(MCPWM_UNIT_1,MCPWM_TIMER_1,&servo_pwm_config);
}

void loop() {
  mcpwm_set_duty(MCPWM_UNIT_1,MCPWM_TIMER_1,MCPWM_OPR_A,7.5);
  delay(1000);
  mcpwm_set_duty(MCPWM_UNIT_1,MCPWM_TIMER_1,MCPWM_OPR_A,2.5);
  delay(1000);
  mcpwm_set_duty(MCPWM_UNIT_1,MCPWM_TIMER_1,MCPWM_OPR_A,7.5);
  delay(1000);
  mcpwm_set_duty(MCPWM_UNIT_1,MCPWM_TIMER_1,MCPWM_OPR_A,12.5);
  delay(1000);
  mcpwm_set_duty(MCPWM_UNIT_1,MCPWM_TIMER_1,MCPWM_OPR_A,7.5);
  delay(5000);
}
