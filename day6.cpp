#include <bits/stdc++.h>

using namespace std;

#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

const int DAYS = 256;




int main()
{
	string str;
	cin >> str;
	std::vector<int> fishs;
	std::map<int, long long> fishes = {{-1,0LL},{0,0LL},{1,0LL},{2,0LL},{3,0LL},{4,0LL},{5,0LL},{6,0LL},{7,0LL},{8,0LL}};
    std::stringstream ss(str);
    long long p2 = 0;

    for (int i; ss >> i;) {
        fishs.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }
    for (auto& i : fishs)
	{
		fishes[i]+=1LL;
	}

    for(int i = 0;i<DAYS;i++)
	{
		cout<<"DAY:"<<i<<endl;
		for(int j = 0; j<9;j++)
		{
			fishes[j-1] = fishes[j];
		}
		fishes[6]+=fishes[-1];
		fishes[8]=fishes[-1];
		fishes[-1]=0LL;
		for(auto& [k,v] : fishes)
			cout<<"K:"<<k<<";V:"<<v<<"type:"<<typeid(v).name()<<endl;
	}

	for(auto& [k, v] : fishes)
	{
		p2+=v;
	}

	cout<<"FISH:"<<p2<<endl;




	return 0;
}














