// tests_9_1.cpp
// Unit-тести Google Test для Завдання 9.1 (ряд Тейлора, варіант 23: e^(x^2))
// Тестуються модулі nsDod::dod() та nsSum::sum(); дані передаються
// через глобальні змінні простору імен nsVar.
#include <gtest/gtest.h>
#include <cmath>

#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace nsVar;

// ---------- dod(): рекурентне обчислення доданка a *= x^2 / n ----------

TEST(DodTest, FirstTermAfterOne)
{
    x = 2; n = 1; a = 1;
    nsDod::dod();
    EXPECT_DOUBLE_EQ(a, 4.0);          // 1 * 2^2 / 1
}

TEST(DodTest, GeneralStep)
{
    x = 3; n = 2; a = 1;
    nsDod::dod();
    EXPECT_DOUBLE_EQ(a, 4.5);          // 1 * 3^2 / 2
}

TEST(DodTest, ZeroArgumentGivesZeroTerm)
{
    x = 0; n = 5; a = 7;
    nsDod::dod();
    EXPECT_DOUBLE_EQ(a, 0.0);
}

TEST(DodTest, NegativeXGivesSameTermAsPositive)
{
    x = -3; n = 2; a = 1;
    nsDod::dod();
    EXPECT_DOUBLE_EQ(a, 4.5);          // x входить у квадраті
}

// ---------- sum(): сума ряду e^(x^2) ----------

TEST(SumTest, ZeroArgument)
{
    x = 0; e = 1e-6;
    nsSum::sum();
    EXPECT_DOUBLE_EQ(s, 1.0);          // e^0 = 1
    EXPECT_EQ(n, 1);                   // додано один доданок після першого
}

TEST(SumTest, MatchesLibraryExp)
{
    const double xs[] = { -1.5, -1.0, -0.5, 0.3, 0.5, 1.0, 1.5, 2.0 };
    e = 1e-9;
    for (double v : xs) {
        x = v;
        nsSum::sum();
        EXPECT_NEAR(s, std::exp(v * v), 1e-6) << "x = " << v;
    }
}

TEST(SumTest, ResultIsEvenFunctionOfX)
{
    e = 1e-8;
    x = 1.2; nsSum::sum(); const double plus = s;
    x = -1.2; nsSum::sum(); const double minus = s;
    EXPECT_DOUBLE_EQ(plus, minus);
}

TEST(SumTest, HigherPrecisionNeedsMoreTerms)
{
    x = 1.0;
    e = 1e-3; nsSum::sum(); const int termsLow = n;
    e = 1e-9; nsSum::sum(); const int termsHigh = n;
    EXPECT_GT(termsHigh, termsLow);
}

TEST(SumTest, CanBeCalledRepeatedly)
{
    // sum() сама скидає n, a, s, тому повторний виклик дає той самий результат
    x = 1.0; e = 1e-8;
    nsSum::sum(); const double first = s; const int n1 = n;
    nsSum::sum();
    EXPECT_DOUBLE_EQ(s, first);
    EXPECT_EQ(n, n1);
}
