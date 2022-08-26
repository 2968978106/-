const int motorA = 26;//正转
const int motorB = 27;//反转
//pwm
const int freq = 2000;
const int resolution = 8;
const int motor_channel_A = 0;
const int motor_channel_B = 1;
const int duty_cycle = 255;
void setup() {
  ledcSetup(motor_channel_B,freq,resolution);
  ledcAttachPin(motorB,motor_channel_B);
  ledcSetup(motor_channel_A,freq,resolution);
  ledcAttachPin(motorA,motor_channel_A);
}

void loop() {
  for (int i=0;i<=255;i=i+5){
    ledcWrite(motor_channel_B,i);
    ledcWrite(motor_channel_A,0);
    delay(50);
    }
  ledcWrite(motor_channel_B,duty_cycle);
  delay(5000);
  for (int i=255;i>=0;i=i-5){
    ledcWrite(motor_channel_B,i);
    ledcWrite(motor_channel_A,0);
    delay(50);
    }
   ledcWrite(motor_channel_A,duty_cycle);
   ledcWrite(motor_channel_B,duty_cycle);
   delay(3000);
  for (int i=0;i<=255;i=i+5){
    ledcWrite(motor_channel_A,i);
    ledcWrite(motor_channel_B,0);
    delay(50);
    }
  ledcWrite(motor_channel_A,duty_cycle);
  delay(5000);
  for (int i=255;i>=0;i=i-5){
    ledcWrite(motor_channel_A,i);
    ledcWrite(motor_channel_B,0);
    delay(50);
    }
   ledcWrite(motor_channel_A,duty_cycle);
   ledcWrite(motor_channel_B,duty_cycle);
   delay(3000);   
}
