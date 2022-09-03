# printf : Porque putnbr() y putstr() no son suficientes
***Oficialmente terminado el xx/09/2022 / Nota xxx de 100 / [English](README.md) version***

El objetivo de este proyecto es reprogramar la función `printf()`. Para así aprender, principalmente, a utilizar un número variable de argumentos.

## Indice
***TODO***

## Requisitos del ejercicio
- No implementar la gestión del buffer del `printf()` original
- Hay que usar el comando `ar` para crear la librería. El uso de `libtool` esta prohibido
- `libftprintf.a` deberá ser creado en la raiz de tu repositorio
- Especificadores a implementar: %c, %s, %p, %d, %i, %u, %x, %X, %%
- (Bonus) Opciones a implementar: -, 0, ., ancho mínimo
- (Bonus) Flags a implementar: #, +, (espacio)

## Descripción, Declaración y Valor de salida
`printf()` envía la salida formateada a stdout. Mientras que su propotipo es:
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
    <td>?????</td>
    <td>Imprime un solo carácter</td>
  </tr>
  <tr>
    <td>%s</td>
    <td>?????</td>
    <td>Imprime un string (como se define por defecto en C)</td>
  </tr>
  <tr>
    <td>%p</td>
    <td>?????</td>
    <td>La dirección del puntero `void *` dado como argumento se imprime en formato hexadecimal</td>
  </tr>
  <tr>
    <td>%d</td>
    <td>?????</td>
    <td>Imprime un número decimal</td>
  </tr>
  <tr>
    <td>%i</td>
    <td>?????</td>
    <td>Imprime un entero en base 10</td>
  </tr>
  <tr>
    <td>%u</td>
    <td>?????</td>
    <td>Imprime un número decimal sin signo</td>
  </tr>
  <tr>
    <td>%x</td>
    <td>?????</td>
    <td>Imprime un número hexadecimal en minúsculas</td>
  </tr>
  <tr>
    <td>%X</td>
    <td>?????</td>
    <td>Imprime un número hexadecimal en mayúsculas</td>
  </tr>
  <tr>
    <td>%%</td>
    <td>?????</td>
    <td>Para imprimir el símbolo del porcentaje</td>
  </tr>
</tbody>
<thead>
  <tr>
    <th colspan="3"><h3>Flags</h3></th>
  </tr>
  <tr>
    <th>Flag</th>
    <th>Función</th>
    <th>Descripción</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td>-</td>
    <td>?????</td>
    <td>Justificar a la izquierda dentro del ancho de campo dado. La justificación a la derecha es la predeterminada (consulta el subespecificador de ancho)</td>
  </tr>
  <tr>
    <td>+</td>
    <td>?????</td>
    <td>Obliga a preceder el resultado con un signo más o menos (+ o -) incluso para números positivos. De forma predeterminada, solo los números negativos van precedidos del signo "-"</td>
  </tr>
  <tr>
    <td>(espacio)</td>
    <td>?????</td>
    <td>Si no se va a escribir ningún signo, se inserta un espacio en blanco antes del valor</td>
  </tr>
  <tr>
    <td>#</td>
    <td>?????</td>
    <td>- Usado con los especificadores o, x o X, el valor va precedido de 0, 0x o 0X respectivamente para valores distintos de cero.<br>
    - Usado con e, E y f, obliga a que la salida escrita contenga un punto decimal incluso si no le siguen dígitos. De forma predeterminada, si no siguen dígitos, no se escribe ningún punto decimal.<br>
    - Usado con g o G, el resultado es el mismo que con e o E, pero no se eliminan los ceros finales.</td>
  </tr>
  <tr>
    <td>0</td>
    <td>?????</td>
    <td>Rellena a la izquierda el número con ceros (0) en lugar de espacios, donde se especifica el relleno (consulta el subespecificador de ancho)</td>
  </tr>
</tbody>
<thead>
  <tr>
    <td colspan="3"><h3>Anchos</h3></td>
  </tr>
  <tr>
    <th>Ancho</th>
    <th>Función</th>
    <th>Descripción<br></th>
  </tr>
</thead>
<tbody>
  <tr>
    <td>(número)</td>
    <td>?????</td>
    <td>Número mínimo de caracteres a imprimir. Si el valor a imprimir es más corto que este número, el resultado se rellena con espacios en blanco. El valor no se trunca incluso si el resultado es mayor</td>
  </tr>
  <tr>
    <td>*</td>
    <td>?????</td>
    <td>El ancho no se especifica en la cadena de formato, sino como un argumento de valor entero adicional que precede al argumento que debe formatearse</td>
  </tr>
</tbody>
<thead>
  <tr>
    <th colspan="3"><h3>Precisión</h3></th>
  </tr>
  <tr>
    <th>Formato</th>
    <th>Función</th>
    <th>Descripción</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td>.número</td>
    <td>?????</td>
    <td>- Para especificadores de enteros (d, i, o, u, x, X), la precisión especifica el número mínimo de dígitos que se escribirán. Si el valor que se va a escribir es más corto que este número, el resultado se rellena con ceros a la izquierda. El valor no se trunca incluso si el resultado es más largo. Una precisión de 0 significa que no se escribe ningún carácter para el valor 0.<br>
    - Para los especificadores e, E y f, este es el número de dígitos que se imprimirán después del punto decimal.<br>
    Para los especificadores g y G: este es el número máximo de dígitos significativos que se imprimirán. Para s − este es el número máximo de caracteres que se imprimirán. De forma predeterminada, todos los caracteres se imprimen hasta que se encuentra el carácter nulo final.<br>
    - Para el tipo c − no tiene efecto. Cuando no se especifica precisión, el valor predeterminado es 1. Si el período se especifica sin un valor explícito para la precisión, se asume 0.</td>
  </tr>
  <tr>
    <td>.*</td>
    <td>?????</td>
    <td>La precisión no se especifica en la cadena de formato, sino como un argumento de valor entero adicional que precede al argumento que debe formatearse</td>
  </tr>
</tbody>
</table>

***TODO: METER ALGÚN EJEMPLO***
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

La sintaxis usa como ultimo parámetro una variable con el prefijo ... // La función variádica consta de al menos una variable fija y luego una elipsis (…) como último parámetro
The standard stdarg.h header file is used. The older varargs.h header has been deprecated in favor of stdarg.h.
https://en.wikipedia.org/wiki/Variadic_function#In_C
https://es.acervolima.com/funciones-variadicas-en-c/


https://hardfloat.es/blog/2021/11/05/funciones-variadicas.html

https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm#

## Como he organizado las metas de este ejercicio
### Hacer una primera iteración del *Makefile*
### Hacer una funcion básica que devuelva los caracteres del string y que sea capaz de devolver el caracter '%'





---
Hecho por daampuru | LinkedIn: [David Ampurua](www.linkedin.com/in/david-ampurua)
