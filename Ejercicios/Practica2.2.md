### Ejercicio 1
Muestre por pantalla el texto "Practica 2: Manejo de Shell - Inicio..."
```bash
ruben.conde@polifemo:~$ echo Practica2: Manejo de Shell - Inicio...
```

### Ejercicio 2
Muévase al directorio ~/ModuloI/Practica1/
```bash
ruben.conde@polifemo:~$ cd ModuloI/Practica1/
```

### Ejercicio 3
Cree un directorio, dentro de ModuloI, llamado Practica2. (Se deberá usar una ruta relativa).
```bash
ruben.conde@polifemo:~/ModuloI/Practica1$ mkdir ../Practica2
```

### Ejercicio 4
Haga que los permisos del directorio Practica2 sean 'rwx------'. Se deberá usar la notación numérica. (Se deberá usar una ruta relativa).
```bash
ruben.conde@polifemo:~/ModuloI/Practica1$ chmod 700 ../Practica2
```

### Ejercicio 5
Cree, dentro del directorio Practica2, un fichero llamado solucion2. Dicho fichero deberá contener la solución de la presente práctica.
```bash
ruben.conde@polifemo:~/ModuloI/Practica1$ joe ../Practica2/solucion2.txt
```

### Ejercicio 6
Volviendo a la primera sesión, muévase al directorio Practica2. (Se deberá usar una ruta absoluta)
```bash
ruben.conde@polifemo:~/ModuloI/Practica1$ cd /home/ruben.conde/ModuloI/Practica2
```

### Ejercicio 7
Visualice, con la orden find, todos los directorios (sólo directorios) que cuelguen a partir de /var y cuyo nombre contenga la cadena 'data'.
```bash
ruben.conde@polifemo:~/ModuloI/Practica2$ find /var -type d -name "*data*"
```

### Ejercicio 8
Visualice, con la orden find, todos los ficheros regulares (sólo ficheros) que cuelguen a partir de /etc y cuyo contenido haya sido modificado hace menos de 100 días.
```bash
ruben.conde@polifemo:~/ModuloI/Practica2$ find /etc -type f -mtime -100
```

### Ejercicio 9
Copie el fichero /etc/passwd y el fichero /etc/group al directorio Practica2.
```bash
ruben.conde@polifemo:~/ModuloI/Practica2$ cp /etc/{passwd,group} .
```

### Ejercicio 10
Busque su nombre de usuario en los ficheros passwd y group que acaba de copiar.
```bash
ruben.conde@polifemo:~/ModuloI/Practica2$ grep ruben.conde {passwd,group}
```

### Ejercicio 11
Visualice el número de caracteres del fichero group.
```bash
ruben.conde@polifemo:~/ModuloI/Practica2$ wc -m group
```

### Ejercicio 12
Visualice la longitud de la línea más larga del fichero passwd.
```bash
ruben.conde@polifemo:~/ModuloI/Practica2$ wc -L passwd
```

### Ejercicio 13
Visualice el contenido del fichero group ordenado alfabéticamente en orden inverso.
```bash
ruben.conde@polifemo:~/ModuloI/Practica2$ sort -r group
```

### Ejercicio 14
Visualice las tres primeras líneas del fichero passwd.
```bash
ruben.conde@polifemo:~/ModuloI/Practica2$ head -3 passwd
```

### Ejercicio 15
Visualice las tres últimas líneas del fichero passwd.
```bash
ruben.conde@polifemo:~/ModuloI/Practica2$ tail -3 passwd
```

### Ejercicio 16
Cree en su directorio de usuario un enlace simbólico llamado versos, que apunte al fichero fichcancion.
```bash
# Código aquí
```

### Ejercicio 17
Busque las líneas del fichero "versos" creado anteriormente que comiencen por "Cobi".
```bash
ruben.conde@polifemo:~/ModuloI/Practica2$ grep -i Cobi versos
```

### Ejercicio 18
Visualice los usuarios conectados al sistema, donde aparezca también la línea de cabecera de las columnas.
```bash
ruben.conde@polifemo:~/ModuloI/Practica2$ who -H
```

### Ejercicio 19
Visualice el identificador de su grupo de usuarios.
```bash
ruben.conde@polifemo:~/ModuloI/Practica2$ id -g
```

### Ejercicio 20
Visualice el calendario del mes de enero de 2022.
```bash
ruben.conde@polifemo:~/ModuloI/Practica2$ cal 1 2022
     Enero 2022
do lu ma mi ju vi sá
                   1
 2  3  4  5  6  7  8
 9 10 11 12 13 14 15
16 17 18 19 20 21 22
23 24 25 26 27 28 29
30 31
```

### Ejercicio 21
Visualice la fecha actual con el formato: "Año: 2023, Mes: 02, Dia: 08".
```bash
ruben.conde@polifemo:~/ModuloI/Practica2$ echo "Año: $(date +"%Y"), Mes: $(date +"%m"), Dia: $(date +"%d")"
```

### Ejercicio 22
Visualice el Terminal desde el que está conectado.
```bash
ruben.conde@polifemo:~/ModuloI/Practica2$ tty
/dev/pts/1
```

### Ejercicio 23
Ejecute el monitor del sistema top.
```bash
ruben.conde@polifemo:~/ModuloI/Practica2$ top
```

### Ejercicio 24
Abra una nueva sesión y cámbiese a ella.
```bash
# Código aquí
```

### Ejercicio 25
Mate (enviar la señal 9) el proceso correspondiente a la orden top.
```bash
ruben.conde@polifemo:~$ ps aux
```

### Ejercicio 26
Envíe un mensaje al usuario usuario.destino que desee y que esté conectado con la frase "Práctica 2 a punto de finalizar por <nombre.usuario>".
```bash
ruben.conde@polifemo:~$ kill -9 49549
```

### Ejercicio 27
Deshabilite la llegada de mensajes instantáneos y probar con algún compañero/a.
```bash
ruben.conde@polifemo:~$ mesg n
```

### Ejercicio 28
Muestre en pantalla el mensaje "Práctica 2: Manejo de Shell... Finalizada".
```bash
ruben.conde@polifemo:~$ echo Practica 2: Manejo de Shell... Finalizado
```

### Ejercicio 29
Salga adecuadamente del sistema.
```bash
ruben.conde@polifemo:~$ exit
```
