#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

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
    
    
    return 0;
}
