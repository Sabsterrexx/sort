#ifndef SORT_H
#define SORT_H

#include<vector>
#include<string>

void readFromFile(const char * fName, std::vector<int>&vec);

void swap(int *a, int *b);

void merge(std::vector<int>&vec, int l, int m, int r);

int partition (std::vector<int>&vec, int low, int high);

void mergeSort(std::vector<int>&vec,int l,int r);

std::vector<int> bubbleSort(std::vector<int>&vec);

void selectionSort(std::vector<int>&vec);

std::vector<int> quickSort(std::vector<int>&vec, int low, int high);

std::vector<int> insertionSort(std::vector<int>&vec);

#endif