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

const int INSX = 100, INSY = 100;
void out(VVI vect)
{
	REP(i, INSX)
	{
		REP(j, INSY)
		{
			cout<<vect[i][j];
		}
		cout<<endl;
	}
}


struct HeightMap
{

	struct Node
	{
		int value;
		Node* up;
		Node* down;
		Node* left;
		Node* right;
		bool bup=false, bdown=false, bleft=false, bright=false;

	};
	Node points[100][100];
	vector<Node> basin;
	VII basinCheck;
	int threeBiggest[3];
	HeightMap()
	{
		REP(i, INSX)
		{
			string str;
			cin>>str;
			REP(j,INSY)
			{
				points[i][j].value = str[j]-48;
			}
		}
		link();
		basinNodes();
		basinSizes();
		mostCommonThree();
	}

	void print()
	{
		REP(i,INSX)
		{
			REP(j,INSY)
			{
				cout<<points[i][j].value;
			}
			cout<<endl;
		}
	}
	void link()
	{
		REP(i,INSX)
		{
			REP(j,INSY)
			{
				if(i!=0)
				{
					points[i][j].up = &points[i-1][j];
					points[i][j].bup=true;
				}
				if(j!=0)
				{
					points[i][j].left = &points[i][j-1];
					points[i][j].bleft=true;
				}
				if(i!=INSX-1)
				{
					points[i][j].down = &points[i+1][j];
					points[i][j].bdown=true;
				}
				if(j!=INSY-1)
				{
					points[i][j].right = &points[i][j+1];
					points[i][j].bright=true;
				}


			}

		}
	}

	void printBasinNodes()
	{
		cout<<endl;
		for(Node it : basin)
		{
			cout<<it.value<<", ";
		}
		cout<<endl;
	}

	void basinNodes()
	{
		REP(i,INSX)
		{
			REP(j,INSY)
			{
				if(i!=0&&points[i][j].value>=points[i-1][j].value)
				{
					continue;
				}
				if(j!=0&&points[i][j].value>=points[i][j-1].value)
				{
					continue;
				}
				if(i!=INSX-1&&points[i][j].value>=points[i+1][j].value)
				{
					continue;
				}
				if(j!=INSY-1&&points[i][j].value>=points[i][j+1].value)
				{
					continue;
				}
				basin.push_back(points[i][j]);

			}

		}
	}
	int sumBasins()
	{
		int sum=0;
		for(Node it : basin)
		{
			cout<<sum<<":";
			sum += it.value+1;
		}
		cout<<endl;
		return sum;
	}
	PII connectNines(PII xy)
	{

		int i = xy.first, j=xy.second;
		PII down = make_pair(i,j);
		if(i!=0&&points[i][j].value>points[i-1][j].value)
		{
			down=make_pair(i-1,j);
		}
		if(j!=0&&points[i][j].value>points[i][j-1].value)
		{
			down=make_pair(i,j-1);
		}
		if(i!=INSX-1&&points[i][j].value>points[i+1][j].value)
		{
			down=make_pair(i+1,j);
		}
		if(j!=INSY-1&&points[i][j].value>points[i][j+1].value)
		{
			down=make_pair(i,j+1);
		}
		if (down == make_pair(i,j))
			return down;
		PII recurse = connectNines(down);
		cout<<recurse.first<<":"<<recurse.second<<endl;
		return recurse;
	}

	void basinSizes()
	{
		REP(i,INSX)
		{
			REP(j,INSY)
			{
				if(points[i][j].value!=9)
					basinCheck.push_back(connectNines(make_pair(i,j)));
			}
		}
	}
	void mostCommonThree()
	{
		map<PII,int> counts;
		for(auto& it:basinCheck)
			++counts[it];
		using pair_type = decltype(counts)::value_type;
		REP(i,3)
		{
			auto pr = max_element
			(
				begin(counts),end(counts),
				[] (const pair_type & p1, const pair_type & p2) {
					return p1.second < p2.second;
				}
			);
			threeBiggest[i] = pr->second;
			counts.erase(pr->first);
		}

	}

	int biggest()
	{
		int total = 1;
		REP(i,3)
		{
			total*=threeBiggest[i];
		}
		return total;
	}

};




int main()
{
//	VVI heightMap;
//	VI riskSpots;
	HeightMap height;
	height.print();
	height.printBasinNodes();
	cout<<endl<<height.sumBasins()<<endl;
	cout<<height.biggest()<<endl;


	return 0;
}














