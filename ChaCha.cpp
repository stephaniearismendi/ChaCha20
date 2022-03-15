#include "ChaCha.hpp"
#include <iomanip>
#include <vector>

/* Rota un entero 'x' de 32 bits 'n' bits a la izquierda */
#define RtoL(x, n) \
    ((x << n) | (x >> (32 - n)))

/* Definición de la función Quarter-Round del ChaCha20 */
#define QR(a, b, c, d)             \
    block[a] += block[b];          \
    block[d] ^= block[a];          \
    block[d] = RtoL(block[d], 16); \
    block[c] += block[d];          \
    block[b] ^= block[c];          \
    block[b] = RtoL(block[b], 12); \
    block[a] += block[b];          \
    block[d] ^= block[a];          \
    block[d] = RtoL(block[d], 8);  \
    block[c] += block[d];          \
    block[b] ^= block[c];          \
    block[b] = RtoL(block[b], 7);
/* Definición del número de rondas */
#define ROUNDS 20

void ChaCha20::declarar_datos()
{
    key[0] = 0x03020100;
    key[1] = 0x07060504;
    key[2] = 0x0b0a0908;
    key[3] = 0x0f0e0d0c;
    key[4] = 0x13121110;
    key[5] = 0x17161514;
    key[6] = 0x1b1a1918;
    key[7] = 0x1f1e1d1c;
    // for(int i = 0; i < 8; i++){
    //     cout << key[i] << endl;
    // }
    count = 0x00000001;
    nonce[0] = 0x09000000;
    nonce[1] = 0x4a000000;
    nonce[2] = 0x00000000;
}

// void ChaCha20::introducir_datos(){
//     cout << "Introduzca la clave." << endl;
//     for(uint32_t i = 0; i < 8; i++){
//         cout << "Introduzca la palabra número " << i + 1 << " de la clave: ";
//         cin >> key[i];
//         cout << endl;
//     }
//     cout << "Introduzca el nonce." << endl;
//     for(uint32_t i = 0; i < 3; i++){
//         cout << "Introduzca la palabra número " << i + 1 << " del nonce: ";
//         cin >> nonce[i];
//         cout << endl;
//     }
//     count = 0x00000001;
// }

void ChaCha20::algorithm()
{
    rellenar_bloque();
    cout << "\tEstado inicial= " << endl;
    // imprimir_bloque_int(block);
    to_hex(block);
    uint32_t init[16];
    for (int i = 0; i < 16; i++)
    {
        init[i] = block[i];
    }
    for (uint32_t i = 0; i < ROUNDS; i += 2)
    {
        QR(0, 4, 8, 12)
        QR(1, 5, 9, 13)
        QR(2, 6, 10, 14)
        QR(3, 7, 11, 15)
        QR(0, 5, 10, 15)
        QR(1, 6, 11, 12)
        QR(2, 7, 8, 13)
        QR(3, 4, 9, 14)
    }
    cout << "\tEstado final tras las 20 iteraciones= " << endl;
    // imprimir_bloque_int(block);
    to_hex(block);
    for (int i = 0; i < 16; i++)
    {
        out[i] = block[i] + init[i];
    }
    cout << "\t Estado de salida del generador= " << endl;
    to_hex(out);
}

void ChaCha20::rellenar_bloque()
{
    for (int i = 0; i < 4; i++)
    {
        block[i] = chachaConst[i];
    }
    int j = 0;
    for (int i = 4; i < 12; i++)
    {
        block[i] = key[j];
        j++;
    }
    block[12] = count;
    j = 0;
    for (int i = 13; i < 16; i++)
    {
        block[i] = nonce[j];
        j++;
    }
}

void ChaCha20::imprimir_bloque_int(uint32_t bloque[16])
{
    int j = 0;
    for (int i = 0; i < 16; i++)
    {
        cout << "\t" << bloque[i] << " ";
        if (j == 3)
        {
            j = 0;
            cout << endl;
        }
        else
        {
            j++;
        }
    }
    cout << endl;
}

void ChaCha20::to_hex(uint32_t bloque[32])
{
    std::string final;
    int j = 0;
    for (int i = 0; i < 16; i++)
    {
        std::stringstream sstream;
        sstream << std::hex << bloque[i];
        final = sstream.str();
        cout << "\t " << final << " ";
        if (j == 3)
        {
            cout << endl;
            j = 0;
        }
        else
        {
            j++;
        }
    }
    cout << endl;
}