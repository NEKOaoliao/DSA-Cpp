//模拟
#include <cstdio>
#include <queue>
using namespace std;

int main()
{
    queue<int> myqueue;
    queue<int> ans;
    int n, temp;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        myqueue.push(temp);
    }

    while (myqueue.size())
    {
        ans.push(myqueue.front());
        myqueue.pop();
        myqueue.push(myqueue.front());
        myqueue.pop();
    }

    while (ans.size())
    {
        printf(" %d", ans.front());
        ans.pop();
    }

    return 0;
}