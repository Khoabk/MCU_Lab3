/*
 * timer.h
 *
 *  Created on: Oct 11, 2021
 *      Author: dang khoa
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_


//extern enum Button{Button1, Button2, Button3};

#define Button1     0
#define Button2     1
#define Button3     2

#define No_timer  3

extern int button;




extern int timer_counter[No_timer];
extern int timer_bound[No_timer];
extern int timer_flag[No_timer];


void set_Timer(int timer);
void timer_run(void);



//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef * htim);

#endif /* INC_TIMER_H_ */
