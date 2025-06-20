#pragma once
#include "thread.hpp" 
#include <chrono> // for milliseconds
#include "ifilter.h" // for IFilter

class MeasureTask : public OsWrapper::Thread<256U>
{
public:
  MeasureTask(std::chrono::milliseconds sampletime, IFilter& filter) : 
                            mFilter(filter), mSampletime(sampletime)
  {
  }; 
  
  void Execute() override;
private:
  IFilter& mFilter;
  std::chrono::milliseconds mSampletime;
};