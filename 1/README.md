# Primer artefacto
### Reutilización del código

El código presente en [Artefacto1.c](https://github.com/dagalemiri/diseno-detallado-de-software/blob/master/artefactos/Primer%20artefacto/Artefacto1.c) corresponde a parte de una tarea desarrollada por mi en el ramo Estructura de Datos y Algoritmos, esta función verifica la morfología que tiene una celda en un mapa. La implementación tiene 170 lineas de las cuales la mayoría corresponden a control de flujo, se puede apreciar a simple vista que existen algunos problemas con este método. Dentro de estos problemas se pueden identificar Code Smells como "Duplicated Code" y "Long Method", los cuales afectan en la calidad interna del código. Según lo visto en clases un método no debería tener más de 10 lineas, por lo que tener un método con 170 lineas es un problema que debe ser solucionado.


Analizando el código se puede notar que la siguiente forma de bloque se repite cuatro veces:

```C
if (row == 0)
{
  needed_grass++;
}
else if (map->table[row-1][column].id == 0)
{

}
else
{
  if (map->table[row-1][column].down == 1)
  {
    needed_grass++;
  }
  else if (map->table[row-1][column].down == 2)
  {
    needed_road++;
  }
  else if (map->table[row-1][column].down == 3)
  {
    needed_castle++;
  }
}
```

La siguiente forma de bloque también se repite cuatro veces:

```C
if (cell.up == 1)
{
  real_grass++;
}
else if (cell.up == 2)
{
  real_road++;
}
else if (cell.up == 3)
{
  real_castle++;
}
```

Al realizar este dignóstico, se puede afirmar que la función puede ser reescrita de modo de disminuir la cantidad de lineas. Para llevar esto a cabo se puede dividir esta función en tres, donde una de ellas continuará llamandose como la función original (structure_verification) y las otras dos corresponderán a los bloques que se repiten. Al realizar este ajuste en el diseño de la función ya no existirá repetición de código, esto debido a que se llamará a las nuevas funciones cada vez que se necesite usar esa estructura de control de flujo. Hacer este cambio no solo disminuye la cantidad de lineas de código, si no que lo hace más mantenible, entendible y reutilizable.

Por otro lado, otro problema que está presente en el código es la falta de abstracción. Ayudaría significativamente al entendimiento y reutilización si el código fuera más abstracto; por ejemplo la linea
```c
if(map->table[row-1][column].down == 1)
```
no deja claro que significa que el valor de "down" sea igual a 1. Además, tampoco está claro para que sirven cada uno de los bloques de código if/else que se repiten.

El análisis hecho en este artefacto muestra como aplicar conceptos de abstracción, acoplamiento y cohesión pueden mejorar la calidad del código. Es importante no solo generar códigos funcionales, si no también bien diseñados.
