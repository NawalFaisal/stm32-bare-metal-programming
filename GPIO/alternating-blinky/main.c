#include <stdint.h>

typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t RESERVED[4];
    volatile uint32_t ODR;
} GPIO_TypeDef;

typedef struct {
    volatile uint32_t RESERVED[12];
    volatile uint32_t AHB1ENR;
} RCC_TypeDef;

#define RCC ((RCC_TypeDef *)0x40023800)
#define GPIOA ((GPIO_TypeDef *)0x40020000)

int main(void) {
    RCC->AHB1ENR |= (1 << 0);
    GPIOA->MODER &= ~(3 << 10);
    GPIOA->MODER |= (1 << 10);
    GPIOA->ODR |= (1 << 5);      //start high
    
    // clear + configure
    GPIOA->MODER &= ~(3 << 12);
    GPIOA->MODER |= (1 << 12);
    GPIOA->ODR &= ~(1 << 6);       //start low
    
    while(1) {
        GPIOA->ODR ^= (1 << 5);
        GPIOA->ODR ^= (1 << 6);
        for(volatile int i = 0; i < 100000; i++);
    }
}