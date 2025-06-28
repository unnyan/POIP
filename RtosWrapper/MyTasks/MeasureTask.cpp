#include "MeasureTask.hpp"
#include "adc.h"
#include <iostream>

void MeasureTask::Execute()
{
  Adc<std::uint32_t> adc;
  adc.TurnOn();
  for (;;)
  {
    adc.StartConversion();
    adc.WaitEndOfConvertion();
    const auto adcCode = adc.GetData();
    
    const std::uint32_t tsCal1Address = 0x1FFF7A2CU;
    const std::uint16_t tsCal1 = *reinterpret_cast<std::uint16_t*>(tsCal1Address);
    
    const std::uint32_t tsCal2Address = 0x1FFF7A2EU;
    const std::uint16_t tsCal2 = *reinterpret_cast<std::uint16_t*>(tsCal2Address);
    
    const auto k = (110.0f - 30.0f) / static_cast<float>(tsCal2 - tsCal1);
    const auto b = 110.0f - k * static_cast<float>(tsCal2);
    
    const auto temp = k*adcCode + b;
    const auto filteredTemp = mFilter.FilterValue(temp);
      
    std::cout << "Temperature: " << temp << std::endl;
    std::cout << "Filtered temperature: " << filteredTemp << std::endl;
    std::cout << "__________________" << std::endl;
    
    Sleep(mSampletime);
  }
};