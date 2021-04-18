#include <chrono>
#include <iostream>

#include "sort.hpp"

std::vector<int> unsorted;
std::vector<int> input;
std::vector<int> output;

namespace benchmark {

    using std::chrono::high_resolution_clock;

    void displayTime(std::string title,std::chrono::_V2::system_clock::time_point t1,std::chrono::_V2::system_clock::time_point t2){
        using std::chrono::duration;
        using std::chrono::duration_cast;
        using std::chrono::milliseconds;
        /* Getting number of milliseconds as an integer. */
        // auto ms_int = duration_cast<milliseconds>(t2 - t1);
        /* Getting number of milliseconds as a double. */
        duration<double, std::milli> ms_double = t2 - t1;
        std::cout << title << ": ";
        std::cout << ms_double.count() << "ms\n";
    }

    void timeQuickSort() {
        auto t1 = high_resolution_clock::now();
        input = unsorted;
        quickSort(input);
        auto t2 = high_resolution_clock::now();
        displayTime("quickSort", t1, t2);
    }

    void timeInsertionSort() {
        auto t1 = high_resolution_clock::now();
        input = unsorted;
        insertionSort(input);
        auto t2 = high_resolution_clock::now();
        displayTime("insertionSort", t1, t2);
    }


    void timeBubbleSort(){
        auto t1 = high_resolution_clock::now();
        input = unsorted;
        bubbleSort(input);
        auto t2 = high_resolution_clock::now();
        displayTime("bubbleSort", t1, t2);
    }

}  

int main() {
    readFromFile("testCases/randomNumbers3.txt", unsorted);
    readFromFile("testCases/randomNumbers3-out.txt", output);

    benchmark::timeQuickSort();
    benchmark::timeInsertionSort();
    benchmark::timeBubbleSort();

    return 0;
}