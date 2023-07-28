#include "main.h"

/**
 * converter - itoa's mimic function.
 * @number: number
 * @base: base
 * @flags: argument flags
 * @param: paramater structure.
 *
 * Return: string
 */
char *converter(long int number, int base, int flags, parameter_p *param)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = number;
	(void)param;

	if (!(flags & CONVERT_UNSIGNED) && number < 0)
	{
		n = -number;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_unsigned - prints unsigned integers
 * @ap: arg ptr.
 * @param: parameter structure
 *
 * Return: bytes printed
 */
int print_unsigned(va_list ap, parameter_p *param)
{
	unsigned long l;

	if (param->modifier_l)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (param->modifier_h)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	param->unsign = 1;
	return (print_number(converter(l, 10, CONVERT_UNSIGNED, param), param));
}



/**
 * print_address - prints address
 * @ap: arg ptr.
 * @param: parameter structure.
 *
 * Return: bytes printed
 */
int print_address(va_list ap, parameter_p *param)
{
	unsigned long int n = va_arg(ap, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = converter(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, param);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, param));
}
