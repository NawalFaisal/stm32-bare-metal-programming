#include <stdint.h>

typedef struct {
    volatile uint32_t RESERVED[12];
    volatile uint32_t AHB1ENR;
} RCC_TypeDef;

typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t RESERVED[4];
    volatile uint32_t ODR;
} GPIO_TypeDef;

#define RCC   ((RCC_TypeDef *)0x40023800)
#define GPIOA ((GPIO_TypeDef *)0x40020000)

int main(void){

    RCC ->AHB1ENR |= (1<< 0); 
    GPIOA -> MODER |= (1<<10);
    GPIOA -> ODR |= (1<<5);

    while(1){
        GPIOA -> ODR ^= (1<<5);
        for(volatile int i = 0; i < 1000000; i++);
    }

}


