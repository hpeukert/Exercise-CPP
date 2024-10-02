#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time>
#include <limits>   // for numeric_limits

void displayMenu();
int getUserChoice();
int getComputerChoice();
void displayChoices(int userChoice, int computerChoice);
void determineWinner(int userChoice, int computerChoice, int &userScore, int &computerScore);
bool playAgain();

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));

    bool continuePlaying = true;
    int userScore = 0;
    int computerScore = 0;

    while (continuePlaying)
    {
        // Display menu and get choices
        displayMenu();
        int userChoice = getUserChoice();
        int computerChoice = getComputerChoice();

        // Display both choices
        displayChoices(userChoice, computerChoice);

        // Determine and display the winner
        determineWinner(userChoice, computerChoice, userScore, computerScore);

        // Display current scores
        std::cout << "\nCurrent Scores:\n";
        std::cout << "You: " << userScore << " | Computer: " << computerScore << "\n";

        // Ask if the user wants to play again
        continuePlaying = playAgain();
    }

    std::cout << "Thanks for playing! Final Scores - You: " << userScore << " | Computer: " << computerScore << "\n";
    std::cout << "Goodbye.\n";

    return 0;
}

// Function to display the menu to the user
void displayMenu()
{
    std::cout << "\nWelcome to Rock, Paper, Scissors!\n";
    std::cout << "Please choose:\n";
    std::cout << "1. Rock\n";
    std::cout << "2. Paper\n";
    std::cout << "3. Scissors\n";
}

// Function to get the user's choice
int getUserChoice()
{
    int choice;
    while (true)
    {
        std::cout << "Enter your choice (1, 2, or 3): ";
        std::cin >> choice;

        // Check if input is valid
        if (std::cin.fail() || choice < 1 || choice > 3)
        {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid choice. Please enter 1, 2, or 3.\n";
        } else
        {
            return choice;
        }
    }
}

// Function to get the computer's random choice
int getComputerChoice()
{
    return std::rand() % 3 + 1;
}

// Function to display the choices made by both the user and the computer
void displayChoices(int userChoice, int computerChoice)
{
    std::string choices[] = {"Rock", "Paper", "Scissors"};
    std::cout << "You chose: " << choices[userChoice - 1] << "\n";
    std::cout << "Computer chose: " << choices[computerChoice - 1] << "\n";
}

// Function to determine and display the winner, and update scores
void determineWinner(int userChoice, int computerChoice, int &userScore, int &computerScore)
{
    if (userChoice == computerChoice)
    {
        std::cout << "It's a draw!\n";
    } else if ((userChoice == 1 && computerChoice == 3) ||
               (userChoice == 2 && computerChoice == 1) ||
               (userChoice == 3 && computerChoice == 2)) {
        std::cout << "You win!\n";
        userScore++;
    } else
    {
        std::cout << "Computer wins!\n";
        computerScore++;
    }
}

// Function to ask if the user wants to play again
bool playAgain()
{
    char response;
    while (true)
    {
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> response;

        if (response == 'y' || response == 'Y')
        {
            return true;
        } else if (response == 'n' || response == 'N')
        {
            return false;
        } else
        {
            std::cout << "Invalid input. Please enter 'y' to play again or 'n' to quit.\n";
        }
    }
}
