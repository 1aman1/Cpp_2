__const_cast__

* use only when the original variable is not constant in nature.

* It should only be used when it is explicitly required.

* Use when any api has parameters of type non-const, where our arguments are of type const. In order to make these compatible, we can use const_cast, given that the api doesn't do any modifications on the arguments supplied.

__dynamic_cast__

* A derived class pointer when made to hold a base class object, will get sparsity in memory, hence this is invalid.

* opposite fact holds when base is made to point to derived, it is completely valid. 

* a base type pointer is upgraded, object knowledge remains same.

* However this may not be the case when, variables are actual object, and not pointer to objects.

* A pointer to 'Base' class type holding object of type 'Derived' can't be typecasted to a level lower than derived class in hierarchy. It will result in seg-fault / throw exception bad_cast.

* However, A pointer to 'Base' class type holding object of type 'Derived' can be typecasted to a higher than or equal to the level of derived class in hierarchy.  

* This needs atleast one virtual function in the base class, i.e., relies on polymorphic related information.

* This cast has a runtime overhead due to the fact that it uses RTTI to operate.

* This should only be used where 1% chance are that a cast may fail, otherwise if cast is completely valid i.e., 100% success kind, then dynamic_cast can be avoided solely due to performance reasons, and static_cast would do just fine.

* This is sort of a supervisor, whether a cast is valid or not, capable of returning nullptr when cast fails.

__static_cast__

* for making explicit conversions.

* This is for regular casts also because this is much easier to spot in regular code rather than c-style silent casts.

* Catches few implicit conversions that are illegal but somehow allowed by c-style cast, like un-related pointer types.

* It does not do runtime validation, it is a compile time cast.

* Use with conversion operator and conversion constructor.