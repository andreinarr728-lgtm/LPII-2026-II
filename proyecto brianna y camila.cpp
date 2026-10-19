/*
 * Proyecto N.° 1 - Modelo C: Punto de venta "Cafetería PSM"
 * Asignatura: Lenguaje de Programación II (C++) - Sección A
 * Integrantes: [Brianna Robles 34.186.075] y [Camila Villarroel 32.761.908]
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

// Prototypes de funciones
void mostrarCatalogo();
double precioProducto(int codigo);
int leerEnteroEnRango(int minVal, int maxVal);
double leerRealPositivo();
double calcularDescuento(double subtotal);
double calcularIVA(double base);
double aBolivares(double dolares, double tasa);
double calcularVuelto(double total, double recibido);

/*
 * Función: main
 * Qué hace: Controla el flujo principal del punto de venta y el menú general.
 * Qué recibe: Nada.
 * Qué retorna: 0 al finalizar la ejecución correctamente.
 */
int main() {
    cout << fixed << setprecision(2);
    
    cout << "========================================" << endl;
    cout << "   PUNTO DE VENTA - CAFETERIA PSM       " << endl;
    cout << "========================================" << endl;
    
    cout << "Ingrese la tasa del dia (Bs por dolar): ";
    double tasaDia = leerRealPositivo();

    // Variables acumuladoras para el Cierre de Caja
    int totalVentasRegistradas = 0;
    int cantCafe = 0;
    int cantEmpanada = 0;
    int cantJugo = 0;
    int cantPastelito = 0;
    int cantCombo = 0;
    
    double totalVendidoUSD = 0.0;
    double totalVendidoBs = 0.0;
    double ventaMasAltaUSD = 0.0;
    double totalCobradoEfectivoUSD = 0.0;

    int opcionMenu = 0;

    do {
        cout << "\n----------------------------------------" << endl;
        cout << "            MENU PRINCIPAL              " << endl;
        cout << "----------------------------------------" << endl;
        cout << "1. Registrar nueva venta" << endl;
        cout << "2. Mostrar catalogo de productos" << endl;
        cout << "3. Cambiar tasa del dia (Actual: " << tasaDia << " Bs/$)" << endl;
        cout << "4. Cierre de caja" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion (1-5): ";
        
        opcionMenu = leerEnteroEnRango(1, 5);

        switch (opcionMenu) {
            case 1: {
                cout << "\n--- NUEVA VENTA ---" << endl;
                mostrarCatalogo();

                int itemsEnVenta = 0;
                double subtotalVentaUSD = 0.0;
                
                // Contadores temporales para la venta actual
                int tempCafe = 0;
                int tempEmpanada = 0;
                int tempJugo = 0;
                int tempPastelito = 0;
                int tempCombo = 0;

                int codProd = -1;

                while (codProd != 0) {
                    cout << "\nCodigo de producto (1-5, o 0 para finalizar agregados): ";
                    codProd = leerEnteroEnRango(0, 5);

                    if (codProd != 0) {
                        cout << "Cantidad a llevar (1-50): ";
                        int cant = leerEnteroEnRango(1, 50);

                        double pUnitario = precioProducto(codProd);
                        subtotalVentaUSD += (pUnitario * cant);
                        itemsEnVenta += cant;

                        // Acumular temporalmente por producto
                        if (codProd == 1) tempCafe += cant;
                        else if (codProd == 2) tempEmpanada += cant;
                        else if (codProd == 3) tempJugo += cant;
                        else if (codProd == 4) tempPastelito += cant;
                        else if (codProd == 5) tempCombo += cant;

                        cout << "-> Agregado. Subtotal parcial: $" << subtotalVentaUSD << endl;
                    }
                }

                // Validacion obligatoria: No permitir cerrar venta sin productos
                if (itemsEnVenta == 0) {
                    cout << "\n[!] Venta cancelada: No se agregaron productos." << endl;
                } else {
                    double descUSD = calcularDescuento(subtotalVentaUSD);
                    double baseImponibleUSD = subtotalVentaUSD - descUSD;
                    double ivaUSD = calcularIVA(baseImponibleUSD);
                    double totalVentaUSD = baseImponibleUSD + ivaUSD;
                    double totalVentaBs = aBolivares(totalVentaUSD, tasaDia);

                    cout << "\n--- RESUMEN DE COMPRA ---" << endl;
                    cout << "Subtotal:   $" << subtotalVentaUSD << endl;
                    cout << "Descuento:  $" << descUSD << endl;
                    cout << "IVA (16%):  $" << ivaUSD << endl;
                    cout << "TOTAL USD:  $" << totalVentaUSD << endl;
                    cout << "TOTAL BS:   " << totalVentaBs << " Bs" << endl;

                    cout << "\nForma de Pago:" << endl;
                    cout << "1. Efectivo en dolares ($)" << endl;
                    cout << "2. Pago movil en bolivares (Bs)" << endl;
                    cout << "Seleccione forma de pago (1-2): ";
                    int formaPago = leerEnteroEnRango(1, 2);

                    if (formaPago == 1) {
                        cout << "Monto recibido en efectivo ($): ";
                        double recibidoUSD = leerRealPositivo();
                        
                        // Validacion: El pago no puede ser menor al total
                        while (recibidoUSD < totalVentaUSD) {
                            cout << "[!] Error: El monto recibido es menor al total ($" << totalVentaUSD << ")." << endl;
                            cout << "Ingrese un monto mayor o igual al total ($): ";
                            recibidoUSD = leerRealPositivo();
                        }

                        double vueltoUSD = calcularVuelto(totalVentaUSD, recibidoUSD);
                        cout << "Vuelto entregado: $" << vueltoUSD << endl;

                        totalCobradoEfectivoUSD += totalVentaUSD;
                    } else {
                        cout << "Pago movil procesado exitosamente por " << totalVentaBs << " Bs." << endl;
                    }

                    // Confirmar y consolidar datos globales del turno
                    totalVentasRegistradas++;
                    cantCafe += tempCafe;
                    cantEmpanada += tempEmpanada;
                    cantJugo += tempJugo;
                    cantPastelito += tempPastelito;
                    cantCombo += tempCombo;

                    totalVendidoUSD += totalVentaUSD;
                    totalVendidoBs += totalVentaBs;

                    if (totalVentaUSD > ventaMasAltaUSD) {
                        ventaMasAltaUSD = totalVentaUSD;
                    }

                    cout << "\n[OK] Venta #" << totalVentasRegistradas << " registrada con exito." << endl;
                }
                break;
            }
            case 2:
                mostrarCatalogo();
                break;

            case 3:
                cout << "\nIngrese la nueva tasa del dia (Bs por dolar): ";
                tasaDia = leerRealPositivo();
                cout << "[OK] Tasa actualizada a: " << tasaDia << " Bs/$" << endl;
                break;

            case 4:
            case 5: {
                // Impresion de Cierre de Caja
                cout << "\n========================================" << endl;
                cout << "            CIERRE DE CAJA              " << endl;
                cout << "========================================" << endl;
                cout << "Ventas totales realizadas: " << totalVentasRegistradas << endl;
                cout << "Unidades vendidas por producto:" << endl;
                cout << "  1. Cafe:                      " << cantCafe << " und" << endl;
                cout << "  2. Empanada:                  " << cantEmpanada << " und" << endl;
                cout << "  3. Jugo natural:              " << cantJugo << " und" << endl;
                cout << "  4. Pastelito:                 " << cantPastelito << " und" << endl;
                cout << "  5. Combo empanada y jugo:     " << cantCombo << " und" << endl;
                cout << "----------------------------------------" << endl;
                cout << "Total vendido en USD:         $" << totalVendidoUSD << endl;
                cout << "Total vendido en Bs:          " << totalVendidoBs << " Bs" << endl;
                cout << "Venta mas alta registrada:    $" << ventaMasAltaUSD << endl;
                cout << "Total cobrado en efectivo ($):$" << totalCobradoEfectivoUSD << endl;
                cout << "========================================" << endl;

                if (opcionMenu == 5) {
                    cout << "Saliendo del programa... ¡Hasta luego!" << endl;
                }
                break;
            }
        }
    } while (opcionMenu != 5);

    return 0;
}

/*
 * Función: mostrarCatalogo
 * Qué hace: Muestra el catálogo de productos con sus respectivos códigos y precios.
 * Qué recibe: Nada.
 * Qué retorna: Ningún valor (void).
 */
void mostrarCatalogo() {
    cout << "\n----------------------------------------" << endl;
    cout << "           CATALOGO DE PRODUCTOS        " << endl;
    cout << "----------------------------------------" << endl;
    cout << "1. Cafe                   - $1.50" << endl;
    cout << "2. Empanada               - $2.00" << endl;
    cout << "3. Jugo natural           - $2.50" << endl;
    cout << "4. Pastelito              - $1.00" << endl;
    cout << "5. Combo empanada y jugo  - $4.00" << endl;
    cout << "----------------------------------------" << endl;
}

/*
 * Función: precioProducto
 * Qué hace: Retorna el precio unitario en USD según el código del producto.
 * Qué recibe: int codigo (código del producto del 1 al 5).
 * Qué retorna: double con el precio unitario en USD.
 */
double precioProducto(int codigo) {
    switch (codigo) {
        case 1: return 1.50;
        case 2: return 2.00;
        case 3: return 2.50;
        case 4: return 1.00;
        case 5: return 4.00;
        default: return 0.0;
    }
}

/*
 * Función: leerEnteroEnRango
 * Qué hace: Lee un número entero de la entrada estándar y valida tipo y rango.
 * Qué recibe: int minVal (límite inferior), int maxVal (límite superior).
 * Qué retorna: int validado dentro del rango [minVal, maxVal].
 */
int leerEnteroEnRango(int minVal, int maxVal) {
    int valor;
    while (true) {
        if (cin >> valor) {
            if (valor >= minVal && valor <= maxVal) {
                return valor;
            } else {
                cout << "[!] Error: Ingrese un numero entre " << minVal << " y " << maxVal << ": ";
            }
        } else {
            cout << "[!] Error: Entrada invalida. Ingrese un entero numerico: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

/*
 * Función: leerRealPositivo
 * Qué hace: Lee un número real (double) y valida que sea estrictamente mayor a 0.
 * Qué recibe: Nada.
 * Qué retorna: double validado mayor que 0.
 */
double leerRealPositivo() {
    double valor;
    while (true) {
        if (cin >> valor) {
            if (valor > 0.0) {
                return valor;
            } else {
                cout << "[!] Error: El numero debe ser mayor a 0: ";
            }
        } else {
            cout << "[!] Error: Entrada invalida. Ingrese un numero real: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

/*
 * Función: calcularDescuento
 * Qué hace: Calcula y retorna el 10% de descuento si el subtotal es >= $20.00.
 * Qué recibe: double subtotal (monto bruto antes de impuestos/descuentos).
 * Qué retorna: double con el monto del descuento aplicable ($).
 */
double calcularDescuento(double subtotal) {
    if (subtotal >= 20.00) {
        return subtotal * 0.10;
    }
    return 0.0;
}

/*
 * Función: calcularIVA
 * Qué hace: Calcula el 16% de IVA sobre un monto base.
 * Qué recibe: double base (monto con descuento aplicado).
 * Qué retorna: double con el IVA en dólares.
 */
double calcularIVA(double base) {
    return base * 0.16;
}

/*
 * Función: aBolivares
 * Qué hace: Convierte una cantidad dada en dólares a bolívares según la tasa.
 * Qué recibe: double dolares, double tasa.
 * Qué retorna: double con el equivalente en bolívares (Bs).
 */
double aBolivares(double dolares, double tasa) {
    return dolares * tasa;
}

/*
 * Función: calcularVuelto
 * Qué hace: Calcula el cambio o vuelto a entregar en dólares.
 * Qué recibe: double total (monto a pagar), double recibido (monto entregado por el cliente).
 * Qué retorna: double con el vuelto correspondiente.
 */
double calcularVuelto(double total, double recibido) {
    return recibido - total;
}
