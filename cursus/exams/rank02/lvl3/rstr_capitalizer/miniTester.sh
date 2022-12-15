#!/bin/bash

# TRICK FOR DE EXAM:
# To test your decimal to hexadecimal convertior use "bc" calculator
# echo ‘obase=16;127’ | bc  ==>  7F

gcc -Wall -Wextra -Werror print_hex.c

COLOR_OK='\033[1;32m'
COLOR_KO='\033[1;31m'
COLOR_END='\033[0m'


result="$(diff <( echo -e "" ) <( ./a.out ))" &&
	echo -e "$COLOR_OK Test 1: OK$COLOR_END" || echo -e "$COLOR_KO Test 1: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "1" ) <( ./a.out "1" ))" &&
	echo -e "$COLOR_OK Test 2: OK$COLOR_END" || echo -e "$COLOR_KO Test 2: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "8" ) <( ./a.out "8" ))" &&
	echo -e "$COLOR_OK Test 3: OK$COLOR_END" || echo -e "$COLOR_KO Test 3: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "0" ) <( ./a.out "0" ))" &&
	echo -e "$COLOR_OK Test 4: OK$COLOR_END" || echo -e "$COLOR_KO Test 4: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "a" ) <( ./a.out "10" ))" &&
	echo -e "$COLOR_OK Test 5: OK$COLOR_END" || echo -e "$COLOR_KO Test 5: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "f" ) <( ./a.out "15" ))" &&
	echo -e "$COLOR_OK Test 6: OK$COLOR_END" || echo -e "$COLOR_KO Test 6: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "ff" ) <( ./a.out "255" ))" &&
	echo -e "$COLOR_OK Test 7: OK$COLOR_END" || echo -e "$COLOR_KO Test 7: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "3d26" ) <( ./a.out "15654" ))" &&
	echo -e "$COLOR_OK Test 8: OK$COLOR_END" || echo -e "$COLOR_KO Test 8: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "4eae66" ) <( ./a.out "5156454" ))" &&
	echo -e "$COLOR_OK Test 9: OK$COLOR_END" || echo -e "$COLOR_KO Test 9: KO$COLOR_END\n$result\n"
