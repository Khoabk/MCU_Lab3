#include "main.h"
#include "input_reading.h"
#include "input_processing.h"
#include "output_display.h"
#include "timer.h"



State prev_mode = NORMAL;
State current_state= NORMAL;

static int set =0;
static int incre_flag=0;


void fsm_for_input_processing(void)
{

        if(timer_flag[0])
	{
		set_Timer(0);
		update7Seg(prev_mode);
	}


	switch(current_state)
	{

	case NORMAL:
	{

		if(timer_flag[2])
		{
			set_Timer(2);
			count_down();
		}

		if(is_button_pressed(0))
		{
			set_Timer(1);
			GPIOA->ODR = (0x1249<<1);
			reset(0);
			current_state= MODE1;
			prev_mode= MODE1;
			return;
		}

		if(is_button_pressed(2))
		{
			assign();
		}

		return;
	}
	case MODE1:
	case MODE2:
	case MODE3:
	{
		
		if(timer_flag[1])
		{
			set_Timer(1);
			GPIOA->ODR ^= (0x1249<<prev_mode);
		}

		if(is_button_pressed(0))
		{
			reset(0);
			current_state= (current_state+1)%4;
			prev_mode= current_state;
			GPIOA->ODR = (0x1249<<(prev_mode));
			return;
		}

		if(is_button_pressed(1))
		{
			reset(1);
			current_state=INCREMENT;
			incre_flag=1;
			return;
		}

		if(is_button_pressed(2))
		{
			reset(2);
			current_state= SETT;
			set=1;
			return;
		}

		return;
	}
	case INCREMENT:
	{
		if(timer_flag[1])
		{
			set_Timer(1);
			GPIOA->ODR ^= (0x1249<<prev_mode);
		}

		if(incre_flag)
		{
			//increment code
			Increase_time(prev_mode);
			incre_flag=0;
		}

		if(is_button_pressed(1))
		{
			reset(1);

			incre_flag=1;

			return;
		}

		if(is_button_pressed(0))
		{
			reset(0);
			prev_mode=((prev_mode+1)%4);
			current_state=prev_mode;
			GPIOA->ODR = (0x1249<<(prev_mode));
			return;
		}
		if(is_button_pressed(2))
		{
			reset(2);
			current_state= SETT;
			set=1;
			return;
		}

		return;
	}
	case SETT:
	{

		if(timer_flag[1])
		{
			set_Timer(1);
			GPIOA->ODR ^= (0x1249<<prev_mode);
		}

		if(set)
		{
			//setting code
			Set_time(prev_mode);
			set=0;
		}


		if(is_button_pressed(2))
		{
			reset(2);
			current_state= NORMAL;
			prev_mode=NORMAL;
			return;
		}

		if(is_button_pressed(1))
		{
			reset(1);
			current_state=INCREMENT;
			incre_flag=1;
			return;
		}

		if(is_button_pressed(0))
		{

			reset(0);
			prev_mode=((prev_mode+1)%4);
			current_state=prev_mode;
			GPIOA->ODR = (0x1249<<(prev_mode));
			return;
		}

		return;
	}
	default: break;

	}

}
