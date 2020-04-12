#include <iostream>

using namespace std;

int& test(){
    static int a=0;
    a++;
    return a;

}


int main()
{
    cout << ++test() << endl;
    return 0;
}
