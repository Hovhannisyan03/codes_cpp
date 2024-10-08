#include <iostream>

void countingSort(int* arr, int size)
{
    int max = arr[0];
    for(int i = 1; i < size; ++i)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
    
    int count[max + 1] = {0};

    for(int i = 0; i < size; ++i)
    {
        ++count[arr[i]];
    } 
    for(int i = 1; i < max + 1; ++i)
    {
        count[i] += count[i - 1];
    } 
        
    int output[size];


    for(int i = size - 1; i >= 0; --i)
    {
        output[count[arr[i]]- 1] = arr[i];
        --count[arr[i]];
    }

    for(int i = 0; i < size; ++i)
    {
        arr[i] = output[i];
    }
}

int main()
{
    int size = 0;
    std::cin >> size;
    int *arr = new int[size];

    for(int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    } 

    countingSort(arr,size);

    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    } 
}
