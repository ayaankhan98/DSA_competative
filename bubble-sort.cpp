/*********************************************************
 *  Suppose a list of numbers A[1],A[2],A[3],.......,A[N] is in memory. The bubble sort algorithm works as follows
 *  BubbleSort Algorithm -
 *                  step (1) -> Compare A[1] and A[2] and arrange them in desired order, so that A[1] < A[2].
 *                              Then compare A[2] and A[3] and arrange them so that A[2] < A[3]. Then Compare 
 *                              A[3] and A[4] and arrange them so that A[3] < A[4]. Continue till we compare
 *                              A[N-1] with A[N] and arrange them so that A[N-1] < A[N]
 * 
 * Observe that step (1) involves n-1 comparisons. During step 1, the largest element bubbled up to the nth position. When
 * step 1 is completed A[N] will contain the largest element.
 *                  step (2) -> Repeat step (1) with one less comparison, that is now we stop after we compare and possibly
 *                              rearrange A[N-2] and A[N-1], When Step(2) Second largest element will occupy the
 *                              A[N-1] position of array
 *                  step (3) -> Repeat step 1 again until you possibly rearrange A[1] and A[2] 
 * 
 * After n-1 steps the list will be sorted in incresing order
 * 
 * *******************************************************/



#include <iostream>

const int SIZE = 10;

void bsort(int arr[])
{
    int temp;
    for(int i=SIZE-1;i!=0;i--)
    {
        for(int j=0;j<SIZE-1;++j)
        {
            if(arr[j] < arr[j+1])    // this will sort the array in increasing order, in order to sort the array in
                                    // decreasing order use arr[j] > arr[j+1]
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int arr[SIZE] = {43,6,2,7,34,13,76,2,3,876};  // taking some initial values to test the algorithm
    bsort(arr);                                     // calling the bsort function on the array to sort it
    for(auto i=0;i<SIZE;++i)
        std::cout<<arr[i]<<"  ";                    // printing the sorted version of array
    std::cout<<std::endl;
    return 0;
}