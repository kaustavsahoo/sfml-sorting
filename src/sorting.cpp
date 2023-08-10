#include "sorting.h"

#include <algorithm>

static void merge_sort_recursive(std::vector<int> &vec, int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    merge_sort_recursive(vec, left, mid);
    merge_sort_recursive(vec, mid + 1, right);

    for (int i = left; i <= right; i++)
    {
        selectedIdx = i;
        ready.release(); 
        value.acquire(); 
    }


    std::vector<int> temp(right - left + 1);
    std::merge(vec.begin() + left, vec.begin() + mid + 1, vec.begin() + mid + 1, vec.begin() + right + 1, temp.begin());

    std::copy(temp.begin(), temp.end(), vec.begin() + left);
}

void merge_sort(std::vector<int> &vec)
{
    merge_sort_recursive(vec, 0, vec.size() - 1);
    completed = true;
    ready.release();
}

void bubble_sort(std::vector<int> &vec)
{
    int n = vec.size();
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (vec[i] > vec[i + 1])
            {
                std::swap(vec[i], vec[i + 1]);
                swapped = true;
                selectedIdx = i + 1;
                ready.release();
                value.acquire();
            }
        }
        n--;
    }
    completed = true;
    ready.release();
}

void insertion_sort(std::vector<int> &vec)
{
    for (int i = 1; i < vec.size(); ++i)
    {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            j--;
            selectedIdx = j;
            ready.release(); 
            value.acquire(); 
        }
        vec[j + 1] = key;
    }
    completed = true;
    ready.release();
}

void selection_sort(std::vector<int> &vec)
{
    for (int i = 0; i < vec.size() - 1; ++i)
    {
        int min_index = i;
        for (int j = i + 1; j < vec.size(); ++j)
        {
            if (vec[j] < vec[min_index])
            {
                min_index = j;
                otherIdx = min_index;
                ready.release();
                value.acquire();
            }
        }
        std::swap(vec[i], vec[min_index]);
        selectedIdx = i;
        ready.release();
        value.acquire();
    }
    completed = true;
    ready.release();
}

int partition(std::vector<int> &vec, int left, int right)
{
    int pivot = vec[right];
    int i = left - 1;
    for (int j = left; j < right; ++j)
    {
        if (vec[j] <= pivot)
        {
            i++;
            std::swap(vec[i], vec[j]);
        }
    }
    std::swap(vec[i + 1], vec[right]);
    for (int i = left; i <= right; i++)
    {
        selectedIdx = i;
        ready.release(); 
        value.acquire(); 
    }

    return i + 1;
}


void quicksort_recursive(std::vector<int> &vec, int left, int right)
{
    
    if (left >= right)
        return;
    
    int p = partition(vec, left, right);
    otherIdx = p;
    
    ready.release();
    value.acquire();

    quicksort_recursive(vec, left, p - 1);
    quicksort_recursive(vec, p + 1, right);
}

void quicksort(std::vector<int> &vec)
{
    quicksort_recursive(vec, 0, vec.size() - 1);
    completed = true;
    ready.release();
}