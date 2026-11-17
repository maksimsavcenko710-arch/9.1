#include <cmath>
#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace nsDod;
using namespace nsVar;

// сума ряду з точністю e
void nsSum::sum()
{
    n = 0;
    a = 1; // перший доданок a0 = 1
    s = a;
    do
    {
        n++;
        dod();
        s += a;
    } while (std::fabs(a) > e);
}