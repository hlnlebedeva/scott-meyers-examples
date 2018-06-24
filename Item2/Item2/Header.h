#include <stdlib.h>
#include <iostream>


class GamePlayer
{
private:
	static const int NumTurns = 5;
	int scores[NumTurns];

public:
	const int* TryGetAddress();
};


class GamePlayer1
{
private:
	enum { NumTurns = 5 }; // the enum hack
							// NumTurns a symbolic name for 5
	int scores[NumTurns];
};


class CostEstimate
{
private:
	static const double FudgeFactor;
};

