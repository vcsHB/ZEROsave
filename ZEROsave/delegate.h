#pragma once 
#include <vector>
#include <functional>


template <typename... Args>
class Delegate {
public:
    // 함수 포인터 추가 템플릿 메서드 (전역 함수 또는 람다)
    template <typename Function>
    void Add(Function func) {
        invokers_.emplace_back(func);
    }

    // 멤버 함수 포인터 추가 템플릿 메서드
    template <typename Object, typename Function>
    void Add(Object* obj, Function func) {
        invokers_.emplace_back([=](Args... args) { (obj->*func)(args...); });
    }

    // 모든 등록된 함수 호출
    void operator()(Args... args) const {
        for (const auto& invoker : invokers_) {
            invoker(args...);
        }
    }

private:
    std::vector<std::function<void(Args...)>> invokers_;  // 다양한 인수를 받는 함수 객체를 저장
};
