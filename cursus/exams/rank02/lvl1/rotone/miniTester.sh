#!/bin/bash
gcc -Wall -Wextra -Werror rotone.c

COLOR_OK='\033[1;32m'
COLOR_KO='\033[1;31m'
COLOR_END='\033[0m'

result="$(diff <( echo -e "bcdBCD" ) <( ./a.out "abcABC" ))" &&
	echo -e "$COLOR_OK Test 1: OK$COLOR_END" || echo -e "$COLOR_KO Test 1: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "yzaYZA" ) <( ./a.out "xyzXYZ" ))" &&
	echo -e "$COLOR_OK Test 2: OK$COLOR_END" || echo -e "$COLOR_KO Test 2: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "Lbjyp" ) <( ./a.out "Kaixo" ))" &&
	echo -e "$COLOR_OK Test 3: OK$COLOR_END" || echo -e "$COLOR_KO Test 3: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo." ) <( ./a.out "Les stagiaires du staff ne sentent pas toujours tres bon." ))" &&
	echo -e "$COLOR_OK Test 4: OK$COLOR_END" || echo -e "$COLOR_KO Test 4: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "BlkiA aMLJKa , 23z " ) <( ./a.out "AkjhZ zLKIJz , 23y " ))" &&
	echo -e "$COLOR_OK Test 5: OK$COLOR_END" || echo -e "$COLOR_KO Test 5: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e ) <( ./a.out "" ))" &&
	echo -e "$COLOR_OK Test 6: OK$COLOR_END" || echo -e "$COLOR_KO Test 6: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e ) <( ./a.out ))" &&
	echo -e "$COLOR_OK Test 7: OK$COLOR_END" || echo -e "$COLOR_KO Test 7: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "__ BHVS !!" ) <( ./a.out "__ AGUR !!" ))" &&
	echo -e "$COLOR_OK Test 8: OK$COLOR_END" || echo -e "$COLOR_KO Test 8: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "aFs ??" ) <( ./a.out "zEr ??" ))" &&
	echo -e "$COLOR_OK Test 9: OK$COLOR_END" || echo -e "$COLOR_KO Test 9: KO$COLOR_END\n$result\n"
