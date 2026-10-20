# Proyecto N.° 1 - Modelo C: Punto de venta «Cafetería PSM»

Asignatura: Lenguaje de Programación II (C++)  
Sección: A  
Integrantes: [Brianna Robles 34.186.075] y [Camila Villarroel 34.186.075]  

DESCRIPCION DEL PROYECTO
Programa en C++ que simula el punto de venta de una cafetería durante un turno de trabajo. Registra ventas en dólares, realiza conversión a bolívares según la tasa del día, valida la entrada de datos contra errores de tipeo y genera un reporte completo en el cierre de caja.

COMO EJECUTAR EL PROGRAMA
1. Abrir el archivo `proyecto.cpp` en *Dev-C++* o cualquier IDE de C++.
2. Compilar y ejecutar el proyecto (`F11` en Dev-C++).
3. Al iniciar, ingresar la Tasa del día (Bs/$).
4. Utilizar el menú principal para registrar ventas, consultar el catálogo, modificar la tasa o consultar el Cierre de caja.

TABLA DE CASOS DE PRUEBA

1. Caso: Ingresar letras en lugar de un número al pedir la tasa del día.                   | Salida: Error: escriba un numero: / [!] Error: Entrada invalida. Ingrese un numero real:

2. Caso: Ingresar 0 al configurar la tasa del día.                                         |Salida: [!] Error: El numero debe ser mayor a 0:

3. Caso: Ingresar un valor negativo al configurar la tasa del día.                         |Salida: [!] Error: El numero debe ser mayor a 0:

4. Caso: Ingresar el código 6 o introducir letras al seleccionar un producto                |Salida: [!] Error: Ingrese un numero entre 0 y 5:

5. Caso: Ingresar cantidad 0 o 51 al especificar cuántas unidades llevar                    |Salida: [!] Error: Ingrese un numero entre 1 y 50:

6. Caso: Intentar terminar una venta ingresando 0 sin haber agregado ningún producto.       |Salida: [!] Venta cancelada: No se agregaron productos.

7. Caso: Registrar una venta con un subtotal de 19.50 $ (menor al umbral, sin descuento).  |Salida: Subtotal: 19.50 $, Descuento: 0.00 $, IVA: 3.12 $, Total: 22.62 $

8. Caso: Registrar una venta con un subtotal de 20.00 $ exactos (aplica 10% de descuento). |Salida: Subtotal: 20.00 $, Descuento: 2.00 $, IVA: 2.88 $, Total: 20.88 $

9. Caso: Pagar en efectivo con un monto menor al total de la cuenta.                       |Salida: [!] Error: El monto recibido es menor al total... (vuelve a solicitar el monto)

10. Caso: Ejecutar el cierre de caja sin haber registrado ninguna venta en el turno.       |Salida: Ventas totales realizadas: 0, Total vendido en USD: 0.00 $, Total vendido en Bs: 0.00 Bs
