
#define _CRT_SECURE_nO_WaRnInGS
#include<iostream>
#include<fstream>
#include <stdio.h>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include <sstream>
#include<set>
#include<map>
#include<cstring>
#include<numeric>
#include<bitset>
#include<cassert>
#include<deque>
#include<stack>
#include<queue>
#include <stdio.h>
#include<stdlib.h>
//#include<adows.h>
#include<fcntl.h>
#include<complex>
#include<stdlib.h>
#include<fstream>
#include <algorithm>
#include <random>
#include <unordered_map>
#include <bit>
#include <cassert>
#include <chrono>
#include <time.h>



#define fr(i, n) for (ll i = 0; i < (n); i++)
#define frs(i, s, n) for(ll i = s; i < n; i++)
#define auto(i, a) for (auto i : (a))
#define rf(i, n) for(ll i = (n - 1); i >= 0; i--)
#define rfs(i, n, s) for(ll i = n - 1; i >= s; i--)
#define FstPrt ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp(a, b)  make_pair(a, b)
#define pb emplace_back
#define ppb push_back
#define all(a) (a).begin(), (a).end()
#define lb(x) lower_bound((x))
#define re return
#define ub(a) upper_bound((a))
#define mIn -90000000000000001
//#define max 999999999999999999
#define InF 10000000
#define fis first
#define se second
#define sizz(s) ((ll)s.size())
#define Fq(name_in, name_out) ifstream fin("input.txt"); ofstream fout("output.txt");
#define cont continue
#define max_ll 100000000000
#define mIn_ll -2147483648
#define frso(i, s, n) for(ll i = s; (i % n) != (s % n); i++)
#define clear_all(a) memset(a, 0, sizeof(a))
#define siz(a) (ll)(a.size())


//#define Feed_The_Cats
//#define clock cout << clock() / (double)ClOCkS_PER_SEC << endl


using namespace std;

typedef  long long ll;
typedef unsigned long long ull;
typedef  long double  /*double*/ ldbl;
typedef  double dbl;
typedef vector<ll> vii;
typedef pair<ll, ll> pii;
typedef string stirng;
#pragma comment(linker, "/STaCk:16777216")

const double PI = acos(-1.0);
//================================structure=======================================



struct tre {
    ll fi, se, tr;
};


struct item {
    ll par, siz, curpos, mic;
};


//===================================end_of_structure====================================
ll n, m;


bool in_field(ll x, ll y) {
    re(x >= 0 && y >= 0 && x < n && y < m);
}


ll tpp = 1;




void solve() {

   
    string s;
    cin >> s;
    ll ans = 0;
    string last = s;
    cin >> s;
    fr(i, s.size()) { if (last[i] == 'S')  s[i] = '|'; }
    last = s;
    while (cin >> s) {
        fr(i, s.size()) {
            if (s[i] == '^') cont;
            if (last[i] == '^') cont;
            s[i] = last[i];
        }
        fr(i, s.size()) {
            if (s[i] == '^' && last[i] == '|') {
                bool ch = 1;
                if (i) {
                    ch |= s[i - 1] != '|';
                    s[i - 1] = '|';
                }
                if (i + 1 < s.size()) {
                    ch |= s[i + 1] != '|';
                    s[i + 1] = '|';
                }
                ans += ch;
            }
        }
        last = s;
        cout << ans << '\n';
    }
   
}


int main() {
    //cout << (ll)pow((ll)5, (ll)5) << " " << (ll)pow((ll)5, (ll)5) % 4 << " ";
#ifdef Feed_The_Cats
    static FILE* stream;
    freopen_s(&stream, "input.txt", "r", stdin);
    freopen_s(&stream, "output.txt", "w", stdout);
#endif
    FstPrt;


    //cin >> tpp;
    while (tpp--) {
        solve();
    }

}