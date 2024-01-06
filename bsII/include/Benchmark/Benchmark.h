#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <iostream>
#include <chrono>
#include <functional>
#include <utility>
#include <type_traits>

#include "Debug/Info.h"

/**
 * @brief Benchmark a function.
 * @details This function will benchmark a function and print the time taken to execute it.
 * @tparam RetT The return type of the function. Must be specified explicitly.
 * @tparam Func The function to benchmark, DONT CALL IT, just pass it as a parameter.
 * @tparam Args The arguments of the function. Leave empty if the function has no arguments.
 */
#define BENCHMARK(returnType, func, ...) \
    Benchmark::BENCHMARK_SEL<returnType>(#func, func, ##__VA_ARGS__)

class Benchmark {

struct VoidValueTag {};
struct ReturnValueTag {};

public:
    template<typename RetT, typename Func, typename... Args>
    static RetT BENCHMARK_SEL(std::string &&funcName, Func &&func, Args &&... args) {
        if constexpr (std::is_void_v<decltype(func(std::forward<Args>(args)...))>) {
            return getFunctionExecutionTime(std::forward<Func>(func), funcName, VoidValueTag{},
                                            std::forward<Args>(args)...);
        } else {
            return getFunctionExecutionTime(std::forward<Func>(func), funcName, ReturnValueTag{},
                                            std::forward<Args>(args)...);
        }
    }

    template<typename Func, typename... Args>
    static auto getFunctionExecutionTime(Func &&func, std::string& funcName, ReturnValueTag, Args &&... args) {
        auto start = std::chrono::high_resolution_clock::now();
        auto ret = func(std::forward<Args>(args)...);
        auto end = std::chrono::high_resolution_clock::now();
        Debug::Info<Benchmark, SHOW>() << "DEBUG TRACE (Benchmark): " << "Time taken by " << funcName << " is " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms." << Debug::endl;
        return ret;
    }

    template<typename Func, typename... Args>
    static auto getFunctionExecutionTime(Func &&func, std::string& funcName, VoidValueTag, Args &&... args)
    -> decltype(func(std::forward<Args>(args)...), void()) {
        auto start = std::chrono::high_resolution_clock::now();
        func(std::forward<Args>(args)...);
        auto end = std::chrono::high_resolution_clock::now();
        Debug::Info<Benchmark, SHOW>() << "DEBUG TRACE (Benchmark): " << "Time taken by " << funcName << " is " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms." << Debug::endl;
    }
};

#endif //BENCHMARK_H
