/*
 * input_processing.h
 *
 *  Created on: Oct 12, 2021
 *      Author: dang khoa
 */



#include "main.h"

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#define number_of_button 3

extern int process[number_of_button];

extern int released;

void button_reading(int select_button);

unsigned char is_button_pressed(uint8_t index);

void reset(int button_select);

#endif /* INC_INPUT_READING_H_ */
