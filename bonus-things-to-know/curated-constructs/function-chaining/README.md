__function_chaining__

* `Reference type function(parameters)` and `return *this` to maintain the context.

* Otherwise, the chained functions will get called on returned temporary object, rendering calls unusable.