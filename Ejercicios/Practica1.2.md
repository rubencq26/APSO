# Contenido:

- `cd`, `mkdir`, `rmdir`, `pwd`
- `ls`, `cp`, `mv`, `rm`, `cat`, `more`, `echo`
- Construcciones globales (`*`, `?`, `[1]`)
- Edición de ficheros (`joe`)
- Rutas Relativas y absolutas

# Consejos:

- Use el tabulador para completar las rutas.
- Compruebe el resultado de las órdenes que ejecute.
- Use `man` para obtener ayuda de las distintas órdenes.

# Enunciado:

**NOTAS:**

Antes de comenzar a realizar la práctica será indispensable haber cambiado la clave de acceso a Polifemo (orden: `passwd`).

Mientras no se indique, no se puede cambiar de directorio.

Será necesario usar los tipos de ruta que se indican en cada orden. Si no se indica ninguno, se podrá usar cualquiera.

1. Muestre por pantalla el texto “Practica 1: Manejo de Shell – Inicio…”
  ```shell
  ruben.conde@polifemo:~$ echo Practica 1: Manejo de Shell – Inicio…
```
2. Visualice la ruta de su directorio de trabajo (directorio en el que se encuentra).
  ```bash
    ruben.conde@polifemo:~$ pwd
```
3. Visualice el contenido de su directorio de trabajo en formato largo (mostrando los detalles de cada fichero o directorio).
  ```bash
  ruben.conde@polifemo:~$ ls -l
```
4. Cree un directorio que sea hijo de su directorio de usuario con el nombre `ModuloI`. (Atienda el uso de mayúsculas y minúsculas).
  ```bash
  ruben.conde@polifemo:~$ mkdir ModuloI
```
5. Cree dentro de `ModuloI` un directorio llamado `Practical`. Use una ruta absoluta.
  ```bash
  ruben.conde@polifemo:~$ mkdir /home/ruben.conde/ModuloI/Practica1
```
6. Muévase al directorio `Practical`. Se debe usar una ruta relativa.
  ```bash
  ruben.conde@polifemo:~$ cd ModuloI/Practica1/
```
7. Dentro del directorio `Practical`, cree la siguiente estructura de directorios. Se deben usar rutas absolutas. (Consulte en el `man` la opción `-p` de `mkdir`).


   ![image](https://github.com/user-attachments/assets/d5d333e1-2f08-4fcd-9ef6-643d4eda21b5)

  ```bash
  ruben.conde@polifemo:~/ModuloI/Practica1$ mkdir -p Datos/{Temporal,basura}
```
8. Visualice el contenido de su directorio de trabajo en formato largo (mostrando los detalles de cada fichero o directorio). Se debe usar una ruta absoluta.
  ```bash
  ruben.conde@polifemo:~/ModuloI/Practica1$ ls -la /home/ruben.conde/ModuloI/Practica1/
```
9. Visualice el contenido del directorio raíz en formato largo (mostrando los detalles de cada fichero o directorio). Se debe usar una ruta relativa.
  ```bash
  ruben.conde@polifemo:~/ModuloI/Practica1$ ls -la /
```
10. Copie los ficheros `soneto` y `cancion`, que están en el directorio `/home/so/ficheros`, al directorio `Practical` con una sola orden. Use rutas relativas.
  ```bash
  ruben.conde@polifemo:~/ModuloI/Practica1$ cp ../../../so/ficheros/{soneto,cancion} .
```
11. Muévase al directorio `ModuloI`.
   ```bash
  ruben.conde@polifemo:~/ModuloI/Practica1$ cd ..
```
12. Copie el fichero `soneto` del directorio `Practical` al directorio `Temporal` con el nombre `estrofa`. Use rutas relativas.
  ```bash
  ruben.conde@polifemo:~/ModuloI$ cp Practica1/soneto Practica1/Datos/Temporal/estrofa
```
13. Mueva el fichero `cancion` desde el directorio `Practical` al directorio `Datos`.
  ```bash
  ruben.conde@polifemo:~/ModuloI$ mv Practica1/cancion Practica1/Datos/
```
14. Visualice el contenido del fichero `estrofa` del directorio `Temporal`.
  ```bash
  ruben.conde@polifemo:~/ModuloI$ cat Practica1/Datos/Temporal/estrofa
```
15. Cambie el nombre del fichero `soneto` por el de `verso`.
  ```bash
  ruben.conde@polifemo:~/ModuloI$ mv Practica1/soneto Practica1/verso
```

A partir de aquí se puede cambiar de directorio cada vez que se quiera. Se puede usar también cualquier tipo de ruta.

16. Copie todos los ficheros del directorio `/home/so/ficheros` cuyo nombre comience por `f` al directorio `Datos`.
  ```bash
  ruben.conde@polifemo:~/ModuloI$ cp /home/so/ficheros/f* Practica1/Datos/
```
17. Ubicados en el directorio `ficheros` anterior, liste detalladamente todos los ficheros:
    a) cuyos nombres terminen con un número.
        ```bash
          ruben.conde@polifemo:/home/so/ficheros$ ls *[0123456789]
        ```
    b) cuyos nombres no comiencen con ninguna vocal (ni mayúsculas ni minúsculas).
        ```bash
        ruben.conde@polifemo:/home/so/ficheros$ ls [^aeiouAEIOU]*
        ```
    c) cuyos nombres no comiencen por ningún número.
        ```bash
        ruben.conde@polifemo:/home/so/ficheros$ ls [^0123456789]*
        ```
    d) cuya extensión tenga exactamente 3 caracteres.
      ```bash
        ruben.conde@polifemo:/home/so/ficheros$ ls *.???
      ```
    e) cuya extensión tenga más de 3 caracteres.
        ```bash
          ruben.conde@polifemo:/home/so/ficheros$ ls *.????*
        ```
    f) cuya extensión sea `bak` y el nombre comience por una letra.
        ```bash
          ruben.conde@polifemo:/home/so/ficheros$ ls [^0123456789]*.bak
        ```
19. Borre todos los ficheros del directorio `Datos` cuyo nombre esté compuesto de dos caracteres.
  ```bash
  ruben.conde@polifemo:~/ModuloI/Practica1/Datos$ rm ??
```
20. Copie todos los ficheros del directorio `Datos`, cuyo nombre finalice en un número, al directorio `Temporal`.
  ```bash
  ruben.conde@polifemo:~/ModuloI/Practica1/Datos$ cp *[0123456789] Temporal/
```
21. Visualice, de forma que se pare cada vez que se llene la pantalla, el contenido del fichero `fichcacion`.
  ```bash
  ruben.conde@polifemo:/home/so/ficheros$ more fichcancion
```
22. Visualice el contenido de su directorio de usuario, incluyendo el contenido de los subdirectorios, en formato largo y ordenados por tamaño de menor a mayor. Use el manual para conocer las opciones necesarias.
  ```bash
  ruben.conde@polifemo:~$ ls -lR
```
23. Consulte la ayuda de la orden `rm`. ¿Para qué se usa la opción `–r`?
  ```bash
  ruben.conde@polifemo:~$ man rm
   -r, -R, --recursive
              borra los contenidos de los directorios recursivamente
```
24. Borre el directorio `Temporal`. Use las órdenes que sean necesarias.
  ```bash
  ruben.conde@polifemo:~$ rm -r ModuloI/Practica1/Datos/Temporal
```
25. Cree un directorio llamado `tmpfiles` que sea hijo del directorio `Datos`.
  ```bash
  ruben.conde@polifemo:~/ModuloI/Practica1/Datos$ mkdir tmpfiles
```
26. En el directorio `tmpfiles`, cree un archivo llamado `file1.txt` usando el editor `joe`.
  ```bash
ruben.conde@polifemo:~/ModuloI/Practica1/Datos/tmpfiles$ joe file1.txt
```
27. En el directorio `tmpfiles`, cree un archivo llamado `file2.txt` mediante la orden `cat`.
  ```bash
  ruben.conde@polifemo:~/ModuloI/Practica1/Datos/tmpfiles$ cat > file2.txt
hola mundo
file2

ctrl + D
```
28. Muestre por pantalla la conjunción de los ficheros creados anteriormente.
  ```bash
  ruben.conde@polifemo:~/ModuloI/Practica1/Datos/tmpfiles$ cat file1.txt file2.txt
```
29. Edite el fichero `file1.txt` con el editor `joe` para almacenar información de al menos 20 líneas.
  ```bash
  ruben.conde@polifemo:~/ModuloI/Practica1/Datos/tmpfiles$ joe file1.txt

^K  IW   file1.txt (Modified)                                                                                                                                                                    Row 21   Col 5
Línea 1: Este es un ejemplo de texto.
Línea 2: Estoy usando el editor joe.
Línea 3: Puedo escribir varias líneas.
Línea 4: Este es un archivo de prueba.
Línea 5: Continuando con más líneas.
Línea 6: Línea número seis.
Línea 7: Sigo escribiendo.
Línea 8: Otra línea más.
Línea 9: Casi llegando a la línea 10.
Línea 10: ¡Mitad del camino!
Línea 11: Continuando después de la línea 10.
Línea 12: Más contenido.
Línea 13: Línea número trece.
Línea 14: Casi terminando.
Línea 15: Últimas líneas.
Línea 16: Línea dieciséis.
Línea 17: Casi listo.
Línea 18: Penúltima línea.
Línea 19: Una más.
Línea 20: ¡Última línea!
fin
```
30. Muestre la información del fichero anterior, donde cada 5 líneas vaya pausando la salida por pantalla.
  ```bash
  ruben.conde@polifemo:~/ModuloI/Practica1/Datos/tmpfiles$ more -5 file1.txt
```
31. En el mismo directorio `tmpfiles`, cree un fichero de la manera que desee y llámelo `file-text.txt`.
  ```bash
  ruben.conde@polifemo:~/ModuloI/Practica1/Datos/tmpfiles$ cat > file-text.txt
```
32. ¿Cómo listaría detalladamente los ficheros cuyo nombre contengan un guión?
  ```bash
  ruben.conde@polifemo:~/ModuloI/Practica1/Datos/tmpfiles$ ls -l *-*
```
33. Acceda con una sola instrucción a su directorio usuario.
  ```bash
  ruben.conde@polifemo:~$ cd
```
34. Estando en el directorio de trabajo `Datos`, elimine mediante ruta absoluta el fichero `file2.txt` que se ubica dentro del directorio `tmpfiles`.
  ```bash
  ruben.conde@polifemo:~/ModuloI/Practica1/Datos$ rm /home/ruben.conde/ModuloI/Practica1/Datos/tmpfiles/file2.txt
```
35. Mediante ruta relativa, borre el directorio `tmpfiles` haciendo uso de los comandos que necesite.
  ```bash
  ruben.conde@polifemo:~/ModuloI/Practica1/Datos$ rm -r tmpfiles/
```
36. Limpie la pantalla.
  ```bash
  ruben.conde@polifemo:~/ModuloI/Practica1/Datos$ clear
```
37. Muestre en pantalla el mensaje “Práctica 1: Manejo de Shell… Finalizada”.
  ```bash
  ruben.conde@polifemo:~$ echo Practica 1: Manejo de Shell... Finalizada
Practica 1: Manejo de Shell... Finalizada
```
38. Salga adecuadamente del sistema.
  ```bash
ruben.conde@polifemo:~$ exit
```
