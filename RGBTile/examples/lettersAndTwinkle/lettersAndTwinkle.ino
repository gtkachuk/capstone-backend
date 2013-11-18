/***********
*  Example of drawing letters and "twinkle" function
*  for the 5 x 5 RGB LED "tile" made by Burgeon Group
*
* Natalie Freed, June 2013
*
* Uses Adafruit_WS2801 library from adafruit.com
*
***********/

#include "RGBTile.h"
#include "SPI.h"

RGBTile myTile;
char name1[]  = "BURGEON"; //character array to hold word to draw
char name2[]  = "GROUP"; //character array to hold word to draw

void setup()
{
  myTile = RGBTile();
  Serial.begin(9600);
  
  //Start by coloring in a nice gradient
  for(int i=0;i<5;i++)
  {
    for(int j=0;j<5;j++)
    {
      myTile.colorPixel(i, j, 100, 0, map(i*5+j, 0, 24, 0, 255));
    }
  }
}

void loop()
{
  for(int i=0;i<7;i++) //display each character in the name
  {
      myTile.drawLetter(name1[i]);
      delay(1000); //wait a second after display each letter
  }
  myTile.drawLetter(' '); //draw a space
  delay(1000);
  for(int i=0;i<5;i++) //display each character in the name
  {
      myTile.drawLetter(name2[i]);
      delay(1000); //wait a second after display each letter
  }
  
  unsigned long time = millis(); //get current time since program started
  delay(1000);
  while(millis()-time < 5000) //for 3 seconds
  {
    myTile.twinkle();
    delay(random(0, 150)); //wait a random amount of time between 0 and 150 milliseconds between changes, for a more natural twinkle
  }
  delay(1000);
}

