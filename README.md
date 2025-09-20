# Sistema de Gestión y Ordenamiento de Vuelos

## Descripción general del proyecto

El proyecto permite registrar, consultar y organizar (filtrar) la información pertinente sobre un listado de vuelos. Los datos a filtrar son: 
- Id del vuelo.
- Fecha.
- Hora de llegada y salida.
- Precio.
- Aerolínea.
- Origen y destino.
  
Añadido a esto, se tomó una muestra pequeña de 12 vuelos de distintas aerolíneas con el mismo destino (Cuidad de México -> Cancún). Se le permitirá al usuario filtrar los vuelos a este destino por medio del atributo de precio, para encontrar el vuelo que mejor se acomode a sus necesidades.


## SICT0301 Evalúa los componentes

### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
En el sistema, los vuelos se almacenan en un vector y se muestran ordenados por precio mediante std::sort con comparadores estáticos (cmpPrecioAsc/cmpPrecioDesc) dentro del método ordenarPorPrecio.

Algoritmo efectivo: std::sort implementa introsort (quick sort + heap sort + insertion sort).

Complejidad temporal: O(nlogn) en promedio y también en el peor caso a heap sort. El costo extra por copiar el vector antes de ordenar es O(n), por lo que el total sigue dominado por O(nlogn).

Complejidad espacial: O(n) por la copia voluntaria (para no cambiar el estado del vector original).

Estabilidad: std::sort no es estable, si se requiriera preservar orden entre precios iguales, se puede sustituir por std::stable_sort.

Con esto, el ordenamiento cumple los requisitos de rendimiento y simplicidad del proyecto.

### Hace un análisis de complejidad correcto y completo todas las estructuras de datos y cada uno de sus usos en el programa

### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.


## SICT0302 Toma decisiones

### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Se eligió std::sort por rendimiento O(nlogn), robustez y simplicidad ya que evita implementar un sort propio. Se ordena una copia para mostrar sin modificar el estado. Se utilizan omparadores estáticos (cmpPrecioAsc/Desc) compatibles con std::sort, además, es fácil de cambiar el criterio o usar std::stable_sort si se necesita estabilidad.

### Selecciona una estructura de datos adecuada al problema y lo usa correctamente.


## SICT0303 Implementa acciones científicas

### Implementa mecanismos para consultar información de las estructras correctos

### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta


## Consideraciones
El programa solo corre en la consola y esta hecho con c++ standard por lo que corre en todos los sistemas operativos

compilar con: "g++ Vuelo.h Vuelos.h main.cpp"

correr en linux: "/a.out"

correr en windows: "a.exe"


## Referencias a APIs extras para el proyecto.

- std::sort // Ordena el rango (firts, last) en un tiempo de O(n log n). En el proyecto se utiliza con un comparador binario para ordenar de manera ascendente y descendente dependiendo del comparador. cppreference. https://en.cppreference.com/w/cpp/algorithm/sort.html

- static // Se utiliza para poder desarrollar correctamnete el sort en el programa. Al determinarlo como static ya no queda como un metodo que debe ser llamado por un objeto y std::sort puede usarlo correctamente. geeksforgeeks. https://www.geeksforgeeks.org/cpp/static-keyword-cpp/

- pushback() // Se utiiza para agregar un nuevo objeto dentro del vector, al final del mismo. cplusplus. https://cplusplus.com/reference/vector/vector/push_back/





