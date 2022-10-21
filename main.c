#include <stdint.h>

int main(){
    volatile uint8_t* bitmap = (0x4000);
    for (uint16_t i = 0; i<= (192*32)-1; i++){
        bitmap[i] = 0xAA;
    }
    while(1){ volatile asm ("nop"); }
}
