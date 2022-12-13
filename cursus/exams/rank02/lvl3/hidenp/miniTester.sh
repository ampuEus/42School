#!/bin/bash
gcc -Wall -Wextra -Werror hidenp.c

COLOR_OK='\033[1;32m'
COLOR_KO='\033[1;31m'
COLOR_END='\033[0m'

result="$(diff <( echo -e "1" ) <( ./a.out "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" ))" &&
	echo -e "$COLOR_OK Test 1: OK$COLOR_END" || echo -e "$COLOR_KO Test 1: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "1" ) <( ./a.out "abc" "2altrb53c.sse" ))" &&
	echo -e "$COLOR_OK Test 2: OK$COLOR_END" || echo -e "$COLOR_KO Test 2: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "0" ) <( ./a.out "abc" "btarc" ))" &&
	echo -e "$COLOR_OK Test 3: OK$COLOR_END" || echo -e "$COLOR_KO Test 3: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "" ) <( ./a.out ))" &&
	echo -e "$COLOR_OK Test 4: OK$COLOR_END" || echo -e "$COLOR_KO Test 4: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "" ) <( ./a.out "1" ))" &&
	echo -e "$COLOR_OK Test 5: OK$COLOR_END" || echo -e "$COLOR_KO Test 5: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "0" ) <( ./a.out "11" "2"))" &&
	echo -e "$COLOR_OK Test 6: OK$COLOR_END" || echo -e "$COLOR_KO Test 6: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "" ) <( ./a.out "1" "2" "3"))" &&
	echo -e "$COLOR_OK Test 7: OK$COLOR_END" || echo -e "$COLOR_KO Test 7: KO$COLOR_END\n$result\n"
