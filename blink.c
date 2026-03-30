#include <stdint.h>

/* Peripheral base addresses (STM32F7) */
#define PERIPH_BASE       0x40000000UL
#define AHB1PERIPH_BASE   (PERIPH_BASE + 0x00020000UL)

/* GPIOB and RCC base */
#define GPIOB_BASE        (AHB1PERIPH_BASE + 0x0400UL)
#define RCC_BASE          (AHB1PERIPH_BASE + 0x3800UL)

/* Register offsets */
#define RCC_AHB1ENR       (*(volatile uint32_t *)(RCC_BASE + 0x30))
#define GPIOB_MODER       (*(volatile uint32_t *)(GPIOB_BASE + 0x00))
#define GPIOB_ODR         (*(volatile uint32_t *)(GPIOB_BASE + 0x14))

/* Bit definitions */
#define RCC_AHB1ENR_GPIOBEN (1 << 1)   // Enable GPIOB clock

int main(void)
{
    /* 1. Enable GPIOB clock */
    RCC_AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

    /* 2. Set PB0 as output (MODER0 = 01) */
    GPIOB_MODER &= ~(3 << (0 * 2));  // Clear mode bits
    GPIOB_MODER |=  (1 << (0 * 2));  // Set as output

    while (1)
    {
        /* 3. Toggle PB0 */
        GPIOB_ODR ^= (1 << 0);

        /* crude delay */
        for (volatile uint32_t i = 0; i < 500000; i++);
    }
}