/*****************************
 * Problem - An array of numerical values in memory is given we
 *           want to find the location of largest element and the largest
 *           element in the given array
 * Algorithm -
 *            setp 1 ->  initially let the max (max = first element) to be maximum and set the location to be 1
 *            setp 2 ->  now compare the max with the next element of the array
 *              if the next element is greater than max
 *                      set the value of max equal to this element and update location to location of this element
 *              repeat loop go to step 2
*****************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>

int main()
{
    /**** initilizing a sample array with some random numbers for testing the algorithm ****/
    srand(time(0));
    const long int size = 1000000;
    int arr[size];
    for(int i =0 ;i<size;i++)
        arr[i] = rand();
    
    // setting the first element of array to be maximum
    int max = arr[0];
    // setting the location of max element (max element is first {assumption} thereform set loc to 0)
    int loc =0 ;

    for(int i=0;i<size;i++)
    {
        // checking if the assumed max is less than the next element of array
        if (max < arr[i])
        {
            // if the assumed element max is less
            // then update the location of new maximum element
            loc = i;
            // update the max element
            max = arr[i];
        }
    }
    std::cout<<"Max Element : "<<max<<" at position : "<<loc;
    std::cout<<std::endl;
    return 0;
}