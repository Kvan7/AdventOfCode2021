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

struct Display
{
	string in[10], out[4];
	string delim;
	int output = 0;
	Display()
	{
		fill();
		decode();
	}
	int countNiceNumbers()
	{
		int c = 0;
		for(auto& it : out)
		{
			int len = it.length();
			if((len==2||len==4)||(len==3||len==7))
				c++;
		}
		return c;
	}
	string missing(string str, string longer)
	{
		if(longer.length()-str.length() != 1)
			return "-1";
		for(int i = 0;i<longer.length();i++)
			if(str.find(longer.substr(i,1))==string::npos)
				return longer.substr(i,1);
		return "-1";
	}

	string rmissing(string str, string longer)
	{
		for(int i = 0;i<longer.length();i++)
			if(longer.find(str.substr(i,1))!=string::npos)
				return str.substr(i,1);
		return "-1";
	}

	void decode()
	{
		map<string, int> key = {{in[0],1},{in[1],7},{in[2],4},{in[9],8}};
		string cde = missing(in[8],in[9])+missing(in[7],in[9])+missing(in[6],in[9]);
		REP(i,3)
		{
			string s = in[3+i];
			int coun=0;
			REP(j,3)
				coun+=(s.find(cde[j])!=string::npos)?1:0;
			switch(coun)
			{
			case 1:
				key.insert(make_pair(in[3+i], 5));
				break;
			case 2:
				key.insert(make_pair(in[3+i], 3));
				break;
			case 3:
				key.insert(make_pair(in[3+i], 2));
				break;
			default:
				break;
			}
		}
		REP(i,3)
		{
			string s = missing(in[6+i],in[9]);
			int coun=0;
			REP(j,3)
				coun+=(in[3+j].find(s)!=string::npos)?1:0;
			switch(coun)
			{
			case 1:
				key.insert(make_pair(in[6+i], 9));
				break;
			case 2:
				key.insert(make_pair(in[6+i], 6));
				break;
			case 3:
				key.insert(make_pair(in[6+i], 0));
				break;
			default:
				break;
			}
		}
		REP(i,4)
		{
			output*=10;
			output+=key[out[i]];
		}
	}

	void print()
	{
		REP(i,10)
			cout<<in[i]<<" ";
		cout<<"#"<<delim<<"# ";
		REP(i,4)
			cout<<out[i]<<" ";
		cout<<endl;
	}

	void fill()
	{
		REP(i,10)
		{
			cin>>in[i];
			sort(in[i].begin(),in[i].end());
		}
		cin>>delim;
		REP(i,4)
		{
			cin>>out[i];
			sort(out[i].begin(),out[i].end());
		}
		sort(begin(in), end(in), []
			(const string& first, const string& second){
				return first.length() < second.length();
			});
	}
};

const int INS = 200;

int main()
{
	long total = 0L;
	REP(i, INS)
	{
		Display d;
		d.print();
		total+=d.output;
	}
	cout<<total;

	return 0;
}














