open Common

let slider_indicator_visible_mode =
  simple_ty "Elm" "Slider_Indicator_Visible_Mode"

let funs = [
  prop ~args:[] "slider_indicator_visible_mode" slider_indicator_visible_mode;
  simple_unit "font_hint_type_set" [evas_font_hinting_flags];
]

