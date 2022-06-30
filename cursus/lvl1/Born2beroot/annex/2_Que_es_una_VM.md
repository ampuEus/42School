# ¿Qué es una máquina virtual?

Una máquina virtual (VM) es algo prácticamente idéntico a un ordenador normal. Ambos tienen una CPU, RAM, un disco duro, interfaces red, ... Además de poder instalar sistemas operativos y software en ellos. La diferencia reside en que un ordenador físico usa su propio hardware, mientras que la máquina virtual toma prestados los recursos físicos de su host. Por lo tanto, una máquina virtual es solo código, un ordenador virtual dentro de un servidor físico.

El software llamado hipervisor (en este caso VirtualBox) es responsable de crear y ejecutar máquinas virtuales, así como de administrar recursos (como CPU, memoria y almacenamiento) entre ellas.

![Esquema de las capas al usar una máquina virtual](VM_layers.png)

## Ventajas de las VM
- Ejecutar un sistema operativo diferente al de la computadora física sin tener que particionar su disco duro o reiniciarlo.
- Instalar sistemas operativos antiguos, incluso si el hardware ya no es compatible.
- Llevar un sistema operativo completo en un USB, o transferir una máquina completa de una computadora a otra fácilmente.
- Desarrollar un programa diseñado para un sistema operativo diferente al de la máquina física.
- Como una VM proporciona un entorno aislado del resto del sistema, es posible ejecutar software malicioso sin riesgo para el ordenador físico. Además, es posible tomar una instantánea del estado de la VM para restaurarla como estaba en ese momento.
- Una máquina virtual (y sus discos duros) pueden congelarse, reiniciarse, copiarse, transferirse de una computadora a otra y eliminarse fácilmente.
- Tiene mucha escalabilidad, ya que permite instalar varias máquinas virtuales en un número limitado de equipos físicos, en lugar de tener que multiplicar el número de máquinas físicas. Esto ahorra en gastos, en electricidad y en tiempo de mantenimiento.

## Desventajas de las VM
- El host debe ser capaz de manejar la virtualización: muy poca RAM genera lentitud y latencia.
- Si el ordenador host falla, es posible que ya no se pueda acceder a las máquinas virtuales a menos que haya copias de seguridad en otra máquina física.
- Una Ordenador real también es más vulnerable a los ataques si ejecuta varias máquinas virtuales en lugar de un solo sistema operativo.
