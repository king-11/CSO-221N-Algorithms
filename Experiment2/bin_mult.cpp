/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-10-14 14:56:31
 * @ Modified by: Target_X
 * @ Modified time: 2021-01-19 10:55:15
 * @ Description:
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repA(i, a, n) for (int i = a; i <= (n); ++i)
#define repD(i, a, n) for (int i = a; i >= (n); --i)
#define tr(a, x) for (auto &a : x)
#define all(c) c.begin(), c.end()

#define int long long
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define f first
#define s second
#define sz(a) int((a).size())
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c), x) != c.end())

#define vi vector<int>
#define si set<int>
#define endl "\n"
#define pii pair<int, int>
#define minq priority_queue<int, vector<int>, greater<int>>
#define mem(a, val) memset(a, val, sizeof(a))
#define scani(x) scanf("%lld", &x)
#define scani2(x, y) scanf("%lld %lld", &x, &y)
#define scani3(x, y, z) scanf("%lld %lld %lld", &x, &y, &z);
#define print(x) printf("%lld ", x)
#define println(x) printf("%lld\n", x)
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MOD 1000000009

using namespace std;

// available snippets
// phi, seive, exponentiation, gcd, extended euclid, dfs, path lca, factorization
// kmp search, segtree, dsu, ordered set, power2

using namespace std;
using namespace __gnu_pbds;

const int N = 3e5 + 11;

int32_t main()
{
  SpeedForce;

  string s1, s2;
  cin >> s1 >> s2;
  int n = s1.length();
  int m = s2.length();

  if (n < m)
    swap(n, m), swap(s1, s2);

  reverse(s2.begin(), s2.end());

  for (int i = 0; i < n - m; i++)
    s2.push_back('0');
  reverse(s2.begin(), s2.end());

  vector<int> v1, v2;
  for (auto i : s1)
  {
    v1.push_back(i - '0');
  }
  for (auto i : s2)
  {
    v2.push_back(i - '0');
  }

  auto brute = [&](vector<int> v1, vector<int> v2) {
    int n = 2 * v1.size();
    vector<int> res(n + 1);
    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());
    for (int i = 0; i < v1.size(); i++)
    {
      for (int j = 0; j < v2.size(); j++)
      {
        res[i + j] += v1[i] & v2[j];
      }
    }
    for (int i = 0; i < n; i++)
    {
      int x = res[i];
      res[i] = x % 2;
      res[i + 1] += x / 2;
    }
    while (res.size() > 1 && res.back() == 0)
      res.pop_back();
    reverse(res.begin(), res.end());
    return res;
  };
  auto res = brute(v1, v2);
  for (int i = 0; i < res.size(); i++)
    cout << res[i];
  cout << endl;
}
