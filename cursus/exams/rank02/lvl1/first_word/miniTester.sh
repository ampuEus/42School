#!/bin/bash
gcc -Wall -Wextra -Werror first_word.c

COLOR_OK='\033[1;32m'
COLOR_KO='\033[1;31m'
COLOR_END='\033[0m'

result="$(diff <( echo -e "Kaixo" ) <( ./a.out "Kaixo" ))" &&
	echo -e "$COLOR_OK Test 1: OK$COLOR_END" || echo -e "COLOR_KOTest 1: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "Kaixo" ) <( ./a.out "   Kaixo" ))" &&
	echo -e "$COLOR_OK Test 2: OK$COLOR_END" || echo -e "COLOR_KOTest 2: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "Kaixo" ) <( ./a.out "Kaixo   " ))" &&
	echo -e "$COLOR_OK Test 3: OK$COLOR_END" || echo -e "COLOR_KOTest 3: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "Kaixo" ) <( ./a.out "   Kaixo   " ))" &&
	echo -e "$COLOR_OK Test 4: OK$COLOR_END" || echo -e "COLOR_KOTest 4: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "Kaixo" ) <( ./a.out "   Kaixo   Kaixo   " ))" &&
	echo -e "$COLOR_OK Test 5: OK$COLOR_END" || echo -e "COLOR_KOTest 5: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "Kaixo" ) <( ./a.out "	Kaixo" ))" &&
	echo -e "$COLOR_OK Test 6: OK$COLOR_END" || echo -e "COLOR_KOTest 6: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "Kaixo" ) <( ./a.out "Kaixo	" ))" &&
	echo -e "$COLOR_OK Test 7: OK$COLOR_END" || echo -e "COLOR_KOTest 7: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "Kaixo" ) <( ./a.out "	Kaixo	" ))" &&
	echo -e "$COLOR_OK Test 8: OK$COLOR_END" || echo -e "COLOR_KOTest 8: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "Kaixo" ) <( ./a.out "	Kaixo	Kaixo" ))" &&
	echo -e "$COLOR_OK Test 9: OK$COLOR_END" || echo -e "COLOR_KOTest 9: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "Kaixo" ) <( ./a.out "	Kaixo	Kaixo	" ))" &&
	echo -e "$COLOR_OK Test 10: OK$COLOR_END" || echo -e "COLOR_KOTest 10: KO$COLOR_END\n$result\n"
result="$(diff <( echo "" ) <( ./a.out  ))" &&
	echo -e "$COLOR_OK Test 11: OK$COLOR_END" || echo -e "COLOR_KOTest 11: KO$COLOR_END\n$result\n"
result="$(diff <( echo "" ) <( ./a.out "" ))" &&
	echo -e "$COLOR_OK Test 12: OK$COLOR_END" || echo -e "COLOR_KOTest 12: KO$COLOR_END\n$result\n"
result="$(diff <( echo "" ) <( ./a.out " " ))" &&
	echo -e "$COLOR_OK Test 13: OK$COLOR_END" || echo -e "COLOR_KOTest 13: KO$COLOR_END\n$result\n"
result="$(diff <( echo "" ) <( ./a.out "	" ))" &&
	echo -e "$COLOR_OK Test 14: OK$COLOR_END" || echo -e "COLOR_KOTest 14: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "Kaixo" ) <( ./a.out "  	  Kaixo 	 Kaixo 	 " ))" &&
	echo -e "$COLOR_OK Test 15: OK$COLOR_END" || echo -e "COLOR_KOTest 15: KO$COLOR_END\n$result\n"
