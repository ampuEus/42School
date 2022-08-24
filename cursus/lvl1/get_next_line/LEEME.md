# Get Next Line (gnl) : Leer una línea de un fd es tedioso
***Oficialmete terminado el xx/08/2022 / Nota xxx de 100 / [English](README.md) version***

El objetivo de este proyecto es programar una función que devuelva una línea leída de un file descriptor sin perder la pista de la siguiente línea y con un tamaño de búfer aleatorio.

## Indice

## Requisitos del ejercicio
- La forma de leer el contenido de un archivo debe ser extrayendo una línea en cada ejecución del programa con sucesivas llamadas a este.
- Debe devolver el contenido de la línea leida seguido del carácter de salto de línea ('\n'), a menos que se este al final del archivo y no termine con salto de línea
- Debe devolver NULL cuando no haya nada que leer o en caso de error
- (Bonus) Debe leer desde un archivo o desde la entrada estándar
- (Bonus) El programa solo puede tener una unica variable estatica

## Conceptos básicos a interiorizar en esta práctica
### Variables estaticas
Una variable local en el momento en que acaba la subrutina/función en la que se haya declarado se eliminan las referencias de la pila y se quitan de la memoria.
Por otro lado, una variables estaticas persiste hasta el final del programa, independientemente de donde se haya declarado (son equiparables a las variables globales, aunque con matices).

![Esquema de la pila de memoria](annex/MemoryAllocationDiagram.png)

> NOTA: Los array en C se guardan en Stack, no en Heap. Aunque sean equivalentes a un puntero + malloc.

Aquí un ejemplo de como una variable estática local no pierde su memoria sin importar cuántas veces se llame a la función en la que ha sudi declarada:

```c
#include <stdio.h>

void foo(void)
{
	static int	x; // Declaración de la variable estática
	// NOTA: Su valor por defecto es 0

	printf("x = %d", x);
	x++;
}
int main(void)
{
	int count;

	count = 0;
	while (count <= 10)
	{
		foo();
		count++;
	}
	return (0);
}
//	Aquí, una vez finaliza el programa, es cuando la variable estática deja de "existir"
```

Output:
```c
x = 0
x = 1
x = 2
x = 3
x = 4
x = 5
x = 6
x = 7
x = 8
x = 9
x = 10
```

De cara a la prática get next line, una vez se cargan los caracteres leidos del bufér a la variable estática y se ve que no hay un salto de línea (`\n`) y además no se ha finalizado la lectura del archivo, hay que seguir guardando en esta variable las cosas leidas desde `read` hasta encontrar un `\n`. Para luego, sacar los caractes anteriores al salto de línea y seguir guardando el resto en la variable estática.

### Descriptor de archivo (*File Descriptors (fd)*) + abrir y cerrar un archivo
Para manipular un archivo en C tienes que decirle al sistema operativo de donde le va ha venir la información que hay en el archivo, aquí es donde entra el descritor de archivo. En los sistemas operativos basados en Unix, el descriptor de archivo es un identificador único para un archivo u otro recurso de entrada/salida.

Exiten tres descriptores estandar, cada uno relacionado con los tres flujos de datos estandar:

| Valor entero |      Nombre      | Constante simbólica  | Secuencia de archivos |
|:------------:|:----------------:|:--------------------:|:---------------------:|
|      0       | Entrada estándar |    STDIN_FILENO      |         stdin         |
|      1       | Salida estándar  |    STDOUT_FILENO     |         stdout        |
|      2       | Error estándar   |    STDERR_FILENO     |         stderr        |

Sabiendo esto, para poder abrir el archivo que quieres leer necesitarás usar la función `open` de la librería `fcntl.h`, su funcionamiento es el siguiente:

```c
// Propotipo:
int open(const char *direccion_archivo, int flags);

// Tipos de flags:
flags1 = open("archivo.txt", O_RDONLY); // solo lectura
flags2 = open("archivo.txt", O_WRONLY); // solo escritura
flags3 = open("archivo.txt", O_RDWR);   // lectura escritura
```

El valor devuelto es un descriptor de archivo siendo este una referencia a el archivo que se le ha pasado. Además, `open` puede devolver −1 indicando una falla con `errno` detallando el error.

Finalmente, cuando terninas de manipular el archivo, tiens que desreferenciar el descriptor del archivo con la función `close` de la biblioteca `unistd.h`.

Este es un ejemplo de como abrir y cerrar un archivo de forma correcta:

```c
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	int	fd;

//	Abre el archivo y asigna el descriptor del archivo
//	devuelto a la variable fd para usarla más tarde:
	fd = open("fichier.txt", O_RDONLY);
//	Comprueba que se ha abierto correctamente:
	if (fd == -1)
		return (-1);

//	[...]

//	Por último cierra el archivo con la referencia de su fd:
	close(fd);
	return (0);
}
```

### Leer de un archivo
La función `read`, de la biblioteca `unistd.h`, carga el contenido de un archivo en la memoria, en parte o en su totalidad, utilizando un descriptor de archivo.

```c
ssize_t read(int fd, void *buf, size_t count);
             └─┬──┘  └───┬───┘  └─────┬────┘
               │         │            └─────> Número de caracteres a leer
               │         └─────> Puntero hacia un área de memoria donde almacenar temporalmente los caracteres que se leen
               └─────> Este es fd que se recive del open
```

El resultado de `read` son los caracteres que ha leido, utilizando *-1* como aviso de algún error en la lectura.

**IMPORTANTE:** `read` deja de leer cuando llega al número de caracteres dado, o al final del archivo (EOF). Y recordará la posición del último carácter leído, por lo que si se vuelve a llamar más tarde con el mismo descriptor de archivo, reanudará la lectura donde la dejó, o se quedará al final del archivo si ya lo habia terminado de leer.

En el caso del get next line, la *fd* es una de las variables que hay que pasarle a la función y *count* esta definido por el valor de *BUFFER_SIZE* el cual hay que definir en el tiempo de compilación.

### Que es un buffer + BUFFER_SIZE
En el caso del software, un búfer es un área de datos compartida por procesos de programa que funcionan a diferentes velocidades. El búfer permite que cada proceso funcione sin que el otro lo detenga. Al igual que un caché, un búfer es un "lugar de espera de punto medio", pero existe no tanto para acelerar la velocidad de una actividad como para apoyar la coordinación de actividades separadas.

Hay que tener en cuenta que un búfer sea efectivo, se debe considerar el tamaño del búfer y los algoritmos para mover datos dentro y fuera del búfer.

Ejemplo de un bufer de 16 bytes funcionando:

![Animacion de bufér circular](annex/Circular_Buffer_Animation.gif)

En get next line se pide que el tamaño del buffer se defina en la variable `BUFFER_SIZE` a la hora de compilar (utilizando el flags `-D`) para poder cambiarlo de forma sencilla. Y para prevenirse por si el usuario no lo define a la hora de compilar, es recomendable establecer un valor por defecto en el header del get next line:

```c
# ifndef BUFFER_SIZE		// Si BUFFER_SIZE no esta definido
#  define BUFFER_SIZE 64	// Dale el valor de 64
# endif
```

NOTA: Dependiendo del tamaño del buffer a la hora de utilizar `read` es probable que te quedes corto y no encuentres un final de línea y tengas que guardar esa información del buffer y volver a ejecutar `read` hasta encontrar un salto de línea y en ese momento te pases y tengas que guardar los caracteres después del salto de línea en la variable estatida, ya que cuando vuelvas a ejecutar `read` leera desde donde se había quedado y el buffer se sobreescribirá de nuevo.


## Como he organizado las metas de este ejercicio
### [main](src/main.c) que abre y cierra un archivo de prueba para pasar al get_next_line
### Función para leer de un descriptor de archivo
### Sacar una línea del get_next_line
### Guardar los caracteres extra leidos
### Juntar todo en la función get_next_line
### (Bonus) Leer de más de un *fd*

## Solución de problemas típicos
### La definición del búfer y su tamaño: **Stack Overflow**
#### ¿Que es el Stack Overflow?
Para comprender este error primero es necesario saber que la memoria *stack* está limitada según el lenguaje/compilador que se este usando, aunque en varios lenguajes/compiladores se puede establecer el tamaño solicitado.

Por lo general, los valores predeterminados (si no se configuran manualmente) son de aproximadamente 1 MB para los idiomas actuales, lo cual es suficiente a menos que haga algo que generalmente no se recomienda (como asignar matrices enormes en el stack).

Sabiendo esto ya se puede intuir que este error ocurre cuando se revasa el límite establecido en el stack.

Una de las soluciones, si es posible, es utilizar la memoria heap en su lugar la cual tiene un limite mucho mayor (dependiendo de la RAM que tenga el PC).

#### Dos formas de declarar el búfer: Array VS malloc()
<table>
    <thead>
        <tr>
            <th>Forma de Array</th>
            <th>Con Malloc</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><pre lang="c">
char	buffer[BUFFER_SIZE + 1];
<br>
reader = read(fd, buffer, BUFFER_SIZE);
</pre</td>
            <td><pre lang="c">
char	*buffer;
<br>
buffer = malloc((BUFFER_SIZE + 1) * sizeof(*buffer));
if (!buffer)
	return (NULL);
reader = read(fd, buffer, BUFFER_SIZE);
<br>
/* [some code] */
<br>
free(buffer);
</pre></td>
        </tr>
    </tbody>
</table>

#### ¿Y si no se define el BUFFER_SIZE al compilar?

### Mala liberalización de memoria



---
Made by daampuru | LinkedIn: [David Ampurua](www.linkedin.com/in/david-ampurua)
