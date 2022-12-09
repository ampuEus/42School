#!/bin/bash
gcc -Wall -Wextra -Werror inter.c

COLOR_OK='\033[1;32m'
COLOR_KO='\033[1;31m'
COLOR_END='\033[0m'

result="$(diff <( echo -e "Kaixo" ) <( ./a.out "Kaixo" "sdafdfsKdfidfgxdfgog" ))" &&
	echo -e "$COLOR_OK Test 1: OK$COLOR_END" || echo -e "$COLOR_KO Test 1: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "Kaix" ) <( ./a.out "Kaixo" "sdafdfsKdfidfgxdfgg" ))" &&
	echo -e "$COLOR_OK Test 2: OK$COLOR_END" || echo -e "$COLOR_KO Test 2: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "" ) <( ./a.out "Kaixo" "12345" ))" &&
	echo -e "$COLOR_OK Test 3: OK$COLOR_END" || echo -e "$COLOR_KO Test 3: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "Kaixo" ) <( ./a.out "Kaaaixo" "sdafaaadfsKdKKfidfgxdfgog" ))" &&
	echo -e "$COLOR_OK Test 4: OK$COLOR_END" || echo -e "$COLOR_KO Test 4: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "Kaioxo" ) <( ./a.out "Kaaaiooxooo" "sdafaaadfsKdKKfidfgxdfgog" ))" &&
	echo -e "$COLOR_OK Test 5: OK$COLOR_END" || echo -e "$COLOR_KO Test 5: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "padinton" ) <( ./a.out "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" ))" &&
	echo -e "$COLOR_OK Test 6: OK$COLOR_END" || echo -e "$COLOR_KO Test 6: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "df6ewg4" ) <( ./a.out ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd ))" &&
	echo -e "$COLOR_OK Test 7: OK$COLOR_END" || echo -e "$COLOR_KO Test 7: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "rien" ) <( ./a.out "rien" "cette phrase ne cache rien" ))" &&
	echo -e "$COLOR_OK Test 8: OK$COLOR_END" || echo -e "$COLOR_KO Test 8: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "" ) <( ./a.out "Kaixo" "" ))" &&
	echo -e "$COLOR_OK Test 9: OK$COLOR_END" || echo -e "$COLOR_KO Test 9: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "" ) <( ./a.out "" "Kaixo" ))" &&
	echo -e "$COLOR_OK Test 10: OK$COLOR_END" || echo -e "$COLOR_KO Test 10: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "" ) <( ./a.out "" "" ))" &&
	echo -e "$COLOR_OK Test 11: OK$COLOR_END" || echo -e "$COLOR_KO Test 11: KO$COLOR_END\n$result\n"
