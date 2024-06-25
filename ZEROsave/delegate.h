#pragma once
class delegate
{
public:
    delegate() : objectPtr(0), subPtr(0)
    {}

    template <class T, void (T::* TMethod)(int) >
    void bind(T* objectPtr)
    {
        this->objectPtr = objectPtr;
        this->subPtr = &methodStub<T, TMethod>; // methodStub �����Ͱ� �����
    }
    void operator () (int a1) const
    {
        return (*subPtr)(objectPtr, a1);
    }

private:
    typedef void (*subType) (void* objectPtr, int);

    void* objectPtr; // ȣ���� ��ü
    subType  subPtr;    // ����Լ� ������ �ִ� �޼�

    // methodStub�� ȣ��Ǹ� objectPtr�� ���� Ÿ������ �����ϰ�  TMethod�� ����� ����Լ��� ȣ��
    template < class T, void (T::* TMethod) (int) >
    static void methodStub(void* objectPtr, int a1)
    {
        T* p = static_cast<T*>(objectPtr);
        return (p->*TMethod)(a1);
    }
};
