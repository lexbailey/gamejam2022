#include <stdint.h>
#include "image.h"

/*
uint16_t calc_y(uint16_t y){
    return ((y & 0x7) << 8) | ((y & 0x38) << 2) | ((y & 0xC0) << 5);
}
*/

#define CALC_Y(y) ((((y) & 0x7) << 8) | (((y) & 0x38) << 2) | (((y) & 0xC0) << 5))
#define NTILES (2)

uint8_t tiles[NTILES*32] = {
    0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,
    0xFF, 0xFF, 0xFF, 0xFF,
    0x80, 0x01, 0x01, 0x80,
    0x80, 0x01, 0x01, 0x80,
    0x80, 0x01, 0x01, 0x80, 
    0x80, 0x01, 0x01, 0x80,
    0x80, 0x01, 0x01, 0x80,
    0x80, 0x01, 0x01, 0x80,
    0xFF, 0xFF, 0xFF, 0xFF, 
};

#define MAPW (50)
#define MAPH (50)
#define MAPSZ (MAPH * MAPW)
#define XY(x,y) ((x)+((y)*MAPW))
#define TILE(n) (tiles + (32*(n)))

uint8_t maze[MAPSZ];

uint16_t px;
uint16_t py;

void render_maze(){
    volatile uint8_t* bitmap = (uint8_t *)(0x4000);
    for (uint16_t y = 0; y <= 9; y++){
        for (uint16_t x = 0; x <= 9; x++){
            uint8_t *t = TILE(maze[XY(x,y)]);
            for (uint16_t i = 0; i<= 7; i++){
                uint16_t sy1 = CALC_Y((16*y)+i);
                uint16_t sy2 = CALC_Y(((16*y)+8)+i);
                bitmap[sy1+(x*2)]   = t[i*4];
                bitmap[sy1+(x*2)+1] = t[(i*4)+1];
                bitmap[sy2+(x*2)]   = t[(i*4)+2];
                bitmap[sy2+(x*2)+1] = t[(i*4)+3];
            }
        }
    }
}

void test_maze(){
    for (int i =0; i<= MAPSZ-1; i++){
        maze[i] = 0;
    }
    for (int i =0; i<= 9; i++){
        maze[XY(0,i)] = 1;
        maze[XY(i,0)] = 1;
        maze[XY(9,i)] = 1;
        maze[XY(i,9)] = 1;
    }
}

int main(){
    volatile uint8_t* bitmap = (uint8_t *)(0x4000);
    for (uint16_t row = 0; row<= 5; row++){
        uint16_t start = CALC_Y(row);
        for (uint16_t i = 0; i<= 9; i++){
            bitmap[start+i] = image[(row*10)+i];
        }
    }
    test_maze();
    render_maze();
    while(1){ /*volatile asm ("nop");*/ }
}
