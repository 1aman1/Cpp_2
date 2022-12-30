__Types of Polymorphism__

* 1-Compile-time Polymorphism.
* 2-Runtime Polymorphism.

> 1-Compile-time Polymorphism.

>> When there are multiple functions with the same name but different parameters, then the functions are said to be overloaded, hence this is known as Function Overloading.

>>> Functions can be overloaded by changing the number of arguments or/and changing the type of arguments. In simple terms, it is a feature of object-oriented programming providing many functions to have the same name but distinct parameters when numerous tasks are listed under one function name.

>> Operator Overloading
>>> C++ has the ability to provide the operators with a special meaning for a data type, this ability is known as operator overloading.

>2-Runtime Polymorphism
>>This type of polymorphism is achieved by Function Overriding. Late binding and dynamic polymorphism are other names for runtime polymorphism. The function call is resolved at runtime in runtime polymorphism. In contrast, with compile time polymorphism, the compiler determines which function call to bind to the object after deducing it at runtime.

>>> Function Overriding
Function Overriding occurs when a derived class has a definition for one of the member functions of the base class. That base function is said to be overridden

>> Virtual Function
A virtual function is a member function that is declared in the base class using the keyword virtual and is re-defined (Overridden) in the derived class. 

>>> Virtual functions are Dynamic in nature, They are defined by inserting the keyword “virtual” inside a base class and are always declared with a base class and overridden in a child class, A virtual function is called during Runtime

@ operator overloading
> making arithmetic operations possible on user defined objects/entities.
> The objects can then be added, multiplied etc.

@ conversion
> used defined types can be converted to primitive types, and vice versa.
We need to tell the compiler how to do that.

@ methods for conversion
> conversion operator OR
> 1 arg constructor

@ pitfalls for conversion
> they ought to have similar meanings, overloaded + must not do multiplication and likewise.
> if a + is overloaded, one can -without being wrong- assume += would also do the same. It's is good to cover the spots.
> the purpose to overload should be there,
for ex: finding a certain character in string, we should not overload && or any other operator for any un-intuitive purpose because the reason to bring operator overloading in picture is to make code more intuitive.

@ catch 
> using conversion operator and 1arg constructor at the same time ?
compiler doesn't like to be confused, it will throw error.
So, keep only one way for conversion.

@ not all operators can be overloaded
> :  
> ::
> .
> ->
> ?:

@ creativity
> only existing operators are overloaded, 
a thought to make up a *&, would be too creative for C++.

