#include <iostream>

const int SIZE = 20;

int LinerSearch(int arr[],int ele)
{
    for(auto i=0;i<SIZE;++i)
    {
        if(arr[i] == ele)
            return i;
    }
    return -1;
}

int main()
{
    int arr[SIZE],n;
    // filling array with some numbers for testing
    for(auto i=0;i<SIZE;++i)
        arr[i] = (i+10);
    
    std::cout<<"Enter element which you want to search : ";
    std::cin>>n;

    int pos = LinerSearch(arr, n);
    if (pos != -1)
        std::cout<<"Element Found at positon : "<<pos+1;
    else
        std::cout<<"No Such Element!";
    std::cout<<std::endl;
    return 0;
}