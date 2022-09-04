# Breve guia sobre la compilación, los archivos objetos y la vinculación

>NOTA: Aunque los ejemplos que se van a utilizar en esta guia son para el lenguaje C, puede ser extrapolado a otros lenguajes de programación que dispongan de compilador.

Hay (en la mayoría de los casos, descontando el código interpretado) dos etapas para pasar del código fuente (lo que se escribe, p. ej. archivos *.c*) al código ejecutable (lo que se ejecuta en el PC, p .ej. archivos *.exe* o *.out*):

  1. Primero esta la **compilación**, que convierte el codigo fuente, archivos escritos en un lenguaje concreto; en archivos objeto (*.o*), archivos binarios entendibles para el tipo de ordenado/microchip que se haya elegido.
  2. Después, la **vinculación**, es lo que combina archivos objeto para formar un ejecutable.

![Flow de compilación para el lenguaje C](img/CompilationFlowForC.png)



# Referencias
  - https://www.howtogeek.com/427086/how-to-use-linuxs-ar-command-to-create-static-libraries/
  - https://subscription.packtpub.com/book/programming/9781838821135/1/ch01lvl1sec05/understanding-compilation-linking-and-object-file-contents
  - https://stackoverflow.com/questions/3996651/what-is-compiler-linker-loader
  - https://stackoverflow.com/questions/311882/what-do-statically-linked-and-dynamically-linked-mean/311889#311889
  - https://es.wikipedia.org/wiki/Ar_(Unix)
  - https://es.wikipedia.org/wiki/C%C3%B3digo_objeto

