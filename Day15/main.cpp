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

vector<int> inCSV()
{
	string str;
	cin >> str;
	vector<int> vect;
	std::stringstream ss(str);
	for (int i; ss >> i;) {
        vect.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }
    return vect;
}
void vviout(VVI vect)
{
	REP(i, vect.size())
	{
		REP(j, vect[i].size())
		{
			cout<<vect[i][j];
		}
		cout<<endl;
	}
}


const int T=100, ST=500;
//const int T=10, ST = 50;
//const int T=3, ST = 15;

struct Edge
{
	PII from, to;
	int weight;
	Edge(PII s, PII d, int w)
	{
		from=s;
		to=d;
		weight=w;
	}
};

vector<PII> getNeighbors(PII source)
{
	vector<PII> arr;
	if(source.first!=0)
		arr.push_back(make_pair(source.first-1,source.second));
	if(source.second!=0)
		arr.push_back(make_pair(source.first,source.second-1));
	if(source.first<ST-1)
		arr.push_back(make_pair(source.first+1,source.second));
	if(source.second<ST-1)
		arr.push_back(make_pair(source.first,source.second+1));
	return arr;
}


int main()
{
	int riskMap[ST][ST];
	REP(i, T)
	{
		string inStr;
		cin>>inStr;
		REP(j,T)
		{
			for(int k=0;k<25;k++)
			{
				int value = (inStr[j]-48)+k/5+k%5;
				if(value>9)
					value-=9;
				riskMap[i+T*(k/5)][j+T*(k%5)] = value;
			}

		}

	}
	cout<<endl;
	REP(i,ST)
	{
		REP(j,ST)
			cout<<riskMap[i][j];
		cout<<endl;
	}
	cout<<endl;
	auto cmp = [](Edge a, Edge b){
		return a.weight > b.weight;
	};
	priority_queue<Edge, vector<Edge>, decltype(cmp)> worklist(cmp);
	worklist.push(Edge(make_pair(0,0),make_pair(0,1),riskMap[0][1]));
	worklist.push(Edge(make_pair(0,0),make_pair(1,0),riskMap[1][0]));
	map<PII,Edge> backpointers;
	PII destination = make_pair(ST-1,ST-1), source = make_pair(0,0);
	while (!worklist.empty())
	{
		Edge workitem = worklist.top();
		worklist.pop();
		if(backpointers.find(workitem.to)!=backpointers.end())
			continue;
		backpointers.insert(make_pair(workitem.to,workitem));
		if(workitem.to==destination)
			break;
		vector<PII> ind = getNeighbors(workitem.to);
		for(PII incidence : ind)
		{
			worklist.push(Edge(workitem.to, incidence, workitem.weight + riskMap[incidence.first][incidence.second]));
		}
	}
	if (backpointers.find(destination)==backpointers.end())
		return -1;
	cout<<endl<<backpointers.at(destination).weight;




	return 0;
}














