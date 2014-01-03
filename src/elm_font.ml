type properties = {
  name : string;
  styles : string list;
}

external properties_get : string -> properties = "ml_elm_font_properties_get"

