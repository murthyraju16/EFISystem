    /******************************************************************************
    * File Name: EFI_PWM.c
    * Description:  This file contains the set up for fast-PWM mode
    ******************************************************************************/
    /******************************************************************************
    *                      Includes
    ******************************************************************************/
    #include"EFI_PWM.h"
    #include<avr/io.h>
    #include"avr/interrupt.h"
    /******************************************************************************
    *                      Defines and data types
    ******************************************************************************/


    /******************************************************************************
    *                      Global variables
    ******************************************************************************/

    /******************************************************************************
    *                      Static variables
    ******************************************************************************/
    /******************************************************************************
    *                      Internal function prototypes
    ******************************************************************************/
    /******************************************************************************
    *                      Public functions
    ******************************************************************************/
    void PWM_setup()
    {
    TCCR0A|= ((1<<WGM01) | (1<<WGM00));  /* fast pwm mode*/
    TCCR0A|= (1<< COM0A1); /* non inverting mode  and clear OC0A on compare match*/
    TCCR0A&= ~(1<<COM0A0);

    TCNT0=0x00;   /*Timer counter register*/
    OCR0A=0x00;
    sei();       /* Global interrupt*/
    }

    void PWM_EFI(float time_val)
    {
        OCR0A = (time_val/0.080)*(255.0);
        /* TIme period of each pulse is 80 msec */
        /* for respective injection duration in msec the duty cycle will be adjusted accordingly by the above formula */
    }

    void PWM_enable()
    {
        TCCR0B|= ((1<<CS00)); /*clock and WGM02*/
        TCCR0B&=~(1<<CS01);
        TCCR0B|=(1<<CS02);      /*101    // timer is on*/
    }

    void PWM_disable(){

       TCCR0B&=0X00;        /* clock freq is 0 */

    }


    /******************************************************************************
    *                      Internal functions
    ******************************************************************************/

    /******************************************************************************
    *                      End of File
    ******************************************************************************/
