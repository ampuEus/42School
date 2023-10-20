#!/bin/sh

##############################
########## Contants ##########
##############################
USAGE=$(cat <<'EOF'
 NAME
    Philosopher tester -- Tests for philosopher exercise

 SYNOPSIS
    tester.sh BINPATH [-m] [-b] [-l] [-t TIME_VALUE]

 EXIT STATUS
   0  if no errors in execution
   1+ if trouble

 OPTIONS
   -m, --mandatory

   Default option. Execute the tests for the requirements of the mandatory part.
   The tests have been taken form philosopher correction.
   If you want to run it together with the bonus tests, use both options at
   the same time (-m -b).

   -c, --custom        Run tests to verify the mandatory performance.

   -b, --bonus         Execute the tests for the requirements of the bonus part.

   -l, --leaks         Check leaks of the program

   -a, --arguments     Run tests to verify input arguments.

     Run harder tests to verify program performance in different situations.

   -t, --time TIME_VALUE

     Change the maximum execution time (in seconds) of tests where no
     philosopher is supposed to die. Default value is 60 seconds.

 NOTES
   In the tests it is assumed that the program outputs the errors on stderr
   file descriptor.

EOF
)

# Colors
NORMAL="\e[0m"
RED="\e[91m"
GREEN="\e[92m"
YELLOW="\e[93m"
BLUE="\e[94m"

# Routes / Files
TEMP_FILE_OUT="tester_stdout.temp"
TEMP_FILE_ERR="tester_stderr.temp"

# Messages
SUCCESS="${GREEN}OK$NORMAL"
WARNING="${YELLOW}OK$NORMAL"
FAIL="${RED}KO$NORMAL"
SUCCESS_LEAKS="${GREEN}MOK$NORMAL"
FAIL_LEAKS="${RED}MKO$NORMAL"

# Timer
TIME_FOR_CHECK_ARGS=0.2
TIME_FOR_FILES_CREATION=0.1

#################################
########## Input parse ##########
#################################
progname=$(basename "$0")
mandatory=
bonus=
segment=
time=60

TEMP=$(getopt -o 'hmcblat:' \
		--long 'help,mandatory,custom,bonus,leaks,arguments,log,time:' \
		-n "$progname" -- ${1+"$@"})
[ $? -eq 0 ] || { echo "$progname use -h for help" >&2; exit 1; }
eval set -- "$TEMP" ; unset TEMP

while true ; do
	case "$1" in
	--)										shift; break ;;
	-m|--mandatory)	mandatory=yes;			shift ;;
	-c|--custom)	segment=${segment}s;	shift ;;
	-b|--bonus)		bonus=yes;				shift ;;
	-l|--leaks)		segment=${segment}l;	shift ;;
	-a|--arguments)	segment=${segment}a;	shift ;;
	-t|--time)		time=$2;				shift; shift ;;
	-h|--help)		[ -t 1 ] || PAGER=cat; echo "$USAGE" | ${PAGER:-more} ; exit 0 ;;
	*) echo "[ERROR] Internal error!" >&2; exit 99 ;;
	esac
done

target=$1
if [ -f "$target" ];then
	echo "$BLUE[+] Binary to test: $target$NORMAL"
else
	echo "$RED[ERROR] No valid binary. Given binary address: $target$NORMAL" >&2
	exit 2
fi

###########################
########## Tests ##########
###########################
test_leaks ()
{
	test=$1
	target=$2
	bin=$(basename $target)
	args=$3

	echo -n "$test "

	(valgrind $target $args > /dev/null 2> $TEMP_FILE_ERR)
	if [ "$args" = "" ];then
		args="<no arguments>"
	fi
	sleep $TIME_FOR_CHECK_ARGS
	pkill $bin
	std_err=$(grep -c -E 'LEAK' $TEMP_FILE_ERR)
	if [ $std_err -gt 0 ];then
		echo "$FAIL_LEAKS: $target $args"
	else
		echo "$SUCCESS_LEAKS: $target $args"
	fi
	rm -rf $TEMP_FILE_ERR
}

test_args_wrong ()
{
	test=$1
	target=$2
	bin=$(basename $target)
	args=$3

	echo -n "$test "

	($target $args > $TEMP_FILE_OUT 2> $TEMP_FILE_ERR)&
	if [ "$args" = "" ];then
		args="<no arguments>"
	fi
	sleep $TIME_FOR_CHECK_ARGS
	pkill $bin
	std_out=$(cat $TEMP_FILE_OUT)
	std_err=$(cat $TEMP_FILE_ERR)
	if [ "$std_err" = "" ];then
		echo "$FAIL: $target $args -> It should print an error on stderr."
	elif [ "$std_out" != "" ];then
		echo "$FAIL: $target $args -> It should not print anything in stdout, errors go on stderr.$NORMAL"
	else
		echo "$SUCCESS: $target $args"
	fi
	rm -rf $TEMP_FILE_OUT
	rm -rf $TEMP_FILE_ERR
}

test_args_good ()
{
	test=$1
	target=$2
	bin=$(basename $target)
	args=$3

	echo -n "$test "

	($target $args > $TEMP_FILE_OUT 2> $TEMP_FILE_ERR)&
	if [ "$args" = "" ];then
		args="<no arguments>"
	fi
	sleep $TIME_FOR_CHECK_ARGS
	pkill $bin
	std_out=$(grep -c -E 'error|Error|ERROR' $TEMP_FILE_OUT)
	std_err=$(cat $TEMP_FILE_ERR)
	if [ "$std_err" != "" ];then
		echo "$FAIL: $target $args -> It should not print an error on stderr."
	elif [ $std_out -gt 0 ];then
		echo "$FAIL: $target $args -> Errors go on stderr, no on stdout.$NORMAL"
	else
		echo "$SUCCESS: $target $args"

	fi
	rm -rf $TEMP_FILE_OUT
	rm -rf $TEMP_FILE_ERR
}

test_die ()
{
	test=$1
	target=$2
	bin=$(basename $target)
	args=$3

	echo -n "$test "

	($target $args > $TEMP_FILE_OUT 2> $TEMP_FILE_ERR)&
	sleep $TIME_FOR_FILES_CREATION
	for i in `seq 0 $time`;do
		printf "\r$test [${i}s / ${time}s]"
		pgrep $bin > /dev/null
		if [ $? -eq 1 ];then
			break
		fi
		sleep 1
	done
	pkill $bin
	std_out=$(grep -c 'died' $TEMP_FILE_OUT)
	std_err=$(cat $TEMP_FILE_ERR)
	if [ "$std_err" != "" ];then
		echo "\r$test $FAIL: $target $args -> It should not print anything on stderr."
	elif [ "$std_out" -gt 0 ];then
		echo "\r$test $SUCCESS: $target $args"
	else
		echo "\r$test $FAIL: $target $args -> A philosopher should died."
	fi
	rm -rf $TEMP_FILE_OUT
	rm -rf $TEMP_FILE_ERR
}

test_live ()
{
	test=$1
	target=$2
	bin=$(basename $target)
	args=$3

	echo -n "$test "

	($target $args > /dev/null)&
	for i in `seq 0 $time`;do
		printf "\r$test [${i}s / ${time}s]"
		pgrep $bin > /dev/null
		if [ $? -gt 0 ];then
			echo "\r$test $FAIL: $target $args -> No philosopher should died."
			return
		fi
		sleep 1
	done
	sleep 1
	pkill $bin
	echo "\r$test $SUCCESS: $target $args"
}

test_eat ()
{
	test=$1
	target=$2
	bin=$(basename $target)
	args=$3
	philos_count=$(echo "$args" | awk '{print $1}')
	eat_count=$(echo "$args" | awk '{print $NF}')
	total_eat=$(( $philos_count * $eat_count ))

	echo -n "$test "

	($target $args > $TEMP_FILE_OUT 2> $TEMP_FILE_ERR)&
	sleep $TIME_FOR_FILES_CREATION
	for i in `seq 0 $time`;do
		printf "\r$test [${i}s / ${time}s]"
		pgrep $bin > /dev/null
		if [ $? -gt 0 ];then
			break
		fi
		sleep 1
	done
	pgrep $bin > /dev/null
	if [ "$?" -eq 1 ];then
		if [ $(grep -c 'eating' $TEMP_FILE_OUT) -ge $total_eat ];then
			echo "\r$test $SUCCESS: $target $args"
		else
			echo "\r$test $FAIL: $target $args -> It should only be stopped if each philosopher has eaten at least $eat_count times."
		fi
	else
		echo "\r$test $FAIL: $target $args -> It should have stopped once the philosophers would have eaten $eat_count times."
		pkill $bin
	fi
	rm -rf $TEMP_FILE_OUT
	rm -rf $TEMP_FILE_ERR
}

test_five ()
{
	echo "\e[94m[+] Test #5 on progress, please wait...\e[0m"
	i=1
	t=0
	error=0
	while [ $i -le 10 ];do
		("$2/$1/$1" 2 60 60 60 > $TEMP_FILE)&
		sleep 2
		pgrep $1 > /dev/null
		if [ "$?" -eq 1 ];then
			printf "\r[%d/10]" $i
			tmp=$(grep died -m 1 $TEMP_FILE | awk '{print $1}' | sed 's/[^0-9]*//g')
			if [ $i -gt 1 ];then
				x=$(expr $tmp - $t)
				x=${x#-}
				if [ $x -gt 10 ];then
					printf "\r\e[91m[+] Test #5 Failed\e[0m\n"
					echo "Test #5" "Given 2 60 60 60 arguments to $1, the time difference of each death shouldn't be bigger than 10ms !"
					error=1
					break
				fi
			else
				t=$tmp
			fi
		else
			printf "\r\e[91m[+] Test #5 Failed\e[0m\n"
			echo "Test #5" "Given 2 60 60 60 arguments to $1, a philosopher should die !"
			pkill $1
			break
		fi
		i=$(( $i + 1 ))
	done

	if [ $error -eq 0 ];then
		echo "\r\e[92m[+] Test #5 Succeeded\e[0m"
	fi
}

test_six ()
{
	("$2/$1/$1" 10 410 200 200 > /dev/null)&
	sleep 2
	forks=$(pgrep $1 | wc -l)
	if [ "$forks" -eq 11 ];then
		printf "\r\e[92m[+] Test #6 Succeeded\e[0m\n"
	else
		printf "\r\e[91m[+] Test #6 Failed\e[0m\n"
		echo "Test #6" "Given 10 410 200 200 arguments to $1, 10 processes should be forked, each process for a philosopher !"
	fi
	pkill $1
}


##########################
########## Main ##########
##########################
MSG_TIMES="$BLUE[+] NOTE: The tests where the philospher don't have to die will be running for $time seconds, and the ones that have to die 5 seconds. Or until a philosopher dies.$NORMAL"

is_installed()
{
	cmd=$1

	which $cmd > /dev/null
	if [ "$?" -eq 1 ];then
		echo "\r${RED}The "$cmd" command is not installed and is required for 'leaks' testing.$NORMAL"
		return 0
	fi
	return 1
}


if [ "$segment" = "" ] || [ $(echo $segment | grep -c 'l') -gt 0 ];then
	is_installed "valgrind"
	is_installed "leaks"

	test_leaks "Test 001" $target "3"
	test_leaks "Test 001" $target "3 23 543 67"
fi

if [ "$segment" = "" ] || [ $(echo $segment | grep -c 'a') -gt 0 ];then

	echo "$BLUE[+] Tests to check the input paramenters$NORMAL"
	echo "$BLUE[+] (Only check if the program is able to discretize between correct or wrong input arguments)$NORMAL"

	test_args_wrong "Test 001" $target ""
	test_args_wrong "Test 002" $target "3"
	test_args_wrong "Test 003" $target "3 300"
	test_args_wrong "Test 004" $target "3 300 100"
	test_args_good "Test 004" $target "3 300 100 100"
	test_args_wrong "Test 005" $target "3 300 100 100 10 5"
	test_args_wrong "Test 006" $target "3 300 100 100 10 5 5"
	test_args_wrong "Test 007" $target "\"3 300 100 100\""
	test_args_wrong "Test 008" $target "\"3 300 100 100 10\""
	test_args_wrong "Test 009" $target "0 400 100 100"
	test_args_wrong "Test 010" $target "0 400 100 100 10"
	test_args_good "Test 011" $target "3 0 100 100"
	test_args_good "Test 012" $target "3 0 100 100 10"
	test_args_good "Test 013" $target "3 100 0 100"
	test_args_good "Test 014" $target "3 100 0 100 10"
	test_args_good "Test 015" $target "3 100 100 0"
	test_args_good "Test 016" $target "3 100 100 0 10"
	test_args_good "Test 017" $target "3 100 100 10 0"
	test_args_good "Test 018" $target "3 0 0 0"
	test_args_good "Test 019" $target "3 0 0 0 0"
	test_args_wrong "Test 020" $target "0 0 0 0"
	test_args_wrong "Test 021" $target "0 0 0 0 0"
	test_args_wrong "Test 022" $target "a 300 100 100"
	test_args_wrong "Test 023" $target "3   b 100 100"
	test_args_wrong "Test 024" $target "3 300   c 100"
	test_args_wrong "Test 025" $target "3 300 100   d"
	test_args_wrong "Test 026" $target "3 300 100 fdd"
	test_args_wrong "Test 027" $target "a 300 100 100 10"
	test_args_wrong "Test 028" $target "3   b 100 100 10"
	test_args_wrong "Test 029" $target "3 300   c 100 10"
	test_args_wrong "Test 030" $target "3 300 100   d 10"
	test_args_wrong "Test 031" $target "3 300 100 100  e"
	test_args_wrong "Test 032" $target "3 300 100 100 qe"
	test_args_wrong "Test 033" $target "? 300 100 100"
	test_args_wrong "Test 034" $target "3 300, 100 100"
	test_args_wrong "Test 035" $target "3 300, 100 ^100"
	test_args_wrong "Test 036" $target "3 **   100 100 10"
	test_args_wrong "Test 037" $target "3 ^    100 100 10"
	test_args_wrong "Test 038" $target "3 *    10r0 100 10"
	test_args_wrong "Test 039" $target "3 *    100 1t00 10"
	test_args_wrong "Test 040" $target "-   300  100  100"
	test_args_wrong "Test 041" $target "--   300  100  100"
	test_args_wrong "Test 042" $target "-3  300  100  100"
	test_args_wrong "Test 043" $target " 3 -300  100  100"
	test_args_wrong "Test 044" $target " 3 --300  100  100"
	test_args_wrong "Test 045" $target " 3  300 -100  100"
	test_args_wrong "Test 046" $target " 3  300  100 -100"
	test_args_wrong "Test 047" $target "-   300  100  100  10"
	test_args_wrong "Test 048" $target "-3  300  100  100  10"
	test_args_wrong "Test 049" $target " 3 -300  100  100  10"
	test_args_wrong "Test 050" $target " 3  300 -100  100  10"
	test_args_wrong "Test 051" $target " 3  300  100 -100  10"
	test_args_wrong "Test 052" $target " 3  300  100 -100 -10"
	test_args_wrong "Test 053" $target "+   300  100  100"
	test_args_wrong "Test 054" $target " 3  +    100  100"
	test_args_wrong "Test 055" $target " 3  ++   100  100"
	test_args_wrong "Test 056" $target " 3  ++300 100  100"
	test_args_wrong "Test 057" $target "+++ 300  100  100"
	test_args_good "Test 058" $target "+3  300  100  100"
	test_args_good "Test 059" $target " 3 +300  100  100"
	test_args_good "Test 060" $target " 3  300 +100  100"
	test_args_good "Test 061" $target " 3  300  100 +100"
	test_args_wrong "Test 062" $target "+   300  100  100  10"
	test_args_wrong "Test 063" $target " 3  ++   100  100  10"
	test_args_good "Test 064" $target "+3  300  100  100  10"
	test_args_good "Test 065" $target " 3 +300  100  100  10"
	test_args_good "Test 066" $target " 3  300 +100  100  10"
	test_args_good "Test 067" $target " 3  300  100 +100  10"
	test_args_good "Test 068" $target " 3  300  100  100 +10"
	test_args_wrong "Test 069" $target "3+ 300 100 100"
	test_args_wrong "Test 070" $target "3 30+0 100 100"
	test_args_wrong "Test 071" $target "3 -2147483648 100 100"		# INT_MIN
	test_args_good "Test 072" $target "3  2147483647 100 100"		# INT_MAX
	test_args_wrong "Test 073" $target "3 -2147483649 100 100"		# INT_MIN - 1
	test_args_good "Test 074" $target "3  2147483648 100 100"		# INT_MAX + 1
	test_args_wrong "Test 075" $target "3 -2147483648 100 100 10"	# INT_MIN
	test_args_good "Test 076" $target "3  2147483647 100 100 10"	# INT_MAX
	test_args_wrong "Test 077" $target "3 -2147483648 100 100 10"	# INT_MIN - 1
	test_args_good "Test 078" $target "3  2147483648 100 100 10"	# INT_MAX + 1
	test_args_good "Test 079" $target "3 4294967295 100 100"		# UINT_MAX
	test_args_wrong "Test 080" $target "3 4294967296 100 100"		# UINT_MAX + 1
	test_args_good "Test 081" $target "3 4294967295 100 100 10"		# UINT_MAX
	test_args_wrong "Test 082" $target "3 4294967296 100 100 10"	# UINT_MAX + 1
	test_args_good "Test 083" $target "	3 300 100 100"
	test_args_good "Test 084" $target "3	    		300 100 100"
	test_args_good "Test 085" $target "3 300 100 100	"
	test_args_wrong "Test 086" $target "3 \t 300 100 100"
	test_args_wrong "Test 087" $target "3 \t  \t 300 100 100"
	test_args_wrong "Test 088" $target "3 \n 300 100 100"
fi

if { [ "$mandatory" = "" ] && [ "$bonus" = "" ]; } \
	|| { [ "$mandatory" = "yes" ] && [ "$bonus" = "yes" ]; };then

	echo "[============[Testing Philosopher mandatory part]==============]\n"

	# TODO añadir (dar opcion a comprobar siempre los leaks):
	# pruebas que se ocurran
	#	args = 2 60 60 60
	# pruebas cabronas
	# 	que se tarde mas en comer y/o dormir que en morir
	# 	argumentos exageradamente altos
	# 		muchos filos y que la CPU pete
	# ¿las pruebas del bonus son iguales al mandatory?

	echo "$BLUE[+] Correction tests running $NORMAL"
	#Test 1 800 200 200. The philosopher should not eat and should die.
	test_live "Correction test 001" $target "5 800 200 200"
	test_eat  "Correction test 002" $target "5 800 200 200 7"
	test_live "Correction test 003" $target "4 410 200 200"
	test_die  "Correction test 004" $target "4 310 200 100"

	if [ "$segment" = "" ] || [ $(echo $segment | grep -c 'c') -gt 0 ];then
		echo "$BLUE[+] Custom tests running $NORMAL"
		echo $MSG_TIMES
		test_live "Simple test 001" $target "4 1000 200 200"
		test_eat  "Simple test 002" $target "4 1000 200 200 3"
		test_live "Simple test 003" $target "7 800 200 200"
		test_eat  "Simple test 004" $target "7 800 200 200 7"
		test_live "Simple test 005" $target "6 800 200 200"
		test_eat  "Simple test 006" $target "6 800 200 200 7"
		test_live "Simple test 007" $target "4 800 200 200"
		test_eat  "Simple test 008" $target "4 800 200 200 7"
		test_live "Simple test 009" $target "3 800 200 200"
		test_eat  "Simple test 010" $target "3 800 200 200 7"
		test_die  "Simple test 011" $target "1 800 200 200"
	fi

fi

# if [ "$bonus" = "yes" ];then
#
# 	echo "\n[============[Testing Philosopher bonus part]==============]\n"
#
# 	test_four $target 7 28 1
# 	test_four $target 10 40 2
# 	test_four $target 12 48 3
# 	test_four $target 15 60 4
# 	test_five $target
# 	test_six $target
# fi

# Remove test files
rm -rf $TEMP_FILE_OUT
rm -rf $TEMP_FILE_ERR

exit 0
