cmake_minimum_required(VERSION 3.20)
project(Encryption)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        # Headers
        container.h
        encryptionKeyValue.h
        periodicShift.h

        # Sources
        main.cpp
        container.cpp
        encryptionKeyValue.cpp
        periodicShift.cpp encryptingKeyNumber.h encryptingKeyNumber.cpp)

add_executable(Encryption ${SOURCE_FILES})
