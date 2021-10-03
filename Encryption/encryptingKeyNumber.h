//
// Created by andrew on 03.10.2021.
//

#ifndef ENCRYPTION_ENCRYPTINGKEYNUMBER_H
#define ENCRYPTION_ENCRYPTINGKEYNUMBER_H

struct encryptionKeyNumber {
    char key[100];
    int number;
};

void Print(encryptionKeyNumber &keyNumber);

#endif //ENCRYPTION_ENCRYPTINGKEYNUMBER_H
