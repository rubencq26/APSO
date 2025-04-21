### NOTAS:
1. No nos podemos mover de directorio mientras no se especifique.
2. Si un punto requiere más de una orden, en la solución aparecerán todas las necesarias para llevar a cabo ese punto.
3. La pregunta solo se considerará correcta si usa las rutas relativas o absolutas correctamente.

---

### 1. Crear en vuestro directorio personal un directorio llamado "prac1" con rutas relativas.

```bash
mkdir prac1
```

---

### 2. Copiar el fichero "p1.txt" que se encuentra en `/home/so/velez/MI` en el directorio "prac1" con rutas absolutas.

```bash
cp /home/so/velez/MI/p1.txt /home/ruben.conde/prac1/
```

---

### 3. Abrir una nueva sesión (sesión 2) (nuevo terminal). En esta nueva sesión nos movemos al directorio "prac1" con rutas relativas. Editamos con el "joe" el fichero "p1.txt" mediante rutas absolutas. Desde esta sesión solo podremos modificar el fichero "p1.txt" para ir añadiendo las soluciones a cada pregunta. Las siguientes preguntas se harán desde la primera sesión.

```bash
joe prac1/p1.txt
```

---

### 4. Crear dentro del directorio "prac1", mediante ruta absoluta, el directorio "prac11". Moverse al directorio "prac11" mediante ruta relativa.

```bash
mkdir /home/ruben.conde/prac1/prac11
cd prac1/prac11
```

---

### 5. Crear desde aquí, con un solo comando, y mediante rutas relativas, cuatro directorios que sean hijos de "prac1", llamándolos "prac12", "prac13", "prac14" y "prac15".

```bash
mkdir ../prac12 ../prac13 ../prac14 ../prac15
```

---

### 6. Moveros al directorio raíz con el comando más corto posible. Visualizar desde aquí el contenido del fichero "p1.txt" que habéis copiado en vuestro directorio "prac1" mediante rutas relativas. Moveros al directorio "prac13" mediante ruta relativa. Visualizar desde aquí el fichero "p1.txt" del directorio "prac1" mediante rutas relativas.

```bash
cd /
cat home/ruben.conde/prac1/p1.txt
cd home/ruben.conde/prac1/prac13
cat ../p1.txt
```

---

### 7. Crear mediante rutas absolutas con el "joe" un fichero llamado "prueba13" en el directorio "prac13" cuyo contenido será:

> "Esto es un fichero de prueba perteneciente al usuario (tu nombre de usuario)"

```bash
joe /home/ruben.conde/prac1/prac13/prueba13
```

Crear con el "joe" un fichero llamado "prueba12" en el directorio "prac12" mediante rutas relativas cuyo contenido sea:

> "Esto es un fichero de prueba perteneciente al usuario (tu nombre de usuario)"

```bash
joe ../prac12/prueba12
```

---

### 8. Crea con el comando "joe" un fichero llamado "ejemplo01" en el directorio "prac11", usando rutas relativas, que contenga la frase:

> "Esto es un fichero ejemplo creado con el joe en la práctica 1"

```bash
joe ../prac11/ejemplo01
```

---

### 9. Copiar los ficheros "prueba12" y "prueba13" al directorio "prac11", mediante rutas relativas.

```bash
cp ../prac1[23]/prueba1[23] ../prac11
```

---

### 10. Copiar el fichero "prueba12" del directorio "prac12" al directorio "prac14", mediante rutas relativas, con el nombre "prueba14".

```bash
cp ../prac12/prueba12 ../prac14/prueba14
```

---

### 11. Crear dentro del directorio "prac12" dos directorios llamados "temp1" y "temp2", con rutas relativas.

```bash
mkdir ../prac12/temp1 ../prac12/temp2
```

---

### 12. Moveros al directorio "prac1" con rutas relativas. Mover el fichero "prueba13" del directorio "prac13" al directorio "temp1" con rutas relativas. Copiar los ficheros "prueba12" del directorio "prac12" y "prueba14" del directorio "prac14" al directorio "temp1" con rutas relativas y con un solo comando y sin usar construcciones globales.

```bash
cd ..
mv prac13/prueba13 prac12/temp1
cp prac12/prueba12 prac14/prueba14 prac12/temp1
```

---

### 13. Copiar todos los ficheros del directorio "temp1" que empiecen por "p", el penúltimo carácter sea un "1" y terminen en un número del 1 al 5 al directorio "temp2" utilizando las construcciones globales adecuadas y rutas relativas.

```bash
cp prac12/temp1/p*[1][12345] prac12/temp2/
```

---

### 14. Borrar todos los ficheros del directorio "temp1" cuyo penúltimo carácter sea un número usando construcciones globales y rutas absolutas.

```bash
rm prac12/temp1/*[0123456789]?
```

---

### 15. Borrar el directorio "temp1" con rutas absolutas. Borrar el directorio "temp2" sin borrar previamente los ficheros que hay dentro y con rutas relativas (Se usa el comando "rm" con una opción. Buscar la opción adecuada con la ayuda del comando "man").

```bash
rmdir /home/ruben.conde/prac1/prac12/temp1
rm -r prac12/temp2
```

---

### 16. Nos movemos a nuestro directorio personal con el comando más breve posible. Comprobamos que estamos en nuestro directorio personal con el comando correspondiente.

```bash
cd
pwd
```

---

### 17. Vamos a la sesión en la que tenemos editado el fichero "p1.txt" (sesión 2) con el "joe". Salvamos el fichero con el nombre "solp1.txt". Debe quedar grabado en el directorio "prac1" con el nombre "solp1.txt". Volvemos a la primera sesión.

```bash
# En la sesión 2:
Ctrl + K, D
```

---

### 18. Ejecutamos el comando: "chmod 700 prac1/solp1.txt". Si nos da un error comprobar que el fichero "solp1.txt" tiene el nombre correcto y que se encuentra en el directorio "prac1". Si no da errores, hemos terminado.

```bash
chmod 700 prac1/solp1.txt
```
