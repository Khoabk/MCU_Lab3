/*
 * output_display.h
 *
 *  Created on: Oct 14, 2021
 *      Author: dang khoa
 */


#include "input_processing.h"

#ifndef INC_OUTPUT_DISPLAY_H_
#define INC_OUTPUT_DISPLAY_H_


//extern int upper_bound[No_led];

void update7Seg(State mode);


void Increase_time(State mode);

void Set_time(State mode);

void assign(void);

void count_down(void);

#endif /* INC_OUTPUT_DISPLAY_H_ */
