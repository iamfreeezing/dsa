#include <iostream>
using namespace std;

int main() {

    int num = 5;

    /*

    memory has symbol table, which stores:
    variable name : memory address
    => num : 120
    => p : 080 
    and at address 120 => a box containing 5.

    
    */

    int *p = &num; 
    //data type that stores address    =    //address
    //at address 080 (p) => 120 is stored.
    //p is a pointer to an int

    int *dontDo; //garbage value can be anything, might be some important memory address.
                //ALWAYS initialize.

    int *doThis = 0; //right way to initialize, point to a memory add that DNE (0)
                //segmentation fault
    doThis = &num;

    cout << *p << endl;     //* = dereference operator
    cout << num << endl;
    cout << *doThis << endl;

    int *copying = 0;
    copying = p;

    cout << "initial p: " << p << " -- " << copying << endl;

    p = p + 1; //value of p (address) increases by  4 (reaches next integer, ek se badhta to same hi int rehta)
                // that is, it reaches the next int. will increase by 1 if char to reach next char etc.
                //in case of an array, points to next element

    cout << "after pointer + 1: " << &num + 1 << endl;


    /*
    ----------- when value changes and when it doesnt ---------------------------------------
    
    when a (int/char etc.) variable is passed to a function, its copy is created. (pass by value)
    but arrays are always passed by reference.

    int num = 5;
    int a = num;
    they point to different copies of 5;
    a++ doesn't change num.

    int num = 5; 
    int *ptr = &num; 
    int a = *ptr;
    they point to different copies of 5;
    a++ doesn't change num.

    (*ptr)++ changes num.
    
    ----------- when value changes and when it doesnt ---------------------------------------

    */

   
   //size of pointer = 8 (for all datatypes, as it stores address always)


    return 0;
}