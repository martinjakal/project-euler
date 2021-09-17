#include "MathPackage.hpp"

namespace math {

int factorial(int number)
{
    return number == 0 ? 1 : number * factorial(number - 1);
}

} // namespace math
