#!/bin/bash

declare XTRA=false
declare SED_ARG="-r"

usage() {
  echo "Usage: shorten-crossrefs.sh [-x] [-b] input"
  echo ""
  echo "Generate shorter version of cross-refernces"
  echo "  -x  produce extra short version"
  echo "  -h  display this help and exit"
  echo "  -b  BSD style system (different sed arguments)"
  exit $E_OPTERROR
}

opts() {
  while getopts "xhb" optname
  do
    case "$optname" in
      "x") XTRA=true
        ;;
      "b") SED_ARG="-E"
	;;
      "h") usage
        ;;
      "?") echo "Unknown option $OPTARG"
        ;;
      ":") echo "No argument value for option $OPTARG"
        ;;
      *) echo "Unknown error while processing options"
        ;;
    esac
  done
  return $OPTIND
}

main() {
  opts "$@"
  local argstart=$?

  shift $(($argstart - 1))
  local input=$1; shift

  if [[ ! -f $input ]]; then
    echo "The input file is invalid or missing"
    exit 1
  fi

  local output=$(sed $SED_ARG '/@.*\{/,/^\}/{
/booktitle|journal/ {
  s/=[^(]*\(([^)]+)\).*/= "\1",/g
}
}' $input)
  if $XTRA; then
    output=$(echo "$output" | sed $SED_ARG '/@.*\{/,/^\}/{
/@.*\{/n
/booktitle|journal/ P
/^\}/ !{
  D
}
}')
  fi

  echo "$output"
}

main "$@"
