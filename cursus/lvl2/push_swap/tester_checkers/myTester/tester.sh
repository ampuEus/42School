#!/bin/sh
BIN=../bin/push_swap
CHECKER=./checkers/checker_linux

###### STYLE #####
NOSTYLE='\033[0m'
RED='\033[1;31m'
GREEN='\033[1;32m'
BOLD='\033[1m'

##### Test for 3 numbers #####
echo "TEST FOR 3 NUMBERS"
for file in ./arguments/3_nbr/*; do
	ARG=$(cat $file)
	FILE="${BOLD}${file##*'/'}${NOSTYLE}"
	MOVEMENTS=$($BIN $ARG | wc -l)
	CHECKER_PASS=$($BIN $ARG | $CHECKER $ARG)
	[ $CHECKER_PASS=OK ] && PASS="${GREEN}YES${NOSTYLE}" || PASS="${GREEN}NO${NOSTYLE}"
	[ $MOVEMENTS -gt 3 ] && MOVEMENTS="${GREEN}$MOVEMENTS${NOSTYLE}" || MOVEMENTS="${GREEN}$MOVEMENTS${NOSTYLE}"
	echo -e "Testing file: $FILE | Passed = $PASS | Leaks = | Moves = $MOVEMENTS"
done

##### Test for 5 numbers #####
# echo "TEST FOR 5 NUMBERS"
# for dir in ./arguments/5_nbr/*; do
# 	for file in $dir/*; do
# 		ARG=$(cat $file)
# 		PUSH_SWAP=$($BIN $ARG)
# 		MOVEMENTS=$($PUSH_SWAP | wc -l)
# 		CHECKER_PASS=$($PUSH_SWAP | $CHECKER $ARG)
# 		echo $CHECKER_PASS
# 		[ $MOVEMENTS -gt 15 ] && PASS="NO" || PASS="YES"
# 		echo "Testing file: ${dir##*'/'}/${file##*'/'} | Passed = $PASS | Moves = $MOVEMENTS"
# 	done
# done
