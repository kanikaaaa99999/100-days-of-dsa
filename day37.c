#include<stdio.h>
#include<string.h>

#define MAX 100

int pq[MAX];
int n = 0;

void insert(int x)
{
    int i;

    if(n == MAX)
    {
        printf("Queue Overflow\n");
        return;
    }

    i = n - 1;

    while(i >= 0 && pq[i] > x)
    {
        pq[i+1] = pq[i];
        i--;
    }

    pq[i+1] = x;
    n++;
}

int delete()
{
    if(n == 0)
        return -1;

    int val = pq[0];

    for(int i = 0; i < n-1; i++)
        pq[i] = pq[i+1];

    n--;

    return val;
}

int peek()
{
    if(n == 0)
        return -1;

    return pq[0];
}

int main()
{
    int N, x;
    char op[10];

    scanf("%d",&N);

    for(int i=0;i<N;i++)
    {
        scanf("%s",op);

        if(strcmp(op,"insert")==0)
        {
            scanf("%d",&x);
            insert(x);
        }

        else if(strcmp(op,"delete")==0)
        {
            printf("%d\n",delete());
        }

        else if(strcmp(op,"peek")==0)
        {
            printf("%d\n",peek());
        }
    }

    return 0;
}