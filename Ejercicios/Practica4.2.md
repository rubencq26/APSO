# Ejercicios - Práctica 4.2 Manejo de la Shell

## Ejercicio 1
Muestre por pantalla el texto “Practica 4: Manejo de Shell – Inicio…”
```bash
 ruben.conde@polifemo:~$ echo Practica 4: Manejo de Shell - Inicio
```

## Ejercicio 2
Cree un directorio llamado `Practica4` dentro de `ModuloI`. Dentro de este último, cree otro llamado `temp`.
```bash
ruben.conde@polifemo:~$ mkdir -p ModuloI/Practica4/temp
```

## Ejercicio 3
Visualice el valor de todas las variables definidas en el sistema mostrándolas pantalla a pantalla.
```bash
ruben.conde@polifemo:~$ set -o
```

## Ejercicio 4
Ejecute el shell `ksh`. ¿Qué cambios observa? ¿Funciona la tecla de tabulación de la misma forma?
```bash
~ [8]$
Cambia el Promt y si funciona la tabulacion
```
## Ejercicio 5
Ejecute el shell `sh`. ¿Qué cambios observa? ¿Funciona la tecla de tabulación de la misma forma?
```bash
$
El tabulador no funciona
```
## Ejercicio 6
Salga de las shell que ha ejecutado y vuelva a `bash`.
```bash
$ exit
```
## Ejercicio 7
Active el atributo de la shell `xtrace` (para mostrar el comando a ejecutar).
```bash
ruben.conde@polifemo:~$ set -x
```
## Ejercicio 8
Desde su directorio de usuario, ejecute la orden necesaria para copiar los ficheros que haya desde el directorio raíz, que comiencen por `rmt` al directorio `temp` creado anteriormente y observar el resultado (use para ello sustitución de comandos).
```bash
ruben.conde@polifemo:~$ cp $(find / -type f -name "rmt*" 2> /dev/null) ModuloI/Practica4/temp
```
## Ejercicio 9
Desactive el atributo activado en el punto anterior.
```bash
ruben.conde@polifemo:~$ set +x
```
## Ejercicio 10
Cree una variable llamada `P4` que contenga la ruta absoluta al directorio `Practica4`.
```bash
ruben.conde@polifemo:~$ P4="/home/ruben.conde/ModuloI/Practica4/"
```
## Ejercicio 11
Use la variable `P4` para moverse al directorio `Practica4`.
```bash
ruben.conde@polifemo:~$ cd $P4
```
## Ejercicio 12
Visualice la ayuda de la orden `echo`.
```bash
ruben.conde@polifemo:~/ModuloI/Practica4$ man echo
```
## Ejercicio 13
Visualice por pantalla el mensaje “El directorio de trabajo actual es <<ruta al directorio de trabajo actual>>”. Haga uso de la variable `PWD`.
```bash
ruben.conde@polifemo:~/ModuloI/Practica4$ echo "El directorio de trabajo actual es $(pwd)"
El directorio de trabajo actual es /home/ruben.conde/ModuloI/Practica4
```
## Ejercicio 14
Elimine la variable `HOME`.
```bash
ruben.conde@polifemo:~/ModuloI/Practica4$ unset $HOME
```
## Ejercicio 15
Muévase a su directorio de usuario mediante la orden `cd` sin argumentos. ¿Qué ocurre?
```bash
ruben.conde@polifemo:/home/ruben.conde/ModuloI/Practica4$ cd
-bash: cd: HOME not set
```
## Ejercicio 16
Cree un fichero llamado `losalias`, en el directorio `Practica4`, que contenga todos los alias definidos ordenados en orden inverso.
```bash
ruben.conde@polifemo:/home/ruben.conde/ModuloI/Practica4$ alias | sort -r > losalias
```
## Ejercicio 17
Cree un alias llamado `fecha`, que visualice la fecha en formato “23 del 11 de 2009”.
```bash
ruben.conde@polifemo:/home/ruben.conde/ModuloI/Practica4$ alias fecha="echo $(date +%"d") del $(date +%"m") de $(date +%"Y")"
```
## Ejercicio 18
Restaure la variable `HOME` a su directorio personal.
```bash
ruben.conde@polifemo:/home/ruben.conde/ModuloI/Practica4$ HOME="/home/ruben.conde"
```
## Ejercicio 19
Cree un alias llamado `p4`, que cambie siempre al directorio `Practica4` desde cualquier ubicación.
```bash
ruben.conde@polifemo:~/ModuloI/Practica4$ alias p4="cd /home/ruben.conde/ModuloI/Practica4"
```
## Ejercicio 20
Cámbiese al directorio `Practica2` y use el alias `p4` para moverse al directorio `Practica4`.
```bash
ruben.conde@polifemo:~/ModuloI/Practica4$ cd ../Practica2
ruben.conde@polifemo:~/ModuloI/Practica2$ p4
```
## Ejercicio 21
Modifique el prompt para que muestre el nombre del usuario en vez del nombre de la máquina, únicamente en la sesión en la que se realiza esta orden.
```bash
ruben.conde >PS1="\u>"
```
## Ejercicio 22
Haga que la variable `PATH` incluya la ruta al directorio de usuario de forma permanente.
```bash
PATH="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/home/ruben.conde"
```
## Ejercicio 23
Haga que cada vez que acceda al sistema, se muestre un mensaje de bienvenida que incluya su nombre de usuario.
```bash
echo "bienvenido $(id -un)"
```
## Ejercicio 24
Elimine el alias `p4` creado anteriormente.
```bash
ruben.conde>unalias p4
```
## Ejercicio 25
Muestre en pantalla el mensaje “Práctica 4: Manejo de Shell… Finalizada”.
```bash
ruben.conde>echo "Práctica 4: Manejo de Shell:: Finalizada"
```
## Ejercicio 26
Salga adecuadamente del sistema.
```bash
ruben.conde>exit
```
