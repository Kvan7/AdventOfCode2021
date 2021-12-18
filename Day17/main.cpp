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


//const int T=1324, ST=500;
//const int T=6, ST = 50;

//const int T=3, ST = 15;
//pair<PII,PII> target = {{20,30},{-10,-5}};
pair<PII,PII> target = {{124,174},{-123,-86}};





bool inTarget(PII coord)
{
	bool inX = (coord.first>=target.first.first&&coord.first<=target.first.second);
	bool inY = (coord.second>=target.second.first&&coord.second<=target.second.second);
	return inX&&inY;
}

bool outsideBounds(PII coord)
{
	return coord.first>target.first.second || coord.second<target.second.first;
}

PII step(PII v)
{
	PII newV;
	if(v.first==0)
		newV={0,v.second-1};
	else if(v.first<0)
		newV={v.first+1,v.second-1};
	else
		newV={v.first-1,v.second-1};
	return newV;
}


bool goodPath(PII v)
{
	PII pos = {0,0};
	while(!outsideBounds(pos))
	{
		if(inTarget(pos))
		{
//			cout<<";"<<pos.first<<","<<pos.second<<";";

			return true;
		}

		pos.first+=v.first;
		pos.second+=v.second;
		v=step(v);
	}
}

VI allPosX()
{
	VI works;

	for(int vx = target.first.second;vx>0;vx--)
	{
		for(int pos = 0, vxi=vx;pos<=target.first.second&&vxi>=0;pos+=vx,vxi--)
		{
			if(target.first.first<=pos&&target.first.second>=pos)
			{
				works.push_back(vx);
				break;
			}
		}
	}
	return works;


}
VII allPosY(int vx)
{
	VII works;
	int endCol = 0;
	for(int a = vx;a>0;a--)
		endCol+=a;
	for(int vy = -(target.second.first+1); vy>=target.second.first; vy--)
	{
		if(goodPath(make_pair(vx,vy)))
		{
			works.push_back(make_pair(vx,vy));
//			cout<<"("<<vx<<","<<vy<<")"<<endl;
		}

	}





	return works;


}


PII findBestPath()
{

	int vx = 0;
	int col = target.first.first;
	while(col<=target.first.second)
	{
		int tat=0, vxi=0;
		while(tat<col)
		{
			vxi++;
			tat+=vxi;
		}
		if(tat==col)
		{
			vx = max(vxi,vx);
		}
		col++;
	}

//	int row = target.second.first;
//	int mrow = -INF;
//	int vy=0;




	return make_pair(vx, -(target.second.first+1));

}


int countPaths()
{
	VI xPath = allPosX();
	int pathCount = 0;
	for(auto& it : xPath)
		pathCount+=allPosY(it).size();




	return pathCount;
}

int countPathsBruteForce()
{
	int total = 0;
	for(int vx = 1; vx <=target.first.second;vx++)
		for(int vy = target.second.first;vy<=-target.second.first;vy++)
			total +=(goodPath(make_pair(vx,vy)))?1:0;

	return total;
}



int main()
{
	PII best = findBestPath();
//	goodPath(make_pair(6,22));
	cout<<"X: "<<best.first<<"; Y: "<< best.second<<endl;
//	for(int pos = 0, vy = best.second; vy>=0;pos+=vy,vy--)
//		cout<<pos<<endl;

	auto t1 = std::chrono::high_resolution_clock::now();
	cout<<"Paths:"<<countPaths()<<endl;
	auto t2 = std::chrono::high_resolution_clock::now();
	cout<<"BruteForcePaths:"<<countPathsBruteForce()<<endl;
	auto t3 = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double, std::milli> ms_double_R = t2 - t1;
	std::chrono::duration<double, std::milli> ms_double_B = t3 - t2;

	cout<<"Regular time: "<< ms_double_R.count()<<"ms"<<endl<<"Brute force time: "<< ms_double_B.count()<<"ms"<<endl;

	return 0;
}














