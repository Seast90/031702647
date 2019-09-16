//#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstdio>
#include <string>
#include<locale>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define de(x) cout<<#x<<" = "<<x<<"\n"
#define dd(x) cout<<#x<<" = "<<x<<" "
#define mes(p) memset(p,0,sizeof(p))
#define all(x) x.begin(),x.end()
#define rson mid+1,r,rt<<1|1
#define sz(x) (int)x.size()
#define lson l,mid,rt<<1
#define mp make_pair
#define pb push_back
#define ls (rt<<1)
#define rs (ls|1)
#define se second
#define fi first
//typedef pair <int ,int > pi;
//typedef vector <int > vi;
typedef double db;
typedef double db;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
//const int mod = (int)1e5+3;
//const int P = (int)1e5+3;
//const int N = 2e5 + 105;
//const int maxn = 2e5 + 6;
//const double PI = acos(-1);
//const int M = 1 << 17 << 1;

int main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	freopen("1.in","r",stdin); 
	freopen("1.out","w",stdout);
	locale china("chs");
	wcin.imbue(china);
	wcout.imbue(china);
	wstring s;
	//wcin >> s;
	//wcout << s;
	wchar_t c = L'"';
	int t = 0;
	while(wcin>>s){
		//t++;
		wcout << "L" <<c <<s<<c << ",";
	}
	/*while (wcin >> s) {
		//t++;
		wcout <<  s << "\n";
	}*/
	//cout << t;
	//system("pause");
	return 0;
}
