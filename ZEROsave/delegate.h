#pragma once 
#include <vector>
#include <functional>
#include <iostream>

template<typename... Args>
class Delegate {
public:
    using FunctionType = void(*)(Args...);

    void Add(FunctionType func) {
        functions.push_back(func);
    }

    void Invoke(Args... args) {
        for (auto& func : functions) {
            func(args...);
        }
    }

private:
    std::vector<FunctionType> functions;
};