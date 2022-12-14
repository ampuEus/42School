# ft_printf : Porque putnbr() y putstr() no son suficientes
***Oficialmente terminado el 06/12/2022 / Nota 125 de 100 / [English](README.md) version***

El objetivo de este proyecto es reprogramar la función `printf()`. Para así aprender, principalmente, a utilizar un número variable de argumentos.

## Índice
- Requisitos del ejercicio
- Descripción, Declaración y Valor de salida
- Parametros y formato
- Conceptos básicos a interiorizar en esta práctica
  * Funciones variádicas
  * Estructuras
    + ¿Que es una estructura?
- Referencias
- Repositorios útiles de otros estudiantes

## Requisitos del ejercicio
- No implementar la gestión del buffer del `printf()` original
- Hay que usar el comando `ar` para crear la librería. El uso de `libtool` está prohibido
- `libftprintf.a` deberá ser creado en la raíz de tu repositorio
- Especificadores a implementar: %c, %s, %p, %d, %i, %u, %x, %X, %%
- (Bonus) Opciones a implementar: -, 0, ., ancho mínimo
- (Bonus) Flags a implementar: #, +, (espacio)

## Descripción, Declaración y Valor de salida
`printf()` Es una función variádicas que envía la salida formateada a *stdout*. Su propotipo es:
```c
int printf(const char *format, ...)
```

Donde *format* es el string que contiene el texto que se escribirá en la salida estándar.
Opcionalmente, puede contener etiquetas de formato que se reemplazan por los valores especificados en argumentos adicionales posteriores y se formatean según lo solicitado. El prototipo de las etiquetas de formato es el especificador `%[flags][ancho][.precisión]especificador`, que se explica a continuación.

## Parametros y formato
<table>
<thead>
  <tr>
    <th colspan="3"><h3>Especificadores y salida</h3></th>
  </tr>
  <tr>
    <th>Especificador</th>
    <th>Función</th>
    <th>Salida</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td>%c</td>
    <td><a href=src/ft_print_cs.c>ft_print_c</a></td>
    <td>Imprime un solo carácter</td>
  </tr>
  <tr>
    <td>%s</td>
    <td><a href=src/ft_print_cs.c>ft_print_s</a></td>
    <td>Imprime un string (como se define por defecto en C)</td>
  </tr>
  <tr>
    <td>%p</td>
    <td><a href=src/ft_print_hex.c>ft_print_p</a></td>
    <td>La dirección del puntero `void *` dado como argumento se imprime en formato hexadecimal</td>
  </tr>
  <tr>
    <td>%d</td>
    <td><a href=src/ft_print_nbr.c>ft_print_nbr</a></td>
    <td>Imprime un número decimal</td>
  </tr>
  <tr>
    <td>%i</td>
    <td><a href=src/ft_print_nbr.c>ft_print_nbr</a></td>
    <td>Imprime un entero en base 10</td>
  </tr>
  <tr>
    <td>%u</td>
    <td><a href=src/ft_print_nbr.c>ft_print_ulnbr</a></td>
    <td>Imprime un número decimal sin signo</td>
  </tr>
  <tr>
    <td>%x</td>
    <td><a href=src/ft_print_hex.c>ft_putnbr</a></td>
    <td>Imprime un número hexadecimal en minúsculas</td>
  </tr>
  <tr>
    <td>%X</td>
    <td><a href=src/ft_print_hex.c>ft_putnbr</a></td>
    <td>Imprime un número hexadecimal en mayúsculas</td>
  </tr>
  <tr>
    <td>%%</td>
    <td><a href=src/ft_print_cs.c>ft_print_c</a></td>
    <td>Para imprimir el símbolo del porcentaje</td>
  </tr>
</tbody>
<thead>
  <tr>
    <th colspan="3"><h3>Flags</h3></th>
  </tr>
  <tr>
    <th>Flag</th>
    <th colspan="2">Descripción</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td>-</td>
    <td colspan="2">Justificar a la izquierda dentro del ancho de campo dado. La justificación a la derecha es la predeterminada (consulta el subespecificador de ancho)</td>
  </tr>
  <tr>
    <td>+</td>
    <td colspan="2">Obliga a preceder el resultado con un signo más o menos (+ o -) incluso para números positivos. De forma predeterminada, solo los números negativos van precedidos del signo "-"</td>
  </tr>
  <tr>
    <td>(espacio)</td>
    <td colspan="3">Si no se va a escribir ningún signo, se inserta un espacio en blanco antes del valor</td>
  </tr>
  <tr>
    <td>#</td>
    <td colspan="2">✅ Usado con los especificadores o, x o X, el valor va precedido de 0, 0x o 0X respectivamente para valores distintos de cero.<br>
    ❌ Usado con e, E y f, obliga a que la salida escrita contenga un punto decimal incluso si no le siguen dígitos. De forma predeterminada, si no siguen dígitos, no se escribe ningún punto decimal.<br>
    ❌ Usado con g o G, el resultado es el mismo que con e o E, pero no se eliminan los ceros finales.</td>
  </tr>
  <tr>
    <td>0</td>
    <td colspan="2">Rellena a la izquierda el número con ceros (0) en lugar de espacios, donde se especifica el relleno (consulta el subespecificador de ancho)</td>
  </tr>
</tbody>
<thead>
  <tr>
    <th colspan="3"><h3>Anchos</h3></t>
  </tr>
  <tr>
    <th>Ancho</th>
    <th colspan="2">Descripción<br></th>
  </tr>
</thead>
<tbody>
  <tr>
    <td>(número)</td>
    <td colspan="2">Número mínimo de caracteres a imprimir. Si el valor a imprimir es más corto que este número, el resultado se rellena con espacios en blanco. El valor no se trunca incluso si el resultado es mayor</td>
  </tr>
  <tr>
    <td>*</td>
    <td colspan="2">El ancho no se especifica en la cadena de formato, sino como un argumento de valor entero adicional que precede al argumento que debe formatearse</td>
  </tr>
</tbody>
<thead>
  <tr>
    <th colspan="3"><h3>Precisión</h3></th>
  </tr>
  <tr>
    <th>Formato</th>
    <th colspan="2">Descripción</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td>.número</td>
    <td colspan="2">✅ Para especificadores de enteros (d, i, o, u, x, X): La precisión especifica el número mínimo de dígitos que se escribirán. Si el valor que se va a escribir es más corto que este número, el resultado se rellena con ceros a la izquierda. El valor no se trunca incluso si el resultado es más largo. Una precisión de 0 significa que no se escribe ningún carácter para el valor 0.<br>
    ❌ Para los especificadores e, E y f: Este es el número de dígitos que se imprimirán después del punto decimal.<br>
    ❌ Para los especificadores g y G: Este es el número máximo de dígitos significativos que se imprimirán.<br>
    ✅ Para s: Este es el número máximo de caracteres que se imprimirán. De forma predeterminada, todos los caracteres se imprimen hasta que se encuentra el carácter nulo final.<br>
    ✅ Para el tipo c: No tiene efecto.<br>
    NOTA: Cuando no se especifica precisión, el valor predeterminado es 1. Si el período se especifica sin un valor explícito para la precisión, se asume 0.</td>
  </tr>
  <tr>
    <td>.*</td>
    <td colspan="2">La precisión no se especifica en la cadena de formato, sino como un argumento de valor entero adicional que precede al argumento que debe formatearse</td>
  </tr>
</tbody>
</table>

### Ejemplo:
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
Salida:
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

## Conceptos básicos a interiorizar en esta práctica
### Funciones variádicas
Son aquellas funciones que pueden recibir un numero indefinido de argumentos.

La función variádica consta de al menos una variable fija, utilizada para especificar los argumentos, y luego mediante una elipsis ("...") se hace referencia al resto de parámetros:
```c
int funcion_variadrica(int <variable_fija>, ...);
```
>NOTA: La *<variable_fija>* no tiene por qué ser siempre de tipo *int*

Después en el cuerpo de la función, es necesario usar una serie de macros para acceder a los argumentos que se le hayan pasado a la función:
  - `va_list(<var>)`: Sirve para la definición de la variable donde almacenar los argumetos de la función variádica
  - `va_start(va_list <var>, argN)`: Permite el acceso a los argumentos de la función variádica
  - `va_arg(va_list <var>, tipo)`: Accede al siguiente argumento de la función variádica
  - `va_copy (va_list dest, va_list src)`: Hace una copia de los argumentos de la función variádica
  - `va_end(va_list \<var\>)`: Finaliza del acceso a los argumentos

```c
#include <stdio.h>
#include <stdarg.h> // Añadir la librería para la gestión de las variádicas

void prueba_multi(char *format, ...)
{
	va_list args; // Inicializar los argumentos de la función variádica

	va_start(args, format); // Activar el acceso a los argumentos de la función

	// Ir recorriendo los argumentos
	printf("%s", va_arg(args, char *));
	printf("%c", va_arg(args, int)); // NOTA: Mejor usar "int" en vez de "char"
	printf("%s", va_arg(args, char *));
	printf("%i", va_arg(args, int));
	printf("%s", va_arg(args, char *));

	va_end(args); // Finalizar el acceso a los argumentos
}

int main (void)
{
	prueba_multi("<printf_formats>", "Hello ", 't', "his is ", 1, " variadric function");
	return (0);
}
```
Salida:
```
Hello this is 1 variadic function
```

### Estructuras
Sí se quiere hacer el bonus, en mi opinión es imprescindible usar una estructura que vaya guardando el formato con el que se quiere *print*ear los datos.
#### ¿Que es una estructura?
Una *struct* es una *key word* para crear un tipo de datos definido por el usuario en C/C++. Una estructura crea un tipo de datos que se puede utilizar para agrupar elementos de tipos posiblemente diferentes en un solo tipo.

**Creación** de una estructura
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

**Declaración** de la estructura:
```c
t_Tags	tags;
```
> NOTA: Normalmente es necesario inicializar la estructura, para ello se puede usar la funcióon `memset`

Para acceder a los valores de la estructura se utiliza el punto ('.'), a no ser que se trate de un puntero a la estructura, en cuyo caso se utiliza "->", por ejemplo:
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

> **Consejo para la mejora del rendimiento**: Para mejorar el rendimiento de un programa cuando se está trabajando con estructuras, es utilizar punteros cuando hay que pasar la información de la estructura a una función (`void ft_example(t_Tags *tag)`). Ya que si se genera una nueva variable (`void ft_example(t_Tags tag)`) hay que duplicar toda la información de la estructura por cada llamada a la función.

## Referencias
  - https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm#
  - https://hardfloat.es/blog/2021/11/05/funciones-variadicas.html
  - https://es.acervolima.com/funciones-variadicas-en-c/
  - https://en.wikipedia.org/wiki/Variadic_function#In_C

## Repositorios útiles de otros estudiantes
  - https://github.com/madebypixel02/ft_printf
  - https://github.com/mcombeau/ft_printf
  - https://github.com/benatcastro/ft_printf

---
Hecho por daampuru | LinkedIn: [David Ampurua](https://www.linkedin.com/in/david-ampurua)
