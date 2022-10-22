#include <stdint.h>

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
#define TILE(n) (tiles + ((n)<<5))

uint8_t maze[MAPSZ];

uint16_t px = 5;
uint16_t py = 5;

/*
void render_maze(){
    volatile uint8_t* bitmap = (uint8_t *)(0x4000);
    for (uint16_t y = 0; y <= 9; y++){
        uint16_t my = y + py - 5;
        for (uint16_t x = 0; x <= 9; x++){
            uint8_t *t = TILE(maze[XY(x+px-5,my)]);
            uint16_t sy = CALC_Y(y<<4);
            uint16_t by = sy+(x<<1);
            uint16_t *bp = (uint16_t *)(bitmap+by);
            uint16_t *tp = (uint16_t *)(t);
            for (uint16_t i = 0; i<= 28; i+=4){
                *bp = *tp;
                bp += 16;
                tp += 1;

                *bp = *tp;
                tp += 1;
                bp += 112;
            }
        }
    }
}
*/

void render_maze(){
    volatile uint8_t* bitmap = (uint8_t *)(0x4000);
    for (uint16_t xy = 0; xy <= 63; xy++){
        uint16_t my = (xy>>3) + py - 5;
        uint8_t *t = TILE(maze[XY((xy&0x7)+px-5,my)]);
        uint16_t sy = CALC_Y((xy&0xFFF8)<<1);
        uint16_t by = sy+((xy&0x7)<<1);
        uint16_t *bp = (uint16_t *)(bitmap+by);
        uint16_t *tp = (uint16_t *)(t);
        for (uint16_t i = 0; i<= 28; i+=4){
            *bp = *tp;
            bp += 16;
            tp += 1;

            *bp = *tp;
            tp += 1;
            bp += 112;
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

void init_ui(){
    volatile uint8_t* attrs = (uint8_t *)(0x5800);
    
}

int main(){
    // black border
    asm(
        "push af\n"
        "ld a,0\n"
        "call 8859\n"
        "pop af\n"
    );
    test_maze();
    while (1){
        render_maze();
        px += 1;
        if (px > 15){
            px = 5;
        }
    }
}
