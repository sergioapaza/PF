#ifndef BANCO_H
#define BANCO_H

#include <iostream>

using namespace std;

class Banco {
protected:
    float capital;

public:
    Banco() : capital(100000000.0) {}

    void setCapital(float newCapital) {
        capital = newCapital;
    }

    float getCapital() const {
        return capital;
    }

    void mostrarCapital() const {
        cout << "Capital del banco: " << capital << endl;
    }
};

#endif // BANCO_H
