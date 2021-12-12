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



const int INS=10, STEPS = 100;

struct OctopusGrid
{

	struct Octopus
	{
		int energy = 0;
		Octopus* n;
		Octopus* s;
		Octopus* w;
		Octopus* e;
		Octopus* nw;
		Octopus* se;
		Octopus* sw;
		Octopus* ne;
		bool bn=false, bs=false, bw=false, be=false,bnw=false, bse=false, bsw=false, bne=false;

		void startFlash()
		{
			if(bn&&(*n).energy!=0)
				{
					cout<<"N:"<<(*n).energy<<":";
					(*n).flash();
				}

				if(bs&&(*s).energy!=0)
				{
//					cout<<"S:"<<(*s).energy<<":";
					(*s).flash();
				}

				if(bw&&(*w).energy!=0)
				{
//					cout<<"W:"<<(*w).energy<<":";
					(*w).flash();
				}

				if(be&&(*e).energy!=0)
				{
//					cout<<"E:"<<(*e).energy<<":";
					(*e).flash();
				}

				if(bne&&(*ne).energy!=0)
				{
//					cout<<"NE:"<<(*ne).energy<<":";
					(*ne).flash();
				}

				if(bsw&&(*sw).energy!=0)
				{
//					cout<<"SW:"<<(*sw).energy<<":";
					(*sw).flash();
				}

				if(bnw&&(*nw).energy!=0)
				{
//					cout<<"NW:"<<(*nw).energy<<":";
					(*nw).flash();
				}

				if(bse&&(*se).energy!=0)
				{
//					cout<<"SE:"<<(*se).energy<<":";
					(*se).flash();
				}
				cout<<endl;
//			return total;
		}

		void flash()
		{
			energy++;
//			cout<<"<E:"<<energy<<">";
			if(energy>9)
			{
				energy=0;
				if(bn&&(*n).energy!=0)
				{
//					cout<<"N:"<<(*n).energy<<":";
					(*n).flash();
				}

				if(bs&&(*s).energy!=0)
				{
//					cout<<"S:"<<(*s).energy<<":";
					(*s).flash();
				}

				if(bw&&(*w).energy!=0)
				{
//					cout<<"W:"<<(*w).energy<<":";
					(*w).flash();
				}

				if(be&&(*e).energy!=0)
				{
//					cout<<"E:"<<(*e).energy<<":";
					(*e).flash();
				}

				if(bne&&(*ne).energy!=0)
				{
//					cout<<"NE:"<<(*ne).energy<<":";
					(*ne).flash();
				}

				if(bsw&&(*sw).energy!=0)
				{
//					cout<<"SW:"<<(*sw).energy<<":";
					(*sw).flash();
				}

				if(bnw&&(*nw).energy!=0)
				{
//					cout<<"NW:"<<(*nw).energy<<":";
					(*nw).flash();
				}

				if(bse&&(*se).energy!=0)
				{
//					cout<<"SE:"<<(*se).energy<<":";
					(*se).flash();
				}

			}
//			cout<<endl;
//			return total;



/*


			if(energy>9)
				return 0;
			energy++;
			if(energy > 9&&!toFlash)
			{
				cout<<"tat";
				total++;
				toFlash = true;
				if(bn&&!(*n).toFlash)
					total+=(*n).flash();
				if(bs&&!(*s).toFlash)
					total+=(*s).flash();
				if(bw&&!(*w).toFlash)
					total+=(*w).flash();
				if(be&&!(*e).toFlash)
					total+=(*e).flash();
				if(bne&&!(*ne).toFlash)
					total+=(*ne).flash();
				if(bsw&&!(*sw).toFlash)
					total+=(*sw).flash();
				if(bnw&&!(*nw).toFlash)
					total+=(*nw).flash();
				if(bse&&!(*se).toFlash)
					total+=(*se).flash();
			}
			return total;
			*/
		}

	};
	Octopus octopi[INS][INS];

	OctopusGrid()
	{
		REP(i, INS)
		{
			string str;
			cin>>str;
			REP(j,INS)
			{
				octopi[i][j].energy = str[j]-48;
			}
		}
		link();

	}

	void print()
	{
		REP(i,INS)
		{
			REP(j,INS)
			{
				cout<<octopi[i][j].energy;
			}
			cout<<endl;
		}
	}
	void link()
	{
		REP(i,INS)
		{
			REP(j,INS)
			{
				if(i!=0)
				{
					octopi[i][j].n = &octopi[i-1][j];
					octopi[i][j].bn=true;
				}
				if(j!=0)
				{
					octopi[i][j].w = &octopi[i][j-1];
					octopi[i][j].bw=true;
				}
				if(i!=INS-1)
				{
					octopi[i][j].s = &octopi[i+1][j];
					octopi[i][j].bs=true;
				}
				if(j!=INS-1)
				{
					octopi[i][j].e = &octopi[i][j+1];
					octopi[i][j].be=true;
				}
				if(i!=0&&j!=0)
				{
					octopi[i][j].nw = &octopi[i-1][j-1];
					octopi[i][j].bnw=true;
				}
				if(j!=0&&i!=INS-1)
				{
					octopi[i][j].ne = &octopi[i+1][j-1];
					octopi[i][j].bne=true;
				}
				if(i!=INS-1&&j!=INS-1)
				{
					octopi[i][j].se = &octopi[i+1][j+1];
					octopi[i][j].bse=true;
				}
				if(j!=INS-1&&i!=0)
				{
					octopi[i][j].sw = &octopi[i-1][j+1];
					octopi[i][j].bsw=true;				}

			}

		}
	}

	bool syncFlash()
	{
		REP(i,INS)
			REP(j,INS)
				if(octopi[i][j].energy!=0)
					return false;
		return true;
	}

	int stepGrid()
	{
		int flashCount = 0;
		cout<<endl;
		REP(i,INS)
		{
			REP(j,INS)
			{
				octopi[i][j].energy++;

			}
		}
		REP(i,INS)
		{
			REP(j,INS)
			{
				if(octopi[i][j].energy>9)
				{
					octopi[i][j].energy=0;
					octopi[i][j].startFlash();
//					cout<<"Flashed at:"<<i<<","<<j<<endl;
//					print();
//					cout<<endl;
				}

			}
		}
		REP(i,INS)
			REP(j,INS)
				if(octopi[i][j].energy==0)
					flashCount++;

		return flashCount;
	}


	void basinOctopuss()
	{
		REP(i,INS)
		{
			REP(j,INS)
			{
				if(i!=0&&octopi[i][j].energy>=octopi[i-1][j].energy)
				{
					continue;
				}
				if(j!=0&&octopi[i][j].energy>=octopi[i][j-1].energy)
				{
					continue;
				}
				if(i!=INS-1&&octopi[i][j].energy>=octopi[i+1][j].energy)
				{
					continue;
				}
				if(j!=INS-1&&octopi[i][j].energy>=octopi[i][j+1].energy)
				{
					continue;
				}

			}

		}
	}


	PII connectNines(PII xy)
	{

		int i = xy.first, j=xy.second;
		PII down = make_pair(i,j);
		if(i!=0&&octopi[i][j].energy>octopi[i-1][j].energy)
		{
			down=make_pair(i-1,j);
		}
		if(j!=0&&octopi[i][j].energy>octopi[i][j-1].energy)
		{
			down=make_pair(i,j-1);
		}
		if(i!=INS-1&&octopi[i][j].energy>octopi[i+1][j].energy)
		{
			down=make_pair(i+1,j);
		}
		if(j!=INS-1&&octopi[i][j].energy>octopi[i][j+1].energy)
		{
			down=make_pair(i,j+1);
		}
		if (down == make_pair(i,j))
			return down;
		PII recurse = connectNines(down);
		cout<<recurse.first<<":"<<recurse.second<<endl;
		return recurse;
	}

};




int main()
{
	OctopusGrid octo;
	long total = 0L;
	int step = 0;
	cout<<endl;
	octo.print();
	cout<<endl;
	while(!octo.syncFlash())
	{
		int change = octo.stepGrid();
		cout<<change<<endl<<endl;
		total+=static_cast<long>(change);
		octo.print();
		step++;
	}
	cout<<"TOTAL: "<<total;
	cout<<"STEPS: "<<step;

	return 0;
}














