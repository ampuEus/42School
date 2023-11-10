# Minishell: Tan bonito como shell
***Oficialmente terminado el xx/06/2023 / Nota xxx de 100 / [English](README.md) version***

El objetivo de este proyecto es que crees un shell sencillo. Sí, tu propio pequeño bash. Aprenderás un montón sobre procesos y file descriptors.

## Índice
- [Minishell: Tan bonito como shell](#minishell-tan-bonito-como-shell)
  - [Índice](#índice)
  - [Enunciado del ejercicio](#enunciado-del-ejercicio)
    - [Reglas](#reglas)
    - [Funcionalidades a implementar](#funcionalidades-a-implementar)
    - [Funcionalidades BONUS a implementar](#funcionalidades-bonus-a-implementar)
  - [Conceptos básicos a interiorizar en este proyecto: ¿Cómo funciona Shell?](#conceptos-básicos-a-interiorizar-en-este-proyecto-cómo-funciona-shell)
    - [Flujo general de shell](#flujo-general-de-shell)
    - [Reconocimiento de tokens](#reconocimiento-de-tokens)
  - [Referencias](#referencias)

## Enunciado del ejercicio
### Reglas
  - **Mostrar una entrada** mientras espera un comando nuevo
  - Implementar un **historial** funcional
  - Buscar y ejecutar el ejecutable correcto (basado en la variable PATH o mediante el uso de rutas relativas o absolutas)
  - No usar más de **una variable global**
  - No interpretar comillas sin cerrar o caracteres especiales no especificados en el enunciado como '\' (barra invertida) o ';' (punto y coma)
  - Gestionar que la '’' evite que el shell interprete los metacaracteres en la secuencia entrecomillada
  - Gestionar que la '"' evite que el shell interprete los metacaracteres en la secuencia entrecomillada, exceptuando '$' (signo de dólar)

### Funcionalidades a implementar
  - Redirecciones:
    - `<` redirige el *input*
    - `>` redirige el *output*
    - `<<` debe recibir un delimitador, después leer del input de la fuente actual hasta llegar a una línea que solo tenga dicho delimitado. **No necesita actualizar el historial**.
    - `>>` redirige el *output* en modo *append* para el archivo dado
  - Pipes (`|`). El *output* de cada comando en la pipeline es el *input* del siguiente
  - Gestionar las variables de entorno ('$' seguidos de caracteres) que deberán expandirse a sus valores
  - Gestionar `$?`, deberá expandirse al estado de salida del comando más reciente ejecutado en la pipeline
  - `ctrl-C`, `ctrl-D` y `ctrl-\`, que deberán funcionar como en `bash`
    - Cuando sea interactivo:
      - `ctrl-C` imprime una nueva entrada en una línea nueva
      - `ctrl-D` termina el shell
      - `ctrl-\` no hace nada
  - Los siguientes *built-in*:
    - `echo` con la opción `-n`
    - `cd` solo con una ruta relativa o absoluta
    - `pwd` sin opciones
    - `export` sin opciones
    - `unset` sin opciones
    - `env` sin opciones o argumentos
    - `exit` sin opciones

### Funcionalidades BONUS a implementar
  - Los operadores `&&` y `||` (*and* y *or* respectivamente) con paréntesis para prioridades.
  - Los wildcards `*` deben funcionar para el directorio actual

## Conceptos básicos a interiorizar en este proyecto: ¿Cómo funciona Shell?
### Flujo general de shell
***TODO poner una imagen explicando el flujo de forma gráfica***

  1. La shell **lee desde**:
     - Un archivo
     - La opción `-c`
     - Las funciones `system()` and `popen()`
> Si la primera línea de un archivo de comandos de shell comienza con los caracteres "#!", el resultado no está controlado.
  2. La shell **divide la entrada en tokens** (Ver [Reconocimineto de tokens](#reconocimiento-de-tokens)):
     - Palabras
     - Operadores
  3. La shell **analiza la entrada** en [comandos simples](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_09_01) y [comandos compuestos](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_09_04).
  4. La shell **realiza las expansiones** necesarias (por separado) en cada comando, dando como resultado una lista de nombres de rutas y campos que se tratarán como un comando y argumentos.
  5. La shell **realiza las [redirecciones](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_07)** necesarias y elimina los operadores de redirección y sus operandos de la lista de parámetros.
  6. La shell **ejecuta** la lista de parámetros, en ella puede var:
     - Funciones
     - *Built-in*
     - Archivos ejecutables o scripts, proporcionando los nombres de los argumentos como parámetros posicionales numerados del 1 al n, y el nombre del comando
  7. [Opcionalmente] La shell espera a que se complete el comando y **recopila el [estado de salida](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_08_02)**

### Reconocimiento de tokens


## Referencias
  - https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_08
  - https://www.gnu.org/software/libc/manual/html_node/Implementing-a-Shell.html
  - https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf
  - https://brennan.io/2015/01/16/write-a-shell-in-c/
  - https://blog.ehoneahobed.com/building-a-simple-shell-in-c-part-1
  - https://blog.ehoneahobed.com/building-a-simple-shell-in-c-part-2
  - https://blog.ehoneahobed.com/building-a-simple-shell-in-c-part-3
  - https://blog.ehoneahobed.com/building-a-simple-shell-in-c-part-4

---
Hecho por lbengoech y daampuru | LinkedIn: [Laura Bengoechea]() y [David Ampurua](https://www.linkedin.com/in/david-ampurua)
