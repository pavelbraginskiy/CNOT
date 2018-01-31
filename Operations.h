//
// Created by pavel on 1/30/18.
//

#ifndef CNOT_OPERATIONS_H
#define CNOT_OPERATIONS_H

#include "Ptr.h"
#define pt Ptr::IPtr*


namespace CNOT::Operations {
    void op_not(pt a); //NOT

    void op_cnot(pt a, pt b); //Controlled NOT

    void op_ccnot(pt a, pt b, pt c); //Doubly controlled NOT

    void op_write_l(char *string); //Write Literal

    void op_copy(pt a, pt b); //Copy from a to b
}
#undef pt
#endif //CNOT_OPERATIONS_H
