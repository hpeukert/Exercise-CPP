#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>

class HangmanGame
{
    private:
    std::string m_word;
    std::string m_guessedWord;
    int m_maxTries;
    int m_currentTries;
    std::vector<char> m_guessedLetters;

    public:
    HangmanGame(std::string word, int maxTries) : m_word(word), m_maxTries(maxTries), m_currentTries(0)
    {
        m_word.size() < 6 ? m_maxTries = 6 : m_maxTries = m_word.size();
        m_guessedWord = std::string(word.length(), '_');
    }

    void play()
    {
        while (m_currentTries < m_maxTries && m_guessedWord != m_word)
        {
            displayGameStatus();
            char guess = askForGuess();
            checkGuess(guess);
        }

        if (m_guessedWord == m_word)
        {
            std::cout << "Congratulations, you found the word: " << m_word << std::endl;
        }
        else
        {
            std::cout << "Unfortunately you did not guess the word correctly. The solution was: " << m_word << std::endl;
        }
    }

    private:
    void displayGameStatus()
    {
        std::cout << "Current word: " << m_guessedWord << std::endl;
        std::cout << "Already guessed letters: ";
        for (char letter : m_guessedLetters)
        {
            std::cout << letter << " ";
        }
        std::cout << std::endl;
    }

    char askForGuess()
    {
        char guess;
        std::cout << "Guess a letter: ";
        std::cin >> guess;
        return guess;
    }

    void checkGuess(char guess)
    {
        m_guessedLetters.push_back(guess);

        bool correctGuess = false;
        for (int i = 0; i < m_word.length(); i++)
        {
            if (m_word[i] == guess)
            {
                m_guessedWord[i] = guess;
                correctGuess = true;
            }
        }

        if (!correctGuess)
        {
            m_currentTries++;
            std::cout << "Wrong guess! " << m_maxTries - m_currentTries << " tries remaining." << std::endl;
        }
    }
};

int main()
{
    auto str = std::string{};
    auto words = std::vector<std::string>{};

    // load words from txt file into vector
    auto iffile = std::ifstream{};
    iffile.open("Words.txt");
    if(iffile.is_open())
    {
        while (std::getline(iffile, str))
        {
            words.push_back(str);
        }
    }
    iffile.close();

    // select random word/string from vector
    srand(time(0));
    std::string randomWord = words[rand() % words.size()];

    HangmanGame game(randomWord, 0);
    game.play();

    return 0;
}
