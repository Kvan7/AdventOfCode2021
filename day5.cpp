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

const int VENT_COUNT = 500;
const int MAX = 1000;


struct VentMap
{
	vector<vector<int>> diagram = vector<vector<int>>(MAX, vector<int>(MAX));

	void add(int x1, int y1, int x2, int y2)
	{
		int ymin = min(y1,y2);
		int ymax = max(y1,y2);
		int xmin = min(x1,x2);
		int xmax = max(x1,x2);
		if(x1==x2)
		{
			FOR(i, ymin, ymax+1, 1)
			{
				diagram[i][x1]++;
			}
		}else if(y1==y2)
		{
			FOR(i, xmin, xmax+1, 1)
			{
				diagram[y1][i]++;
			}
		}else
		{

			for(int x = x1, y=y1;x-x2!=0;(x1>x2)?x--:x++,(y1>y2)?y--:y++)
			{
				diagram[y][x]++;
			}
			diagram[y2][x2]++;
		}
	}


	void print()
	{
		for(auto& a: diagram)
		{
			for(auto& x: a)
			{
				cout<<x;
			}
			cout<<endl;
		}
	}
};

pair<pair<int,int>,pair<int,int>> parseIn()
{
	string in, p1,p2;

	cin>>p1>>in>>p2;


	int loc1 = p1.find(",");
	int loc2 = p2.find(",");
	string ls[] = {p1.substr(0,loc1),p1.substr(loc1+1),p2.substr(0,loc2),p2.substr(loc2+1)};

	int a = stoi(ls[0]),b = stoi(ls[1]),c = stoi(ls[2]),d = stoi(ls[3]);
	return make_pair(make_pair(a,b),make_pair(c,d));
}

int counts(VentMap vents)
{

	int total = 0;
	REP(i, MAX)
	{
		REP(j, MAX)
		{

			total += (vents.diagram[i][j]>1)?1:0;
		}
	}
	return total;
}




int main()
{
	VentMap ventMap;

	REP(vent, VENT_COUNT)
	{
		pair<pair<int,int>,pair<int,int>> ins = parseIn();
		ventMap.add(ins.first.first, ins.first.second, ins.second.first, ins.second.second);
	}
	ventMap.print();
	cout<<"danger zones: "<<counts(ventMap)<<endl;

	return 0;
}














