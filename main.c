#include "main.h"

void init_config()
{
		  init_clcd_config();
		  init_mkp_config();
		  init_timer0_config();
		  init_ADC_config();
}

void main()
{
		  init_config();
#if 0
		  /* init EEPROM to 0 */
		  unsigned char *ptr = 0x00;
		  while ((*ptr++) != 0xFF)
					 write_internal_eeprom(*ptr,'0');
#else
		  /* if EEPROM have data copy it */
		  if (read_internal_eeprom(0x00) != '0')
		  {
					 puts(line1_home," READING EEPROM ");
					 delay(3000);
					 char str[17];
					 E_count = 0x00;
					 log_itr = (read_internal_eeprom(0x00) - '0');
					 for (i = 0;i < log_itr; i++ )
					 {
								for (j = 0;j < 16; j++ )
										  str[j] = read_internal_eeprom(E_count += 1);
								str[16] = '\0';
								strcpy(log[i],str);
					 }
		  }

		  while (1)
		  {
					 /* scan key for input */
					 key = scan_matrix_keypad();

					 /* condition if user try to enter in system */
					 if (((key == '1') && (state == START_SCREEN)) || (state == PASSWORD))
								state = password_enter();
					 /* gaer up */
					 else if ((key == '5') && (gear < 4))
					 {
								gear++;
								delay(700);
					 }
					 /* gaer down */
					 else if ((key == '6') && (gear > 0))
					 {
								gear--;
								delay(700);
					 }
					 /* back to previous menu */
					 else if (key == '7')
					 {
								if((state == DISPLAY_TIME) || (state == DISPLAY_LOG))
										  state = MAIN_MENU;
								else if((state == MAIN_MENU) || (state == PASSWORD))
										  state = START_SCREEN;
					 }
					 /* collission make */
					 else if (key == '8')
					 {
								store_log();
					 }
					 else if (state == START_SCREEN)
								display();
					 else if (state == MAIN_MENU)
								state = main_menu_func();
					 else if (state == DISPLAY_LOG)
								state = display_log();
					 else if (state == DISPLAY_TIME)
								state = set_time();

					 if (!E_got)
					 {
								E_got = 1;
								/* speed limit defination */
								if (((gear == 1) && (data > 30)) || ((gear == 2)&&(data < 10 || data > 50)) || ((gear == 3)&&(data < 20 || data > 80)) || ((gear == 4)&&(data < 30 && data > 120)))
								{
										  store_log();
								}
					 }

		  }
#endif
}

