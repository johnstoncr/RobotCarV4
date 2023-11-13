#define PWMA 5    // Controls power to right motor
#define PWMB 6    // Controls power to left motor
#define AIN 7     // Controls direction of right motor, HIGH = FORWARD, LOW = REVERSE
#define BIN 8     // Controls direction of right motor, HIGH = FORWARD, LOW = REVERSE
#define STBY 3    // Place Motors in standby if LOW, Run if HIGH

float distance; 
int degRot; 
int leftSpeed, rightSpeed;

void setup() { 
  // put your setup code here, to run once: 
  Serial.begin(9600); 
pinMode (STBY,OUTPUT);
pinMode (PWMA,OUTPUT);
pinMode (PWMB,OUTPUT);
pinMode (AIN,OUTPUT);
pinMode (BIN,OUTPUT);
digitalWrite(STBY,LOW);  // put it in Standby Mode
} 

void loop() {
  leftSpeed = 155;
  rightSpeed = 155; 
  setSpeed(leftSpeed, rightSpeed);

  forward(10);

  while(1==1){
    
  }
}

void setSpeed(int leftVal, int rightVal){
  analogWrite(PWMA, leftVal);
  analogWrite(PWMB, rightVal);
}

void forward(float distance){ 
  float time; 
  digitalWrite(AIN,HIGH);
  digitalWrite(BIN,HIGH);
  time=distance/2.45*1000;  //after calibration the car travelled 12ft 3 inches in 5 seconds
  
  digitalWrite(STBY,HIGH); 
  delay(time);  // move for "time" seconds 
  stopCar(); 
}

void backward(float distance){ 
  float time; 
//  digitalWrite(STBY,LOW);
  analogWrite(PWMA,255);
  analogWrite(PWMB,255);
  digitalWrite(AIN,LOW);
  digitalWrite(BIN,LOW);
  time=distance/2.45*1000; 
  digitalWrite(STBY,HIGH);
  delay(time); 
  stopCar(); 
} 

void turnRight(int deg){ 
  float time; 
  //digitalWrite(STBY,LOW);
  analogWrite(PWMA,255);
  analogWrite(PWMB,255);
  digitalWrite(AIN,LOW);
  digitalWrite(BIN,HIGH);        
  time=deg/345.*1000.; //after calibration the robot rotated 1725 degrees in 5 seconds
  Serial.println(deg); 
  digitalWrite(STBY,HIGH);
  delay(time); 
  stopCar(); 
} 
        
void turnLeft(float deg){ 
  float time; 
//  digitalWrite(STBY,LOW);
  analogWrite(PWMA,255);
  analogWrite(PWMB,255);
  digitalWrite(AIN,HIGH);
  digitalWrite(BIN,LOW);          
  time=deg/345.*1000.; 
  Serial.println(deg);
  digitalWrite(STBY,HIGH); 
  delay(time); 
  stopCar(); 
} 

void stopCar(){ 
 digitalWrite(STBY, LOW);
}

//Calibration             } 
void calF(){ 
  analogWrite(PWMA,255);
  analogWrite(PWMB,255);
  digitalWrite(AIN,HIGH);
  digitalWrite(BIN,HIGH);
  digitalWrite(STBY,HIGH);
  delay(5000); 
  stopCar(); 
} 

void calB(){ 
  digitalWrite(PWMA,HIGH);
  digitalWrite(PWMB,HIGH);
  digitalWrite(AIN,LOW);
  digitalWrite(BIN,LOW);
  digitalWrite(STBY,HIGH);
  delay(5000); 
  stopCar(); 
} 

void calR(){ 
  digitalWrite(PWMA,HIGH);
  digitalWrite(PWMB,HIGH);
  digitalWrite(AIN,LOW);
  digitalWrite(BIN,HIGH);
  digitalWrite(STBY,HIGH);        
  delay(5000); 
  stopCar(); 
} 

void calL(){ 
  digitalWrite(PWMA,HIGH);
  digitalWrite(PWMB,HIGH);
  digitalWrite(AIN,HIGH);
  digitalWrite(BIN,LOW);
  digitalWrite(STBY,HIGH);          
  delay(5000); 
  stopCar(); 
}
              