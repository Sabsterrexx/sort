#include <iostream>
#include <random>
#include <time.h>
#include<fstream>
#include<vector>
#include "printElements.hpp"
#include "sort.hpp"

void readFromFile(const char * fName, std::vector<int>&vec){
    vec.clear();
 	std::ifstream file(fName);
    std::string line;
    if(file.is_open() && file.good()) {
        while (std::getline(file, line)){
            vec.push_back(std::stoi(line));
        }
    }
    
    else
        std::cout << "Error opening file" << fName;    
}

void swap(int *a, int *b){

    int t = *a;
    *a = *b;
    *b = t;

}

void merge(std::vector<int>&vec, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    std::vector<int>L(n1);
    std::vector<int>R(n2);

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = vec[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = vec[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            i++;
        }
        else{
            vec[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        vec[k] = R[j];
        j++;
        k++;
    }
}

int partition (std::vector<int>&vec, int low, int high){
    int pivot = vec[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++){
        // If current element is smaller than the pivot
        if (vec[j] < pivot){
            i++; // increment index of smaller element
            swap(&vec[i], &vec[j]);
        }
    }

    swap(&vec[i + 1], &vec[high]);

    return (i + 1);
}



//no (vec,0,vec.size()-1)
void mergeSort(std::vector<int>&vec,int l,int r){
    if(l>=r) 
        return;//returns recursively
    
    int m =l+ (r-l)/2;
    mergeSort(vec,l,m);
    mergeSort(vec,m+1,r);
    merge(vec,l,m,r);
}

//yes 
std::vector<int> bubbleSort(std::vector<int>&vec) {
    int n = vec.size(); 
    for (int i = 0; i < n-1; i++)     
        for (int j = 0; j < n-i-1; j++) 
            if (vec[j] > vec[j+1]) 
                swap(&vec[j], &vec[j+1]); 
    
    return vec;
} 

//yes 
std::vector<int> selectionSort(std::vector<int>&vec){ 
    int size = vec.size();
    std::vector<int>output;
    int alt;

    while(size > 0){

        for(int i = 0; i < size; i++){
            if(vec[i] < vec[0]){
                alt = vec[0];
                vec[0] = vec[i];
                vec[i] = alt;
            }
        }

        output.push_back(vec[0]);
        vec.erase(vec.begin());
        size--;
    }

    vec = output;

    return vec;

} 



std::vector<int> quickSort(std::vector<int>&vec, int low, int high){

    if (low < high){
        /* pi is partitioning index, arr[p] is now
        at right place */

        int pi = partition(vec, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(vec, low, pi - 1);

        quickSort(vec, pi + 1, high);

    }

    return vec;

}


//yes (vec,0,9)

std::vector<int> quickSort(std::vector<int>&vec){

    return quickSort(vec,0,vec.size()-1);

}




//yes
std::vector<int> insertionSort(std::vector<int>&vec){
    int n = vec.size(); 

    int i, key, j;
    for (i = 1; i < n; i++){
        key = vec[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && vec[j] > key){
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = key;
    }

    return vec;
}
