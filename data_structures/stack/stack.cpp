#include <iostream>
#include <optional>
#include <vector>

namespace {
class Stack {
 public:
  Stack() = default;

  void push(int item) { m_items.push_back(item); }

  bool pop(int& value) {
    if (m_items.empty()) {
      return false;
    }

    value = m_items.back();
    m_items.pop_back();
    return true;
  }

  [[nodiscard]] std::optional<int> peek() const {
    if (m_items.empty()) {
      return std::nullopt;
    }
    return m_items.back();
  }

  [[nodiscard]] std::size_t size() const { return m_items.size(); }
  [[nodiscard]] bool isEmpty() const { return m_items.empty(); }

 private:
  std::vector<int> m_items;
};
}  // namespace

auto main() -> int {
  Stack s{};
  s.push(10);
  s.push(20);

  if (auto peek = s.peek(); peek.has_value()) {
    std::cout << "Peek: " << peek.value() << '\n';
  }

  s.push(30);
  std::cout << "Size: " << s.size() << '\n';

  int value{};
  if (s.pop(value)) {
    std::cout << "Popped Value: " << value << '\n';
  }

  if (auto peek = s.peek(); peek.has_value()) {
    std::cout << "Current Peek: " << peek.value() << '\n';
  }

  std::cout << "Size: " << s.size() << '\n';
  std::cout << "Is Stack empty? " << std::boolalpha << s.isEmpty() << '\n';

  return 0;
}
