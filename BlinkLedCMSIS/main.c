#include "stm32f10x.h"

volatile uint32_t msTicks;  
void SysTick_Handler(void) {
    msTicks++;  
}
void delay(uint32_t ms) {
    uint32_t start = msTicks;
    while ((msTicks - start) < ms) {}
}
void BlinkLed(){
	static uint32_t t_pre=0;
	if ((msTicks - t_pre) >= 500) {
            GPIOC->ODR ^= GPIO_ODR_ODR13;  // Ð?o tr?ng thái chân GPIOC_Pin13
            t_pre = msTicks;  // C?p nh?t th?i di?m d?o tr?ng thái
}
}
int main(void) {
    SystemInit();  
    if (SysTick_Config(SystemCoreClock / 1000)) {
        while (1);  
    }
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;  // Enable GPIOC clock
    GPIOC->CRH |= GPIO_CRH_MODE13;      // Output mode, max speed 50 MHz
    GPIOC->CRH &= ~GPIO_CRH_CNF13;      // General purpose output push-pull
    while (1) {
        BlinkLed();
        }
 }