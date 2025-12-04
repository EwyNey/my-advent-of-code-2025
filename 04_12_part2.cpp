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


int rx[] = { -1, -1, -1, 0, 1, 1, 1 ,0 };
int ry[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

map<pii, set<pii>> g;

void solve() {
    
   
    vector<string> v;
    string s;
    
    int X =  137;
    fr(i, X) {
        cin >> s;
        v.pb(s);
    }
    n = X, m = v[0].size();
    
    fr(i, X) {
        fr(j, v[i].size()) {
            if (v[i][j] == '.') cont;
            fr(q, 8) {
                int x = i + rx[q], y = ry[q] + j;
                if (in_field(x, y) && v[x][y] == '@') {
                    g[{i, j}].insert({ x, y });
                }
            }
        }
    }

    set<pii, bool (*) (pii, pii)>ne([](pii a, pii b) {
        if (g[a].size() == g[b].size()) re a < b;
        re g[a].size() < g[b].size();
    });

    fr(i, n) fr(j, m) if (v[i][j] == '@') ne.insert({ i, j });
    int ans = 0;
    while (!ne.empty()) {
        auto cur = *ne.begin();
        ne.erase(ne.begin());
        if (g[cur].size() >= 4) break;
        ans++;
        for (auto i : g[cur]) {
            ne.erase(i);
            g[i].erase(cur);
            ne.insert(i);
        }
    }

    cout << ans;
    
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