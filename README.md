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
	<p>Permite agregar registros con información como número de Socios, apellido y nombre, etc.</p>
</div>
<div>
	<li>Dar de alta un registro, ej: Un Socios.</li>
	<p>Permite agregar un nuevo Socios al archivo existente.</p>
</div>
<div>
	<li>Eliminar un registro lógicamente, ej: Un Socios.</li>
	<p>Permite marcar un Socios como eliminado sin borrarlo físicamente del archivo.</p>
</div>
<div>
	<li>Buscar Socio segun su numero.</li>
	<p>Permite, dado un numero de socio, encantrarlo o no en el archivo.</p>
</div>
<div>
	<li>Crear un listado con los registros del archivo.</li>
	<p>Permite crear una lista de Socios que no fueron dados de baja (Socio dado de baja: socio.num == 0).</p>
</div>

<h3>Implementación</h3>
<p>El proyecto está implementado en lenguaje C y se enfoca en la manipulación de archivos binarios. El programa incluye varias funciones que permiten interactuar con el archivo y gestionar productos en él:</p>

### Modo de apertura

```c
arch = fopen(nomArch, "rb");
arch = fopen(nomArch, "ab");
arch = fopen(nomArch, "rb+");
```
<ul>
    <li><strong>leerSocio</strong>: Modulo que lee los datos de un Socios desde el teclado.</li>
    <li><strong>mostrarSocio</strong>: Modulo que muestra la info de un socio.</li>
	<li><strong>mostrarLista</strong>: Modulo que muestra la lista creada.</li>
	<li><strong>mostrarMenu</strong>: Modulo que muestra las opciones del menu.</li>
	<li><strong>existe</strong>: Modulo que nos que busca en el archivo un socio segun su numero.</li>
	<li><strong>alta</strong>: Modulo que da de alta un socio si no existe.</li>
	<li><strong>baja</strong>: Modulo que da de baja un socio si existe.</li>
	<li><strong>crearNodo</strong>: Modulo que crea el nodo para la lista.</li>
	<li><strong>agregarAdelante</strong>: Modulo que agrega adelante en la lista el nodo creado anteriormente.</li>
	<li><strong>generarLista</strong>: Modulo que genera la lista.</li>
	<li><strong>menu</strong>: Modulo del menu.</li>
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
- Gerardo Henriquez
- Esteban Lisjak

---
