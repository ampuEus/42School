# ft_printf : Because ft_putnbr() and ft_putstr() aren’t enough
***Officially finished at 2022-12-06 / Grade: 125 of 100 / Versión en [español](LEEME.md)***

The goal of this project is recode `printf()`. To mainly learn about using a variable number of arguments.

## Table of Contents
- Exercise requirements
- Description, Declaration and Output Value
- Parametros y formato
- [Basic concepts to learn in this practice
  * Variadic functions
  * Structures
    + What is a structure?
- References
- Useful repositories from other students

## Exercise requirements
- Do not implement the buffer management of the original `printf()`
- You have to use the `ar` command to create the library. Use of `libtool` is prohibited
- `libftprintf.a` should be created in the root of your repository
- Specifiers to implement: %c, %s, %p, %d, %i, %u, %x, %X, %%
- (Bonus) Options to implement: -, 0, ., minimum width
- (Bonus) Flags to implement: #, +, (space)

## Description, Declaration and Output Value
`printf()` is a variadic function that sends the formatted output to *stdout*. Its prototype is:
```c
int printf(const char *format, ...)
```

Where *format* is the string containing the text to be written to standard output.
It can optionally contain format tags that are replaced by the values specified in additional arguments and formatted as requested. The prototype for formatting tags is the `%[flags][width][.precision]specifier`, which is explained below.

## Parametros y formato
<table>
<thead>
  <tr>
    <th colspan="3"><h3>Specifiers and output</h3></th>
  </tr>
  <tr>
    <th>Dpecifier</th>
    <th>Function</th>
    <th>Output</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td>%c</td>
    <td><a href=src/ft_print_cs.c>ft_print_c</a></td>
    <td>Print a single character</td>
  </tr>
  <tr>
    <td>%s</td>
    <td><a href=src/ft_print_cs.c>ft_print_s</a></td>
    <td>Prints a string (as defined by default in C)</td>
  </tr>
  <tr>
    <td>%p</td>
    <td><a href=src/ft_print_hex.c>ft_print_p</a></td>
    <td>The address of the `void *` pointer given as an argument is printed in hexadecimal format</td>
  </tr>
  <tr>
    <td>%d</td>
    <td><a href=src/ft_print_nbr.c>ft_print_nbr</a></td>
    <td>Print a decimal number</td>
  </tr>
  <tr>
    <td>%i</td>
    <td><a href=src/ft_print_nbr.c>ft_print_nbr</a></td>
    <td>Prints an integer in base 10</td>
  </tr>
  <tr>
    <td>%u</td>
    <td><a href=src/ft_print_nbr.c>ft_print_ulnbr</a></td>
    <td>Prints an unsigned decimal number</td>
  </tr>
  <tr>
    <td>%x</td>
    <td><a href=src/ft_print_hex.c>ft_putnbr</a></td>
    <td>Prints a lowercase hexadecimal number</td>
  </tr>
  <tr>
    <td>%X</td>
    <td><a href=src/ft_print_hex.c>ft_putnbr</a></td>
    <td>Prints a uppercase hexadecimal number</td>
  </tr>
  <tr>
    <td>%%</td>
    <td><a href=src/ft_print_cs.c>ft_print_c</a></td>
    <td>To print the percent symbol</td>
  </tr>
</tbody>
<thead>
  <tr>
    <th colspan="3"><h3>Flags</h3></th>
  </tr>
  <tr>
    <th>Flag</th>
    <th colspan="2">Description</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td>-</td>
    <td colspan="2">Left justify within the given field width. Right justification is the default (see width subspecifier)</td>
  </tr>
  <tr>
    <td>+</td>
    <td colspan="2">Forces to precede the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded by the "-" sign.</td>
  </tr>
  <tr>
    <td>(space)</td>
    <td colspan="3">If no sign is to be written, a blank space is inserted before the value</td>
  </tr>
  <tr>
    <td>#</td>
    <td colspan="2">✅ Used with the o, x, or X specifiers, the value is preceded by 0, 0x, or 0X respectively for non-zero values.<br>
    ❌ Used with e, E, and f, forces written output to contain a decimal point even if no digits follow. By default, if no digits follow, no decimal point is written.<br>
    ❌ Used with g or G, the result is the same as with e or E, but the final zeros are not removed.</td>
  </tr>
  <tr>
    <td>0</td>
    <td colspan="2">Fill in number with zeros (0) instead of spaces, where padding is specified (see width subspecifier)</td>
  </tr>
</tbody>
<thead>
  <tr>
    <th colspan="3"><h3>Widths</h3></t>
  </tr>
  <tr>
    <th>Width</th>
    <th colspan="2">Description<br></th>
  </tr>
</thead>
<tbody>
  <tr>
    <td>(number)</td>
    <td colspan="2">Minimum number of characters to print. If the value to print is shorter than this number, the result is padded with blanks. The value is not truncated even if the result is greater</td>
  </tr>
  <tr>
    <td>*</td>
    <td colspan="2">The width is not specified in the format string, but as an additional integer value argument that precedes the argument to be formatted</td>
  </tr>
</tbody>
<thead>
  <tr>
    <th colspan="3"><h3>Precision</h3></th>
  </tr>
  <tr>
    <th>Format</th>
    <th colspan="2">Description</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td>.number</td>
    <td colspan="2">✅ For integer specifiers (d, i, o, u, x, X): The precision specifies the minimum number of digits to write. If the value to be written is shorter than this number, the result is padded with zeros to the left. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0.<br>
    ❌ For e, E, and f specifiers: This is the number of digits to print after the decimal point.<br>
    ❌ For g and G specifiers: This is the maximum number of significant digits that will be printed.<br>
    ✅ For s: This is the maximum number of characters that will be printed. By default, all characters are printed until the final null character is encountered.<br>
    ✅ For type c: No effect.<br>
    NOTE: When no precision is specified, the default value is 1. If the period is specified without an explicit value for precision, 0 is assumed.</td>
  </tr>
  <tr>
    <td>.*</td>
    <td colspan="2">The precision is not specified in the format string, an additional integer value argument that precedes the argument to be formatted</td>
  </tr>
</tbody>
</table>

### Example:
```c
#include <stdio.h>

int main()
{
   printf ("Characters: %c %c \n", 'a', 65);
   printf ("Decimals: %d %ld\n", 1977, 650000L);
   printf ("Preceding with blanks: %10d \n", 1977);
   printf ("Preceding with zeros: %010d \n", 1977);
   printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
   printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
   printf ("Width trick: %*d \n", 5, 10);
   printf ("%s \n", "A string");
   return 0;
}
```
Output:
```bash
Characters: a A
Decimals: 1977 650000
Preceding with blanks:       1977
Preceding with zeros: 0000001977
Some different radices: 100 64 144 0x64 0144
floats: 3.14 +3e+000 3.141600E+000
Width trick:    10
A string
```

## Basic concepts to learn in this practice
### Variadic functions
They are those functions that can receive an undefined number of arguments.

The variadic function consists of at least one fixed variable, used to specify the arguments, and then using an ellipsis ("...") the rest of the parameters are referenced:
```c
int funcion_variadrica(int <fixed_variable>, ...);
```
>NOTE: The *<fixed_variable>* does not always have to be of type *int*

Later in the body of the function, it is necessary to use a series of macros to access the arguments that have been passed to the function:
  - `va_list(<var>)`: It is used to define the variable where to store the arguments of the variadic function
  - `va_start(va_list <var>, argN)`: Allows access to the arguments of the variadic function
  - `va_arg(va_list <var>, type)`: Accesses the next argument of the variadic function
  - `va_copy (va_list dest, va_list src)` : Makes a copy of the variadic function arguments
  - `va_end(va_list \<var\>)`: Ends the access to the arguments

```c
#include <stdio.h>
#include <stdarg.h> // Add the library for the management of variadics functions

void prueba_multi(char *format, ...)
{
	va_list args; // Initialize variadic function arguments

	va_start(args, format); // Enable access to function arguments

	// Go through the arguments
	printf("%s", va_arg(args, char *));
	printf("%c", va_arg(args, int)); // NOTE: Better to use "int" instead of "char"
	printf("%s", va_arg(args, char *));
	printf("%i", va_arg(args, int));
	printf("%s", va_arg(args, char *));

	va_end(args); // End access to arguments
}

int main (void)
{
	prueba_multi("<printf_formats>", "Hello ", 't', "his is ", 1, " variadric function");
	return (0);
}
```
Output:
```
Hello this is 1 variadic function
```

### Structures
If you want to do the bonus, in my opinion it is essential to use a structure that saves the format with which you want to *print* the data.
#### What is a structure?
A *struct* is a *key word* for creating a user-defined data type in C/C++. A structure creates a data type that can be used to group elements of possibly different types into a single type.

**Creating** a structure
```c
typedef struct stTags
{
	char	err;
	char	no_comb;
	char	specifier;
	int		len;
	char	flag_minus;
	char	flag_plus;
	char	flag_space;
	char	flag_hashtag;
	char	flag_zero;
	int		width_number;
	char	precision_dot;
	int		precision_size;
}	t_Tags;
```

**Declaration** of the structure:
```c
t_Tags	tags;
```
> NOTE: Normally it is necessary to initialize the structure, for this you can use the `memset` function

To access the structure's values, the point ('.') is used, unless it is a pointer to the structure, in which case "->" is used, for example:
```c
void ft_example(t_Tags *tag)
{
	tag->len = 10;
}

int	main(int argv, char **argc)
{
	t_Tags	tags;
	int			len;

	ft_memset(&tags, '\0', sizeof(tags));
	tags.len = 50;
	ft_example(&tags);
	len += tags.len;
	return (0);
}
```

> **Performance Improvement Tip**: To improve the performance of a program which works with structures, it is to use pointers when you have to pass the information of the structure to a function (`void ft_example(t_Tags *tag) `). Since if a new variable is generated (`void ft_example(t_Tags tag)`) information will be duplicated unnecessarily for each call to the function.

## References
  - https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm#
  - https://hardfloat.es/blog/2021/11/05/funciones-variadicas.html
  - https://es.acervolima.com/funciones-variadicas-en-c/
  - https://en.wikipedia.org/wiki/Variadic_function#In_C

## Useful repositories from other students
  - https://github.com/madebypixel02/ft_printf
  - https://github.com/mcombeau/ft_printf
  - https://github.com/benatcastro/ft_printf

---
Made by daampuru | LinkedIn: [David Ampurua](https://www.linkedin.com/in/david-ampurua)
