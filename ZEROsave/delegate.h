#pragma once 
#include <vector>
#include <functional>
#include <iostream>

template<typename... Args>
class Delegate {
public:
    using FuncType = std::function<void(Args...)>;

    void Add(FuncType func) {
        functions.push_back(func);
    }

    void Invoke(Args... args) {
        for (auto& func : functions) {
            func(args...);
        }
    }

private:
    std::vector<FuncType> functions;
};
