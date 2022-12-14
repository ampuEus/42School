# Push_swap : Porque Swap_push no suena tan natural
***Oficialmente terminado el xx/12/2022 / Nota xxx de 100 / [English](README.md) version***

En este proyecto se aprenderá a ordenar datos en un stack, con un conjunto limitado de instrucciones, y utilizando el menor número de instrucciones posibles. Para tener éxito, se deberá trastear con algunos de los diversos algoritmos y elegir, entre todos, el más apropiado para un ordenamiento óptimo.

## Índice
***TODO***

## Enunciado del ejercicio
Se dispone de 2 stack (llamados *a* y *b* ) y un grupo de números enteros aleatorios (en el grupo nunca habrá dos numeros iguales) de entrada que se deben ordenar.

Al **principio**, en el stack *a* estarán los números enteros y el stack *b* vacio.

El **objetivo** es ordenar los números en orden ascendeste (implementando un algoritmo de ordenación) en el stack *a*. Pero, para ello, solo se podrán usar las sigientes instrucciones:

| Instrucción            | Descripción                                                                                                          |
|------------------------|----------------------------------------------------------------------------------------------------------------------|
| sa (swap a)            | Intercambia los dos primeros elementos encima del stack a.<br>No hace nada si hay uno o menos elementos.             |
| sb (swap b)            | Intercambia los dos primeros elementos encima del stack a.<br>No hace nada si hay uno o menos elementos.             |
| ss                     | sa y sb a la vez.                                                                                                    |
| pa (push a)            | Toma el primer elemento del stack b y lo pone encima del stack a.<br>No hace nada si b está vacío.                   |
| pb (push b)            | Toma el primer elemento del stack a y lo pone encima del stack b.<br>No hace nada si b está vacío.                   |
| ra (rotate a)          | Desplaza hacia arriba todos los elementos del stack a una posición.<br>El primer elemento se convierte en el último. |
| rb (rotate b)          | Desplaza hacia arriba todos los elementos del stack a una posición.<br>El primer elemento se convierte en el último. |
| rr                     | ra y rb a la vez.                                                                                                    |
| rra (reverse rotate a) | Desplaza hacia abajo todos los elementos del stack a una posición.<br>El último elemento se convierte en el primero. |
| rrb (reverse rotate b) | Desplaza hacia abajo todos los elementos del stack a una posición.<br>El último elemento se convierte en el primero. |
| rrr                    | rra y rrb a la vez.                                                                                                  |

## Conceptos básicos a interiorizar en esta práctica
