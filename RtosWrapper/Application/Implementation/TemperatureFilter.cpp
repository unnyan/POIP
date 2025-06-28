#include "TemperatureFilter.h"

TemperatureFilter::TemperatureFilter()
    : buffer{}, index(0), count(0)
{
}

float TemperatureFilter::FilterValue(float value)
{
    buffer[index] = value;
    index = (index + 1) % windowSize;
    if (count < windowSize) ++count;

    float sum = 0.0f;
    for (int i = 0; i < count; ++i)
    {
        sum += buffer[i];
    }

    return sum / count;
}
