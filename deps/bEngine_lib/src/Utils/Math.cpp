#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc51-cpp"
#pragma ide diagnostic ignored "cert-msc50-cpp"
//
// Created by benajah on 10/25/24.
//

#include "bEngine/Utils/Math.h"

#include <cstdlib>
#include <ctime>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
namespace bEngine::Utils::Math {
    bool srand_initialized{false};
    int randomValue(int min, int max) {
        if (min > max) {
            min ^= max;
            max ^= min;
            min ^= max;
        }

        if (!srand_initialized) {
            srand(time(nullptr));
            srand_initialized = true;
        }


        return rand() % abs(max - min + 1) + min;
    }
}// namespace bEngine::Utils::Math
#pragma clang diagnostic pop
#pragma clang diagnostic pop