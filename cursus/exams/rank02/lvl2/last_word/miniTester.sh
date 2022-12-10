#!/bin/bash
gcc -Wall -Wextra -Werror last_word.c

COLOR_OK='\033[1;32m'
COLOR_KO='\033[1;31m'
COLOR_END='\033[0m'

result="$(diff <( echo -e "PONY" ) <( ./a.out "FOR PONY" ))" &&
	echo -e "$COLOR_OK Test 1: OK$COLOR_END" || echo -e "$COLOR_KO Test 1: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "not" ) <( ./a.out "this        ...       is sparta, then again, maybe    not" ))" &&
	echo -e "$COLOR_OK Test 2: OK$COLOR_END" || echo -e "$COLOR_KO Test 2: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "" ) <( ./a.out "   " ))" &&
	echo -e "$COLOR_OK Test 3: OK$COLOR_END" || echo -e "$COLOR_KO Test 3: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "" ) <( ./a.out "   " ))" &&
	echo -e "$COLOR_OK Test 4: OK$COLOR_END" || echo -e "$COLOR_KO Test 4: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "" ) <( ./a.out "a" "b" ))" &&
	echo -e "$COLOR_OK Test 5: OK$COLOR_END" || echo -e "$COLOR_KO Test 5: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "lorem,ipsum" ) <( ./a.out "  lorem,ipsum  " ))" &&
	echo -e "$COLOR_OK Test 6: OK$COLOR_END" || echo -e "$COLOR_KO Test 6: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "" ) <( ./a.out "" ))" &&
	echo -e "$COLOR_OK Test 7: OK$COLOR_END" || echo -e "$COLOR_KO Test 7: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "" ) <( ./a.out  ))" &&
	echo -e "$COLOR_OK Test 8: OK$COLOR_END" || echo -e "$COLOR_KO Test 8: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "agur" ) <( ./a.out "Kaixo agur" ))" &&
	echo -e "$COLOR_OK Test 9: OK$COLOR_END" || echo -e "$COLOR_KO Test 9: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "zaude?" ) <( ./a.out "zer moduz zaude?" ))" &&
	echo -e "$COLOR_OK Test 10: OK$COLOR_END" || echo -e "$COLOR_KO Test 10: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "zaude???" ) <( ./a.out "zer moduz zaude???" ))" &&
	echo -e "$COLOR_OK Test 11: OK$COLOR_END" || echo -e "$COLOR_KO Test 11: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "Kaixo" ) <( ./a.out "Kaixo" ))" &&
	echo -e "$COLOR_OK Test 12: OK$COLOR_END" || echo -e "$COLOR_KO Test 12: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "Kaixo" ) <( ./a.out "   Kaixo" ))" &&
	echo -e "$COLOR_OK Test 13: OK$COLOR_END" || echo -e "$COLOR_KO Test 13: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "123" ) <( ./a.out "123" ))" &&
	echo -e "$COLOR_OK Test 14: OK$COLOR_END" || echo -e "$COLOR_KO Test 14: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "__123__" ) <( ./a.out "__123__" ))" &&
	echo -e "$COLOR_OK Test 15: OK$COLOR_END" || echo -e "$COLOR_KO Test 15: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "_" ) <( ./a.out "  123 _" ))" &&
	echo -e "$COLOR_OK Test 16: OK$COLOR_END" || echo -e "$COLOR_KO Test 16: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "_" ) <( ./a.out "  123 _ " ))" &&
	echo -e "$COLOR_OK Test 17: OK$COLOR_END" || echo -e "$COLOR_KO Test 17: KO$COLOR_END\n$result\n"
