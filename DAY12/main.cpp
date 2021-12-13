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


const int INS=24;

struct State
{
	string value;
	set<string> visitedSmalls;
	bool doubleVisit;
	State(string str, set<string> vis, bool dv)
	{
		value = str;
		visitedSmalls = vis;
		doubleVisit = dv;
	}
};


int main()
{
	map<string, vector<string>> adj;
	int pathCount = 0;
	REP(i,INS)
	{
		string str;
		cin>>str;
		int a = str.find("-");
		string x = str.substr(0,a), y = str.substr(a+1);
		if(x!="start")
			adj[y].push_back(x);
		if(y!="start")
			adj[x].push_back(y);
	}
	queue<State> q({State("start",set<string>{"start"},false)});
	string position;
	set<string> visitedSmall;
	bool dv;
	while(!q.empty())
	{
		State check = q.front();
		position = check.value;
		visitedSmall = check.visitedSmalls;
		dv = check.doubleVisit;
//		cout<<"str:"<<position<<";saml:"<<visitedSmall.size()<<";DV:"<<dv<<endl;

		q.pop();
		if(position == "end")//
		{
			pathCount++;

		}
		else
		{
			for(auto& neighbor : adj[position])
			{
//				cout<<"Neigh:"<<neighbor<<"---------------------"<<endl;

				if(islower(neighbor[0]))
				{
					if(visitedSmall.find(neighbor)!=visitedSmall.end())
					{
						if(!dv)
							q.push(State(neighbor, visitedSmall, true));

					}
					else
					{
						set<string> small = visitedSmall;
						small.insert(neighbor);
						q.push(State(neighbor, small, dv));
//						for(string it:small)
//							cout<<it<<":";
//						cout<<endl;
					}
				}
				else
				{
					q.push(State(neighbor, visitedSmall, dv));
				}
			}
		}
	}

	cout<< "cound:"<< pathCount;







	return 0;
}














