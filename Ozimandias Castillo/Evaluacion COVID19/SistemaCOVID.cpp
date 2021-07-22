// SistemaCOVID.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Cliente.h"
#include "CovidController.h"

int main()
{
    std::cout << "Hello World!\n";
    Cliente c1(5680540, 37, "Adolfo", "Villafan"), c2(5680542, 39, "Veronica", "Viania"), c3;
    CovidController cc1;
    cc1.verificarIngreso(c1, 1, 1, 8, 30);
    cc1.verificarIngreso(c2, 7, 1, 8, 30);
    cc1.verificarIngreso(c3, 5, 2, 18, 30);
    //cc1.verEstdisticas();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
