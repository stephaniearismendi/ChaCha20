/**
 * @file main.cpp
 * @author stephanie arismendi escobar (alu0101351728)
 * @brief ChaCha20 cipher development C++
 * @version 0.1
 * @date 2022-03-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "ChaCha.hpp"

using namespace std;

int main()
{
    cout << "  ______   __                   ______   __                   ______    ______  " << endl;
    cout << " /      \ /  |                 /      \ /  |                 /      \  /      \ " << endl;
    cout << "/$$$$$$  |$$ |____    ______  /$$$$$$  |$$ |____    ______  /$$$$$$  |/$$$$$$  |" << endl;
    cout << "$$ |  $$/ $$      \  /      \ $$ |  $$/ $$      \  /      \ $$____$$ |$$$  \$$ |" << endl;
    cout << "$$ |      $$$$$$$  | $$$$$$  |$$ |      $$$$$$$  | $$$$$$  | /    $$/ $$$$  $$ |" << endl;
    cout << "$$ |   __ $$ |  $$ | /    $$ |$$ |   __ $$ |  $$ | /    $$ |/$$$$$$/  $$ $$ $$ |" << endl;
    cout << "$$ \__/  |$$ |  $$ |/$$$$$$$ |$$ \__/  |$$ |  $$ |/$$$$$$$ |$$ |_____ $$ \$$$$ |" << endl;
    cout << "$$    $$/ $$ |  $$ |$$    $$ |$$    $$/ $$ |  $$ |$$    $$ |$$       |$$   $$$/ " << endl;
    cout << " $$$$$$/  $$/   $$/  $$$$$$$/  $$$$$$/  $$/   $$/  $$$$$$$/ $$$$$$$$/  $$$$$$/  " << endl;
    cout << "                                                                                " << endl;
    ChaCha20 obj;
    obj.declarar_datos();
    // obj.introducir_datos();
    obj.algorithm();
}