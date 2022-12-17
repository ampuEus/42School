#!/bin/bash

gcc -Wall -Wextra -Werror tab_mult.c

COLOR_OK='\033[1;32m'
COLOR_KO='\033[1;31m'
COLOR_END='\033[0m'


result="$(diff <( echo -e ) <( ./a.out ))" &&
	echo -e "$COLOR_OK Test 1: OK$COLOR_END" || echo -e "$COLOR_KO Test 1: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e ) <( ./a.out 1))" &&
	echo -e "$COLOR_OK Test 2: OK$COLOR_END" || echo -e "$COLOR_KO Test 2: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e ) <( ./a.out 2))" &&
	echo -e "$COLOR_OK Test 3: OK$COLOR_END" || echo -e "$COLOR_KO Test 3: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "1 x 9 = 9\n2 x 9 = 18\n3 x 9 = 27\n4 x 9 = 36\n5 x 9 = 45\n6 x 9 = 54\n7 x 9 = 63\n8 x 9 = 72\n9 x 9 = 81\n") <( ./a.out 9))" &&
	echo -e "$COLOR_OK Test 4: OK$COLOR_END" || echo -e "$COLOR_KO Test 4: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e ) <( ./a.out 10))" &&
	echo -e "$COLOR_OK Test 5: OK$COLOR_END" || echo -e "$COLOR_KO Test 5: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "1 x 19 = 19\n2 x 19 = 38\n3 x 19 = 57\n4 x 19 = 76\n5 x 19 = 95\n6 x 19 = 114\n7 x 19 = 133\n8 x 19 = 152\n9 x 19 = 171\n") <( ./a.out 19))" &&
	echo -e "$COLOR_OK Test 6: OK$COLOR_END" || echo -e "$COLOR_KO Test 6: KO$COLOR_END\n$result\n"
