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
    T(int v, const char* n);//1
    int value;//2
    std::string name;//3
};

T::T(int v, const char* n) : value(v), name(n) {}

struct Eval                                //4
{
    T* compare(T* a, T* b) //5
    {
        if( a->value < b->value ) return a;
        if( a->value > b->value ) return b;
        return nullptr;
    }
};

struct U
{
    float firstValue { 0 }, secondValue { 0 };
    float memberFunction(float* updatedValue)      //12
    {
        if (updatedValue != nullptr)
        {
			std::cout << "U's X value: " << firstValue << std::endl;
			firstValue = *updatedValue;
			std::cout << "U's X updated value: " << firstValue << std::endl;
            while (std::abs(secondValue - firstValue) > 0.001f)
            {
                while (std::abs(secondValue - firstValue) > 0.1f)
                {
                    secondValue += (firstValue > secondValue) ? 0.1f : -0.1f;
                }
                secondValue += (firstValue > secondValue) ? 0.001f : -0.001f;
			}
		}
		std::cout << "nullptr passed to memberFunction." << std::endl;
        return firstValue;
    }
};

struct StaticStruct
{
    static float staticFunction(U* that, float* updatedValue )        //10
    {
        std::cout << "U's X value: " << that->firstValue << std::endl;
        that->firstValue = *updatedValue;
        std::cout << "U's X updated value: " << that->firstValue << std::endl;
        while( std::abs(that->secondValue - that->firstValue) > 0.001f )
        {
            /*
             write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
             */
            while (std::abs(that->secondValue - that->firstValue) > 0.1f)
            {
				that->secondValue += (that->firstValue > that->secondValue) ? 0.1f : -0.1f;
            }
			that->secondValue += (that->firstValue > that->secondValue) ? 0.001f : -0.001f;
        }
        std::cout << "U's Y updated value: " << that->secondValue << std::endl;
        return that->secondValue * that->firstValue;
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
    T highValue(10, "High Value");                                             //6
    T lowValue(1, "Low Value");                                             //6

    Eval f;                                            //7
    auto* smaller = f.compare(&highValue, &lowValue);                              //8
    if (smaller != nullptr) {std::cout << "the smaller one is << " << smaller->name << std::endl;} //9
    
    U values1;
    U values1;
    float updatedValue = 5.f;
    std::cout << "staticfuntion's multiplied values: " << StaticStruct::staticFunction( &values1, &updatedValue) << std::endl;                  //11
    
    U values2;
    std::cout << "member function's multiplied values: " << values2.memberFunction( &updatedValue ) << std::endl;
}
