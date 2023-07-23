# Find stuff related to C++ & furthermore on Modern-C++ too

* strings
* containers
* random access iterators
* dynamic memory allocation
* templace based code
* polymorphism using c++
* pointers & smart pointers
* move semantics
* Uniform initialization
* Lambda expression
* constexpr
* multi-threading

__Compilation Behind The Scenes__

-> preprocess : remove comments, macros substitution, includes header contents

-> compiler : gives assembly code

-> assembler : gives out object code

-> loader : loads dll, if any



C++11 (Released in 2011):

Auto: Type inference using the auto keyword for automatic type deduction.
Range-based for loops: Simplified looping over container elements using for (element : container).
nullptr: Introduces a null pointer literal nullptr.
Lambda Expressions: Anonymous functions can be defined using lambda expressions.
Rvalue References and Move Semantics: Introduced && for move semantics and perfect forwarding.
Smart Pointers: std::unique_ptr, std::shared_ptr, and std::weak_ptr for better memory management.
Initializer Lists: Initialization of containers using {} syntax.
Static Assertions: static_assert for compile-time assertions.
Delegating Constructors: One constructor can call another within the same class.
Explicit Conversion Operators: explicit conversion operators for user-defined types.
Override and Final Specifiers: override and final for virtual function overriding control.
Thread Support Library: std::thread, std::mutex, and other threading primitives.
Regular Expressions: Standard support for regular expressions using std::regex.
std::function: A general-purpose polymorphic function wrapper.
std::chrono: Library for working with time and durations.
New String literals: Support for raw string literals (R"...") and Unicode literals.
Type Traits: Template meta-programming enhancements using std::is_* type traits.
C++14 (Released in 2014):

Return Type Deduction for Functions: Automatic deduction of return types using auto in function declarations.
Variable Templates: Variables can be templated like functions with constexpr.
Generic Lambdas: Lambda expressions can use auto in parameter lists to define generic lambdas.
std::make_unique: Helper function for creating std::unique_ptr with less boilerplate.
Relaxed constexpr: More flexibility in using constexpr.
Binary Literals and Digit Separators: Support for binary literals (0b1101) and digit separators (1'000'000).
std::index_sequence: A utility for generating compile-time sequences of integers.
std::exchange: Allows safe exchange of values between variables.
std::hash improvements: Hashing for more types, including standard containers.
C++17 (Released in 2017):

Structured Bindings: Decomposition of structured objects into individual variables.
if constexpr: Compile-time conditional execution based on the value of a template argument.
Inline Variables: Variables can be defined inline in headers.
Fold Expressions: Variadic template expansion in a concise form using ....
namespace std::filesystem: Filesystem library for portable file system operations.
std::optional: A container for optional values, which may or may not contain a value.
std::variant: A container for holding one value out of many alternative types.
std::any: A container for holding any type of value.
Parallel Algorithms: Parallel versions of standard algorithms like std::for_each.
New Standard Attributes: [[fallthrough]], [[maybe_unused]], [[nodiscard]], etc.
std::string_view: A non-owning view of a character sequence, often used for performance improvements.
C++20 (Released in 2020):

Concepts: Introduces constraints to template parameters using the requires keyword.
Ranges: The Standard Ranges Library provides new algorithms and adaptors for ranges.
Coroutines: Support for coroutines with co_await, co_yield, etc.
Three-way Comparisons: Default comparison operators using the <=> operator.
Modules: A new way to organize and encapsulate code in modular units.
std::span: A non-owning view of a contiguous sequence, similar to std::string_view.
std::format: String formatting library with Python-like syntax.
std::atomic_ref: Non-owning references to atomic objects.
Synchronized Output Streams: std::osyncstream for synchronized output to std::cout.
Calendar and Time Zone: Calendars and time zone support in the standard library.
std::bit_cast: Type punning with safety guarantees.
std::erase_if: Erasing elements from a container satisfying a condition.
std::atomic<float> and std::atomic<double>: Support for floating-point atomics.
C++23 (Expected release in 2023):
As my knowledge was last updated in September 2021, I don't have access to the features introduced in C++23. However, it's expected to bring further improvements and new features to the language.

Please note that this is not an exhaustive list, but it covers many of the significant features introduced in each C++ version. Additionally, compiler support may vary, and it's always a good idea to check the compiler documentation for specific feature support.