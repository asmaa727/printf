#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/**
* _printf - produces output according to a format.
* @format: format.
* Return: the number of printed characters 
*/
int _printf(const char *format, ...)
{
int i;
int printed = 0;
int printed_chars = 0;
int flag;
int width ;
int precision;
int size;
int buffer_index = 0;
va_list list;
char buffer[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(list, format);
for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buffer[buffer_index++] = format[i];
if (buffer_index == BUFF_SIZE)
print_buffer(buffer, &buffer_index);
printed_chars++;
}
else
{
print_buffer(buffer, &buffer_index);
flag = get_flags(format, &i);
width = get_width(format, &i, list);
precision = get_precision(format, &i, list);
size = get_size(format, &i);
++i;
printed = handle_print(format, &i, list, buffer,
flags, width, precision, size);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}
print_buffer(buffer, &buff_ind);
va_end(list);
return (printed_chars);
}
/**
* print_buffer - Prints the contents of the buffer if it exist
* @buffer: Array of chars
* @buff_ind: Index at which to add next char, represents the length.
*/
void print_buffer(char buffer[], int *buffer_index)
{
if (*buffer_index > 0)
write(1, &buffer[0], *buffer_index);
*buffer_index = 0;
}
