#include <iostream>

using namespace std;

bool BinarySearch(const int* begin, const int* end, int target) {
  const int* left = begin;
  const int* right = end - 1;

  while (left <= right) {
    const int* mid = left + (right - left) / 2;
    if (*mid == target) {
      return true;
    }
    if (*mid < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return false;
}

int main() {
  int number;
  cin >> number;

  // read array elements
  int* arr = new int[number];
  for (int i = 0; i < number; ++i) {
    cin >> arr[i];
  }

  int queries;
  cin >> queries;

  // perform binary search queries
  for (int i = 0; i < queries; ++i) {
    int start;
    int end;
    int target;
    cin >> start >> end >> target;

    // check if target exists in the specified range
    if (BinarySearch(&arr[start], &arr[end], target)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  delete[] arr;  // deallocate memory

  return 0;
}
