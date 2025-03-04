
# Ejercicios

## Ejercicio 1
Muestre por pantalla el texto "Practica 3: Manejo de Shell – Inicio…"
```bash
ruben.conde@polifemo:~$ echo "Practica 3: Manejo de Shell – Inicio…"
```

## Ejercicio 2
Cree un directorio llamado Practica3 dentro de ModuloI. Acceda dentro del directorio ModuloI.
```bash
ruben.conde@polifemo:~$ mkdir ModuloI/Practica3
ruben.conde@polifemo:~$ cd ModuloI/
```
## Ejercicio 3
Use la orden find para visualizar los nombres y los tamaños de todos los ficheros (sólo los ficheros) que cuelguen de su directorio de usuario y cuyo tamaño sea inferior a 100 caracteres. Sólo deben aparecer los nombres de ficheros (sin la ruta) y los tamaños.
```bash
ruben.conde@polifemo:~/ModuloI$ find ~ -printf "%f   %b\n"  -size -100c -type f
```
## Ejercicio 4
Copie el fichero /home/so/ficheros/infinito al directorio Practica3.
```bash
ruben.conde@polifemo:~$ cp /home/so/ficheros/infinito ModuloI/Practica3
```
## Ejercicio 5
Haga que el fichero infinito tenga permisos de ejecución para todos.
```bash
ruben.conde@polifemo:~/ModuloI$ chmod 711 Practica3/infinito
```
## Ejercicio 6
Ejecute el fichero infinito.
```bash
ruben.conde@polifemo:~/ModuloI$ Practica3/infinito
```
## Ejercicio 7
En un nuevo terminal, visualice los procesos que está ejecutando.
```bash
ruben.conde@polifemo:~$ ps aux
```
## Ejercicio 8
Vuelva al terminal donde ejecutó infinito y aborte el proceso (CTRL+C).
```bash

```
## Ejercicio 9
Ejecute nuevamente el programa infinito, pero esta vez en segundo plano.
```bash

```
## Ejercicio 10
En el mismo terminal donde se está ejecutando infinito, visualice los procesos que está ejecutando.
```bash
ruben.conde@polifemo:~/ModuloI$ Practica3/infinito &
```
## Ejercicio 11
Recupere (traiga a primer plano) el proceso infinito. Abórtelo una vez recuperado.
```bash
ruben.conde@polifemo:~/ModuloI$ fg 1
```
## Ejercicio 12
Haga que el resultado devuelto por la orden del punto 3 quede en un fichero llamado pequeños en el directorio Practica3.
```bash
ruben.conde@polifemo:~/ModuloI$ find ~ -printf "%f   %b\n"  -size -100c -type f 1> Practica3/pequeños
```
## Ejercicio 13
Cambiamos al directorio Practica3.
```bash
ruben.conde@polifemo:~/ModuloI$ cd Practica3
```
## Ejercicio 14
Usando las órdenes necesarias, cree un fichero llamado minfo, dentro del directorio Practica3, que contenga tres líneas: la primera con su nombre de usuario, la segunda con el terminal que está usando, y la última con el nombre del grupo al que pertenece.
```bash
ruben.conde@polifemo:~/ModuloI/Practica3$ id -un > minfo
ruben.conde@polifemo:~/ModuloI/Practica3$ tty >> minfo
ruben.conde@polifemo:~/ModuloI/Practica3$ id -gn >> minfo
```
## Ejercicio 15
Visualice los nombres de los ficheros que cuelgan del directorio /etc y que hace más de 100 días que han sido modificados. Los errores no deben aparecer por la pantalla.
```bash
ruben.conde@polifemo:~/ModuloI/Practica3$ find /etc -mtime +100 2> /dev/null
```
## Ejercicio 16
Haga que los errores generados en el punto anterior se almacenen en un fichero llamado err del directorio Practica3.
```bash
ruben.conde@polifemo:~/ModuloI/Practica3$ find /etc -mtime +100 2> err
```
## Ejercicio 17
Genere un fichero en el directorio Practica3, llamando crons, que contenga el resultado de buscar todos los ficheros que cuelguen a partir del directorio /var que comiencen por cr. Los errores también deben aparecer en el fichero.
```bash
ruben.conde@polifemo:~/ModuloI/Practica3$ find /var/ -name "cr*" -type f &> crons
```
## Ejercicio 18
Visualice el número (sólo el número) de directorios que existan a partir de su directorio de usuario.
```bash
ruben.conde@polifemo:~/ModuloI/Practica3$ find ~ -type d | wc -l
```
## Ejercicio 19
Genere un fichero, en el directorio Practica3, llamado usersort, que contenga los nombres de los usuarios conectados al sistema en ese instante, ordenados alfabéticamente en orden inverso.
```bash
ruben.conde@polifemo:~/ModuloI/Practica3$ find /home/ -type d -maxdepth 1 -printf "%f\n" | sort -r 1> usersort
```
## Ejercicio 20
Con una única orden busque, a partir de su directorio de usuario, todos los ficheros que comiencen por f o s, y visualice el contenido de todos ellos pantalla a pantalla. (Use sustitución de comandos).
```bash
ruben.conde@polifemo:~/ModuloI/Practica3$ more $(find ~ -type f -name "[fs]*")
```
## Ejercicio 21
Con una única orden, copie cualquier fichero que esté en vuestro directorio ModuloI, o dentro de cualquier subdirectorio, y cuyo tiempo de acceso hace más de 2 días, al directorio mas2 creado de manera previa dentro del directorio Practica3. (Use sustitución de comandos).
```bash
ruben.conde@polifemo:~/ModuloI/Practica3$ cp $(find ../ -atime +2 -type f) mas2
```
## Ejercicio 22
Muestre en pantalla el mensaje "Práctica 3: Manejo de Shell… Finalizada".
```bash
ruben.conde@polifemo:~/ModuloI/Practica3$ echo "Práctica 3: Manejo de Shell… Finalizada"
```
## Ejercicio 23
Salga adecuadamente del sistema.
```bash
ruben.conde@polifemo:~/ModuloI/Practica3$ exit
```
