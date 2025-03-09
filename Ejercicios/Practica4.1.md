## Ejercicio 1
Cree con un solo comando el siguiente árbol de directorios a partir de su directorio personal.
![imagen](https://github.com/user-attachments/assets/15feb20b-63e2-4e06-966c-3d956d18fd8e)

```bash
ruben.conde@polifemo:~$ mkdir -p prac4/prac41 prac4/prac42/tmp1/tmp2 prac4/prac43

```
---

## Ejercicio 2
Muévase al directorio prac43. Quite todo tipo de permisos para el grupo y el resto de los grupos al directorio prac4, prac42, tmp1 y tmp2 con un sólo comando y usando rutas relativas.
```bash
ruben.conde@polifemo:~$ cd prac4/prac42
ruben.conde@polifemo:~/prac4/prac42$ chmod 700 ~/prac4 ~/prac4/prac4? ~/prac4/prac42/tmp1 ~/prac4/prac42/tmp1/tmp2

```
---

## Ejercicio 3
Muévase al directorio prac42. Cree con el cat un fichero en el directorio tmp1 que se llame prueba y contenga la frase "Este es un fichero de prueba". Añada con el comando cat una nueva frase al fichero sin borrar la anterior que diga "Esta frase se ha añadido después".
```bash
ruben.conde@polifemo:~/prac4/prac42$ cat > tmp1/prueba
Este es un fichero de prueba
ruben.conde@polifemo:~/prac4/prac42$ cat >> tmp1/prueba 
Esta frase se ha añadido despues que la anterior


```
---

## Ejercicio 4
Visualice el contenido de las primeras 52 variables del sistema. Muestre por pantalla el contenido de la variable PATH (sólo esa variable).
```bash
ruben.conde@polifemo:~/prac4/prac42$ set | head -52
ruben.conde@polifemo:~/prac4/prac42$ echo $PATH

```
---

## Ejercicio 5
Cree una variable llamada ORIGEN que contenga la ruta absoluta al directorio /home/so/velez/MI. Cree dos variables llamadas DESTINO1 y DESTINO2 con la ruta absoluta al directorio tmp1 y tmp2 respectivamente del directorio prac42. Visualice el contenido de estas dos variables (sólo de estas dos). Use las variables ORIGEN y DESTINO1 para copiar todos los ficheros del directorio /home/so/velez/MI que contienen una p en su nombre y terminan en .txt al directorio tmp1 de prac42.
```bash
ruben.conde@polifemo:~/prac4/prac42$ ORIGEN=/home/so/velez/MI
ruben.conde@polifemo:~/prac4/prac42$ DESTINO1=/home/ruben.conde/prac4/prac42/tmp1
ruben.conde@polifemo:~/prac4/prac42$ DESTINO2=/home/ruben.conde/prac4/prac42/tmp1/tmp2
ruben.conde@polifemo:~/prac4/prac42$ cp $ORIGEN/p*.txt $DESTINO1
```
---

## Ejercicio 6
Muévase al directorio prac43 con rutas relativas. Cree un alias llamado fnuevos que busque los ficheros (no directorios) a partir de su directorio personal a los que se haya accedido hace menos de 3 horas, empiecen por punto y terminen en e, y o c y visualice su contenido uno a uno.
```bash
ruben.conde@polifemo:~/prac4/prac42$ cd ../prac43
ruben.conde@polifemo:~/prac4/prac43$ alias fnuevos="cat $(find /home/ruben.conde/ -name ".*[eyc]" -amin -180)"

```
---

## Ejercicio 7

Visualice todos los alias del sistema. Cree cinco nuevos alias:
  ```bash
  ruben.conde@polifemo:~/prac4/prac43$ alias
  ```
- Uno se llamará dir y visualizará página a página todos los ficheros del directorio en el que está (incluso los que empiezan por punto), con todos los permisos en orden alfabético.
  ```bash
  ruben.conde@polifemo:~$ alias dir="ls -la | grep "^-rwxrwxrwx" | sort | more"
  ```
- dirinverso hará lo mismo pero saldrán ordenados en orden inverso.
  ```bash
  ruben.conde@polifemo:~$ alias dir="ls -la | grep "^-rwxrwxrwx" | sort -r | more"
  ```
- Otro se llamará fecha y visualizará la fecha con el siguiente formato: "Hoy es <día de la semana>, <día del mes> de <mes> de <año>. Chao".
  ```bash
  ruben.conde@polifemo:~$ alias fecha="echo Hoy es $(date +%"A"), $(date +"%d") de $(date +%"B") de $(date +%"Y"). Chao"
  ```
- El otro se llamará hora y visualizará la hora con el siguiente formato: "Son las <hora> horas y <minuto> minutos. Chao".
  ```bash
  ruben.conde@polifemo:~$ alias hora="echo Son las $(date +%"H") horas y $(date +%"m") minutos. Chao"
  ```
- El último debe conseguir que cuando ejecute cd.. (sin el espacio en blanco entre el cd y los dos puntos) no produzca error.
```bash
ruben.conde@polifemo:~$ alias cd..="cd .."
```
---

## Ejercicio 8
Cree un fichero llamado usuarios en el directorio tmp2 con la lista de todas las sesiones que hay abiertas en este instante ordenadas alfabéticamente. Use rutas relativas.
```bash

```
---

## Ejercicio 9
Muévase al directorio prac4. Ejecute el interprete de comandos ksh. Visualice las variables activas en este interprete de comandos. Modifique el prompt para que visualice la frase "Comando::>".
```bash

```
---

## Ejercicio 10
Salga del interprete de comandos ksh y vuelva al bash. Cuente con la ayuda del who y del wc el número de sesiones que hay abiertas (debe salir un número).
```bash

```
---

## Ejercicio 11
Modifique el prompt principal para que visualice su nombre de usuario en vez del nombre de la máquina. A continuación el directorio donde está mediante ruta absoluta y al final debe aparecer el símbolo ">" (Ejemplo: Para el usuario velez actualmente sale velez@Polifemo:~/prac4$. Después de modificar el prompt debe salir velez: /home/velez/prac4>).
```bash

```
---

## Ejercicio 12
Modifique el prompt secundario para que emita el siguiente mensaje: "cierre las comillas, por favor".
```bash

```
---

## Ejercicio 13
Edite con el joe el fichero .profile. Modifique la variable PATH para que siempre se ejecuten los ficheros que se encuentran en el directorio actual. Añada la variable ORIGEN creada en el apartado 5 para que se pueda usar siempre que entre en una nueva sesión.
```bash

```
---

## Ejercicio 14
Cierre la sesión. Vuelva a entrar. Añada los alias hora y fecha al .profile para que siempre se puedan ejecutar. Haga lo necesario para que los alias introducidos en el .profile se vuelvan activos y puedan ser usados.
```bash

```
---

