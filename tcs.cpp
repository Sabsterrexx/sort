#include <vector>

#include "catch2/catch.hpp"
#include "printElements.hpp"
#include "sort.hpp"


std::vector<int> unsorted;
std::vector<int> input;
std::vector<int> output;

TEST_CASE("Sorting Algorithms", "[vector]") {
  if (unsorted.size() == 0) {
    readFromFile("testCases/randomNumbers1.txt", unsorted);
    readFromFile("testCases/randomNumbers1-out.txt" , output);
  }

  SECTION("Bubble Sort") {
    input = unsorted;
    REQUIRE(bubbleSort(input) == output);
  }

  SECTION("Quick Sort") {
    input = unsorted;
    REQUIRE(quickSort(input) == output);
  }

  SECTION("Insertion Sort") {
    input = unsorted;
    REQUIRE(insertionSort(input) == output);
  }

  SECTION("Selection Sort"){
    input = unsorted;
    REQUIRE(selectionSort(input) == output);
  }

}