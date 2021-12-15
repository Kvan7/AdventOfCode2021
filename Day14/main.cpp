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


const int T=100, STEPS=40;
//const int T=16, STEPS = 40;

//map<string,string> rules;

//string step(string str)
//{
//	if(str.length()<=1)
//		return str;
//	if(rules.find(str)!=rules.end())
//	{
//		cout<<"@@";
//		return rules[str];
//	}
//
//	int mid = str.length()/2;
////	cout<<"&&&";
//	string left = step(str.substr(0,mid));
//	string right = step(str.substr(mid));
//	string result = (rules.find(left.substr(left.length()-1)+right.substr(0,1))!=rules.end())?
//		left.substr(0,left.length()-1)+rules[left.substr(left.length()-1)+right.substr(0,1)]+right.substr(1):
//		left+right;
//	rules.insert(make_pair(str, result));
////	cout<<"+++";
//	return result;
//}

map<pair<char,char>,long long> emptyCount(map<pair<char,char>,char> rules){
	map<pair<char,char>,long long> x;
	for(const auto& [key,value]:rules)
	{
		x[key]=0LL;
	}
	return x;
}


int main()
{
	string str;
	map<pair<char,char>,char> rules;
//	string temp;
//	cin>>temp;
//	REP(i,temp.length())
//		str.push_back(temp.substr(i,1));
	cin>>str;
	map<pair<char,char>,long long> counts;
	map<char,long long> charCount;
	REP(i,T)
	{
		string a,b,u;
		cin>>a>>u>>b;
		rules.insert(make_pair(make_pair(a[0],a[1]),b[0]));
	}
	counts=emptyCount(rules);
	REP(i,str.length()-1)
		counts[make_pair(str[i],str[i+1])]++;
	for(const auto& [key,value]:charCount)
	{
		charCount[key]=0LL;
	}
	for(char ch:str)
		charCount[ch]++;
	REP(i, STEPS)
	{
		cout<<"STEP"<<i<<endl;
//		map<pair<char,char>,int> countsN=emptyCount(rules);
		for(const auto& [key,value] : map<pair<char,char>,long long>(counts))
		{
			counts[key]-=value;
			counts[make_pair(key.first, rules[key])]+=value;
			counts[make_pair(rules[key],key.second)]+=value;
			charCount[rules[key]]+=value;
		}
//		counts=countsN;
		for(const auto& [key,value]: charCount)
			cout<<key<<":"<<value<<endl;
	}
	long long h=-1LL,l=100000000000000000000000LL;
	for(const auto& [key,value]: charCount)
	{
		cout<<key<<":"<<value<<endl;
		h=max(h,value);
		l=min(l,value);
	}
	cout<<h-l<<endl;



	return 0;
}














