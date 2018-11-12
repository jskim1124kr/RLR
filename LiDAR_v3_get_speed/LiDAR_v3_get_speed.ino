unsigned long pulseWidth;

unsigned long  previous_distance = 0;
unsigned long  current_distance = 0;

double current_speed = 0;
unsigned long current_time = 0;

void setup()
{
  Serial.begin(115200); // Start serial communications

  pinMode(2, OUTPUT); // Set pin 2 as trigger pin
  digitalWrite(2, LOW); // Set trigger LOW for continuous read

  pinMode(3, INPUT); // Set pin 3 as monitor pin
}

void loop()
{
  
  pulseWidth = pulseIn(3, HIGH); // Count how long the pulse is high in microseconds

  long previous_time;
  long elapsed_time;
  
  if(pulseWidth != 0)
  {
    previous_time = current_time;
    current_time = millis();
    elapsed_time = current_time - previous_time;
    
    previous_distance = current_distance;
    current_distance = pulseWidth / 10; // 10usec = 1 cm of distance
    current_speed = (double)(previous_distance - current_distance) / elapsed_time * 36;

    if (current_distance <= 4000 && current_speed <= 10000){
      Serial.print("Distance : ");
      Serial.print(current_distance);
      Serial.print("\tspeed : ");
      Serial.print(current_speed); // Print the distance//
      Serial.println("km/h");
    }
  }
  
  delay(50);  
  
}
