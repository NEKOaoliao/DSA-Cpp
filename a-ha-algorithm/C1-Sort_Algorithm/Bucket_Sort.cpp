#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int num, i, temp;
    scanf("%d", &num);
    vector<int> data;
    for (i = 0; i < num; i++)
    {
        scanf("%d", &temp);
        data.push_back(temp);
    }
}