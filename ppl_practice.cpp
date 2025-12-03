// #include <bits/stdc++.h>
// using namespace std;

// class employee
// {
//     public:
//     int emp_id;
//     string emp_name;

//     void print_name();
// };

// void employee :: print_name()
// {
//     cout <<emp_name;
// }
// int main()
// {

//     employee emp_1;

//     emp_1.emp_id = 1;
//     emp_1.emp_name = "Shivansh\n";

//     emp_1.print_name();
//     int a = 10;
//     int* ptr;
//     ptr = &a;
//     // //free(a);
//     // cout << ptr << "\n" << *ptr << "\n";
//     // ++*ptr;
//     // cout << ptr << "\n" << *ptr << "\n";
//     // *ptr++;
//     // cout << ptr << "\n" << *ptr << "\n";

//     int b[5];

//     for(int i = 9; i < 9+5; ++i)
//     {
//         b[i-9] = i;
//     }

//     int(*q)[5];
//     q = &b;
//     cout << **q;
//     ++q;
//     cout << "\n";
//     cout << **q;
//     cout << "\n";
//     //b[0] = &a;
//     cout << b[0] << "\n";
//     //q[0] = &a;
//     //cout << (*q)[0];

//     int **x = &ptr;
//     cout << x << " " << *x << " " << **x << "\n";
//     cout << ptr << "\n";
//     char name[5] = "Indi";
//     char Name[6] = "India";
//     cout << name << "\n";
//     cout << Name << "\n";
// }

#include <iostream>
using namespace std;
 
class Employee
{
 
    int passwd;
public:
    static int count; //static variable
    string eName;
 
    void setName(string name)
    {
        eName = name;
        count++;
        passwd = 99;
    }
    
    int getpasswd()
    {
        return passwd;
    }
    static int getCount()//static method
    {
        return count;
    }

    friend void make_passwd(Employee emp, int val);
    //int make_passwd();
};

void make_passwd(Employee emp, int val)
{
    emp.passwd = val;
}
 
int Employee::count = 0; //defining the value of count
 
int main()
{
    Employee Harry;
    Harry.setName("Harry");
    cout << Employee::getCount() << endl;
    cout << Harry.count << "\n";
    int password = Harry.getpasswd();
    cout << password;
    // make_passwd(Harry, 34);
    // Harry.passwd = 34;
}
