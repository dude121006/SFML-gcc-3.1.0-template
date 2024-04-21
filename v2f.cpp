#include "v2f.h"

void v2f::Negate()
{
    x = -x;
    y = -y;
}

void v2f::MakeUnitVector()
{
    float mag = std::sqrt(pow(x, 2) + pow(y, 2));
    if (mag >= std::numeric_limits<float>::epsilon())
    {
        x /= mag;
        y /= mag;
    }
    else
    {
        x = 0.0f;
        y = 0.0f;
    }
}

