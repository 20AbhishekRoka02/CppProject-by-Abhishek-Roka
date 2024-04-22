#include <iostream>
#include <time.h>
#include <string.h>
using namespace std;

class Game
{

public:
    char validLiterals[3] = {'r','p','s'};
    Game()
    {
        cout << "Welcome to Rock, Paper and Scissor Game" << endl;
    }

    char interpretUserInput(string userInput){
        return (char) tolower(userInput[0]);
    }

    int randomNumGenerator(int min, int max)
    {
        // srand(time(NULL));
        return rand() % max + min;
    }

    int userWinDecision(char userOption, char computerOption)
    {
        if ((userOption == 'r' && computerOption == 's') || (userOption == 'p' && computerOption == 'r') || (userOption == 's' && computerOption == 'p'))
        {
            return 1;
        } else if (userOption==computerOption)
        {
            return 2;
        } else
        {
            return 0;
        }
        
    }

    void declareResult(char userInput){
        char computerChoice = validLiterals[randomNumGenerator(0,2)];
        
        if (userWinDecision(userInput, computerChoice) == 1)
        {
            cout << "You won the game!" << endl;
        } else if (userWinDecision(userInput, computerChoice) == 2)
        {
            cout << "It's a tie" << endl;
        } else{
            cout << "Computer won the game! Better luck next time." << endl;
        }
    }

    int isValidLiteral(char literalGiven){
        int length = sizeof(validLiterals)/sizeof(validLiterals[0]);

        for (int i = 0; i < length; i++)
        {
            if (literalGiven == validLiterals[i]){
                return 1;
            }
        }
        return 0;
    }
};

int main()
{
    Game game = Game();
    string option;
    bool keepRunning = true;
    game.interpretUserInput("Rock");
    while (keepRunning)
    {
        cout << "Following are the options:-" << endl;
        cout << "Choose Rock" << endl;
        cout << "Choose Scissor" << endl;
        cout << "Choose Paper" << endl;
        cout << "Choose Exit" << endl;
        cout << "Enter: ";
        cin >> option;

        char userData = game.interpretUserInput(option);
        
        if (userData == 'e')
        {
            keepRunning=false;
            cout << "Good Bye!" << endl;
        } else if (game.isValidLiteral(userData)==1)
        {
            game.declareResult(userData);
        } else
        {
            cout << "Invalid option!" << endl;
        }
    }

    return 0;
}
