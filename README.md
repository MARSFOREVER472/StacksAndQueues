# StacksAndQueues

_Antes de comenzar..._

## Qué son las pilas y filas en C++?

### Pila

_Una pila es una estructura lineal en la que los elementos pueden ser añadidos o 
eliminados solo por el final y una cola es una lista lineal en la que los elementos 
solo pueden ser añadidos por un extremo y eliminados por el otro._

_Las pilas se pueden representar en la memoria de la computadora de varias 
formas, una de ellas es a través de una lista enlazada en la cual cada 
componente apunta a su predecesor excepto el primer componente que 
apuntará a Nil para indicar el final de la lista._

**Esta forma de representación puede ser caracterizada por:**
```
Type
Pila = ^Lista;
Lista = Record
Elemento : Tipo de dato;
Predecesor : Pila;
end;
```
_...en donde "Pila" es la variable puntero, "Lista" es la variable referenciada y "Tipo de dato" es 
el tipo de dato que corresponde a la información que se desea almacenar._

_La pila se formará creando cada nuevo componente y enlazándolo después a su 
predecesor._

**Las operaciones de inserción y extracción de elementos en la pila pueden 
definirse entonces por:**
```
Procedure Insertar (Var Ultimo : Pila; Informacion : Tipo de dato);

Var

Nuevo : Pila;

begin

New (Nuevo);

Nuevo.Elemento := Informacion;

Nuevo.Predecesor := Ultimo;

Ultimo := Nuevo;

end;


Procedure Extraer (Var Ultimo : Pila; Var Informacion : Tipo de dato);

begin

If Ultimo <> Nil Then

begin

Informacion := Ultimo.Elemento;

Ultimo := Ultimo.Predecesor;

end

end;
```

- _Antes de usarlos se debe declarar dos variables: una de tipo "Pila" y la otra de 
tipo "Tipo de dato" para almacenar en ellas los valores que devuelven los 
procedimientos en las variables "Ultimo" e "Información"._
- _Inicialice la variable de tipo "Pila" a "Nil"._

_Esta forma de representación de las pilas mediante lista enlazadas es muy útil 
cuando es necesario indicar el orden de procesamiento de los datos y no se 
conoce la cantidad de elementos a procesar ya que a través de ella es posible 
crear y destruir variables dinámicamente._


### Cola

_Es una lista lineal en la que los elementos solo pueden ser añadidos por un extremo y eliminados por el otro._

_Para las colas se utilizan las mismas representaciones que para las pilas, solamente se añade un apuntador al último elemento._

**Esta forma de representación puede ser caracterizada por:**

```
Type

Cola = ^Lista;

Lista = Record

Elemento : Tipo de dato;

Proximo : Cola;

end;

Punteros = Record

Inicio : Cola;

Fin : Cola;

end;
```

_En la formación de la cola cada nuevo componente que se cree será el último 
por lo que deberá apuntar a Nil y el que era el último hasta ese momento 
apuntará al nuevo componente pasando a ser el penúltimo._

**La operación de inserción se puede definir por:**

```
Procedure Insertar (Var Ultimo : Punteros; Informacion : Tipo de dato);

Var

Nuevo : Cola;

begin

New (Nuevo);

Nuevo.Elemento := Informacion;

Nuevo.Proximo := Nil;

If Ultimo.Fin = Nil then

begin

Ultimo.Inicio := Nuevo;

Ultimo.Fin := Nuevo:

end

else

begin

Ultimo.Fin.Proximo := Nuevo;

Ultimo.Fin := Nuevo;

end;

end;
```

**y la de extracción por:**

```
Procedure Extraer (Var Ultimo : Punteros; Var Información : Tipo de dato);

begin

If Ultimo.Inicio <> Nil Then

begin

Información := Ultimo.Inicio.Elemento;

Ultimo.Inicio := Ultimo.Inicio.Proximo;

end;

end;
```

_Antes de usarlos se debe declarar una variable de tipo "Punteros" y otra de tipo 
"Tipo de dato" e inicializar los punteros "Inicio" y "Fin" de la variable "Punteros" a "Nil"._

_Al igual que en el caso de las pilas, esta forma de representación de las colas es 
muy eficiente en el caso de que sea necesario indicar el orden de procesamiento 
de los datos y no se conozca la cantidad de elementos a procesar._
