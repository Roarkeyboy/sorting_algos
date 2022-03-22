#include "array.hpp"

#include <random>     // mt19937 and uniform_int_distribution
#include <algorithm>  // generate
#include <iterator>   // begin, end, and ostream_iterator
#include <functional> // bind

std::vector<int> create_random_data(const size_t array_size) {
  std::random_device r;
  std::seed_seq      seed{r(), r(), r(), r(), r(), r(), r(), r()};
  std::mt19937       eng(seed); // a source of random data

  std::uniform_int_distribution<int> dist;
  std::vector<int> tmp(array_size);

  generate(begin(tmp), end(tmp), bind(dist, eng));
  return tmp;
}

void init_arrays(std::vector<std::vector<int>> & arrays, const size_t array_size) {
    std::vector<int> random_vector = create_random_data(array_size);
    for(int ii = 0; ii < 7; ii++) {
        std::vector<int> tmp;
        tmp.reserve(array_size);
        std::copy(random_vector.begin(), random_vector.end(), std::back_inserter(tmp));
        arrays.push_back(tmp);
    }
}