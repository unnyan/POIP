#pragma once

class IFilter
{
public:
  virtual float FilterValue(float value) = 0;
};