#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node
{
    int value = NULL;
    struct Node *nextNode = nullptr;
};

int main(int argc, const char **argv)
{
    struct Node *head = nullptr, *pointer = nullptr;

    int n, temp;

    scanf("%d", &n);

    scanf("%d", &temp);
    head = new Node;
    head->value = temp;
    pointer = head;
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &temp);
        pointer->nextNode = new Node;
        pointer->nextNode->value = temp;
        pointer = pointer->nextNode;
    }

    pointer = head;
    while (pointer->nextNode != nullptr)
    {
        printf("@@%d\n", pointer->value);
        pointer = pointer->nextNode;
    }
    printf("@@%d\n", pointer->value);

    return 0;
}
