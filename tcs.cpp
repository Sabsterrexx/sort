#include<vector>
#include "catch2/catch_amalgamated.hpp"
#include "sort.hpp"
#include "printElements.hpp"

std::vector<int>input;
std::vector <int> output;

TEST_CASE("Good to go","[vector]"){

    readFromFile("numbers.txt",input);
    readFromFile("numbers-out.txt",output);

    REQUIRE(bubbleSort(input) == output);
    
}

