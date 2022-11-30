# 42 Exams guide
***Gracias a @pasqualerossi***
## Table of content
***TODO***

## Exam details
### Norminette
No hay Norminette en los examenes.

### Para practicar el logeo a los exámenes
  1. Logueate en uno de los ordenadores de 42 con la cuenta de examen
     - *login*: exam
     - 	*contraseña*: exam
  2. Ejecuta el comando `examshell` en la terminal
     - *login*: Tu usuario
     - *contraseña*: Tu contraseña
  3. Habilita el *photo check*
>Una vez dentro de *examshell*, solo puedes ejecutar estos comandos:
>  - `status`. Para onsultar la hora y otras cosas
>  - `grademe`. Para la comprobación del ejercicio *push*eado (moulinet)
>  - `finish`. Para cerrar *examshell* y finalizar el examen
  1. Abre una nueva terminal
     - Veras los enunciados del examne en el directorio *subject*
     - Después, puedes ver el directorio *Rendu*. Este es tu repositorio para el examen.
     - Luego tienes que crear el directorio con el nombre del proyecto, crear los archivos que se piden (por ejemplo los .c y/o .h) y empezar a trabajar.
     - Cuando estes listo, vuelve a *Rendu* y *push*ea el directorio, para ello haz:
```bash
      git add .
      git commit -m "<insert a comment>"
      git push
      grademe
```

### For practice the exam itself
Para practicar el examen dispones de este github -> https://github.com/JCluzet/42_EXAM