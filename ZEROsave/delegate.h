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
        this->subPtr = &methodStub<T, TMethod>; // methodStub 포인터가 저장됨
    }
    void operator () (int a1) const
    {
        return (*subPtr)(objectPtr, a1);
    }

private:
    typedef void (*subType) (void* objectPtr, int);

    void* objectPtr; // 호출대상 객체
    subType  subPtr;    // 멤버함수 정보가 있는 메소

    // methodStub가 호출되면 objectPtr을 원래 타임으로 변경하고  TMethod에 저장된 멤버함수를 호출
    template < class T, void (T::* TMethod) (int) >
    static void methodStub(void* objectPtr, int a1)
    {
        T* p = static_cast<T*>(objectPtr);
        return (p->*TMethod)(a1);
    }
};
