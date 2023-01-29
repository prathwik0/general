#include <iostream>
using namespace std;

class data
{
    int i;
    char c;
    float f;
    data()
    {
        i = 0;
        c = 's';
        f = 10.23;
    }
    data(int x, char y, float z)
    {
        i = x;
        c = y;
        f = z;
    }
    data(data &d2)
    {
        i = d2.i;
        c = d2.c;
        f = d2.f;
    }
    data(int x, char y, float z = 2.3)
    {
        i = x;
        c = y;
        f = z;
    }
    void display()
    {
        cout << endl;
        cout << "i : " << i << endl;
        cout << "c : " << c << endl;
        cout << "f : " << f << endl;
    }
}

int
main()
{
    data d1;
    cout << "d1 : " << endl;
    d1.display();

    data d2(10, 'q', 2, 2);
    cout << "d2 : " << endl;
    d2.display();

    data d3(22, 'e');
    cout << "d3 : " << endl;
    d3.display();

    data d4(d2)
            cout
        << "d2 : " << endl;
    d4.display();

    return 0;
}