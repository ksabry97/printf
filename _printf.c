#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h> 
#include <string.h>
#include "main.h"
/**
 * tostring - convert int to string
 * @str: array
 * @int: integer
 */

void tostring(char str[], int num)
{
    int i, rem, len = 0, n;
 
    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}

/**
 * _printf - print string with format
 * @format: input string
 *
 * Return: number of printed characters
 */

int _printf(const char *format, ...)
{
    char *cursor;
    int count = 0;
    
    if (!format)
    {
        return 0;
    }
    va_list args;
    va_start(args, format);
    for (cursor = format; *cursor != '\0'; cursor++)
    {
        while (*cursor != '%')
        {
            putchar(*cursor);
            cursor++;
            count++;
            if (*cursor == '\0')
            {
                return count;
            }
        }
        cursor++;
        switch(*cursor)
        {
            case 'c':
                putchar(va_arg(args, int));
                count++;
                break;
            case 'd':
                char str[sizeof(int)];
                tostring(str, va_arg(args, int));
                for (int j = 0; j < strlen(str); j++)
                {
                    putchar(*(str + j));
                }
                count += strlen(str) - 1;
                break;
            case 's':
                char *s;
                s = va_arg(args, char *);
                for (int x = 0;  x < strlen(s); x++)
                {
                    putchar(*(s + x));
                }
                count += strlen(s) - 1;
                break;
            default:
                putchar('%');
                putchar(*cursor);
        }
    }
    return count;
}
