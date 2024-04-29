#ifndef CLIENTE_H
#define CLIENTE_H

#include "Cuenta.h"
#include "Cajero.h"

using namespace std;

class Cliente {
private:
    int DNI;
    string nombreApellidos;
    Cuenta cuenta;
    Cajero& cajero; // Cajero es ahora una referencia no constante

public:
    Cliente(int DNI, const string& nombreApellidos, const Cuenta& cuenta, Cajero& cajero) // Se cambió const Cajero& por Cajero&
        : DNI(DNI), nombreApellidos(nombreApellidos), cuenta(cuenta), cajero(cajero) {}

    void iniciarSesion() {
        cout << "Iniciando sesion como: " << nombreApellidos << endl;
        cajero.iniciarSesion(cuenta.obtenerNumeroCuenta(), cuenta.obtenerNombreApellidos());
    }

    void consultarSaldo() {
        cajero.consultarSaldo(cuenta.obtenerNumeroCuenta());
    }

    void retirarEfectivo(float cantidad) {
        cajero.retirarEfectivo(cuenta.obtenerNumeroCuenta(), cantidad);
    }

    void depositarEfectivo(float cantidad) {
        cajero.depositarEfectivo(cuenta.obtenerNumeroCuenta(), cantidad);
    }

    void realizarTransferencia(int numeroCuentaDestino, float cantidad) {
        cajero.transferencia(cuenta.obtenerNumeroCuenta(), numeroCuentaDestino, cantidad);
    }

    void salir() {
        cajero.salir();
    }
};

#endif // CLIENTE_H
