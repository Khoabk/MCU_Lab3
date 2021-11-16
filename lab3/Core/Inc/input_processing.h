/*
 * input_processing.h
 *
 *  Created on: Oct 13, 2021
 *      Author: dang khoa
 */

#ifndef INC_INPUT_PROCESSING_H_
#define INC_INPUT_PROCESSING_H_


typedef enum
{
	NORMAL,
	MODE1,
	MODE2,
	MODE3,
	INCREMENT,
	SETT
}State;


extern  State prev_mode;

void fsm_for_input_processing(void);


#endif /* INC_INPUT_PROCESSING_H_ */
