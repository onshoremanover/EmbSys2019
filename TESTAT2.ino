#include <SD.h>
#include <SPI.h>
#include <AudioZero.h>


#define pinVolpos 13
#define pinVolneg 12
#define pin_Next 11
#define pin_StartStop 10




int STEP = 10;
int volume2 = 50;

File myFile;
File root;

void setup()
{
  // debug output at 115200 baud
  Serial.begin(115200);

  // setpinVolpos SD-card
  Serial.print("Initializing SD card...");
  if (!SD.begin(4)) {
    Serial.println(" failed!");
    while(true);
  }


  Serial.println("\nFiles found on the card (name and size in bytes): ");
  root = SD.open("/");

  printDirectory(root, 0);

  Serial.println();
 
  AudioZero.begin(2*44100);


 


analogWrite(A1, volume2 );
    attachInterrupt(digitalPinToInterrupt(pinVolpos), VolposPressed,FALLING);
  attachInterrupt(digitalPinToInterrupt(pinVolneg), VolnegPressed,FALLING);
  attachInterrupt(digitalPinToInterrupt(pin_StartStop), eplay,FALLING);
  attachInterrupt(digitalPinToInterrupt(pin_Next), epause,FALLING);
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ LOOP @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void loop()
{
  //int count = 0;

 
 
  
  File myFile = SD.open("test.wav");
  if (!myFile) {
    // if the file didn't open, print an error and stop
    Serial.println("error opening test.wav");
    while (true);
  }

  Serial.print("Playing");
 
  
  // until the file is not finished  
  AudioZero.play(myFile);

  Serial.println("End of file. Thank you for listening!");
  while (true) ;
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ FKT @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



void VolposPressed() {
  if (volume2 < 1023) {
    volume2 += STEP;
   }
   Serial.print("pinVolpos: "); Serial.println(volume2);
   analogWrite(A1,volume2);
}

void VolnegPressed() {
  if (volume2 > 0) {
    volume2 -= STEP;
  }
   Serial.print("pinVolneg: "); Serial.println(volume2);
   analogWrite(A1,volume2);
}

void eplay(){
  AudioZero.play(myFile);
  
  }
void epause(){
AudioZero.pause(myFile);
  
}


void printDirectory(File dir, int numTabs) {
  while (true) {

    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    /*if (entry.isDirectory()) {
      Serial.println("/");
      printDirectory(entry, numTabs + 1);
    } else {*/
      // files have sizes, directories do not
      Serial.print("\t\t");
      //Serial.println(entry.size(), DEC);
    //}

// filter nach letzte vier buchstaben = .wav
    
    entry.close();
  }
}
