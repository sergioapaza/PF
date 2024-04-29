#include <iostream>
#include "Cajero.h"
#include "Cliente.h"

int main() {
    // Crear un cajero
    Cajero cajero;

    // Crear cuentas para clientes
    Cuenta cuenta1(12345, "Juan Perez", 11111111, true, true, "contraseña1", true);
    Cuenta cuenta2(67890, "Maria Gomez", 22222222, false, false, "contraseña2", false);

    // Asignar cuentas al cajero
    cajero.crearCuenta(cuenta1);
    cajero.crearCuenta(cuenta2);

    // Crear clientes
    Cliente cliente1(11111111, "Juan Perez", cuenta1, cajero);
    Cliente cliente2(22222222, "Maria Gomez", cuenta2, cajero);

    // Cliente 1 realiza operaciones
    cliente1.iniciarSesion();
    cliente1.consultarSaldo();
    cliente1.retirarEfectivo(500.0);
    cliente1.depositarEfectivo(1000.0);
    cliente1.realizarTransferencia(67890, 200.0);
    cliente1.salir();

    // Cliente 2 realiza operaciones
    cliente2.iniciarSesion();
    cliente2.consultarSaldo();
    cliente2.retirarEfectivo(300.0);
    cliente2.depositarEfectivo(2000.0);
    cliente2.salir();

    return 0;
}
