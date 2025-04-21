
# Contenido:

- Atributos de ficheros y permisos (chmod)
- find
- grep, wc, cal, date, df, sort
- Creación de enlaces (ln)
- who, ps, tty, id, kill, top, write, mesg, tail, head

# Consejos:

- Use el tabulador para completar las rutas.
- Compruebe el resultado de las órdenes que ejecute.
- Use `man` para obtener ayuda de las distintas órdenes.

# Enunciado:

**NOTAS:**

- Trabajaremos como en la práctica 1. Copiamos este fichero en el directorio `prac2` con el nombre `solp2.txt`. En ese fichero iremos colocando la solución a cada pregunta.
- Hay que intentar solucionar cada pregunta de la forma más eficiente.
- Mientras no se indique, no se puede cambiar de directorio.
- Si un punto requiere más de una orden, en la solución aparecerán todas las necesarias para llevar a cabo ese punto.
- La pregunta sólo se considerará correcta si usa las rutas relativas o absolutas correctamente. Si no se indica, se podrá usar cualquiera.

---

### Ejercicio 1:
Cree con un solo comando el siguiente árbol de directorios a partir de su directorio personal con rutas relativas.
![imagen](https://github.com/user-attachments/assets/5247c25b-ae5f-415e-b678-ca0bf777a84e)

```bash
ruben.conde@polifemo:~$ mkdir -p prac2/prac21/tmp1 prac2/prac22 prac2/prac23/tmp2

```

---

### Ejercicio 2:
Muévase al directorio `prac2`. Copie los ficheros `f1.txt` y `f2.txt` que se encuentran en `/home/so/velez/MI` en el directorio `prac2` usando rutas absolutas para indicar la ruta a los ficheros y ruta relativa para indicar el directorio de destino.

```bash
ruben.conde@polifemo:~/prac2$ cp /home/so/velez/MI/f[12].txt .

```

---

### Ejercicio 3:
Use la adición y sustracción de permisos para dejar al directorio `prac2` sin permiso de lectura y escritura, tanto para el grupo del propietario como para los que no son del grupo del propietario. El propietario debe quedarse con los permisos que ya tenía.

```bash
ruben.conde@polifemo:~/prac2$ chmod go-rw .

```

---

### Ejercicio 4:
Usando el método de colocación de permisos global, haga que los ficheros `f1.txt` y `f2.txt` tengan todos los permisos para el propietario, permiso de lectura para los usuarios del grupo del propietario y ningún permiso para los usuarios que no son del grupo del propietario.

```bash
ruben.conde@polifemo:~/prac2$ chmod 740 f[12].txt

```

---

### Ejercicio 5:
Muévase al directorio `prac21` mediante rutas absolutas. Mediante rutas relativas haga una copia de los ficheros `f1.txt` y `f2.txt` en el directorio `tmp1`. Renombre el fichero `f1.txt` del directorio `tmp1` a `f21.txt` con rutas relativas.

```bash
ruben.conde@polifemo:~/prac2$ cd /home/ruben.conde/prac2/prac21
ruben.conde@polifemo:~/prac2/prac21$ cp ../f[12].txt tmp1/
ruben.conde@polifemo:~/prac2/prac21$ mv tmp1/f1.txt  tmp1/f21.txt

```

---

### Ejercicio 6:
Mueva y renombre el fichero `f2.txt` del directorio `tmp1` al directorio `tmp2` con el nombre `f23.txt` usando rutas relativas y en un solo comando.

```bash
ruben.conde@polifemo:~/prac2/prac21$ mv tmp1/f2.txt ../prac23/tmp2/f23.txt
```

---

### Ejercicio 7:
Muévase con un solo comando al directorio `tmp2` sin usar rutas absolutas. Busque con el comando `find` los directorios que cuelgan de su directorio personal cuyo segundo carácter sea una `r` o una `t` (tanto en mayúsculas como en minúsculas), su penúltimo carácter no sea un número y su último carácter sea un número.

```bash
ruben.conde@polifemo:~/prac2/prac21$ cd ../prac23/tmp2/
ruben.conde@polifemo:~/prac2/prac23/tmp2$ find /home/ruben.conde/ -name ?[rtRT]*[^1234567890][1234567890] -type d
```

---

### Ejercicio 8:
Busque los ficheros que no sean directorios (pueden ser de cualquier otro tipo) y que cuelguen de su directorio personal, que sean más nuevos que el fichero `solpl.txt` que se encuentra en su directorio `prac1` y que hayan sido modificados hace menos de 3 días. Use rutas absolutas en todo momento.

```bash
ruben.conde@polifemo:~/prac2/prac23/tmp2$ find /home/ruben.conde/ -type f -newer /home/ruben.conde/prac1/solp1.txt  -mtime -3
```

---

### Ejercicio 9:
Consulte con el comando `grep` dónde aparecen en los ficheros `f1.txt` y `f2.txt` del directorio `prac2` los caracteres "llama", sea en mayúscula o en minúscula (con un solo comando). Debe aparecer 5 veces en `f1.txt` y 6 veces en `f2.txt` para estar correcto.

```bash
ruben.conde@polifemo:~/prac2/prac23/tmp2$ grep -i "llama" /home/ruben.conde/prac2/f[12].txt
```

---

### Ejercicio 10:
¿Cuántos bytes ocupa el fichero `f21.txt`? Indique dos comandos distintos con los que pueda averiguar el tamaño en bytes de un fichero.

```bash
ruben.conde@polifemo:~/prac2/prac23/tmp2$ wc -c /home/ruben.conde/prac2/prac21/tmp1/f21.txt
1499 /home/ruben.conde/prac2/prac21/tmp1/f21.txt

ruben.conde@polifemo:~/prac2/prac23/tmp2$ ls -l /home/ruben.conde/prac2/prac21/tmp1/f21.txt
-rwxr----- 1 ruben.conde users 1499 feb 27 12:04 /home/ruben.conde/prac2/prac21/tmp1/f21.txt
```

---

### Ejercicio 11:
Consulte en qué día de la semana se fundó la Universidad de Huelva (1 de Julio de 1993) con el comando `cal`. (Nota: consulte sólo el mes y averigüe el día de la semana que es).

```bash
ruben.conde@polifemo:~/prac2/prac23/tmp2$ cal 7 1993
     Julio 1993
do lu ma mi ju vi sá
             1  2  3
 4  5  6  7  8  9 10
11 12 13 14 15 16 17
18 19 20 21 22 23 24
25 26 27 28 29 30 31
```

---

### Ejercicio 12:
Muestre la hora y fecha con el siguiente formato:

```
Bienvenido. Son las <hora> horas y <minuto> minutos del <día de la semana en letras> <día del mes> de <mes en letras>.
Ha sido un placer.
```

```bash
ruben.conde@polifemo:~/prac2/prac23/tmp2$ echo "Bienvenido. Son las $(date +"%H") horas y $(date +"%M") minutos del $(date +"%A") $(date +"%d") de $(date +"%B"). Ha sido un placer"
Bienvenido. Son las 14 horas y 55 minutos del lunes 03 de marzo. Ha sido un placer
```

---

### Ejercicio 13:
Muévase a su directorio personal. Ordene el fichero `usuarios04-05.txt` que se encuentra en el directorio `/home/so/velez/MI` de menor a mayor y guarde el fichero resultante en el directorio `prac22` con el nombre `usu.orden.pabajo`. Haga lo mismo pero ordenando de mayor a menor y guarde el resultado en el directorio `prac22` con el nombre `usu.orden.parriba`.

```bash
ruben.conde@polifemo:~$ sort /home/so/velez/MI/usuarios04-05.txt > prac2/prac22/usu.orden.pabajo
ruben.conde@polifemo:~$ sort -r /home/so/velez/MI/usuarios04-05.txt > prac2/prac22/usu.orden.parriba
```

---

### Ejercicio 14:
Visualice el fichero `fi.txt`. Visualice las 2 últimas líneas del fichero `solf1.txt` que se encuentra en el directorio `/home/so/velez/MI` para ver la solución al enigma.

```bash
ruben.conde@polifemo:~$ cat /home/so/velez/MI/f1.txt
ruben.conde@polifemo:~$ tail -n 2 /home/so/velez/MI/solf1.txt
```

---

### Ejercicio 15:
Muévase al directorio `prac2`. Visualice el número de caracteres del fichero `f23.txt` del directorio `tmp2`.

```bash
ruben.conde@polifemo:~/prac2$ wc -m prac23/tmp2/f23.txt
8384 prac23/tmp2/f23.txt
```

---

### Ejercicio 16:
Cree un enlace (hard link) llamado `solucionprac1` en el directorio `prac2` que se corresponda con el fichero `solp1.txt` del directorio `prac1`.

```bash
ruben.conde@polifemo:~/prac2$ ln ../prac1/solp1.txt solucionprac1
```

---

### Ejercicio 17:
Cree un enlace simbólico (soft link) llamado `temporal` en el directorio `prac2` que apunte al directorio `tmp2` del directorio `prac23`.

```bash
ruben.conde@polifemo:~/prac2$ ln -s prac23/tmp2/ temporal
```

---

### Ejercicio 18:
Usando el comando `file`, averigüe de qué tipo son los ficheros `solucionprac1` y `temporal`.

```bash
ruben.conde@polifemo:~/prac2$ file solucionprac1
solucionprac1: UTF-8 Unicode text, with CRLF, LF line terminators

ruben.conde@polifemo:~/prac2$ file temporal
temporal: symbolic link to prac23/tmp2/
```

---

### Ejercicio 19:
Usando el comando `who`, visualice sólo los nombres de todas las sesiones que hay actualmente abiertas en el sistema, y el número de sesiones abiertas. Se necesita una opción.

```bash
ruben.conde@polifemo:~/prac2$ who -q
alejandro.hurtado1 natalia.canela ruben.conde oscar.ortega santiago.moreno1 pedro.pontiga714 pedro.pontiga714 lucia.zamudio natalia.canela adrian.colino adrian.colino adrian.colino elisamaria.munoz
# users=13
```

---

### Ejercicio 20:
Abra una nueva sesión. Edite con el editor `joe` un fichero con el nombre `inservible`. Averigüe con el comando `ps` el identificador del proceso `joe`. Mate al proceso `joe` con el comando `kill`.

```bash
ruben.conde@polifemo:~/prac2$ ps aux | grep joe
ruben.conde@polifemo:~/prac2$ kill -9 60048
```

---

### Ejercicio 21:
Escriba un mensaje con el comando `write` al usuario `velez` que tiene la sesión abierta a una hora más temprana.

```bash
ruben.conde@polifemo:~/prac2$ write velez
```

---

### Ejercicio 22:
Deje todos los permisos menos el de ejecución al fichero `solp2.txt` y quite el resto de los permisos para todos los que no son de su grupo sobre ese fichero.

```bash
# Escribe aquí la solución al ejercicio 22
```
```
