/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* valueName) : value(v), name(valueName) {}   //1
    int value;//2 
    std::string name;//3
};

struct ReturnSmallerInt                                //4
{
    T* compare(T& a, T& b) //5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;   
        return nullptr;
    }
};

struct U
{
    float uVar1 { 0 }, uVar2 { 0 };
    float update(float& updatedValue)      //12
    {
        std::cout << "U's uVar1 value: " << uVar1 << std::endl;
        uVar1 = updatedValue;
        std::cout << "U's uVar1 updated value: " << uVar1 << std::endl;
        while(std::abs(uVar2 - uVar1) > 0.001f)
        {
            this->uVar2 += 0.01f;
        }
        std::cout << "U's uVar2 updated value: " << uVar2 << std::endl;
        return uVar2 * uVar1;
    }
};

struct updateVar
{
    static float update(U& that, float& updatedValue)        //10
    {
        std::cout << "U's uVar1 value: " << that.uVar1 << std::endl;
        that.uVar1 = updatedValue;
        std::cout << "U's uVar1 updated value: " << that.uVar1 << std::endl;
        while( std::abs(that.uVar2 - that.uVar1) > 0.001f )
        {
            /*
             write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
             */
            that.uVar2 += 0.01f;
        }
        std::cout << "U's uVar2 updated value: " << that.uVar2 << std::endl;
        return that.uVar2 * that.uVar1; 
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T t1(8,"tInstance1");                                             //6
    T t2(9,"tInstance2");                                             //6
    
    ReturnSmallerInt f;                                            //7
    auto * smaller = f.compare(t1, t2);                              //8
    if(smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl;
    }
    else
    {
        std::cout << "The two values in comparison are equal to each other in value." << std::endl;
    }
    
     //9
    
    U uInstance1;
    float updatedValue = 5.f;
    std::cout << "[static func] uInstance1's multiplied values: " << updateVar::update(uInstance1, updatedValue) << std::endl;                  //11
    
    U uInstance2;
    std::cout << "[member func] uInstance2's multiplied values: " << uInstance2.update(updatedValue) << std::endl;
}
