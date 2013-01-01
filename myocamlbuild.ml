open Ocamlbuild_plugin

let ( & ) f x = f x

let write_variants () =
  let action env builder =
    Cmd (S [!Options.ocamlc; A "-custom"; A "-o"; P "write_variants";
      P "write_variants_stubs.c"; P "write_variants.ml"]) in
  rule "write_variants" ~prod:"write_variants"
  ~deps:["write_variants_stubs.c";"write_variants.ml"]  action;
  let action2 env builder =
    Cmd (S [P "./write_variants"; Sh ">"; P "variants.h"]) in
  rule "write_variants2" ~prod:"variants.h" ~dep:"write_variants" action2

let headers =
  ["include.h"; "variants.h"; "eina_wrap.h"; "evas_wrap.h"; "edje_wrap.h";
    "elm_wrap.h"]

let () = dispatch & function
  | After_options ->
    dep ["compile"; "c"] headers;
    flag ["compile"; "c"] (Sh "-ccopt \"`pkg-config --cflags elementary`\"");
    flag_and_dep ["link"; "byte"] & S [P "dllefl_stubs.so"; A "-dllib";
      A "-lefl_stubs"];
    (*dep ["link"; "native"] ["libefl_stubs.a"];*)
    flag_and_dep ["link"; "native"] &
      S [P "libefl_stubs.a"; Sh "-cclib \"`pkg-config --libs elementary`\""];
    flag ["ocamlmklib"] (Sh "`pkg-config --libs elementary`");
    flag ["native"; "compile"] & S [A "-for-pack"; A "Efl"];
    write_variants ()
  | _ -> ()
