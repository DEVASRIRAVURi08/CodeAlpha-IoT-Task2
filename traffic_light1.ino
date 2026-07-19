// C++ code
//Traffic light pins for each direction
int red[]={2,7,10,13};		//REdLEDS:N,E,S,W
int yellow[]={3,6,9,12};	//YELLOWLEDS
int green[]={4,5,8,11};	//GREENLEDS
  
//Timing for signals
int greenTime=5000;		//5 SECONDS GREEN
int yellowTime=2000;	//2 SECONDS YELLOW

void setup()
{
  //set all LED pins to output mode
  for (int i=0;i<4;i++){
  pinMode(red[i], OUTPUT);
  pinMode(yellow[i], OUTPUT);
  pinMode(green[i], OUTPUT);  
  }
}

void loop(){
  for (int i=0;i<4;i++){
    allred();			//turn all red before next green 
  digitalWrite(red[i], LOW);		//turn off red for current road
  digitalWrite(green[i], HIGH);		//Green ON
  delay(greenTime); // Wait during green signal
	 
  digitalWrite(green[i], LOW);		//Green ON
  digitalWrite(yellow[i], HIGH);	//yellow ON
  delay(yellowTime); // Wait during yellow signal
    
  digitalWrite(yellow[i], LOW);		//yellow off 
  digitalWrite(red[i], HIGH);		//red ON
  }
}
  
  //turn all red before each cycle
void allred(){
  for (int i=0;i<4;i++){
    digitalWrite(red[i], HIGH);
    digitalWrite(yellow[i], LOW);
    digitalWrite(green[i], LOW);
  }
}