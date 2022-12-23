/* Define values for pins
   "s" pins work in 2's, 2^n,
   so you can have a combination of High and low*/
#define s0 4
#define s1 5
#define s2 6
#define s3 7
#define sensorOut 8

/* Variables to store the detected frequency*/
int redFreq = 0;
int greenFreq = 0;
int blueFreq = 0;

void setup() {

  //Used to set scaling value
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);

  //Used for setting diodes to detect specific colors
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);

  //input frequency, this is the pin that actually detects the color
  pinMode(sensorOut, INPUT); 

  // High Low sets frequency scaling to 20% (it depends on what board you use that determines what scale val is best)
  digitalWrite(s0,HIGH);
  digitalWrite(s1,LOW);
  
   // Begins serial communication 
  Serial.begin(9600);
}

void loop() {
  // Combination of Low and Low sets the diodes to detect RED only
  digitalWrite(s2,LOW);
  digitalWrite(s3,LOW);
  
  // Store the frequency detected in a variable
  redFreq = pulseIn(sensorOut, LOW);
  
   // Printing the RED (R) value to serial window
  Serial.print("R = ");
  Serial.println(redFreq);
  delay(100);
  

  /* When holding color sensor over desired color, youll get a range, not an exact value,
     so you place the lowest and highest values seen while holding the color sensor over the specific color,
     i.e, this example lowest for red button was 75 and highest was 100*/
  if (redFreq > 75 && redFreq < 100)
  {
    //print to serial window for this example but can change this to do whatever
    Serial.println("Red Detected");
    delay(100);
  }
}
