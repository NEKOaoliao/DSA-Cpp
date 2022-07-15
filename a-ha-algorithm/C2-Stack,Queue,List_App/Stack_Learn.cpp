//回文数
#include <stack>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string myString;
    cin >> myString;
    int len = myString.length();
    int mid = len / 2;
    stack<char> myStack;

    for (int i = len - 1; i >= mid; i--)
    {
        myStack.push(myString[i]);
    }

    if (len % 2)
        myStack.pop();

    for (int i = mid - 1; i >= 0; i--)
    {
        if (myStack.top() == myString[i])
        {
            myStack.pop();
        }
        else
        {
            printf("False");
            return 0;
        }
    }

    printf("Yes");
    return 0;
}
