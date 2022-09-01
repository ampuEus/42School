# Quick guide about compilation, object files and linking

>NOTE: Although the examples that are going to be used in this guide are for the C language, it can be extrapolated to other programming languages that have a compiler.

There are (in most cases, discounting interpreted code) two stages in getting from source code (what you write, e.g. *.c* files) to executable code (what you run on PC, e.g. *.exe* or *.out*):

  1. First there is the **compilation**, which converts the source code, files written in a specific language; in object files (*.o*), binary files understandable for the type of computer/microchip that has been chosen.
  2. Then, linking, is what combines object modules together to form an executable.

![Compilation flow for c language](img/CompilationFlowForC.png)

# Referencias
  - https://www.howtogeek.com/427086/how-to-use-linuxs-ar-command-to-create-static-libraries/
  - https://subscription.packtpub.com/book/programming/9781838821135/1/ch01lvl1sec05/understanding-compilation-linking-and-object-file-contents
  - https://stackoverflow.com/questions/3996651/what-is-compiler-linker-loader
  - https://stackoverflow.com/questions/311882/what-do-statically-linked-and-dynamically-linked-mean/311889#311889
  - https://es.wikipedia.org/wiki/Ar_(Unix)
  - https://es.wikipedia.org/wiki/C%C3%B3digo_objeto

