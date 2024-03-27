# Base-26 Addition
This is a program that can perform addition of numbers in an unusual base-26 number system. In the base-26 system, 26 different capital letters (A-Z) are used to represent the digits, where A represents 0 and Z represents 25. The value of each digit increases by a factor of 26 as you move to the left.

For example, the base-26 number ZY represents the decimal value of 674, as Z (representing 25) is multiplied by 26^1 and Y (representing 24) is multiplied by 26^0, resulting in a total of 26*25 + 24 = 674.

The program should be able to take input in the form of one or more base-26 numbers separated by "+" signs, and then output the sum of these numbers in the simplest form. For instance, if the input is "ZY + C =", the program should output "BAA", which represents the decimal value of 676 (674 + 2).
