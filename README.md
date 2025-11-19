# Sistema de Gestión y Ordenamiento de Vuelos

## Descripción general del proyecto

El proyecto permite registrar, consultar y organizar (filtrar) la información pertinente sobre un listado de vuelos. Los datos a filtrar son: 
- Id del vuelo.
- Fecha.
- Hora de llegada y salida.
- Precio.
- Aerolínea.
- Origen y destino.
  
Añadido a esto, se tomó una muestra pequeña de 20 vuelos de distintas aerolíneas con el mismo destino (Cuidad de México -> Cancún). Se le permitirá al usuario filtrar los vuelos a este destino por medio del atributo de precio, de forma ascendente o descendente para encontrar el que mejor se acomode a sus necesidades. Se pueden agregar, eliminar y buscar vuelos (por medio de ID).


## SICT0301 Evalúa los componentes

### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

  En el sistema, los vuelos se almacenan en un vector y se muestran ordenados por precio mediante std::sort con comparadores estáticos (cmpPrecioAsc/cmpPrecioDesc) dentro del método ordenarPorPrecio.
  Algoritmo efectivo: std::sort implementa introsort (quick sort + heap sort + insertion sort).
  Complejidad temporal: O(nlogn) en promedio y también en el peor caso a heap sort. El costo extra por copiar el vector antes de ordenar es O(n), por lo que el total sigue dominado por O(nlogn).
  Complejidad espacial: O(n) por la copia voluntaria (para no cambiar el estado del vector original).
  Estabilidad: std::sort no es estable, si se requiriera preservar orden entre precios iguales, se puede sustituir por std::stable_sort.
  Con esto, el ordenamiento cumple los requisitos de rendimiento y simplicidad del proyecto.

### Hace un análisis de complejidad correcto y completo todas las estructuras de datos y cada uno de sus usos en el programa

  - Arbol AVL:
  Se utiliza un árbol AVL para almacenar y mantener ordenados los vuelos por ID y permitir: Búsquedas rápidas de vuelos, Inserciones eficientes, Eliminaciones balanceadas
    Inserción -> se utiliza al cargar los datos del csv con una complejidad de O(log n). Además de insterar nuevos valores.
    Eliminación -> se utiliza al eliminar vuelos del AVL con una complejidad de O(log n).
    Rotaciones -> se utilizan para mantener el AVL estable (no degenerado) con una complejidad de O(1) cada uno.
    Busquedas -> se utiliza para extraer algun valor del AVL con una complejidad de O(log n)
    Espacio -> En cuanto al espacio tenemos una complejidad de O(n) ya que se guarda un nodo por cada vuelo.

  - Vector: 
  Utilizamos el vector para ordenar de manera ascedente y descendente los valores guardados en el AVL.
    Carga -> se insertan los valores del csv de manera secuencial con una complejidad de tiempo O(n).
    Copia -> se genera una copia para ordenar los vuelos, con una complejidad de O(n).

### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.

Carga de CSV: lee línea por línea, convierte los campos y construye objetos Vuelo.
  Complejidad de O(n)

Guardar el CSV: recorre el vector y escribe al archivo.
  Complejidad de O(n)

Mostrar vuelos: Despliega los elementos del vector.
  Complejidad de O(n)

En base a todas las complejidades en nuestro programa, podemos inidcar que este tiene una complejidad final de O(n log n) debido al ordenamineto de los vuelos, aunque la mayoria de estructuras y algoritmos cuenten con una complejidad de O(n) o O(log n).


## SICT0302 Toma decisiones

### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

  Se eligió std::sort por rendimiento O(nlogn), robustez y simplicidad, haciendolo correcto para este problema.
  Se ordena una copia para mostrar sin modificar el estado, ya que actua más como un filtro de datos, al querer regresar al estado original despues de su uso. 
  Se utilizan omparadores estáticos (cmpPrecioAsc/Desc) compatibles con std::sort, para poder filtrar de forma ascendente y descendente los precios de los vuelos, además, es fácil de cambiar el criterio de comparación o usar std::stable_sort si se necesita estabilidad.

### Selecciona una estructura de datos adecuada al problema y lo usa correctamente.
  
  Se eligió como estructura principal un árbol AVL para gestionar el conjunto de vuelos de manera más eficiente cuando se requieren busquedas, inserciones o eliminaciones.
  Además, garantiza tiempos de operación O(log n) en estas acciones, volviendolo lo más eficiente posible.
  Perimite consultas y actualizaciones rápidas sin la necesidad de recorrer todos los valores dentro de nuestro sistema mejorando significativamente el rendimiento. 

## SICT0303 Implementa acciones científicas

### Implementa mecanismos para consultar información de las estructras correctos

  Se implementaron mecanismos para la consulta de la información por medio de metodos de busqueda, inserción y eliminación en la estuctura del árbol AVL, cargado de valores externs presentes en un documento csv. Esta elección responde a la necesidad de realizar consultas rápidas sin la necesidad de recorrer todo el conjunto de datos dentro de nuestra estructura, aportando eficiencia y robustez cumpliendo el criterio de tomar desiciones informadas al seleccionar estructuras adecuadas al problema. 

### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta

  El programa implementa mecanismos de carga de información al realizar la lectura y carga automática del archivo csv, convirtiendo los datos a sus tipos adecuados y generando objetos de tipo vuelo, instertandolos en nuestra estructura y garantizando una carga correcta de datos. Esto se puede visualizar en el metodo cargaCSV() donde se llevan a cabo estas acciones.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta

  El programa ofrece funcionalidad completa de escritura mediante el método guardarCSV() que recorre el vector listaCSV, escribe un archivo CSV válido, sobrescribe el archivo original para mantener consistencia y maneja correctamente la conversión de tipos y el orden del formato. Garantizando que las inserciones y eliminaciones realizadas por el usuario persisten y que los datos guardados siguen un formato estándar reutilizable.

## Consideraciones
El programa solo corre en la consola y esta hecho con c++ standard por lo que corre en todos los sistemas operativos

compilar con: "g++ Vuelo.h Vuelos.h main.cpp"

correr en linux: "/a.out"

correr en windows: "a.exe"

Todos los archivos deben de estar presentes en la misma carpeta o el programa no compilará correctamente. Además, el documento .csv debe de estar cerrado para que los datos se almacenen correctamente (Guardar los datos nuevos).


## Referencias a APIs extras para el proyecto.

- std::sort // Ordena el rango (firts, last) en un tiempo de O(n log n). En el proyecto se utiliza con un comparador binario para ordenar de manera ascendente y descendente dependiendo del comparador. cppreference. https://en.cppreference.com/w/cpp/algorithm/sort.html

- static // Se utiliza para poder desarrollar correctamnete el sort en el programa. Al determinarlo como static ya no queda como un metodo que debe ser llamado por un objeto y std::sort puede usarlo correctamente. geeksforgeeks. https://www.geeksforgeeks.org/cpp/static-keyword-cpp/

- pushback() // Se utiiza para agregar un nuevo objeto dentro del vector, al final del mismo. cplusplus. https://cplusplus.com/reference/vector/vector/push_back/

- std::stoi // Convierte de string a entero. cplusplus. https://cplusplus.com/reference/string/stoi/

- std::stod // Convierte de string a double. cplusplus. https://cplusplus.com/reference/string/stod/

- emplace_back // Insterta un nuevo elemento al final de un  vector, donde el elemento se construye en el lugar con su constructor. cplusplus. https://cplusplus.com/reference/vector/vector/emplace_back/



