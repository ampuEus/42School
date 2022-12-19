#!/bin/bash
gcc -Wall -Wextra -Werror add_prime_sum.c

COLOR_OK='\033[1;32m'
COLOR_KO='\033[1;31m'
COLOR_END='\033[0m'

result="$(diff <( echo -e "10" ) <( ./a.out "5" ))" &&
	echo -e "$COLOR_OK Test 1: OK$COLOR_END" || echo -e "$COLOR_KO Test 1: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "17" ) <( ./a.out "7" ))" &&
	echo -e "$COLOR_OK Test 2: OK$COLOR_END" || echo -e "$COLOR_KO Test 2: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "0" ) <( ./a.out "0" ))" &&
	echo -e "$COLOR_OK Test 3: OK$COLOR_END" || echo -e "$COLOR_KO Test 3: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "0" ) <( ./a.out "" ))" &&
	echo -e "$COLOR_OK Test 4: OK$COLOR_END" || echo -e "$COLOR_KO Test 4: KO$COLOR_END\n$result\n"
