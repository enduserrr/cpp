#!/bin/bash

CONVERT_PATH='./convert'

RED='\033[0;91m'
GREEN='\033[0;92m'
WB='\033[1;97m'
RES='\033[0m'
function display_help()
{
	printf "$WBusage:\t./tester.sh\n$RES"
	exit
}

if [ "$#" -ne "0" ]
then
	display_help
fi

## check if ./convert is here
convert_ok=$(ls $CONVERT_PATH 2>/dev/null | wc -l)
if [ "$convert_ok" -eq "0" ]
then
	printf "$REDconverter needed, please make it\n$RES"
	exit
fi

## test
function test()
{
	printf "\n$GREEN$CONVERT_PATH $1$RES\n"
	$CONVERT_PATH $1
}
## Should work
test "0"
test "0.0f"
test ".0f"
test "0.f"
test "0."
test "nan"
test "inf"
test "+inff"
test "-inf"
test "42.00001f"
test "42.12"
test "-42.5"
test "42000000000000000000000000000000000000.17"
test "420000000000000000000000000000000000000.17"
test "420000000000000000000000000000000000000.17f"
test "2147483648"
test "2147483648.1"
test "-2147483649"
test "-2147483648"
test "'a'"
test "'\'"
test "'*'"

## Should cause an error
test ".f"
test "-.f"
test "7f"
test "7.77.7"
test "-7.12f1"
test
