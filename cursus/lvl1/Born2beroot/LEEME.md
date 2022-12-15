# Born2beroot
***Oficialmente terminado el 08/07/2022 / Nota 125 de 100 / [English](README.md) version***

Esta práctica es una introducción a la administración de sistemas. En esta prática se han interiorizado los principios de:

- La creación de **maquinas virtuales**
- La **instalación de SO** con unas reglas de particiones y encriptación estrictas
- **Seguridad**. Con la implementación de sudo, un firewall y una política de contraseñas fuerte
- **Acceso remoto**. Implementando un servidor SSH
- **Gestión de usuarios**. Trabajando con usuarios, grupos y sus privilegios
- **Monitorización**. Sabiendo como extraer información sobre la maquina (RAM disponible, número de conexiones activas, comandos ejecutados mediante sudo...)


## Software utilizado[^1]
- VM: [VirtualBox](https://www.virtualbox.org/) 6.1
- OS: [Debian bullseye](https://cdimage.debian.org/debian-cd/current/amd64/iso-cd/) 11.3.0 ([Debian vs CentOS](annex/1_Debian_VS_CentOS.es.md))


## Índice:
  - [1. CREACIÓN DE LA MÁQUINA VIRTUAL](#1-creación-de-la-máquina-virtual)
    - [1.1. INSTALANDO DEBIAN EN LA VM](#11-instalando-debian-en-la-vm)
      - [1.1.1. PARTICIÓN MANUAL](#111-partición-manual)
      - [1.1.2. ENCRIPTACIÓN DE DISCO](#112-encriptación-de-disco)
      - [1.1.3. CONFIGURANDO LVM](#113-configurando-lvm)
        - [1.1.3.1. Creación de grupo de volúmenes lógicos](#1131-creación-de-grupo-de-volúmenes-lógicos)
        - [1.1.3.2. Creación de volumen lógico](#1132-creación-de-volumen-lógico)
        - [1.1.3.3. Configurando las particiones](#1133-configurando-las-particiones)
        - [1.1.3.4. Instalando sistema base de Debian](#1134-instalando-sistema-base-de-debian)
    - [1.2. ACCEDIENDO A Born2beroot](#12-accediendo-a-born2beroot)
  - [2. CONFIGURANDO UN DEBIAN COMO SERVIDOR](#2-configurando-un-debian-como-servidor)
    - [2.1. IMPLEMENTACIÓN DE sudo](#21-implementación-de-sudo)
      - [2.1.1. INSTALACIÓN de sudo](#211-instalación-de-sudo)
      - [2.1.2. CONFIGURACIÓN DE sudo](#212-configuración-de-sudo)
    - [2.2. IMPLEMENTACIÓN DE AppArmor: Limitación de sudo](#22-implementación-de-apparmor-limitación-de-sudo)
    - [2.3. IMPLEMENTACIÓN DE UFW](#23-implementación-de-ufw)
      - [2.3.1 INTALACIÓN Y ACTIVACIÓN](#231-intalación-y-activación)
      - [2.3.2. GESTIÓN DE LAS REGLAS](#232-gestión-de-las-reglas)
    - [2.4. IMPLEMENTACIÓN DE UN SERVIDOR SSH EN Born2beroot](#24-implementación-de-un-servidor-ssh-en-born2beroot)
      - [2.4.1. INSTALAR](#241-instalar)
      - [2.4.2. CONFIGURAR EL SERVIDOR SSH](#242-configurar-el-servidor-ssh)
      - [2.4.3. REDIRECCIONAMIENTO DE PUERTOS CON VIRTUALBOX](#243-redireccionamiento-de-puertos-con-virtualbox)
      - [2.4.4. CONEXIÓN A UN SERVIDOR SSH](#244-conexión-a-un-servidor-ssh)
    - [2.5. MONITORIZACIÓN DEL SERVIDOR](#25-monitorización-del-servidor)
      - [2.5.1. ENVIAR UN MENSAJE A CADA TERMINAL](#251-enviar-un-mensaje-a-cada-terminal)
      - [2.5.2. ENVIAR EL MENSAJE CADA 10 MINUTOS](#252-enviar-el-mensaje-cada-10-minutos)
      - [2.5.3. CALCULAR CUANDO SE HA INICIADO EL SISTEMA](#253-calcular-cuando-se-ha-iniciado-el-sistema)
    - [2.6. IMPLEMENTACIÓN DE UN SISTEMA FUERTE DE CONTRASEÑAS](#26-implementación-de-un-sistema-fuerte-de-contraseñas)
    - [2.7. GESTIÓN DEL HOSTNAME, USUARIOS Y GRUPOS](#27-gestión-del-hostname-usuarios-y-grupos)
      - [2.7.1. MODIFICAR EL HOSTNAME](#271-modificar-el-hostname)
      - [2.7.2. GESTIÓN DE USUARIOS](#272-gestión-de-usuarios)
      - [2.7.3. GESTIÓN DE GRUPOS](#273-gestión-de-grupos)
  - [3. PARTE BONUS](#3-parte-bonus)
    - [3.1. PHP](#31-php)
    - [3.2. LIGHTTPD](#32-lighttpd)
      - [3.2.1 ACTIVACIÓN de FastCGI (**Fast** **C**ommon **G**atewway **I**nterface)](#321-activación-de-fastcgi-fast-common-gatewway-interface)
    - [3.3. MariaDB](#33-mariadb)
    - [3.4. WORDPRESS](#34-wordpress)
    - [3.5. SERVICIO EXTRA: Fail2Ban](#35-servicio-extra-fail2ban)
  - [EXTRA: POSIBLES ERRORES](#extra-posibles-errores)
      - [\*ERROR\* Failed to send host log message](#error-failed-to-send-host-log-message)
  - [Repositorios útiles de otros estudiantes](#repositorios-útiles-de-otros-estudiantes)

## 1. CREACIÓN DE LA MÁQUINA VIRTUAL
Para crear una nueva [máquina virtual](annex/2_Que_es_una_VM.md) ve a la parte superior de la ventana principal de VirtualBox, haz clic en **Nuevo** para comenzar.

![Imagen de VirtualBox](img/1_StartWindow.png)

Ponle un nombre a la máquina, decide dónde instalarla y especifica qué linux se va a instalar en la VM (en mi caso, Debian). Si vas a utilizar los equipos de tu cluster de 42 por razones de espacio, tienes que ubicarla en **/sgoinfre/goinfre/Perso/your_42_login**. Otra opción puede ser colocarlo en un USB con suficiente espacio o en un disco duro externo.

![Imagen de VirtualBox](img/2_CfgPage1.png)

Como no se van a instalar programas que vayan a consumir mucha RAM, como puede ser el entorno grafico u otros tipos de utilidades que están corriendo en segundo plano, los **1024MB** que están por defecto **son suficientes**, pero para asegurar yo le **he puesto el doble 2GB**.

![Imagen de VirtualBox](img/3_CfgPage2.png)

Ahora hay que elegir la opción de **crear un nuevo disco duro virtual**.

![Imagen de VirtualBox](img/4_CfgPage3.png)

Aquí se dejará la partición por defecto de VirtualBox, **VirtualBox Disk Image**.

![Imagen de VirtualBox](img/5_CfgPage4.png)

La opción por defecto de dejar que el disco duro **se asigne dinámicamente** está bien.

![Imagen de VirtualBox](img/6_CfgPage5.png)

Para el tamaño del disco duro, **12 GB son suficientes** tanto para las partes obligatorias como para las adicionales. Ten en cuenta que cuanto más grande sea el tamaño del disco, más tiempo llevará la creación de la firma, algo no conveniente para la evaluación de Born2beroot.

![Imagen de VirtualBox](img/7_CfgPage6.png)

Fin, machina virtual Born2beroot creada.

![Imagen de VirtualBox](img/8_VMcreationEnd.png)

### 1.1. INSTALANDO DEBIAN EN LA VM
Antes de ejecutar la maquina virtual, al no tener este ningún sistema operativo, hay que asignarle el .iso de OS que te has descargado para poder boot-ear desde él.

|![Imagen de VirtualBox](img/9_BootISO1.png)|![Imagen de VirtualBox](img/10_BootISO2.png)|![Imagen de VirtualBox](img/11_BootISO3.png)|
|-|-|-|

Una vez hecho esto, al arrancar la VM te aparece el menú de instalación de Debian con diferentes opciones. A ti te interesa una de las 2 primeras: Graphical install o Install. Las dos sirven para instalar el OS solo que la primera tiene una interfaz gráfica algo más simple. En este caso, se usará la opción de siempre “**Install**”, aunque la forma de proceder es muy parecida en cualquiera de las 2 opciones

![Imagen de VirtualBox](img/12_InstalationMenu.png)

El primer paso es elegir el lenguaje de instalación que tú quieras, en mi caso lo dejaré en **inglés**.

![Imagen de VirtualBox](img/13_InstalationCfg1.png)

Después toca elegir tú región geográfica (para temas relacionados con la zona horaria, formatos de números, texto…). **Para el objetivo de este ejercicio es indiferente**.

![Imagen de VirtualBox](img/14_InstalationCfg2.png)

Ahora hay que elegir la distribución de teclado que quieras usar [más info](https://es.wikipedia.org/wiki/Distribuci%C3%B3n_del_teclado), en mi caso, yo uso un teclado basado en la distribución española.

![Imagen de VirtualBox](img/15_InstalationCfg3.png)

En cuanto al nombre de la máquina, el ejercicio especifica que el nombre debe estar compuesto por **tú login de la intra seguido de 42**.

![Imagen de VirtualBox](img/16_InstalationCfg4.png)

El nombre de dominio no es necesario configurarlo en esta práctica, así que **déjalo en blanco**.

![Imagen de VirtualBox](img/17_InstalationCfg5.png)

Para la contraseña del usuario root, tienes que definir una contraseña fuerte siguiendo las normas que establece el enunciado de este ejercicio.

![Imagen de VirtualBox](img/18_InstalationCfg6.png)

Una vez configurado el administrador, toca crear un usuario. El nombre, recomendable que sea tú login de la intra, ya que es el usuario que se va a evaluar, y la contraseña que tiene que seguir las mismas normas que la contraseña del root.

|![Imagen de VirtualBox](img/19_InstalationCfg7.png)|![Imagen de VirtualBox](img/20_InstalationCfg8.png)|![Imagen de VirtualBox](img/21_InstalationCfg9.png)|
|-|-|-|

#### 1.1.1. PARTICIÓN MANUAL
Ahora toca particionar el disco. Aunque el instalador de diferentes opciones, las particiones que se piden en la parte obligatoria y en el bonus obligan a usas el **modo manual**. [más información sobre las particiones, LVM y la encriptación](annex/3_Particiones_LVM_Encriptacion.md)

![Imagen de VirtualBox](img/22_InstalationCfg10.png)

Ahora hay que elegir el disco donde se van ha crear las particiones (solo debería de haber uno llamado “**SCSIX (0,0,0) (sda) - […] HARDDISK**”). Vas a tener que crear 2 particiones una para el boot loader y otra partición cifrada donde estarán los volúmenes LVM.

|![Imagen de VirtualBox](img/23_InstalationCfg11.png)|![Imagen de VirtualBox](img/24_InstalationCfg12.png)|
|-|-|

En el siguiente paso se te mostrará la nueva tabla de particiones creada donde hay que ir haciendo la segmentación que se quiere. La primera partición que se va ha crear va ha ser la de boot, que NO debe estar encriptada, ya que si no ni siquiera te arrancaría el OS. Selecciona el **espacio libre** que hay en el disco.

![Imagen de VirtualBox](img/25_InstalationCfg13.png)

Crea una **nueva partición**.

![Imagen de VirtualBox](img/26_InstalationCfg14.png)

Un espacio de **500 MB** debería ser suficiente.

![Imagen de VirtualBox](img/27_InstalationCfg15.png)

La partición debe ser de tipo **primaria**.

![Imagen de VirtualBox](img/28_InstalationCfg16.png)

Y, el boot, es recomendable crearlo al **inicio**.

![Imagen de VirtualBox](img/29_InstalationCfg17.png)

Ahora hay que decirle para que se va ha utilizar la partición, en este caso se **montará** como **/boot**.

|![Imagen de VirtualBox](img/30_InstalationCfg18.png)|![Imagen de VirtualBox](img/31_InstalationCfg19.png)|
|-|-|

Por último, se da a **aceptar**. Ya has creado la partición de arranque.

![Imagen de VirtualBox](img/32_InstalationCfg20.png)

Ahora toca crear la partición LVM donde estarán todos los demás volúmenes. Así que selecciona el espacio libre que queda y crear una nueva partición.

|![Imagen de VirtualBox](img/33_InstalationCfg21.png)|![Imagen de VirtualBox](img/34_InstalationCfg22.png)|
|-|-|

En cuanto al tamaño, selecciona el espacio restante del disco.

![Imagen de VirtualBox](img/35_InstalationCfg23.png)

Esta vez será de tipo **lógica**.

![Imagen de VirtualBox](img/36_InstalationCfg24.png)

Y para el punto de montaje **no hay que definir nada** y darle a **hecho**. Más Adelante volverás a esta partición y la modificarás para cumplir con los volúmenes exigidos por el enunciado.

|![Imagen de VirtualBox](img/37_InstalationCfg25.png)|![Imagen de VirtualBox](img/38_InstalationCfg26.png)|![Imagen de VirtualBox](img/39_InstalationCfg27.png)|
|-|-|-|

#### 1.1.2. ENCRIPTACIÓN DE DISCO
Tras crear la partición para el LVM toca encriptarla, para ello ve a encriptar volúmenes.

![Imagen de VirtualBox](img/40_InstalationCfg28.png)

Si tienes dos particiones como aparece en la imagen dale a **sí**.

![Imagen de VirtualBox](img/41_InstalationCfg29.png)

Y empieza a **encriptar las particiones**, no olvides que la partición que contiene el arranque no hay que encriptarla.

![Imagen de VirtualBox](img/42_InstalationCfg30.png)

**Selecciona** (poniendo te encima y presionando la tecla de espacio) la partición para **LVM** y **continua**.

![Imagen de VirtualBox](img/43_InstalationCfg31.png)

Después clica en **hecho, finalizar** y **sí**. Y espera a que el proceso de encriptación termine.

|![Imagen de VirtualBox](img/44_InstalationCfg32.png)|![Imagen de VirtualBox](img/45_InstalationCfg33.png)|![Imagen de VirtualBox](img/46_InstalationCfg34.png)|
|-|-|-|

Una vez que el instalador termine de cifrar los datos de la partición, tienes que **elegir una contraseña** de desencriptado. Esta contraseña debe ser segura y no puedes olvidarla, de lo contrario no podrás acceder a la máquina Born2beroot.

![Imagen de VirtualBox](img/47_InstalationCfg35.png)

#### 1.1.3. CONFIGURANDO LVM
##### 1.1.3.1. Creación de grupo de volúmenes lógicos
Es hora de crear los volúmenes lógicos que pide el ejercicio dentro de la partición encriptada.

|![Imagen de VirtualBox](img/48_InstalationCfg36.png)|![Imagen de VirtualBox](img/49_InstalationCfg37.png)|
|-|-|

Para que LVM pueda administrar volúmenes lógicos, primero hay que crear un grupo de volúmenes.

![Imagen de VirtualBox](img/50_InstalationCfg38.png)

Ahora debes **asignarle un nombre al grupo**, en mi caso usaré el mismo que se usa en el enunciado del ejercicio “LVMGroup”.

![Imagen de VirtualBox](img/51_InstalationCfg39.png)

Por último, **selecciona SOLO** la **partición** que has **encriptado** a el grupo, NO asignes la partición de arranque.

![Imagen de VirtualBox](img/52_InstalationCfg40.png)

##### 1.1.3.2. Creación de volumen lógico
Ahora que tienes el grupo de volúmenes creado y la partición lógica cifrada está asignada a él, hay que crear los volúmenes lógicos uno por uno. Como ejemplo haré la root, que debe estar presente tanto para las partes obligatorias como para las de bonificación. Para ello ve a **crear volumen lógico**.

![Imagen de VirtualBox](img/53_InstalationCfg41.png)

Selecciona el grupo **donde** vas a **albergar la partición**.

![Imagen de VirtualBox](img/54_InstalationCfg42.png)

Y asígnale un **nombre** y un **espacio en disco**. En mi caso lo llamaré "root" y un tamaño de 3GB tendría que ser suficiente para cumplir con los objetivos de la práctica obligatoria y bonus.

|![Imagen de VirtualBox](img/55_InstalationCfg43.png)|![Imagen de VirtualBox](img/56_InstalationCfg44.png)|
|-|-|

Y listo, ya se ha creado la primera partición. Ahora solo te queda repetir el proceso…

1.	Crear un volumen lógico
2.	Elegir el grupo
3.	Darle un nombre
4.	Asignarle un espacio en disco (más abajo tienes una captura de como he organizado yo los tamaños de las distintas particiones[^2])

…hasta tener todas las particiones que pide el ejercicio (yo te recomiendo hacer también los de la parte bonus), cuando hayas acabado de particionar dale a terminar.

![Imagen de VirtualBox](img/57_InstalationCfg45.png)

##### 1.1.3.3. Configurando las particiones
Una vez creados los volúmenes toca asignarles una “tarea” dentro del OS. Para que, en este caso Debian, pueda usarlos como corresponda. Para hacer esto se tienen que especificar el file system y punto de montaje de para volumen.

Como ejemplo, volveré a utilizar la partición root.

![Imagen de VirtualBox](img/58_InstalationCfg46.png)

Al querer decirle al OS como tiene que usar la partición voy a clicar en usar **como:..**

![Imagen de VirtualBox](img/59_InstalationCfg47.png)

Elijo el *file system Ext4**.

![Imagen de VirtualBox](img/60_InstalationCfg48.png)

Y en cuanto al **punto de montaje**, elijo el que le corresponde a la partición **root**.

|![Imagen de VirtualBox](img/61_InstalationCfg49.png)|![Imagen de VirtualBox](img/62_InstalationCfg50.png)|![Imagen de VirtualBox](img/63_InstalationCfg51.png)|
|-|-|-|

Ahora solo te queda repetir nuevamente el proceso…

1.	Elegir un volumen lógico
2.	Ir a “usar como”
3.	Elegir el file system Ext4 (Menos en swap, el cual hay que elegir el file system “swap” y no hay que seleccionar un punto de montaje)
4.	Seleccionar el punto de montaje dependiendo de la función que vaya a tener esa partición (menos para var-log que hay ponerlo manualmente en “/var/log”)

…hasta tener todas las particiones que pide el ejercicio, cuando hayas acabado de particionar dale a finalizar partición y escribir cambios en el disco. Después clica en Sí.

##### 1.1.3.4. Instalando sistema base de Debian
En este último paso se va ha instalar el sistema base y para ello hay que definir algunos parámetros:
- Al **escaneo** dale a **no**
- Para el servidor de descarga de los paquetes de Debian tienes que elegir un **país** (normalmente cuando más cercano sea el país a tú ubicación mejor) y un **mirror**
- La conexión **proxy** puedes dejarla **vacía**
- Y no hace falta participar en el estudio estadístico


|![Imagen de VirtualBox](img/64_InstalationCfg52.png)|![Imagen de VirtualBox](img/65_InstalationCfg53.png)|![Imagen de VirtualBox](img/66_InstalationCfg54.png)|
|-|-|-|
|![Imagen de VirtualBox](img/67_InstalationCfg55.png)|![Imagen de VirtualBox](img/68_InstalationCfg56.png)|

Para la selección de software, no hace falta poner **ninguno**, se instalará lo que se necesite más adelante. Así que **desmarca todas las casillas** seleccionándolas y presionando la barra espaciadora. Después dale a continuar.

![Imagen de VirtualBox](img/69_InstalationCfg57.png)

Dale a que **sí** que quieres instalar [GRUB](https://www.gnu.org/software/grub/)

![Imagen de VirtualBox](img/70_InstalationCfg58.png)

Y se instalará en “**/dev/sda**”

![Imagen de VirtualBox](img/71_InstalationCfg59.png)

¡FIN! Ya tienes instalado Debian en tú VM.

![Imagen de VirtualBox](img/72_InstalationCfg60.png)

### 1.2. ACCEDIENDO A Born2beroot
Ahora reinicia la VM. Al arrancar te pedirá la contraseña para descifrar la partición encriptada, y luego las credenciales del usuario que creaste al inicio del proceso de instalación.

Para verificar que la instalación es correcta, puedes probar algunos comandos:
- **cat /etc/os-release**. Para comprobar la información del sistema operativo
- **lsblk**. Para revisar tus particiones
- **apt –v**. Comprueba si el administrador de paquetes está instalado de forma predeterminada
- **date**. Para comprobar la zona horaria (Tiene que coincidir con el país que pusiste en la instalación). Aunque si es incorrecta, no es muy importante para Born2beroot.

![Imagen de VirtualBox](img/73_DebianInstalled.png)

## 2. CONFIGURANDO UN DEBIAN COMO SERVIDOR
### 2.1. IMPLEMENTACIÓN DE sudo
#### 2.1.1. INSTALACIÓN de sudo
*[¿Que es sudo?](annex/5_Root_Superuser_Sudo.es.md)*

Para instalar un programa en el servidor, tienes que iniciar sesión como root.
```bash
su root
```
> Nota que cuando te logues como root el símbolo de la consola de comandos pasa de '$' a '#' mientras te mantienes como usuario root.

Una vez como root, antes de instalar nada es recomendable actualizar la lista de los programas que se pueden descargar del repositorio. Además de, como todavía no está el servidor en producción, es recomendable actualizar los programas que están ya instalados en el sistema.
Todo esto se hace mediante la utilidad [apt](annex/4_Gestion_de_paquetes_Debian.md):
```bash
apt update # Actualiza la lista de paquetes
apt upgrade # Actualiza los paquetes instalados en el sistema
apt install sudo # Instalación de la utilidad sudo
```
Ahora toca dar los privilegios de ejecutar sudo a el usuario deseado. Para hacer esto hay diferentes formas, pero la más correcta y apropiada es añadir al usuario a un grupo que tenga los privilegios que tú quieras darle. A la hora de instalar el programa sudo, este ya tiene un grupo por defecto que tiene los privilegios de sudo llamado "sudo".

Aunque para cerciorarte del nombre puedes ejecutar el comando `sudo visudo` y fijarte si existe un grupo que se llama así:

![Fichero visudo](img/74_visudo.png)

Explicación:
```bash
%sudo ALL=(ALL:ALL) ALL
└─┬─┘ └┬┘  └──┬──┘  └┬┘
  │    │      │      └────╴> El comando en sí
  │    │      └────> Usuario que puede ejecutar el comando
  │    └────> El host al que se le aplica lo igualado
  └────> Usuario (en este caso grupo ya que tiene el prefijo '%') al que se aplica el comando
```
> Sabiendo esto, otra de las muchas formas de dar privilegios a un usuario puede ser añadirlo directamente y darle los privilegios que quieras, pero no suele ser una buena praxis.

Para añadir el usuario a un grupo hay diferentes formas, la que yo uso es:
```bash
sudo usermod -aG sudo daampuru
└┬─┘ └──┬──┘  ││ └┬─┘ └──┬───┘
 │      │     ││  │      └────> Es usuario en sí
 │      │     ││  └────> El grupo al que quieres unir al usuario
 │      │     │└────> A el grupo deseado
 │      │     └────> Con las opciones de "append" (agregar)
 │      └────> Para modificar la información de login de los usuarios
 └────> Ejecuta el comando sudo
```
> ATENCIÓN: Mucho ojo de no olvidarte la opción *a* ya que si solo pones "-G" el usuario seleccionado se borrará de todos los demás grupos en los que este y solo estará en este. Una forma más fácil es `adduser <username> sudo`

Una vez añadido el usuario al grupo, hay que refrescar la información de login de dicho usuario. Esto se hace deslogueandote y volviéndote a loguear:
```bash
exit # Con este comando te deslogueas como usuario root
exit # Con este segundo exit te deslogueas como tú usuario normal
```
Una vez logueado de nuevo con tu usuario normal prueba a ver si poder usar sudo, ejecutando un comando que necesite permisos root o también puedes ejecutar el comando `whoami` te dice con qué usuario estas logeado:
```bash
whoami # Si lo haces sin el sudo te devolverá tu usuario normal
sudo whoami # Y si lo hacer con sudo te tiene que devolver que lo ha ejecutado el usuario root
```

#### 2.1.2. CONFIGURACIÓN DE sudo
Por temas de seguridad, la práctica Born2beroot exige hacerle unas configuraciones extra a los ajustes de sudo que viene por defecto:

- El grupo sudo tiene un máximo de 3 intentos para introducir la contraseña correcta
- Cuando se utilice sudo y la contraseña sea incorrecta debe salir un mensaje personalizado
- Para cada comando ejecutado con sudo, tanto el input como el output deben quedar archivados en el directorio */var/log/sudo/*.
- El modo TTY[^3] debe estar activado por razones de seguridad.

Para añadir estos parámetros al programa sudo hay que modificar el fichero *sudoers.tmp*. Para abrir/modificar este fichero es recomendable utilizar el propio comando que te proporciona sudo, en vez de abrirlo como si fuera un fichero normal. Además de tener que abrirlo como usuario root.
```bash
sudo visudo
```
Ahora tienes que añadir las siguientes líneas al fichero:
```bash
Defaults passwd_tries=3 # Se expecifica un máximo de 3 intentos
Defaults badpass_message="Logging atempts with wrong password, try again." # Mesaje de error personalizado
Defaults logfile="/var/log/sudo/sudo.log" # Lugar donde se guardarán las interacciones con sudo
Defaults log_input # Guarda los input
Defaults log_output # Guarda los output
Defaults requiretty # Obliga a estar TTY abierto
```
> Si no existe el directorio donde quieres guardar los logs, tendrás que crearlo con `mkdir`.

### 2.2. IMPLEMENTACIÓN DE AppArmor: Limitación de sudo
Desde Debian 10 [AppArmor](annex/6_Que_es_AppArmor.md) viene preinstalado en Debian, por lo que yo usaré este mismo (además de ser más fácil de utilizar). Para ver AppArmor está instalado y corriendo correctamente hay que ejecutar lo siguiente:
```bash
sudo aa-status
```
Y tiene que aparecerta algo parecido a esto:
```bash
apparmor module is loaded.
3 profiles are loaded.
[...]
```
En este caso si todo está bien deja la configuración por defecto.

### 2.3. IMPLEMENTACIÓN DE UFW
#### 2.3.1 INSTALACIÓN Y ACTIVACIÓN
Para instalar [UFW](annex/7_Que_es_UFW.md) haz:
```bash
sudo apt install ufw
sudo ufw enable
```
Si todo ha ido bien tiene que aparecerte el mensaje *Firewall is active and enabled on system startup*. Además, para ver si efectivamente UFW se está corriendo en segundo plano puedes ejecutar el siguiente comando:
```bash
sudo ufw status verbose # NOTA: La opción "verbose" es opcional, solo añade más información a la respuesta
```

#### 2.3.2. GESTIÓN DE LAS REGLAS
Aunque de momento no es necesario aplicar ninguna regla en concreto, voy a enseñarte los primeros pasos para que sepas como crear, eliminar y monitorizar las reglas.

- Creación de reglas
```bash
sudo ufw allow 4242 # Permite la entrada de tráfico por el puerto 4242
sudo ufw deny 8080 # Deniega la entrada de tráfico por el puerto 8080
```
> Estas reglas no se aplican únicamente a los puertos de tú servidor, también se pueden aplicar a IPs por ejemplo.

- Monitorización de reglas activas
```bash
sudo ufw status numbered
```

- Eliminación de reglas
```bash
sudo ufw delete allow 4242
sudo ufw delete deny 8080

# Otra forma sería usando el id que obtienes con el comando de status numbered
sudo ufw delete 2
```
> NOTA: Ten cuidado porque si intentas borrar más de una regla a la vez usando el id tienes que ordenarlos de mayor a menor, ya que si empiezas borrando los de menor valor los de mayor valor irán tomando esos valores.


### 2.4. IMPLEMENTACIÓN DE UN SERVIDOR SSH EN Born2beroot
#### 2.4.1. INSTALAR
Otro requisito de la práctica es la posibilidad de conectarse a tú servidor de forma remota y hacerlo por el puerto 4242. Para ello te dicen que utilices el protocolo [SSH](annex/8_Que_es_SSH.md), para poder usarlo de forma sencilla existen diferentes programas, pero el más usado en Linux es **OpenSSH**, el cual se puede implementar de dos formas como cliente (sirve para conectarse a otro ordenador) y/o servidor (sirve para que otros ordenadores se conecten). A ti te interesa implementar un servidor con OpenSSH.
```bash
sudo apt install openssh-server
```
Para ver el estado del servidor ssh:
```bash
sudo systemctl status ssh
```

#### 2.4.2. CONFIGURAR EL SERVIDOR SSH
 Como puedes ver, el servidor esta preconfigurado para que acepte las conexión procedentes del puerto 22, mira la línea `Server listening on :: port 22`. Para que el servidor solo acepte conexiones que vengan del puerto 4242 tienes que modificar la configuración por defecto del ssh. El archivo de configuración está en */etc/ssh/sshd_config*.
```bash
sudo nano /etc/ssh/sshd_config
```
Una vez abierto busca la línea `# Port 22`, descomentala y cambia el 22 por el 4242.

|![Fichero de configuración del ssh por defecto](img/75_sshd_config_default.png)|![Fichero de configuración del ssh modificado](img/76_sshd_config.png)|
|-|-|

Una vez guardado el servidor ssh devería cambiar el puerto de escucha automáticamente, si no es así prueba a reiniciar el servicio ssh.
```bash
sudo systemctl restart ssh
```
 Por último, hay que autorizar al firewall UFW que autorice las conexiones de entrada por el puerto 4242. Además de añadir esta regla, es posible que tengas que eliminar una nueva regla que permite las conexiones por el puerto 22 que se ha creado automáticamente al instalar OpenSSH.
```bash
sudo ufw allow 4242
sudo delete allow ssh # To delete port 22 rule
```

#### 2.4.3. REDIRECCIONAMIENTO DE PUERTOS CON VIRTUALBOX
Para poder conectarte a la VM desde otro ordenador a través de SSH tienes que redireccionar el puerto del host (el PC donde tienes instalada la VM) al propio puerto de la máquina virtual. En el caso de que trabajes con VirtualBox ve a los ajustes de Born2beroot, una vez allí ve ha *network -> Adapter 1 -> Advanced -> Port Forwarding*

|![Redireccionando el puerto parte 1](img/77_PortForwarding1.png)|![Redireccionando el puerto parte 2](img/78_PortForwarding2.png)|
|-|-|

Una vez hecho esto ya deverias de poder conectarte vía ssh, pero si quieres asegurar vuelve a reiniciar el servicio.
```bash
sudo systemctl restart ssh
```

#### 2.4.4. CONEXIÓN A UN SERVIDOR SSH
Para conectarte desde otro ordenador te hace falta tener un cliente ssh instalado. Suponiendo que ya lo tengas, lo único que tienes que hacer es abrir una terminal y
```bash
ssh daampuru@localhost -p 4242
└┬┘ └──┬───┘ └───┬───┘  │ └┬─┘
 │     │         │      │  └────> Puerto por el que quieres conectarte
 │     │         │      └────> Opción de poder elegir otro puerto que no sea el de por defecto
 │     │         └────> IP a la que quieres conectarte
 │     └────> Usuario del sistema al que quieres conectarte
 └────> Comando para usar el cliente ssh
```
> NOTA: Como la VM comparte la dirección IP del host, puedes usar la dirección IP local del host. Puedes usar *Localhost* el cual es un atajo interno del PC usado para referirse a su propia dirección IP, la cual es 127.0.0.1 (puedes usar cualquiera de las dos).

En la primera conexión a traves de un cliente ssh te pide un certificado para entablecer una conexión segura.

![Primera conexión al servidor](img/79_SshConection1.png)

Una vez dentro, es como estar en el propio servidor Born2beroot pero de forma remota.

![Conexión al servidor](img/80_SshConection2.png)

Para desconectarte de la conexión SSH solo tienes que ejecutar el comando `exit`


### 2.5. MONITORIZACIÓN DEL SERVIDOR
La siguiente etapa de la guía es hacer el script *monitoring.sh* el cual debe ejecutarse cada 10 minutos desde el arranque del equipo y mostrar la información deseada en todas las terminales activas. Información a mostrar:

| Información                                                                           | Comando                                                                             |
|---------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------|
| La arquitectura de tu sistema operativo y su versión de kernel.                       | uname -srvmo                                                                        |
| El número de núcleos físicos.                                                         | grep 'physical id' /proc/cpuinfo \| uniq \| wc -l                                   |
| El número de núcleos virtuales.                                                       | grep processor /proc/cpuinfo \| uniq \| wc -l                                       |
| La memoria RAM disponible actualmente en tu servidor y su porcentaje de uso.          | **Used:** free -h \| grep Mem \| awk '{print $3}'<br> **Total:** free -h \| grep Mem \| awk '{print $2}'<br> **Percentage:** free -k \| grep Mem \| awk '{printf("%.2f%%"), $3 / $2 * 100}'<br> |
| La memoria disponible actualmente en tu servidor y su utilización como un porcentaje. | **Used:** df -h --total \| grep total \| awk '{print $3}'<br> **Total:** df -h --total \| grep total \| awk '{print $2}'<br> **Percentage:** df -k --total \| grep total \| awk '{print $5}'<br> |
| El porcentaje actual de uso de tus núcleos (la CPU).                                   | top -bn1 \| grep '^%Cpu' \| cut -c 9- \| xargs \| awk '{printf("%.1f%%"), $2 + $4}' |
| La fecha y hora del último reinicio.                                                  | who -b \| awk '{print($3 " " $4)}'                                                  |
| Si LVM está activo o no.                                                              | $(if [ $(lsblk | grep lvm | wc -l) -eq 0 ]; then echo no; else echo yes; fi)|
| El número de conexiones activas.                                                      | grep TCP /proc/net/sockstat \| awk '{print $3}'                                     |
| El número de usuarios del servidor.                                                   | who \| wc -l                                                                        |
| La dirección IPv4 de tu servidor y su MAC (Media Access Control)                      | **IP:** hostname -I \| awk '{print $1}'<br> **MAC:** ip link show \| grep link/ether \| awk '{print $2} |
| El número de comandos ejecutados con sudo                                             | grep COMMAND /var/log/sudo/sudo.log \| wc -l / 2                                       |

Algunos comandos solo los puede ejecutar el usuario root por lo que tienes 2 opciones:
1. Te logueas como root y crear/modificas el fichero
2. Lo haces con un usuario normal y despues le cambias el dueño (`chown`) para que sea del root

Una vez creado el fichero tienes que darle derechos de ejecución `chmod +x monitoring.sh`

#### 2.5.1. ENVIAR UN MENSAJE A CADA TERMINAL
Para enviar un mensaje a cada terminal (broadcast) existe el comando `wall`, el cual te permite emitir un mensaje a todos los usuarios a la vez en todos los terminales. Además, puede recibir como texto a mostrar el contenido de un archivo.

De forma predeterminada, el anuncio tiene como prefijo un banner, pero ese banner es opcional en este proyecto.

```bash
wall "message"    # Con banner
wall -n "message" # Sin banner
```

#### 2.5.2. ENVIAR EL MENSAJE CADA 10 MINUTOS
Para este cometido existe el servicio `crontab` (**c**h**ron**o **tab**le) que te permite la ejecución de scripts o software de forma automática cuando ocurre un evento en concreto que tú le hayas asignado, como puede ser una fecha y hora determinada o en un intervalo de tiempo específico.

Este es un programa que viene preinstalado con el propio Debian y para que se ejecute en segundo plano siempre que arranques el equipo usa el siguiente comando:
```bash
systemctl enable cron
```
Para programas los trabajos *cron* usa archivos llamados *crontab*. Logueado como root tienes que crear uno de estos archivos.
```bash
crontab -e * * * * * <command to execute>
         │ │ │ │ │ └────> Selecciona el día de la semana (0 - 6, 0 = Domingo)
         │ │ │ │ └────> Selecciona el mes del año (1 - 12)
         │ │ │ └────> Selecciona el día de la semana (1 - 31)
         │ │ └────> Seleciona la hora (0 - 23)
         │ └────> Selecciona el minuto (0 - 59)
         └────> Edita los crontab del usuario
```
> NOTA: '*' significa cualquier valor

Para ejecutar el archivo de monitoreo cada 10 minutos hay que usar la siguiente combinación.
```bash
crontab -e */10 * * * * ./root/monitoring.sh
```
> Suponiendo que */root/monitoring.sh* sea donde tienes el archivo.

Y para que la salida del comando se muestre en todas las terminales hay que añadirle el comando `wall`, otra manera de hacerlo es introducir el comando `wall` directamente en el script.
```bash
crontab -e */10 * * * * ./root/monitoring.sh | wall
```
Aun así, este script se ejecutará cada 10 minutos de cada hora (00:10, 00:20, 00:30 ...) no cada 10 minutos desde que se **arranca el sistema**. Para conseguir esto tendrás un nuevo script que combine el comando `sleep` y que sepa a qué hora se ha iniciado en sistema.

#### 2.5.3. CALCULAR CUANDO SE HA INICIADO EL SISTEMA
Crea un nuevo script llamado *sleep.sh*. Este script, calculará la cantidad de segundos entre el tiempo de arranque preciso y el décimo minuto. Para hacer los cálculos puedes usar la calculadora basada en terminal `bc`, por lo que primero tienes que instalarla en el sistema
```bash
sudo apt install bc
```
Por otro lado, el código fuente de sleep.sh es:
```bash
#!bin/bash

# Get boot time minutes and seconds
BOOT_MIN=$(uptime -s | cut -d ":" -f 2)
BOOT_SEC=$(uptime -s | cut -d ":" -f 3)

# Calculate number of seconds between the nearest 10th minute of the hour and boot time:
# Ex: if boot time was 11:43:36
# 43 % 10 = 3 minutes since 40th minute of the hour
# 3 * 60 = 180 seconds since 40th minute of the hour
# 180 + 36 = 216 seconds between nearest 10th minute of the hour and boot
DELAY=$(bc <<< $BOOT_MIN%10*60+$BOOT_SEC)

# Wait that number of seconds
sleep $DELAY
```
Por último, añade este archivo al comando de crontab, de este modo cron llamará a `sleep.sh` y este pasado *X* tiempo llamará a `monitoring.sh`:
```bash
*/10 * * * * bash /root/sleep.sh && bash /root/monitoring.sh
```

### 2.6. IMPLEMENTACIÓN DE UN SISTEMA FUERTE DE CONTRASEÑAS
> NOTA: Si tienes pensado hacer la parte bonus te recomiendo que pospongas este apartado hasta tenerla hecha, así no tendrás que andar cambiando la contraseñas ni andar preocupándote de sí van a expirar o no.

Las características que te piden para configurar la política de contraseñas son:
-	La contraseña expira en 30 días
-	El número mínimo de días permitido antes de modificar una contraseña son 2
- El usuario debe recibir un mensaje de aviso 7 días antes de que su contraseña expire.
-	Mínimo 10 caracteres de longitud
- Mínimo una mayúscula y un número
- No puede tener más de 3 veces consecutivas el mismo carácter
-	La contraseña no puede contener el nombre del usuario.
-	La contraseña debe tener al menos 7 caracteres que no sean parte de la antigua contraseña (la contraseña de root no tiene que seguir esta norma)

Las reglas se arriba hay que separarlos en dos grupos, los 3 primeros que tienen que ver con los días y el resto que definen como tiene que ser las contraseñas.

Para los tres primeros tiene que modificar el archivo:
```bash
sudo nano /etc/login.defs
```
Y en el apartado *Password aging controls* (línea 160) cambia los siguientes valores:
```bash
PASS_MAX_DAYS 30
PASS_MIN_DAYS 2
PASS_WARN_AGE 7
```
Pero cuidado, estos cambios no se aplican de forma automática a los usuarios preexistentes (el *root* y *daampuru* en mi caso). Para modificar estas reglas necesitas usa el commando `chage`:
```bash
sudo chage -M 30 root
sudo chage -M 30 daampuru
sudo chage -m 2 root
sudo chage -m 2 daampuru
sudo chage -W 7 root
sudo chage -W 7 daampuru
# Para comprobar, el flag "-l" sirve para ver las reglas que tiene puestas
sudo chage -l root
sudo chage -l daampuru
```
Para aplicar las demás características hace falta que te descargues el siguiente paquete:
```bash
sudo apt install libpam-pwquality
```
Y para imponer las características que se quieren en las contraseñas hay que configurar el archivo */etc/security/pwquality.conf*
```bash
# Number of characters in the new password that must not be present in the
# old password.
difok = 7
# The minimum acceptable size for the new password (plus one if
# credits are not disabled which is the default)
minlen = 10
# The maximum credit for having digits in the new password. If less than 0
# it is the minimun number of digits in the new password.
dcredit = -1
# The maximum credit for having uppercase characters in the new password.
# If less than 0 it is the minimun number of uppercase characters in the new
# password.
ucredit = -1

# [...]

# The maximum number of allowed consecutive same characters in the new password.
# The check is disabled if the value is 0.
maxrepeat = 3

# [...]

# Whether to check it it contains the user name in some form.
# The check is disabled if the value is 0.
usercheck = 1

# [...]

# Prompt user at most N times before returning with error. The default is 1.
retry = 3
# Enforces pwquality checks on the root user password.
# Enabled if the option is present.
enforce_for_root

# [...]
```
Por último, cambia las contraseñas del root y tú usuario para que cumplan con la nueva política de contraseñas:
```bash
sudo passwd <user/root>
```


### 2.7. GESTIÓN DEL HOSTNAME, USUARIOS Y GRUPOS
La última cosa a tener en cuenta es que a la hora de la defensa se te pedirá que:
- Cambies el hostname del sistema
- Crees un nuevo usuario, le cambies el nombre ...
- Y lo añadas a un grupo

#### 2.7.1. MODIFICAR EL HOSTNAME
Para modificar el hostname tienes 2 opciones:
1. Usar el comando `sudo hostnamectl set-hostname <new_hotsname>`
2. Editarlo directamente el archivo */etc/hostname*
3. NOTA: Si te sale el error `sudo: unable to resolve host <nuevo nombre del host>: Name or service not known` también deberás añadirlo al archivo */etc/hosts*

Para comprobar que efectivamente el nombre ha cambiado puedes ejecutar:
```bash
hostnamectl status
```
> Si ves que todavía no ha cambiado el nombre, prueba a reiniciar el equipo.

#### 2.7.2. GESTIÓN DE USUARIOS
Comandos útiles para hacer la gestión de usuarios:

| Comando                                                                            | Descripción                                                                |
|------------------------------------------------------------------------------------|----------------------------------------------------------------------------|
| adduser                                                                            | Creates a new complete user                                                |
| useradd                                                                            | Creates a new user                                                         |
| usermod                                                                            | Changes the user's paramenters: -l (username), -c (full name), -g (groups) |
| userdel -r                                                                         | Deletes a user and all associated files                                    |
| id -u                                                                              | Displays user ID                                                           |
| users                                                                              | Show a list of all currently logged in users                               |
| cat /etc/passwd \| cut -d ":" -f 1<br>*or*<br>cat /etc/passwd \| awk -F '{print $1}' | Displays a list of all users on the machine                              |

#### 2.7.3. GESTIÓN DE GRUPOS
Comandos útiles para hacer la gestión de grupos:

| Comando      | Descripción                             |
|--------------|-----------------------------------------|
| groupadd     | Creates a new group                     |
| gpasswd -a   | Adds a user to a group                  |
| gpasswd -d   | Removes a user from a group             |
| groupdel     | Deletes a group                         |
| id -g        | Shows a user's main group ID            |
| getent group | Displays a list of all groups           |


## 3. PARTE BONUS
En la parte bonus aparte de crear las particiones extra que se pedían a la hora de la instalación del SO, hay que crear una página web ([aquí](annex/9_Breve_Introduccion_a_las_paginasWeb.md) tienes una pequeña introducción) con **WordPress**. Y como backend te dicen que debes implementar lo siguiente:
- El servidor HTTP a implementar tiene que ser **Lighttpd**
- Para programar el servidor para la parte del backend hay que usar **PHP**
- En cuanto a la implementación de la base de datos se va ha usar **MariaDB**

### 3.1. PHP
En el momento en que estoy escribiendo esta guía, A la hora de instalar PHP si ejecutas `sudo apt list php` puedes ver como en Debian 11 la versión estable de PHP es la 7.4, aunque ya este la versión 8 disponible. En un principio con la versión 7.4 no tendrías que tener ningún problema. Además de PHP 7.4 también hacen falta los paquetes* php-common*, *php-cgi*, *php-cli* y *php-mysql* ya que son necesarios para WordPress.

```bash
sudo apt update
sudo apt install php php-common php-cgi php-cli php-mysql
php -v # Para comprobar que versión se ha instalado
```

### 3.2. LIGHTTPD
Antes de empezar con la instalación de lighttp, si has instalado primero PHP es posible se te haya instalado apache2 como dependencia de php (para comprobar si está o no en el sistema puedes ejecutar `sudo apt list apache2` y si al final del paquete pone *[installed]* es que está instalado), por lo que para evitar posibles conflictos si está instalado ejecuta `sudo apt purge apache2` para eliminarlo del sistema.

Para instalar lighttpd simplemente tienes que ejecutar:

```bash
sudo apt install lighttpd
lighttpd -v # Para comprobar que efectivamente se ha instalado
```

Una vez instalado, toca activarlo y hacer que el servicio empiece a funcionan en segundo plano al arrancar el ordenador.

```bash
sudo systemctl start lighttpd
sudo systemctl enable lighttpd
sudo systemctl status lighttpd
```

Una vez comprobado con el comando `status` que el servicio esta ejecutándose, tienes que decirle al firewall que permita pasar tráfico con el protocolo *http* (o lo que es lo mismo por el puerto 80 y protocolo TCP/IP)

```bash
sudo ufw allow http
sudo ufw status
```

Y como ya has hecho con el puerto 4242 a la hora de permitir conexiones con SSH, tienes que volver a enrutar los puertos de la VM con los de su host. *Settings >> Network >> Adapter 1 >> Advanced >> Port Forwarding* y para que el host pueda seguir usando el puerto 80 vas a usar su puerto 8080, así no tendrás interferencias con el tráfico de datos:

![Enrutado de puertos entre host y VM para lighttpd](img/81_PortForward_Lighttpd.png)

Para testar que efectivamente el servidor web de Born2beroot está funcionando correctamente intenta conectarte a él. Vete al navegador del host de la VM y como la VM esta alojada en tú propio ordenador como dirección escribe la *localhost* (o 127.0.0.1) y como puerto el 8080 (que en realidad es el 80 de la VM).

![Pagína de inicio del servidor web](img/82_Lighttpd_server_working.png)

¡PERFECTOOO! Ya tienes tu servidor web corriendo correctamente en la VM.

#### 3.2.1 ACTIVACIÓN de FastCGI (**Fast** **C**ommon **G**atewway **I**nterface)
Pero todavía queda hacer que se vean las páginas dinámicas que se crean con PHP. A la hora de instalar PHP se ha creado un directorio donde dejar las páginas web creadas con PHP */var/www/html/*, para crear una página simple que muestre la información de php ejecuta:

```bash
sudo nano /var/www/html/info.php
```

Dentro del script escribe:

```php
<?php
phpinfo();
?>
```

Si buscas la dirección *http://localhost/info-php* en tú navegador te responderá con el error *403 Forbidden*.

Para arreglar esto tienes que entender el paradigma de las páginas web dinámicas y estáticas. En las **webs estáticas**, el servidor web enviaba inmediatamente páginas HTML pre-escritas para cada solicitud HTTP que recibía. Por otro lado, en las **webs dinámicas**, el servidor web no responde de inmediato, sino que transfiere los datos de la solicitud HTTP a una aplicación externa (en este caso PHP) que los interpreta y le devuelve el código HTML generado al servidor web, y el este responde a la solicitud.

En la comunicación entre la aplicación externa y el servidor web es donde entra FastCGI, el cual es un protocolo binario que permite dicha comunicación. Necesitas configurar este protocolo entre lighttpd y PHP para poder acceder a la página *info.php* desde un navegador web.

```bash
sudo lighty-enable-mod fastcgi # Habilita el modo CGI
sudo lighty-enable-mod fastcgi-php # Habilita la comunicación CGI con PHP
sudo service lighttpd force-reload # Reinicia el servicio para efectuar los cambios
```

Ahora si intentas leer la página *info.php* en tú ordenador veras algo parecido a esto:

![Página PHP vía Lighttpd con FastCGI ](img/83_Lighttpd_and_PHP_working.png)

### 3.3. MariaDB
Para que el Wordpress almacene los datos de la web hay que usar MariaDB. Para instalarlo haz:

```bash
sudo apt install mariadb-server
```

Ahora iniciarlo y haz que se ejecute siempre en segundo plano al arrancar el equipo.

```bash
sudo systemctl start mariadb
sudo systemctl enable mariadb
systemctl status mariadb
```

Para hacer una [instalación más segura](https://dev.mysql.com/doc/refman/5.7/en/mysql-secure-installation.html) ejecuta:

```bash
sudo mysql_secure_installation
```

Después toca rellenar los campos que te piden al ejecutar el comando anterior

```bash
Enter current password for root (enter for none): <Enter>
Switch to unix_socket authentication [Y/n]: Y
Set root password? [Y/n]: Y
New password: SuperLuna!26
Re-enter new password: SuperLuna!26
Remove anonymous users? [Y/n]: Y
Disallow root login remotely? [Y/n]: Y
Remove test database and access to it? [Y/n]:  Y
Reload privilege tables now? [Y/n]:  Y
```

Por último, reinicia MariaDB para que se implemente la nueva configuración.

```bash
sudo systemctl restart mariadb
```

Una vez instalado, vas a loguearte a MariaDB como root (OJO como root de la base de datos no el usuario root de la VM).

```bash
mysql -u root -p
```

> Antes de empezar a usar la base de datos, tienes que saber que hay que usar su propio lenguaje (*SQL*) para poder gestionar las bases de datos y sus tablas. Yo te recomiendo que hagas una pausa y aprendas como hacer CRUD (**C**reate, **R**ead, **U**pdate y **D**elete) en SQL (aquí te dejo un [cheatsheet](annex/SQL_Chearsheet.png) y [aquí](https://sqliteonline.com/) un compilador online para que pruebes). Esto es algo básico en todas las bases de datos que quieras usar.

Para crear la base de datos de WordPress tienes que:

```SQL
MariaDB [(none)]> CREATE DATABASE wordpress; --Crea la base de datos llamada "wordpress_db"
MariaDB [(none)]> CREATE USER 'admin'@'localhost' IDENTIFIED BY 'check42_MVP'; --Crea un nuevo usuario con contraseña
MariaDB [(none)]> GRANT ALL ON wordpress.* TO 'admin'@'localhost' IDENTIFIED BY 'check42_MVP' WITH GRANT OPTION; --Da privilegios de super usuario a "admin" en el contexto de esa base de datos
MariaDB [(none)]> FLUSH PRIVILEGES;
MariaDB [(none)]> EXIT;
```

Para comprobar que has creado la base de datos puedes ejecutar estando logueado como root en MariaDB:

```bash
MariaDB [(none)]> show databases;
```

La salida debe ser parecida a:

```bash
+--------------------+
| Database           |
+--------------------+
| information_schema |
| mysql              |
| performance_schema |
| wordpress          |
+--------------------+
```

### 3.4. WORDPRESS
Por último, toca instalar y configurar Wordpress

```bash
sudo apt install wordpress
```

Una vez instalado te vas ha basar en el script de ejemplo que tiene el propio wordpress en */usr/share/wordpress/wp-config-sample.php*[^4] y */usr/share/wordpress/wp-admin*, copialo al directorio del servidor web, abrelo con un editor de texto (`nano` por ejemplo) y modifica los siguientes apartados:

```bash
sudo cp -r /usr/share/wordpress/ /var/www/html/
sudo mv /usr/share/wordpress/wp-config-sample.php /var/www/html/wp-config.php
sudo nano /var/www/html/wp-config.php
```

```php
<?php
/* [...] */
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** Database username */
define( 'DB_USER', 'admin' );

/** Database password */
define( 'DB_PASSWORD', 'SuperLuna!26' );

/** Database host */
define( 'DB_HOST', 'localhost' );
/* [...] */
?>
```

Por último, tienes que darle permisos al usuario `www-data` ([aquí](https://askubuntu.com/questions/873839/what-is-the-www-data-user) te dejo una breve explicación de por qué se utiliza), que se ha creado en la instalación del servidor web, para que pueda leer los archivos de la página web.

```bash
sudo chown -R www-data:www-data /var/www/html/
sudo chmod -R 755 /var/www/html/
sudo systemctl restart lighttpd
```

Como puedes ver poniendo *http://localhost:8080/wordpress/wp-admin/install.php* en tú navegador te saldrá un pequeño set-up del wordpress, solo te queda rellenarlo como quieras.

![Instalador de Wordpress](img/84_Wordpress_Setup.png)

### 3.5. SERVICIO EXTRA: Fail2Ban
Como servicio extra, uno de los más útiles a mi parecer para cualquier servidor (aún más si tienes un servidor SSH activado como es tú caso) es `Fail2ban`[^5], se trata de un programa para la prevención de intrusos en un sistema, que actúa penalizando o bloqueando las conexiones remotas que intentan accesos por fuerza bruta. Si encuentra múltiples intentos de inicio de sesión fallidos o ataques automáticos desde una dirección IP, puede bloquearla con el firewall, ya sea de manera temporal o permanente.

Para la instalación:

```bash
sudo apt install fail2ban
sudo systemctl start fail2ban
sudo systemctl enable fail2ban
sudo systemctl status fail2ban
```

Y para la configuración hay que modificar el fichero */etc/fail2ban/jail.local*:

```bash
sudo cp /etc/fail2ban/jail.conf /etc/fail2ban/jail.local
sudo nano /etc/fail2ban/jail.local
```

Vete hasta el apartado sobre SSH (sobre la línea 280) y añade lo siguiente:

```bash
# [...]

#
# SSH servers
#

[sshd]

# To use more aggressive sshd modes set filter parameter "mode" in jail.local:
# normal (default), ddos, extra or aggressive (combines all).
# See "tests/files/logs/sshd" or "filter.d/sshd.conf" for usage example and details.
# mode   = normal
enabled  = true
maxretry = 3
findtime = 10m
bantime  = 1d
port     = 4242
logpath  = %(sshd_log)s
backend  = %(sshd_backend)s

# [...]
```

Una vez tengas todo funcionando, para ver los logs de los intentos fallidos solo tienes que hace lo siguiente:

```bash
sudo fail2ban-client status
sudo fail2ban-client status sshd
sudo tail -f /var/log/fail2ban.log
```

Para probar que Fail2ban realmente está prohibiendo las direcciones IP, puedes cambiar el tiempo de prohibición de SSH a un valor más bajo, como 15 minutos, en el archivo de configuración /etc/fail2ban/jail.local. Luego intenta conectarse varias veces desde la máquina host a través de SSH con la contraseña incorrecta. Después de algunos intentos, debería rechazar la conexión y el comando fail2ban-client status sshd debería mostrar la dirección IP prohibida.

Y ya está. Ya tienes Born2beroot finalizada.


## EXTRA: POSIBLES ERRORES
#### \*ERROR\* Failed to send host log message
En el arranque de la máquina, puedes notar el siguiente error: *[DRM :vmw_host_log [VMWGFX]] \*ERROR\* Failed to send host log message*. Es un pequeño problema con el controlador de gráficos que no afecta el funcionamiento de la máquina. Sin embargo, no es muy agradable de ver. Puedes solucionar fácilmente este error cambiando el controlador de gráficos:

1. Apague la máquina virtual,
2. Vaya a VirtualBox >> Máquina >> Configuración,
3. Vaya a Pantalla >> Pantalla >> Controlador de gráficos,
4. Elija VBoxVGA.




[^1]: Son las últimas versiones estables de los respectivos programas en la fecha que se está haciendo este ejercicio

[^2]: Si le das un valor muy bajo a “var” a la hora de instalar el sistema base puede darte problemas.

[^3]: Modo TTY (Texto) o Gráfico (Gestor de ventanas). Desde el punto de vista de un Servidor el arranque en modo terminal supone un ahorro de recursos, ya que casi todas las consultas que realizamos sobre el mismo, se suelen gestionar mediante SSH.

[^4]: [Aquí](https://blog.ostermiller.org/install-wordpress-apt-ubuntu-host-multiple-blog-domains/) tienes todo lo que instala y donde lo instala wordpress hacerlo mediante `apt`

[^5]: [Aquí](https://www.youtube.com/watch?v=PAK7I1cKwzA) te dejo un video explicativo muy bueno del gran Pelado Nerd

## Repositorios útiles de otros estudiantes
- El repositorio de referencia que he utilizado para hacer esta guia es: https://github.com/mcombeau.
  - Junto con su página web: https://www.codequoi.com/en/42-get_next_line-project/

- https://github.com/mpeq/born2beroot

---
Hecho por daampuru | LinkedIn: [David Ampurua](www.linkedin.com/in/david-ampurua)
