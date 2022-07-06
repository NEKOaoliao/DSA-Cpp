#include <stdio.h>
#include <vector>
using namespace std;

void QuickSort(vector<int> &data, int left, int right);

int main()
{
    int num, i, j, k, temp;
    scanf("%d", &num);
    vector<int> data;
    for (i = 0; i < num; i++)
    {
        scanf("%d", &temp);
        data.push_back(temp);
    }

    QuickSort(data, 0, num - 1);

    for (int item : data)
        printf(" %d ", item);
}

void QuickSort(vector<int> &data, int left, int right)
{
    if (left >= right)
        return;
    int pivot = data[left];
    int l = left, r = right;
    //顺序问题很重要，因为循环条件里有等于，顺序反了的话如果给定数据第一个是最小元素会导致结果出错
    while (l != r)
    {
        //小于的时候停下
        while (data[r] >= pivot && l < r)
            r--;
        //大于的时候停下
        while (data[l] <= pivot && l < r)
            l++;
        //不相等就交换
        if (l < r)
            swap(data[l], data[r]);
    }
    //把pivot放到对应的位置上
    swap(data[left], data[l]);
    //递归
    QuickSort(data, left, l - 1);
    QuickSort(data, l + 1, right);
}
