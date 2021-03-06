// RandomUsername (Nikola Jovanovic)
// Counting Sort
// Sorting an array: O( N + K )
// N - array size, K - upper bound for the numbers

#include <bits/stdc++.h>
#define DBG false
#define debug(x) if(DBG) printf("(ln %d) %s = %d\n", __LINE__, #x, x);
#define lld long long
#define ff(i,a,b) for(int i=a; i<=b; i++)
#define fb(i,a,b) for(int i=a; i>=b; i--)
#define par pair<int, int>
#define fi first
#define se second
#define mid (l+r)/2
#define INF 1000000000
#define MAXN 10005
#define MAXNUM 1000005
#define MOD 1000000007

using namespace std;

// The array we're sorting and its size
int a[MAXN];
int cnt[MAXNUM];
int tmp[MAXN];
int n;
int range; // Number range: [1..range]

// Stable version
void countingSort()
{
    // Count every element
    for(int i = 1; i <= n; i++)
    {
        cnt[a[i]]++;
    }
    // Calculate indices
    for(int i = 1; i <= range; i++)
    {
        cnt[i] += cnt[i-1];
    }
    // Place the elements in a temporary array
    for(int i = n; i >= 1; i--)
    {
        int idx = cnt[a[i]]--;
        tmp[idx] = a[i];
    }
    // Put the elements back
    for(int i = 1; i <= n; i++)
    {
        a[i] = tmp[i];
    }
}

// Testing
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    range = 1000;
    countingSort();
    for(int i = 1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
