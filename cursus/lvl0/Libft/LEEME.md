# Libft: Mi primera librería de C
***Oficialmete terminado el xx/xx/2022 / Nota xxx de 100 / [English](README.md) version***

Este proyecto consiste en programar una librería en C. Aquí se han hecho muchas funciones básicas de propósito general que serán la base los programar hecho en la escuela 42.

## ¿Qué es Libft?
Libft es un proyecto con el propósito de recrear algunas [funciones estándar de C](https://www.tutorialspoint.com/c_standard_library/index.html) ("libc.a"), y otras que aunque no sean estándar pueden ser útiles, para después hacer tu propia librería y usarla en los futuros programar del curso de 42 (ya que no se permiten usar funciones que no hay hecho uno mismo). De esta manera se aprende cómo funcionan estas funciones básicas codificándolas desde cero.

## Guia rápida
```bash
# Clona el repositorio y accede a la carpeta
git clone https://github.com/ampuEus/42School/tree/main/cursus/lvl0/Libft && cd Libft/

# Ejecuta Make para compilar la libreria
make

# Ejecuta Make con bonus para ejecutar todas las funciones más las bonus
make bonus

# Compila tú main con la libreria, ejemplo:
clang main.c libft.a

# Ejecuta tú programa
./a.out

# Elimina los objetos de salida
make fclean

# Fin !
```

## Pasar los testers
Para pasar los testers que he implementado, primero hay que descargar los submoludos de los testers con `git clone --recursive` y después hay que ejecutar `make <tester name>`. Por ejemplo:
```bash
git clone --recursive https://github.com/ampuEus/42School/tree/main/cursus/lvl0/Libft && cd Libft/
make libftTester
make fclean

# Tester pasado
```
- Testers usados
  - Tripouille/libftTester: https://github.com/Tripouille/libftTester

## Funciones incluidas
[Makefile](src/Makefile), [main.c](src/main.c), [libft.h](src/libft.h)


<table>
    <thead>
        <tr>
            <th colspan=3><h3>Librería estandar de C</h3></a></th>
        </tr>
        <tr>
            <th colspan=2><h4><a href="https://www.tutorialspoint.com/c_standard_library/ctype_h.htm">&lt;ctype.h&gt;</a>: Funciones para verificar y manipular caracteres</h4></th>
        </tr>
        <tr>
            <th>Nombre</th>
            <th>Descripción</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><a href=src/ft_isalnum.c>ft_isalnum</a></td>
            <td>Comprueba si el carácter pasado es alfanumérico.</td>
        </tr>
        <tr>
            <td><a href=src/ft_isalpha.c>ft_isalpha</a></td>
            <td>Comprueba si el carácter pasado es alfabético.</td>
        </tr>
        <tr>
            <td><a href=src/ft_isascii.c>ft_isascii</a></td>
            <td>Comprueba si el carácter pasado es ASCII.</td>
        </tr>
        <tr>
            <td><a href=src/ft_isdigit.c>ft_isdigit</a></td>
            <td>Comprueba si el carácter pasado es un número decimal.</td>
        </tr>
        <tr>
            <td><a href=src/ft_isprint.c>ft_isprint</a></td>
            <td>Comprueba si el carácter pasado se puede imprimir en consola.</td>
        </tr>
        <tr>
            <td><a href=src/ft_tolower.c>ft_tolower</a></td>
            <td>Convierte las letras mayúsculas a minúsculas.</td>
        </tr>
        <tr>
            <td><a href=src/ft_toupper.c>ft_toupper</a></td>
            <td>Convierte las letras minúsculas a mayúsculas.</td>
        </tr>
    </tbody>
    <thead>
        <tr>
            <th colspan=2><h4><a href="https://www.tutorialspoint.com/c_standard_library/string_h.htm">&lt;string.h&gt;</a>: Funciones para manipular cadenas de caracteres</h4></th>
        </tr>
        <tr>
            <th>Nombre</th>
            <th>Descripción</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><a href=src/ft_bzero.c>ft_bzero</a></td>
            <td>Borra los datos en los <i>n</i> bytes del bloque de memoria. (Escribe ceros, esto es, apunta a NULL)</td>
        </tr>
        <tr>
            <td><a href=src/ft_memchr.c>ft_memchr</a></td>
            <td>Busca la primera aparición del carácter <i>c</i> (siendo un carácter sin signo) en los primeros <i>n</i> bytes de la cadena.</td>
        </tr>
        <tr>
            <td><a href=src/ft_memcmp.c>ft_memcmp</a></td>
            <td>Compara los primeros <i>n</i> bytes de <i>str1</i> y <i>str2</i>.</td>
        </tr>
        <tr>
            <td><a href=src/ft_memcpy.c>ft_memcpy</a></td>
            <td>Copia <i>n</i> caracteres de <i>src</i> a <i>dest</i>.</td>
        </tr>
        <tr>
            <td><a href=src/ft_memmove.c>ft_memmove</a></td>
            <td>Copia <i>n</i> caracteres de <i>src</i> a <i>dest</i>. (Manera no destructiva)</td>
        </tr>
        <tr>
            <td><a href=src/ft_memset.c>ft_memset</a></td>
            <td>Copia el carácter <i>c</i> (un carácter sin signo) a los primeros <i>n</i> caracteres de la cadena.</td>
        </tr>
        <tr>
            <td><a href=src/ft_strchr.c>ft_strchr</a></td>
            <td>Busca la primera aparición del carácter <i>c</i> (un carácter sin signo) en la cadena.</td>
        </tr>
        <tr>
            <td><a href=src/ft_strlcat.c>ft_strlcat</a></td>
            <td>Agrega la cadena <i>src</i> al final de <i>dst</i>. Agregará como máximo <i>dstsize - strlen (dst) - 1</i> caracteres.</td>
        </tr>
        <tr>
            <td><a href=src/ft_strlcpy.c>ft_strlcpy</a></td>
            <td>Copia hasta el carácter <i>dstsize - 1</i> de la cadena <i>src</i> a <i>dst</i>.</td>
        </tr>
        <tr>
            <td><a href=src/ft_strlen.c>ft_strlen</a></td>
            <td>Calcula la longitud de la cadena pero sin incluir el carácter nulo de terminación.</td>
        </tr>
        <tr>
            <td><a href=src/ft_strncmp.c>ft_strncmp</a></td>
            <td>Compara como máximo los primeros <i>n</i> bytes de <i>str1</i> y <i>str2</i>.</td>
        </tr>
        <tr>
            <td><a href=src/ft_strnstr.c>ft_strnstr</a></td>
            <td>Localiza la primera aparición de la cadena <i>little</i> terminada en nulo en la cadena <i>big</i>, donde no se buscan más de <i>len</i> caracteres.</td>
        </tr>
        <tr>
            <td><a href=src/ft_strrchr.c>ft_strrchr</a></td>
            <td>Busca la última aparición del carácter <i>c</i> (un carácter sin signo) en la cadena.</td>
        </tr>
    </tbody>
    <thead>
        <tr>
            <th colspan=2><h4><a href="https://www.tutorialspoint.com/c_standard_library/stdlib_h.htm">&lt;stdlib.h&gt;</a>: Funciones de proposito general</h4></th>
        </tr>
        <tr>
            <th>Nombre</th>
            <th>Descripción</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><a href=src/ft_atoi.c>ft_atoi</a></td>
            <td>Convierte la cadena a un número entero (tipo int).</td>
        </tr>
        <tr>
            <td><a href=src/ft_calloc.c>ft_calloc</a></td>
            <td>Asigna la memoria solicitada inicializada a cero bytes.</td>
        </tr>
    </tbody>
    <thead>
        <tr>
            <th colspan=3><h4>Librería de C no estandar</h4></a></th>
        </tr>
        <tr>
            <th>Nombre</th>
            <th>Descripción</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><a href=src/ft_itoa.c>ft_itoa</a></td>
            <td>Convierte el int a una cadena (tipo char *).</td>
        </tr>
        <tr>
            <td><a href=src/ft_putchar_fd.c>ft_putchar_fd</a></td>
            <td>Envía el carácter <i>c</i> al descriptor de archivo dado.</td>
        </tr>
        <tr>
            <td><a href=src/ft_putendl_fd.c>ft_putendl_fd</a></td>
            <td>Envía la cadena <i>s</i> al descriptor de archivo dado, seguida de un salto de línea.</td>
        </tr>
        <tr>
            <td><a href=src/ft_putnbr_fd.c>ft_putnbr_fd</a></td>
            <td>Envía el entero <i>n</i> al descriptor de archivo dado.</td>
        </tr>
        <tr>
            <td><a href=src/ft_putstr_fd.c>ft_putstr_fd</a></td>
            <td>Envía la cadena <i>s</i> al descriptor de archivo dado.</td>
        </tr>
        <tr>
            <td><a href=src/ft_split.c>ft_split</a></td>
            <td>Reserva un array de strings resultante de separar la string <i>s</i> en substrings utilizando el caracter <i>c</i> como delimitador. El array debe terminar con un puntero NULL.</td>
        </tr>
        <tr>
            <td><a href=src/ft_strdup.c>ft_strdup</a></td>
            <td>Devuelve un puntero a una cadena de bytes terminada en nulo, que es un duplicado de la cadena.</td>
        </tr>
        <tr>
            <td><a href=src/ft_striteri.c>ft_striteri</a></td>
            <td>Aplica una función a cada carácter de la cadena.</td>
        </tr>
        <tr>
            <td><a href=src/ft_strjoin.c>ft_strjoin</a></td>
            <td>Devuelve una nueva cadena, que es el resultado de la concatenación de <i>s1</i> y <i>s2</i>.</td>
        </tr>
        <tr>
            <td><a href=src/ft_strmapi.c>ft_strmapi</a></td>
            <td>Aplica una función a cada carácter de la cadena <i>s</i> para crear una nueva cadena.</td>
        </tr>
        <tr>
            <td><a href=src/ft_strtrim.c>ft_strtrim</a></td>
            <td>Devuelve una copia de <i>s1</i> con los caracteres especificados en <i>set</i> eliminados del principio y el final de la cadena.</td>
        </tr>
        <tr>
            <td><a href=src/ft_substr.c>ft_substr</a></td>
            <td>Devuelve una subcadena de la cadena <i>s</i>. La subcadena comienza en el índice <i>start</i> y tiene el tamaño máximo <i>len</i>.</td>
        </tr>
    </tbody>
    <thead>
        <tr>
            <th colspan=2><h4>Manipulación de listas encadenadas</h4></a></th>
        </tr>
        <tr>
            <th>Nombre</th>
            <th>Descripción</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><a href=src/ft_lstadd_back.c>ft_lstadd_back</a></td>
            <td>Agrega el elemento al final de la lista.</td>
        </tr>
        <tr>
            <td><a href=src/ft_lstadd_front.c>ft_lstadd_front</a></td>
            <td>Agrega el elemento al final de la lista.</td>
        </tr>
        <tr>
            <td><a href=src/ft_lstclear.c>ft_lstclear</a></td>
            <td>Elimina y libera el elemento dado y todos los sucesores de ese elemento, usando una función dada y <i>free()</i></td>
        </tr>
        <tr>
            <td><a href=src/ft_lstdelone.c>ft_lstdelone</a></td>
            <td>Toma como parámetro un elemento y libera la memoria del contenido del elemento usando una función dada como parámetro y libera el elemento.</td>
        </tr>
        <tr>
            <td><a href=src/ft_lstiter.c>ft_lstiter</a></td>
            <td>Itera la lista y aplica una función al contenido de cada elemento.</td>
        </tr>
        <tr>
            <td><a href=src/ft_lstlast.c>ft_lstlast</a></td>
            <td>Devuelve el último elemento de la lista.</td>
        </tr>
        <tr>
            <td><a href=src/ft_lstmap.c>ft_lstmap</a></td>
            <td>Itera la lista y aplica una función al contenido de cada elemento. Crea una nueva lista resultante de las sucesivas aplicaciones de la función. Se utiliza una función <i>del</i> para eliminar el contenido de un elemento si es necesario.</td>
        </tr>
        <tr>
            <td><a href=src/ft_lstnew.c>ft_lstnew</a></td>
            <td>Devuelve un nuevo elemento.</td>
        </tr>
        <tr>
            <td><a href=src/ft_lstsize.c>ft_lstsize</a></td>
            <td>Cuenta el número de elementos en una lista.</td>
        </tr>
    </tbody>
</table>

## Materias de apoyo
 - Libreria estandar de C libres (Libc.a)
    - https://www.gnu.org/software/libc/documentation.html
    - https://rootdirectory.de/doku.php?id=pdclib:start
    - https://www.tutorialspoint.com/c_standard_library/index.html
 - Como hacer un Makefile
    - https://makefiletutorial.com/
    - https://www.gnu.org/software/make/manual/make.html
 - Información sobre librerias estáticas
    - https://medium.com/@meghamohan/all-about-static-libraries-in-c-cea57990c495

## Repositorios utilies de otros estudiantes
- https://github.com/wwwwelton/libft

- https://github.com/mcombeau/libft


## Actualizaciones
Como esta librería es la base de todos los programas que se quieren hacer en 42, la librería se estará ampliando cada vez que sea necesario. Ver la carpeta“[src/extra](src/extra)”.

---
Made by daampuru | LinkedIn: [David Ampurua](www.linkedin.com/in/david-ampurua)
