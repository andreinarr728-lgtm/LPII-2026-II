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



---

## Tabla de Casos de Prueba

| N.| Descripción del Caso                           | Entrada de Prueba                                  | Salida Esperada                                            | Salida Obtenida        | Estatus |
| 1 | Tasa con letras                                | `cuarenta` / `40`                                  | Mensaje de error y solicitar de nuevo                      | *(Resultado obtenido)* | ✅ |
| 2 | Tasa con cero o negativo                       | `0` o `-5`                                         | Mensaje de error y solicitar de nuevo                      | *(Resultado obtenido)* | ✅ |
| 3 | Código de producto inválido                    | Código: `6`                                        | Mensaje de error y volver a pedir                          | *(Resultado obtenido)* | ✅ |
| 4 | Código con letras                              | Código: `abc`                                      | Mensaje de error y volver a pedir                          | *(Resultado obtenido)* | ✅ |
| 5 | Cantidad fuera de rango                        | Cantidad: `0` o `55`                               | Mensaje de error y volver a pedir                          | *(Resultado obtenido)* | ✅ |
| 6 | Terminar venta sin productos                   | Código: `0` (al iniciar la venta)                  | Mensaje de aviso de que no se puede cerrar venta vacía     | *(Resultado obtenido)* | ✅ |
| 7 | Venta menor al descuento ($19.50\text{ \$}$)   | Código `4` (x1) + Código `3` (x3), etc.            | Subtotal $19.50\text{ \$}$ (Sin descuento del 10%)         | *(Resultado obtenido)* | ✅ |
| 8 | Venta exacta con descuento ($20.00\text{ \$}$) | Cantidades que sumen exactamente $20.00\text{ \$}$ | Aplicación correcta del 10% de descuento                   | *(Resultado obtenido)* | ✅ |
| 9 | Pago en efectivo menor al total                | Monto menor al total calculado                     | Rechazar pago y volver a pedir monto recibido              | *(Resultado obtenido)* | ✅ |
| 10 | Cierre de caja sin ventas                     | Seleccionar opción Salir sin registrar turnos      | Resumen con 0 ventas y $0.00$ acumulados                   | *(Resultado obtenido)* | ✅ |
