__Internals__

* MAP

* The implementation of an unordered_map is done using a hash table while the implementation of a map is done using a self-balancing binary search tree like Red-Black Tree.

* NOTE: In all the three operations i.e. insertion, deletion, and updation, the best case scenario takes place when the hash function of the unordered_map is good and there are a minimal number of collisions that take place at respective operations. While the worst scenario takes place when the hash table of the unordered_map is not good and there are a very high number of collisions that take place at each operatio

* Benefits of Unordered_map in C++
The unordered_map has the ability to store data in the form of key-value pairs.
The insertion, deletion, and the updation operations have O(1) average time complexity which makes unordered_map a fast data structure.
The searching in the unordered_map is also very fast (O(1) average time complexity) which makes it very useful in the real world.

* Generally, an unordered_map in C++ is faster than map in C++ because the average time complexity for insertion, deletion, and updation is O(1) while in the case of map, the average time complexity for all the operations is O(log(n)) where n is the number of elements present inside the map

* But if we consider the worst case (i.e. when the hashing function is not good), the time complexity for all the operations in an unordered_map is O(n). While the worst case time complexity for all the operations in a map is O(log(n)). Hence, in the worst case scenario, a map is faster than an unordered_map.