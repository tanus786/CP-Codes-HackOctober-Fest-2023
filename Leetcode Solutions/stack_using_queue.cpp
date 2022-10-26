#include <bits/stdc++.h>

using namespace std;
class Stack
{
public:
    queue<int> q;
    void push(int x)
    {
        q.push(x);
        for (auto i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int x = q.front();
        q.pop();
        return x;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};
int main()
{
    Stack st;
    st.push(5);
    st.push(15);
    st.push(45);
    st.push(55);
    cout << st.pop() << " Popped from stack" << endl;
    cout << "top element of stack " << st.top() << endl;
    return 0;
}