# root, superusuario y sudo
***[English](5_Root_Superuser_Sudo.en.md) version***

En informática, el **superusuario** es una cuenta de usuario especial que se utiliza para la administración del sistema. Posee todos los derechos en todos los modos y puede hacer muchas cosas que un usuario común ni puede (cambiar el dueño o permisos a archivos, installar software, abrir puertos...).

Por convención, en la mayoría de los sistemas Linux, el usuario **root** es el nombre de superusuario predeterminado. Aunque, independientemente del nombre, lo que realmente dice si un usuario es superusuario o no es que tiene el **ID de usuario** (uid) igual a **0**.

No es recomendable utilizar el superusuario root para sesiones de uso habitual, ya que pone en riesgo el sistema al dar acceso privilegiado a los programas en ejecución. Es mejor utilizar una cuenta de usuario normal y cambiar al usuario root con el comando `su` para acceder a sus privilegios en caso de ser necesario. Aunque esto también puede ser peligroso, ya que para cambiar al usuario root ejecutando `su root` hace falta saber la contraseña del root, además de poder permanecer como usuario root indefinidamente y no solo para el ejecutar el comando en concreto que hacía falta.

Para solucionar esto, existen programas como **sudo** (**s**uper-**u**ser **do**). Este programa permite ejecutar ciertos comandos como root en las propias sesiones de los usuarios normales (que tengan el permiso para ejecutar `sudo`). De este modo no es necesario que cada usuario deba tener la contraseña del usuario root ya que la utilidad sudo solo pide la propia contraseña del usuario. Además, de que sudo registra todos los comandos `sudo` ejecutados como medida de seguridad.
