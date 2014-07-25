open Hstructs.Elm_entry

module Manchor_info = Fanchor_info (struct end)
include Manchor_info

module Manchor_hover_info = Fanchor_hover_info (struct
  type elm_entry_anchor_info = anchor_info
  type evas_object = Evas.obj
end)
include Manchor_hover_info

type item_provider_cb = Evas.obj -> string -> Evas.obj option

type filter_cb = Evas.obj -> string -> string option

type change_info

type filter_limit_size = {
  mutable max_char_count : int;
  mutable max_byte_count : int
}

type filter_accept_set = {mutable accepted : string; mutable rejected : string}

type text_format = Elm.text_format

type wrap_type = Elm.wrap_type

type input_panel_layout = Elm.input_panel_layout

type input_panel_lang = Elm.input_panel_lang

type autocapital_type = Elm.autocapital_type

type input_panel_return_key_type = Elm.input_panel_return_key_type

type cnp_mode = Elm.cnp_mode

module AF = Autofun.Elm_entry.F (struct
  type evas_object = Evas.obj
  type elm_wrap_type = Elm.wrap_type
  type elm_text_format = Elm.text_format
  type elm_input_panel_return_key_type = Elm.input_panel_return_key_type
  type elm_input_panel_layout = Elm.input_panel_layout
  type elm_input_panel_lang = Elm.input_panel_lang
  type elm_cnp_mode = Elm.cnp_mode
  type elm_autocapital_type = Elm.autocapital_type
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_entry_add"

let addx = Elm_object.create_addx add

external text_style_user_peek : Evas.obj -> string option =
  "ml_elm_entry_text_style_user_peek"

external selection_get : Evas.obj -> string option =
  "ml_elm_entry_selection_get"

external cursor_content_get : Evas.obj -> string =
  "ml_elm_entry_cursor_content_get"

external cursor_geometry_get : Evas.obj -> int * int * int * int =
  "ml_elm_entry_cursor_geometry_get"

external context_menu_item_add :
  Evas.obj -> string -> string -> Elm_icon.ty -> Evas.smart_cb -> unit =
  "ml_elm_entry_context_menu_item_add"

external item_provider_append : Evas.obj -> item_provider_cb -> unit =
  "ml_elm_entry_item_provider_append"

external item_provider_prepend : Evas.obj -> item_provider_cb -> unit =
  "ml_elm_entry_item_provider_prepend"

external markup_filter_append : Evas.obj -> filter_cb -> unit =
  "ml_elm_entry_markup_filter_append"

external markup_filter_prepend : Evas.obj -> filter_cb -> unit =
  "ml_elm_entry_markup_filter_prepend"

external file_get : Evas.obj -> string * Elm.text_format =
  "ml_elm_entry_file_get"

external filter_limit_size :
  filter_limit_size -> Evas.obj -> string -> string option  =
  "ml_elm_entry_filter_limit_size"

external filter_accept_set :
  filter_accept_set -> Evas.obj -> string -> string option =
  "ml_elm_entry_filter_accept_set"

external anchor_hover_parent_get : Evas.obj -> Evas.obj option =
  "ml_elm_entry_anchor_hover_parent_get"

external anchor_info_of_ptr : Evas.ptr -> anchor_info =
  "ml_elm_entry_anchor_info_of_ptr"

external anchor_hover_info_of_ptr : Evas.ptr -> anchor_hover_info =
  "ml_elm_entry_anchor_hover_info_of_ptr"

