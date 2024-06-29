#pragma once 
#include <vector>
#include <functional>

class delegate {
public:
    // 템플릿 메서드: 일반 함수 포인터 추가
    template <typename Function>
    void Add(Function func) {
        invokers_.emplace_back(func);
    }

    // 템플릿 메서드: 멤버 함수 포인터 추가
    template <typename Object, typename Function>
    void Add(Object* obj, Function func) {
        invokers_.emplace_back([=](int arg) { (obj->*func)(arg); });
    }

    // 함수 호출: 등록된 모든 함수 호출
    void operator()(int arg) const {
        for (const auto& invoker : invokers_) {
            invoker(arg);
        }
    }

private:
    std::vector<std::function<void(int)>> invokers_;  // 함수 객체를 저장하는 벡터
};
