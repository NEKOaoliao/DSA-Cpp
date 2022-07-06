#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    //输入部分
    int num, i, j, k, temp;
    scanf("%d", &num);
    vector<int> data;
    for (i = 0; i < num; i++)
    {
        scanf("%d", &temp);
        data.push_back(temp);
    }

    //控制排序是否继续进行
    bool flag = true;
    //记录最后一个未交换的元素
    int indexOFLastUnsortedElement = num - 1;
    //记录被交换的元素
    int swapIndex = 0;
    //核心代码
    for (j = 0; j < num - 1; j++)
    {
        if (!flag) //判断是否需要交换
            break;
        flag = false;
        //内部循环交换
        for (k = 1; k <= indexOFLastUnsortedElement; k++)
        {
            //判断交换
            if (data[k] < data[k - 1])
            {
                swap(data[k], data[k - 1]);
                flag = true;       //交换后置为true
                swapIndex = k - 1; //记录本轮被交换的元素
            }
        }
        indexOFLastUnsortedElement = swapIndex; //将被记录的最后一个本轮交换的元素记入
    }

    //输出
    for (int item : data)
        printf(" %d ", item);

    return 0;
}