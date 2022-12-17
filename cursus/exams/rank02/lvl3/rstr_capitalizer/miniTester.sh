#!/bin/bash

gcc -Wall -Wextra -Werror rstr_capitalizer.c

COLOR_OK='\033[1;32m'
COLOR_KO='\033[1;31m'
COLOR_END='\033[0m'


result="$(diff <( echo -e ) <( ./a.out ))" &&
	echo -e "$COLOR_OK Test 1: OK$COLOR_END" || echo -e "$COLOR_KO Test 1: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "A firsT littlE tesT" ) <( ./a.out "a FiRSt LiTTlE TESt" ))" &&
	echo -e "$COLOR_OK Test 2: OK$COLOR_END" || echo -e "$COLOR_KO Test 2: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "seconD tesT A littlE biT   moaR compleX" ) <( ./a.out "SecONd teST A LITtle BiT   Moar comPLEX" ))" &&
	echo -e "$COLOR_OK Test 3: OK$COLOR_END" || echo -e "$COLOR_KO Test 3: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "   but... thiS iS noT thaT compleX" ) <( ./a.out "   But... This iS not THAT COMPLEX" ))" &&
	echo -e "$COLOR_OK Test 4: OK$COLOR_END" || echo -e "$COLOR_KO Test 4: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "	okay, thiS iS thE lasT 1239809147801 buT noT	thE leasT	T" ) <( ./a.out "	Okay, this is the last 1239809147801 but not	the least	t" ))" &&
	echo -e "$COLOR_OK Test 5: OK$COLOR_END" || echo -e "$COLOR_KO Test 5: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "seconD tesT A littlE biT   moaR compleX"
echo -e "   but... thiS iS noT thaT compleX"
echo -e "	okay, thiS iS thE lasT 1239809147801 buT noT	thE leasT	T" ) <( ./a.out "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "	Okay, this is the last 1239809147801 but not	the least	t" ))" &&
	echo -e "$COLOR_OK Test 6: OK$COLOR_END" || echo -e "$COLOR_KO Test 6: KO$COLOR_END\n$result\n"
