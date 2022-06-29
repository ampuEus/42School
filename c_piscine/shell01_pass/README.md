### Ex01
```bash
id -Gn $FT_USER | tr ' ' ',' | tr -d '\n'
├┘  ││ └──┬───┘   ├┘               │ └┬─┘
│   ││    │     │ │                │  └────╴> Simbolo que representa un salto de línea
│   ││    │     │ │                └─────╴> Opción para borrar el caracter
│   ││    │     │ └─────╴> Utilidad para modificar el texto de entrada, en este caso reempla el primero por el segundo
│   ││    │     └────╴> Sirve para decir que la salida de un comando sea la entrada del siguiente
│   ││    └────╴> Variable de entorno con el valor que se le haya dado
│   │└────╴> Cambia el Id por el nombre
│   └────╴> Muestra los Id-s de lso grupos
└────╴> Utilidad para ver los usiarios/grupos del sistema
```

### Ex02
```bash
find . -name "*.sh" -exec basename {}\;
└┬─┘ │ └────┬─────┘ └─┬─┘            ├┘
 │   │      │         │              └────╴> Se tiene que poner ';' para terminar el comando, y para que bash entienda el caracter tiene que ir precedido de '\'
 │   │      │         └────╴> Ejecuta el siguiente comando
 │   │      └────╴> Busca todos los archivos con terminación ".sh"
 │   └────╴> Busca en el directorio actual y en todos sus subdirectorios
 └────╴> Utilidad para encontrar objetos
```

### Ex03
```bash
ls -a * | wc -w
    │ │   └─┬─┘
    │ │     └────╴> Cuenta el número de palabras
    │ └────╴> Quita '.' y ".."
    └────╴> Muestra también los archivos ocultos
```

### Ex04
```bash
ifconfig | grep ether | awk '{print $2}'
└──┬───┘   └───┬────┘   └───────┬──────┘
   │           │                └────╴> De todas las columnas muestra solo la segunda
   │           └────╴> Me quedo solo con el apartado "ether", el cual representa la MAC
   └────╴> Lista todas las interfaces de redes (esta utilidad esta "deprecated" mejor usar "ip a")
```

### Ex05
Este ejercicio es para aprender a usar el caracter `'\'` para mostrar caracteres ACSII especiales.

NOTA: Para eliminar el caracter oculto de salto de línea (el oef, end of last file) y tener el peso del archivo que se pide se puede utilizar este comando del lenguaje *perl*:
```bash
perl -pi -e "chomp if oef" Nombre_del_archivo
```

### Ex06
```bash
ls -l | awk 'NR % 2==0'
            └────┬────┘
                 └────╴> Muestra la línea solo si el resultado del módulo (%) del número de línea (NR) es igual a 0. en el caso de "%2" se fuerza a que sean las líneas pares
```

### Ex07
```bash
cat -e /etc/passwd | grep -v '^#' | awk 'NR%2==0' | awk -F:'print $1' | rev | sort -r | awk -v ln1=$FT_LINE1 -v ln2=$FT_LINE2 'NR>=ln1 AND NR<=ln2' | awk '{print $0 ", "}' | sed "s/, $/./"

# Explicación:
cat -e /etc/passwd  --> Muestra el contenido del archivo

grep -v '^#'        --> Invierte la busqueda ("-v", busca cosas que NO tengan lo especificado) del texto "^#" donde '^' significa inicio de línea y '#' es el caracter que se usa para hacer comentarios en bash. Por que se esta buscando todo lo que no sea comentario

awk 'NR%2==0'       --> Muestra las líneas pares

awk -F:'print $1'   --> Imprime la segunda columna (se empieza a contar desde 0)

rev                 --> Da la vuelta a las palabras

sort -r             --> Ordena el resultado el orden alfabético, pero al tener la opción "-r" es orden alfabético inverso

awk -v ln1=$FT_LINE1 -v ln2=$FT_LINE2 'NR>=ln1 AND NR<=ln2'
    │└────╴> Para declarar "ln1"    │
    │        como variable          │
    └───────────────┬───────────────┘
                    └───╴> Variables donde están las líneas

awk '{print $0 ", "}' --> Imprime la primera columna (0) con una coma y un espacio al final

sed "s/, $/./"        --> Sustituye (s/) el texto 1 (", $", donde '$' es el terminador de la línea) por el texto 2 (".")
```

### Ex08
1. Pasar las bases a números

| ' | \ | " | ? | ! |   | m | r | d | o | c |   | g | t | a | i | o | _ | l | w | S | n | e | m      | f      |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|--------|--------|
| 0 | 1 | 2 | 3 | 4 |   | 0 | 1 | 2 | 3 | 4 |   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 / A | 11 / B | 12 / C |

2. Crear las variables de entorno
```bash
export FT_NBR1=\\\'\?\"\\\"\'\\ # Lo que se traduce en: \'?"\"'\
export FT_NBR2=rcrdmddd
```
3. Ejecutar el siguiente comando
```bash
echo $FT_NBR1 + $FT_NBR2 | sed "s/'/0/g" | sed 's/\\/1/g' | sed "s/\"/2/g" | sed 's/?/3/g' | sed 's/\!/4/g' | tr "mrdoc" "01234" | xargs echo "ibase=5;obase=23;" | bc | tr "0123456789ABC" "gtaio lusnemf"

# Explicación:
echo $FT_NBR1 + $FT_NBR2 --> NOTA: La suma no se ha sumado todavía

Comandos para pasar de letras a números:
sed "s/'/0/g"     --> Observa que se han usado comillas dobles, esto es debido a que se está sustituyendo una comilla simple. La 'g' final sirve para copiar el espacio de patrones (patter space) en el espacio mantenido (hold space)
sed 's/\\/1/g'    --> Se usa "\\" para poder sustituir el caracter '\'
sed "s/\"/2/g"    --> Se usa "\\" para poder sustituir el caracter '"'. También se usan comillas dobles
sed 's/?/3/g'
sed 's/\!/4/g'    --> Se usa "\\" para poder sustituir el caracter '!'
tr "mrdoc" "01234"

xargs echo "ibase=5;obase=23;"  --> Son comandos de la "bc"
└─┬─┘       └─┬─┘   └─┬─┘ ├┘
  │           │       │   └────╴> Como se quiere poner "12", pero se está en base "5" hay que poner 23[^1].
  │           │       └────╴>
  │           └────╴>
  └────╴>
bc --> Es una calculadora. Cogera el input, lo sumará y le cambiará la base
tr "0123456789ABC" "gtaio lusnemf"  --> Toma en resultado de "bc" y lo vuelve a pasar a letras
```
[^1]
| Base entrada = 5 | 1 | *2* | *3* | 4 | 5 |
|------------------|---|-----|-----|---|---|
| Base de salida   | 0 | *1* | *2* | 3 | 4 |
