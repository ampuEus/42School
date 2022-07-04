# ¿Qué es AppArmor?
AppArmor ("**App**lication **Armor**") es un módulo de seguridad del kernel Linux que permite al administrador del sistema restringir las capacidades de un programa. Cada programa tiene un perfil asociado que controla su capacidad de acceso a la red, sus permisos de lectura, escritura y ejecución, entre otras cosas. Este perfil puede ser creado manual o automáticamente. Complementa el modelo tradicional de control de acceso discrecional de Unix (DAC, **d**iscretionary **a**ccess **c**ontrol) proporcionando el control de acceso obligatorio (MAC, **m**andatory **a**ccess **c**ontrol).

Por ejemplo, una aplicación que está restringida en la configuración predeterminada de Ubuntu es el visor de PDF Evince. Si bien Evince puede ejecutarse como tú cuenta de usuario, solo puede realizar acciones específicas. Evince solo tiene el mínimo de permisos necesarios para ejecutar y trabajar con documentos PDF. Si se descubriera una vulnerabilidad en el procesador de PDF de Evince y abrieras un documento PDF malicioso que se apoderara de Evince, AppArmor restringiría el daño que Evince podría causar. En el modelo de seguridad tradicional de Linux, Evince tendría acceso a todo lo que usted tenga acceso. Con AppArmor, solo tiene acceso a las cosas a las que un visor de PDF necesita acceder.

[Aquí](https://wiki.debian.org/AppArmor/HowToUse) te dejo la guía oficial de cómo usar AppArmor de la página de Debian.

## AppArmor vs SELinux
AppArmor se considera una alternativa a SELinux, un programa similar pero más difícil de instalar y mantener.

Sus mayores diferencias son:

- SELinux está orientado a proteger el sistema completo, todos los objetos del sistema (ficheros, objetos IPC, redes, ...). Sin embargo AppArmor solo está orientado al sistema de ficheros.

- AppArmor implementa una política centrada en la tarea, lo que significa que los atributos de control de acceso están vinculados a las tareas y SELinux implementa una política centrada en los objetos del sistema.

Ambos sistemas usan el principio de "denegación por defecto" (todas las operaciones son denegadas a menos que esté específicamente permitida por la política). Sin embargo, cada uno lo aplica de distinta manera:

- AppArmor, al implementar una política centrada en la tarea, solo aplica el principio para aquellas tareas que controla.
- SELinux aplica el principio en todo caso.

En general podemos decir que SELinux facilita un control de acceso de grado más fino que AppArmor. Por otro lado, AppArmor es más fácil de usar que SELinux ya que la configuración es más fácil de realizar (menos extensa).
