#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

void displayMenu();
int getUserChoice();
int getComputerChoice();
void displayChoices(int userChoice, int computerChoice);
void determineWinner(int userChoice, int computerChoice);
bool playAgain();

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));

    bool continuePlaying = true;

    while (continuePlaying) {
        // Display menu and get choices
        displayMenu();
        int userChoice = getUserChoice();
        int computerChoice = getComputerChoice();

        // Display both choices
        displayChoices(userChoice, computerChoice);

        // Determine and display the winner
        determineWinner(userChoice, computerChoice);

        // Ask if the user wants to play again
        continuePlaying = playAgain();
    }

    std::cout << "Thanks for playing! Goodbye.\n";
    return 0;
}

// Function to display the menu to the user
void displayMenu() {
    std::cout << "\nWelcome to Rock, Paper, Scissors!\n";
    std::cout << "Please choose:\n";
    std::cout << "1. Rock\n";
    std::cout << "2. Paper\n";
    std::cout << "3. Scissors\n";
}

// Function to get the user's choice
int getUserChoice() {
    int choice;
    while (true) {
        std::cout << "Enter your choice (1, 2, or 3): ";
        std::cin >> choice;

        if (choice >= 1 && choice <= 3) {
            return choice;
        } else {
            std::cout << "Invalid choice. Please enter 1, 2, or 3.\n";
        }
    }
}

// Function to get the computer's random choice
int getComputerChoice() {
    return std::rand() % 3 + 1;
}

// Function to display the choices made by both the user and the computer
void displayChoices(int userChoice, int computerChoice) {
    std::string choices[] = {"Rock", "Paper", "Scissors"};
    std::cout << "You chose: " << choices[userChoice - 1] << "\n";
    std::cout << "Computer chose: " << choices[computerChoice - 1] << "\n";
}

// Function to determine and display the winner
void determineWinner(int userChoice, int computerChoice) {
    if (userChoice == computerChoice) {
        std::cout << "It's a draw!\n";
    } else if ((userChoice == 1 && computerChoice == 3) ||
               (userChoice == 2 && computerChoice == 1) ||
               (userChoice == 3 && computerChoice == 2)) {
        std::cout << "You win!\n";
    } else {
        std::cout << "Computer wins!\n";
    }
}

// Function to ask if the user wants to play again
bool playAgain() {
    char response;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> response;

    return (response == 'y' || response == 'Y');
}
