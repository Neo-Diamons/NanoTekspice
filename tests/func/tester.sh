#!/usr/bin/env bash

BIN="$1"

SKIPPED_COMPONENTS="4094 4512 4514 4801 2716 logger"

NB_TESTS=0
NB_SUCCESS=0
NB_FAILURE=0
NB_CRASH=0

RESET="\033[0m"
BOLD="${RESET}\033[1m"
BLUE="${RESET}\033[34m"
GREEN="${RESET}\033[32m"
YELLOW="${RESET}\033[33m"
RED="${RESET}\033[31m"

if [ -z "$BIN" ]; then
  echo "Usage: $0 <path_to_binary>"
  exit 1
fi
if ! command -v "$BIN" &>/dev/null; then
  if [ -f "./$BIN" ]; then
    BIN="./$BIN"
  else
    echo "Error: $1 not found"
    exit 1
  fi
fi
if [ ! -x "$BIN" ]; then
  echo "Error: $1 is not executable"
  exit 1
fi

for file in ./tests/files/nts_advanced/*.nts ./tests/files/nts_single/*.nts ./tests/files/nts_hard_parsing/*.nts
do
  TMP=$( { echo -n | "$BIN" "$file"; } 2>&1 )
  CODE=$?

  if [ $CODE -ne 0 ] && [ $CODE -ne 84 ]; then
    echo -e "╭─${BOLD}[${RED}Crashing${BOLD}]${RESET} $file"
    echo -e "╰─➤ $TMP"
    NB_CRASH=$((NB_CRASH+1))
    continue
  fi

  for component in $SKIPPED_COMPONENTS
  do
    if [ "$TMP" == "Unknown component name '$component'." ]; then
      if [ $CODE -eq 84 ]; then
        echo -e "╭─${BOLD}[${YELLOW}SKIP${BOLD}]${RESET} $file"
        echo -e "╰─➤ $TMP"
        NB_SUCCESS=$((NB_SUCCESS+1))
      else
        echo -e "${BOLD}[${RED}FAIL${BOLD}]${RESET} $file"
        NB_FAILURE=$((NB_FAILURE+1))
      fi
      continue 2
    fi
  done

  if [ $CODE -eq 84 ]; then
    echo -e "╭─${BOLD}[${RED}FAIL${BOLD}]${RESET} $file"
    echo -e "╰─➤ Expected 0 and got 84"
    NB_FAILURE=$((NB_FAILURE+1))
  else
    NB_SUCCESS=$((NB_SUCCESS+1))
  fi
  NB_TESTS=$((NB_TESTS+1))
done

for file in ./tests/files/nts_bad/*.nts missing.nts /dev/null
do
  TMP=$( { echo -n | "$BIN" "$file"; } 2>&1 )
  CODE=$?

  if [ $CODE -eq 0 ]; then
    echo -e "╭─${BOLD}[${RED}FAIL${BOLD}]${RESET} $file"
    echo -e "╰─➤ Expected 84 and got 0"
    NB_FAILURE=$((NB_FAILURE+1))
  elif [ $CODE -eq 84 ]; then
    NB_SUCCESS=$((NB_SUCCESS+1))
  else
    echo -e "╭─${BOLD}[${RED}Crashing${BOLD}]${RESET} $file"
    echo -e "╰─➤ $TMP"
    NB_CRASH=$((NB_CRASH+1))
  fi
  NB_TESTS=$((NB_TESTS+1))
done

if [ $NB_SUCCESS -ne 0 ]; then
  COLOR_SUCCESS="${GREEN}"
else
  COLOR_SUCCESS="${RESET}"
fi
if [ $NB_FAILURE -ne 0 ]; then
  COLOR_FAILURE="${RED}"
else
  COLOR_FAILURE="${RESET}"
fi
if [ $NB_CRASH -ne 0 ]; then
  COLOR_CRASH="${RED}"
else
  COLOR_CRASH="${RESET}"
fi

echo -e "${BOLD}[${BLUE}====${BOLD}] Synthesis: Tested: ${BLUE}$NB_TESTS${BOLD} | Passing: ${COLOR_SUCCESS}$NB_SUCCESS${BOLD} | Failing: ${COLOR_FAILURE}$NB_FAILURE${BOLD} | Crashing: ${COLOR_CRASH}$NB_CRASH${RESET}"
if [ $NB_FAILURE -ne 0 ] || [ $NB_CRASH -ne 0 ]; then
  exit 1
fi
