#include "driver/mcpwm.h"
void setup() {
  //初始化gpio口
  mcpwm_gpio_init(MCPWM_UNIT_1,MCPWM1A,15);//舵机--单元1，15号管脚
  mcpwm_gpio_init(MCPWM_UNIT_0,MCPWM0A,26);//电机A--单元0,26号管脚
  mcpwm_gpio_init(MCPWM_UNIT_0,MCPWM0B,27);//电机B--单元0,27号管脚

  //为舵机对应定时器设置频率和初始值
  mcpwm_config_t servo_pwm_config;
  servo_pwm_config.frequency = 50;
  servo_pwm_config.cmpr_a = 0;
  servo_pwm_config.duty_mode = MCPWM_DUTY_MODE_0;
  servo_pwm_config.counter_mode = MCPWM_UP_COUNTER;

  //为电机对应定时器设置频率和初始值
  mcpwm_config_t motor_pwm_config = {
    motor_pwm_config.frequency = 1000,//频率
    motor_pwm_config.cmpr_a = 0,//A的占空比--%
    motor_pwm_config.cmpr_b = 0,//B的占空比--%
    motor_pwm_config.duty_mode = MCPWM_DUTY_MODE_0,//占空比计算模式（高电平）
    motor_pwm_config.counter_mode = MCPWM_UP_COUNTER,//计数器模式（上位计数）
  };

  //使用以上设置配置PWM1A
  mcpwm_init(MCPWM_UNIT_1,MCPWM_TIMER_1,&servo_pwm_config);
  //使用以上设置配置PWM0A和PWM0B
  mcpwm_init(MCPWM_UNIT_0,MCPWM_TIMER_0,&motor_pwm_config);
}

void loop() {
  //转向加行进
  mcpwm_set_duty(MCPWM_UNIT_1,MCPWM_TIMER_1,MCPWM_OPR_A,7.5);
  delay(1000);
  mcpwm_set_duty(MCPWM_UNIT_0,MCPWM_TIMER_0,MCPWM_OPR_B,100);
  mcpwm_set_duty(MCPWM_UNIT_0,MCPWM_TIMER_0,MCPWM_OPR_A,0);
  delay(3000);
  
  mcpwm_set_duty(MCPWM_UNIT_1,MCPWM_TIMER_1,MCPWM_OPR_A,2.5);
  delay(1000);
  mcpwm_set_duty(MCPWM_UNIT_0,MCPWM_TIMER_0,MCPWM_OPR_B,100);
  mcpwm_set_duty(MCPWM_UNIT_0,MCPWM_TIMER_0,MCPWM_OPR_A,0);
  delay(3000);
  
  mcpwm_set_duty(MCPWM_UNIT_1,MCPWM_TIMER_1,MCPWM_OPR_A,7.5);
  delay(1000);
  mcpwm_set_duty(MCPWM_UNIT_0,MCPWM_TIMER_0,MCPWM_OPR_A,100);
  mcpwm_set_duty(MCPWM_UNIT_0,MCPWM_TIMER_0,MCPWM_OPR_B,0);
  delay(3000);

  mcpwm_set_duty(MCPWM_UNIT_1,MCPWM_TIMER_1,MCPWM_OPR_A,12.5);
  delay(1000);
  mcpwm_set_duty(MCPWM_UNIT_0,MCPWM_TIMER_0,MCPWM_OPR_A,100);
  mcpwm_set_duty(MCPWM_UNIT_0,MCPWM_TIMER_0,MCPWM_OPR_B,0);
  delay(3000);
}
