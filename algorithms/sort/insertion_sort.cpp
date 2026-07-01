#include <cstddef>
#include <iostream>
#include <vector>
namespace {
void insertionSort(std::vector<int>& A) {
  // Insertion Sort: Builds a sorted array one element at a time. It begins by
  // comparing the 2nd element with the 1st, swapping them if the 2nd is
  // smaller. Subsequent elements are then compared backward against the sorted
  // portion and inserted into their correct positions. Total passes: n-1

  // Worst-case:    O(n^2)
  // Average-case:  O(n^2)
  // Best-case:     O(n)

  for (size_t i{1}; i < A.size(); ++i) {
    for (size_t j{i}; j > 0; --j) {
      if (A[j] < A[j - 1]) {
        int temp{A[j - 1]};
        A[j - 1] = A[j];
        A[j] = temp;
      } else {
        break;
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

  insertionSort(A);

  std::cout << "After: ";
  for (int num : A) {
    std::cout << num << ' ';
  }
  std::cout << '\n';
  return 0;
}
