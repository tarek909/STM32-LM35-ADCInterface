#include "gpio.h"
#include "stm32f4xx.h"
#include "keypad.h"


const int no_rows = 4;
const int no_cols = 3;
char rows[4]={1,2,3,4}; /*Rows pin numbers*/
char cols[3]={5,6,7}; /*Columns pin numbers*/
char lookupTable[4][3]={{1,2,3},{4,5,6},{7,8,9},{'*',0,'#'}}; /*Keypad Values*/
char currentvalue;/*variable that stores last pressed key*/


void KeyPad_INIT(void)
{
		/* set input and output pins*/

		/* get pins from rows array and set it as output*/
		for (int counter=0; counter<no_rows; counter++)
		{
			/*config row pins as output and push-pull*/
			GPIO_Init(KeypadPort,rows[counter],1,0);
		}
		/* get pins from cols array and set it as input */
		for (int counter=0; counter<no_cols; counter++)
		{
			/*config column pins as input and internal pull up resistor*/
			GPIO_Init(KeypadPort,cols[counter],0,1);
		}
}


void KeyPad_MANAGE(void)
{
	/*Loop on Rows and set one of them Low*/
	for(int RowCounter=0; RowCounter<no_rows;RowCounter++)
	{
		/*Set all rows High*/
		for(int RowCounter2=0;RowCounter2<no_rows;RowCounter2++)
			GPIO_Write(KeypadPort,rows[RowCounter2],1);
		/*Set one row Low*/
		GPIO_Write(KeypadPort,rows[RowCounter],0);

		/*Loop on columns to find the Low column*/
		for(int ColCounter=0;ColCounter<no_cols;ColCounter++)
		{
			/*if a key is pressed*/
			if(!GPIO_Read(KeypadPort,cols[ColCounter]))
			{
				for(int i =0;i<240000;i++); //30msec delay (clock=8Mhz)
				if(!GPIO_Read(KeypadPort,cols[ColCounter])) /*second check for keypad debouncing*/
				{
				/*use row and column index to store key*/
				currentvalue=lookupTable[RowCounter][ColCounter];
				/*wait till button is released*/
				while(!GPIO_Read(KeypadPort,cols[ColCounter]));
				}
			}
		}
	}
}


char KeyPad_GET_VALUE(void)
{
	return currentvalue;
}


char KeypadCallouts_KeyPressNotificaton(void)
{
	for(int ColCounter=0;ColCounter<no_cols;ColCounter++){
		if(GPIO_Read(KeypadPort,cols[ColCounter]))
				{
					return 1;
				}
	}
	return 0;
}

