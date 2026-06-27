## C++ Journey ##

# Day 01
Learned: 
Program structure,#include, main(),cout,endl, using namespace std,return 0.

Confused:
Why std:: is needed all the time(solved with using namespace std).

Revisit: 
Nothing,all clear.

# Day 02
Learned: 
Variables,data types(int double char bool boolalpha float string),cin user input, reserved keywords,arthimetic operators.

Confused by:
int division dropping decimals silently(now understand).

Revisit: flot vs double difference.

# Day 03
Learned: 
Comparison operators (== != <> <= >=),logical operators (&& || !), combining conditions.

Confused:
Remembering not to use a single `=` for comparison, and handling multiple conditions using parentheses `()`.

Revisit: 
Short circuit evalution (how C++ skips checking the second condition if the first one already decided the reults).

# Day 04
Learned:
Conditional statements (if, else if, else)for branching logic, combining conditions inside an if-statement using (||).

Confused:
Remembering that C++ requires full expresions on both sides of an OR operator (e.g., `guess ==6 || guess == 8`, not `guess ==6 || 8`).

Revisit: 
Nested if else statements (putting an if-statement inside another if-statement).

# Day 05
Learned: 
Loops (for, while, do-while), using loops to caculate a running total (Sum Calculaor0, and using the modulo operator (%) to check for divisibility in multiple conditions (FizzBuzz0.

Confused: 
Keeping track of nesting multiple code blocks using curly braces `{}` (boxes inside boxes).

Revisit: 
The layout of nested loops (loops inside loop0 for Day 6.

# Day 06
Learned:
Nested loops (loops inside loops) and how they step through multi-dimensional structures, and loop control statements (`break` to exit completely and `continue` to skip the current round).

Confused: 
Visualizing how the inner loop fully resets and repeats every time the outer loop ticks forward by one.

Revisit:
Creating more complex patterns (like pyramids or grids) using nested loops.

# Day 07
Learned: 
Designiing modular custom functions with specific return types and parameters to isolate logic and keep `main()` clean.

Deep Dive:
Iplemented defensive programming (`if (b == 0)`) to intercept critical hardware-level devision crahes before they happen, and managed data-type precision using `double` to prevent decimal truncation.

Next Step: 
Exploring functions that execute tasks without returing a value (`void` funcxtions).

# Day 08
Learned: 
1. How to see raw memory addrsses in RAM using th (&) symbol.
   
2. How to use void functions that do an action without returning values.

What was confusing but cleared up:
Why a swap fails without a temp variable because values get overwritten.
How x and y act as nicknames pointing directly to the original variables a and b.

What is useful:
Pass by reference lets a function change variables in main permanently.
