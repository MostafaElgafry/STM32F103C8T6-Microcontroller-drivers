/*
*Author     : Moustafa ElGafry
*Date       : 14 AUG 2020
*Version    : V01
*/

#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H

/* RCC clock source Options:    
				RCC_HSE_CRYSTAL
				RCC_HSE_RC
				RCC_HSI
				RCC_PLL                      */				
#define RCC_CLOCK_TYPE       RCC_HSE_CRYSTAL

/*RCC PLL input Options:
				RCC_PLL_IN_HSI
				RCC_PLL_IN_HSE
				RCC_PLL_IN_HSE_DIV_2
*/
/*Note: Select Value only if you have PLL as input clock source*/
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT        RCC_PLL_IN_HSE_DIV_2
#endif

/*RCC Multiplication Options : 
				2 to 16 
*/
/*Note: Select Value only if you have PLL as input clock source*/
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_MUL_VAL      4
#endif


#endif
