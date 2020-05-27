/*****************
 * Problem - Find all prime numbers between 1 and a given number n
 * 
 *          An integer n > 1 is called a prime number if its only positive divisor are 1 and n;
 *          otherwise, n is a composite number.
 *          if n > 1 is not prime, i.e if n is composite, then n must have a divisor k != 1 (k not equal to 1)
 *          such that k <= sqrt(n) or equally we can say k^2 <= n
 * 
 * Sieve Method ->
 *          
 *          suppose we want to find all prime numbers less than a given number n such as 30. Then usig sieve method
 *          First list the 30 numbers
 *          1   2   3   4   5   6   7   8   9   10
 *          11  12  13  14  15  16  17  18  19  20
 *          21  22  23  24  25  26  27  28  29  30
 * 
 *          cross out 1 and multiples of 2 form the list the remaning list is
 * 
 *          2   3   5   7   9   11  13  15  17  19
 *          21  23  25  27  29
 *          
 *          since 3 is the first number following 2 that has not been eliminated, cross
 *          out the multiples of 3 from the list, now the remaning list is
 *          
 *          2   3   5   7   11  13  17  19  23  25
 *          29
 *      
 *          sine 5 is the first number following 3 that has not been eliminated, cross out
 *          the multiples of 5 from the list, now the reamaning list is
 *          
 *          2   3   5   7   11  13  17  19  23  29
 * 
 *          Now 7 is the first number following 5 that has not been eliminated, but 7^2 > 30. This
 *          means the algorithm is finished and the numbers left are the prime numbers less than 30
 *      
 *          2   3   5   7   11  13  17  19  23  29
 * 
 * Algorithm ->
 *          in crossout function instead of crossing the element we set it to 1, 1 means crossed element
 * 
 *          step1 -> initilize an array with numbers from 1 to n
 *          step2 -> for i=0 till i<sqrt(n) 
 *                      if (array[i] is not 1)
 *                          then cross the multiples of array[i]
 *                    repeat the loop till the condition i<sqrt(i) becomes false
 * 
 * 
 * *****************/



#include <iostream>
#include <math.h>

void cross(int arr[], int k, int size, int start)
{
    for(;start<size;++start)
    {
        if(arr[start] % k == 0)
            arr[start] = 1;
    }
}

int main()
{
    int n;
    std::cout<<"Enter Number : ";
    std::cin>>n;
    int arr[n];
    for(auto i = 0;i<n;i++)
        arr[i] = i + 1;

    for(auto i=0;i<sqrt(n);++i)
    {
        if(arr[i] != 1)
            cross(arr,arr[i],n,i+1);
    }

    std::cout<<"Prime Numbers between 1 and "<<n<<" : ";
    for(auto i = 0; i<n;i++)
    {
        if (arr[i] != 1)
            std::cout<<arr[i]<<"  ";
    }
    std::cout<<std::endl;
    return 0;
}