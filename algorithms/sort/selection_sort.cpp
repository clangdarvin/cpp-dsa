#include <cstddef>
#include <iostream>
#include <vector>

namespace {
void selectionSort(std::vector<int>& A) {
  // Selection sort repeatedly selects the smallest element from the
  // unsorted portion of the list and swaps it with the first element
  // of that unsorted portion. After each pass, the sorted portion
  // grows by one element until the entire list is sorted.

  // Worst-Case:    O(n^2)
  // Average-Case:  O(n^2)
  // Best-Case:     O(n^2)

  for (size_t i{0}; i < A.size() - 1; ++i) {
    size_t minimum{i};
    for (size_t j{i + 1}; j < A.size(); ++j) {
      if (A[j] < A[minimum]) {
        minimum = j;
      }
    }
    int temp{A[i]};
    A[i] = A[minimum];
    A[minimum] = temp;
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

  selectionSort(A);

  std::cout << "After: ";
  for (int num : A) {
    std::cout << num << ' ';
  }
  std::cout << '\n';
  return 0;
}
