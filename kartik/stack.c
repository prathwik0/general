#include <stdio.h>
#include <stdlib.h>
#define N 5

// Defining Stack Structure
typedef struct stack
{
    int top;
    int a[N];
} stack;

// Initializing the elements to stack
void push(int x, stack *s)
{
    if (s->top == N - 1)
    {
        printf("\nOverflow");
    }
    else
    {
        printf("\nThe element to be pushed : %d", x);
        s->top++;
        s->a[s->top] = x;
    }
}

// Deleting an element from stack
void pop(stack *s)
{
    if (s->top == -1)
    {
        printf("\n Underflow");
    }
    else
    {
        int x = s->a[s->top];
        printf("\nThe deleted item is %d", x);
        s->top--;
    }
}

// Displaying the elements
void display(stack *s)
{
    if (s->top == -1)
    {
        printf("\nStack is empty");
    }
    else
    {
        for (int i = 0; i <= s->top; i++)
        {
            printf("%d", s->a[i]);
        }
        printf("\n");
    }
}

int main()
{
    struct stack s;
    s.top = -1;
    int element, item, ch; //'ch' means choice
    while (1)
    {
        printf("\nEnter your choice : ");
        printf("\n1.Push \n2.Pop \n3.Display \n4.Exit \n\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter the element : ");
            scanf("%d", &item);
            push(item, &s);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            display(&s);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nInvalid");
        }
    }
    return 0;
}