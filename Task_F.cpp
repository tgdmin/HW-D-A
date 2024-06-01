#include <cstdint>
#include <iostream>
#include <vector>

uint64_t findMax(const std::vector<uint64_t>& arr) {
  uint64_t maxNum = arr[0];
  for (uint64_t num : arr) {
    if (num > maxNum) {
      maxNum = num;
    }
  }
  return maxNum;
}

void countingSort(std::vector<uint64_t>& arr, int exp) {
  const int radix = 256;
  std::vector<uint64_t> output(arr.size());
  std::vector<int> count(radix, 0);

  for (uint64_t num : arr) {
    int index = (num >> (8 * exp)) & 0xFF;
    count[index]++;
  }

  for (int i = 1; i < radix; ++i) {
    count[i] += count[i - 1];
  }

  for (int i = arr.size() - 1; i >= 0; --i) {
    int index = (arr[i] >> (8 * exp)) & 0xFF;
    output[count[index] - 1] = arr[i];
    count[index]--;
  }

  for (size_t i = 0; i < arr.size(); ++i) {
    arr[i] = output[i];
  }
}

void radixSort(std::vector<uint64_t>& arr) {
  uint64_t maxNum = findMax(arr);

  int maxDigits = 0;
  while (maxNum > 0) {
    maxNum >>= 8;
    maxDigits++;
  }

  for (int exp = 0; exp < maxDigits; ++exp) {
    countingSort(arr, exp);
  }
}

int main() {
  int N;
  std::cin >> N;
  std::vector<uint64_t> arr(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> arr[i];
  }

  radixSort(arr);

  for (uint64_t num : arr) {
    std::cout << num << std::endl;
  }

  return 0;
}
