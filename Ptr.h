//
// Created by pavel on 1/30/18.
//

#ifndef CNOT_PTR_H
#define CNOT_PTR_H

namespace CNOT::Ptr {

    class IPtr {
    public:
        virtual unsigned int GetValue() = 0;

        virtual IPtr *DeRef() = 0;

        virtual IPtr *SpawnRef() = 0;

        virtual void SetRefPtr(IPtr* ptr) = 0;

        virtual ~IPtr() = default;
    };

    class RealPtr : public IPtr {
    private:
        unsigned int value;
    public:
        explicit RealPtr(unsigned int val);

        unsigned int GetValue() override;
        IPtr *DeRef() override;
        IPtr *SpawnRef() override;
        void SetRefPtr(IPtr* ptr) override;

        ~RealPtr() override = default;
    };

    class VirtualPtr : public IPtr {
    private:
        IPtr *dereference;
    public:
        explicit VirtualPtr(IPtr* de_ref);

        unsigned int GetValue() override;
        IPtr *DeRef() override;
        IPtr *SpawnRef() override;
        void SetRefPtr(IPtr* ptr) override;

        ~VirtualPtr() override = default;
    };
}
#endif //CNOT_PTR_H