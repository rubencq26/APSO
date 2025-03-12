# GUIONES/ SCRIPTS
### $
 $variable -> Ejemplo-> echo home vale $HOME \

````bash
  -> $(orden) = `orden `
````
  ACENTO GRAVE -> ```bash `   ` ```

### \
echo \$PATH contiene $PATH
La \ quita el significado al caracter siguiente
ls a* -> ls a\*

### COMILLAS SIMPLES Y COMILLAS DOBLES
Si está entre comillas se asumirá como una cadena. \
Pero las comillas dobles si interpretan los carácteres \ ` y $. \
Ejemplo \
echo 'la variable HOME contiene $HOME' \
echo "la variable HOME contiene $HOME" -> conserva el significado

### ORDEN FILE
Especifica la extencion del archivo, aunque su extensión no esté visible.
Ejemplo
```bash
pedro@Polifemo:~$ file fichero_sin_extension
````

### CREACIÓN DE GUIONES
Los comentarios dentro del guion se hacen con #
```bash
pedro@Polifemo:~$ joe ejemplo_simple
date
ps
who
CTRL+k,x
File ejemplo_simple saved

## DAMOS PERMISO DE EJECUCIÓN
pedro@Polifemo:~$ chmod a+x ejemplo_simple

# COMO EJECUTARLO DE MANERA ABSOLUTA
pedro@Polifemo:~$ /home/pedro/ejemplo_simple
lun mar 16 13:53:37 CET 2020
 PID TTY TIME CMD
 5826 pts/0 00:00:00 bash
25761 pts/0 00:00:00 bash
25763 pts/0 00:00:00 ps
pedro :1 2020-03-16 07:51 (:1)

 # CON RUTA RELATIVA
pedro@Polifemo:~$ ./ejemplo_simple
lun mar 16 13:53:40 CET 2020
 PID TTY TIME CMD
 5826 pts/0 00:00:00 bash
25765 pts/0 00:00:00 bash
25767 pts/0 00:00:00 ps
pedro :1 2020-03-16 07:51 (:1)

#PARA QUE SEA RECONOCIBLE COMO GUIÓN (colorea la sintaxis)
#!/bin/bash
```
Con WHICH ves la ruta del bash o del ksh \
PARA LA EJECUCIÓN :
```bash
pedro@Polifemo:~$ cat ejemplo_entorno
#!/bin/bash
VARIABLE1=V1
echo la variable VARIABLE1 vale $VARIABLE1
echo fin del guión
pedro@Polifemo:~$ ./ejemplo_entorno
la variable VARIABLE1 vale V1
fin del guión
pedro@Polifemo:~$ echo el valor de VARIABLE1 ES $VARIABLE1
el valor de VARIABLE1 ES

```
### ENTRADA, SALIDA Y FINALIZACIÓN DE UN GUIÓN
Read-> crea una variable o la sobreescribe, para q el usuario pueda escribir
EJEMPLO
```bash
#!/bin/bash
echo Introduce una ruta
read LARUTA
find $LARUTA -maxdepth 1 -type d 2>dev/null
ls -ld ~$'find $LARUTA -maxdepth 1 -type d 2>dev/null'

```
Con el exit se finaliza un guion

Segunda manera de ejecutar un proceso, es crear un proceso nuevo que sea g2. Entonces bash habrá creado un proceso.\

Export YO -> exporta la variable y además puedes añadirle contenido.\
Una variable marcada con la orden export, es copiada a cualquier guión que se ejecute
desde el shell que la marcó, por tanto, se podrá usar en el guión. No obstante, se hace
una copia de dicha variable, de modo que de su modificación en el guión, no afecta a la
variable original.
Ejemplo
```bash
pedro@Polifemo:~$ NOEXPORTADA="Variable que no se exportara"
pedro@Polifemo:~$ EXPORTADA="Variable que se exportara"
pedro@Polifemo:~$ echo $NOEXPORTADA
Variable que no se exportara
pedro@Polifemo:~$ echo $EXPORTADA
Variable que se exportara
pedro@Polifemo:~$ export EXPORTADA
pedro@Polifemo:~$ cat ejemplo_entorno2
#!/bin/bash
echo La variable que se exporta vale: $EXPORTADA
echo La variable que no se exporta vale: $NOEXPORTADA
EXPORTADA="Variable que se exportara modificada"
echo fin del guión
```

### EJECUCIÓN DEL GUIÓN EN MODO SOURCE
source ./g2 \
source se puede cambiar por un . -> . ./g2
Si queremos que los cambios que el guión realice en el entrono permanezcan en el
entorno del shell que lo lanza, podemos ejecutar el guión mediante el comando source.
```bash
pedro@Polifemo:~$ cat ejemplo_entorno3
#!/bin/bash
#creamos una variable
V1="vARIABLE UNO"
#creamos un alias
alias yo=whoami
echo fin del guion
pedro@Polifemo:~$ source ./ejemplo_entorno3
fin del guion
pedro@Polifemo:~$ echo $V1
vARIABLE UNO
pedro@Polifemo:~$ yo
pedro

```
### PASO DE PARÁMETROS A UN GUIÓN
./g3 7 9
```bash
GUION
echo los parametros pasados son
echo el primer parametro $1
echo el segundo parámetro $2
```
A partir del 9 se pone {10}, {11}... \
Para saber la cantidad de parámetros se pone $#
La lista de parámetros $*
$0 -> nombre del archivo ejecutado


# Ejercicios

### Ejercicio 1
1. Cree con un solo comando el siguiente árbol de directorios a partir de su directorio personal mediante rutas absolutas.
2. ![image](https://github.com/user-attachments/assets/7c7fa3b2-a13a-4b2e-9518-38bb97c398df)
```bash
ruben.conde@polifemo:~$ mkdir -p /home/ruben.conde/prac5/prac51 /home/ruben.conde/prac5/prac52 /home/ruben.conde/prac5/guiones
```

### Ejercicio 2
2. Añada en el fichero .profile a la variable PATH una nueva ruta, la ruta hasta el directorio guiones que hemos creado en el apartado 1. Esta nueva línea no tendrá efecto hasta que no ejecutemos el fichero .profile. Ejecute el fichero .profile de la forma adecuada para que el nuevo PATH tome efecto. Visualice de nuevo la variable PATH para asegurarse que tiene lo que tenía en la práctica 4 más la nueva ruta que hemos añadido en este apartado. \
IMPORTANTE!!! No continúe adelante si no ha conseguido añadir esa nueva ruta a la variable PATH. Si continúa con el resto de apartados sin hacer los anteriores no podrá realizarlos correctamente.
```bash
PATH="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/home/ruben.conde:.:/home/ruben.conde/prac5/guiones"
```

### Ejercicio 3
3. Muévase al directorio guiones. Cree un guión llamado busca en este directorio que reciba como parámetros un directorio y un número. El guión debe buscar los ficheros (no directorios) a partir del directorio especificado que hayan sido modificados hace menos de n días, siendo n el número de días especificado. Muévase de nuevo a su directorio personal. Ejecute desde aquí el guión pasando como parámetros su directorio personal y el número 10.
```bash
ruben.conde@polifemo:~$ cd prac5/guiones/
find $1 -type f -mtime -$2 -maxdepth 1
ruben.conde@polifemo:~$ cd
ruben.conde@polifemo:~$ chmod 777 prac5/guiones/busca
ruben.conde@polifemo:~$ ./prac5/guiones/busca /home/ruben.conde 10
```

### Ejercicio 4
4. Cree tres nuevos alias en el fichero .profile. Uno se llamará listaf y visualizará la lista de todos los ficheros y directorios a partir de su directorio personal (incluso los que empiezan por punto) así como sus permisos (opción -l).
Otro se llamará gente y contará los usuarios que actualmente se encuentran en el sistema (Se supone que cada fila del comando who es un usuario).
Otro se llamará saludo y visualizará el siguiente mensaje: Hola. Son las <hora> horas y <minuto> minutos del <día de la semana en letras> <día del mes> de <mes> de <año>. Chao.
HAGA QUE TOMEN EFECTO
```bash
alias listaf="ls $(find /home/ruben.conde -type df 2> /dev/null ) -l"
alias gente="who | wc -l"
alias saludo="echo Hola. Son las $(date +%"H") horas y $(date +%"m") minutos del $(date +%"A") $(date +%"d") $(date +%"B") de $(date +%"Y"). Chao"
```

### Ejercicio 5
5. Cree desde aquí, en el directorio guiones, un guión llamado fnuevos que pasándole como parámetro el nombre de un fichero y un directorio indique cuántos ficheros hay a partir del directorio indicado que son más nuevos que el fichero especificado (debe salir un número). Cree otro guion llamado fviejos que pasando los mismos parámetros indique cuántos son más viejos que el fichero especificado.
```bash
find $2 -type f -newer $1 | wc -l
find $2 ! -newer $1 -type f | wc -l
```


### Ejercicio 6
6. Vaya al directorio prac51. Cree un guión llamado trataf en este directorio que para cada fichero que encuentre a partir del directorio pasado como parámetro que termine en .txt lo visualice por pantalla página a página.
Los errores no deben salir por pantalla. Muévase a su directorio personal. Compruebe desde aquí su ejecución pasando como parámetro el directorio /home/so/velez/MI.
```bash
ruben.conde@polifemo:~/prac5/guiones$ cd ../prac51
ruben.conde@polifemo:~/prac5/prac51$ joe trataf
#!/bin/bash
more $(find $1 -name "*.txt" -type f 2> /dev/null)
```


### Ejercicio 7
7. Introduzca en el fichero .profile la modificación realizada a la variable PS1 (en la practica 4), para que el prompt sea nuestro nombre de usuario, seguido de la ruta y del símbolo >. Haga que tome efecto.
```bash
PS1="\u$(pwd)>"
```


### Ejercicio 8
8. Usando el comando cat cree un guión en el directorio guiones llamado copiar al que le pasen como parámetro dos nombres de ficheros y la ruta absoluta a un directorio y copie el fichero especificado en primer lugar en el directorio especificado, con el nombre del fichero especificado en segundo lugar.
```bash

```


### Ejercicio 9
9. Muévase al directorio guiones. Cree un guión llamado vertodo en este
directorio que visualice página a página el contenido de todos los ficheros
(no directorios) que a partir del directorio en el que se encuentra en ese
momento empiecen por s y terminen en .c o .p y sean más nuevos que un
fichero pasado como parámetro. Los posibles errores no deben salir por
pantalla y los ficheros deben ser visualizados por orden alfabético.
```bash
ruben.conde/home/ruben.conde/prac5/prac51>cat > ../guiones/copiar
#!/bin/bash
cp $(find / -name "$1" -type f 2> /dev/null) $3$2
```


### Ejercicio 10
10. Cree en el directorio guiones un guión llamado infor que muestre la
siguiente información:
- Su nombre de usuario
- Su grupo de usuario
- Terminal en el que se encuentra
- Fecha y hora actual del sistema
- Calendario de Marzo de este año
```bash
#!/bin/bash
id -un
id -gn
tty
date
cal 3 2025
```
