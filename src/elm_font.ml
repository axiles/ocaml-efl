type overlay = {
  text_class : string;
  font : string;
  size : int;
}

type properties = {
  name : string;
  styles : string list;
}

external properties_get : string -> properties = "ml_elm_font_properties_get"

external fontconfig_name_get : string -> string option -> string =
  "ml_elm_font_fontconfig_name_get"

