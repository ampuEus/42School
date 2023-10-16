# Push_swap : Porque Swap_push no suena tan natural
***Oficialmente terminado el 20/09/2023 / Nota 125 de 100 / [English](README.md) version***

En este proyecto se aprenderá a ordenar datos en un stack, con un conjunto limitado de instrucciones, y utilizando el menor número de instrucciones posibles. Para tener éxito, se deberá trastear con algunos de los diversos algoritmos y elegir, entre todos, el más apropiado para un ordenamiento óptimo.

<div align="center">
<img width="600px" id="Ejemplo de estabilidad en los algoritmos de ordenación" src="./annex/img/execution_example.gif" />
</div>

## Índice
- [Push\_swap : Porque Swap\_push no suena tan natural](#push_swap--porque-swap_push-no-suena-tan-natural)
  - [Índice](#índice)
  - [Enunciado del ejercicio](#enunciado-del-ejercicio)
  - [Conceptos básicos a interiorizar en esta práctica](#conceptos-básicos-a-interiorizar-en-esta-práctica)
    - [Algoritmos de ordenación](#algoritmos-de-ordenación)
      - [Estabilidad](#estabilidad)
      - [Naturalidad](#naturalidad)
    - [Notación Big-O](#notación-big-o)
      - [Notación Bachmann–Landau](#notación-bachmannlandau)
      - [Las tasas de crecimiento más comunes (de más rápida a más lenta)](#las-tasas-de-crecimiento-más-comunes-de-más-rápida-a-más-lenta)
    - [Listas link-adas *vs* Array de enteros](#listas-link-adas-vs-array-de-enteros)
      - [Problema con la largura del array de enteros](#problema-con-la-largura-del-array-de-enteros)
    - [Algoritmo implementado: INSERTION SORT](#algoritmo-implementado-insertion-sort)
      - [Performance](#performance)
  - [Pasos que yo he seguido para hacer el ejercicio](#pasos-que-yo-he-seguido-para-hacer-el-ejercicio)
  - [Bonus: Hacer tu propio *checker*](#bonus-hacer-tu-propio-checker)
  - [Referencias](#referencias)


## Enunciado del ejercicio
Se dispone de 2 stack (llamados *a* y *b* ) y un grupo de números enteros aleatorios (en el grupo nunca habrá dos numeros iguales) de entrada que se deben ordenar.

Al **principio**, en el stack *a* estarán los números enteros y el stack *b* vacío.

El **objetivo** es ordenar los números en orden ascendente (implementando un algoritmo de ordenación) en el stack *a*. Pero, para ello, solo se podrán usar las siguientes instrucciones:

| Instrucción            | Descripción                                                                                                        |
|------------------------|--------------------------------------------------------------------------------------------------------------------|
| `sa` (swap a)          | Intercambia los dos primeros elementos encima del stack a.<br>No hace nada si hay uno o menos elementos.           |
| `sb` (swap b)          | Intercambia los dos primeros elementos encima del stack a.<br>No hace nada si hay uno o menos elementos.           |
| `ss`                   | `sa` y `sb` a la vez.                                                                                              |
| `pa` (push a)          | Toma el primer elemento del stack b y lo pone encima del stack a.<br>No hace nada si b está vacío.                 |
| `pb` (push b)          | Toma el primer elemento del stack a y lo pone encima del stack b.<br>No hace nada si b está vacío.                 |
| `ra` (rotate a)        | Desplaza hacia arriba todos los elementos del stack a una posición.<br>El primer elemento se convierte en el último.   |
| `rb` (rotate b)        | Desplaza hacia arriba todos los elementos del stack a una posición.<br>El primer elemento se convierte en el último.   |
| `rr`                   | `ra` y `rb` a la vez.                                                                                                  |
| `rra` (reverse rotate a) | Desplaza hacia abajo todos los elementos del stack a una posición.<br>El último elemento se convierte en el primero. |
| `rrb` (reverse rotate b) | Desplaza hacia abajo todos los elementos del stack a una posición.<br>El último elemento se convierte en el primero. |
| `rrr`                  | `rra` y `rrb` a la vez.                                                                                                |

La forma de evaluar el algoritmo de ordenación dependerá de los movimientos totales que ejecute para diferentes cantidades de números:
  - Para 3 valores de entrada: No se permiten más de 3 movimientos.
  - Para 5 valores de entrada: No se permiten más de 12 movimientos.
  - Para 100 valores de entrada: Se puntuará de 1 hasta 5 dependiendo de los movimientos ejecutados.
    - 5 puntos. Movimientos realizados <= 700
    - 4 puntos. 700 < movimientos <= 900
    - 3 puntos. 900 < movimientos <= 1100
    - 2 puntos. 1100 < movimientos <= 1300
    - 1 puntos. 1300 < movimientos <= 1500
  - Para 500 valores de entrada: Se puntuará de 1 hasta 5 dependiendo de los movimientos ejecutados.
    - 5 puntos. Movimientos realizados <= 5500
    - 4 puntos. 5500 < movimientos <= 7000
    - 3 puntos. 7000 < movimientos <= 8500
    - 2 puntos. 8500 < movimientos <= 10000
    - 1 puntos. 10000 < movimientos <= 11500



## Conceptos básicos a interiorizar en esta práctica
Los algoritmos de ordenación son muy útiles para aprender temas clave de la informática como la notación *Big-O*, método *divide-and-conquer* y estructuras de datos (como son árboles binarios, heaps, listas enlazadas, etc) entre otras cosas.


### Algoritmos de ordenación
Un algoritmo de ordenación sirve para reorganizar una matriz o lista de elementos dada de acuerdo con un operador de comparación en los elementos. El operador de comparación se utiliza para decidir el nuevo orden de los elementos de la estructura de datos (por ejemplo, orden ascendente o descendente).

#### Estabilidad
>NOTA: Aunque en esta práctica, no al no haber números repetidos, saber lo que significa la estabilidad en los algoritmos de ordenación no tenga sentido siempre está bien saber algo más.

Un algoritmo de ordenación **es estable si conserva el orden original de los elementos con valores clave iguales** (donde la clave es el valor por el que ordena el algoritmo). Por ejemplo:

<div align="center">
<img width="400px" id="Ejemplo de estabilidad en los algoritmos de ordenación" src="annex/img/Sorting_stability_playing_cards.png" />
</div>

Cuando las cartas se clasifican por valor con una clasificación estable, los dos 5 deben permanecer en el mismo orden en la salida clasificada en la que estaban originalmente. Cuando se clasifican con una clasificación no estable, los 5 pueden terminar en el orden opuesto.

#### Naturalidad
Un algoritmo de ordenación se dice que **es natural cuando su tiempo de ejecución mejora considerablemente si los datos de entrada están ordenados o casi ordenados**.


### Notación Big-O
**IMPORTANTE:** La notación Big O es una notación que se usa cuando se habla de tasas de crecimiento. **No dice la velocidad de ejecución de un algoritmo** (ya que hay muchas variables como la CPU en la que se ejecuta o el lenguaje en el que está escrito), si no que **formaliza la noción entre dos funciones** que "crecen al mismo ritmo", o que una función "crece más rápido que la otra", y cosas por el estilo. **Ya que muestra el total de operaciones (para el peor caso) que se van a hacer**.

Para ignorar las diferencias en la implementación, se utiliza su **tasa de crecimiento asintótica**. Dado un consumo de recursos de *f*, encontramos una función simple *g* tal que *f=Θ(g)*. Donde *Θ* equivale a diferentes implementaciones, por lo que hay que ver qué valor toma *g* (por ejemplo, tiempo lineal *g(n)=n*, tiempo cuadrático *g(n)=n2*, etc.). Es importante recalcar que esto no altera el comportamiento de *g* diferentes tamaños de entrada, duplicar el valor de entrada dará como resultado el mismo comportamiento en *g* (doblándolo para *g(n)=n*, cuatriplicándolo para *g(n)=n2*, y así sucesivamente). Así desde el punto de vista del análisis de algoritmos, no se pierde información por simplificar *f* en *g*, ya que ambos tienen el mismo comportamiento. Esto permite comparar diferentes algoritmos según sus tasas de crecimiento y afirmar que un algoritmo es "más rápido" que otro. Por ejemplo, si hay dos algoritmos con consumos de recursos *f1*, *f2*, con valores *f1=Θ(g1)*, *f2=Θ(g2)*, entonces el primer algoritmo es más rápido que el segundo si *g1=o(g2)*.

#### Notación Bachmann–Landau
| Ecuación | Nombre       | Significado                                                         |
|----------|--------------|---------------------------------------------------------------------|
| f = O(g) | big-oh       | Si eventualmente *f* crece más lento que algún múltiplo de *g*      |
| f = o(g) | little-oh    | Si eventualmente *f* crece más lento que cualquier múltiplo de *g*  |
| f = Ω(g) | big-omega    | Si eventualmente *f* crece más rápido que algún múltiplo de *g*     |
| f = ω(g) | little-omega | Si eventualmente *f* crece más rápido que cualquier múltiplo de *g* |
| f = Θ(g) | theta        | Si finalmente *f* crece al mismo ritmo que *g *                     |

#### Las tasas de crecimiento más comunes (de más rápida a más lenta)
| Ecuación | Descripción | Ejemplo |
|---|---|---|
| O(1) | El algoritmo de tiempo constante se ejecuta en un tiempo constante sin importar cuán grande sea la entrada | Programas que ignoran su entrada y calculan la respuesta a un problema específico |
| O(log log n) | Orden sublogarítmica |  |
| O(log n) | El algoritmo de tiempo logarítmico se ejecuta en un tiempo proporcional al logaritmo de la entrada | Binary search |
| O(√n) | Orden sublineal |  |
| O(n) | El algoritmo de tiempo lineal se ejecuta en un tiempo proporcional a la entrada | Simple search |
| O(n * log n) | Un algoritmo de tiempo lineal rítmico se ejecuta en un tiempo que no se distingue particularmente del tiempo lineal para una entrada "razonable" | Quicksort, Merge Sort, Heap Sort, Tree sort |
| O(n^2) | Los algoritmos de tiempo cuadrático toman un tiempo proporcional al cuadrado de la entrada | Selection sort, Insertion sort, Bubble sort |
| O(n^3) | Un algoritmo de tiempo cúbico probablemente tendrá la estructura de un ciclo a través de *n* valores dentro de otro ciclo de *n* valores dentro de un tercer ciclo de *n* valores |  |
| O(n^c) | Orden potencial fija |  |
| O(a^n), n > 1 | Para un algoritmo de tiempo exponencial, aumentar la entrada en uno es suficiente para multiplicar el tiempo de ejecución del algoritmo (por a). Tenga en cuenta que si a < b, entonces a^n=o(b^n) | Resolver la fórmula booleana de *n* variables. Para probar cada posibilidad requiere que se verifiquen *2^n* casos |
| O(n!) | Algoritmos que verifican cada permutación de una matriz, en la que hay n! de ellos | Traveling salesperson |
| O(n^n) | Orden potencial exponencial |  |

<div align="center">
<img width="400px" id="Ejemplo de algunas tasas de crecimiento comunes" src="annex/img/Comparison_computational_complexity.png" />
</div>

### Listas link-adas *vs* Array de enteros
Teniendo en cuenta las cualidades que tienen las listas pudiendo aumentarse y reducirse en el tiempo de ejecución debido a su **organización dinámica** realizada al asignar y no asignar memoria. Esto hace que **no** sea **necesario preasignar memoria** a la hora de definirla. A diferencia de un array que sí se necesita saber sus dimensiones desde el inicio.

Además, las listas vinculadas se pueden **reorganizar** sin necesidad de realojar el array entero en cada movimiento, ya que solo hay que **cambiar la dirección del puntero al siguiente nodo** de la lista.

Por el contrario, en una lista no se pueden implementar un Binary search y la búsqueda de datos es más engorrosa ya que a un array con pasar la posición del dato es suficiente.

#### Problema con la largura del array de enteros
Si la matriz es una variable global, estática o automática (`int matriz[10];`), entonces funciona `sizeof(array)/sizeof(array[0])`.

Si es una matriz asignada dinámicamente (`int* matriz = malloc(sizeof(int)*10);`) o se pasa como un argumento de función (`void f(int matriz[])`), entonces no puede encontrar su tamaño en tiempo de ejecución. Por lo que se tiene que guardar en algún lugar.

>NOTA: `sizeof(array)/sizeof(array[0])` se compila perfectamente incluso para el segundo caso, pero producirá un resultado erróneo.


### Algoritmo implementado: INSERTION SORT
He usado este algoritmo de ordenación ya que me ha parecido el más intuitivo y fácil de implementar. La idea básica es dividir los valores de entrada en 2 listas, la lista desordenada de entrada (stack_a) y otra ordenada (stack_b). En esta práctica la lista ordenada será inversamente ordenada, para que al volver a pasarlos al stack_a los valores queden ordenados.

**Los valores de la lista no ordenada se van seleccionando uno por uno y colocando en su posición correcta en la lista ordenada.** En el ejemplo de abajo los números con el recuadro negro serían la lista ordenada y los que no tienen recuadro la lista desordenada:

<div align="center">
<img width="300px" id="Ejemplo grafico del insertion sort" src="./annex/img/Insertion-sort-example-300px.gif" />
</div>

Para que esto se haga de la forma más eficiente posible, en cada nueva iteración hay que calcular el coste de mover cada valor a su posición correcta de la lista ordenada y mover el que menos coste suponga.

#### Performance
>NOTA:
>Algunos algoritmos dan comportamientos diferentes cuando se les da una entrada diferente. Por ello, para análisis de algoritmos se suelen buscar los siguientes tiempos de ejecución, dadas diferentes entradas de un tamaño específico:
>  - **El peor de los casos**. Es el tiempo más largo para una entrada específica
>  - **El caso promedio**. Es el tiempo promedio para todas las entradas.
>  - A veces también se analiza **el mejor tiempo de ejecución del caso**.


## Pasos que yo he seguido para hacer el ejercicio
  1. Hacer una correcta gestión de los valores de entrada.
     - Detectar si la sintaxis de los valores de entrada es la correcta
     - Detectar cuando un número es tan grande que no cabe en un `int`
     - Pasar los números de cadena de caracteres a `int` + Detectar valores erróneos
     - Detectar si hay números repetidos
  2. Definir la estructura que tendrá la lista (si vas a usar arrays, eres un fumau de la vida y si vas a usar las listas que hiciste para el libft ya mezclas drogas con alcohol)
  3. Hacer las funciones auxiliares para la gestión de la estructura (`lstnew`, `lstadd`, `lstlast`...)
  4. Hacer las funciones de todas las reglas de movimientos (`sa`, `pb`, `ra`...)
  5. Hacer un primer algoritmo de ordenación **super simple** para ver que este todo ok
  6. (Opcional, pero **MUY** recomendable) Implementar algún tipo de visualizador ya sea tuyo o de terceros como [visualizer](https://github.com/o-reo/push_swap_visualizer/tree/75c535c5d44e984dcb7d7f48bc9a144beb5e66ae)
  7. Implementar el algoritmo de ordenación que deseas
  8. Comparar el resultado con los *checker* dados.

PD: Aquí te dejo una [web](https://pinetools.com/es/generador-numeros-aleatorios) para la generación de números aleatorios.


## Bonus: Hacer tu propio *checker*
Este apartado yo lo he afrontado en 2 etapas:
  1. He tenido que modificar mi makefile para poder compilar por un lado el binario del `push_swap` y por otro el del `checker`
  2. Basandome en la función `main` del `push_swap` he cambiado la logica de `sort` por el checkeo que pide el enunciado siguiendo este flujo:

<div align="center">
<img width="300px" id="Flujo para el checkeo de las ordenes del push_swap" src="./annex/img/CheckerFlow.es.png" />
</div>

## Referencias
  - https://www.geeksforgeeks.org/sorting-algorithms/
  - https://brilliant.org/wiki/sorting-algorithms/
  - https://www.freecodecamp.org/news/sorting-algorithms-explained-with-examples-in-python-java-and-c/
  - https://www.freecodecamp.org/news/big-o-notation-explained-with-examples/
  - https://sbme-tutorials.github.io/2018/data-structures/data-structures.html
  - https://www.educba.com/linked-list-advantages/

---
Hecho por daampuru | LinkedIn: [David Ampurua](https://www.linkedin.com/in/david-ampurua)
