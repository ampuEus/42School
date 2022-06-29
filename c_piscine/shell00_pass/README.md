### Ex00
```bash
# 1. Crea un archivo llamado "z"
	touch z

# 2. Abre el archivo no un editor de texto de consola (nano, vi, vim...) y edita el archivo
	nano z

# 3. Muestra de una forma simple lo que hay dentro del archivo
	cat z
```

### Ex01
```bash

  tar -cf Nombre_del_archivo.tar Archivo1 Archivo2 ...
  └┬┘  ││ └─────────┬──────────┘ └───────────┬────────┘
   │   ││           │                        └─────> Archivos que se quieren comprimir
   │   ││           └─────> Nombre del archivo comprimido de salida (.zip, .7z, ...)
   │   │└─────> Comprimir el archivo (file)
   │   └────╴> Crear archivo comprimido
   └─────> Nombre de la utilidad para comprimir archivos
```

### Ex02

| Tipos de objetos             | Tipos de permisos |
|------------------------------|-------------------|
| '-' -> archivo               | 'r' -> read       |
| 'd' -> directorio            | 'w' -> write      |
| 'l' -> link (acceso directo) | 'x' -> execution  |

```bash
# Salida del comando ls -l

# Para modificar los permisos de los archivos
chmod XYZ archivo1 archivo2 ...
└─┬─┘ │││ └─────────┬─────────┘
  │   │││           └─────╴> Los archivos/directorios a los que se les va ha cambiar los permisos
  │   ││└─────╴>
  │   │└─────╴>
  │   └─────╴>
  └─────╴> Utilidad para cambiar los permisos
# Otra forma más intuitiva de hacerlo sería:
chmos +(rwx) archivo1 archivo2 ...

# Para generar archivos con una fecha de creación en concreto
touch -t YYYYMMDDhhmm.ss Nombre_del_archivo
       │ └─┬─┼─┼─┼─┼┘ ├┘
       │   │ │ │ │ │  └────╴> Segundos
       │   │ │ │ │ └────╴> Minutos
       │   │ │ │ └────╴> Horas
       │   │ │ └────╴> Día
       │   │ └────╴> Mes
       │   └────╴> Año
       └────╴> Opción de especificar la fecha de modificación

# Para generar un link del archivo1 llamado archivo2
ln -s archivo1 archivo2

# NOTA: Para cambiar la hora de un link
touch -ht YYYYMMDDhhmm.ss

# NOTA: Para hacer los archivos del peso adecuado de forma sencilla
head -c 40 /dev/zero > archivo1
└────┬───┘ └───┬───┘ └────┬───┘
     │         │          └────╴> Nombre del archivo donde se enviarán los datos de salida
     │         └────╴> Archivo lleno de caracteres '0'
     └────╴> Lee los primeros 40 caracteres de un archivo
```

### Ex03
Ejecutar el comando `ssh-keygen` y seguir las instrucciones que te va dando

NOTA: Los archivos generados están en *~/.ssh/*. *id_rsa* es la clave privada (NUNCA JAMÁS la conpartas con nadie) y *id_rsa* la clave publica (la que debes dar al resto)

### Ex04
Una vez ubicado en el directorio deseado ejecuta:
```bash
ls -tpn
├┘  ││└────╴> Separa las cosas por comas
│   │└────> Escribe "/" después de los directorios
│   └───╴> Ordena por fecha de modificación
└────> Utilidad para listar el contenido de un directorio
```

### Ex05
```bash
git log -5 --pretty=%H
└┬┘ └┬┘ ├┘           └────╴> Hash de cada commit
 │   │  └────╴> Los últimos 5 commits
 │   └────╴> Muestra el historial de versiones
 └────╴> Programa de control de versiones
```
### Ex06

### Ex07

### Ex08

### Ex09
```bash
41 string 42 42 File
├┘ └───┬───┘ └──┬──┘
│      │        └────╴> Si lo hay, muestra este mensaje
│      └────╴> Un string que ponga "42"
└────╴> Busca en la posición 41, esto es, mira en el byte 42 en adelante
```
