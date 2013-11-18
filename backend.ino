#include "RGBTile.h"
#include "bitlash.h"

RGBTile myTile;

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
}

void loop() {
    runBitlash();
}

