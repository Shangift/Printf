#ifndef _PRINTF_H
#define _PRINTF_H
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#define buf_flush -1
#define output_buf_size 1024
#define convert_lowercase 1
#define convert_unsigned 2
#define parameter_init {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define Null_string "(null)"
/**
<<<<<<< HEAD
* struct parameters - struct parameters.
*
* @unsign: flags if the value is unsigned.
* @l_modifier: if l_modifier is specified, on.
* @h_modifier: if h_modifier is specified, on.
* @space_flag: if hashtag_flag specified, on.
* @hashtag_flag: if _flag specified, on.
* @zero_flag: if _flag specified, on.
* @plus_flag: if flag specified, on.
* @minus_flag: if flag specified, on.
*
*/
=======
 * struct parameters - structure for parameters.
 *
 * @unsign: flags if the value is unsigned.
 * @l_modifier: if l_modifier is specified, on.
 * @h_modifier: if h_modifier is specified, on.
 * @space_flag: if hashtag_flag specified, on.
 * @hashtag_flag: if _flag specified, on.
 * @zero_flag: if _flag specified, on.
 * @plus_flag: if flag specified, on.
 * @minus_flag: if flag specified, on.
 * @width: set maximum field length.
 * @precision: set the maximum no. of digits.
 */
>>>>>>> 1bd8924112c6de36abef64a9297ee4e0cb0e7f5d
typedef struct parameters
{
unsigned int unsign		: 1;
unsigned int l_modifier		: 1;
unsigned int h_modifier		: 1;
unsigned int space_flag		: 1;
unsigned int hashtag_flag	: 1;
unsigned int zero_flag		: 1;
unsigned int plus_flag		: 1;
unsigned int minus_flag		: 1;
unsigned int width              : 1;
unsigned int precision;         : 1;
} parameter_p;
/**
<<<<<<< HEAD
* struct specifier - structure token
*
* @specifier: format token
* @f: function
*/
=======
 * struct specifier - Structure for specifier.
 *
 * @specifier: format token
 * @f: function
 */
>>>>>>> 1bd8924112c6de36abef64a9297ee4e0cb0e7f5d
typedef struct specifier
{
char *specifier;
int (*f)(va_list, parameter_p *);
} specifier_t;
/* _put.c */
int _puts(char *str);
int _putchar(int c);
/* print_functions.c */
int print_char(va_list ap, parameter_p *param);
int print_int(va_list ap, parameter_p *param);
int print_string(va_list ap, parameter_p *param);
int print_percent(va_list ap, parameter_p *param);
int print_S(va_list ap, parameter_p *param);
/* number.c */
char *convert(long int num, int base, int flags, parameter_p *param);
int print_unsigned(va_list ap, parameter_p *param);
int print_address(va_list ap, parameter_p *param);
/* specifier.c */
int (*get_specifier(char *s))(va_list ap, parameter_p *param);
int get_print_func(char *s, va_list ap, parameter_p *param);
int get_flag(char *s, parameter_p *param);
int get_modifier(char *s, parameter_p *param);
char *get_width(char *s, parameter_p *param, va_list ap);
/* convert_number.c */
int print_hex(va_list ap, parameter_p *param);
int print_HEX(va_list ap, parameter_p *param);
int print_binary(va_list ap, parameter_p *param);
int print_octal(va_list ap, parameter_p *param);
/* simple_printers.c */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, parameter_p *param);
int print_rot13(va_list ap, parameter_p *param);
/* print_number.c */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, parameter_p *param);
int print_number_right_shift(char *str, parameter_p *param);
int print_number_left_shift(char *str, parameter_p *param);
/* params.c */
void init_params(parameter_p *param, va_list ap);
/* string_fields.c */
char *get_precision(char *p, parameter_p *param, va_list ap);
/* _prinf.c */
int _printf(const char *format, ...);
#endif
