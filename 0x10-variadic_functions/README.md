Variadic Functions in C
Variadic functions in C are functions that can take a variable number of arguments. These functions are particularly useful when you need a function that can handle different types or a different number of parameters. The standard library in C provides a set of macros in the stdarg.h header to work with variadic functions.

stdarg.h Macros
1. va_start
Description: Initializes the va_list to point to the first unnamed argument.
Syntax: void va_start(va_list ap, last_named_argument);
2. va_arg
Description: Retrieves the next argument from the va_list.
Syntax: type va_arg(va_list ap, type);
You need to specify the type of the argument you're retrieving.
3. va_end
Description: Cleans up the va_list after you're done using it.
Syntax: void va_end(va_list ap);
