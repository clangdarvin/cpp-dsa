#include <cstddef>
#include <iostream>
#include <vector>
namespace {
void bubbleSort(std::vector<int>& A) {
  // Worst-case:    O(n^2)
  // Average-case:  O(n^2)
  // Best-case:     O(n)

  for (size_t i{0}; i < A.size(); ++i) {
    for (size_t j{0}; j < A.size() - 1; ++j) {
      if (A[j] > A[j + 1]) {
        int temp{A[j + 1]};
        A[j + 1] = A[j];
        A[j] = temp;
      }
    }
  }
}
}  // namespace

auto main() -> int {
  std::vector<int> A{30, 25, 20, 15, 10, 5, 2, 1};
  std::cout << "Before: ";
  for (int num : A) {
    std::cout << num << ' ';
  }
  std::cout << '\n';

  bubbleSort(A);

  std::cout << "After: ";
  for (int num : A) {
    std::cout << num << ' ';
  }
  std::cout << '\n';
  return 0;
}
