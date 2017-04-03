#pragma once

#include "sorter.h"

class bubble_sort : public sorter<int>
{
public:
  virtual void sort(std::vector<int>& vec) override;
};
