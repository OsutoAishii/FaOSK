// Filename:  keyboard.c
// Description:  键盘处理函数
// Compiler:  gcc

#include "keyboard.h"

unsigned char data_hander(unsigned char be_data)
{
    unsigned char af_data = '\0';
    if(shift == 0 && capslock ==0)
    {
        switch (be_data)
	    {
            case 0x02:af_data = '1'; break;
            case 0x03:af_data = '2'; break;
            case 0x04:af_data = '3'; break;
            case 0x05:af_data = '4'; break;
            case 0x06:af_data = '5'; break;
            case 0x07:af_data = '6'; break;
            case 0x08:af_data = '7'; break;
            case 0x09:af_data = '8'; break;
            case 0x0a:af_data = '9'; break;
            case 0x0b:af_data = '0'; break;

            case 0x0c:af_data = '-'; break;
            case 0x0d:af_data = '='; break;
            case 0x0e:af_data = '\b'; break;
            case 0x0f:af_data = '\t'; break;

            case 0x10:af_data = 'q'; break;
            case 0x11:af_data = 'w'; break;
            case 0x12:af_data = 'e'; break;
            case 0x13:af_data = 'r'; break;
            case 0x14:af_data = 't'; break;
            case 0x15:af_data = 'y'; break;
            case 0x16:af_data = 'u'; break;
            case 0x17:af_data = 'i'; break;
            case 0x18:af_data = 'o'; break;
            case 0x19:af_data = 'p'; break;

            case 0x1a:af_data = '['; break;
            case 0x1b:af_data = ']'; break;
            case 0x1c:af_data = '\n'; break;

            //case 0x1d:af_data = ''; break;
            case 0x1e:af_data = 'a'; break;
            case 0x1f:af_data = 's'; break;
            case 0x20:af_data = 'd'; break;
            case 0x21:af_data = 'f'; break;
            case 0x22:af_data = 'g'; break;
            case 0x23:af_data = 'h'; break;
            case 0x24:af_data = 'j'; break;
            case 0x25:af_data = 'k'; break;
            case 0x26:af_data = 'l'; break;

            case 0x27:af_data = ';'; break;
            case 0x28:af_data = '\''; break;
            case 0x29:af_data = '`'; break;

            //左shift按下时
            case 0x2a:shift = 1; break;

            case 0x2b:af_data = '\\'; break;

            case 0x2c:af_data = 'z'; break;
            case 0x2d:af_data = 'x'; break;
            case 0x2e:af_data = 'c'; break;
            case 0x2f:af_data = 'v'; break;
            case 0x30:af_data = 'b'; break;
            case 0x31:af_data = 'n'; break;
            case 0x32:af_data = 'm'; break;

            case 0x33:af_data = ','; break;
            case 0x34:af_data = '.'; break;
            case 0x35:af_data = '/'; break;
            
            //右shift按下时
            case 0x36:shift = 1; break;

            case 0x37:af_data = '*'; break;
            //case 0x38:af_data = ''; break;
            case 0x39:af_data = ' '; break;

            //capslock按下时
            case 0x3a:capslock = 1; break;

            //case 0x3b:af_data = ''; break;
            //case 0x3c:af_data = ''; break;
            //case 0x3d:af_data = ''; break;
            //case 0x3e:af_data = ''; break;
            //case 0x3f:af_data = ''; break;
            //case 0x40:af_data = ''; break;
            //case 0x41:af_data = ''; break;
            //case 0x42:af_data = ''; break;
            //case 0x43:af_data = ''; break;
            //case 0x44:af_data = ''; break;

            //case 0x45:af_data = ''; break;
            //case 0x46:af_data = ''; break;

            case 0x47:af_data = '7'; break;
            case 0x48:af_data = '8'; break;
            case 0x49:af_data = '9'; break;
            case 0x4a:af_data = '-'; break;
            case 0x4b:af_data = '4'; break;
            case 0x4c:af_data = '5'; break;
            case 0x4d:af_data = '6'; break;
            case 0x4e:af_data = '+'; break;
            case 0x4f:af_data = '1'; break;
            case 0x50:af_data = '2'; break;
            case 0x51:af_data = '3'; break;
            case 0x52:af_data = '0'; break;
            case 0x53:af_data = '.'; break;

            //case 0x54:af_data = ''; break;

            //case 0x57:af_data = ''; break;
            //case 0x58:af_data = ''; break;

            case 0x73:af_data = '_'; break;

            case 0x7d:af_data = '\\'; break;

            default:break;
	    }
    }
    else if((shift ==1 && capslock ==0) || (shift ==1 && capslock ==1))
    {
        switch (be_data)
	    {
            case 0x02:af_data = '!'; break;
            case 0x03:af_data = '@'; break;
            case 0x04:af_data = '#'; break;
            case 0x05:af_data = '$'; break;
            case 0x06:af_data = '%'; break;
            case 0x07:af_data = '^'; break;
            case 0x08:af_data = '&'; break;
            case 0x09:af_data = '*'; break;
            case 0x0a:af_data = '('; break;
            case 0x0b:af_data = ')'; break;

            case 0x0c:af_data = '_'; break;
            case 0x0d:af_data = '+'; break;
            case 0x0e:af_data = '\b'; break;
            case 0x0f:af_data = '\t'; break;

            case 0x10:af_data = 'Q'; break;
            case 0x11:af_data = 'W'; break;
            case 0x12:af_data = 'E'; break;
            case 0x13:af_data = 'R'; break;
            case 0x14:af_data = 'T'; break;
            case 0x15:af_data = 'Y'; break;
            case 0x16:af_data = 'U'; break;
            case 0x17:af_data = 'I'; break;
            case 0x18:af_data = 'O'; break;
            case 0x19:af_data = 'P'; break;

            case 0x1a:af_data = '{'; break;
            case 0x1b:af_data = '}'; break;
            case 0x1c:af_data = '\n'; break;

            //case 0x1d:af_data = ''; break;
            case 0x1e:af_data = 'A'; break;
            case 0x1f:af_data = 'S'; break;
            case 0x20:af_data = 'D'; break;
            case 0x21:af_data = 'F'; break;
            case 0x22:af_data = 'G'; break;
            case 0x23:af_data = 'H'; break;
            case 0x24:af_data = 'J'; break;
            case 0x25:af_data = 'K'; break;
            case 0x26:af_data = 'L'; break;

            case 0x27:af_data = ':'; break;
            case 0x28:af_data = '\"'; break;
            case 0x29:af_data = '~'; break;

            //左shift抬起时
            case 0xaa:shift = 0; break;

            case 0x2b:af_data = '|'; break;

            case 0x2c:af_data = 'Z'; break;
            case 0x2d:af_data = 'X'; break;
            case 0x2e:af_data = 'C'; break;
            case 0x2f:af_data = 'V'; break;
            case 0x30:af_data = 'B'; break;
            case 0x31:af_data = 'N'; break;
            case 0x32:af_data = 'M'; break;

            case 0x33:af_data = '<'; break;
            case 0x34:af_data = '>'; break;
            case 0x35:af_data = '?'; break;

            //右shift抬起时
            case 0x36:shift = 0; break;

            case 0x37:af_data = '*'; break;
            //case 0x38:af_data = ''; break;
            case 0x39:af_data = ' '; break;

            //capslock按下时
            case 0x3a:
            {
                if (capslock == 1)
                {
                    capslock = 0;
                }
                else
                {
                    capslock =1;
                }
                break;
            }

            //case 0x3b:af_data = ''; break;
            //case 0x3c:af_data = ''; break;
            //case 0x3d:af_data = ''; break;
            //case 0x3e:af_data = ''; break;
            //case 0x3f:af_data = ''; break;
            //case 0x40:af_data = ''; break;
            //case 0x41:af_data = ''; break;
            //case 0x42:af_data = ''; break;
            //case 0x43:af_data = ''; break;
            //case 0x44:af_data = ''; break;

            //case 0x45:af_data = ''; break;
            //case 0x46:af_data = ''; break;

            case 0x47:af_data = '7'; break;
            case 0x48:af_data = '8'; break;
            case 0x49:af_data = '9'; break;
            case 0x4a:af_data = '-'; break;
            case 0x4b:af_data = '4'; break;
            case 0x4c:af_data = '5'; break;
            case 0x4d:af_data = '6'; break;
            case 0x4e:af_data = '+'; break;
            case 0x4f:af_data = '1'; break;
            case 0x50:af_data = '2'; break;
            case 0x51:af_data = '3'; break;
            case 0x52:af_data = '0'; break;
            case 0x53:af_data = '.'; break;

            //case 0x54:af_data = ''; break;

            //case 0x57:af_data = ''; break;
            //case 0x58:af_data = ''; break;

            case 0x73:af_data = '_'; break;

            case 0x7d:af_data = '\\'; break;

            default:break;
	    }
    }
    else if(shift == 0 && capslock == 1)
    {
        switch (be_data)
	    {
            case 0x02:af_data = '1'; break;
            case 0x03:af_data = '2'; break;
            case 0x04:af_data = '3'; break;
            case 0x05:af_data = '4'; break;
            case 0x06:af_data = '5'; break;
            case 0x07:af_data = '6'; break;
            case 0x08:af_data = '7'; break;
            case 0x09:af_data = '8'; break;
            case 0x0a:af_data = '9'; break;
            case 0x0b:af_data = '0'; break;

            case 0x0c:af_data = '-'; break;
            case 0x0d:af_data = '='; break;
            case 0x0e:af_data = '\b'; break;
            case 0x0f:af_data = '\t'; break;

            case 0x10:af_data = 'Q'; break;
            case 0x11:af_data = 'W'; break;
            case 0x12:af_data = 'E'; break;
            case 0x13:af_data = 'R'; break;
            case 0x14:af_data = 'T'; break;
            case 0x15:af_data = 'Y'; break;
            case 0x16:af_data = 'U'; break;
            case 0x17:af_data = 'I'; break;
            case 0x18:af_data = 'O'; break;
            case 0x19:af_data = 'P'; break;

            case 0x1a:af_data = '['; break;
            case 0x1b:af_data = ']'; break;
            case 0x1c:af_data = '\n'; break;

            //case 0x1d:af_data = ''; break;
            case 0x1e:af_data = 'A'; break;
            case 0x1f:af_data = 'S'; break;
            case 0x20:af_data = 'D'; break;
            case 0x21:af_data = 'F'; break;
            case 0x22:af_data = 'G'; break;
            case 0x23:af_data = 'H'; break;
            case 0x24:af_data = 'J'; break;
            case 0x25:af_data = 'K'; break;
            case 0x26:af_data = 'L'; break;

            case 0x27:af_data = ';'; break;
            case 0x28:af_data = '\''; break;
            case 0x29:af_data = '`'; break;

            //左shift抬起时
            case 0xaa:shift = 0; break;

            case 0x2b:af_data = '\\'; break;

            case 0x2c:af_data = 'Z'; break;
            case 0x2d:af_data = 'X'; break;
            case 0x2e:af_data = 'C'; break;
            case 0x2f:af_data = 'V'; break;
            case 0x30:af_data = 'B'; break;
            case 0x31:af_data = 'N'; break;
            case 0x32:af_data = 'M'; break;

            case 0x33:af_data = ','; break;
            case 0x34:af_data = '.'; break;
            case 0x35:af_data = '/'; break;

            //右shift抬起时
            case 0x36:shift = 0; break;

            case 0x37:af_data = '*'; break;
            //case 0x38:af_data = ''; break;
            case 0x39:af_data = ' '; break;

            //capslock按下
            case 0x3a:capslock = 0; break;

            //case 0x3b:af_data = ''; break;
            //case 0x3c:af_data = ''; break;
            //case 0x3d:af_data = ''; break;
            //case 0x3e:af_data = ''; break;
            //case 0x3f:af_data = ''; break;
            //case 0x40:af_data = ''; break;
            //case 0x41:af_data = ''; break;
            //case 0x42:af_data = ''; break;
            //case 0x43:af_data = ''; break;
            //case 0x44:af_data = ''; break;

            //case 0x45:af_data = ''; break;
            //case 0x46:af_data = ''; break;

            case 0x47:af_data = '7'; break;
            case 0x48:af_data = '8'; break;
            case 0x49:af_data = '9'; break;
            case 0x4a:af_data = '-'; break;
            case 0x4b:af_data = '4'; break;
            case 0x4c:af_data = '5'; break;
            case 0x4d:af_data = '6'; break;
            case 0x4e:af_data = '+'; break;
            case 0x4f:af_data = '1'; break;
            case 0x50:af_data = '2'; break;
            case 0x51:af_data = '3'; break;
            case 0x52:af_data = '0'; break;
            case 0x53:af_data = '.'; break;

            //case 0x54:af_data = ''; break;

            //case 0x57:af_data = ''; break;
            //case 0x58:af_data = ''; break;

            case 0x73:af_data = '_'; break;

            case 0x7d:af_data = '\\'; break;

            default:break;
        }
    }
    return af_data;
}
	