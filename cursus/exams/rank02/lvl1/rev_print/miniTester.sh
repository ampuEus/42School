#!/bin/bash
gcc -Wall -Wextra -Werror rev_print.c

COLOR_OK='\033[1;32m'
COLOR_KO='\033[1;31m'
COLOR_END='\033[0m'

result="$(diff <( echo -e "cba" ) <( ./a.out "abc" ))" &&
	echo -e "$COLOR_OK Test 1: OK$COLOR_END" || echo -e "$COLOR_KO Test 1: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "!oxiaK" ) <( ./a.out "Kaixo!" ))" &&
	echo -e "$COLOR_OK Test 2: OK$COLOR_END" || echo -e "$COLOR_KO Test 2: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "zaz" ) <( ./a.out "zaz" ))" &&
	echo -e "$COLOR_OK Test 3: OK$COLOR_END" || echo -e "$COLOR_KO Test 3: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "LIOP a 0bud" ) <( ./a.out "dub0 a POIL" ))" &&
	echo -e "$COLOR_OK Test 4: OK$COLOR_END" || echo -e "$COLOR_KO Test 4: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "" ) <( ./a.out "" ))" &&
	echo -e "$COLOR_OK Test 5: OK$COLOR_END" || echo -e "$COLOR_KO Test 5: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e ) <( ./a.out ))" &&
	echo -e "$COLOR_OK Test 6: OK$COLOR_END" || echo -e "$COLOR_KO Test 6: KO$COLOR_END\n$result\n"
