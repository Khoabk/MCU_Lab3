/*i
 * input_processing.c
 *
 *  Created on: Oct 12, 2021
 *      Author: dang khoa
 */

#include "input_reading.h"
#include "main.h"




#define DURATION_FOR_AUTO_INCREASING  2
#define BUTTON_IS_PRESSED       GPIO_PIN_RESET
#define BUTTON_IS_RELEASED      GPIO_PIN_SET


int process[number_of_button]={0,0,0};

int released=1;


static uint16_t pin_pos[number_of_button]={GPIO_PIN_13,GPIO_PIN_14,GPIO_PIN_15};




static int button_state1[number_of_button]={1,1,1};
static int button_state2[number_of_button]={1,1,1};

static int button_current_state[number_of_button]={0,0,0};

static uint16_t counterForButtonPress[number_of_button]={0,0,0};


void button_reading(int select_button)
{

	//select_button%=3;

	button_state1[select_button] = button_state2[select_button];

	button_state2[select_button]=HAL_GPIO_ReadPin(GPIOA, pin_pos[select_button]);


	if(button_state2[select_button]==button_state1[select_button])
	{

		counterForButtonPress[select_button]++;

		if(counterForButtonPress[select_button]>=DURATION_FOR_AUTO_INCREASING)
		{
			button_current_state[select_button]=button_state2[select_button];

			if(button_current_state[select_button]==BUTTON_IS_RELEASED)
			{
				released=1;
			}

		}

	}
	else
	{

		counterForButtonPress[select_button]=0;
		button_current_state[select_button]=0;



	}
}


unsigned char is_button_pressed(uint8_t index)
{

	if(index >= number_of_button) return 0xff;
	return (button_current_state[index]==BUTTON_IS_PRESSED && process[index]);

}



void reset(int button_select)
{

	process[button_select]=0;

}
