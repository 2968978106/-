#include "driver/mcpwm.h"

void setup() {
  //选用MCPWM_UNIT_0来初始化gpio口
  mcpwm_gpio_init(MCPWM_UNIT_0,MCPWM0A,26);//配置A管脚-26
  mcpwm_gpio_init(MCPWM_UNIT_0,MCPWM0B,27);//配置B管脚-27
  //通过mcpwm_config_t结构体为定时器设置频率和初始值
  mcpwm_config_t motor_pwm_config = {
    motor_pwm_config.frequency = 1000,//频率
    motor_pwm_config.cmpr_a = 0,//A的占空比--%
    motor_pwm_config.cmpr_b = 0,//B的占空比--%
    motor_pwm_config.duty_mode = MCPWM_DUTY_MODE_0,//占空比计算模式（高电平）
    motor_pwm_config.counter_mode = MCPWM_UP_COUNTER,//计数器模式（上位计数）
  };
  //使用以上设置配置PWM0A和PWM0B
  mcpwm_init(MCPWM_UNIT_0,MCPWM_TIMER_0,&motor_pwm_config);
}

void loop() {
  //PWM
  mcpwm_set_duty(MCPWM_UNIT_0,MCPWM_TIMER_0,MCPWM_OPR_B,100);//B的占空比为百分之百
  mcpwm_set_duty(MCPWM_UNIT_0,MCPWM_TIMER_0,MCPWM_OPR_A,0);//A的占空比为0
  mcpwm_start(MCPWM_UNIT_0,MCPWM_TIMER_0);
  delay(3000);//全速前进
  mcpwm_stop(MCPWM_UNIT_0,MCPWM_TIMER_0);//停止输出
  mcpwm_set_duty(MCPWM_UNIT_0,MCPWM_TIMER_0,MCPWM_OPR_A,100);
  mcpwm_set_duty(MCPWM_UNIT_0,MCPWM_TIMER_0,MCPWM_OPR_B,0);
  mcpwm_start(MCPWM_UNIT_0,MCPWM_TIMER_0);
  delay(3000);
}
