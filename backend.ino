#include "RGBTile/RGBTile.h"

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

    // setup bitlash

    // generated setup code goes here

}

void loop() {
    // generated loop code goes here

}

