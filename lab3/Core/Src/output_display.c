/*
 * output_display.c
 *
 *  Created on: Oct 14, 2021
 *      Author: dang khoa
 */


#include "main.h"
#include "output_display.h"
#include "input_processing.h"


#define width  4
#define height 4

#define No_led 3

//								R G Y
static int upper_bound[No_led]={6 ,3,2};





static int traffic_light1_state=0;
static int traffic_light2_state=1;



static int output_buffer[height][width]={{0,0,0,0},
									   	{0,0,0,1},
										{0,0,0,2},
										{0,0,0,3}};


static int seven_seg_transis=0;


uint16_t switch_pins[width]={1<<0,1<<1,1<<2,1<<3};



uint16_t num_array[10]={0x3f,0x6,0x5b,0x4f,0x66,0x6d,0x7d,0x7,0x7f,0x6f};


static int sum1;
static int sum2;




static void display7SEG(int num)
{

		num %= 10;

		GPIOB->ODR |= (0x7f<<9);

		GPIOB->ODR &= ~(num_array[num]<<9);

}



void update7Seg(State mode)
{
	GPIOB->ODR |= (0xf<<0);

	display7SEG(output_buffer[mode][seven_seg_transis]);
	GPIOB->ODR &= ~(switch_pins[seven_seg_transis]);

	seven_seg_transis=(seven_seg_transis+1)%width;
}



void Increase_time(State mode)
{
	output_buffer[mode][1]++;
	output_buffer[mode][0]+=(output_buffer[mode][1]/10);
	output_buffer[mode][1]%=10;
	output_buffer[mode][0]%=10;
}


void Set_time(State mode)
{

	if(mode == NORMAL)
	{
		traffic_light1_state=0;
	    traffic_light2_state=1;

	}

	upper_bound[mode-1]= output_buffer[mode][0]*10+ output_buffer[mode][1];

}






void display_LED(int sth, int side)
{
	int offset= (side==0)?1:7;

	GPIOA->ODR |=(0x3f<<offset);

	GPIOA->ODR &=~(0x9<<(offset+sth));

}




void assign(void)
{

	traffic_light1_state=0;
	traffic_light2_state=1;

	display_LED(traffic_light1_state, 0);
	display_LED(traffic_light2_state, 1);

	output_buffer[0][0]=upper_bound[traffic_light1_state]/10;
	output_buffer[0][1]=upper_bound[traffic_light1_state]%10;

	output_buffer[0][2]=upper_bound[traffic_light2_state]/10;
	output_buffer[0][3]=upper_bound[traffic_light2_state]%10;

}







void count_down(void)
{



	if((output_buffer[0][0]*10 + output_buffer[0][1] - 1)<0)
	{
		traffic_light1_state=(traffic_light1_state+1)%3;
		sum1=upper_bound[traffic_light1_state];
		display_LED(traffic_light1_state,0);
	}
	else sum1= (output_buffer[0][0]*10 + output_buffer[0][1] - 1);


	output_buffer[0][0]=sum1/10;
	output_buffer[0][1]=sum1%10;



	if((output_buffer[0][2]*10 + output_buffer[0][3] - 1)<0)
	{
		traffic_light2_state=(traffic_light2_state+1)%3;
		sum2=upper_bound[traffic_light2_state];
		display_LED(traffic_light2_state,1);
	}
	else sum2= (output_buffer[0][2]*10 + output_buffer[0][3] - 1);


	output_buffer[0][2]=sum2/10;
	output_buffer[0][3]=sum2%10;



}







