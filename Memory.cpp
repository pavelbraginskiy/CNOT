//
// Created by pavel on 1/30/18.
//

#include <malloc.h>
#include "Memory.h"
#include "iostream"

namespace CNOT::Memory {
    Ptr::IPtr **tape = (Ptr::IPtr**) calloc(sizeof(Ptr::IPtr*), 10);
    unsigned int tape_size = 10;
    void set_cell(unsigned int address, Ptr::IPtr *ptr) {
        if (tape_size <= address) {
            tape = (Ptr::IPtr**) realloc(tape, sizeof(Ptr::IPtr*) * (address+1));
            tape_size = address+1;
        }
        if(tape[address] != nullptr)
            delete tape[address];
        tape[address] = ptr;
    }

    Ptr::IPtr *get_cell(unsigned int address) {
        if (tape_size <= address) {
            tape = (Ptr::IPtr**) realloc(tape, sizeof(Ptr::IPtr*) * (address+1));
            tape_size = address+1;

        }
        if (tape[address] == nullptr) {
            set_cell(address, new Ptr::RealPtr(0));
        }

        return tape[address];
    }
}