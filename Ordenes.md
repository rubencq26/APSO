# Ordenes:
## Clase 1
- **pwd** muestra el directorio en el que te encuentras
- **ls** muestra los archivos que hay en la carpeta que te encuentras
- **clear** borra pantalla
- **CTRL + C** aborta
- **passwd** cambia la cntraseña
- insertamos disco con complementos
- sudo apt install bzip2(en la carpeta del disco)
- sudo apt install gcc make perl
- **sftp://172.17.21.248/home/ruben.conde** en el explorador de archivos en linux para trasferencia de archivos a Polifemo
- mkdir nombre crea un directorio ruta relativa
- mkdir /home/ruben.conde/prac1 crea un directorio en ruta absoluta
- **cp /home/ruben.conde/prac1/leon /home/ruben.conde/prueba** copia archivos
- **mv /home/ruben.conde/prac1/leon /home/ruben.conde/prueba** mueve archivos
- **rm -r /** borraria todos los directorios
- **cat fichero** muestra el contenido del fichero
- **more fichero** para visualizar un archivo grande
- **echo hola mundo** saca por pantalla lo que pongas
- **nano /home/ruben.conde/prac1/leon** editor de texto simple
- **joe /home/ruben.conde/prac1/leon** editor de texto mas completo, ctrl + k y luego pulsas h tienes la ayuda, ctrl + k y x sales guardando el fichero, ctrl + k y q sales sin guardar 

## Clase 2
- **ruben.conde@polifemo:~/prac1$ chmod u+w,o-x  p1.txt** cambia los permisos
- ruben.conde@polifemo:~/prac1$ chmod ugo+rwx  p1.txt
- ruben.conde@polifemo:~/prac1$ chmod o-r  p1.txt
- ruben.conde@polifemo:~/prac1$ chmod 744 p1.txt
rwxrwxrwx 111 100 100 744
- ruben.conde@polifemo:~$ find /home/so -name "*.???" busca por nombre del archivo
- ruben.conde@polifemo:~$ find /home/so -type d (f d l) busca ficheros, directorios o enlaces
- ruben.conde@polifemo:~$ find /home/so -mtime +5 busca ficheros modificados hace mas de 5 dias
- -atime +5 accedidos hace mas de 5 dias
- -ctime +5 su estado cambio hace mas de 5 dias
- -mmin +5 modificado hace 5 minutos
- ruben.conde@polifemo:~$ ln prac1/p1.txt enlaceap1.txt crea un hardlink
- ruben.conde@polifemo:~$ ln -s prac1/solp1.txt  enlaceasolp1simbolico.txt crea un softlink
- ruben.conde@polifemo:~$ grep polifemo prac1/solp1.txt hace una busqueda del patron dentro de un fichero
- ruben.conde@polifemo:~$ wc polifemo prac1/solp1.txt  hace un recuento de las coincidencias del patron
- ruben.conde@polifemo:~$ cal 2 2025 muestra el calendario de febrero de 2025
- ruben.conde@polifemo:~$ date te devuelve la fecha y hora
- ruben.conde@polifemo:~$ df tamaño libre en el disco
- ruben.conde@polifemo:~$ sort prac1/solp1.txt ordena alfabeticamente un fichero de texto
- ruben.conde@polifemo:~$ who muestra quien esta conectado
- ruben.conde@polifemo:~$ ps muestra los procesos activos
- ruben.conde@polifemo:~$ tty nombre de la terminal que estoy usando
- ruben.conde@polifemo:~$ id de que grupo soy y a que grupo pertenezco
- ruben.conde@polifemo:~$ top abre como un administrador de tareas
- ruben.conde@polifemo:~$ kill -9  52093 elimina un proceso
- ruben.conde@polifemo:~$ head prac1/solp1.txt muestra las 10 primeras lineas
- ruben.conde@polifemo:~$ tail -n 2 /home/so/velez/MI/solf1.txt muestra las 2 ultimas lineas
- ruben.conde@polifemo:~$ write lucia.zamudio inicia una conexion con otro usuario
- ruben.conde@polifemo:~$ mesg n deniega la entrada de mensajes
- ruben.conde@polifemo:~$ mesg y acepta la entrada de mensajes

## Clase 3
### Redireccion
- Redireccion, en vez de sacar los errores en una pantalla los saca en un fichero **$ orden 2> ./errores.txt**
-  Para sacar la salida normal sin errores tan solo hay que poner **$ orden 1> ./errores.txt**
-  Para sacar la salida normal con y sin errores hay que poner **$ orden &> ./errores.txt**
-  Para que no salga por pantalla los errores **$ orden 2> /dev/null**
-  Para que la redirección no sobrescriba la pantalla sino que la concatene se poner **$ orden >> fichero.txt**
-  Para ejecutar un fichero solo hay que escribir la ruta **$ $ /home/so/ficheros/selecciona**
-  **$ /home/so/ficheros/selecciona < uno.txt** asi en vez de pedir entrada por teclado,solo usa de entrada el contenido del fichero
-  **$ cat >> entrada.txt** forma rapida de añadir texto a un fichero sin editor
### Tuberias
- **ruben.conde@polifemo:~$ who | grep jesus** mete la primera orden en un archivo temporal para ajecutar en el la segunda orden obligatoriamente la segunda orden debe manipular el contenido de un archivo
- **ruben.conde@polifemo:~$ who | grep jesus | wc -l** puedes poner cuantas tuberias quieras
### Sustitucion
- **$ cat $(find ~ -type f -name "*.txt" -mmin -100 2> /dev/null)** ejecuta una orden sobre la salida de otra orden
- **$ rm $(find /home -mmin -60 -user ruben.conde -name "[!.]*" -type f  2> /dev/null)**
### Ejecucion en segundo plano
- **$ orden &** pone en segundo plano lo que ejecutes
- **$ jobs** muestra los procesos activos
- **$ fg 1** pasa el proceso activos a primer plano

  
### Permisos
#### Usuarios
- **u** user/usuario/propietario
- **g** grupo de usuarios al que pertenezaca el propietario
- **o** todos aquellos que no pertenezcan al grupo de usuario
#### Acceso
- **r** read/lectura
- **w** write/escritura
- **x** execution/ejecucion

## Clase 4
- **ruben.conde@polifemo:~$ set -o** muestra las opciones
- **ruben.conde@polifemo:~$ set -o noglob** enciende la opcion que no funcionen los caracteres globales
- **ruben.conde@polifemo:~$ set +o noglob** apaga la opcion noglob
- **ruben.conde@polifemo:~$ set -o verbose** cada comando que se ejecuta se imprime en pantalla
- **ruben.conde@polifemo:~$ set -o xtrace** lo mismo que verbose pero con mas informacion dando la orden ta cual el la ejecuta
- **ruben.conde@polifemo:~$ sh** abre una shell sh
- **ruben.conde@polifemo:~$ csh** abre un nuevo shell csh
- **ruben.conde@polifemo:~$ alias creadir="mkdir"** puedo crear comandos, que hagan otros comandos
- **ruben.conde@polifemo:~$ unalias creadir** borro el alias
- **ruben.conde@polifemo:~$ V1="MENSAJE 1"** crea una variable V1
- **ruben.conde@polifemo:~$ echo $V1** muestra el contenido de una variable
- **ruben.conde@polifemo:~$ unset V1** borra la variable V1
- **ruben.conde@polifemo:~$ which bash** me doice el directorio en el que se encuentra un ejecutable
- **ruben.conde@polifemo:~$ echo $HOME** muestra la rutade tu directorio de usuario
- para cambiar el login hay que modificar el fichero.profile
- para una shell nueca el .bashrc




