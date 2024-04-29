#include "Cuenta.h"
#include "Cajero.h"

using namespace std;

class Cliente {
private:
    int DNI;
    string nombreApellidos;
    Cuenta cuenta;
    Cajero cajero;

public:
    Cliente(int DNI, const string& nombreApellidos, const Cuenta& cuenta, const Cajero& cajero)
        : DNI(DNI), nombreApellidos(nombreApellidos), cuenta(cuenta), cajero(cajero) {}

    void iniciarSesion() const {
        cout << "Iniciando sesión como: " << nombreApellidos << endl;
        cajero.iniciarSesion(cuenta.obtenerNumeroCuenta(), cuenta.obtenerNombreApellidos());
    }

    void consultarSaldo() const {
        cajero.consultarSaldo(cuenta.obtenerNumeroCuenta());
    }

    void retirarEfectivo(float cantidad) const {
        cajero.retirarEfectivo(cuenta.obtenerNumeroCuenta(), cantidad);
    }

    void depositarEfectivo(float cantidad) const {
        cajero.depositarEfectivo(cuenta.obtenerNumeroCuenta(), cantidad);
    }

    void realizarTransferencia(int numeroCuentaDestino, float cantidad) const {
        cajero.transferencia(cuenta.obtenerNumeroCuenta(), numeroCuentaDestino, cantidad);
    }

    void salir() const {
        cajero.salir();
    }
};