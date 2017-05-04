/*
 
 LAMDA REFERENCE CODE
 
 */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>

using namespace std;

/* lambda format
 
 [capture list](parameter list){function body}
 
 [](){cout << "Foo";}
 
 */


// simple lambda
void simpleLambdaFn(vector<int>& v) {
    cout << "simpleLambdaFn called...\n";
    for_each(v.begin(), v.end(), [](int) {
        /* do stuff */
        cout << "do stuff...\n";
    }
    );
}

// abs sort lambda
void absSortLambda(float* x, unsigned n)  {
    cout << "absSortLambda called...\n";
    sort(x, x + n,
         // lambda begins
         [](float a, float b) {
             cout << "Abs sorting..\n";
             return (abs(a) < abs(b));
         }
    );
}

int main() {
    // insert code here...
    std::cout << "Lambda Expressions\n";
    
    
    // use simple lambda
    vector<int> hector = {1, 2, 3};
    
    simpleLambdaFn(hector);
    
    float x = -3.000008;
    absSortLambda(&x, 4);
    
    // simple lambda in for each algorithm
    list<int> myList = {1, 3, 5, 7, 9};
    for_each(myList.begin(), myList.end(), [](int i){ cout << i << ' ';});
    
    cout << "\n";
    
    // capture list by value, reference
    int y = 99;
    cout << "lambda capture y by value" << endl;
    auto lamdaVal = [y]() {cout << y << endl;};
    for (int i = 0; i < 5; i++) {
        y++;
        lamdaVal();
    }

    y = 99; // reset
    cout << "lambda capture y by reference" << endl;
    auto lamdaRef = [&y]() {cout << y << endl;};
    for (int i = 0; i < 5; i++) {
        y++;
        lamdaRef();
    }
    
    // trailing return type
    int captured = 10;
    vector<int> myVec{ 20, 40, 60, 80, 100 };
    cout << "All elements are bigger than captured value? ";
    cout << boolalpha << all_of(myVec.begin(), myVec.end(),
           [captured](int& p) -> bool {
               // comment for length
               if (p > 0) {
                   // just chekcing
               }
               return p > captured;
           });

    cout << "\n";
    
    vector<int> lechter = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // summ all integers, default capture all by reference (&)
    int sum = 0;
    for_each(lechter.begin(), lechter.end(), [&](int x){sum += x;});
    cout << "sum of ints: " << sum << endl;
    
    // find odd or even integers with capture
    size_t c;
    c = count_if(lechter.begin(), lechter.end(), [](int x){return x % 2;});
    cout << "number of odds: " << c << endl;
    
    return 0;
}



