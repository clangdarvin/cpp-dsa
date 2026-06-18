#include <cstddef>
#include <iostream>
#include <vector>

namespace {
int linearSearch(const std::vector<int>& A, int key) {
  // Worst-case:    O(n)
  // Average-case:  O(n)
  // Best-case:     O(1)

  for (std::size_t i{0}; i < A.size(); ++i) {
    if (A[i] == key) {
      return static_cast<int>(i);
    }
  }

  return -1;
}
}  // namespace

auto main() -> int {
  std::vector<int> A{30, 25, 20, 15, 10, 5, 2, 1};
  const int key{12};
  int result{linearSearch(A, key)};
  if (result != -1) {
    std::cout << "Key " << key << " found at index " << result << '\n';
  } else {
    std::cout << "Key " << key << " not found." << '\n';
  }
  return 0;
}
