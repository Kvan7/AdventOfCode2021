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



const int LEN = 12;
const int SIZE = 1000;

struct S{
	char a[LEN];
};

void out(vector<S> vect)
{
	cout<< "el"<<endl;
	string str;
	for(S it: vect)
	{
		str="";
		REP(i,LEN)
		{
			str.insert(0,string(1,it.a[i]));
		}
		cout<<str<<";"<<endl;
	}

}


int main()
{
	int bin[LEN] = {0};
	vector<S> numbers, numbers2;
	numbers.reserve(SIZE);
	numbers2.reserve(SIZE);
	long long number=0,large=0, small=0, digit = 0;
	string binary="", binaryBack = "";
	unordered_map<char,int> digitMap = {{'0',0},{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9}};
	REP(i,SIZE)
	{
		cin>>number;
		S s1,s2;
		for( int j= 0;j<LEN; j++)
		{
			digit = number % 10;
			s1.a[j]='0'+digit;
			s2.a[j]='0'+digit;
			number/=10;
//			cout<<number<<";"<<s1.a[j]<<";"<<s2.a[j]<<";"<<j<<";"<<digit<<endl;
		}
		numbers.push_back(s1);
		numbers2.push_back(s2);
//		REP(j,LEN)
//		{
//			cout<<numbers[i].a[j];
//		}
//		cout<<endl;
	}
	digit=1;
	cout<<"sice:"<<numbers.size()<<endl;
	while(numbers.size()>1)
	{
		number=0;
		REP(i,numbers.size())
		{
			number+=numbers[i].a[LEN-digit]=='1'?1:-1;
		}
		cout<<"numberdet:"<<number<<"; Digit: "<<digit<<";"<<endl;
		number=number>=0?1:0;
		cout<<"1:";
		out(numbers);
		cout<<"number:"<<number<<";"<<endl;
		REP(i,numbers.size())
		{
			if(digitMap[numbers[i].a[LEN-digit]]!=number)
			{
				numbers.erase(numbers.begin()+i);
				i--;
			}
		}
		digit++;
	}
	cout<<"after:";
	out(numbers);
	digit=1;
	while(numbers2.size()>1)
	{
		number=0;
		REP(i,numbers2.size())
		{
			number+=numbers2[i].a[LEN-digit]=='1'?1:-1;
		}
		cout<<"numberdet:"<<number<<"; Digit: "<<digit<<";"<<endl;
		number=number>=0?0:1;
		cout<<"2:";
		out(numbers2);
		cout<<"number:"<<number<<";"<<endl;
		REP(i,numbers2.size())
		{
			if(digitMap[numbers2[i].a[LEN-digit]]!=number)
			{
				string str="";
				REP(j,LEN)
				{
					str.insert(0,string(1,numbers2[i].a[j]));
				}
				cout<<str<<";"<<endl;
				numbers2.erase(numbers2.begin()+i);
				i--;
			}
		}
		digit++;
	}
	cout<<"after:"<<numbers2.size()<<endl;
	out(numbers2);

	REP(i,LEN)
	{

		binary.insert(0,string(1,numbers.front().a[i]));
		binaryBack.insert(0,string(1,numbers2.front().a[i]));
	}
	cout<<endl<<"1."<<binary<<endl<<"2."<<binaryBack<<endl;
//	cout<<binary<<endl;
	large = stoll (binary,nullptr, 2);
	small = stoll (binaryBack,nullptr, 2);
	cout<<(small*large);

	return 0;
}














