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
    T(int v, const char* n);
    int value;
    std::string name;
};

T::T(int v, const char* n) : value(v), name(n) {}

struct Eval                                
{
    T& compare(T& a, T& b) 
    {
        if( a->value < b->value ) return a;
        if( a->value > b->value ) return b;
    }
};

struct U
{
    float firstValue { 0 }, secondValue { 0 };
    float memberFunction(float* updatedValue)      
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
    static float staticFunction(U* that, float* updatedValue )        
    {
        std::cout << "U's X value: " << that->firstValue << std::endl;
        that->firstValue = *updatedValue;
        std::cout << "U's X updated value: " << that->firstValue << std::endl;
        while( std::abs(that->secondValue - that->firstValue) > 0.001f )
        {
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

int main()
{
    T highValue(10, "High Value");                                            
    T lowValue(1, "Low Value");                                          

    Eval f;                                           
    auto* smaller = f.compare(&highValue, &lowValue);                              
    if (smaller != nullptr) {std::cout << "the smaller one is << " << smaller->name << std::endl;} 
    
    U values1;
    U values1;
    float updatedValue = 5.f;
    std::cout << "staticfuntion's multiplied values: " << StaticStruct::staticFunction( &values1, &updatedValue) << std::endl;                
    
    U values2;
    std::cout << "member function's multiplied values: " << values2.memberFunction( &updatedValue ) << std::endl;
}
