#include <deque>
#include <optional>
class LinkedList {
 private:
  struct Node {
    int value;
    Node* next;

    Node(int val, Node* n = nullptr) : value(val), next(n) {}
  };

  Node* m_head = nullptr;
  std::deque<int> m_items;

 public:
  void enqueue(int item) { m_items.push_front(item); }
  void dequeue() { m_items.pop_front(); }
  [[nodiscard]] std::optional<int> peek() const {
    if (m_items.empty()) {
      return std::nullopt;
    }
    return m_items.back();
  }
};

auto main() -> int { return 0; }
