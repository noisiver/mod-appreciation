#!/usr/bin/env bash
MOD_APPRECIATION_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )/" && pwd )"

source $MOD_APPRECIATION_ROOT"/conf/conf.sh.dist"

if [ -f $MOD_APPRECIATION_ROOT"/conf/conf.sh" ]; then
    source $MOD_APPRECIATION_ROOT"/conf/conf.sh"
fi
