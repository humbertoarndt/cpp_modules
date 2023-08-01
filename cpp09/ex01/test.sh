#!/bin/bash

clear
echo "./RPN '8 9 * 9 - 9 - 9 - 4 - 1 +'"
# Answer: 42
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

sleep 1
echo " "
echo "./RPN '7 7 * 7 -'"
# Answer: 42
./RPN "7 7 * 7 -"

sleep 1
echo " "
echo "./RPN '1 2 * 2 / 2 * 2 4 - +'"
# Answer: 0
./RPN "1 2 * 2 / 2 * 2 4 - +"

sleep 1
echo " "
echo "./RPN '(1 + 1)'"
# Answer: ERROR
./RPN "(1 + 1)"