#include <chrono>
#include <functional>
#include <iostream>
#include <random>
#include <sstream>

const unsigned int c_defaultCount = 1000;
const int c_minIntProduced = -1000;
const int c_maxIntProduced = 1000;
const char c_separator = ' ';

unsigned int getNumberOfIntsFromArgs(int argc, char* argv[]);
std::function<int()> getNextRandomNumberFunction();
void produceInts(const std::function<int()>& nextRand, unsigned int numberOfIntsToProduce);

int main(int argc, char* argv[])
{
    unsigned int numberOfIntsToProduce = getNumberOfIntsFromArgs(argc, argv);
    auto nextRand = getNextRandomNumberFunction();
    produceInts(nextRand, numberOfIntsToProduce);

    return 0;
}

unsigned int getNumberOfIntsFromArgs(int argc, char* argv[])
{
    unsigned int numberOfIntsToProduce = c_defaultCount;
    if (argc > 1)
    {
        // Ignore argv[0] because it's the path to this exe.
        std::istringstream arg0Stream(argv[1]);
        arg0Stream >> numberOfIntsToProduce;
    }
    return numberOfIntsToProduce;
}

std::function<int()> getNextRandomNumberFunction()
{
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(
        c_minIntProduced,
        c_maxIntProduced);
    auto nextRand = std::bind(distribution, generator);
    return nextRand;
}

void produceInts(const std::function<int()>& nextRand, unsigned int numberOfIntsToProduce)
{
    for(unsigned int i = 0; i < numberOfIntsToProduce; ++i)
    {
        std::cout << nextRand() << c_separator;
    }

    std::cout << std::endl;
}
