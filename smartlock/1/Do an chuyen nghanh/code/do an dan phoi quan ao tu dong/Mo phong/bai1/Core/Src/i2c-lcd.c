/** 
Edit by modify: Ngoc Hang 
**/

#include "i2c-lcd.h"
extern I2C_HandleTypeDef hi2c1;  // change your handler here accordingly

#define SLAVE_ADDRESS_LCD 0x4E //0x7E change this according to ur setup

void lcd_send_cmd (char cmd)
{
  char data_u, data_l;
	uint8_t data_t[4];
	data_u = (cmd&0xf0);
	data_l = ((cmd<<4)&0xf0);
	data_t[0] = data_u|0x0C;  //en=1, rs=0
	data_t[1] = data_u|0x08;  //en=0, rs=0
	data_t[2] = data_l|0x0C;  //en=1, rs=0
	data_t[3] = data_l|0x08;  //en=0, rs=0
	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
}

void lcd_send_data (char data)
{
	char data_u, data_l;
	uint8_t data_t[4];
	data_u = (data&0xf0);
	data_l = ((data<<4)&0xf0);
	data_t[0] = data_u|0x0D;  //en=1, rs=0
	data_t[1] = data_u|0x09;  //en=0, rs=0
	data_t[2] = data_l|0x0D;  //en=1, rs=0
	data_t[3] = data_l|0x09;  //en=0, rs=0
	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
}

void lcd_init (void)
{
	HAL_Delay(50);
	lcd_send_cmd (0x30); /* set 4-bits interface */
	HAL_Delay(5);
	lcd_send_cmd (0x30); /* start to set LCD function */
	HAL_Delay(1);
	lcd_send_cmd (0x30); /* clear display */
	HAL_Delay(10);
	lcd_send_cmd (0x020); /* set entry mode */
	HAL_Delay(10);
	
	
	
	lcd_send_cmd (0x28); /* set display to on */	
	HAL_Delay(1);
	lcd_send_cmd (0x08); /* move cursor to home and set data address to 0 */
	HAL_Delay(1);
	lcd_send_cmd (0x01);
	HAL_Delay(1);
	HAL_Delay(1);
	lcd_send_cmd (0x06); /* move cursor to home and set data address to 0 */
	HAL_Delay(1);
	lcd_send_cmd (0x0C);
	
}

void lcd_send_string (char *str)
{
	while (*str) lcd_send_data (*str++);
}

void lcd_clear_display (void)
{
	lcd_send_cmd (0x80); //clear display
	for (int i=0;i<70;i++){
		lcd_send_data(' ');
}
}
void lcd_goto_XY (int row, int col)
{
	uint8_t pos_Addr;
	if(row == 1) 
	{
		pos_Addr = 0x80 + row - 1 + col;
	}
	else
	{
		pos_Addr = 0x80 | (0x40 + col);
	}
	lcd_send_cmd(pos_Addr);
}
