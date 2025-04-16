<h1 align="center">Manejo de Archivos en C</h1>

<h3>ARCHIVOS</h3>
<p>En este repositorio se encuentran ejemplos y ejercicios sobre el manejo de archivos en el lenguaje C. El programa principal se enfoca en la gestión de productos en un archivo binario, permitiendo realizar operaciones como altas, modificaciones, eliminaciones lógicas y físicas de productos.</p>

<div align="center">
	<img src="https://cdn-icons-png.flaticon.com/512/2338/2338582.png" width="115" height="130" style="margin:auto;">
</div>

<h3>Objetivos</h3>
<p>El objetivo de este proyecto es demostrar cómo se pueden gestionar los datos (registros), permitiendo al usuario realizar diversas operaciones como:</p>
<div>
	<li>Crear un archivo con registros.</li>
	<p>Permite agregar registros con información como número de producto, nombre, cantidad, precio, etc.</p>
</div>
<div>
	<li>Dar de alta un registro, ej: Un producto.</li>
	<p>Permite agregar un nuevo producto al archivo existente.</p>
</div>
<div>
	<li>Modificar un registro, ej: Un producto.</li>
	<p>Permite modificar los datos de un producto previamente ingresado, usando su código único.</p>
</div>
<div>
	<li>Eliminar un registro lógicamente, ej: Un producto.</li>
	<p>Permite marcar un producto como eliminado sin borrarlo físicamente del archivo.</p>
</div>
<div>
	<li>Eliminar un registro fisicamente, ej: Un producto.</li>
	<p>Permite generar un nuevo archivo con los productos no eliminados, eliminando así los productos marcados como dados de baja.</p>
</div>

<h3>Implementación</h3>
<p>El proyecto está implementado en lenguaje C y se enfoca en la manipulación de archivos binarios. El programa incluye varias funciones que permiten interactuar con el archivo y gestionar productos en él:</p>
<ul>
    <li><strong>leerProducto</strong>: Función que lee los datos de un producto desde el teclado.</li>
    <li><strong>crearArchivo</strong>: Crea un archivo binario con productos ingresados por el usuario.</li>
    <li><strong>altaProducto</strong>: Agrega un nuevo producto al archivo.</li>
    <li><strong>modificarProd</strong>: Modifica los datos de un producto con un código específico.</li>
    <li><strong>eliminarProdLog</strong>: Elimina un producto lógicamente (lo marca como eliminado). </li>
    <li><strong>eliminarProdFis</strong>: Elimina físicamente los productos dados de baja al crear un nuevo archivo.</li>
</ul>

### Librerias

```c
#include <stdio.h>
#include <stdlib.h>
```

---

<h4 align="center">TECNOLOGÍAS Y HERRAMIENTAS</h4>
<div align="center">
	<img src="https://www.netgen.co.za/wp-content/uploads/2022/03/C-image-for-Netgen-1024x1024.png" width="115" height="115" style="margin:auto;">
	<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/9/9a/Visual_Studio_Code_1.35_icon.svg/1200px-Visual_Studio_Code_1.35_icon.svg.png" width="115" height="115" style="margin:auto;">
</div>

<h4>AUTOR:</h4>

- Emiliano Fernández

---
