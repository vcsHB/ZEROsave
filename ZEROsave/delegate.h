#pragma once 
#include <vector>
#include <functional>

class delegate {
public:
    // ���ø� �޼���: �Ϲ� �Լ� ������ �߰�
    template <typename Function>
    void Add(Function func) {
        invokers_.emplace_back(func);
    }

    // ���ø� �޼���: ��� �Լ� ������ �߰�
    template <typename Object, typename Function>
    void Add(Object* obj, Function func) {
        invokers_.emplace_back([=](int arg) { (obj->*func)(arg); });
    }

    // �Լ� ȣ��: ��ϵ� ��� �Լ� ȣ��
    void operator()(int arg) const {
        for (const auto& invoker : invokers_) {
            invoker(arg);
        }
    }

private:
    std::vector<std::function<void(int)>> invokers_;  // �Լ� ��ü�� �����ϴ� ����
};
