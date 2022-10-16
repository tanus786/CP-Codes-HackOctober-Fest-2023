//function overloading
#include <iostream>
using namespace std;

template <class T>
class rishi
{
public:
    T data;
    rishi(T a)
    {
        data = a;
    }
    void display();
};
//How to write display outwards
template <class T>
void rishi<T>::display()
{
    cout << data << endl;
}

void func(int a)
{
    cout << "I am first func()" << a << endl;
}

template <class T>
void func(T a)
{
    cout << "I am templatised func()" << a << endl;
}

int main()
{
    rishi<int> r(4);
    cout << r.data << endl;
    r.display();

    func(4); //exact match takes higher priority
    func(3.5);
    return 0;
}
