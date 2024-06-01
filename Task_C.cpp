#include <iostream>
#include <stack>
#include <vector>

template <typename T>
long BS(std::vector<T>& a, long s, long e, T k) {
  if (e <= s) {
    return (a[s] > k) ? s : s + 1;
  }
  long m = (e + s) / 2;
  if (a[m] == k) {
    return m + 1;
  } else if (a[m] < k) {
    return BS(a, m + 1, e, k);
  } else {
    return BS(a, s, m, k);
  }
}

template <typename T>
void IS(std::vector<T>& a, long s, long e) {
  for (long i = s + 1; i < e; i++) {
    T k = a[i];
    long j = i - 1;
    long p = BS<T>(a, s, j, k);
    for (; j >= p; j--) {
      a[j + 1] = a[j];
    }
    a[p] = k;
  }
}

template <typename T>
T SF(std::vector<T> a, long l, long r) {
  if (r - l + 1 <= 5) {
    IS(a, l, r + 1);
    return a[(r + l) / 2];
  }
  std::vector<T> m;
  for (long i = l; i <= r; i += 5) {
    if (i + 5 > r) {
      IS(a, i, r + 1);
      m.push_back(a[(i + r) / 2]);
      break;
    }
    IS(a, i, i + 5);
    m.push_back(a[(i + i + 4) / 2]);
  }
  return SF(m, 0, m.size() - 1);
}

template <typename T>
long PP(std::vector<T>& a, long l, long r, T m) {
  while (l <= r) {
    for (; a[l] < m; ++l) {
    }
    for (; a[r] > m; --r) {
    }
    if (l >= r) {
      break;
    }
    std::swap(a[l++], a[r--]);
  }
  return r;
}

template <typename T>
void QS(std::vector<T>& a) {
  long s = a.size();
  if (s <= 256) {
    IS(a, 0, s);
    return;
  }
  std::stack<std::pair<long, long>> i_s;
  i_s.emplace(0, s - 1);
  while (!i_s.empty()) {
    long l = i_s.top().first;
    long r = i_s.top().second;
    i_s.pop();
    if (r <= l) {
      continue;
    }
    T p = SF(a, l, r);
    long pi = PP(a, l, r, p);
    if (pi - l + 1 <= 100) {
      IS(a, l, pi + 1);
    } else {
      i_s.emplace(l, pi + 1);
    }
    if (r - pi + 1 < 100) {
      IS(a, pi + 1, r + 1);
    } else {
      i_s.emplace(pi + 1, r);
    }
  }
}

int main() {
  long s;
  long long ph;
  std::cin >> s;
  std::vector<long long> a;
  for (long i = 0; i < s; i++) {
    std::cin >> ph;
    a.push_back(ph);
  }
  QS<long long>(a);
  for (long i = 0; i < s; i++) {
    if (i != s - 1) {
      std::cout << a[i] << ' ';
      continue;
    }
    std::cout << a[i] << '\n';
  }
  return 0;
}
