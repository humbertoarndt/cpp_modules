#!/bin/bash

make && clear

BIN=harl

echo -e "\e[1;32mTest 0: DEBUG\e[0m"
./$BIN DEBUG
echo

echo -e "\e[1;32mTest 1: ERROR\e[0m"
./$BIN ERROR
echo

echo -e "\e[1;32mTest 2: INFO\e[0m"
./$BIN INFO
echo

echo -e "\e[1;32mTest 3: No args\e[0m"
./$BIN
echo

echo -e "\e[1;32mTest 4: Invalid level\e[0m"
./$BIN "Humberto"
echo

echo -e "\e[1;32mTest 5: Too many args\e[0m"
./$BIN "Humberto" "Doisberto"
echo