#!/bin/bash
gcc -Wall -Wextra -Werror do_op.c

COLOR_OK='\033[1;32m'
COLOR_KO='\033[1;31m'
COLOR_END='\033[0m'

result="$(diff <( echo -e "20" ) <( ./a.out "10" "+" "10" ))" &&
	echo -e "$COLOR_OK Test 1: OK$COLOR_END" || echo -e "$COLOR_KO Test 1: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "0" ) <( ./a.out "10" "-" "10" ))" &&
	echo -e "$COLOR_OK Test 2: OK$COLOR_END" || echo -e "$COLOR_KO Test 2: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "100" ) <( ./a.out "10" "*" "10" ))" &&
	echo -e "$COLOR_OK Test 3: OK$COLOR_END" || echo -e "$COLOR_KO Test 3: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "1" ) <( ./a.out "10" "/" "10" ))" &&
	echo -e "$COLOR_OK Test 4: OK$COLOR_END" || echo -e "$COLOR_KO Test 4: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "0" ) <( ./a.out "10" "%" "10" ))" &&
	echo -e "$COLOR_OK Test 5: OK$COLOR_END" || echo -e "$COLOR_KO Test 5: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "" ) <( ./a.out "10" "+" "10" "extra" ))" &&
	echo -e "$COLOR_OK Test 6: OK$COLOR_END" || echo -e "$COLOR_KO Test 6: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "" ) <( ./a.out ))" &&
	echo -e "$COLOR_OK Test 7: OK$COLOR_END" || echo -e "$COLOR_KO Test 7: KO$COLOR_END\n$result\n"

result="$(diff <( echo -e "110" ) <( ./a.out "10" "+" "100" ))" &&
	echo -e "$COLOR_OK Test 8: OK$COLOR_END" || echo -e "$COLOR_KO Test 8: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "-5" ) <( ./a.out "10" "-" "15" ))" &&
	echo -e "$COLOR_OK Test 9: OK$COLOR_END" || echo -e "$COLOR_KO Test 9: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "5" ) <( ./a.out "10" "-" "5" ))" &&
	echo -e "$COLOR_OK Test 10: OK$COLOR_END" || echo -e "$COLOR_KO Test 10: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "50" ) <( ./a.out "10" "*" "5" ))" &&
	echo -e "$COLOR_OK Test 11: OK$COLOR_END" || echo -e "$COLOR_KO Test 11: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "5" ) <( ./a.out "10" "/" "2" ))" &&
	echo -e "$COLOR_OK Test 12: OK$COLOR_END" || echo -e "$COLOR_KO Test 12: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "3" ) <( ./a.out "123" "%" "10" ))" &&
	echo -e "$COLOR_OK Test 13: OK$COLOR_END" || echo -e "$COLOR_KO Test 13: KO$COLOR_END\n$result\n"
