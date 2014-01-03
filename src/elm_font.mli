(** elm_font_* Elm_Font_* *)

type overlay = {
  text_class : string;
  font : string;
  size : int;
}

type properties = {
  name : string;
  styles : string list;
}

val properties_get : string -> properties

val fontconfig_name_get : string -> string option -> string

