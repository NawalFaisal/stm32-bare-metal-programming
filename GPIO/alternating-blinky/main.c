#include <stdint.h>

typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t RESERVED[4];
    volatile uint32_t ODR;
} GPIO_TypeDef;
   

typedef struct {
    volatile uint32_t RESERVED[12];
    volatile uint32_t AHB1ENR;

}RCC_TypeDef;

#define RCC ((RCC_TypeDef *)0x40023800)  
#define GPIOA ((GPIO_TypeDef *)0x40020000)  // treat the bytes at address 0x40020000 as if they were a GPIO_TypeDef struct

int main(void){

    RCC -> AHB1ENR |= (1<<0);
    GPIOA -> MODER |= (1<<10);
    GPIOA -> ODR |= (1<<5);
    GPIOA -> MODER |= (1<<12);
    GPIOA -> ODR &= -(1<<6);


    while(1){
        GPIOA -> ODR ^= (1<<5);
        GPIOA -> ODR ^=(1<<5);
        for(volatile int i = 0; i < 100000; i++);
    }

}