#include <iostream>
#include <vector>
namespace {
int partition(std::vector<int>& A, int p, int r) {
  // Folllows a Divide-and-Conquer Paradigm

  // Worst-case:    O(n^2)
  // Average-case:  O(n log(n))
  // Best-case:     O(n log(n))

  // compare j, pivot: swap i,j
  // swap i+1, high

  int q{p};
  for (int u{p}; u < r; ++u) {
    if (A[u] <= A[r]) {
      int temp{A[q]};
      A[q] = A[u];
      A[u] = temp;
      ++q;
    }
  }
  int temp{A[q]};
  A[q] = A[r];
  A[r] = temp;
  return q;
}

void quickSort(std::vector<int>& A, int p, int r) {
  if (p >= r) {
    return;
  }
  int q{partition(A, p, r)};
  quickSort(A, p, q - 1);
  quickSort(A, q + 1, r);
}
}  // namespace

auto main() -> int {
  std::vector<int> A{30, 25, 20, 15, 10, 5, 2, 1};
  std::cout << "Before: ";
  for (int num : A) {
    std::cout << num << ' ';
  }
  std::cout << '\n';

  quickSort(A, 0, A.size() - 1);

  std::cout << "After: ";
  for (int num : A) {
    std::cout << num << ' ';
  }
  std::cout << '\n';
  return 0;
}
