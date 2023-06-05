# SoLong : ¡Y gracias por todo el pescado!
***Oficialmente terminado el xx/12/2023 / Nota xxx de 100 / [English](README.md) version***

Este proyecto es un pequeño juego en 2D. Está diseñado para hacerte trabajar con texturas y sprites y algunos otros elementos básicos de jugabilidad. Te ayudará a mejorar tus habilidades en estas áreas: ventanas, colores, eventos, texturas, etc.

Se va a usar la librería gráfica del campus **MiniLibX**. Esta librería se ha desarrollado internamente e incluye las herramientas básicas necesarias para abrir una ventana, crear imágenes y trabajar con eventos de teclado y ratón.


## Índice
**TODO**


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
    - El uso de images de la miniLibX es obligatorio
  - El mapa
    - Consta de 5 componentes (representados por caracteres ASCII):
      - Espacio abierto (0), Paredes (1) y objetos (C).
      - Salida del mapa (E) y posición inicial del jugador (P).
    - Obligatorio que el mapa tenga al menos un objeto y unicamente una salida y una posición inicial.
    -  Debe ser rectangular
    -  Debe estar cerrado/rodeado de muros.
    -  Debe haber un camino válido para poder recolectar los objetos y salir.

> En caso de fallos de configuración de cualquier tipo encontrados en el archivo, el programa debe terminar correctamente y devolver “Error\n” seguido de un mensaje explícito de tu elección.

## Bonus
>Se permite el uso de otras funciones para completar la parte extra,
siempre y cuando su uso se justifique durante la evaluación.

Se consiguen puntos extra si:
  - Haces que el jugador pierda cuando toque una patrulla de enemigos.
  - Añades algunas animaciones de sprites.
  - Muestras el contador de movimiento directamente en la pantalla en lugar de en la terminal.


## ¿Qué es la MiniLibX?
> Para una documentación completa ve a al github de [harm-smits](https://harm-smits.github.io/42docs/libs/minilibx).

[X-Window system](https://www.x.org/wiki/)

### Funciones utilies para el proyecto
mlx_init
mlx_new_window
mlx_key_hook
mlx_hook
mlx_loop

## Pasos que yo he seguido para hacer el programa
### 1. Gestión de errores
Basicamente relacionados con la estructura del mapa
### 2. Leer y mostrar el mapa
gnl
### 3. Mover al personaje
### 4. Animar a los enemigos



## Referencias
  - https://harm-smits.github.io/42docs/libs/minilibx.html



https://anyconv.com/png-to-xpm-converter/
---
Hecho por daampuru | LinkedIn: [David Ampurua](https://www.linkedin.com/in/david-ampurua)

