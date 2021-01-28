#include "game.h"
using namespace std;

int main() {
	 Game game;
	     game.welcome();

	     cout << "\n\n\t\t\t\tPress enter to Continue";
	     getchar();

	     game.showAllPlayers();
	     cout << "\n\n\t\t\t\tPress enter to Continue\n";
	     getchar();

	     game.selectPlayers();

	     cout << "\n\n\t\t\t\tPress enter to see the created teams...\n";
	     getchar();

	    game.showTeamPlayers();

	    cin.ignore(numeric_limits<streamsize>::max(), '\n');

	    cout << "\n\n\t\t\t\tPress enter to toss...\n";
	     getchar();

	      game.toss();

	      cout << "\n\n\t\t\t\tPress enter to start first innings...\n";
	      getchar();

	      game.startFirstInnings();

	      cin.ignore(numeric_limits<streamsize>::max(), '\n');

	      cout << "\n\n\t\t\t\tPress enter to start second innings...\n";
	      getchar();

	      game.startSecondInnings();

	      cout << "\n\n\t\t\t\tPress enter to see match summary...\n";
	      getchar();

	      game.showMatchSummary();

	 return 0;
}
