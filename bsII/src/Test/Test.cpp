#include "Test/Test.h"

namespace Test
{
    void run::init(Test::run::Functions &functions)
    {
        run test = run(functions);
        test.start();
    }

    void run::start()
    {
        std::cout << "Running all tests: " << std::endl << std::endl;

        for (auto func : funcs)
        {
            handleResult(func);
        }

        std::cout << "Passed " << getPassedTestsPercentage(results) * 100 << "% of tests." << std::endl;
    }

    void run::handleResult(Test::Function &func)
    {
        RESULT result = getResult(func);
        results.push_back(result);

        if (result)
        {
            std::cout << "Test for " << func.name << " passed." << std::endl << std::endl;
        }
        else
        {
            std::cout << "Test for " << func.name << " failed." << std::endl << std::endl;
        }
    }

    Test::RESULT run::getResult(Test::Function &func)
    {
        using Test::RESULT;

        try
        {
            std::cout << "Running test for " << func.name << "():" << std::endl;
            func.call();
            return RESULT::SUCCESS();
        }
        catch (const std::exception &ex)
        {
            std::cerr << "Error in " << func.name << ex.what() << std::endl;
            return RESULT::FAILURE();
        }
    }

    float run::getPassedTestsPercentage(Test::run::Results &results)
    {
        {
            int passedTests = 0;
            for (auto result : results)
            {
                if (result)
                {
                    passedTests++;
                }
            }

            return (float)passedTests / results.size();
        }
    }
}
