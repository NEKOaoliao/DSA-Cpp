#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    queue<int> playerA;
    queue<int> playerB;

    int nA, nB, temp;

    printf("Please enter number of cards of A\n");
    scanf("%d", &nA);
    printf("Please enter the sequence of the card,once a time\n");
    for (int i = 0; i < nA; i++)
    {
        scanf("%d", &temp);
        playerA.push(temp);
    }

    printf("Please enter number of cards of B\n");
    scanf("%d", &nB);
    printf("Please enter the sequence of the card,once a time\n");
    for (int i = 0; i < nB; i++)
    {
        scanf("%d", &temp);
        playerB.push(temp);
    }

    vector<int> book(10, 0);

    stack<int> cardDesk;

    while (playerB.size() > 0 && playerA.size() > 0)
    {
        // player A action
        temp = playerA.front();
        playerA.pop();
        if (book[temp])
        {
            playerA.push(temp);
            while (cardDesk.top() != temp)
            {
                playerA.push(cardDesk.top());
                book[cardDesk.top()]--;
                cardDesk.pop();
            }
            playerA.push(cardDesk.top());
            book[cardDesk.top()]--;
            cardDesk.pop();
        }
        else
        {
            cardDesk.push(temp);
            book[temp]++;
        }

        if (playerA.empty())
            break;
        // Player B action
        temp = playerB.front();
        playerB.pop();
        if (book[temp])
        {
            playerB.push(temp);
            while (cardDesk.top() != temp)
            {
                playerB.push(cardDesk.top());
                book[cardDesk.top()]--;
                cardDesk.pop();
            }
            playerB.push(cardDesk.top());
            book[cardDesk.top()]--;
            cardDesk.pop();
        }
        else
        {
            cardDesk.push(temp);
            book[temp]++;
        }
    }

    if (playerA.empty())
    {
        printf("B Wins!");
        printf("\nB's cards are: ");
        while (playerB.size())
        {
            printf("%d ", playerB.front());
            playerB.pop();
        }
    }
    else
    {
        printf("A Win!");
        printf("\nA's cards are: ");
        while (playerA.size())
        {
            printf("%d ", playerA.front());
            playerA.pop();
        }
    }
    printf("\nCards on the desk are: ");
    while (cardDesk.size())
    {
        printf("%d ", cardDesk.top());
        cardDesk.pop();
    }
    return 0;
}