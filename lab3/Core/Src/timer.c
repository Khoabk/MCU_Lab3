/*
 * timer.c
 *
 *  Created on: Oct 11, 2021
 *      Author: dang khoa
 */


#include <input_reading.h>
#include "main.h"
#include "timer.h"


int button;

int timer_counter[No_timer]={10,20,500};
int timer_bound[No_timer]={10,20,500};
int timer_flag[No_timer]={0,0,0};
static int timer_cycle=10;



void set_Timer(int timer){

	if(timer>=No_timer)return;

	timer_counter[timer] = timer_bound[timer]/ (timer_cycle);
	
	timer_flag[timer] =0;

}


void timer_run()
{

	for(int i=0; i< No_timer; i++)
	{
		timer_counter[i]=(timer_counter[i]==0)?0:timer_counter[i]-1;

		timer_flag[i]=(timer_counter[i]==0)?1:0;
	}

}



