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

numvar bitlash_colorPixel() {
    if(getarg(0) == 5) { // number of args actually passed is 5
        myTile.colorPixel(getarg(1), getarg(2), getarg(3),
                          getarg(4), getarg(5));
        return (numvar) 0;
    }
    // do nothing if arg count incorrect
    return (numvar) 1;
}

numvar bitlash_drawPixel() {
    if(getarg(0) == 2) {
        myTile.drawPixel(getarg(1), getarg(2));
        return (numvar) 0;
    }
    return (numvar) 1;
}

numvar bitlash_drawAll() {
    myTile.drawAll();
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
    // all new function names MUST be lower case
    addBitlashFunction("color_pixel", (bitlash_function) bitlash_colorPixel);
    addBitlashFunction("draw_pixel", (bitlash_function) bitlash_drawPixel);
    addBitlashFunction("draw_all", (bitlash_function) bitlash_drawAll);
}

void loop() {
    runBitlash();
}

