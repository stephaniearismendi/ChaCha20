#include <iostream>
#include <stdint.h>

using namespace std;

class ChaCha20
{
private:
    const uint32_t chachaConst[4] = {0x61707865,
                                     0x3320646e,
                                     0x79622d32,
                                     0x6b206574};
    uint32_t key[8];
    uint32_t nonce[3];
    uint32_t count;
    uint32_t block[16];
    uint32_t out[16];

public:
    void declarar_datos();
    void algorithm();
    void imprimir_bloque_int(uint32_t bloque[16]);
    void rellenar_bloque();
    void to_hex(uint32_t bloque[16]);
    void introducir_datos();
};