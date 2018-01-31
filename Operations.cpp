//
// Created by pavel on 1/30/18.
//

#include <iostream>
#include "Operations.h"

namespace CNOT::Operations {
    void op_not(Ptr::IPtr* a) {
        a->SetRefPtr(new Ptr::RealPtr(~(a->DeRef()->GetValue())));
    }

    void op_cnot(Ptr::IPtr* a, Ptr::IPtr* b) {
        Ptr::IPtr *a_val, *b_val;
        a_val = a->DeRef();
        b_val = b->DeRef();
        auto res = a_val->GetValue() ^ b_val->GetValue();
        b->SetRefPtr(new Ptr::RealPtr(res));
    }

    void op_ccnot(Ptr::IPtr* a, Ptr::IPtr* b, Ptr::IPtr* c) {
        Ptr::IPtr *a_val, *b_val, *c_val;
        a_val = a->DeRef();
        b_val = b->DeRef();
        c_val = c->DeRef();

        auto res = c_val->GetValue() ^ (a_val->GetValue() & b_val->GetValue());
        c->SetRefPtr(new Ptr::RealPtr(res));
    }

    void op_write_l(char *string) {
        std::cout << string << std::endl;
    }

    void op_copy(Ptr::IPtr* a, Ptr::IPtr* b) {
        b->SetRefPtr(a->DeRef());
    }
}