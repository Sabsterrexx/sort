#include <chrono>
#include <iostream>

#include "sort.hpp"

std::vector<int> unsorted;
std::vector<int> input;
std::vector<int> output;

namespace Benchmark {

    using std::chrono::high_resolution_clock;

    void displayTime(std::string title,std::chrono::_V2::system_clock::time_point t1,std::chrono::_V2::system_clock::time_point t2){
   
        using std::chrono::duration;
        using std::chrono::duration_cast;
        using std::chrono::milliseconds;

        duration<double, std::milli> ms_double = t2 - t1;
        std::cout << title << ":\t";
        std::cout << ms_double.count() << " ms\n";
    }

    void timeQuickSort() {
        input = unsorted;
        auto t1 = high_resolution_clock::now();
        quickSort(input);
        auto t2 = high_resolution_clock::now();
        displayTime("quick", t1, t2);
    }

    void timeInsertionSort() {
        input = unsorted;
        auto t1 = high_resolution_clock::now();
        insertionSort(input);
        auto t2 = high_resolution_clock::now();
        displayTime("insertion", t1, t2);
    }

    void timeSelectionSort(){
        input = unsorted;
        auto t1 = high_resolution_clock::now();
        selectionSort(input);
        auto t2 = high_resolution_clock::now();
        displayTime("selection", t1, t2);
    }

    void timeBubbleSort(){
        input = unsorted;
        auto t1 = high_resolution_clock::now();
        bubbleSort(input);
        auto t2 = high_resolution_clock::now();
        displayTime("bubble", t1, t2);
    }

}  


int main() {

    readFromFile("testCases/randomNumbers1.txt", unsorted);
    readFromFile("testCases/randomNumbers1-out.txt", output);

    Benchmark::timeQuickSort();
    Benchmark::timeInsertionSort();
    Benchmark::timeBubbleSort();
    Benchmark::timeSelectionSort();

    return 0;

}