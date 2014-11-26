#/bin/sh

if test -a _build/src/efl_doc.docdir/index.html; then
  cd _build/src/efl_doc.docdir/;
  for file in *; do
    ../../../install-sh -m 644 $file $1/$file
  done
fi

