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
  
```
9. Visualice el contenido del directorio raíz en formato largo (mostrando los detalles de cada fichero o directorio). Se debe usar una ruta relativa.
  ```bash
  
```
10. Copie los ficheros `soneto` y `cancion`, que están en el directorio `/home/so/ficheros`, al directorio `Practical` con una sola orden. Use rutas relativas.
  ```bash
  
```
11. Muévase al directorio `ModuloI`.
   ```bash
  
```
12. Copie el fichero `soneto` del directorio `Practical` al directorio `Temporal` con el nombre `estrofa`. Use rutas relativas.
  ```bash
  
```
13. Mueva el fichero `cancion` desde el directorio `Practical` al directorio `Datos`.
  ```bash
  
```
14. Visualice el contenido del fichero `estrofa` del directorio `Temporal`.
  ```bash
  
```
15. Cambie el nombre del fichero `soneto` por el de `verso`.
  ```bash
  
```

A partir de aquí se puede cambiar de directorio cada vez que se quiera. Se puede usar también cualquier tipo de ruta.

16. Copie todos los ficheros del directorio `/home/so/ficheros` cuyo nombre comience por `f` al directorio `Datos`.
  ```bash
  
```
17. Ubicados en el directorio `ficheros` anterior, liste detalladamente todos los ficheros:
    a) cuyos nombres terminen con un número.
        ```bash
  
        ```
    b) cuyos nombres no comiencen con ninguna vocal (ni mayúsculas ni minúsculas).
        ```bash
  
        ```
    c) cuyos nombres no comiencen por ningún número.
        ```bash
  
        ```
    d) cuya extensión tenga exactamente 3 caracteres.
      ```bash
  
      ```
    e) cuya extensión tenga más de 3 caracteres.
        ```bash
  
        ```
    f) cuya extensión sea `bak` y el nombre comience por una letra.
        ```bash
  
        ```
19. Borre todos los ficheros del directorio `Datos` cuyo nombre esté compuesto de dos caracteres.
  ```bash
  
```
20. Copie todos los ficheros del directorio `Datos`, cuyo nombre finalice en un número, al directorio `Temporal`.
  ```bash
  
```
21. Visualice, de forma que se pare cada vez que se llene la pantalla, el contenido del fichero `fichaacion`.
  ```bash
  
```
22. Visualice el contenido de su directorio de usuario, incluyendo el contenido de los subdirectorios, en formato largo y ordenados por tamaño de menor a mayor. Use el manual para conocer las opciones necesarias.
  ```bash
  
```
23. Consulte la ayuda de la orden `rm`. ¿Para qué se usa la opción `–r`?
  ```bash
  
```
24. Borre el directorio `Temporal`. Use las órdenes que sean necesarias.
  ```bash
  
```
25. Cree un directorio llamado `tmpfiles` que sea hijo del directorio `Datos`.
  ```bash
  
```
26. En el directorio `tmpfiles`, cree un archivo llamado `file1.txt` usando el editor `joe`.
  ```bash
  
```
27. En el directorio `tmpfiles`, cree un archivo llamado `file2.txt` mediante la orden `cat`.
  ```bash
  
```
28. Muestre por pantalla la conjunción de los ficheros creados anteriormente.
  ```bash
  
```
29. Edite el fichero `file1.txt` con el editor `joe` para almacenar información de al menos 20 líneas.
  ```bash
  
```
30. Muestre la información del fichero anterior, donde cada 5 líneas vaya pausando la salida por pantalla.
  ```bash
  
```
31. En el mismo directorio `tmpfiles`, cree un fichero de la manera que desee y llámelo `file-text.txt`.
  ```bash
  
```
32. ¿Cómo listaría detalladamente los ficheros cuyo nombre contengan un guión?
  ```bash
  
```
33. Acceda con una sola instrucción a su directorio usuario.
  ```bash
  
```
34. Estando en el directorio de trabajo `Datos`, elimine mediante ruta absoluta el fichero `file2.txt` que se ubica dentro del directorio `tmpfiles`.
  ```bash
  
```
35. Mediante ruta relativa, borre el directorio `tmpfiles` haciendo uso de los comandos que necesite.
  ```bash
  
```
36. Limpie la pantalla.
  ```bash
  
```
37. Muestre en pantalla el mensaje “Práctica 1: Manejo de Shell… Finalizada”.
  ```bash
  
```
38. Salga adecuadamente del sistema.
  ```bash
  
```
