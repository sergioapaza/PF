#ifndef CAJERO_H
#define CAJERO_H

#include <vector>
#include "Banco.h"
#include "Cuenta.h"

using namespace std;

class Cajero : public Banco {
private:
    int numeroCuentas;
    vector<Cuenta> cuentas; // Lista de cuentas

public:
    Cajero() : numeroCuentas(0) {}

    void crearCuenta(const Cuenta& nuevaCuenta) {
        cuentas.push_back(nuevaCuenta);
        numeroCuentas++;
    }

    void iniciarSesion(int numeroCuenta, const string& contraseña) {
        for (const Cuenta& cuenta : cuentas) {
            if (cuenta.obtenerNumeroCuenta() == numeroCuenta) {
                cuenta.verificarCuenta(contraseña);
                return;
            }
        }
        cout << "Cuenta no encontrada." << endl;
    }

    void consultarSaldo(int numeroCuenta) {
        for (const Cuenta& cuenta : cuentas) {
            if (cuenta.obtenerNumeroCuenta() == numeroCuenta) {
                cout << "Saldo de la cuenta " << cuenta.obtenerNumeroCuenta() << ": " << cuenta.obtenerSaldo() << endl;
                return;
            }
        }
        cout << "Cuenta no encontrada." << endl;
    }

    void retirarEfectivo(int numeroCuenta, float cantidad) {
        for (Cuenta& cuenta : cuentas) {
            if (cuenta.obtenerNumeroCuenta() == numeroCuenta) {
                cuenta.verificarMaximoRetiro(cantidad);
                if (cuenta.obtenerSaldo() >= cantidad) {
                    cuenta.modificarSaldo(cuenta.obtenerSaldo() - cantidad);
                    cout << "Retiro realizado. Nuevo saldo: " << cuenta.obtenerSaldo() << endl;
                } else {
                    cout << "Saldo insuficiente." << endl;
                }
                return;
            }
        }
        cout << "Cuenta no encontrada." << endl;
    }

    void depositarEfectivo(int numeroCuenta, float cantidad) {
        for (Cuenta& cuenta : cuentas) {
            if (cuenta.obtenerNumeroCuenta() == numeroCuenta) {
                cuenta.verificarMaximoDeposito(cantidad);
                cuenta.modificarSaldo(cuenta.obtenerSaldo() + cantidad);
                cout << "Deposito realizado. Nuevo saldo: " << cuenta.obtenerSaldo() << endl;
                return;
            }
        }
        cout << "Cuenta no encontrada." << endl;
    }

    void transferencia(int numeroCuentaOrigen, int numeroCuentaDestino, float cantidad) {
        Cuenta* cuentaOrigen = nullptr;
        Cuenta* cuentaDestino = nullptr;

        for (Cuenta& cuenta : cuentas) {
            if (cuenta.obtenerNumeroCuenta() == numeroCuentaOrigen) {
                cuentaOrigen = &cuenta;
            } else if (cuenta.obtenerNumeroCuenta() == numeroCuentaDestino) {
                cuentaDestino = &cuenta;
            }

            if (cuentaOrigen && cuentaDestino) {
                break;
            }
        }

        if (cuentaOrigen && cuentaDestino) {
            cuentaOrigen->verificarMaximoRetiro(cantidad);
            if (cuentaOrigen->obtenerSaldo() >= cantidad) {
                cuentaOrigen->modificarSaldo(cuentaOrigen->obtenerSaldo() - cantidad);
                cuentaDestino->modificarSaldo(cuentaDestino->obtenerSaldo() + cantidad);
                cout << "Transferencia realizada de la cuenta " << numeroCuentaOrigen
                     << " a la cuenta " << numeroCuentaDestino << ". Cantidad: " << cantidad << endl;
                return;
            } else {
                cout << "Saldo insuficiente." << endl;
            }
        } else {
            cout << "Una o ambas cuentas no encontradas." << endl;
        }
    }

    void salir() {
        cout << "Cerrando sesion." << endl;
    }

    int obtenerNumeroCuentas() const {
        return numeroCuentas;
    }
};

#endif // CAJERO_H
