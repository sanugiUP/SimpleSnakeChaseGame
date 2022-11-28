/*FILE: terminal.c
AUTHOR: - 
UNIT: COMP1000
PURPOSE: to enable and disable buffering in the terminal
LAST MOD: 2021-09-01 
COMMENT: this file was provided by Curtin University*/

#include<stdio.h>
#include<termios.h>
#include"terminal.h"

/*NAME: disableBuffer
PURPOSE: The function disables buffering on the terminal
IMPORTS: none
EXPORTS: none
REMARKS: none*/
void disableBuffer()
{
    struct termios mode;

    tcgetattr(0, &mode);
    mode.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(0, TCSANOW, &mode);
}


/*NAME: enableBuffer
PURPOSE: The function enables buffering on the terminal
IMPORTS: none
EXPORTS: none
REMARKS: none*/
void enableBuffer()
{
    struct termios mode;

    tcgetattr(0, &mode);
    mode.c_lflag |= (ECHO | ICANON);
    tcsetattr(0, TCSANOW, &mode);
}
