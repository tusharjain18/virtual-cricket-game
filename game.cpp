#include "game.h"
using namespace std;

Game :: Game() {

    teamA.name = "Team-A";
    teamB.name = "Team-B";
    isFirstInnings = false;
    playersPerTeam = 4;
    maxBalls = 6;
    totalPlayers = 11;

    players[0] = "Virat";
    players[1] = "Rohit";
    players[2] = "Dhoni";
    players[3] = "Pant";
    players[4] = "Karthik";
    players[5] = "KLRahul";
    players[6] = "Jadeja";
    players[7] = "Hardik";
    players[8] = "Bumrah";
    players[9] = "BKumar";
    players[10] = "Ishant";

}
void Game :: welcome() {

    cout << "\t\t\t\t _______________________________________________________________________________________________ \n";
    cout << "\t\t\t\t|                                                                                               |\n";
    cout << "\t\t\t\t|=========================================== CRIC-IN ===========================================|\n";
    cout << "\t\t\t\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|\n";
    cout << "\t\t\t\t|                                                                                               |\n";
    cout << "\t\t\t\t|========================================== WELCOME!!! =========================================|\n";
    cout << "\t\t\t\t|                                              TO                                               |\n";
    cout << "\t\t\t\t|====================================== Virtual-Cricket-Game ===================================|\n";
    cout << "\t\t\t\t|_______________________________________________________________________________________________|\n\n";

    cout << "\t\t\t\t _______________________________________________________________________________________________ \n";
    cout << "\t\t\t\t|                                                                                               |\n";
    cout << "\t\t\t\t|=========================================== RULES =============================================|\n";
    cout << "\t\t\t\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|\n";
    cout << "\t\t\t\t|                                                                                               |\n";
    cout << "\t\t\t\t|1. You have to form two teams.Select 4 players for each team from the given pool of 11 players.|\n";
    cout << "\t\t\t\t|2. Win the toss and select what you will do batting or bowling.                                |\n";
    cout << "\t\t\t\t|3. There will be 6 balls in each inning.                                                       |\n";
    cout << "\t\t\t\t|_______________________________________________________________________________________________|\n\n";
}

void Game :: showAllPlayers() {

    int i;
    cout<<"\n";
    cout << "\t\t\t\t _______________________________________________________________________________________________ \n";
    cout << "\t\t\t\t|                                                                                               |\n";
    cout << "\t\t\t\t|==================================== Pool-of-11-players =======================================|\n";
    cout << "\t\t\t\t|_______________________________________________________________________________________________|\n\n\n";
    for(i = 0;i < totalPlayers; i++) {

        cout << "\t\t\t\t\t\t\t\t\t[" << i << "]. " << players[i] << "\n";
    }
}
int Game :: takeIntegerInput() {

    int n;

    while(!(cin >> n)) {

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\t\t\t\t\t\t\t\tERROR!!! Please try again with valid intput : ";
    }

    return n;
}
bool Game :: validateSelectedPlayer(int p) {

    int i;
    vector<Player> players = teamA.players;
    int n = players.size();
    for(i = 0; i < n; i++) {

        if(players[i].id == p) {

            return false;
        }
    }

    players = teamB.players;
    n = players.size();
    for(i = 0; i < n; i++) {

        if(players[i].id == p) {

            return false;
        }
    }

    return true;
}

void Game::selectPlayers() {
	cout << "\t\t\t\t _______________________________________________________________________________________________ \n";
    cout << "\t\t\t\t|                                                                                               |\n";
    cout << "\t\t\t\t|=================================== CREATE TEAM-A AND TEAM-B ==================================|\n";
    cout << "\t\t\t\t|_______________________________________________________________________________________________|\n\n";


	for (int i = 0; i < playersPerTeam; i++) {

		// Add player to team A
		teamASelection:
			cout << endl << "\t\t\t\t Select player " << i + 1 << " of Team A - ";
			int playerIndexTeamA = takeIntegerInput();

			if(playerIndexTeamA<0 || playerIndexTeamA>10 ){
				cout << endl << "\t\t\t\t Please select from the given players" << endl;
				goto teamASelection;
			}
			else if(!validateSelectedPlayer(playerIndexTeamA)){
				cout<<endl<<"\t\t\t\t Player has been already selected. please select other player"<<endl;
				goto teamASelection;
			}
			else{
				Player teamAPlayer;
				teamAPlayer.id = playerIndexTeamA;
				teamAPlayer.name = players[playerIndexTeamA];
				teamA.players.push_back(teamAPlayer);
			}
		// Add player to team B
		teamBSelection:

		cout << endl << "\t\t\t\t Select player " << i + 1 << " of Team B - ";
		int playerIndexTeamB = takeIntegerInput();

		if(playerIndexTeamB<0 || playerIndexTeamB>10 ){
						cout << endl << "\t\t\t\t Please select from the given players" << endl;
						goto teamBSelection;}
		else if(!validateSelectedPlayer(playerIndexTeamB)){
						cout<<endl<<"\t\t\t\t Player has been already selected. please select other player"<<endl;
						goto teamBSelection;
		}

					else{
						Player teamBPlayer;
						teamBPlayer.name = players[playerIndexTeamB];
						teamB.players.push_back(teamBPlayer);
					}
	}
}
void Game :: showTeamPlayers() {

    vector<Player> players = teamA.players;
    vector<Player> player = teamB.players;
    int i;

        cout << "\t\t\t\t _______________________________________ \t\t _______________________________________ \n";
        cout << "\t\t\t\t|                                       |\t\t|                                       |\n";
        cout << "\t\t\t\t|================ TEAM-A ===============|\t\t|================ TEAM-B ===============|\n";
        cout << "\t\t\t\t|_______________________________________|\t\t|_______________________________________|\n\n";

    for(i = 0; i < playersPerTeam; i++) {

        cout << "\t\t\t\t\t\t[" << players[i].id << "]." << players[i].name << "\t\t\t\t\t\t[" << player[i].id << "]." << player[i].name << "\n";
    }
}
void Game :: toss() {

    int randomValue;

    cout << "\t\t\t\t _______________________________________________________________________________________________ \n";
    cout << "\t\t\t\t|                                                                                               |\n";
    cout << "\t\t\t\t|=========================================== TOSS ==============================================|\n";
    cout << "\t\t\t\t|_______________________________________________________________________________________________|\n";

    srand(time(NULL));

    randomValue = rand() % 2;

    switch(randomValue) {

        case 0:
            cout << "\n\t\t\t\tTeam-A won the toss\n";
            tossChoices(teamA);
            break;

        case 1:
            cout << "\n\t\t\t\tTeam-B won the toss\n";
            tossChoices(teamB);
            break;
    }
}
void Game :: tossChoices(Team tossWinnerTeam) {  /* Deciding to bat or ball for the winning team
                                                    and Initializing batting team and bowling team.
                                                  */
    int choice;
    cout << "\n\t\t\t\t||| CHOOSE |||\n";
    cout << "\t\t\t\t1.Batting\n";
    cout << "\t\t\t\t2.Bowling\n";
    cout << "\t\t\t\tEnter the choice(1 for batting and 2 for bowling): ";

    choice = takeIntegerInput();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    switch(choice) {

        case 1:
            cout << "\n\t\t\t\t" <<  tossWinnerTeam.name << " won the toss and decided to bat first\n";
            if(tossWinnerTeam.name.compare("Team-A") == 0) {

                battingTeam = &teamA;   // Initializing batting team.
                bowlingTeam = &teamB;   // Initializing bowling team.
            }
            else {

                battingTeam = &teamB;
                bowlingTeam = &teamA;
            }
            break;
        case 2:
            cout << "\n\t\t\t\t" << tossWinnerTeam.name << " won the toss and decided to ball first\n";
            if(tossWinnerTeam.name.compare("Team-A") == 0) {

                bowlingTeam = &teamA;
                battingTeam = &teamB;
            }
            else {

                bowlingTeam = &teamB;
                battingTeam = &teamA;
            }
            break;
        default:
            cout << "\n\t\t\t\tERROR!!! please enter the valid choice : ";
            tossChoices(tossWinnerTeam);
            break;
    }
}
void Game::startFirstInnings() {

			cout << "\t\t\t\t _______________________________________________________________________________________________ \n";
		    cout << "\t\t\t\t|                                                                                               |\n";
		    cout << "\t\t\t\t|===================================== FIRST-INNINGS-STARTS ====================================|\n";
		    cout << "\t\t\t\t|_______________________________________________________________________________________________|\n";

	isFirstInnings = true;

	initializePlayers();
	playInnings();
}
void Game :: startSecondInnings() {

    cout << "\t\t\t\t _______________________________________________________________________________________________ \n";
    cout << "\t\t\t\t|                                                                                               |\n";
    cout << "\t\t\t\t|===================================== SECOND-INNINGS-STARTS ===================================|\n";
    cout << "\t\t\t\t|_______________________________________________________________________________________________|\n";

    isFirstInnings = false;

    Team tempTeam = *battingTeam;
    *battingTeam = *bowlingTeam;
    *bowlingTeam = tempTeam;

    initializePlayers();
    playInnings();
}

void Game::initializePlayers() {

	// Choose batsman and bowler: Initialize *batsman and *bowler
	batsman = &battingTeam->players[0];
	bowler = &bowlingTeam->players[0];

	cout << "\n\t\t\t\t" << battingTeam->name << " : " << batsman->name << " is going to bat\n";
	cout << "\n\t\t\t\t" << bowlingTeam->name << " : " << bowler->name << " is going to ball\n";

}
void Game :: playInnings() {

    int i;

    for(i = 0; i < maxBalls; i++) {

        cout << "\n\t\t\t\tPress enter to ball...\n";
        getchar();

        bat();
        if(!validateInningsScore())
        {
        	break;
        }
    }
}

void Game :: bat() {

    int runsScored;

    srand(time(NULL));

    runsScored = rand() % 7;

    // Updating batting specs
    batsman->runsScored = batsman->runsScored + runsScored;
    batsman->ballsPlayed = batsman->ballsPlayed + 1;
    battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;

    // Updating bowling specs
    bowler->ballsBowled = bowler->ballsBowled + 1;
    bowler->runsGiven = bowler->runsGiven + runsScored;
    bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled + 1;

    if(runsScored != 0) { // if runsScored = 1, 2, 3, 4, 5, or 6

        cout << "\n\t\t\t\t" << bowler->name << " to " << batsman->name << " " << runsScored << " runs scored!.\n";
    }
    else { // else runScored = 0 and the batsman is ‘OUT’

        cout << "\n\t\t\t\t" << bowler->name << " to " << batsman->name << " ! OUT !\n";

        bowler->wicketsTaken = bowler->wicketsTaken + 1;
        battingTeam->wicketsLost = battingTeam->wicketsLost + 1;

        showScoreCard();

        int newIndex = battingTeam->wicketsLost;
        batsman = &battingTeam->players[newIndex];
    }
}
void Game :: showScoreCard() {

    cout << "\n\t\t\t\t|=============================== BATTING STATS ================================|";
    cout << "\n\t\t\t\t________________________________________________________________________________";
    cout << "\n\t\t\t\t" << batsman->name << " : " << batsman->runsScored << " ( " << batsman->ballsPlayed << " )";
    cout << "\n\t\t\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _";
    cout << "\n\t\t\t\t" << battingTeam->name << " : " << battingTeam->totalRunsScored << " - " << battingTeam->wicketsLost;
    cout << "\n\t\t\t\t________________________________________________________________________________";

    cout << "\n\t\t\t\t|=============================== BOWLING STATS ================================|";
    cout << "\n\t\t\t\t________________________________________________________________________________";
    cout << "\n\t\t\t\t" << bowler->name << " : " << bowler->runsGiven << " ( " << bowler->ballsBowled << " )";
    cout << "\n\t\t\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _";
    cout << "\n\t\t\t\t" << bowlingTeam->name << " : " << battingTeam->totalRunsScored << " ( " << bowlingTeam->totalBallsBowled << " )";
    cout << "\n\t\t\t\t________________________________________________________________________________";
}
bool Game :: validateInningsScore() {

    if(isFirstInnings) {

        if(battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls ) {

            cout << "\t\t\t\t _______________________________________________________________________________________________ \n";
            cout << "\t\t\t\t|                                                                                               |\n";
            cout << "\t\t\t\t|====================================== FIRST-INNINGS-ENDS =====================================|\n";
            cout << "\t\t\t\t|_______________________________________________________________________________________________|\n";

            cout << "\t\t\t\t|============================== " << battingTeam->name << " ===============================|\n";
            cout << "\t\t\t\t\t\t\t" << battingTeam->totalRunsScored << " - " << battingTeam->wicketsLost << "\n";

            cout << "\n\t\t\t\t\t\t!!! RESULT !!!";
            cout << "\n\t\t\t\t" << bowlingTeam->name << " needs to  score " << battingTeam->totalRunsScored + 1  << " runs ";
            cout << " in " << maxBalls << " balls \n";

            return false;
            }
    }
        else {

            if (battingTeam->totalRunsScored > bowlingTeam->totalRunsScored) {

        	    cout <<"\n\t\t\t\t\t\t *****"<< battingTeam->name << " WON THE MATCH *****" << "\n\n";
        	    return false;
            }
            else if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls) {

                if (battingTeam->totalRunsScored < bowlingTeam->totalRunsScored) {

            	cout <<"\n\t\t\t\t\t\t *****" << bowlingTeam->name << " WON THE MATCH *****" << "\n\n";
            }
            else {

            	cout << "\n\t\t\t\t\t\t MATCH DRAW" << "\n\n";
            }
            return false;
        }
        }

    return true;
}
void Game :: showMatchSummary()
{

    	cout << "\t\t\t\t ||| MATCH ENDS ||| " << "\n\n";

        cout <<"\n\t\t\t\t\t\t"<< battingTeam->name << " " << battingTeam->totalRunsScored << "-" << battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ")" << "\n";

        cout << "\t\t\t\t==========================================" << "\n";
        cout << "\t\t\t\t| PLAYER \t BATTING \t BOWLING |" << "\n";

        for (int j = 0; j < playersPerTeam; j++) {
        	Player player = battingTeam->players[j];
        	cout << "\t\t\t\t|----------------------------------------|" << "\n";
        	cout << "\t\t\t\t| " << "[" << j << "] " << player.name << "  \t ";
            cout << player.runsScored << "(" << player.ballsPlayed << ") \t\t ";
    		cout << player.ballsBowled << "-" << player.runsGiven << "-";
    		cout << player.wicketsTaken << "\t |" << "\n";
        }
        cout << "\t\t\t\t==========================================" << "\n\n";

        cout <<"\n\t\t\t\t\t\t"<< bowlingTeam->name << " " << bowlingTeam->totalRunsScored << "-" << bowlingTeam->wicketsLost << " (" << battingTeam->totalBallsBowled << ")" << "\n";

        cout << "\t\t\t\t==========================================" << "\n";
        cout << "\t\t\t\t| PLAYER \t BATTING \t BOWLING |" << "\n";

        for (int i = 0; i < playersPerTeam; i++) {
        	Player player = bowlingTeam->players[i];
            cout << "\t\t\t\t|----------------------------------------|" << "\n";
            cout << "\t\t\t\t| " << "[" << i << "] " << player.name << "  \t ";
            cout << player.runsScored << "(" << player.ballsPlayed << ") \t\t ";
            cout << player.ballsBowled << "-" << player.runsGiven << "-";
    		cout << player.wicketsTaken << "\t |" << "\n";
        }
        cout << "\t\t\t\t==========================================" << "\n\n";
    }
