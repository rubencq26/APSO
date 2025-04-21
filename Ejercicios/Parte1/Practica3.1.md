# Practica 3.1

## Ejercicio 1

Cree con un solo comando el siguiente árbol de directorios a partir de su directorio personal con rutas relativas.
![imagen](https://github.com/user-attachments/assets/e01a66da-5466-4e61-b8a9-3d848089709f)

```bash
ruben.conde@polifemo:~$ mkdir -p prac3/prac31/temp1 prac3/prac32/tmp2 prac3/prac33/tmp3

```
---

## Ejercicio 2

Quite todo tipo de privilegios para el grupo y el resto de los grupos a los directorios prac3, prac31, prac32 y prac33 usando rutas relativas. El propietario deberá tener todos los permisos sobre esos directorios.

```bash
ruben.conde@polifemo:~$ chmod 700 $(find prac3)

```
---

## Ejercicio 3

Visualice todos los ficheros y directorios de su directorio personal (incluso los ocultos), con los permisos establecidos sobre cada uno de ellos.

```bash
ruben.conde@polifemo:~$ ls -la

```
---

## Ejercicio 4

Con el comando find, el wc y las tuberías cuente cuántos directorios tiene a partir de su directorio personal que tengan una m o un número en su nombre.

```bash
ruben.conde@polifemo:~$ find ~ -type d -name "[mM0123456789]*" | wc -l

```
---

## Ejercicio 5

Busque, a partir del directorio /bin, todos los ficheros (no directorios) que comiencen por vocal y se hayan modificado hace más de 1 día. La salida de ese comando la debe enviar a un fichero llamado comandos que se guardará en el directorio tmp1 de prac31. No deben aparecer los errores por pantalla. Hágalo con sólo una línea de comando.

```bash
ruben.conde@polifemo:~$ find /bin -type f -mtime +1 -name "[aAeEiIoOuU]*" 1> prac3/prac31/temp1/comandos.txt

```
---

## Ejercicio 6

Encuentre todos los ficheros del sistema (del tipo que sean: normales, directorios, enlaces, de dispositivo, etc....) cuyo primer carácter sea una vocal o un número, la segunda no sea un número, termine en .c o .p y su nombre tenga sólo 6 caracteres (contando el punto y la extensión). La salida de debe ser visualizada página a página y los errores no deben mostrarse por pantalla.

```bash
ruben.conde@polifemo:~$ find / -name "[aAeEiIoOuU0123456789][!0123456789]??.[pc]" 2>/dev/null | more

```
---

## Ejercicio 7

Copie todos los ficheros que tenga a partir de su directorio personal que empiecen con el texto sol y tengan una p en su nombre en el directorio tmp2 del directorio prac32. Use para ello sustitución de comandos.

```bash
ruben.conde@polifemo:~$ cp $(find ~ -type f -name "sol*p*") /home/ruben.conde/prac3/prac32/tmp2/
```
---

## Ejercicio 8

Muévase al directorio prac33. Mueva todos los ficheros que a partir de su directorio personal terminan en ~ al directorio tmp3. Borre del directorio tmp3 todos los ficheros que terminan en ~. (Asegúrese antes que sólo tiene ficheros que terminan en ese carácter - Alt+126).

```bash
ruben.conde@polifemo:~$ cd prac3/prac33
ruben.conde@polifemo:~/prac3/prac33$ mv $(find ~ -type f -name "*~") tmp3/
```
---

## Ejercicio 9

Muévase al directorio prac3 con rutas relativas. Cree con el comando cal, y tras ejecutarlo 4 veces, un fichero llamado 2_cuatrimestre en el directorio prac32 con el calendario de los meses de marzo, abril, mayo y junio de este año.

```bash
ruben.conde@polifemo:~/prac3/prac33$ cd ..
ruben.conde@polifemo:~/prac3$ cal 3 2025 1> prac32/calendario.txt
ruben.conde@polifemo:~/prac3$ cal 4 2025 1>> prac32/calendario.txt
ruben.conde@polifemo:~/prac3$ cal 5 2025 1>> prac32/calendario.txt
ruben.conde@polifemo:~/prac3$ cal 6 2025 1>> prac32/calendario.txt
```
---

## Ejercicio 10

Introduzca la siguiente lista por teclado mediante el comando sort de forma que al final obtenga un fichero llamado ciudades en el directorio prac32 con la lista ordenada (en orden descendente) de lo introducido por teclado:

- cordoba
- sevilla
- huelva
- almeria
- cadiz
- malaga
- jaen
- granada

```bash
ruben.conde@polifemo:~/prac3$ sort -r 1> prac32/ciudades.txt
- cordoba
- sevilla
- huelva
- almeria
- cadiz
- malaga
- jaen
- granada
```
---

## Ejercicio 11

Cree un fichero llamado usuarios en el directorio prac32 con la lista de todos los directorios personales de los usuarios del sistema, ordenada alfabéticamente en orden ascendente y con una sola línea de comando (Para ello use el find con las opciones oportunas, el sort, tuberías y redirección)(Suponga que cada directorio del directorio /home es de un usuario del sistema)(Deben salir sólo los directorios y sólo su nombre -no la ruta- (se consigue con la opción -printf))(Cada directorio estará en una línea del fichero)(No hay que adentrarse en las carpetas de cada usuario (opción -maxdepth)).

```bash
ruben.conde@polifemo:~/prac3$ find /home -type d -printf "%f\n" -maxdepth 1 | sort 1> prac32/usuarios.txt
```
---

## Ejercicio 12

Cree en el directorio prac32 un fichero llamado personal que contenga 4 líneas con la siguiente información: nombre de usuario, identificador de usuario, nombre de grupo, identificador de grupo. No está permitido usar ningún editor de textos para crear este fichero. (Hay que ejecutar 4 veces el comando id).

```bash
ruben.conde@polifemo:~/prac3$ id -un > prac32/personal.txt
ruben.conde@polifemo:~/prac3$ id -u >> prac32/personal.txt
ruben.conde@polifemo:~/prac3$ id -gn >> prac32/personal.txt
ruben.conde@polifemo:~/prac3$ id -g >> prac32/personal.txt
```
