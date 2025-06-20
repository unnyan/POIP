#ifndef TEMPERATURE_FILTER_H
#define TEMPERATURE_FILTER_H

#include "ifilter.h"

class TemperatureFilter : public IFilter
{
public:
    TemperatureFilter();

    float FilterValue(float value) override;

private:
    static constexpr int windowSize = 10;
    float buffer[windowSize];
    int index;
    int count;
};

#endif // TEMPERATURE_FILTER_H
