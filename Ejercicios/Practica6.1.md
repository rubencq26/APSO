
# Ejercicios
\[\e]0;\u@\h: \w\a\]${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$

```bash

```
## Ejercicio 1
### Cree con un solo comando el siguiente árbol de directorios a partir de su directorio personal mediante rutas relativas.
![image](https://github.com/user-attachments/assets/65f7090d-c3e8-4560-8c43-1fdb454ae85b)

```bash
ruben.conde@polifemo:~$ mkdir -p prac6/prac6 prac6/fuentes/tmp1/tmp2 prac6/guiones

```
## Ejercicio 2
### Incluya dentro del fichero .profile la variable GUION con la ruta al directorio guiones creado anteriormente. Haga que tome efecto esta variable. Copie todos los ficheros que a partir de su directorio personal terminen en .txt en el directorio tmp1.
```markdown
```bash
GUION="/home/ruben.conde/prac6"
ruben.conde@polifemo:~$ . ./.profile

```
## Ejercicio 3
### Muévase al directorio guiones. Cree un guión en el directorio guiones llamado tratafichero. Este guión debe recoger un único parámetro. Si el parámetro es un fichero ordinario debe visualizar su contenido con el comando more. Si se trata de un directorio, se debe ver el contenido del mismo con el comando ls -la. Si no es ni un fichero ni un directorio debe hacerse un echo del parámetro. (Se necesita usar el comando test y la estructura if).

```bash

```
## Ejercicio 4
### Muévase al directorio prac6 que está dentro de prac6. Ejecute desde aquí el guión anterior dos veces. La primera vez pásele como parámetro $HOME/prac2/f1.txt. La segunda pásele como parámetro la variable GUION creada en el apartado 2.

```bash

```
## Ejercicio 5
### Muévase al directorio guiones. Cree un guión llamado fpfinal que copie todos los nombres de enlaces simbólicos encontrados en un directorio especificado, cuyo nombre coincida con el segundo parámetro, y los guarde en un archivo enlaces.txt dentro del tercer directorio especificado. Los errores no deben mostrarse en pantalla.
Si no se pasan 3 parámetros visualiza un mensaje que dice: Se necesitan
al menos 3 parámetros
Si se pasan 3 parámetros se comprueba que el primero y el tercero son
directorios. Si no lo son, visualiza el mensaje: El primer y tercer
parámetro han de ser directorios
Copia todos los nombres (solo el nombre, no la ruta) de enlaces simbólicos
(ficheros soft link) encontrados a partir del primer directorio especificado,
cuyo nombre coincida con el segundo parámetro, en el directorio
especificado en tercer lugar con el nombre enlaces.txt. Los errores no
deben salir por pantalla.
Ejecute este guion con los parámetros siguientes:
Primer parámetro: /home
Segundo parámetro: ficheros que empiecen por una letra mayúscula.
Tercer parámetro: directorio fuentes creado en el apartado 1 

```bash

```
## Ejercicio 6
### Cree un guión llamado mtam que muestre, para cada fichero encontrado a partir del directorio pasado como primer parámetro ```markdowncuyo nombre coincide con el segundo parámetro, su tamaño. Compruebe que el número de parámetros es el correcto y que el primero es un directorio. (Usa el for en el guión).
Ejecútelo con los parámetros siguientes:
Primer parámetro: directorio fuentes creado anteriormente.
Segundo parámetro: ficheros que empiecen por s y tengan un punto
en su nombre. 
```bash

```
## Ejercicio 7
### Cree un guión llamado anida, al que se le pasará un parámetro y deberá hacer lo siguiente: Pedirá que se introduzca un número por el teclado y creará tantos directorios anidados como indique el número leído, a partir del directorio en el que nos encontramos.

Pedirá que se introduzca un número por el teclado.
Creará tantos directorios anidados, con el nombre que se ha pasado como
primer parámetro, como indique el número leído, a partir del directorio en el
que nos encontramos.

Ejemplo: Se ejecuta anida p1 y el número que se lee es 3. Esto creará un
directorio p1, que tiene dentro un directorio p1, que a su vez tiene dentro un
directorio p1, a partir del directorio en el que estamos.

NOTA: Se monta un bucle while, que itera tantas veces como indique el
contador, y dentro se va creando la ruta de los subdirectorios sobre una
variable, que es la usada para crear los subdirectorios.
Muévase al directorio tmp2. Ejecute desde aquí el guión anterior de la
siguiente forma: anida p6 y se teclea el número 2 por teclado cuando lo
solicite. 
```bash

```
## Ejercicio 8
### Muévase al directorio guiones. Cree un guión llamado opcion que lea una palabra del teclado. Si la palabra empieza por un número almacena la palabra al final de un fichero llamado numero, en un fichero llamado vocal si empieza por vocal y en un fichero llamado otro para cualquier otro caso. Use el case para decidir a que fichero va la palabra. Debe estar haciendo siempre lo mismo hasta que se pulse un punto, pero no debe parar si se introduce un punto seguido de cualquier otro conjunto de caracteres. 

```bash

```
## Ejercicio 9
### Modifique los permisos de los directorios tmp1 y tmp2 para que el propietario tenga todos los permisos menos el de ejecución, el grupo solo el de lectura y los otros solo el de ejecución.

```bash

```
## Ejercicio 10
### Consulte el número de procesos total que tiene activos en este preciso momento (contando los de todas las ventanas abiertas). (Se usa ps y wc).
```bash

```
