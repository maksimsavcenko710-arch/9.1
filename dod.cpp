#include "dod.h"
#include "var.h"

using namespace nsVar;

// наступний доданок = попередній * x^2 / n
void nsDod::dod()
{
    a *= x * x / n;
}