#ifndef init_clcd_congfig_h
#define init_clcd_congfig_h

#define eight_bit_two_line_display write_lcd(0x38, CMD_MODE)
#define cursor_on write_lcd(0x0E, CMD_MODE)
#define cursor_off write_lcd(0x0C, CMD_MODE)
#define cursor_blink write_lcd(0x0F, CMD_MODE)
#define clear_display write_lcd(0x01, CMD_MODE)
#define entry_mode write_lcd(0x06, CMD_MODE)
#define line1_home 0x80
#define line2_home 0xC0

void init_clcd_config(void);

#endif
