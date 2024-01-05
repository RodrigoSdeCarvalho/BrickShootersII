#ifndef TEST_H
#define TEST_H

#include <utility>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <tuple>
#include <functional>
#include <string>

#include "Test/RESULT.h"
#include "Test/Function.h"

#define REMOVE_SPACES_BETWEEN_ARGS(...)                    \
    []() {                                                 \
        std::string result = #__VA_ARGS__;                 \
        for (size_t i = 0; i < result.size(); ++i) {       \
            if (result[i] == ',' && i + 1 < result.size() && result[i + 1] == ' ') { \
                result.erase(i + 1, 1);                    \
            }                                             \
        }                                                 \
        return result;                                     \
    }()

#define ARGS_TO_VECTOR(...)                                  \
    []() {                                                  \
        std::vector<std::string> result;                     \
        std::istringstream iss(REMOVE_SPACES_BETWEEN_ARGS(__VA_ARGS__)); \
        std::string token;                                   \
        while (std::getline(iss, token, ',')) {              \
            result.push_back(token);                         \
        }                                                   \
        return result;                                      \
    }()

#define TEST(...) \
    typedef std::vector<std::string> Strings; \
    typedef void (*FunctionPointer)(); \
    typedef std::vector<FunctionPointer> FunctionPointers; \
    typedef std::vector<Test::Function> Functions;  \
    Strings names = ARGS_TO_VECTOR(__VA_ARGS__); \
    FunctionPointers pointers = {__VA_ARGS__};\
    int length = names.size(); \
    Functions funcs;                      \
    for (int i = 0; i < length; ++i)          \
    {                                         \
        funcs.push_back(Test::Function(pointers[i], names[i])); \
    }             \
    Test::run::init(funcs) \

namespace Test
{
    class run
    {
    private:
        typedef std::vector<RESULT> Results;
        typedef std::vector<Function> Functions;

    public:
        static void init (Functions& functions);

    private:
        run(Functions& functions)
        {
            funcs = functions;
        }

        ~run() = default;

        void start();

        void handleResult(Function &func);

        RESULT getResult(Function &func);

        float getPassedTestsPercentage(Results& results);

    private:
        Functions funcs;
        Results results;
    };
}

constexpr void assert_that(bool statement, const char* message) {
    if (!statement) throw std::runtime_error{ message };
}

#endif //TEST_H