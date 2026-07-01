#include <deque>
#include <iostream>
#include <optional>

class Queue {
 public:
  Queue() = default;

  void enqueue(int item) { m_items.push_back(item); }

  [[nodiscard]] std::optional<int> dequeue() {
    if (m_items.empty()) {
      return std::nullopt;
    }

    int front{m_items.front()};
    m_items.pop_front();
    return front;
  }

  [[nodiscard]] std::optional<int> peek() const {
    if (m_items.empty()) {
      return std::nullopt;
    }

    return m_items.front();
  }

  [[nodiscard]] std::optional<int> rear() const {
    if (m_items.empty()) {
      return std::nullopt;
    }

    return m_items.back();
  }

  [[nodiscard]] bool isEmpty() const { return m_items.empty(); }

  [[nodiscard]] std::size_t size() const { return m_items.size(); }

 private:
  std::deque<int> m_items;
};

auto main() -> int {
  Queue q{};

  q.enqueue(100);
  q.enqueue(200);
  q.enqueue(300);
  q.enqueue(400);

  if (auto front = q.peek()) {
    std::cout << "Front: " << *front << '\n';
  }

  if (auto back = q.rear()) {
    std::cout << "Rear: " << *back << '\n';
  }

  if (auto removed = q.dequeue()) {
    std::cout << "Dequeued: " << *removed << '\n';
  }

  if (auto front = q.peek()) {
    std::cout << "Front: " << *front << '\n';
  }

  if (auto back = q.rear()) {
    std::cout << "Rear: " << *back << '\n';
  }

  std::cout << "Size: " << q.size() << '\n';

  return 0;
}
