#include<SoftwareSerial.h>
char t;

/* Create object named bt of the class SoftwareSerial */ 
SoftwareSerial bt(2,3); /* (Rx,Tx) */  

void setup() {
  pinMode(13,OUTPUT);   //left motors  forward
  pinMode(12,OUTPUT);   //left motors reverse
  pinMode(11,OUTPUT);   //right  motors forward
  pinMode(10,OUTPUT);   //right motors reverse
  bt.begin(9600); /* Define baud rate for software serial communication */
  Serial.begin(9600); /* Define baud rate for serial communication */
}

void loop() {
    
  
    if (bt.available()) /* If data is available on serial port */
    {
      t = bt.read();
      Serial.write(bt.read()); /* Print character received on to the serial monitor */
    }
    if(t == 'F'){            //move  forward(all motors rotate in forward direction)
  digitalWrite(11,HIGH);
  digitalWrite(13,HIGH);
}
 
else if(t == 'B'){      //move reverse (all  motors rotate in reverse direction)
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
}
  
else if(t == 'L'){      //turn right (left side motors rotate in forward direction,  right side motors doesn't rotate)
  digitalWrite(11,HIGH);
}
 
else  if(t == 'R'){      //turn left (right side motors rotate in forward direction, left  side motors doesn't rotate)
  digitalWrite(13,HIGH);
}

else if(t ==  'W'){    //turn led on or off)
  digitalWrite(9,HIGH);
}
else if(t == 'w'){
  digitalWrite(9,LOW);
}
 
else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
delay(10);
    
}
