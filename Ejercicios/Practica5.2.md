
# Ejercicios

## Ejercicio 1
### Muestre por pantalla el texto "Practica 5: Manejo de Scripts (I) – Inicio…"
```bash
ruben.conde@polifemo:~/prac5/guiones$ echo Practica 5: Manejo de Scripts - Inicio..
```

## Ejercicio 2
### Cree un directorio llamado Practica5 dentro de ModuloI.
```bash
ruben.conde@polifemo:~/ModuloI$ mkdir Practica5
```
## Ejercicio 3
### Cree una variable llamada YO, que contenga su nombre y apellidos.
```bash
ruben.conde@polifemo:~$ YO="Rubén Conde Quintero"
```
## Ejercicio 4
### Cree un script llamado saludos.sh en el directorio Practica5 que visualice la hora, el mensaje "Saludos " seguido del contenido de la variable YO, y sus procesos de usuario.
```bash
ruben.conde@polifemo:~/ModuloI/Practica5$ export YO
date +"%R"
echo Saludos $YO
ps

```
## Ejercicio 5
### Compruebe el funcionamiento del script saludos.sh.
```bash
ruben.conde@polifemo:~/ModuloI/Practica5$ saludos.sh
13:55
Saludos Rubén Conde Quintero
  PID TTY          TIME CMD
59026 pts/4    00:00:00 bash
60360 pts/4    00:00:00 saludos.sh
60362 pts/4    00:00:00 ps
```
## Ejercicio 6
### Cree un script llamado contador.sh en el directorio Practica5 que tome dos parámetros (ruta a un directorio y cadena de caracteres) y cuente los archivos que contienen dicha cadena.
```bash
ruben.conde@polifemo:~/ModuloI/Practica5$ joe contador.sh

    I A  contador.sh (sh)                                  Row 2    Col 1
#!/bin/bash
grep -rl $2 $1 | wc -l
```
## Ejercicio 7
### Consulte la ayuda de la orden sleep.
```bash
ruben.conde@polifemo:~/ModuloI/Practica5$ man sleep
```
## Ejercicio 8
### Cree un script llamado personal.sh en el directorio Practica5 que solicite la edad, cree un alias para mostrar archivos ocultos y espere un segundo antes de mostrar "Fin del script".
```bash
ruben.conde@polifemo:~/ModuloI/Practica5$ joe personal1.sh

^K  I A  personal1.sh (Modified)(sh)  export ocultos       Row 4    Col 15
echo Introduzca su edad
read EDAD
alias ocultos="ls -a $(pwd)"
sleep 1
echo fin del script

```
## Ejercicio 9
### Ejecute el script personal.sh y asegúrese de que la variable y el alias estén disponibles tras su ejecución.
```bash
ruben.conde@polifemo:~/ModuloI/Practica5$ . personal1.sh
```
## Ejercicio 10
### Compruebe el funcionamiento del alias ocultos.
```bash
ruben.conde@polifemo:~/ModuloI/Practica5$ ocultos
```
## Ejercicio 11
### Cree un script llamado salida.sh en el directorio Practica5 que muestre un mensaje de cierre, espere 5 segundos y termine con estado 15.
```bash
ruben.conde@polifemo:~/ModuloI/Practica5$ joe salida.sh

^K  I A  salida.sh (Modified)(sh)                          Row 3    Col 8
echo Este script se cerrara en 5 segundos con estado de salida 15
sleep 5
exit 15
```
## Ejercicio 12
### Compruebe por pantalla el estado resultante del último proceso ejecutado.
```bash
ruben.conde@polifemo:~/ModuloI/Practica5$ echo $?
15
```
## Ejercicio 13
### Cree los scripts padre.sh e hijo.sh en el directorio Practica5 para gestionar procesos y variables entre padre e hijo.
```bash
ruben.conde@polifemo:~/ModuloI/Practica5$ joe padre.sh

^K  I A  padre.sh (Modified)(sh)  . /home/ruben.conde/Mod  Row 6    Col 3
#!/bin/bash
echo "Proceso padre (inicio).."
export V1
echo V1=$V1
ps
. /home/ruben.conde/ModuloI/Practica5/hijo.sh
echo V1=$V1
echo "Proceso Padre (fin)..."
ruben.conde@polifemo:~/ModuloI/Practica5$ joe hijo.sh

^K  I A  hijo.sh (Modified)(sh)  echo "Proceso hijo(inici  Row 2    Col 28
#!/bin/bash
echo "Proceso hijo(inicio)"
echo V1=$V1
V1="Mundo Hola"
echo V1=$V1
ps
echo "Proceso hijo(fin) .."

```
## Ejercicio 14
### Ejecute el proceso padre.sh y analice el resultado obtenido.
```bash
ruben.conde@polifemo:~/ModuloI/Practica5$ ./padre.sh
Proceso padre (inicio)..
V1=Hola Mundo
  PID TTY          TIME CMD
 2669 pts/4    00:00:00 padre.sh
 2670 pts/4    00:00:00 ps
59026 pts/4    00:00:00 bash
Proceso hijo(inicio)
V1=Hola Mundo
V1=Mundo Hola
  PID TTY          TIME CMD
 2669 pts/4    00:00:00 padre.sh
 2671 pts/4    00:00:00 ps
59026 pts/4    00:00:00 bash
Proceso hijo(fin) ..
V1=Mundo Hola
Proceso Padre (fin)...
```
## Ejercicio 15
### Muestre por pantalla el texto "Practica 5: Manejo de Scripts (I) – Finalizada…"
```bash
ruben.conde@polifemo:~/ModuloI/Practica5$ echo "Practica 5: Manejo de Script
s (I) – Finalizada…"
```
## Ejercicio 16
### Salga adecuadamente del sistema.
```bash
ruben.conde@polifemo:~/ModuloI/Practica5$ exit
```
