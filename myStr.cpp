#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
    MyString test = "abcdg";
    MyString test2 = "abcde";
    MyString test3 = test + test2;
    test3.show();
    
    

}
