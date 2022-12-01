#!/bin/bash
gcc -Wall -Wextra -Werror search_and_replace.c

COLOR_OK='\033[1;32m'
COLOR_KO='\033[1;31m'
COLOR_END='\033[0m'

result="$(diff <( echo -e "Klixo" ) <( ./a.out "Kaixo" "a" "l" ))" &&
	echo -e "$COLOR_OK Test 1: OK$COLOR_END" || echo -e "$COLOR_KO Test 1: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "Popoche est un sobre" ) <( ./a.out "Papache est un sabre" "a" "o" ))" &&
	echo -e "$COLOR_OK Test 2: OK$COLOR_END" || echo -e "$COLOR_KO Test 2: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e ) <( ./a.out "zaz" "art" "zul" ))" &&
	echo -e "$COLOR_OK Test 3: OK$COLOR_END" || echo -e "$COLOR_KO Test 3: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "zaz" ) <( ./a.out "zaz" "r" "u" ))" &&
	echo -e "$COLOR_OK Test 4: OK$COLOR_END" || echo -e "$COLOR_KO Test 4: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e ) <( ./a.out "jacob" "a" "b" "c" "e" ))" &&
	echo -e "$COLOR_OK Test 5: OK$COLOR_END" || echo -e "$COLOR_KO Test 5: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "ZaZ eT David aiME le METal." ) <( ./a.out "ZoZ eT Dovid oiME le METol." "o" "a" ))" &&
	echo -e "$COLOR_OK Test 6: OK$COLOR_END" || echo -e "$COLOR_KO Test 6: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "eNcOre Un ExEmPle Pas Facile a Ecrire " ) <( ./a.out "wNcOre Un ExEmPle Pas Facilw a Ecrirw " "w" "e" ))" &&
	echo -e "$COLOR_OK Test 7: OK$COLOR_END" || echo -e "$COLOR_KO Test 7: KO$COLOR_END\n$result\n"
