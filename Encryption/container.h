//
// Created by andrew on 03.10.2021.
//

#ifndef ENCRYPTION_CONTAINER_H
#define ENCRYPTION_CONTAINER_H

#include "encryptionKeyValue.h"
#include "periodicShift.h"
#include "encryptingKeyNumber.h"

struct container {
public:
    static const int CAPACITY = 1000;

    // length's for each container
    int lengthKV = 0;
    int lengthPS = 0;
    int lengthKN = 0;

    // Containers[][].
    encryptionKeyValue *containerKV[CAPACITY];
    periodicShift *containerPS[CAPACITY];
    encryptionKeyNumber *containerKN[CAPACITY];
};

/// Randomizing values.
void RndExamples(std::ofstream& ofs);

/// Randomizes values for only key.
void Sort(container& cont);

#endif //ENCRYPTION_CONTAINER_H
