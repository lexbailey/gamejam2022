#include <stdint.h>
#include "image.h"

uint16_t calc_y(uint16_t y){
    return ((y & 0x7) << 8) | ((y & 0x38) << 2) | ((y & 0xC0) << 5);
}

int main(){
    volatile uint8_t* bitmap = (0x4000);
    for (uint16_t row = 0; row<= 5; row++){
        uint16_t start = calc_y(row);
        for (uint16_t i = 0; i<= 9; i++){
            bitmap[start+i] = image[(row*10)+i];
        }
    }
    while(1){ volatile asm ("nop"); }
}
