//
// Created by pavel on 1/30/18.
//

#ifndef CNOT_MEMORY_H
#define CNOT_MEMORY_H


#include "Ptr.h"

namespace CNOT::Memory {
    void set_cell(unsigned int address, Ptr::IPtr *ptr);
    Ptr::IPtr *get_cell(unsigned int address);
}

#endif //CNOT_MEMORY_H
