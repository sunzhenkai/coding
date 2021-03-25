#!/bin/sh
set -x

exitFun() {
  echo "ERROR: failed, due to $1"
  exit 1
}

fix() {
    [ ! -d "${1}" ] && exitFun "target is not folder"
    mv "${1}" "${1}_back"
    mkdir "${1}"
    mv "${1}_back"/* "${1}/" 
    mv "${1}_back"/.[^.]* "${1}/" 
    rmdir "${1}_back"
}

fix "${1}"
