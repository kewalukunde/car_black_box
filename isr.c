#include "main.h"
extern unsigned short count;

void interrupt isr(void)
{
		  unsigned short p,q;

		  if (TMR0IF == 1)
		  {
					 TMR0IF = 0;
					 count++;
					 E_time++;
		  }

		  if (count == 5)
		  {
					 //increments the last value
					 counter[9]++;
					 //checks for the every digit
					 for (p = 9; p >= 2; p--)
					 {
								/* for incrementing the timer 0-9 */
								if (p == 6 || p == 9)
								{
										  if (counter[p] > '9')
										  {
													 counter[p] = '0';
													 counter[p - 1]++;
										  }
								}
								/* For incrementing the timer 0-5 */
								else if (p == 5 || p == 8)
								{
										  if (counter[p] > '5')
										  {
													 counter[p] = '0';
													 counter[p - 2]++;
										  }
								}
								/* for HH */
								else if (p == 3)
								{
										  /* FOR 24hrs */
										  if (counter[p - 1] == '2')
										  {
													 if (counter[p] > '3')
													 {
																counter[p] = '0';
																counter[p - 1]++;
													 }
										  }
										  else
										  {
													 if (counter[p] > '9')
													 {
																counter[p] = '0';
																counter[p - 1]++;
													 }
										  }
								}
								/* make 00 if gets 24 */
								else if (p == 2)
								{
										  if (counter[p] > '2')
										  {
													 counter[p] = '0';
										  }
								}
					 }
					 count = 0;
		  }

		  if (E_time == 50)
		  {
					 write_internal_eeprom(0x00,log_itr%10+'0');
                                         E_count = 0x00;

					 for(p = 0;p < log_itr; p++)
					 {
								for(q = 0;q < 16; q++)
										  write_internal_eeprom(E_count += 1,log[p][q]);
					 }
					 
					 E_got = 0;
					 E_time = 0;
		  }
}
