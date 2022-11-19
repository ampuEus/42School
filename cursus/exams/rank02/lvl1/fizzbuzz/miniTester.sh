#!/bin/bash
gcc -Wall -Werror -Wextra fizzbuzz.c

COLOR_OK='\033[1;32m'
COLOR_KO='\033[1;31m'
COLOR_END='\033[0m'

result="$(diff desired_output <( ./a.out ))" &&
	echo -e "$COLOR_OK Test: OK$COLOR_END" || echo -e "$COLOR_KO Test: KO$COLOR_END\n$result\n"

