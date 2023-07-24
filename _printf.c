#include "main.h"
/**
* _printf - Printf function
* @format: format.
* Return: Printed chars.
*/
int _printf(const char *format, ...)
{
int i, printed = 0, printed_chars = 0;
int flags, width, precision, size, buff_ind = 0;
va_list list;
if (format == NULL)
return (-1);
va_start(list, format);
for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
if (buff_ind == BUFF_SIZE)
printed_chars++;
}
else
{
++i;
if (printed == -1)
return (-1);
printed_chars += printed;
}
}
va_end(list);
return (printed_chars);
}
