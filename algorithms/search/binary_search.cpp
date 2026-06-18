#include <cstddef>
#include <iostream>
#include <vector>
namespace {
int binarySearch(const std::vector<int>& a, int key) {
  // Worst-case:    O(log n)
  // Average-case:  O(log n)
  // Best-case:     O(1)

  int low = 0;
  int high = static_cast<int>(a.size()) - 1;

  while (low <= high) {
    int mid = low + ((high - low) / 2);

    if (a[mid] == key) {
      return mid;
    }

    if (a[mid] > key) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return -1;
}

}  // namespace
auto main() -> int {
  std::vector<int> A{1, 2, 5, 10, 15, 20, 25, 30};
  int key{12};
  int result{binarySearch(A, key)};
  if (result != -1) {
    std::cout << "Key " << key << " found at index " << result << '\n';
  } else {
    std::cout << "Key " << key << " not found." << '\n';
  }
  return 0;
}
