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
};

uint8_t px = 22;
uint8_t py = 28;

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

void render_text() __naked {
    asm(
        "push de\n"
        "push af\n"
        "ld a,2\n"
        "call $1601\n"
        "ld de,text\n"
        "push bc\n"
        "ld bc,4\n"
        "pop bc\n"
        "pop af\n"
        "pop de\n"
        "ret\n"
        "text:\n"
        "defm \"abcd\""
    );
}

#define ATTR(x,y) ((((uint16_t)(y))<<5)+((uint16_t)(x)))

void init_ui(){
    uint8_t player_attr = 0x06;
    volatile uint8_t* attrs = (uint8_t *)(0x5800);
    for (int i = 16; i<= (16+(32*24)); i+= 32){
        attrs[i] = 0;
    }

    for (int i = 16*32; i< (16*32)+16; i+= 1){
        attrs[i] = 0;
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

    render_text();

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

int main(){
    // black border
    asm(
        "push af\n"
        "ld a,0\n"
        "call 8859\n"
        "pop af\n"
    );
    init_ui();
    while (1){
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
    }
}
