#!/bin/sh

if test -d _build/src/efl_doc.docdir/; then
  cd _build/src/efl_doc.docdir/;
  for file in *; do
    ../../../install-sh -m 644 $file $1/api/$file
  done;
  cd ../../../examples;
  for file in *; do
    ../install-sh -m 644 $file $1/examples/$file
  done;
  echo "Documentation installed in: $1"
fi

