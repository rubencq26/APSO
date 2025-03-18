## Ejercicios

### Ejercicio 1
Muestre por pantalla el texto:  
**"Practica 6: Scripts (Estructuras de Control) – Inicio…"**
```bash
ruben.conde@polifemo:~$ echo "Practica 6: Scripts (Estructuras de Control) – Inicio…"
```

### Ejercicio 2
Cree un directorio llamado **Practica6** dentro de **ModuloI** y sitúese en él.
```bash
ruben.conde@polifemo:~$ mkdir -p ModuloI/Practica6
ruben.conde@polifemo:~$ cd ModuloI/Practica6
```

### Ejercicio 3
En el directorio **Practica6**, cree un script llamado **miron** que tome un único parámetro y realice las siguientes acciones:
- Si no se pasa un parámetro, mostrará un mensaje de error y finalizará.
- Si el parámetro es un **directorio**, mostrará su contenido con `ls -la` (eliminando errores de salida).
- Si es un **enlace simbólico**, mostrará la ruta al fichero original y su contenido con `cat`.
- Si es un **fichero ordinario**, mostrará su contenido con `more`.
- Si no es ninguno de los anteriores, mostrará un mensaje de error con el valor del parámetro.
```bash
#!/bin/bash
if [ $# != 1 ]
then
        echo "Error de parametros"
elif [ -d $1 ]
then
        ls -la $1
elif [ -L $1 ]
then
        readlink -f $1
        cat $1
elif [ -f $1 ]
then
        more $1
else
        echo error $1
fi
```

### Ejercicio 4
Cree un script llamado **nprimeros.sh** que tome dos parámetros:  
- Un **directorio** y un **número**.  
- Si el primer parámetro no es un directorio, mostrará un mensaje de error y finalizará.  
- Si es un directorio válido, mostrará los **n primeros ficheros** del listado con el mensaje:  
  **"El nombre del fichero i es <<nombre del fichero>>"**  
  donde `i` representa el orden del fichero en el listado.  
```bash
 #!/bin/bash

 # Verifica que el primer argumento sea un directorio
 if [ ! -d "$1" ]; then
    echo "Error: El argumento no es un directorio."
    exit 1
 fi

 contador=1

 # Recorre los archivos en el directorio
 for i in "$1"/*; do
     echo "El nombre del fichero $contador es $(basename "$i")"

    if [ "$contador" -eq "$2" ]; then
        break  # Salir del bucle cuando se alcance el número indicado
    fi

    contador=$((contador + 1))  # Sumar correctamente
  done
```

### Ejercicio 5
Cree los directorios **largos** y **cortos** dentro de **Practica6**.
```bash

```

### Ejercicio 6
Cree un script llamado **selector.sh** que tome una secuencia de parámetros.  
- Para cada parámetro, comprobará si es un **fichero del directorio de trabajo**.
  - Si su nombre tiene **más de 6 caracteres**, lo copiará al directorio **largos**.
  - Si su nombre tiene **6 caracteres o menos**, lo copiará al directorio **cortos**.  
- **Notas:**  
  - Se debe usar un `case` dentro de un bucle `for`.
  - Analizar el comportamiento con enlaces simbólicos a ficheros de texto.
```bash

```

### Ejercicio 7
Cree un script llamado **replica.sh** que tome un parámetro y haga lo siguiente:
- Si no se pasa un parámetro, mostrará un mensaje de error y finalizará.
- Si hay parámetro, pedirá un número entre **2 y 9**.
  - Si el número es menor que 2, se tomará como **2**.
  - Si el número es mayor que 9, se tomará como **9**.
- Creará **tantos directorios anidados con el nombre del parámetro** como indique el número ingresado.  
  **Ejemplo:** Si se ejecuta `replica p1` y se ingresa `3`, se creará la estructura:
```bash

```


### Ejercicio 8
Cree un script llamado **verdire.sh** que muestre continuamente el contenido de un directorio.  
- Si recibe un **parámetro válido** (directorio), mostrará su contenido cada segundo.  
- Si el parámetro **no es válido**, mostrará un mensaje de error y finalizará.  
- Si no se recibe parámetro, mostrará el contenido del **directorio de trabajo**.  
- **Este script no finalizará automáticamente**, deberá ser interrumpido con `CTRL+C`.
```bash

```
### Ejercicio 9
Cree un script llamado **reubicadoSelectivo.sh** que funcione de la siguiente manera:
- Si no recibe **exactamente dos parámetros**, mostrará:  
**"Número de parámetros incorrecto, se esperaban 2"** y saldrá con código de estado `11`.
- Si los dos parámetros **no son directorios válidos**, mostrará:  
**"Los parámetros deben ser directorios válidos"** y saldrá con código de estado `21`.
- Pedirá al usuario que introduzca un **carácter o número**.
- Para cada fichero en el **primer directorio** que empiece con ese carácter/número:
- Se mostrará su **nombre** y sus **3 últimas líneas**.
- Se preguntará si se quiere mover (`s` para sí).
- Si se mueve, se colocará en el **segundo directorio**.
- Al final, se informará de cuántos ficheros fueron movidos.
```bash

```
### Ejercicio 10
Cree un script llamado **controlBucle.sh** que pruebe `break` y `continue` en los bucles `for`, `while` y `until`:
- Recibirá un parámetro que indique el tipo de bucle (`for`, `while` o `until`).
- En un bucle del **1 al 10**:
- No mostrará el número **6** (saltará con `continue`).
- En la **penúltima iteración**, saltará directamente al final del bucle con `break`.
```bash

```
### Ejercicio 11
Muestre por pantalla el mensaje:  
**"Práctica 6: Scripts (Estructuras de Control) … Finalizada"**
```bash

```
### Ejercicio 12
Salga adecuadamente del sistema.
```bash

```
