#!/bin/bash

clear
echo "====== h ======"
./convert h
# char: 'h'
# int: 104
# float: 104.0f
# double: 104.0
echo
echo "====== hh ======"
./convert hh
# char: impossible
# int: impossible
# float: impossible
# double: impossible
echo
echo "====== 0 ======"
./convert 0
# char: Non displayable
# int: 0
# float: 0.0f
# double: 0.0
echo
echo "====== nan ======"
./convert nan
# char: impossible
# int: impossible
# float: nanf
# double: nan
echo
echo "====== nanf ======"
./convert nanf
# char: impossible
# int: impossible
# float: nanf
# double: nan
echo
echo "====== +inf ======"
./convert +inf
# char: impossible
# int: impossible
# float: inff
# double: inf
echo
echo "====== +inff ======"
./convert +inff
# char: impossible
# int: impossible
# float: inff
# double: inf
echo
echo "====== -inf ======"
./convert -inf
# char: impossible
# int: impossible
# float: -inff
# double: -inf
echo
echo "====== -inff ======"
./convert -inff
# char: impossible
# int: impossible
# float: -inff
# double: -inf
echo
echo "====== 42.0f ======"
./convert 42.0f
# char: '*'
# int: 42
# float: 42.0f
# double: 42.0
echo
echo "====== 3.0f ======"
./convert 3.0f
# char: Non displayable
# int: 3
# float: 3.0f
# double: 3.0