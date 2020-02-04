#include <iostream>

void computeLPS(int LPS[],std::string pattern)
{
    LPS[0] = 0;
    for(auto i=1,j=0,k=1;i<pattern.length();)
    {
        if(pattern[i] == pattern[j])
        {
            LPS[k] = j + 1;
            i++;
            j++;
            k++;
        }
        else
        {
            if(j == 0)
            {
                i++;
                LPS[k] = 0;
                k++;
            }
            else
            {
                j = LPS[j-1];
            }
            
        }
        
    }
}

int kmp(std::string text, std::string pattern)
{
    int LPS[pattern.length()],i,j;
    computeLPS(LPS,pattern);
    for(i=0,j=0;i<text.length();)
    {
        if(text[i] == pattern[j])
        {
            i++;
            j++;    
        }
        else
        {
            if(j == 0)
            {
                i++;
            }
            else
            {
                j = LPS[j-1];
            }
            
        }
        if(j == pattern.length())
        {
            std::cout<<"Found Pattern at : "<<i-j+1;
        }   
    }
}

int main()
{   /* taking a test case to test the algorithm */
    std::string text = "ababcabcabababd";
    std::string pattern = "ababd";
    kmp(text,pattern);
    std::cout<<std::endl;
    return 0;
}