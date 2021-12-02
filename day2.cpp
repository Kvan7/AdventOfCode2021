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

enum Direction{
	Forward,
	Up,
	Down,
};

int main()
{
	int total=0, horizontal=0, depth=0, aim=0, movement;
	string direction;
	map<string,Direction> dir;
	dir["forward"]=Direction::Forward;
	dir["up"]=Direction::Up;
	dir["down"]=Direction::Down;
	REP(i, 1000)
	{
		cin>>direction>>movement;
		switch(dir[direction])
		{
		case Direction::Forward:
			horizontal+=movement;
			depth+=aim*movement;
			break;
		case Direction::Up:
			aim-=movement;
			break;
		case Direction::Down:
			aim+= movement;
			break;
		}

		cout<<endl<<"horizontal: "<<horizontal<<"; depth: "<<depth<<endl;
		// 1459206
		// 1320534480
	}
	total = (horizontal*depth);
	cout << "total: "<<total;


	return 0;
}
