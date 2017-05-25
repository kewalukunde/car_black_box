#include "main.h"

void display(void)
{
		  static unsigned short pot = 50;
		  unsigned short data_tmp;
		  /* Potentiometer */

		  if (!pot--)
		  {
					 pot = 50;
					 data = adc() >> 2;
					 data_tmp = data;
					 for (k = 15; k >= 13; k--)
					 {
								/* convert the result into ASCII  */
								counter[k] = (data_tmp % 10) + '0';
								data_tmp = data_tmp / 10;
					 }
		  }

		  if (counter[13] == '0' && counter[14] == '0' && counter[15] == '0')
		  {
					 counter[0] = 'F';
		  }
		  else
		  {
					 counter[0] = 'O';
		  }

		  counter[11] = (gear % 10) + '0';

		  puts(line1_home, message);
		  puts(line2_home, counter);
}
