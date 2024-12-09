#include <vector>
#include <functional>
#include <iostream>

#include "candle.h"

// массив всех тестов, который мы заполняем в функции initTests
static std::vector<std::function<bool()>> tests;

// тест 1: Проверка, что точка внутри тела свечи
bool test1()
{
    Candle candle{ 0.0, 3.0, 1.0, 2.0 }; // open = 0.0, close = 3.0, body = (1.0, 2.0)
    return candle.body_contains(1.5); // внутри тела
}

// тест 2: Проверка, что точка на границе тела свечи (открытие)
bool test2()
{
    Candle candle{ 0.0, 3.0, 1.0, 2.0 };
    return candle.body_contains(1.0); // на границе тела (open)
}

// тест 3: Проверка, что точка на границе тела свечи (закрытие)
bool test3()
{
    Candle candle{ 0.0, 3.0, 1.0, 2.0 };
    return candle.body_contains(2.0); // на границе тела (close)
}

// тест 4: Проверка, что точка внутри тела и теней свечи
bool test4()
{
    Candle candle{ 0.0, 3.0, 1.0, 2.0 }; // open = 0.0, close = 3.0, body = (1.0, 2.0)
    return candle.contains(2.5); // внутри всей свечи
}

// тест 5: Проверка, что точка на границе теней свечи
bool test5()
{
    Candle candle{ 0.0, 3.0, 1.0, 2.0 };
    return candle.contains(1.0); // на границе низкой тени (low)
}

// тест 6: Проверка, что точка на границе теней свечи
bool test6()
{
    Candle candle{ 0.0, 3.0, 1.0, 2.0 };
    return candle.contains(3.0); // на границе высокой тени (high)
}

// тест 7: Проверка размера всей свечи, когда high и low равны
bool test1()
{
    Candle candle{ 0.0, 3.0, 3.0, 0.0 };
    return candle.full_size() == 0.0; // тени равны нулю
}

// тест 8: Проверка размера свечи с ненулевыми тенями
bool test2()
{
    Candle candle{ 1.0, 5.0, 0.0, 3.0 };
    return candle.full_size() == 5.0; // разница между high и low (5.0 - 0.0)
}

// тест 9: Проверка размера свечи, когда low больше, чем high
bool test3()
{
    Candle candle{ 3.0, 2.0, 5.0, 4.0 };
    return candle.full_size() == 3.0; // разница между high и low (5.0 - 2.0)
}

void initTests()
{
    tests.push_back(test1);
    tests.push_back(test2);
    tests.push_back(test3);
}

int launchTests()
{
    int total = 0;
    int passed = 0;

    for (const auto& test : tests)
    {
        std::cout << "test #" << (total + 1);
        if (test())
        {
            passed += 1;
            std::cout << " passed\n";
        }
        else
        {
            std::cout << " failed\n";
        }
        total += 1;
    }

    std::cout << "\ntests " << passed << "/" << total << " passed!" << std::endl;

    return total - passed;
}

int main()
{
    initTests();
    return launchTests();
}
