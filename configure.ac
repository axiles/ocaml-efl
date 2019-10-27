AC_INIT([ocaml-efl], [1.21.0])

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

dnl Check for OCamlbuild flag
AC_ARG_VAR([OCAMLBUILD_FLAGS], [Options passed to OCamlbuild])

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

dnl Checking for CFLAGS
AC_ARG_VAR([CFLAGS], [
  Other options to pass to the C compiler
])

dnl Checking for Elementary
PKG_CHECK_MODULES([ELEMENTARY], [elementary >= 1.8])
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
AC_SUBST([ELM_EO_CLASS_OBJ], "elm_obj")
AC_SUBST([EO_ISA], "eo_isa")
AC_SUBST([ELM_IMAGE_PROGRESS], "no")
AC_SUBST([EFL_UI_EVERYWHERE], ["false"])
AC_SUBST([EFL_21], ["false"])
AC_SUBST([EFL_22], ["false"])
AX_COMPARE_VERSION([$ELEMENTARY_VERSION], [ge], ["1.11"], [
  ELM_EO_CLASS_OBJ="elm"
], [])
AX_COMPARE_VERSION([$ELEMENTARY_VERSION], [ge], ["1.18"], [
  ELM_EO_CLASS_OBJ="efl_ui"
], [])
AX_COMPARE_VERSION([$ELEMENTARY_VERSION], [ge], ["1.19"], [
  EO_ISA="efl_isa"
  ELM_EO_CLASS_OBJ="elm_get"
  ELM_IMAGE_PROGRESS="yes"
], [])
AX_COMPARE_VERSION([$ELEMENTARY_VERSION], [ge], ["1.20"], [
  EFL_UI_EVERYWHERE="true"
])
AX_COMPARE_VERSION([$ELEMENTARY_VERSION], [ge], ["1.21"], [
  EFL_21="true"
], [])
AX_COMPARE_VERSION([$ELEMENTARY_VERSION], [ge], ["1.22"], [
  EFL_22="true"
], [])

dnl Checking for Lablgl (used to compile an example, optional)
AC_CHECK_OCAML_PKG([lablgl])
AS_IF([test $OCAML_PKG_lablgl = "no"], [
  AC_MSG_WARN([Lablgl example will not be compiled])
], [
  AC_SUBST([LABGL_DIR], [$($OCAMLFIND query lablgl)])
])

dnl Checking for Lwt (used to compile an example, optional
AC_CHECK_OCAML_PKG([lwt.extra])
AS_IF([test $OCAML_PKG_lwt_extra = "no"], [
  AC_MSG_WARN([Lwt example will not be compiled])
], [
  AC_SUBST([LWT_DIR], [$($OCAMLFIND query lwt.extra)])
])

dnl Get the list of the examples
AS_ECHO(["configure: creating ./examples/list.txt"])
rm -f examples/list.txt
AS_FOR([FILE], [file], [examples/*.ml], [
  echo FILE | sed 's|examples/\(.*\)[.]ml|\1|' >> examples/list.txt
])

AC_CONFIG_FILES([Makefile myocamlbuild.ml META src/write_connect/main.ml])

AC_OUTPUT

