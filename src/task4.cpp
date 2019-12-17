#include "task4.h"
#include <stdio.h>
#include <string.h>

int number(char ch0)
{
    if (ch0 >= '0' && ch0 <= '9')
        return 1;
    else
        return 0;
}

int in_number(int flag, char ch)
{
    if (flag == 0 && number(ch) == 1) //enter in number
        return 1;
    else if (flag == 1 && number(ch) == 1) //in number
        return 2;
    else if (flag == 1 && number(ch) == 0) //exit 
        return 3;
}

int char_in_int(char ch1)
{
    return (ch1 - '0');
}

int getSum(char buf[])
{
    if (buf[strlen(buf) - 1] == '\n')
        buf[strlen(buf) - 1] = '\0';

    int i = 0, flag = 0,number=0,sum=0,count=0;
    while (i<strlen(buf))
    {
        switch (in_number(flag, buf[i]))
        {
        case 1:
            number = char_in_int(buf[i]);
            flag = 1;
            count++;
            break;
        case 2:
            number = number * 10 + char_in_int(buf[i]);
            count++;
            if (count > NUMB_SIZE)
            {
                flag = 0;
                count = 0;
                sum +=number;
                number = 0;
            }
            break;
        case 3:
            sum += number;
            number = 0;
            flag = 0;
            break;
        }
        i++;
    }
    if (i == strlen(buf))
        sum += number;
    
    return sum;
}