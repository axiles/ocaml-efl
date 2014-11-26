#!/bin/sh

if test -d $1; then
  rm -rf $1;
  echo "Documentation removed"
fi

