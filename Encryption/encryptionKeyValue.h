//
// Created by andrew on 03.10.2021.
//

#ifndef ENCRYPTION_ENCRYPTIONKEYVALUE_H
#define ENCRYPTION_ENCRYPTIONKEYVALUE_H

struct encryptionKeyValue {
    char key[100], value[100];
};

void Print(encryptionKeyValue &keyValue);

#endif //ENCRYPTION_ENCRYPTIONKEYVALUE_H
