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

const int INS=90;




map<char,char> convertOpp = {{'(',')'},{'[',']'},{'{','}'},{'<','>'},{')',')'},{']',']'},{'}','}'},{'>','>'}};
map<char,char> convert = {{'(','('},{'[','['},{'{','{'},{'<','<'},{')','('},{']','['},{'}','{'},{'>','<'}};
map<char,int> value = {{'(',1},{'[',1},{'{',1},{'<',1},{')',-1},{']',-1},{'}',-1},{'>',-1}};
map<char,int> errorValue = {{')',3},{']',57},{'}',1197},{'>',25137}};
map<char,long long> autoComplete = {{')',1LL},{']',2LL},{'}',3LL},{'>',4LL}};

int main()
{
	string str;
	long totalCorupt = 0L;
	long long totalAuto = 0LL;
	vector<long long> autoCompleteScores;
	REP(i,INS)
	{
		cin>>str;
		map<char,int> status = {{'(',0},{'[',0},{'{',0},{'<',0}};
		stack<char> st;
		for(char ch:str)
		{
			char con = convert[ch];
			if(value[ch]>0)
			{
				st.push(ch);
			}else
			{
				char out = st.top();
				st.pop();
				if(out!=con)
				{
					totalCorupt+=errorValue[ch];
					while(!st.empty())
						st.pop();
					break;
				}
			}
//			status[con]+=value[ch];
//			if(status[con]<0)
//			{
//				total+=errorValue[ch];
//				break;
//			}
		}
		long long totalLocal = 0LL;
		while(!st.empty())
		{
			char ch = st.top();
			st.pop();
			cout<<ch<<", ";
			totalLocal*=5;
			totalLocal+=autoComplete[convertOpp[ch]];
		}
		if(totalLocal!=0)
			autoCompleteScores.push_back(totalLocal);
		cout<<endl;
	}
	cout<<"thiehslk";
	sort(autoCompleteScores.begin(),autoCompleteScores.end());
	for(auto& it: autoCompleteScores)
	{
		cout<<it<<", ";
	}
	cout<<endl;

	totalAuto = autoCompleteScores[autoCompleteScores.size()/2];




	cout<<totalCorupt<<endl;
	cout<<totalAuto<<endl;








	return 0;
}














