#include <cstdio>
#include <vector>
using namespace std;
#define MAX 1001
int main()
{
    int num, i, j, temp;
    scanf("%d", &num);
    vector<int> book(MAX, 0);
    for (i = 0; i < num; i++)
    {
        scanf("%d", &temp);
        book[temp]++; //向桶里放
    }

    for (j = 0; j < MAX; j++)
    {
        while (book[j] > 0)
        {
            printf(" %d ", j);
            book[j]--; //按顺序从桶里取出来
        }
    }
}