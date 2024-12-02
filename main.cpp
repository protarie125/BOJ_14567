#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;
using vvl = vector<vl>;

ll N, M;
vvl adj;
vl prep;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> N >> M;
  adj = vvl(N + 1, vl{});
  prep = vl(N + 1, 0);
  for (auto i = 0; i < M; ++i) {
    ll A, B;
    cin >> A >> B;

    adj[A].push_back(B);
    prep[B] += 1;
  }

  vl dist(N + 1, 1);
  queue<ll> Q{};
  for (auto i = 1; i <= N; ++i) {
    if (prep[i] == 0) {
      Q.push(i);
      dist[i] = 1;
    }
  }

  while (!Q.empty()) {
    auto f = Q.front();
    Q.pop();

    for (const auto& n : adj[f]) {
      if (prep[n] == 0) continue;

      prep[n] -= 1;

      dist[n] = max(dist[n], dist[f] + 1);
      if (prep[n] == 0) {
        Q.push(n);
      }
    }
  }

  for (auto i = 1; i <= N; ++i) {
    cout << dist[i] << ' ';
  }

  return 0;
}