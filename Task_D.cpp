#include <iostream>
#include <limits>
#include <stack>
#include <string>

int main() {
  int M;
  std::cin >> M;

  std::stack<int> IL;
  int MI = std::numeric_limits<int>::max();

  for (int i = 0; i < M; ++i) {
    std::string command;
    std::cin >> command;

    if (command == "enqueue") {
      int n;
      std::cin >> n;
      IL.push(n);
      MI = std::min(MI, n);
      std::cout << "ok\n";
    } else if (command == "dequeue") {
      if (!IL.empty()) {
        int FI = IL.top();
        IL.pop();
        if (FI == MI) {
          MI = std::numeric_limits<int>::max();
          std::stack<int> TS = IL;
          while (!TS.empty()) {
            MI = std::min(MI, TS.top());
            TS.pop();
          }
        }
        std::cout << FI << "\n";
      } else {
        std::cout << "error\n";
      }
    } else if (command == "front") {
      if (!IL.empty()) {
        std::cout << IL.top() << "\n";
      } else {
        std::cout << "error\n";
      }
    } else if (command == "size") {
      std::cout << IL.size() << "\n";
    } else if (command == "clear") {
      while (!IL.empty()) {
        IL.pop();
      }
      MI = std::numeric_limits<int>::max();
      std::cout << "ok\n";
    } else if (command == "min") {
      if (!IL.empty()) {
        std::cout << MI << "\n";
      } else {
        std::cout << "error\n";
      }
    }
  }

  return 0;
}
