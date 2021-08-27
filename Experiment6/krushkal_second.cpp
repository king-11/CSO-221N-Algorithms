/*input
5 8
1 3 75
3 4 51
2 4 19
3 2 95
2 5 42
5 4 31
1 2 9
3 5 66
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

int parent[100005];
vector<int> minimumWeightEdges;
int countEdges;
int a[100005];

struct edge
{
    int a, b, c;
} weights[100005];

bool cmp(edge x, edge y)
{
    return x.c < y.c;
}

void initialize(int n)
{
    for (int i = 1; i <= n; i++)
        parent[i] = i;
}

int findParent(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x]);
}

int unionSet(int i, int sum)
{
    int x, y;
    x = findParent(weights[i].a);
    y = findParent(weights[i].b);
    if (x != y)
    {
        parent[x] = y;
        minimumWeightEdges.push_back(i);
        sum += weights[i].c;
    }
    return sum;
}

int unionSet2(int i, int sum)
{
    int x, y;
    x = findParent(weights[i].a);
    y = findParent(weights[i].b);
    if (x != y)
    {
        parent[x] = y;
        sum += weights[i].c;
        countEdges++;
    }
    return sum;
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    initialize(n);

    for (int i = 0; i < m; i++)
    {
        cin >> weights[i].a >> weights[i].b >> weights[i].c;
    }

    sort(weights, weights + m, cmp);
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        if (minimumWeightEdges.size() == n - 1)
            break;
        sum = unionSet(i, sum);
    }

    cout << "MST: " << sum << "\n"; //cost

    int secondMST = INT_MAX;

    cout << "All other spanning trees:\n";

    sum = 0;
    int j;
    for (j = 0; j < minimumWeightEdges.size(); j++)
    {
        initialize(n);
        countEdges = 0;
        for (int i = 0; i < m; i++)
        {
            if (i == minimumWeightEdges[j])
                continue;
            sum = unionSet2(i, sum);
        }
        if (countEdges != n - 1)
        {
            sum = 0;
            continue;
        }
        cout << sum << "\n";
        if (secondMST > sum)
            secondMST = sum;
        sum = 0;
    }

    cout << "Second Best MST is: " << secondMST << "\n";
}
