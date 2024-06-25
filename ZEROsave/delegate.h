#pragma once 
#include <vector>
#include <functional>


template <typename... Args>
class Delegate {
public:
    // �Լ� ������ �߰� ���ø� �޼��� (���� �Լ� �Ǵ� ����)
    template <typename Function>
    void Add(Function func) {
        invokers_.emplace_back(func);
    }

    // ��� �Լ� ������ �߰� ���ø� �޼���
    template <typename Object, typename Function>
    void Add(Object* obj, Function func) {
        invokers_.emplace_back([=](Args... args) { (obj->*func)(args...); });
    }

    // ��� ��ϵ� �Լ� ȣ��
    void operator()(Args... args) const {
        for (const auto& invoker : invokers_) {
            invoker(args...);
        }
    }

private:
    std::vector<std::function<void(Args...)>> invokers_;  // �پ��� �μ��� �޴� �Լ� ��ü�� ����
};
