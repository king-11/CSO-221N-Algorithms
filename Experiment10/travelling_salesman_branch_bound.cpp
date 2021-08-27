/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-02-08 10:46:34
 * @ Modified by: Target_X
 * @ Modified time: 2021-02-08 10:50:10
 * @ Description: Jai Shree Ram
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repA(i, a, n) for (int i = a; i <= (n); ++i)
#define repD(i, a, n) for (int i = a; i >= (n); --i)
#define tr(a, x) for (auto &a : x)
#define all(c) c.begin(), c.end()

#define int long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define f first
#define s second
#define sz(a) int((a).size())
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c), x) != c.end())

#define vi vector<int>
#define vii vector<pii>
#define si set<int>
#define usi unordered_set<int>
#define mi map<int, int>
#define umi unordered_map<int, int>
#define minq priority_queue<int, vector<int>, greater<int>>
#define maxq priority_queue<int, vector<int>, less<int>>
#define endl "\n"
#define scani(x) scanf("%lld", &x)
#define scani2(x, y) scanf("%lld %lld", &x, &y)
#define scani3(x, y, z) scanf("%lld %lld %lld", &x, &y, &z);
#define print(x) printf("%lld ", x)
#define println(x) printf("%lld\n", x)
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MOD 1000000009

// available snippets
// phi, seive, exponentiation, gcd, extended euclid, dfs, path lca, factorization
// kmp search, segtree, dsu, ordered set, power2

using namespace std;
using namespace __gnu_pbds;

template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &a)
{
  in >> a.f >> a.s;
  return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> a)
{
  out << a.f << " " << a.s;
  return out;
}
template <typename T, typename T1>
T maxs(T &a, T1 b)
{
  if (b > a)
    a = b;
  return a;
}
template <typename T, typename T1>
T mins(T &a, T1 b)
{
  if (b < a)
    a = b;
  return a;
}

const int N = 3e5 + 11;
const int INF = 1LL << 60;

void solve()
{
  int n; cin >> n;
  vector<vector<int>>dis(n,vector<int>(n));

  for(int i = 0; i < n; i++){
   for(int j = 0 ; j < n; j++){
    cin >> dis[i][j];
   }
  }

  int best = INF;
  vector<int>path;

  auto get = [&](int u,int k){
   vector<int>d;
   for(int i = 0; i < n; i++){
    if(i!=u){
     d.push_back(dis[i][u]);
    }
   }
   sort(d.begin(),d.end());
   return d[k];
  };

  int curr_bound = 0;

  for(int i = 0; i < n; i++){
   curr_bound += get(i,0) + get(i,1);
  }
  curr_bound = (curr_bound + 1)/2;

  vector<int>vis(n+1);
  vector<int>t = {0};
  vis[0] = 1;
  function<void(int,int,int)>dfs = [&](int i,int curr_bound,int cost){
   if(i == n){
    cost += dis[t.back()][0];
    if(best > cost){
     path = t;
     best = cost;
    }
   }
   else{
    for(int j = 0; j < n; j++){
     if(!vis[j]){
      int temp = curr_bound;
      int new_cost = cost + dis[t.back()][j];


      if(i == 1){
       temp -= (get(t.back(),0) + get(j,0))/2;
      }
      else{
       temp -= (get(t.back(),1) + get(j,0))/2;
      }

      if(temp + new_cost < best){
       vis[j] = 1;
       t.push_back(j);
       dfs(i+1,temp,new_cost);
       t.pop_back();
       vis[j] = 0;
      }
     }
    }
   }
  };

  dfs(1,curr_bound,0);

  cout << "Cost is " << best << endl;

  cout << "Route" << endl;

  for(auto i:path)cout << i << "->";
   cout << 0 << endl;
}

int32_t main()
{
  SpeedForce;

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve();
    // cout << endl;
  }
  return 0;
}
