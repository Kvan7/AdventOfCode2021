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
typedef pair<long,long> PLL;
typedef pair<long long, long long> PDL;
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


const int P1=3, P2=7, PC=2;
//const int P1=4, P2 = 8, PC=2;

struct Player
{
	int score;
	int position;
	int id;
	Player()
	{
		score=0;
		position=0;
	}
	Player(int s, int p, int i)
	{
		score=s;
		position=p;
		id=i;
	}
	void turn(int distance)
	{
		position +=distance;
		while(position>10)
			position-=10;
		score+=position;
	}
	string toString()
	{
		return "Score: "+to_string(score)+"; Position: "+to_string(position)+"\n";
	}
};
struct DeterministicDie
{
	int value, rollCount;
	DeterministicDie()
	{
		value=0;
		rollCount=0;
	}
	int roll()
	{
		value++;
		rollCount++;
		if(value>100)
			value-=100;
		return value;
	}
};

struct GameBoard
{
	Player players[PC];
	int currentTurn;
	DeterministicDie die;
	GameBoard(int p1Start, int p2Start)
	{
		players[0]=Player(0,p1Start,0);
		players[1]=Player(0,p2Start,1);
		currentTurn=0;
	}
	GameBoard(int p1Start, int p1s, int p2Start, int p2s, int ct)
	{
		players[0]=Player(p1s,p1Start,0);
		players[1]=Player(p2s,p2Start,1);
		currentTurn=ct;
	}

	int loseScore()
	{
		return players[currentTurn].score;

	}

	void playMovePractice()
	{
		players[currentTurn].turn((die.roll()+die.roll()+die.roll()));
		currentTurn++;
		if(currentTurn>=PC)
			currentTurn-=PC;
	}

	int whoWon()
	{
		REP(i,PC)
			if(players[i].score>=1000)
				return i;
		return -1;
	}

	string toString()
	{
		string result="";
		REP(i,PC)
			result+=players[i].toString();
		return result+"Roll Count: "+to_string(die.rollCount)+"Player Turn: "+to_string(currentTurn)+" Last Roll: "+to_string(die.value)+"\n";
	}

};


map<pair<PII,PII>, PDL> memo;

PDL totalWins(pair<PII,PII> state)
{
	if(state.second.second>=21)
		return make_pair(0LL,1LL);

	if(memo.find(state)!=memo.end())
		return memo[state];
	PDL result = {0LL,0LL};
	REP(i,3)
	{
		REP(j,3)
		{
			REP(k,3)
			{

				long long a=0LL,b=0LL;
				int newPos = (state.first.first+i+j+k+3)%10;
				int upScore =  newPos+state.first.second+1;
				tie(a,b) = totalWins(make_pair(state.second,make_pair(newPos,upScore)));
				result.first+=b;
				result.second+=a;
			}
		}
	}
	memo[state]=result;
	return result;
}




int main()
{
	auto start = chrono::high_resolution_clock::now();
	GameBoard gm = GameBoard(P1,P2);
	while(gm.whoWon()==-1)
	{
		gm.playMovePractice();
	}
	cout<<gm.loseScore()*gm.die.rollCount<<endl;
	auto middle = chrono::high_resolution_clock::now();
	long long p1,p2;
	tie(p1,p2) = totalWins({{P1-1,0},{P2-1,0}});
	cout<<p1<<" "<<p2<<" "<<max(p1,p2)<<endl;

	auto stop = chrono::high_resolution_clock::now();
	auto duration1 = chrono::duration_cast<chrono::microseconds>(middle-start);
	auto duration2 = chrono::duration_cast<chrono::microseconds>(stop-middle);
	cout<<"Execution time P1: "<<duration1.count()<<" microseconds"<<endl;
	cout<<"Execution time P2: "<<duration2.count()<<" microseconds"<<endl;


	return 0;
}














