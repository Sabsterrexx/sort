#include<vector>
#include "catch2/catch_amalgamated.hpp"
#include "sort.hpp"
#include "printElements.hpp"

std::vector<int>unsorted;

std::vector<int>input;

std::vector <int> output;



TEST_CASE("Good to go","[vector]"){

    readFromFile("numbers.txt",unsorted);
    readFromFile("numbers-out.txt",output);

    input = unsorted;
    REQUIRE(bubbleSort(input) == output);

    CHECK(bubbleSort(input) == output);

    BENCHMARK("Bubble Sort"){

        return bubbleSort(input);
    };

    /*input = unsorted;
    REQUIRE(quickSort(input,0,9) == output);
    
    CHECK(quickSort(input,0,9) == output);

    BENCHMARK("Quick Sort"){

        return quickSort(input,0,9);
    };*/

    input = unsorted;
    REQUIRE(insertionSort(input,10000) == output);

    CHECK(insertionSort(input,10000) == output);

    BENCHMARK("Insertion Sort"){

        return insertionSort(input,10000);
    };

}

