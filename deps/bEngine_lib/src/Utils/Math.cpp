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
    bool srand_initialized{ false };
    int randomValue( int min, int max ) {
        // Good Luck!!
        if ( min > max ) {
            min ^= max;
            max ^= min;
            min ^= max;
        }

        if ( !srand_initialized ) {
            srand( time( nullptr ) );
            srand_initialized = true;// Because we don’t want to seed it every damn time—who has that kind of time?
        }


        return rand() % abs( max - min + 1 ) + min;// Efficiency? Nah, we’re here for the chaos.
    }
}// namespace bEngine::Utils::Math
#pragma clang diagnostic pop
#pragma clang diagnostic pop