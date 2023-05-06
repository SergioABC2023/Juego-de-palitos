#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int Palitos = 15; // Número de palitos
const int PalitosPorTurnoMaximos = 3; // Número máximo de palitos por turno
const int IA1 = 1; // (Primera IA)
const int IA2 = 2; // (Segunda IA)

// Función que imprime los palitos
void ImprimirPalitos(int NumPalitos) {
    for (int i = 0; i < NumPalitos; i++) {
        cout << "|";
    }
    cout << endl;
}

// Función que realiza el turno de la IA
int TurnoIA(int IDjugador, int NumPalitos) {
    int EliminarPalitos = rand() % PalitosPorTurnoMaximos + 1;
    cout << "La IA " << IDjugador << " ha quitado " << EliminarPalitos << " palitos." << endl;
    return NumPalitos - EliminarPalitos;
}

int main() {
    srand(time(NULL));

    int NumPalitos = Palitos; // número de palitos
    int numeroIA = IA1; // jugador actual, Ejemplo: IA 1

    // Ciclo del juego
    while (NumPalitos > 0) {
        cout << "Palitos: ";
        ImprimirPalitos(NumPalitos); // Imprimir los palitos

        // Realizar turno del jugador actual
        if (numeroIA == IA1) {
            NumPalitos = TurnoIA(numeroIA, NumPalitos);
            numeroIA = IA2;
        } else if (numeroIA == IA2) {
            NumPalitos = TurnoIA(numeroIA, NumPalitos);
            numeroIA = IA1;
        }
    }
    cout <<  endl;
    cout << "Gana la IA " << numeroIA << endl;

    return 0;
}
