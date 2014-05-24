#include <AESLib.h>

void setup() 
{

  Serial.begin(57600);
  
}

void loop() {
  #define arraySize 128
  char inData[arraySize];
  short index            = 0;
  char inChar;
  if(Serial.available() > 0)
  {
      while(Serial.available() > 0 && index < arraySize-1)
     {
         inChar = Serial.read();
         inData[index]    = inChar;
         index++;
         inData[index]    = '\0'; // Add a null at the end
     }
     
      //Check if the serial responded with at least one character before encryption
      //Serial.println(inData[0]);
      if(!inData[0]){
        exit(0);
      }
      //TODO: add salt using the above pattern to check length
      
      //Serial.println(inData); //print the string we just recieved from usb
      
      //This is our cipher. Change the numbers so they are between 0-31
      uint8_t key[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};

      aes256_enc_single(key, inData);
      Serial.print(inData); //TODO: add more salt

      //Use this to test if everything is working by decrypting
      //aes256_dec_single(key, inData);
      //Serial.print(inData);
  }

}