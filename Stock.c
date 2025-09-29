#include <stdio.h>

int main() {
    int id, stock, cantidad, opcion;
    float precio, total_ganancias = 0, descuento, precio_con_descuento, total_venta;
    char nombre[30];

    // Registro del producto
    printf("Ingrese el ID del producto: ");
    scanf("%d", &id);

    printf("Ingrese el nombre del producto: ");
    scanf("%c" ,nombre);
    fgets(nombre, 30, stdin); 
    
    // Validar que el stock no sea negativo
    do {
        printf("Ingrese la cantidad inicial en stock: ");
        scanf("%d", &stock);
        if (stock < 0) {
            printf("El stock no puede ser negativo. Intente nuevamente.\n");
        }
    } while (stock < 0);

    // Validar que el precio no sea negativo
    do {
        printf("Ingrese el precio unitario del producto: ");
        scanf("%f", &precio);
        if (precio < 0) {
            printf("El precio no puede ser negativo. Intente nuevamente.\n");
        }
    } while (precio < 0);

    do {
        printf("\nMenú de Opciones:\n");
        printf("1. Vender producto\n");
        printf("2. Reabastecer producto\n");
        printf("3. Mostrar información del producto\n");
        printf("4. Mostrar total de ganancias\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                // Validar que la cantidad a vender no sea negativa
                do {
                    printf("Ingrese la cantidad a vender: ");
                    scanf("%d", &cantidad);
                    if (cantidad < 0) {
                        printf("La cantidad no puede ser negativa. Intente nuevamente.\n");
                    }
                } while (cantidad < 0);

                if (stock < cantidad) {
                    printf("No hay suficiente unidades en stock; no se puede vender.\n");
                } else {
                    // Pedir el porcentaje de descuento
                    do {
                        printf("Ingrese el porcentaje de descuento (0-100): ");
                        scanf("%f", &descuento);
                        if (descuento < 0 || descuento > 100) {
                            printf("Porcentaje de descuento inválido. Debe estar entre 0 y 100.\n");
                        }
                    } while (descuento < 0 || descuento > 100);

                    // Calculamos el precio con descuento
                    precio_con_descuento = precio * (1 - descuento / 100);
                    
                    // Calculamos el total de la venta con el precio con descuento
                    total_venta = cantidad * precio_con_descuento;
                    
                    // Realizamos la venta: restamos el stock y sumamos las ganancias
                    stock -= cantidad;
                    total_ganancias += total_venta;  // Sumamos las ganancias con el descuento aplicado
                    
                    printf("Venta realizada con exito, %d unidades vendidas.\n", cantidad);
                    printf("Precio con descuento: %.2f\n", precio_con_descuento);
                    printf("Total de la venta con descuento: %.2f\n", total_venta);
                }
                break;

            case 2:
                // Validar que la cantidad a reabastecer no sea negativa
                do {
                    printf("Ingrese la cantidad a agregar al stock: ");
                    scanf("%d", &cantidad);
                    if (cantidad < 0) {
                        printf("La cantidad no puede ser negativa. Intente nuevamente.\n");
                    }
                } while (cantidad < 0);
                stock += cantidad;  // Aumentamos el stock con la cantidad proporcionada
                printf("Stock actualizado. Nuevo stock: %d\n", stock);
                break;

            case 3:
                printf("\nInformación del producto:\n");
                printf("ID: %d\n", id);
                printf("Nombre: %s", nombre);
                printf("Stock disponible: %d\n", stock);
                printf("Precio unitario: %.2f\n", precio);
                break;

            case 4:
                printf("Total de ganancias: $%.2f\n", total_ganancias);
                break;

            case 5:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }
    } while (opcion != 5);

    return 0;
}