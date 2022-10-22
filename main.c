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

#define MAPW (32)
#define MAPH (32)
#define MAPSZ (MAPH * MAPW)
#define XY(x,y) ((x)+((y)<<5))
#define TILE(n) (tiles + ((n)<<5))

uint8_t maze[MAPSZ];

uint16_t px = 5;
uint16_t py = 5;

void render_maze(){
    uint16_t tl_x = px - 5;
    uint16_t tl_y = py - 5;
    for (uint16_t xy = 0; xy <= 63; xy++){
        uint16_t x = xy&0x7;
        uint16_t *tp = (uint16_t *)TILE(maze[XY(x+tl_x,(xy>>3) + tl_y)]);
        uint16_t *bp = (uint16_t *)(0x4000+((((xy&0x18)<<3) | ((xy&0x20)<<6)) | (x<<1)));
        for (uint16_t i = 0; i<= 7; i++){
            *bp = *tp++;
            bp += 16;
            *bp = *tp++;
            bp += 112;
        }
    }
}

void test_maze(){
    for (int i =0; i<= MAPSZ-1; i++){
        maze[i] = 0;
    }
    for (int i =0; i<= 7; i++){
        maze[XY(0,i)] = 1;
        maze[XY(i,0)] = 1;
        maze[XY(7,i)] = 1;
        maze[XY(i,7)] = 1;
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
