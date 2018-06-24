using namespace std;


class TimeKeeper
{
private:
	//long time[10000];
	long *time;
public:
	virtual void getTime();
	TimeKeeper() { time = new long[10000]; };
	virtual ~TimeKeeper() { delete[] time; };
};

class AtomicClock : public TimeKeeper
{
private:
	//long atomicTime[10000];
	long *atomicTime;
public:
	void getTime();
	AtomicClock() { atomicTime = new long[10000]; }
	~AtomicClock() { delete[] atomicTime; }
};
	
class WaterClock : public TimeKeeper
{
private:
	//long waterType[10000];
	long *waterTime;
public:
	void getTime();
	WaterClock() { waterTime = new long[10000]; }
	~WaterClock() { delete[] waterTime; }
};

class WristClock : public TimeKeeper
{
private:
	//long pulse[10000];
	long *wristTime;
public:
	void getTime();
	WristClock() { wristTime = new long[10000]; }
	~WristClock() { delete[] wristTime; }
};

class Point
{
public:
	Point(int xCoord, int yCoord);
	~Point();
private:
	int x, y;
};

class SpecialString : public string
{
public:
	SpecialString(const char* s) : string(s)
	{
		specString = new string(s);
	}

	~SpecialString()
	{
		delete specString;
	}
private:
	string *specString;
};

class AWOV // AWOV = Abstract w/o Virtuals
{
public:
	virtual ~AWOV() = 0;
			// declare virtual destructor
	virtual void Method() = 0; 

};

AWOV::~AWOV()
{
	std::cout << "~AWOV()\n";
}

void AWOV::Method()
{
		std::cout << "default method";
}

class AWOVInh : public AWOV
{
public:
	void Method() { std::cout << "method implemented by derived class\n";  }
	~AWOVInh() { std::cout << "~AWOVInh()\n"; }

};