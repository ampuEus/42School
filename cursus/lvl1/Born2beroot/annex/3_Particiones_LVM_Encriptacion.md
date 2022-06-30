# Partitions, LVM and Encryption
## ¿Por qué tener varias particiones?
Desde el punto de vista de funcionamiento es indiferente tener todos los datos en una única partición o en varias. Lo que se consigue segmentado la información es protegerse de la corrupción o rotura de la partición ya que, si se tiene una para cada cosa, aunque deje de funcionar una aun se pueden recuperar los datos del resto de particiones y el daño es menor.
Particiones para cumplir con la parte obligatoria:
- **boot**. Se ubican los ficheros estáticos utilizados por el cargador de arranque
- **root**. Es el directorio Home para el usuario root
- **home**. Aquí están los directorios del resto de los usuarios
- [**swap**](https://wiki.debian.org/Swap). Se trata de una partición especial que esencialmente es un complemento de memoria a la RAM del ordenador

Particiones para cumplir con el bonus:
- **var**. Se guardan datos de variables
- **srv**. Se guardan datos de los servicios ofrecidos por el sistema
- **tmp**. Es el directorio para los archivos temporales
- **var/log**. Dentro del directorio var existe esta carpeta donde se guardan los logs

[Aquí](https://www.debian.org/releases/bullseye/amd64/apcs02.es.html) puede aprender un poco más sobre el árbol de directorios de Debian.

## ¿Qué es [LVM](https://wiki.debian.org/es/LVM)?
**Logical Volume Manager** (LVM) es un sistema de gestión flexible y dinámico para la memoria del disco duro de Linux. Nos permite tener tantas particiones como necesitemos, y redimensionarlas, moverlas e incluso congelarlas, sin necesidad de reiniciar la máquina. Este sistema de “particionamiento virtual” es muy útil en un servidor, que debe preservar la estabilidad y la gestión rápida de sus recursos de memoria.
