# Binary Search vs Linear Search

## **Introducción**
La búsqueda en arrays es una operación fundamental en programación. Existen dos algoritmos principales para buscar elementos en un array: **Linear Search** y **Binary Search**. Cada uno tiene sus ventajas y desventajas dependiendo del caso de uso.

---

## **Linear Search**
### **Descripción**
Linear Search recorre el array elemento por elemento desde el inicio hasta el final, comparando cada elemento con el valor buscado.

### **Características**
- **Requisito del Array**: No necesita que el array esté ordenado.
- **Complejidad Temporal**: O(n), donde *n* es el número de elementos en el array.
- **Ventajas**:
  - Funciona en cualquier array, ordenado o no.
  - Fácil de implementar.
- **Desventajas**:
  - Ineficiente para arrays grandes debido a su complejidad lineal.

### **Cuándo Usar Linear Search**
- Cuando el array no está ordenado.
- Cuando el tamaño del array es pequeño.
- Cuando buscas simplicidad en la implementación.

---

## **Binary Search**
### **Descripción**
Binary Search es un algoritmo eficiente que divide el array en mitades para buscar el elemento deseado. Solo funciona en arrays **ordenados**.

### **Características**
- **Requisito del Array**: El array debe estar ordenado.
- **Complejidad Temporal**: O(log n), donde *n* es el número de elementos en el array.
- **Ventajas**:
  - Mucho más rápido que Linear Search para arrays grandes.
  - Reduce drásticamente el número de comparaciones.
- **Desventajas**:
  - Solo funciona en arrays ordenados.
  - Requiere más lógica en la implementación.

### **Cuándo Usar Binary Search**
- Cuando el array está ordenado.
- Cuando el tamaño del array es grande y necesitas eficiencia.
- Cuando buscas un elemento específico en un conjunto de datos ordenados.

---