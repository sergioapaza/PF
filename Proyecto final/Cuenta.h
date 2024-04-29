#include <string>
#include <iostream>

using namespace std;

class Cuenta {
private:
    int numeroCuenta;
    float saldo;
    string nombreApellidos;
    int DNI;
    bool tipoMoneda;
    bool tipoTarjeta;
    string contraseña;
    bool tipoDeCuenta;

public:
    Cuenta(int numeroCuenta, const string& nombreApellidos, int DNI, bool tipoMoneda,
           bool tipoTarjeta, const string& contraseña, bool tipoDeCuenta)
        : numeroCuenta(numeroCuenta), nombreApellidos(nombreApellidos), DNI(DNI),
          tipoMoneda(tipoMoneda), tipoTarjeta(tipoTarjeta), contraseña(contraseña),
          tipoDeCuenta(tipoDeCuenta), saldo(0.0) {}

    void verificarCuenta(const string& inputContraseña) const {
        if (inputContraseña == contraseña) {
            cout << "Cuenta verificada." << endl;
        } else {
            cout << "Contraseña incorrecta." << endl;
        }
    }

    void cambiarContraseña(const string& nuevaContraseña) {
        contraseña = nuevaContraseña;
    }

    void verificarMaximoRetiro(float cantidad) const {
        if (tipoDeCuenta && cantidad > 1000.0) {
            cout << "Excede el límite de retiro para cuenta de ahorros." << endl;
        } else if (!tipoDeCuenta && cantidad > 5000.0) {
            cout << "Excede el límite de retiro para cuenta empresarial." << endl;
        } else {
            cout << "Retiro permitido." << endl;
        }
    }

    void verificarMaximoDeposito(float cantidad) const {
        if (tipoDeCuenta && cantidad > 10000.0) {
            cout << "Excede el límite de depósito para cuenta de ahorros." << endl;
        } else if (!tipoDeCuenta && cantidad > 50000.0) {
            cout << "Excede el límite de depósito para cuenta empresarial." << endl;
        } else {
            cout << "Depósito permitido." << endl;
        }
    }

    int obtenerNumeroCuenta() const {
        return numeroCuenta;
    }

    float obtenerSaldo() const {
        return saldo;
    }

    void modificarSaldo(float nuevoSaldo) {
        saldo = nuevoSaldo;
    }

    string obtenerNombreApellidos() const {
        return nombreApellidos;
    }

    int obtenerDNI() const {
        return DNI;
    }

    bool obtenerTipoMoneda() const {
        return tipoMoneda;
    }

    bool obtenerTipoTarjeta() const {
        return tipoTarjeta;
    }

    bool obtenerTipoDeCuenta() const {
        return tipoDeCuenta;
    }
};