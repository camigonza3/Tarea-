#include <stdio.h>
 
int main() {
    int num_empleados = 0;
    float horas_trabajadas, valor_hora, ventas, salario_bruto, bonificacion, aporte_iess, salario_neto, horas_extra;
    float total_nominas = 0;
    char respuesta;
 
    while (1) {
        printf("¿Desea registrar un empleado? (s/n): ");
        scanf(" %c", &respuesta);
 
        if (respuesta == 'n') {
            break;
        }
 
        // Preguntar por las horas trabajadas del empleado
        do {
            printf("Ingrese las horas trabajadas: ");
            scanf("%f", &horas_trabajadas);
        } while (horas_trabajadas < 0);
 
        // Preguntar por el valor de la hora del empleado
        do {
            printf("Ingrese el valor por hora: ");
            scanf("%f", &valor_hora);
        } while (valor_hora < 0);
 
        // Preguntar por el valor de ventas del empleado
        do {
            printf("Ingrese el valor de ventas: ");
            scanf("%f", &ventas);
        } while (ventas < 0);
 
        // Calcular el número de horas extra trabajadas
        if (horas_trabajadas > 40) {
            horas_extra = horas_trabajadas - 40;
        } else {
            horas_extra = 0;
        }
 
        // Calcular el salario bruto del empleado, incluyendo horas extra
        salario_bruto = (horas_trabajadas - horas_extra) * valor_hora + horas_extra * (valor_hora * 1.1 * (horas_extra <= 10) + valor_hora * 1.15 * (horas_extra > 10 && horas_extra <= 15) + valor_hora * 1.2 * (horas_extra > 15));
 
        // Calcular la bonificación en función del valor de ventas del empleado
        bonificacion = ventas * 0.02 * (ventas <= 800) + ventas * 0.04 * (ventas > 800 && ventas <= 1500) + ventas * 0.06 * (ventas > 1500 && ventas <= 3000) + ventas * 0.08 * (ventas > 3000);
 
        // Calcular el aporte al IESS (Instituto Ecuatoriano de Seguridad Social)
        aporte_iess = salario_bruto * 0.0945;
 
        // Calcular el salario neto del empleado, después de deducir el aporte al IESS y sumar la bonificación
        salario_neto = salario_bruto - aporte_iess + bonificacion;
 
        // Imprimir el salario neto del empleado
        printf("Salario del empleado %d: $%.2f\n", ++num_empleados, salario_neto);
 
        // Actualizar el valor total de la nómina
        total_nominas += salario_neto;
    }
 
    // Imprimir el valor promedio de la nómina si se registraron empleados
    if (num_empleados > 0) {
        printf("\nValor promedio de la nómina: $%.2f\n", total_nominas / num_empleados);
    }
 
    return 0;
}

