#include <iostream>
#include <stack>
#include <string>


int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(std::string s)
{
    std::stack<char> st;
    st.push('N');
    std::string ns;
    int length = s.length();
    for(int i = 0 ; i < length ; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            ns += s[i];
        }
        else if(s[i] == '(')
        {
            st.push('(');
        }
        else if(s[i] == ')')
        {
            while(st.top() != 'N' && st.top() != '(')
            {
                char ch = st.top();
                st.pop();
                ns += ch;
            }
            if (st.top() == '(')
            {
                char ch = st.top();
                st.pop();
            }
        }
        else
        {
            while (st.top() != 'N' && precedence(s[i]) <= precedence(st.top()))
            {
                char ch = st.top();
                st.pop();
                ns += ch;
            }
            st.push(s[i]);
        }
    }
    while(st.top() != 'N')
    {
        char ch = st.top();
        st.pop();
        ns += ch;
    }

    std::cout<<ns<<std::endl;
}

int main()
{
    std::string s = "(a+b)*c+d";
    infixToPostfix(s);
    std::cout<<std::endl;
    return 0;
}