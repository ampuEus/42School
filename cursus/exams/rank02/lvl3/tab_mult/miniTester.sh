#!/bin/bash

gcc -Wall -Wextra -Werror tab_mult.c

COLOR_OK='\033[1;32m'
COLOR_KO='\033[1;31m'
COLOR_END='\033[0m'


result="$(diff <( echo -e ) <( ./a.out ))" &&
	echo -e "$COLOR_OK Test 1: OK$COLOR_END" || echo -e "$COLOR_KO Test 1: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "1 x 0 = 0"
echo -e "2 x 0 = 0"
echo -e "3 x 0 = 0"
echo -e "4 x 0 = 0"
echo -e "5 x 0 = 0"
echo -e "6 x 0 = 0"
echo -e "7 x 0 = 0"
echo -e "8 x 0 = 0"
echo -e "9 x 0 = 0") <( ./a.out 0))" &&
	echo -e "$COLOR_OK Test 2: OK$COLOR_END" || echo -e "$COLOR_KO Test 2: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "1 x 1 = 1"
echo -e "2 x 1 = 2"
echo -e "3 x 1 = 3"
echo -e "4 x 1 = 4"
echo -e "5 x 1 = 5"
echo -e "6 x 1 = 6"
echo -e "7 x 1 = 7"
echo -e "8 x 1 = 8"
echo -e "9 x 1 = 9") <( ./a.out 1))" &&
	echo -e "$COLOR_OK Test 3: OK$COLOR_END" || echo -e "$COLOR_KO Test 3: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "1 x 2 = 2"
echo -e "2 x 2 = 4"
echo -e "3 x 2 = 6"
echo -e "4 x 2 = 8"
echo -e "5 x 2 = 10"
echo -e "6 x 2 = 12"
echo -e "7 x 2 = 14"
echo -e "8 x 2 = 16"
echo -e "9 x 2 = 18") <( ./a.out 2))" &&
	echo -e "$COLOR_OK Test 4: OK$COLOR_END" || echo -e "$COLOR_KO Test 4: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "1 x 9 = 9"
echo -e "2 x 9 = 18"
echo -e "3 x 9 = 27"
echo -e "4 x 9 = 36"
echo -e "5 x 9 = 45"
echo -e "6 x 9 = 54"
echo -e "7 x 9 = 63"
echo -e "8 x 9 = 72"
echo -e "9 x 9 = 81") <( ./a.out 9))" &&
	echo -e "$COLOR_OK Test 5: OK$COLOR_END" || echo -e "$COLOR_KO Test 5: KO$COLOR_END\n$result\n"
result="$(diff <(echo -e "1 x 10 = 10"
echo -e "2 x 10 = 20"
echo -e "3 x 10 = 30"
echo -e "4 x 10 = 40"
echo -e "5 x 10 = 50"
echo -e "6 x 10 = 60"
echo -e "7 x 10 = 70"
echo -e "8 x 10 = 80"
echo -e "9 x 10 = 90") <( ./a.out 10))" &&
	echo -e "$COLOR_OK Test 6: OK$COLOR_END" || echo -e "$COLOR_KO Test 6: KO$COLOR_END\n$result\n"
result="$(diff <( echo -e "1 x 19 = 19\n2 x 19 = 38"
echo -e "3 x 19 = 57"
echo -e "4 x 19 = 76"
echo -e "5 x 19 = 95"
echo -e "6 x 19 = 114"
echo -e "7 x 19 = 133"
echo -e "8 x 19 = 152"
echo -e "9 x 19 = 171") <( ./a.out 19))" &&
	echo -e "$COLOR_OK Test 7: OK$COLOR_END" || echo -e "$COLOR_KO Test 7: KO$COLOR_END\n$result\n"
