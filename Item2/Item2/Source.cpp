#include "header.h"

const int GamePlayer::NumTurns; //static

const double CostEstimate::FudgeFactor = 1.35;

const int* GamePlayer::TryGetAddress()
{
	return &NumTurns;
}


int main()
{
	char input;

	const int *numTurns = GamePlayer().TryGetAddress();

	std::cout << "Hello!\n";
	std::cout << numTurns << '\n';
	std::cout << *numTurns;
	std::cin >> input;

}