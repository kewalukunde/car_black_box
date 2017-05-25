/*
 * =====================================================================================
 *
 *       Filename:  functions.c
 *        Created:  Tuesday 16 May 2017 02:04:21  IST
 *         Author:  KEWAL UKUNDE , kewalukunde@gmail.com
 *   Organization:  Emertxe technology banglore
 *
 * =====================================================================================
 */


#include "main.h"

char password[] = "1111";
/* password enter function */
int password_enter()
{
  		  clear_display;
		  char enter_pass[] = "    ";
		  int k = 0;
		  /* loop to get password */
		  while (k < 4)
		  {
					 delay(600);
					 puts(line1_home," ENTER PASSWORD ");
					 puts(line2_home+5,enter_pass);
					 key = scan_matrix_keypad();
					 write_lcd(0xC0+5+k,CMD_MODE); 
					 /* increment number */
					 if (key == '1')
					 {
								if (enter_pass[k] == ' ')
										  enter_pass[k] = 47;

								enter_pass[k]++;
								if (enter_pass[k] == ':')
										  enter_pass[k] = '0';
					 }
					 /* decrement number */
					 else if (key == '2')
					 {					
								if (enter_pass[k] == ' ')
										  enter_pass[k] = ':';

								enter_pass[k]--;
								if (enter_pass[k] == 47)
										  enter_pass[k] = '9';
					 }
					 /* change cursor */
					 else if (key == '3')	
								k++;
					 if (key == '7')
								return START_SCREEN;
		  }	

		  /* if password correct enter into main menu */
		  if (!strcmp(password,enter_pass))
					 return MAIN_MENU;
		  /* if wrong re_enter password */
		  else 
		  {
					 k = 0;
					 puts(line2_home,"#WORNG PASSWORD#");
					 delay(2500);
					 return PASSWORD;
		  }
}

int main_menu_func()
{ 
		  static char s_select = 0;
		  puts(line1_home,"   MAIN MENU    ");

		  delay(700);
		  key = scan_matrix_keypad();

		  /* select maenu option */
		  if ((key == '1') && (!s_select) )
					 s_select = 1;
		  else if ((key == '1') && (s_select) )
					 s_select = 0;

		  /* display selected option */
		  if(!s_select)
					 puts(line2_home,"*1) Log  2) Time");
		  else
					 puts(line2_home," 1) Log *2) Time");

        /* according to selected menu change state */
		  if ((key == '3') && (!s_select))
		  {	
					 clear_display;
					 return DISPLAY_LOG;
		  }
		  if ((key == '3') && (s_select))
		  {
					 clear_display;
					 return DISPLAY_TIME;
		  }
}

int set_time()
{
        char temp_time[] = "    00:00:00    ";
		  puts(line1_home,"#   SET TIME   #");
			
		  k = 4;
		  while (k < 12)
		  {
					 key = scan_matrix_keypad();
					 delay(650);
					
					 /* incress number */
					 if (key == '1')
					 {
								temp_time[k]++;
								if (temp_time[k]== ':')
										  temp_time[k] = '0';
					 }
					 /* decress number */
					 else if (key == '2')
					 {					
								temp_time[k]--;
								if (temp_time[k] == 47)
										  temp_time[k] = '9';
					 }
					 /* change cursor */
					 else if (key == '3')
					 {
								k++;
								if ((k == 6)||(k == 9))
										  k++;
					 }
					 /* back to orevious menu */
					 if (key == '7')
								return MAIN_MENU;
					 
					 puts(line2_home,temp_time);
					 write_lcd(0xC0+k,CMD_MODE); 
		  }

		  /* copy date at start screen */
		  for (k = 2; k < 10 ; k++)
					 counter[k] = temp_time[k+2];
		  return MAIN_MENU;
}

int display_log()
{
		  k = 0;
		  while (log_itr >= 0)
		  {
		          puts(line1_home,"N   TIME   G SPD");
					 puts(line2_home,log[k]);
					 key = scan_matrix_keypad();
					 delay(700);
					
					 /* change log number */
					 if ((key == '1') && (k < log_itr))
								k++;
					 else if ((key == '2') && (k > 0))
								k--;
					 if (key == '7')
								return MAIN_MENU;
		  }
}
