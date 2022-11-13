//Author	:		Mohamed Gamal
//Date		:		19-August-2020
//Version	:		V01
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidInit(void){
	#define SCB_AIRCR		*((volatile u32*)(0xE000ED0C))
	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION;
}

void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber){
	if (Copy_u8IntNumber <=31)
		NVIC_ISER0 = (1<< Copy_u8IntNumber);
	else if(Copy_u8IntNumber <=59)
		NVIC_ISER1 = ( 1 << (Copy_u8IntNumber-32));
	else{
		//return error
	}
}

void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber){
	
	if (Copy_u8IntNumber <=31)
		NVIC_ICER0 = (1<< Copy_u8IntNumber);
	else if(Copy_u8IntNumber <=59)
		NVIC_ICER1 = ( 1 << (Copy_u8IntNumber-32));
	else {
		//return error
	}
}

void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber){
	if (Copy_u8IntNumber <=31)
		NVIC_ISPR0 = (1<< Copy_u8IntNumber);
	else if(Copy_u8IntNumber <=59)
		NVIC_ISPR1 = ( 1 << (Copy_u8IntNumber-32));
	else {
		//return error
	}
}

void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber){
	if (Copy_u8IntNumber <=31)
		NVIC_ICPR0 = (1<< Copy_u8IntNumber);
	else if(Copy_u8IntNumber <=59)
		NVIC_ICPR1 = ( 1 << (Copy_u8IntNumber-32));
	else {
		//return error
	}
}
u8	 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber){
	u8 LOC_NVICResult = 0;
	if (Copy_u8IntNumber <=31)
		LOC_NVICResult = GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
	else if(Copy_u8IntNumber <=59)
		LOC_NVICResult = GET_BIT(NVIC_IABR1,Copy_u8IntNumber);
	else {
		//return error
	}
	return LOC_NVICResult;
}

void MNVIC_voidSetPriority(s8 Copy_s8IntID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority, u32 Copy_u32Group ){
	u8 Local_u8Priority =  Copy_u8SubPriority | Copy_u8GroupPriority << ( (MNVIC_GROUP_SUB_DISTRIBUTION - 0x05FA0300) / 256 )  ;
	/*check if core peripheral*/
	
	/*else, external peripheral*/
	if (Copy_s8IntID >= 0){
		NVIC_IPR[Copy_s8IntID] = Local_u8Priority << 4;
	}
	//SCB_AIRCR	= Copy_u32Group;
}
