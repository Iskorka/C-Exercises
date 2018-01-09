#include <iostream>
#include "smartpointer.h"

using namespace std;

class A
{
public:
    explicit A(int a) : m_a(a){}
    ~A(){cout<<"A is destroyed\n";}
    void foo(){cout<<"foo\n";}
private:
    int m_a;
};

SmartPointer<A> foo(const int &b)
{
    SmartPointer<A> buf(new A(b));

    return buf;
}

int main()
{
    A *a = new A(3);
    SmartPointer<A> p1(a);
    SmartPointer<A> p2(p1);
    SmartPointer<A> p3 = p1;

//    SmartPointer<A> p4 = move(foo(2));
//    SmartPointer<A>p5=move(foo(2));
//    p5=static_cast<SmartPointer<A>&&>(p4);

//    SmartPointer<A> p6 = foo(5);

    return 0;
}

