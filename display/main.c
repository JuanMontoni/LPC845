#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "peripherals.h"
#include "board.h"
#include "app.h" 
#include "stdio.h"

#include "display.h"

#define delay_ms(x)     flag_tick = 0; while(x != flag_tick)

#define LED_ON              0
#define LED_OFF             1
#define LED_RED             GPIO, 1, 2
#define LED_BLUE            GPIO, 1, 1
#define LED_GREEN           GPIO, 1, 0
#define LED_RED_W(x)        GPIO_PinWrite(LED_RED, x)
#define LED_BLUE_W(x)       GPIO_PinWrite(LED_BLUE, x)
#define LED_GREEN_W(x)      GPIO_PinWrite(LED_GREEN, x)
#define LED_RED_R()         GPIO_PinRead(LED_RED)
#define LED_BLUE_R()        GPIO_PinRead(LED_BLUE)
#define LED_GREEN_R()       GPIO_PinRead(LED_GREEN)
#define SW_ISP              GPIO_PinRead(GPIO, 0, 12)
#define SW_USER             GPIO_PinRead(GPIO, 0, 4)

volatile uint32_t flag_tick = 0;

int main(void)
{

    BOARD_InitHardware();
    BOARD_InitDebugConsole();
    gpio_pin_config_t out_config = {kGPIO_DigitalOutput, 1};
    GPIO_PortInit(GPIO, 1);
    GPIO_PinInit(GPIO, 1, 0, &out_config);
    GPIO_PinInit(GPIO, 1, 1, &out_config);
    GPIO_PinInit(GPIO, 1, 2, &out_config);
    gpio_pin_config_t in_config = {kGPIO_DigitalInput};
    GPIO_PortInit(GPIO, 0);
    GPIO_PinInit(GPIO, 0, 4, &in_config);
    GPIO_PinInit(GPIO, 0, 12, &in_config);
    // GPIO_PinInit(GPIO, 0, 28, &out_config);
    // GPIO_PinWrite(GPIO, 0, 28, 0);

    iniciar_display();

    SysTick_Config(SystemCoreClock/1000);

    int a = 0;   
    
    /*
    while (a == 0)
    {
        PRINTF("Seleccionar display a usar:\n 1_Display 1\n 2_Display 2\n 3_Ambos displays\n");
        SCANF("%d",&a);
        SELECT_DISPLAY(a);        
    }
    */

    SELECT_DISPLAY();
    DIG_DOT_OFF();

    
    int seg = 0;
    int min = 0;
    int hora = 0;    
    

    while (1)
    {   

        
        seg = seg + 1;
        delay_ms(1000);

        if(seg == 60)   {min = min + 1;  seg = 0;}
        if(min == 60)   {hora = hora + 1;    min = 0;}   

        if(hora == 0 && min == 0 && seg<10) PRINTF("00:00:0%d\n", seg);
        
        if(hora == 0 && min == 0 && seg>=10) PRINTF("00:00:%d\n", seg);

        if(hora == 0 && min<10 && min != 0 && seg<10) PRINTF("00:0%d:0%d\n", min, seg);

        if(hora == 0 && min<10 && min != 0 && seg>=10) PRINTF("00:0%d:%d\n", min, seg);

        if(hora == 0 && min>=10 && seg<10) PRINTF("00:%d:0%d\n", min, seg);

        if(hora == 0 && min>=10 && seg>=10) PRINTF("00:%d:%d\n", min, seg);

        if(hora != 0 && min == 0 && seg<10) PRINTF("%d:00:0%d\n",hora, seg);
        
        if(hora != 0 && min == 0 && seg>=10) PRINTF("%d:00:%d\n",hora, seg);

        if(hora != 0 && min<10 && seg<10) PRINTF("%d:0%d:0%d\n",hora, min, seg);

        if(hora != 0 && min<10 && seg>=10) PRINTF("%d:0%d:%d\n",hora, min, seg);

        if(hora != 0 && min>=10 && seg>=10) PRINTF("%d:%d:%d\n",hora, min, seg);

        a = a + 1;

        if(a == 10) a = 0;

        SELECT_DIG(a);

        /*
        if(!SW_USER && SW_ISP)  a = a + 1;
        delay_ms(100);
        LED_BLUE_W(LED_ON);
        if(SW_USER && !SW_ISP)  a = a - 1;
        delay_ms(100);
        if(a>9) a = 0;
        if(a<0) a = 9;

        SELECT_DIG(a);

        
        if(!SW_USER && !SW_ISP)
        {
            delay_ms(50);
            if(!SW_USER && !SW_ISP)
            {
            LED_GREEN_W(LED_ON);
            delay_ms(1000);
            LED_GREEN_W(LED_OFF);
            delay_ms(1000);   
            a = a + 1;
            PRINTF("%d\n",a);
            }
        } 

        if(!SW_USER)
        {   

            DIG_9();
        } 

       if(flag_tick >= 1000){
        if(SW_ISP == 0){
            if(LED_GREEN_R() == LED_OFF) LED_GREEN_W(LED_ON);
            }
            else LED_BLUE_W(LED_ON);
        
            flag_tick = 0;
       }
        */
    }
    return 0;
}


void SysTick_Handler(void) {
    flag_tick++;
}
