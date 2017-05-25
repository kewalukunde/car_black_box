#ifndef main_h
#define main_h

#include <xc.h>
#include <string.h>
#include "init_clcd_config.h"
#include "init_mkp_config.h"
#include "init_ADC_config.h"
#include "init_timer0_config.h"
#include "scan_matrix_keypad.h"
#include "delay.h"
#include "clcd.h"
#include "ADC.h"
#include "EEPROM.h"
#include "functions.h"
#include "display.h"

enum stats
{
		  START_SCREEN,
		  PASSWORD,
		  MAIN_MENU,
		  DISPLAY_LOG,
		  DISPLAY_TIME
};

char log[10][17];
unsigned short data, count,E_count,E_time;
int k, i, j,log_itr;
unsigned char key,state = START_SCREEN;
unsigned short gear;
char message[] = "E   TIME   G SPD";
char counter[] = "0 00:00:00 0 000";

#endif
