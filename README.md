# GRAFTlib
GReg's Arena FuncTions Library - The C standard library utilizing a memory arena and fitting the norm

# Purpose
GRAFTlib is a library designed to meet the 42 school's norminette (see coding standards below) while utilizing a memory arena. As such all functions included in this library are based on the C standard library but instead of using malloc, they allocate the data into the arena. This library is to provide Hive Helsinki, and the 42 schools at large, an opportunity to contribute to an open source project that is in turn useful for the community. 

# Coding Standards
42 Schools require very strict code formatting. In order for this library to be of use it follows the same standards. While we do not necessarily agree with them, this code would not be of use for fellow students otherwise. If you are unsure of what the standards are then review the norm, or run norminette. When submitting code to be included the following standards of norminette must be met:
- Functions are no more than 25 lines long,
- Functions are no more than 80 characters wide,
- Functions take no more than 4 parameters,
- Functions that take no parameters must have void in the prototype,
- Function can have no more than 5 variables,
- Maximum 5 functions per file,
- Everything must be in Snakecase e.g.: function_name(), int big_num, t_linked_list,
- Structs must start with s_, Enums with e_, Typedef'd data structures with t_,
- Every file must have a 42 school header from the student who created it.
- More to come as we remember them.

# Contribution Requirements
In order to contribute to this project you must be a current 42 school student or graduate. Your code must meet the above standards. Just run norminette to check. And it must include the following:
- Every function requires documentation,
- Documentation must be in Javadoc,
- All helper functions must be made static,
- Function names must be  "verb_noun" e.g.: get_list_length(),
- NO PUSHING TO MAIN
- All contributions require a Pull Request and a Code Review
