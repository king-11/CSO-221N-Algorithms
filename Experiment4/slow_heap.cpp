// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define boostIO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repn(i, n) for (int i = 1; i <= n; i++)
#define rrep(i, b, a) for (int i = b; i >= a; i--)
#define sz(v) (int)(v.size())
#define all(v) v.begin(), v.end()
#define mem0(a) memset(a, 0, sizeof(a))
#define mem1(a) memset(a, -1, sizeof(a))
#define trav(a, x) for (auto &a : x)
#define popcount(x) __builtin_popcountll(x)
#define pb push_back
#define fi first
#define se second
#define mod 1000000007
#define int long long
typedef pair<int, int> pii;
const long long INF = 1e18;
const int N = 1e5 + 5;

struct Node {
    int val;
    Node* left;
    Node* right;
};

Node* SLOWHEAP(int a[], int start, int end) {
    Node* cur = new Node();
    if (start > end) return cur;
    if (start == end) {
        cur->val = a[start];
        return cur;
    }
    int mn = a[start], l = start;
    for (int i = start; i <= end; i++) 
    {
        if (a[i] <= mn) 
        {
            mn = a[i];
            l = i;
        }
    }
    swap(a[l], a[end]);
    cur->val = a[end];
    int mid = (end - start + 1) / 2; // number of elements in the left part
    if (mid) 
    {
        cur->left = SLOWHEAP(a, start, start + mid - 1);
    }
    if (start + mid <= end - 1) 
    {
        cur->right = SLOWHEAP(a, start + mid, end - 1);
    }
    return cur;
}
void printHeap(Node* root, int num) {
    if (root == NULL) return;
    cout << num << "->" << (root->val) << endl;
    printHeap(root->left, 2 * num);
    printHeap(root->right, 2 * num + 1);
}
//T(n)
signed main() {
    boostIO;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Node* root = SLOWHEAP(a, 0, n - 1); // to construct the heap and get its root
    printHeap(root, 1); // to print the constructed heap using divide and conquer
    return 0;
}
// Zuhair
