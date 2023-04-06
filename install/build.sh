#! /bin/sh
#
#   TODO:
#       - Replace Makefile with shell script.

appName="pokemon-text"

fullPath="$(readlink -f "$0")"
scriptDir="$(dirname "$fullPath")"
scriptFile="$(basename "$fullPath")"
scriptName="$(echo "$scriptFile" | cut -f 1 -d '.')"
startDir="$(pwd)"
rootDir="$(readlink -f "$scriptDir/..")"
buildDir="$rootDir/build"
programDir="$rootDir/run"

#   Clean directory.
#
#   @param $1   The directory to clean.
cleanDir() {
    if [ "$cleanBuild" = false ] || [ ! -d "$1" ] && [ ! -f "$1" ]; then
        return 0
    fi

    rm -rf "$1"
    mkdir -p "$1"
    say "Cleaned $1"
}

#   Change directory with error handling.
enter () {
    cd "$1" >/dev/null || error "Couldn't enter $1."
}

#   Print formatted to be from this script.
#
#   @param $1   The message to print.
error() {
    say "$1"
    quit 1
}

#   Print formatted to be from this script.
#
#   @param $1   The message to print.
finish() {
    say "$1"
    quit 0
}

quit() {
    cd "$startDir" || :
    exit "$1"
}

#   Print formatted to be from this script.
#
#   @param $1   The message to print.
say () {

    if [ -z "$1" ]; then
        echo "[$scriptName]: say() takes a message argument."
        quit
    fi

    if [ "$silent" = false ]; then
        echo "[$scriptName]: $1"
    fi
}

usage() {
    echo "
usage: $scriptName [-d] [-f filePath] [-h] [-m]

    -d  Dirty build.
    -f  .ini file for the program.
    -h  Print this.
    -n  Don't run program after building.
"
    exit 0
}

#   Default values.   #
cleanBuild=true
doRun=true
iniFile=""
logLevel="0"
silent=false
# # # # # # # # # # # #

while getopts 'df:hl:n' opt; do
  case $opt in
    d) cleanBuild=false ;;
    f) iniFile="$OPTARG" ;;
    h) usage ;;
    l) logLevel="$OPTARG" ;;
    n) doRun=false ;;
    *) usage ;;
  esac
done

# # # # # # # # # # # #

cleanDir "$buildDir"
cleanDir "$programDir"
enter "$rootDir"

if [ "$OS" = "Windows_NT" ]; then
    suffix="windows"
else
    suffix="unix"
fi

if [ -n "$iniFile" ]; then
    if [ ! -f "$iniFile" ]; then
        error "No such file: $iniFile"
    fi
    cp "$iniFile" "$programDir"
fi

say "Initiating build."
enter "$scriptDir/$suffix"
make || error "Make failed."


if [ "$doRun" = true ]; then
    enter "$programDir"
    "./$appName" -l "$logLevel"
fi

cleanDir "$buildDir"
finish "Done building."
