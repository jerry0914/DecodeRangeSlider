void min_limiter_state_changed(){
  if(digitalRead(MIN_LIMITER_PIN)==LOW){
    control_state |= STATE_MIN_LIMITER;
  }
  else{
    control_state &= ~STATE_MIN_LIMITER;
  }  
}

void max_limiter_state_changed(){
  if(digitalRead(MAX_LIMITER_PIN)==LOW){
    control_state |= STATE_MAX_LIMITER;
    //Serial.println("Maximum limiter is hitted!!");
  }
  else{
    control_state &= ~STATE_MAX_LIMITER;
     //Serial.println("Maximum limiter is released!!");
  }
}

void setup() {
  //put your setup code here, to run once:
  Serial.begin(9600);
  delay(5);
  min_limiter_state_changed();// Initialize minimum limiter state
  max_limiter_state_changed();// Initialize maximum limiter state
  attachInterrupt(MIN_LIMITER_PIN, min_limiter_state_changed, CHANGE);
  attachInterrupt(MAX_LIMITER_PIN, max_limiter_state_changed, CHANGE);
  wifi_connect();
  wifi_server_init();
  motor_init();
}

