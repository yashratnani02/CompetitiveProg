#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define endl '\n'
#define pii pair<int, int>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
constexpr int mod = 998244353;
const int MAX = 5e3 + 10;
template <typename F, typename S>
ostream &operator<<(ostream &ostream, pair<F, S> &p)
{
    cout << p.first << " " << p.second;
    return ostream;
}

template <typename T>
ostream &operator<<(ostream &ostream, vector<T> &v)
{
    for (auto &element : v)
    {
        cout << element << " ";
    }
    return ostream;
}

template <typename T>
ostream &operator<<(ostream &ostream, vector<vector<T>> &v)
{
    for (auto &row : v)
    {
        for (auto &cell : row)
        {
            cout << cell << " ";
        }
        cout << "\n";
    }
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
void binom_init()
{
    int MOD = mod;
    fac.resize(MAX);
    finv.resize(MAX);
    inv.resize(MAX);
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    for (int i = 2; i < MAX; i++)
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

void solve()
{
 
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << tc << ": ";
        solve();
    }

    return 0;
}
