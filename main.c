#include <stdint.h>

#define CALC_Y(y) ((((y) & 0x7) << 8) | (((y) & 0x38) << 2) | (((y) & 0xC0) << 5))
#define NTILES (2)

uint8_t tiles[NTILES*32] = {
    0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,

//brick wall
    0xFF, 0xFF, 0xFF, 0xFF,
    0x80, 0x01, 0x01, 0x80,
    0x80, 0x01, 0x01, 0x80,
    0x80, 0x01, 0x01, 0x80, 
    0x80, 0x01, 0x01, 0x80,
    0x80, 0x01, 0x01, 0x80,
    0x80, 0x01, 0x01, 0x80,
    0xFF, 0xFF, 0xFF, 0xFF,


};

uint8_t player_sprite[32] = {
    0x00, 0x70, 0x0f, 0xf0,
    0x01, 0xe0, 0x0f, 0xf0,
    0x03, 0xc0, 0x0f, 0xf0,
    0x07, 0xe0, 0x07, 0xe0,
    0x05, 0xa0, 0x07, 0xe0,
    0x03, 0xc0, 0x07, 0xe0,
    0x02, 0x40, 0x04, 0x20,
    0x07, 0xe0, 0x06, 0x30,
};

#define MAPW (32)
#define MAPH (32)
#define MAPSZ (MAPH * MAPW)
#define XY(x,y) (((uint16_t)(x))+(((uint16_t)(y))<<5))
#define TILE(n) (tiles + ((n)<<5))
#define _ 0
#define H 1

uint8_t maze[MAPSZ] = {
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,_,_,_,_,_,_,_,H,_,_,_,_,_,H,_,_,_,_,H,_,_,_,_,1,1,1,1,1,
    1,1,1,1,H,H,H,H,_,H,H,H,_,H,H,H,_,H,H,H,H,_,H,_,H,H,_,1,1,1,1,1,
    1,1,1,1,_,_,_,_,_,_,_,_,_,_,_,H,_,_,_,_,_,_,H,_,_,H,_,1,1,1,1,1,
    1,1,1,1,H,H,H,H,H,H,_,H,H,H,H,H,_,H,H,H,H,_,H,H,H,H,_,1,1,1,1,1,
    1,1,1,1,_,_,_,_,_,_,_,H,_,_,_,_,_,H,_,_,_,_,_,_,_,_,_,1,1,1,1,1,
    1,1,1,1,_,H,H,H,H,H,H,H,_,H,H,H,_,H,_,H,H,H,H,H,H,_,_,1,1,1,1,1,
    1,1,1,1,_,_,_,_,_,_,_,H,_,_,_,H,_,H,_,_,_,_,_,_,_,_,_,1,1,1,1,1,
    1,1,1,1,_,H,H,H,H,H,H,H,H,H,H,H,H,H,H,H,H,H,H,H,H,H,H,1,1,1,1,1,
    1,1,1,1,_,_,_,_,_,H,_,_,_,_,_,_,_,H,_,_,_,H,_,_,_,_,_,1,1,1,1,1,
    1,1,1,1,_,H,_,_,_,H,_,H,H,H,H,H,H,H,_,_,_,H,_,H,H,H,_,1,1,1,1,1,
    1,1,1,1,_,H,_,_,_,H,_,_,_,_,_,_,_,H,_,_,_,H,_,_,_,H,_,1,1,1,1,1,
    1,1,1,1,_,H,_,H,H,H,_,H,H,H,H,H,H,H,_,H,_,H,H,H,H,H,_,1,1,1,1,1,
    1,1,1,1,_,H,_,H,_,H,_,H,_,_,_,_,_,H,_,H,_,H,_,_,_,_,_,1,1,1,1,1,
    1,1,1,1,_,H,_,H,_,H,_,H,_,H,_,H,_,H,_,H,H,H,_,_,_,H,H,1,1,1,1,1,
    1,1,1,1,_,_,_,H,_,H,_,_,_,H,_,H,_,H,_,_,_,H,_,_,_,H,_,1,1,1,1,1,
    1,1,1,1,_,H,_,H,_,H,_,_,_,H,_,H,H,H,_,H,_,H,_,H,_,H,_,1,1,1,1,1,
    1,1,1,1,_,H,_,_,_,_,_,_,_,H,_,_,_,H,_,H,_,_,_,H,_,H,_,1,1,1,1,1,
    1,1,1,1,H,H,_,H,H,H,H,H,H,H,H,H,H,H,_,H,_,H,H,H,_,_,_,1,1,1,1,1,
    1,1,1,1,_,_,_,H,_,H,_,_,_,_,_,_,_,H,_,H,_,H,_,H,_,H,_,1,1,1,1,1,
    1,1,1,1,_,H,H,H,_,H,_,_,_,H,_,_,_,H,_,H,_,H,_,H,_,H,_,1,1,1,1,1,
    1,1,1,1,_,_,_,_,_,H,_,_,_,H,_,_,_,H,_,H,_,H,_,_,_,H,_,1,1,1,1,1,
    1,1,1,1,H,H,H,H,_,H,H,H,_,H,H,H,H,H,_,H,_,H,H,H,H,H,_,1,1,1,1,1,
    1,1,1,1,_,_,_,H,_,_,_,_,_,H,_,_,_,H,_,H,_,H,_,_,_,_,_,1,1,1,1,1,
    1,1,1,1,H,H,_,H,_,H,H,H,_,H,H,H,_,H,_,H,_,H,_,H,_,H,_,1,1,1,1,1,
    1,1,1,1,_,_,_,_,_,H,_,_,_,_,_,_,_,_,_,H,_,H,_,H,_,H,_,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};

#define PLAYER_START_X (22)
#define PLAYER_START_Y (27)
uint8_t px;
uint8_t py;

void render_maze(){
    uint8_t tl_x = px - 3;
    uint8_t tl_y = py - 3;
    for (uint8_t xy = 0; xy <= 63; xy++){
        if (xy==0x1b){continue;}
        uint8_t x = xy&0x7;
        uint16_t *tp = (uint16_t *)TILE(maze[XY(x+tl_x,(xy>>3) + tl_y)]);
        uint16_t *bp = (uint16_t *)(0x4000+( ((uint16_t)(((((xy&0x18)<<3) | (x<<1))))) | ((uint16_t)((xy&0x20)<<6))));
        for (uint8_t i = 0; i<= 7; i++){
            *bp = *tp++;
            bp += 16;
            *bp = *tp++;
            bp += 112;
        }
    }
}

//open_channel = 0x1601
//print_str 0x203c
void render_text(char *text, uint16_t len) __naked {
    asm(
        "push af\n"
        "ld a,2\n"
        "call $1601\n"
        "pop af\n"
        "push iy\n"
        "ld iy,4\n"
        "add iy,sp\n"
        "ld c,(iy)\n"
        "inc iy\n"
        "ld b,(iy)\n"
        "inc iy\n"
        "ld e, (iy)\n"
        "inc iy\n"
        "ld d, (iy)\n"
        "pop iy\n"
        "call $203c\n"
        "ret\n"
    );
}

#define ATTR(x,y) ((((uint16_t)(y))<<5)+((uint16_t)(x)))

void init_all(){
    // black border
    asm(
        "push af\n"
        "ld a,1\n"
        "call 8859\n"
        "pop af\n"
    );
}

#define TXT_INK "\x10"
#define TXT_PAPER "\x11"
#define TXT_BRIGHT "\x13"
#define TXT_AT "\x16"

void init_maze(){
    uint8_t player_attr = 0x06;
    volatile uint8_t* attrs = (uint8_t *)(0x5800);
    for (int i = 16; i<= (16+(32*16)); i+= 32){
        attrs[i] = 1<<3;
    }

    for (int i = 16*32; i< (16*32)+16; i+= 1){
        attrs[i] = 1<<3;
    }

    for (int y = 0; y<= 15; y++){
        for (int x = 0; x<= 15; x++){
            attrs[ATTR(x,y)] = 0x02;
        }
    }

    // render player
    uint8_t xy = (3<<3) | 3;
    uint8_t x = xy&0x7;
    uint16_t *tp = (uint16_t *)player_sprite;
    uint16_t *bp = (uint16_t *)(0x4000+( ((uint16_t)(((((xy&0x18)<<3) | (x<<1))))) | ((uint16_t)((xy&0x20)<<6))));
    for (uint8_t i = 0; i<= 7; i++){
        *bp = *tp++;
        bp += 16;
        *bp = *tp++;
        bp += 112;
    }
    attrs[ATTR(7,7)] = player_attr;
    attrs[ATTR(7,6)] = player_attr;
    attrs[ATTR(6,7)] = player_attr;
    attrs[ATTR(6,6)] = player_attr;
    //render_text( TXT_AT "\x11\x00" TXT_INK "\x07" TXT_PAPER "\x00" TXT_BRIGHT "\x01" "Foooooooooo", 12);
}

void init_battle(){
}

uint16_t get_dir() __naked {
    asm(
        "push bc\n\t"
        "push af\n\t"
        "ld bc,$dfde\n\t"
        "in a,(c)\n\t"
        "and 3\n\t"
        "ld h,a\n\t"
        "ld bc,$fefe\n\t"
        "in a,(c)\n\t"
        "and 8\n\t"
        "or h\n\t"
        "ld h,a\n\t"
        "ld bc,$fdfe\n\t"
        "in a,(c)\n\t"
        "and 4\n\t"
        "or h\n\t"
        "ld h,a\n\t"
        "pop af\n\t"
        "pop bc\n\t"
        "ret\n\t"
    );
}

#define MODE_TITLE (0)
#define MODE_MAZE (1)
#define MODE_BATTLE (3)
int mode = MODE_TITLE;

void to_mode(int newmode){
    mode = newmode;
    if (mode == MODE_TITLE){
        px = PLAYER_START_X;
        py = PLAYER_START_Y;
    }
    if (mode == MODE_MAZE) {
        init_maze();
    }
    if (mode == MODE_BATTLE) {
        init_battle();
    }
}

int main(){
    init_all();
    to_mode(MODE_TITLE);
    to_mode(MODE_MAZE);
    while (1){
        switch (mode) {
            case MODE_TITLE:
                render_text( TXT_AT "\17\0" TXT_INK "\7" TXT_PAPER "\0" TXT_BRIGHT "\1" "Monster's Maze", 23);
                break;
            case MODE_MAZE:
                render_maze();
                uint16_t dir = get_dir()>>8;
                uint8_t lx = px;
                uint8_t ly = py;
                if (dir == 0xE){
                    px ++;
                }
                if (dir == 0xD){
                    px --;
                }
                if (dir == 0x7){
                    py ++;
                }
                if (dir == 0xB){
                    py --;
                }
                if (maze[XY(px, py)] != 0) {
                    px = lx;
                    py = ly;
                }
                break;
            case MODE_BATTLE:
                break;
        }
    }
}
