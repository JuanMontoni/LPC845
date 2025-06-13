#ifndef __DISPLAY__
#define __DISPLAY__

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "peripherals.h"
#include "board.h"
#include "app.h" 


void iniciar_display(void)
{
    BOARD_InitHardware();
    BOARD_InitDebugConsole();
    gpio_pin_config_t out_config = {kGPIO_DigitalOutput};
    GPIO_PortInit(GPIO, 0);
    GPIO_PinInit(GPIO, 0, 8, &out_config);
    GPIO_PinInit(GPIO, 0, 9, &out_config);
    GPIO_PinInit(GPIO, 0, 0, &out_config);
    GPIO_PinInit(GPIO, 0, 1, &out_config);
    GPIO_PinInit(GPIO, 0, 6, &out_config);
    GPIO_PinInit(GPIO, 0, 10, &out_config);
    GPIO_PinInit(GPIO, 0, 11, &out_config);
    GPIO_PinInit(GPIO, 0, 13, &out_config);
    GPIO_PinInit(GPIO, 0, 14, &out_config);
    GPIO_PinInit(GPIO, 0, 15, &out_config);
}

void SELECT_DISPLAY(void)
{
    int SELECT;
    PRINTF("Seleccionar display a usar:\n 1_Display 1\n 2_Display 2\n 3_Ambos displays\n");
    SCANF("%d",&SELECT);

    if(SELECT == 1)
    {
        GPIO_PinWrite(GPIO, 0, 8, 0);
        GPIO_PinWrite(GPIO, 0, 9, 1);
    }
    if(SELECT == 2)
    {
        GPIO_PinWrite(GPIO, 0, 8, 1);
        GPIO_PinWrite(GPIO, 0, 9, 0);
    }
    if(SELECT == 3) 
    {
        GPIO_PinWrite(GPIO, 0, 8, 0);
        GPIO_PinWrite(GPIO, 0, 9, 0);        
    }
}

void DIG_1(void)
{
    GPIO_PinWrite(GPIO, 0, 6, 0); 
    GPIO_PinWrite(GPIO, 0, 11, 0); 

    GPIO_PinWrite(GPIO, 0, 13, 1);
    GPIO_PinWrite(GPIO, 0, 10, 1); 
    GPIO_PinWrite(GPIO, 0, 15, 1);
    GPIO_PinWrite(GPIO, 0, 14, 1);
    GPIO_PinWrite(GPIO, 0, 0, 1);
}

void DIG_2(void)
{   
    GPIO_PinWrite(GPIO, 0, 0, 0);
    GPIO_PinWrite(GPIO, 0, 10, 0);
    GPIO_PinWrite(GPIO, 0, 11, 0); 
    GPIO_PinWrite(GPIO, 0, 14, 0);
    GPIO_PinWrite(GPIO, 0, 15, 0);

    GPIO_PinWrite(GPIO, 0, 6, 1);
    GPIO_PinWrite(GPIO, 0, 13, 1);
}

void DIG_3(void)
{   
    GPIO_PinWrite(GPIO, 0, 6, 0);
    GPIO_PinWrite(GPIO, 0, 10, 0);
    GPIO_PinWrite(GPIO, 0, 11, 0); 
    GPIO_PinWrite(GPIO, 0, 14, 0);
    GPIO_PinWrite(GPIO, 0, 15, 0);

    GPIO_PinWrite(GPIO, 0, 13, 1);
    GPIO_PinWrite(GPIO, 0, 0, 1);
}

void DIG_4(void)
{   
    GPIO_PinWrite(GPIO, 0, 6, 0);
    GPIO_PinWrite(GPIO, 0, 13, 0);
    GPIO_PinWrite(GPIO, 0, 11, 0); 
    GPIO_PinWrite(GPIO, 0, 15, 0);

    GPIO_PinWrite(GPIO, 0, 10, 1); 
    GPIO_PinWrite(GPIO, 0, 14, 1);
    GPIO_PinWrite(GPIO, 0, 0, 1);
}

void DIG_5(void)
{   
    GPIO_PinWrite(GPIO, 0, 6, 0);
    GPIO_PinWrite(GPIO, 0, 13, 0);
    GPIO_PinWrite(GPIO, 0, 10, 0); 
    GPIO_PinWrite(GPIO, 0, 15, 0);
    GPIO_PinWrite(GPIO, 0, 14, 0);

    GPIO_PinWrite(GPIO, 0, 0, 1);
    GPIO_PinWrite(GPIO, 0, 11, 1); 
}

void DIG_6(void)
{   
    GPIO_PinWrite(GPIO, 0, 6, 0);
    GPIO_PinWrite(GPIO, 0, 13, 0);
    GPIO_PinWrite(GPIO, 0, 10, 0); 
    GPIO_PinWrite(GPIO, 0, 15, 0);
    GPIO_PinWrite(GPIO, 0, 14, 0);
    GPIO_PinWrite(GPIO, 0, 0, 0);

    GPIO_PinWrite(GPIO, 0, 11, 1);
}

void DIG_7(void)
{   
    GPIO_PinWrite(GPIO, 0, 6, 0);
    GPIO_PinWrite(GPIO, 0, 10, 0); 
    GPIO_PinWrite(GPIO, 0, 11, 0); 

    GPIO_PinWrite(GPIO, 0, 13, 1);
    GPIO_PinWrite(GPIO, 0, 15, 1);
    GPIO_PinWrite(GPIO, 0, 14, 1);
    GPIO_PinWrite(GPIO, 0, 0, 1);
}

void DIG_8(void)
{   
    GPIO_PinWrite(GPIO, 0, 6, 0);
    GPIO_PinWrite(GPIO, 0, 13, 0);
    GPIO_PinWrite(GPIO, 0, 10, 0); 
    GPIO_PinWrite(GPIO, 0, 15, 0);
    GPIO_PinWrite(GPIO, 0, 14, 0);
    GPIO_PinWrite(GPIO, 0, 0, 0);
    GPIO_PinWrite(GPIO, 0, 11, 0);
}

void DIG_9(void)
{   
    GPIO_PinWrite(GPIO, 0, 13, 0);
    GPIO_PinWrite(GPIO, 0, 10, 0); 
    GPIO_PinWrite(GPIO, 0, 15, 0);
    GPIO_PinWrite(GPIO, 0, 6, 0);
    GPIO_PinWrite(GPIO, 0, 11, 0); 

    GPIO_PinWrite(GPIO, 0, 14, 1);
    GPIO_PinWrite(GPIO, 0, 0, 1);
}

void DIG_0(void)
{   
    GPIO_PinWrite(GPIO, 0, 6, 0);
    GPIO_PinWrite(GPIO, 0, 13, 0);
    GPIO_PinWrite(GPIO, 0, 10, 0); 
    GPIO_PinWrite(GPIO, 0, 15, 1);
    GPIO_PinWrite(GPIO, 0, 14, 0);
    GPIO_PinWrite(GPIO, 0, 0, 0);
    GPIO_PinWrite(GPIO, 0, 11, 0);
}

void DIG_APAGADOS(void)
{
    GPIO_PinWrite(GPIO, 0, 6, 1);
    GPIO_PinWrite(GPIO, 0, 13, 1);
    GPIO_PinWrite(GPIO, 0, 10, 1); 
    GPIO_PinWrite(GPIO, 0, 15, 1);
    GPIO_PinWrite(GPIO, 0, 14, 1);
    GPIO_PinWrite(GPIO, 0, 0, 1);
    GPIO_PinWrite(GPIO, 0, 11, 1);
    GPIO_PinWrite(GPIO, 0, 1, 1);
}

void DIG_PRENDIDOS(void)
{
    GPIO_PinWrite(GPIO, 0, 6, 0);
    GPIO_PinWrite(GPIO, 0, 13, 0);
    GPIO_PinWrite(GPIO, 0, 10, 0); 
    GPIO_PinWrite(GPIO, 0, 15, 0);
    GPIO_PinWrite(GPIO, 0, 14, 0);
    GPIO_PinWrite(GPIO, 0, 0, 0);
    GPIO_PinWrite(GPIO, 0, 11, 0);
    GPIO_PinWrite(GPIO, 0, 1, 0);
}

void DIG_DOT_ON(void)
{
    GPIO_PinWrite(GPIO, 0, 1, 0);
}

void DIG_DOT_OFF(void)
{
    GPIO_PinWrite(GPIO, 0, 1, 1);
}

void SELECT_DIG(int DIG)
{
    switch (DIG)
        {
        case 0:
            DIG_0();
            break;

        case 1:
            DIG_1();
            break;

        case 2:
            DIG_2();
            break;

        case 3:
            DIG_3();
            break;

        case 4:
            DIG_4();
            break;

        case 5:
            DIG_5();
            break;

        case 6:
            DIG_6();
            break;

        case 7:
            DIG_7();
            break;

        case 8:
            DIG_8();
            break;

        case 9:
            DIG_9();
            break;   
        }
}

#endif