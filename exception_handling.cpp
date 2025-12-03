#include <iostream>

using namespace std;

int main()
{
    int n,d;
    cin >> n >> d;
    int result;
    try
    {
        if(d == 0)
        {
            throw d;
        }
        result = n/d;
    }
    catch(int ex)
    {
        cout << "Divide by zero not allowed - " << ex << "\n";
    }
    //int result = n/d; //exception will occur here
    cout << result << "\n";
}