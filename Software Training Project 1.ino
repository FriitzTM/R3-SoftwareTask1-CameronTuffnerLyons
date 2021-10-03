byte Input_Pins_Tens[] = {5, 4, 3, 2}; // Creates Binary input array to be used to control the primary digit

byte Input_Pins_Ones[] = {9, 8, 7, 6}; // Creates Binary input array to be used to control the secondary digit
  
// Array of possible outputs listed in their binary format.
  
byte Binary_Output[10][4] = {
  
  // List of the Binary digits of 1-9 in acending order.
  
  {0,0,0,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,1,1},
  {0,1,0,0},
  {0,1,0,0},
  {0,1,1,0},
  {0,1,1,1},
  {1,0,0,0},
  {1,0,0,1}
};
  
// Variables to utilize potentiometer and to hold digit values
byte Value_To_Display, Digit[2];


// sets default display value
void setDefaultOutput(byte value){
  Value_To_Display = value;
}

// sets pins' output mode
void setPinOutputModes(){
  
  for (byte i=2; i<=9; i++){
   pinMode(i, HIGH); 
  }
  
}

// reads the input value of the POT and maps in to the desired range
byte getMappedPOTInputValue(byte min,byte max){
  
  return map(analogRead(A0), 0, 1023, min, max);
  
}

//sets Value_To_Display to the mapped POT input
void setValueToDisplay(byte min, byte max){
 
 Value_To_Display = getMappedPOTInputValue(min, max);
   
}


//Separates both digits from input Value to individual variables
void convertValueToDigits(byte Value){
 
  Digit[1] = (Value / 10) % 10;
  
  Digit[0] = Value % 10;
  
}

//Generates both digits by setting binary input pins to corresponding array cell in Binary_Output
void generate7segOutput(byte value[2]){
  
  for( byte i = 0; i < 4; i++){
    
	digitalWrite(Input_Pins_Tens[i], Binary_Output[value[1]][i]);
    
    digitalWrite(Input_Pins_Ones[i], Binary_Output[value[0]][i]);
  }
}


void setup()
{
  //default display value
	setDefaultOutput(0);
  
  
  //set pins to output mode
  setPinOutputModes();
  

}


void loop()
{
   delay(10); // Delay a little bit to improve simulation performance
  
  setValueToDisplay(0,99);
  
  convertValueToDigits(Value_To_Display);
  
  generate7segOutput(Digit);
}