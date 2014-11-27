#!/bin/sh

X="no"
cd examples;
for file in *.ml; do
  name=$(echo $file | sed 's/\(.*\)[.].*/\1/')
  realname=$1$name
  if test -f $realname; then
    X="yes";
    rm -f $realname;
  fi;
done;

if test $X = "yes"; then
  echo The examples have been removed
fi

