#include <iostream>
#include <vector>
namespace {

void Merge(std::vector<int>& A, int p, int q, int r) {
  int n_l{q - p + 1};
  int n_r{r - q};
  std::vector<int> L(n_l);
  std::vector<int> R(n_r);

  for (int i{0}; i < n_l; ++i) {
    L[i] = A[p + i];
  }

  for (int j{0}; j < n_r; ++j) {
    R[j] = A[q + 1 + j];
  }

  int i{0};
  int j{0};
  int k{p};

  while (i < n_l && j < n_r) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      ++i;
    } else {
      A[k] = R[j];
      ++j;
    }
    ++k;
  }

  while (i < n_l) {
    A[k] = L[i];
    ++i;
    ++k;
  }

  while (j < n_r) {
    A[k] = R[j];
    ++j;
    ++k;
  }
}

void MergeSort(std::vector<int>& A, int p, int r) {
  // Folllows a Divide-and-Conquer Paradigm
  // Does not sort array in place: creates a copy

  // Worst-case:    O(n log(n))
  // Average-case:  O(n log(n))
  // Best-case:     O(n log(n))

  // Base Case
  if (p >= r) {
    return;
  }

  int q{(p + r) / 2};
  MergeSort(A, p, q);
  MergeSort(A, q + 1, r);
  Merge(A, p, q, r);
}

}  // namespace

auto main() -> int {
  std::vector<int> A{30, 25, 20, 15, 10, 5, 2, 1};
  std::cout << "Before: ";
  for (int num : A) {
    std::cout << num << ' ';
  }
  std::cout << '\n';

  MergeSort(A, 0, A.size() - 1);

  std::cout << "After: ";
  for (int num : A) {
    std::cout << num << ' ';
  }
  std::cout << '\n';
  return 0;
}
