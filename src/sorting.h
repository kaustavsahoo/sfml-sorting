#pragma once

#include <vector>
#include <semaphore>

extern std::binary_semaphore ready; // semaphore to signal when a value is ready
extern std::binary_semaphore value; // semaphore to signal when a value is consumed

extern bool completed;
extern int selectedIdx, otherIdx;

void bubble_sort(std::vector<int> &vec);
void insertion_sort(std::vector<int> &vec);
void selection_sort(std::vector<int> &vec);
void merge_sort(std::vector<int> &vec);
void quicksort(std::vector<int>& vec);