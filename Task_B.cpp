#include <iostream>
#include <vector>

std::vector<int> calculate_A(int n, int A0, int A1) {
  std::vector<int> A;
  A.push_back(A0);
  A.push_back(A1);
  for (int i = 2; i < n; ++i) {
    int Ai = (A[i - 1] * 123 + A[i - 2] * 45) % (10000000 + 4321);
    A.push_back(Ai);
  }
  return A;
}

int partition(std::vector<int>& A, int low, int high) {
  int pivot = A[high];
  int i = low - 1;
  for (int j = low; j < high; ++j) {
    if (A[j] <= pivot) {
      i++;
      std::swap(A[i], A[j]);
    }
  }
  std::swap(A[i + 1], A[high]);
  return i + 1;
}

int quick_select(std::vector<int>& A, int low, int high, int k) {
  if (low == high) {
    return A[low];
  }
  int pivot_index = partition(A, low, high);
  if (k == pivot_index) {
    return A[k];
  } else if (k < pivot_index) {
    return quick_select(A, low, pivot_index - 1, k);
  } else {
    return quick_select(A, pivot_index + 1, high, k);
  }
}

int k_order_statistic(int n, int k, int A0, int A1) {
  std::vector<int> A = calculate_A(n, A0, A1);
  return quick_select(A, 0, n - 1, k - 1);
}

int main() {
  int n, k, A0, A1;
  std::cin >> n >> k >> A0 >> A1;
  std::cout << k_order_statistic(n, k, A0, A1) << std::endl;
  return 0;
}
