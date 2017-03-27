#include "bubble_sort.h"

void bubble_sort::sort(std::vector<int>& vec)
{
  for(size_t end = vec.size(); end > 0; --end)
  {
    for(size_t i = 1; i < end; ++i)
    {
      if(vec[i - 1] >= vec[i])
      {
        std::swap(vec[i - 1], vec[i]);
      }
    }
  }
}
