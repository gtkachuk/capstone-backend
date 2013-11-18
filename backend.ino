#include "RGBTile.h"
#include "bitlash.h"

// global used by most functions
RGBTile myTile;

/*******************************************************************************
* bitlash functions
*/
numvar bitlash_twinkle() {
    myTile.twinkle();
    return (numvar) 0;
}

/*******************************************************************************
* arduino
*/
void setup() {
    // setup RGBTile
    myTile = RGBTile();

    // start by coloring in a nice gradient
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            myTile.colorPixel(i, j, 100, 0, map(i * 5 + j, 0, 24, 0, 255));
        }
    }
    myTile.drawAll();

    // setup bitlash
    initBitlash(57600);
    addBitlashFunction("twinkle", (bitlash_function) bitlash_twinkle);
}

void loop() {
    runBitlash();
}

