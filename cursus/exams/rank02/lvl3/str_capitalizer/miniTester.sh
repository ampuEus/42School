#!/bin/bash

# TRICK FOR DE EXAM:
# To test your decimal to hexadecimal convertior use "bc" calculator
# echo ‘obase=16;127’ | bc  ==>  7F

gcc -Wall -Wextra -Werror str_capitalizer.c

COLOR_OK='\033[1;32m'
COLOR_KO='\033[1;31m'
COLOR_END='\033[0m'


result="$(diff <( echo -e ) <( ./a.out ))" &&
	echo -e "$COLOR_OK Test 1: OK$COLOR_END" || echo -e "$COLOR_KO Test 1: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "A First Little Test" ) <( ./a.out "a FiRSt LiTTlE TESt" ))" &&
	echo -e "$COLOR_OK Test 2: OK$COLOR_END" || echo -e "$COLOR_KO Test 2: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "__second Test A Little Bit   Moar Complex" ) <( ./a.out "__SecONd teST A LITtle BiT   Moar comPLEX" ))" &&
	echo -e "$COLOR_OK Test 3: OK$COLOR_END" || echo -e "$COLOR_KO Test 3: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "   But... This Is Not That Complex" ) <( ./a.out "   But... This iS not THAT COMPLEX" ))" &&
	echo -e "$COLOR_OK Test 4: OK$COLOR_END" || echo -e "$COLOR_KO Test 4: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "	Okay, This Is The Last 1239809147801 But Not	The Least	T" ) <( ./a.out "	Okay, this is the last 1239809147801 but not	the least	t" ))" &&
	echo -e "$COLOR_OK Test 5: OK$COLOR_END" || echo -e "$COLOR_KO Test 5: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "__second Test A Little Bit   Moar Complex"
echo -e "   But... This Is Not That Complex"
echo -e "	Okay, This Is The Last 1239809147801 But Not	The Least	T" ) <( ./a.out "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "	Okay, this is the last 1239809147801 but not	the least	t" ))" &&
	echo -e "$COLOR_OK Test 6: OK$COLOR_END" || echo -e "$COLOR_KO Test 6: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e ) <( ./a.out ""))" &&
	echo -e "$COLOR_OK Test 7: OK$COLOR_END" || echo -e "$COLOR_KO Test 7: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e ""
echo -e "") <( ./a.out "" ""))" &&
	echo -e "$COLOR_OK Test 8: OK$COLOR_END" || echo -e "$COLOR_KO Test 8: KO$COLOR_END\n$result\n"
