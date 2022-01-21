#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define endl '\n'
#define pii pair<int, int>
#define sz(x) (int)x.size();
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma gcc optimize("Ofast")
#pragma GCC optimization("Ofast")
#pragma optimize(Ofast)
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
constexpr int mod = 1e9 + 7;
const int MAX = 2e6 + 5;
template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename F, typename S>
ostream &operator<<(ostream &ostream, pair<F, S> &p)
{
    cout << "{" << p.first << "," << p.second << "}";
    return ostream;
}
using BigInt = __int128;
void readBigInt(BigInt& num) {
    BigInt x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    num = x * f;
}
std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}
template <typename T>
ostream &operator<<(ostream &ostream, vector<T> &v)
{
    cout << "[";
    for (int i = 0; i < v.size(); i++)
    {
        if (i != (v.size() - 1))
        {
            cout << v[i] << ",";
        }
        else
        {
            cout << v[i];
        }
    }
    cout << "]";
    return ostream;
}
template <typename SS>
ostream &operator<<(ostream &ostream, set<SS> &s)
{
    cout << "[";
    auto iit = s.end();
    iit--;
    for (auto it = s.begin(); it != iit; it++)
    {
        cout << *it << ",";
    }
    cout << *iit << "]";
    return ostream;
}
template <typename KK, typename VV>
ostream &operator<<(ostream &ostream, map<KK, VV> &m)
{
    cout << "[";
    auto iit = m.end();
    iit--;
    for (auto it = m.begin(); it != iit; it++)
    {
        cout << *it << ",";
    }
    cout << *iit << "]";
    return ostream;
}
template <typename F, typename S>
istream &operator>>(istream &istream, pair<F, S> &p)
{
    cin >> p.first >> p.second;
    return istream;
}

template <typename T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &element : v)
    {
        cin >> element;
    }
    return istream;
}

template <int MOD = mod>
struct Mint
{
    int value;
    // static const int MOD_value = MOD;

    Mint(long long v = 0)
    {
        value = v % MOD;
        if (value < 0)
            value += MOD;
    }
    Mint(long long a, long long b) : value(0)
    {
        *this += a;
        *this /= b;
    }

    Mint &operator+=(Mint const &b)
    {
        value += b.value;
        if (value >= MOD)
            value -= MOD;
        return *this;
    }
    Mint &operator-=(Mint const &b)
    {
        value -= b.value;
        if (value < 0)
            value += MOD;
        return *this;
    }
    Mint &operator*=(Mint const &b)
    {
        value = (long long)value * b.value % MOD;
        return *this;
    }

    Mint mexp(Mint a, long long e)
    {
        Mint res = 1;
        while (e)
        {
            if (e & 1)
                res *= a;   
            a *= a;
            e >>= 1;
        }
        return res;
    }

    Mint inverse(Mint a) { return mexp(a, MOD - 2); }
    Mint &operator/=(Mint const &b) { return *this *= inverse(b); }
    friend Mint operator+(Mint a, Mint const b) { return a += b; }
    friend Mint operator-(Mint a, Mint const b) { return a -= b; }
    friend Mint operator-(Mint const a) { return 0 - a; }
    friend Mint operator*(Mint a, Mint const b) { return a *= b; }
    friend Mint operator/(Mint a, Mint const b) { return a /= b; }
    friend std::istream &operator>>(std::istream &istream, Mint &a)
    {
        long long v;
        istream >> v;
        a = v;
        return istream;
    }
    friend std::ostream &operator<<(std::ostream &ostream, Mint const &a) { return ostream << a.value; }
    friend bool operator==(Mint const &a, Mint const &b) { return a.value == b.value; }
    friend bool operator!=(Mint const &a, Mint const &b) { return a.value != b.value; }
};
using mint = Mint<mod>;
vector<mint> fac, finv, inv;
void binom_init(int MAX_N)
{
    int MOD = mod;
    fac.resize(MAX_N);
    finv.resize(MAX_N);
    inv.resize(MAX_N);
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    for (int i = 2; i < MAX_N; i++)
    {
        fac[i] = fac[i - 1] * i;
        inv[i] = MOD - MOD / i * inv[MOD % i];
        finv[i] = finv[i - 1] * inv[i];
    }
}
int accurateFloor(int a, int b)
{
    // cout<<a<<" "<<b<<endl;
    int val = a / b;
    while (val * b > a)
    {
        // cout<<val<<" "<<endl;
        val--;
    }

    return val;
}
mint binom(int n, int r)
{
    if (n < r || n < 0 || r < 0)
        return 0;
    return fac[n] * finv[r] * finv[n - r];
}
long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void chmin(int &x, int y)
{
    x = min(x, y);
}
void chmax(int &x, int y)
{
    x = max(x, y);
}
int findLevel(int n)
{
    return log2(n) + 1;
}
int ll(int i)
{
    return (long long)i;
}
void merge(vector<int> &A, vector<int> &B)
{
    if (A.size() > B.size())
    {
        swap(A, B);
    }
    B.insert(B.end(), A.begin(), A.end());
}
void merge(set<int> &A, set<int> &B)
{
    if (A.size() > B.size())
    {
        swap(A, B);
    }
    B.insert(A.begin(), A.end());
}
void solve()
{
    cout<<"Hello World"<<endl;
}
signed main()
{
    fastio;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << tc << ": ";
        solve();
    }

    return 0;
}
