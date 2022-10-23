#include <stdint.h>

#define CALC_Y(y) ((((y) & 0x7) << 8) | (((y) & 0x38) << 2) | (((y) & 0xC0) << 5))
#define NTILES (5)

uint8_t titlescreen[] = {
    #include "titlescreen"
};

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

#include "assets.h"


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

#define TXT_INK "\x10"
#define TXT_PAPER "\x11"
#define TXT_BRIGHT "\x13"
#define TXT_AT "\x16"

uint8_t maze[MAPSZ] = {
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,_,_,_,_,_,_,_,H,_,_,_,_,_,H,_,_,_,_,H,3,_,_,_,1,1,1,1,1,
    1,1,1,1,H,H,H,H,_,H,H,H,_,H,H,H,_,H,H,H,H,_,H,_,H,H,_,1,1,1,1,1,
    1,1,1,1,_,_,_,_,_,_,2,_,_,_,_,H,2,_,_,_,_,_,H,_,_,H,_,1,1,1,1,1,
    1,1,1,1,H,H,H,H,H,H,_,H,H,H,H,H,_,H,H,H,H,_,H,H,H,H,_,1,1,1,1,1,
    1,1,1,1,_,2,_,_,_,_,_,H,_,_,_,_,_,H,_,_,2,_,_,_,_,_,_,1,1,1,1,1,
    1,1,1,1,_,H,H,H,H,H,H,H,_,H,H,H,_,H,_,H,H,H,H,H,H,_,_,1,1,1,1,1,
    1,1,1,1,_,_,_,_,_,_,_,H,_,_,_,H,_,H,_,_,_,_,_,_,_,_,_,1,1,1,1,1,
    1,1,1,1,_,H,H,H,H,H,H,H,H,H,H,H,H,H,H,H,H,H,H,H,H,H,H,1,1,1,1,1,
    1,1,1,1,2,_,_,_,_,H,2,_,_,_,_,_,_,H,_,_,_,H,_,2,_,_,_,1,1,1,1,1,
    1,1,1,1,_,H,_,_,_,H,_,H,H,H,H,H,H,H,_,_,_,H,_,H,H,H,_,1,1,1,1,1,
    1,1,1,1,_,H,_,_,_,H,_,_,_,_,_,_,_,H,_,_,_,H,_,_,_,H,_,1,1,1,1,1,
    1,1,1,1,_,H,_,H,H,H,_,H,H,H,H,H,H,H,_,H,_,H,H,H,H,H,_,1,1,1,1,1,
    1,1,1,1,_,H,_,H,_,H,_,H,_,_,2,_,_,H,2,H,_,H,_,_,_,2,_,1,1,1,1,1,
    1,1,1,1,_,H,_,H,_,H,2,H,_,H,_,H,_,H,_,H,H,H,_,_,_,H,H,1,1,1,1,1,
    1,1,1,1,_,_,_,H,_,H,_,_,_,H,_,H,_,H,_,_,_,H,_,_,_,H,_,1,1,1,1,1,
    1,1,1,1,_,H,_,H,_,H,_,_,_,H,_,H,H,H,_,H,_,H,_,H,_,H,_,1,1,1,1,1,
    1,1,1,1,_,H,2,_,_,_,_,_,_,H,_,_,_,H,_,H,_,_,_,H,_,H,_,1,1,1,1,1,
    1,1,1,1,H,H,_,H,H,H,H,H,H,H,H,H,H,H,_,H,2,H,H,H,_,_,_,1,1,1,1,1,
    1,1,1,1,_,_,_,H,_,H,_,_,_,_,_,_,_,H,_,H,_,H,_,H,_,H,_,1,1,1,1,1,
    1,1,1,1,_,H,H,H,_,H,_,_,_,H,_,_,_,H,_,H,_,H,_,H,_,H,_,1,1,1,1,1,
    1,1,1,1,_,_,_,_,2,H,_,_,_,H,_,_,_,H,_,H,2,H,_,2,_,H,_,1,1,1,1,1,
    1,1,1,1,H,H,H,H,_,H,H,H,_,H,H,H,H,H,2,H,_,H,H,H,H,H,_,1,1,1,1,1,
    1,1,1,1,_,_,_,H,_,_,_,_,_,H,_,_,_,H,_,H,_,H,_,2,_,_,_,1,1,1,1,1,
    1,1,1,1,H,H,_,H,_,H,H,H,2,H,H,H,2,H,_,H,_,H,_,H,_,H,_,1,1,1,1,1,
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
uint8_t bpx;
uint8_t bpy;
uint8_t obpx;
uint8_t obpy;

uint8_t player_hp;

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
        "push bc\n"
        "push de\n"
        "push iy\n"
        "ld iy,8\n"
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
        "pop de\n"
        "pop bc\n"
        "ret\n"
    );
}

void format_text(char row, char col, char bg, char fg, char bright, char* str, uint16_t len){
    str[0] = 0x16;
    str[1] = row;
    str[2] = col;
    str[3] = 0x11;
    str[4] = bg;
    str[5] = 0x10;
    str[6] = fg;
    str[7] = 0x13;
    str[8] = bright;
    render_text(str, 9+len);
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

void sprite(uint16_t *tp, uint16_t x, uint16_t y){
    uint16_t *bp = (uint16_t *)(0x4000+CALC_Y(y<<4)+(x<<1));
    for (uint8_t i = 0; i<= 7; i++){
        *bp = *tp++;
        bp += 16;
        *bp = *tp++;
        bp += 112;
    }
}

void unsprite(uint16_t x, uint16_t y){
    uint16_t *bp = (uint16_t *)(0x4000+CALC_Y(y<<4)+(x<<1));
    for (uint8_t i = 0; i<= 7; i++){
        *bp = 0;
        bp += 16;
        *bp = 0;
        bp += 112;
    }
}

void sprite_attr(uint16_t x, uint16_t y, uint8_t attr){
    volatile uint8_t* attrs = (uint8_t *)(0x5800);
    uint16_t ax = x<<1;
    uint16_t ay = y<<1;
    attrs[ATTR(ax, ay)] = attr;
    attrs[ATTR(ax+1, ay)] = attr;
    attrs[ATTR(ax, ay+1)] = attr;
    attrs[ATTR(ax+1, ay+1)] = attr;
}

void init_maze(){
    uint8_t player_attr = 0x06;
    volatile uint8_t* bitmap = (uint8_t *)(0x4000);
    volatile uint8_t* attrs = (uint8_t *)(0x5800);
    //screen is mostly black
    for (int i = 0; i<= 32*192; i++){
        bitmap[i] = 0;
    }
    for (int i = 0; i<= (32*24); i+= 1){
        attrs[i] = 1;
    }

    // Some blue lines
    for (int i = 16; i<= (16+(32*16)); i+= 32){
        attrs[i] = 1<<3;
    }
    for (int i = 16*32; i< (16*32)+16; i+= 1){
        attrs[i] = 1<<3;
    }

    // Maze area is red on black
    for (int y = 0; y<= 15; y++){
        for (int x = 0; x<= 15; x++){
            attrs[ATTR(x,y)] = 0x02;
        }
    }

    // render player
    sprite(player_sprite, 3,3);
    sprite_attr(3,3,player_attr);
    format_text(17, 0, 0, 7, 1, "         Find the ghost.", 15);
}

#define DIR_RIGHT (0xE)
#define DIR_LEFT (0xD)
#define DIR_DOWN (0x7)
#define DIR_UP (0xB)

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

uint16_t get_enter() __naked {
    asm(
        "push bc\n\t"
        "push af\n\t"
        "ld bc,$bffe\n\t"
        "in a,(c)\n\t"
        "and 1\n\t"
        "ld h,a\n\t"
        "pop af\n\t"
        "pop bc\n\t"
        "ret\n\t"
    );
}

#define MODE_TITLE (0)
#define MODE_MAZE (1)
#define MODE_BATTLE (2)
#define MODE_WON (3)
#define MODE_GAMEOVER (4)

uint8_t mode = MODE_TITLE;

#define ENEMY_MIN (2)

#define ENEMY_BAT (2)
#define ENEMY_GHOST (3)
#define ENEMY_SPIDER (4)

#define ENEMY_MAX (4)
uint8_t cur_encounter;
uint8_t enc_x;
uint8_t enc_y;
uint8_t enemy_hp;

uint8_t bats[7];

uint8_t cur_en_hp = 10;

void init_battle(){
    volatile uint8_t* bitmap = (uint8_t *)(0x4000);
    volatile uint8_t* attrs = (uint8_t *)(0x5800);
    //screen is mostly black
    for (int i = 0; i < (32*18); i+= 1){
        attrs[i] = 1;
    }
    for (int i = 32*18; i< (32*24); i+= 1){
        attrs[i] = 7 | (1<<6);
    }
    for (int i = 0; i<= 32*192; i++){
        bitmap[i] = 0;
    }
    for (int i = 0; i < (32*2); i+= 1){
        attrs[i] = (2<<3)|2;
    }
    for (int i = 32*16; i < ((32*16)+(32*2)); i+= 1){
        attrs[i] = (2<<3)|2;
    }
    for (int i = 0; i < (32*16); i+= 32){
        attrs[i] = (2<<3)|2;
        attrs[i+1] = (2<<3)|2;
        attrs[i+30] = (2<<3)|2;
        attrs[i+31] = (2<<3)|2;
    }

    enemy_hp = cur_en_hp;
    cur_en_hp += 1;

    format_text( 19,0,1,7,1, "         HP:                             ", 32);
    format_text( 19,3,2,2,0, "                                      ", 20);
    format_text( 19,3,4,4,0, "                                      ", player_hp);
    if(cur_encounter == ENEMY_BAT) {
        bats[1] = 35;
        bats[0] = 25;
        bats[6] = 15;
        bats[2] = 50;
        bats[4] = 80;
        bats[3] = 70;
        bats[5] = 70;
        bpx = 2;
        bpy = 5;
        format_text( 17,0,1,7,1, "         Adventurer vs Bats!             ", 32);
        format_text( 18,0,1,7,1, "         Move around to avoid the bats!  ", 32);
    }
    if(cur_encounter == ENEMY_GHOST) {
        format_text( 17,0,1,7,1, "         Adventurer vs Ghosts!           ", 32);
        format_text( 18,0,1,7,1, "         Turn on lights to scare ghosts. ", 32);
    }
    if(cur_encounter == ENEMY_SPIDER) { format_text( 17,0,1,7,1, "         Adventurer vs Spiders!", 19); }
}

void to_mode(uint8_t newmode){
    volatile uint8_t* bitmap = (uint8_t *)(0x4000);
    volatile uint8_t* attrs = (uint8_t *)(0x5800);
    //screen is mostly black
    for (int i = 0; i<= 32*192; i++){
        bitmap[i] = 0;
    }
    for (int i = 0; i<= (32*24); i+= 1){
        attrs[i] = 1;
    }
    mode = newmode;
    if (mode == MODE_TITLE){
        px = PLAYER_START_X;
        py = PLAYER_START_Y;
        player_hp = 20;
        memcpy(0x4000, titlescreen, (32*192)+(32*24));
        format_text( 20,0,1,7,1, "           press enter to start          ", 32);
    }
    if (mode == MODE_MAZE) {
        init_maze();
        render_maze();
    }
    if (mode == MODE_BATTLE) {
        init_battle();
    }
}


void battle_won(){
    maze[XY(enc_x,enc_y)] = 0;
    to_mode(MODE_MAZE);
}

void render_battle(){
    
    volatile uint8_t* attrs = (uint8_t *)(0x5800);
    if (player_hp < 20){
        attrs[ATTR(3+(player_hp), 19)] = (2<<3)|2;
    }
    if(cur_encounter == ENEMY_BAT) {
        unsprite(obpx, obpy);
        sprite(player_sprite, bpx, bpy);
        sprite_attr(bpx, bpy, 6);
        static uint16_t battime = 5000; // same bat place :^)
        uint16_t time = battime;
        while (time != 0){
            time --;
        }
        for (int y = 0; y<= 6; y++) {
            if (bats[y] > 15){
                bats[y] --;
            }
            else{
                unsprite(bats[y],y+1);
                if (bats[y] > 2){
                    bats[y] --;
                    sprite(TILE(ENEMY_BAT), bats[y],y+1);
                    sprite_attr(bats[y], y+1, 1);
                    if (bpx==bats[y] && bpy==(y+1)){player_hp --;}
                }
                else{
                    if (bpx==(bats[y]-1) && bpy==(y+1)){player_hp --;}
                    bats[y] = 70;
                    enemy_hp --;
                    if (enemy_hp <= 0){
                        battle_won();
                        battime -= 200;
                    }
                }
                if (player_hp == 0){
                    to_mode(MODE_GAMEOVER);
                }
            }
        }
    }
}


int main(){
    init_all();
    to_mode(MODE_TITLE);
    //to_mode(MODE_MAZE);
    uint16_t dir;
    while (1){
        if (mode == MODE_TITLE){
            dir = get_dir()>>8;
            if ((get_enter()>>8) == 0){
                to_mode(MODE_MAZE);
            }
        }
        if (mode == MODE_MAZE){
            render_maze();
            dir = get_dir()>>8;
            uint8_t lx = px;
            uint8_t ly = py;
            if (dir == DIR_RIGHT){
                px ++;
            }
            if (dir == DIR_LEFT){
                px --;
            }
            if (dir == DIR_DOWN){
                py ++;
            }
            if (dir == DIR_UP){
                py --;
            }
            uint8_t newtile = maze[XY(px, py)];
            if (newtile == ENEMY_GHOST){
                to_mode(MODE_WON);
            }
            else if (newtile >= ENEMY_MIN && newtile <= ENEMY_MAX) { // encounter
                cur_encounter = newtile;
                enc_x = px;
                enc_y = py;
                to_mode(MODE_BATTLE);
            }
            if (newtile != 0) {
                px = lx;
                py = ly;
            }
        }
        if (mode == MODE_BATTLE){
            render_battle();
            dir = get_dir()>>8;
            obpx = bpx;
            obpy = bpy;
            if (dir == DIR_RIGHT){
                bpx ++;
            }
            if (dir == DIR_LEFT){
                bpx --;
            }
            if (dir == DIR_DOWN){
                bpy ++;
            }
            if (dir == DIR_UP){
                bpy --;
            }
            if (bpx > 14) {bpx = 14;}
            if (bpy > 7) {bpy = 7;}
            if (bpx < 1) {bpx = 1;}
            if (bpy < 1) {bpy = 1;}

        }
        if (mode == MODE_WON){
            format_text( 10,0,1,7,1, "         WINNER!!!!!!                    ", 32);
            format_text( 11,0,1,7,1, "                        WINNER!!!!!      ", 32);
            format_text( 18,0,1,7,1, "           press enter to reset          ", 32);
            if ((get_enter()>>8) == 0){
                to_mode(MODE_TITLE);
            }
        }
        if (mode == MODE_GAMEOVER){
            format_text( 10,0,1,7,1, "         Game over                       ", 32);
            format_text( 18,0,1,7,1, "           press enter to reset          ", 32);
            if ((get_enter()>>8) == 0){
                to_mode(MODE_TITLE);
            }
        }
    }
    while(1){asm("nop");}
}
