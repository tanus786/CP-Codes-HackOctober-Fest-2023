#include <stdio.h>
#include <stdlib.h>

struct stack
{
    char data;
    struct stack *next;
};

void push(struct stack **top, char ch)
{
    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
    temp->data = ch;
    temp->next = NULL;
    if (*top == NULL)
    {
        *top = temp;
        return;
    }
    temp->next = *top;
    *top = temp;
}
char pop(struct stack **top)
{
    struct stack *t;
    char p;
    t = *top;
    if (t == NULL)
    {
        *top = NULL;
        return 0;
    }
    p = t->data;
    *top = t->next;
    return p;
}
int checkPrecedence(char ch)
{
    // printf("%c ", ch);
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else if (ch == '(' || ch == '{')
        return -1;
    else
        return -1;
}
void convert(char *ch)
{
    struct stack *top = NULL;
    char output[50];

    int i = 0, p = 0;
    while (ch[i] != '\0')
    {

        if ((ch[i] >= 'a' && ch[i] <= 'z') || (ch[i] >= 0 && ch[i] <= 9))
        {
            printf("%c", ch[i]);
            output[p] = ch[i];
            p++;
        }
        else if (ch[i] == '(' || ch[i] == '{')
            push(&top, ch[i]);
        else if (ch[i] == ')' || ch[i] == '}')
        {
            while (top->data != '(')
            {

                output[p] = ch[i];
                p++;

                printf("%c", pop(&top));
            }
            pop(&top);
        }
        else
        {
            if (top == NULL)
                push(&top, ch[i]);
            else if (checkPrecedence(ch[i]) > checkPrecedence(top->data))
            {
                push(&top, ch[i]);
            }
            else
            {
                while (top != NULL && (checkPrecedence(ch[i]) <= checkPrecedence(top->data)))
                {
                    if (ch[i] != '(' || ch[i] != '{')
                    {
                        output[p] = ch[i];
                        p++;
                    }
                    printf("%c", pop(&top));
                }
                push(&top, ch[i]);
            }
        }
        i++;
    }
    while (top != NULL)
    {
        if (ch[i] != '(')
        {
            output[p] = ch[i];
            p++;
        }

        printf("%c", pop(&top));
    }
  
}

int main()
{
    char c[] = "(a+b/d^e*f)^(g*h-i^j)*k+p"; 

    convert(c);
    return 0;
}