AC_INIT([ocaml-efl], [1.12.0])

AM_INIT_AUTOMAKE([foreign])

AC_CONFIG_MACRO_DIR([m4])

dnl Checking for OCaml
AC_PROG_OCAML
AS_IF([test $OCAMLC = "no"], [
  AC_MSG_ERROR([OCaml was not found on this system])
])
AX_COMPARE_VERSION([$OCAMLVERSION], [ge], [3.12], [], [
  AC_MSG_ERROR([OCaml 3.12 or newer is required])
])

dnl Checking for OCamlfind
AC_PROG_FINDLIB
AS_IF([test $OCAMLFIND = "no"],
  AC_MSG_ERROR([OCamlfind/Findlib was not found on this system])
])
AC_ARG_VAR([OCAMLFIND_DESTDIR], [(Default: $libdir/ocaml/$OCAMLVERSION)])
AS_IF([test -z $OCAMLFIND_DESTDIR], [
  OCAMLFIND_DESTDIR=$libdir/ocaml/$OCAMLVERSION
])
AC_ARG_VAR([OCAMLFIND_LDCONF], [(Default: $OCAMLLIB/ldconf.so)])
AS_IF([test -z $OCAMLFIND_LDCONF], [
  OCAMLFIND_LDCONF=$OCAMLLIB/ld.conf
])

dnl Checking for Elementary
PKG_CHECK_MODULES([ELEMENTARY], [elementary >= 1.11])
AC_ARG_VAR([ELEMENTARY_VERSION],[
  version for ELEMENTARY, overriding pkg-config
])
AS_IF([test -z $ELEMENTARY_VERSION], [
  AS_IF([test -z PKG_CONFIG], [
    AC_MSG_ERROR(
      [Without pkg-config, you must set the variable ELEMENTARY_VERSION]
    )
  ])  
  ELEMENTARY_VERSION=$($PKG_CONFIG --modversion elementary)
])

dnl Checking for Lablgl (used to define an example, optional)
AC_CHECK_OCAML_PKG([lablgl])
AS_IF([test OCAML_PKG_lablgl = "no"], [], [
  AC_SUBST([LABGL_DIR], [$($OCAMLFIND query lablgl)])
])

dnl Get the list of the examples
AS_ECHO(["configure: creating ./examples/list.txt"])
rm -f examples/list.txt
AS_FOR([FILE], [file], [examples/*.ml], [
  echo FILE | sed 's|examples/\(.*\)[.]ml|\1|' >> examples/list.txt
])

AC_CONFIG_FILES([Makefile myocamlbuild.ml src/META])

AC_OUTPUT

