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


const int DOTS=799, FOLDS = 12;
//const int DOTS=18, FOLDS = 2;







int main()
{
	set<PII> dotSet;
	REP(i, DOTS)
	{
		string str;
		cin>>str;
		int n = str.find(",");
		dotSet.insert(make_pair(stoi(str.substr(0,n)), stoi(str.substr(n+1))));
	}
	queue<pair<char,int>> foldq;
	REP(i,FOLDS)
	{
		string str;
		cin>>str>>str>>str;
		foldq.push(make_pair(str[0],stoi(str.substr(2))));
	}
//	REP(i,FOLDS)
//		cout<<foldList[i].first<<"~"<<foldList[i].second<<endl;


	char dir;
	int val, xt, yt;
	while(!foldq.empty())
	{
		tie(dir,val) = foldq.front();
		foldq.pop();
		set<PII> newSet;

		FOREACH(it, dotSet)
		{
			tie(xt,yt) = *it;
			if(dir=='y')
				yt=(yt>val)?val*2-yt:yt;
			if(dir=='x')
				xt=(xt>val)?val*2-xt:xt;
			newSet.insert(make_pair(xt,yt));
		}
		dotSet = newSet;
	}
	int mx=0,my=0;
	FOREACH(it,dotSet)
	{
		tie(xt,yt) = *it;
		mx = max(mx,xt);
		my = max(my,yt);
	}

	cout<<dotSet.size()<<":"<<mx<<"-"<<my<<endl;
	vector<vector<char>> dotMap;
	REP(i,my+1)
	{
		vector<char> temp;
		REP(j,mx+1)
			temp.push_back('.');
		dotMap.push_back(temp);
	}

	REP(i,my+1)
	{
		REP(j,mx+1)
			cout<<dotMap[i][j];
		cout<<endl;
	}

	FOREACH(it,dotSet)
	{
		tie(xt,yt) = *it;
		cout<<xt<<"+"<<yt<<endl;
		dotMap[yt][xt] = '#';
	}
	REP(i,my+1)
	{
		REP(j,mx+1)
			cout<<dotMap[i][j];
		cout<<endl;
	}



	return 0;
}














