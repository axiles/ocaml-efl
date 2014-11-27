#!/bin/sh

if test -d _build/examples; then
  X="no"
  cd _build/examples;
  for file in *.byte *.native; do
    name=$(echo $file | sed 's/\(.*\)[.].*/\1/')
    ../../install-sh $file $1$name;
    X="yes"
  done;
  if test $X = "yes"; then
    echo The examples have been installed as: $1'***'
  fi
fi
