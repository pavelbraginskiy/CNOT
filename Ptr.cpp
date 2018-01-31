//
// Created by pavel on 1/30/18.
//

#include <iostream>
#include "Ptr.h"
#include "Memory.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
namespace CNOT::Ptr {
    RealPtr::RealPtr(unsigned int val) {
        this->value = val;
    }
    unsigned int RealPtr::GetValue() {
        return this->value;
    }

    IPtr* RealPtr::DeRef() {
        return Memory::get_cell(this->value);
    }
    IPtr* RealPtr::SpawnRef() {
        return new VirtualPtr(this);
    }
    void RealPtr::SetRefPtr(Ptr::IPtr *ptr) {
        Memory::set_cell(this->value, ptr);
    }


    VirtualPtr::VirtualPtr(IPtr *de_ref) {
        this->dereference = de_ref;
    }
    unsigned int VirtualPtr::GetValue() {
        return 0;
    }
    IPtr* VirtualPtr::DeRef() {
        return this->dereference;
    }
    IPtr* VirtualPtr::SpawnRef() {
        return new VirtualPtr(this);
    }
    void VirtualPtr::SetRefPtr(CNOT::Ptr::IPtr* ptr) {
        std::cerr << "Memory error: Virtual cell is readonly." << std::endl;
        exit(1);
    }



}
#pragma clang diagnostic pop