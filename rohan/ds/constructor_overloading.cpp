#include <iostream>
using namespace std;

class fuck
{
    int i;
    char c;
    float f;

public:
    fuck()
    {
        i = 0;
        c = 's';
        f = 10.23;
    }

    fuck(int x, char y, float z)
    {
        i = x;
        c = y;
        f = z;
    }

    fuck(fuck &d2)
    {
        i = d2.i;
        c = d2.c;
        f = d2.f;
    }

    fuck(int x, char y)
    {
        float z = 2.3;
        i = x;
        c = y;
        f = z;
    }

    void display()
    {
        cout << "i : " << i << endl;
        cout << "c : " << c << endl;
        cout << "f : " << f << endl;
        cout << endl;
    }
};

int main()
{
    fuck d1;
    cout << "d1 : " << endl;
    d1.display();

    fuck d2(10, 'q', 2);
    cout << "d2 : " << endl;
    d2.display();

    fuck d3(22, 'e');
    cout << "d3 : " << endl;
    d3.display();

    fuck d4(d2);
    cout << "d4 : " << endl;
    d4.display();

    return 0;
}