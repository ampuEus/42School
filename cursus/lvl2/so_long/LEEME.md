# [SoLong](https://www.youtube.com/watch?v=N_dUmDBfp6k)
***Oficialmente terminado el xx/12/2023 / Nota xxx de 100 / [English](README.md) version***

Este proyecto es un pequeño juego en 2D. Está diseñado para hacerte trabajar con texturas y sprites y algunos otros elementos básicos de jugabilidad. Te ayudará a mejorar tus habilidades en estas áreas: ventanas, colores, eventos, texturas, etc.

Se va a usar la librería gráfica del campus **MiniLibX**. Esta librería se ha desarrollado internamente e incluye las herramientas básicas necesarias para abrir una ventana, crear imágenes y trabajar con eventos de teclado y ratón.

# TODO
Hacer gif del juego
> Contexto: Basado en el meme ["Bicho blanco"](https://www.youtube.com/watch?v=3FsFJ5a1k7I). Eres Twelve, el personaje de Street Fighter, en una Rave. Tienes que recolectar todos los melocotones y salvar a tu bro Q de la borrachera.
>
> Nota: Al ser un *ser de luz* como eres, flores brotarán allá por donde pises.


## Índice
- [SoLong](#solong)
- [TODO](#todo)
  - [Índice](#índice)
  - [Enunciado del ejercicio](#enunciado-del-ejercicio)
  - [Bonus](#bonus)
  - [¿Qué es la MiniLibX?](#qué-es-la-minilibx)
    - [Funciones útiles  para el proyecto](#funciones-útiles--para-el-proyecto)
  - [Pasos que yo he seguido para hacer el programa](#pasos-que-yo-he-seguido-para-hacer-el-programa)
    - [1. Gestión de errores](#1-gestión-de-errores)
    - [2. Cargar todas las imagenes necesarias](#2-cargar-todas-las-imagenes-necesarias)
    - [3. Mostrar el mapa en una ventana](#3-mostrar-el-mapa-en-una-ventana)
    - [4. Mover al personaje](#4-mover-al-personaje)
    - [5. Animar los sprites](#5-animar-los-sprites)
  - [Referencias](#referencias)
  - [Anexo: Herramientas para editar imagenes](#anexo-herramientas-para-editar-imagenes)


## Enunciado del ejercicio
  - El juego
    - El objetivo es recolectar todos los objetos del mapa y salir siguiendo la ruta más corta posible.
    - El jugador puede moverse en 4 direcciones: subir, bajar, izquierda y derecha.
    - El número de movimientos debe mostrarse en la terminal.
    - Hay que utilizar una perspectiva 2D.
    - El jugador no puede entrar dentro de las paredes.
  - La Gestión de gráficos
    - El programa mostrará la imagen en una ventana.
    - La gestión de tu ventana debe ser limpia (cambiar de ventana, minimizar, etc).
    - Pulsar la tecla ESC o pulsar la X de la ventana debe cerrar la ventana y el programa.
    - El uso de imágenes de la miniLibX es obligatorio
  - El mapa
    - Consta de 5 componentes (representados por caracteres ASCII):
      - Espacio abierto (0), Paredes (1) y objetos (C).
      - Salida del mapa (E) y posición inicial del jugador (P).
    - Obligatorio que el mapa tenga al menos un objeto y únicamente una salida y una posición inicial.
    -  Debe ser rectangular
    -  Debe estar cerrado/rodeado de muros.
    -  Debe haber un camino válido para poder recolectar los objetos y salir.

> En caso de fallos de configuración de cualquier tipo encontrados en el archivo, el programa debe terminar correctamente y devolver “Error\n” seguido de un mensaje explícito de tu elección.

## Bonus
>Se permite el uso de otras funciones para completar la parte extra,
siempre y cuando su uso se justifique durante la evaluación.

Se consiguen puntos extra si:
  - Haces que el jugador pierda cuando toque una patrulla de enemigos (N).
  - Añades algunas animaciones de sprites.
  - Muestras el contador de movimiento directamente en la pantalla en lugar de en la terminal.


## ¿Qué es la MiniLibX?
> Para una documentación completa ve a al github de [harm-smits](https://harm-smits.github.io/42docs/libs/minilibx) o [gontjarow](https://gontjarow.github.io/MiniLibX/).

MiniLibX es una biblioteca gráfica básica que permite renderizar cosas en la pantalla sin ningún conocimiento de [X-Window](https://www.x.org/wiki/) y [Cocoa](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/CocoaDrawingGuide/Introduction/Introduction.html). Permite crear ventanas, proporciona una herramienta de dibujo y imágenes y la gestión básica de eventos.

### Funciones útiles  para el proyecto
<table>
<thead>
  <tr>
    <th>Prototipo</th>
    <th>Descripción</th>
    <th>Return</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td><code>void *mlx_init()</code></td>
    <td>Inicia la conexión entre el programa y la pantalla del PC.</td>
    <td>Un identificador para identificar futuras llamadas a las rutinas de la biblioteca.</td>
  </tr>
  <tr>
    <td><code>void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)</code></td>
    <td>Crea una nueva ventana, definida en <code>mlx_ptr</code>. De las dimensiones <code>size_x</code> y <code>size_y</code> con el titulo <code>title</code> en la barra superior de la ventana.</td>
    <td><br>Éxito al crear la ventana: <code>mlx_ptr != NULL</code></br>
        <br>Error al crear la ventana: <code>mlx_ptr = NULL</code></br></td>
  </tr>
  <tr>
    <td><code>int mlx_destroy_window(void *mlx_ptr, void *win_ptr)</code></td>
    <td>Cierra la ventada con el id <code>mlx_ptr<code>.</td>
    <td>Por ahora no devuelven nada.</td>
  </tr>
  <tr>
    <td><code>int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y)</code></td>
    <td>Pinta la imagen en la ventana elegida, en la coordenada seleccionada</td>
    <td><br>Éxito: <code>img_ptr = NULL</code></br>
        <br>Error: <code>img_ptr != NULL</code></br></td>
  </tr>
  <tr>
    <td><code>void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height)</code></td>
    <td>Guarda una nueva imagen en memoria.</td>
    <td>-</td>
  </tr>
  <tr>
    <td><code>int mlx_destroy_image(void *mlx_ptr, void *img_ptr)</code></td>
    <td>Borra la imagen que se le ha indicado de la memoria.</td>
    <td>-</td>
  </tr>
  <tr>
    <td><code>int mlx_loop(void *mlx_ptr)</code></td>
    <td>NECESARIA PARA RECIVIR LOS EVENTOS. Es un bucle infinito que espera un evento para llama a una función definida por el usuario asociada con este evento.</td>
    <td>-</td>
  </tr>
  <tr>
    <td><code>int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param)</code></td>
    <td>Es la función genérica para "atrapar" los eventos y ejecutar la función asociada.</td>
    <td>-</td>
  </tr>
  <tr>
    <td><code>int mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param)</code></td>
    <td>Función particular para los eventos de teclas.</td>
    <td>-</td>
  </tr>
  <tr>
    <td><code>int mlx_expose_hook(void *win_ptr, int (*funct_ptr)(), void *param)</code></td>
    <td>Función particular para el evento cuando el usuario activa (hace focus) la ventana seleccionada.</td>
    <td>-</td>
  </tr>
  <tr>
    <td><code>int mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param)</code></td>
    <td>La función asociada será ejecutada cuando no ocurra ningún evento.</td>
    <td>-</td>
  </tr>
  <tr>
    <td><code>int mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string)</code></td>
    <td>Dibuja el texto especificado (con el color deseado), empezando en las coordenadas señaladas.</td>
    <td>.</td>
  </tr>
</tbody>
</table>

Donde:
  - `mlx_ptr` es el puntero identificador del display
  - `win_ptr` es la ventana donde se va a dibujar
  - `img_ptr` es la imagen a dibujar


## Pasos que yo he seguido para hacer el programa
### 1. Gestión de errores
Básicamente se han comprobado 3 cosas:
  - Que **el archivo existe**.
  - Que tiene la **extensión adecuada**, `.ber`.
  - Que el **mapa cumple** con **los requisitos** marcados por el ejercicio.

Para comprobar el mapa, lo he leído mediante la función `get_next_line` y la he guardado en una variable `char **` dentro de la estructura de datos que usaré en todo el juego.

### 2. Cargar todas las imagenes necesarias
Utilizando la función `mlx_xpm_file_to_image` se han cargado las imágenes necesarias para la parte gráfica del juego. Cada sprite se ha ubicado en su array correspondiente a la espera de ser utilizado en las diferentes fases del juego.

> NOTA: Una vez terminado el juego, recuerda que hay que liberar el espacio de memoria utilizado por estas imágenes mediante la función `mlx_destroy_image`.

### 3. Mostrar el mapa en una ventana
Una vez volcado el mapa y las imágenes, se ha calculado las dimensiones necesarias de la ventana del juego para poder mostrarlo. Iniciada una conecxión con la pantalla usando `mlx_init` y creada la ventana con `mlx_new_window`, se ha recorrido el mapa para pintar las texturas básicas (pared y suelo) y obtener las posiciones iniciales de cada item para ser renderizados más adelante.

### 4. Mover al personaje
Para mover al personaje se ha utilizado la función `mlx_key_hook` que ejecuta una función cada vez que el evento de "input detectado" se activa. Después, dicha función se encarga de calcular cual será la siguiente acción del personaje dependiendo del estado actual del juego y la casilla a la que se quiere ir.

### 5. Animar los sprites
Para darle "viva" a los item, se ha utilizado la función `mlx_loop_hook` que cada X segundos ejecuta la función encargada de ir modificando los sprites del buffer que se a cargado para cada item.


## Referencias
  - https://harm-smits.github.io/42docs/libs/minilibx.html
  - https://gontjarow.github.io/MiniLibX/

## Anexo: Herramientas para editar imagenes
  - [Editor básico de imágenes online](https://ezgif.com)
  - [Para separar por frames los gifs](https://ezgif.com/split)
  - [Para pasar de PNG a XPM](https://anyconv.com/png-to-xpm-converter/)

---
Hecho por daampuru | LinkedIn: [David Ampurua](https://www.linkedin.com/in/david-ampurua)
