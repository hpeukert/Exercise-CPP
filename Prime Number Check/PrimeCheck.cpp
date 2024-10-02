#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

// Sieve of Eratosthenes to generate small primes for initial checks
std::vector<int> generateSmallPrimes(int limit)
{
    std::vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= limit; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= limit; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    std::vector<int> primes;
    for (int i = 2; i <= limit; ++i)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
        }
    }

    return primes;
}

// Function to check if a number is prime using the precomputed small primes
bool isPrime(int number, const std::vector<int>& small_primes)
{
    if (number <= 1)
    {
        return false;
    }

    // Use the small primes to quickly check divisibility
    for (int prime : small_primes)
    {
        if (prime * prime > number)
        {
            break;
        }
        if (number % prime == 0)
        {
            return false;
        }
    }

    // If not divisible by any small prime, it is likely prime
    return true;
}

int main()
{
    // Generate small primes up to sqrt(10^6) for fast checks
    int small_prime_limit = 1000;
    std::vector<int> small_primes = generateSmallPrimes(small_prime_limit);

    // User input for prime check in a loop
    while (true)
    {
        std::cout << "Enter a number to check if it is a prime (or type 'q' to quit): ";

        int num;
        std::cin >> num;

        // Check if the input is a valid integer
        if (std::cin.fail())
        {
            // Check for 'q' or other inputs to quit the loop
            std::cin.clear(); // Clear the error flag
            std::string input;
            std::cin >> input;

            if (input == "q" || input == "Q")
            {
                break; // Exit the loop
            } else
            {
                std::cout << "Invalid input. Please enter an integer or 'q' to quit." << std::endl;
                continue;
            }
        }

        // Prime check
        if (isPrime(num, small_primes))
        {
            std::cout << num << " is a prime number." << std::endl;
        } else {
            std::cout << num << " is not a prime number." << std::endl;
        }
    }

    std::cout << "Goodbye!" << std::endl;

    return 0;
}
