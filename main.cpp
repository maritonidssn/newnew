#include <iostream>

using namespace std;
int main() {
    // NUMBER 1
    // int a, b, c;

    // cout << "Enter the first num: ";
    // cin >> a;
    // cout << "Enter the second num: ";
    // cin >> b;    
    // cout << "Enter the third num: ";
    // cin >> c;    

    // int largest = a;
    // if (b > largest) 
    // {
    //     largest = b; /* code */
    // }
    // else if (c > largest)
    // {
    //     largest = c;
    // }
    
    // cout << "The largest num is " << largest;


    // NUMBER 2
    // int a, b; 
    // cout << "Enter the first num: ";
    // cin >> a;

    // char op;
    // cout << "Enter operator: ";
    // cin >> op;
    
    // cout << "Enter the second num: ";
    // cin >> b;

    // switch (op) {
    //     case '+': cout << a + b ;
    //     break;
    //     case '-': cout << a - b;
    //     break;
    //     case '*': cout << a * b;
    //     break;
    //     case '/': 
    //     if (b == 0) {
    //         cout << "cannot be divided by 0";
    //     }
    //     else {
    //         cout << a / b;
    //     }
    //     break;

        

    // }
    
    int a;
    cout << "Enter a num: ";
    cin >> a;

    for (int i = 1; i <= 10; i++) {
        cout << a << "x" << i << "=" << a * i << endl;
    }



    
    
    return 0;
}
