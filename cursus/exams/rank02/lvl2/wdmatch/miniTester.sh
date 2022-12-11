#!/bin/bash
gcc -Wall -Wextra -Werror wdmatch.c

COLOR_OK='\033[1;32m'
COLOR_KO='\033[1;31m'
COLOR_END='\033[0m'

result="$(diff <( echo -e "faya" ) <( ./a.out "faya" "fgvvfdxcacpolhyghbreda" ))" &&
	echo -e "$COLOR_OK Test 1: OK$COLOR_END" || echo -e "$COLOR_KO Test 1: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "" ) <( ./a.out "faya" "fgvvfdxcacpolhyghbred" ))" &&
	echo -e "$COLOR_OK Test 2: OK$COLOR_END" || echo -e "$COLOR_KO Test 2: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "quarante deux" ) <( ./a.out "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " ))" &&
	echo -e "$COLOR_OK Test 3: OK$COLOR_END" || echo -e "$COLOR_KO Test 3: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "" ) <( ./a.out "error" rrerrrfiiljdfxjyuifrrvcoojh ))" &&
	echo -e "$COLOR_OK Test 4: OK$COLOR_END" || echo -e "$COLOR_KO Test 4: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "" ) <( ./a.out "" ""))" &&
	echo -e "$COLOR_OK Test 5: OK$COLOR_END" || echo -e "$COLOR_KO Test 5: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "" ) <( ./a.out ))" &&
	echo -e "$COLOR_OK Test 6: OK$COLOR_END" || echo -e "$COLOR_KO Test 6: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "" ) <( ./a.out "Kaixo"))" &&
	echo -e "$COLOR_OK Test 7: OK$COLOR_END" || echo -e "$COLOR_KO Test 7: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "Kaixo" ) <( ./a.out "Kaixo" "Kaixoo"))" &&
	echo -e "$COLOR_OK Test 8: OK$COLOR_END" || echo -e "$COLOR_KO Test 8: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "" ) <( ./a.out "Kaixo" "Kaixoo" "3"))" &&
	echo -e "$COLOR_OK Test 9: OK$COLOR_END" || echo -e "$COLOR_KO Test 9: KO$COLOR_END\n$result\n"
