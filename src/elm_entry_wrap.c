#include "include.h"

Evas_Object* ml_Elm_Entry_Item_Provider_Cb(
        void* data, Evas_Object* entry, const char* item)
{
      
        value* v_fun = (value*) data;
        value v_r = caml_callback2(*v_fun, (value) entry, copy_string(item));
        Evas_Object* r;
        if(v_r == Val_int(0)) r = NULL;
        else r = (Evas_Object*) Field(v_r, 0);
      
        return r;
}

void ml_Elm_Entry_Filter_Cb(void* data, Evas_Object* entry, char** text)
{
      
        value* v_fun = (value*) data;
        value v_r = caml_callback2(*v_fun, (value) entry, copy_string(*text));
        free(*text);
        if(v_r == Val_int(0)) *text = NULL;
        else {
                char* text1 = String_val(Field(v_r, 0));
                *text = caml_stat_alloc(strlen(text1) + 1);
                strcpy(*text, text1);
        }
      
}

inline Elm_Entry_Filter_Limit_Size
        Elm_Entry_Filter_Limit_Size_val(value v)
{
        Elm_Entry_Filter_Limit_Size ls;
        ls.max_char_count = Int_val(Field(v, 0));
        ls.max_byte_count = Int_val(Field(v, 1));
        return ls;
}

inline value
        copy_Elm_Entry_Filter_Limit_Size(Elm_Entry_Filter_Limit_Size ls)
{
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_int(ls.max_char_count));
        Store_field(v, 1, Val_int(ls.max_byte_count));
        return v;
}

/* WARNING: You must not use the GC when using the result */
inline Elm_Entry_Filter_Accept_Set
        Elm_Entry_Filter_Accept_Set_val(value v)
{
        Elm_Entry_Filter_Accept_Set as;
        as.accepted = String_val(Field(v, 0));
        as.rejected = String_val(Field(v, 1));
        return as;
}

inline value
        copy_Elm_Entry_Filter_Accept_Set(Elm_Entry_Filter_Accept_Set as)
{
        CAMLparam0();
        CAMLlocal1(v);
        v = caml_alloc(2, 0);
        if(as.accepted == NULL) Store_field(v, 0, copy_string(""));
        else Store_field(v, 0, copy_string(as.accepted));
        if(as.rejected == NULL) Store_field(v, 1, copy_string(""));
        else Store_field(v, 1, copy_string(as.rejected));
        CAMLreturn(v);
}

PREFIX value ml_elm_entry_add(value v_parent)
{
        Evas_Object* entry = elm_entry_add((Evas_Object*) v_parent);
        if(entry == NULL) caml_failwith("ml_elm_entry_add");
        return (value) entry;
}

PREFIX value ml_elm_entry_text_style_user_push(value v_obj, value v_style)
{
        elm_entry_text_style_user_push((Evas_Object*) v_obj,
                (const char*) String_val(v_style));
        return Val_unit;
}

PREFIX value ml_elm_entry_text_style_user_pop(value v_obj)
{
        elm_entry_text_style_user_pop((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_text_style_user_peek(value v_obj)
{
        CAMLparam0();
        CAMLlocal1(v);
        char* text = (char*) elm_entry_text_style_user_peek(
                (Evas_Object*) v_obj);
        if(text == NULL) return Val_int(0);
        v = caml_alloc(1, 0);
        Store_field(v, 0, copy_string(text));
        CAMLreturn(v);
}

PREFIX value ml_elm_entry_single_line_set(value v_obj, value v_flag)
{
        elm_entry_single_line_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_entry_single_line_get(value v_obj)
{
        return Val_Eina_Bool(elm_entry_single_line_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_password_set(value v_obj, value v_flag) {
        elm_entry_password_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_entry_password_get(value v_obj)
{
        return Val_Eina_Bool(elm_entry_password_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_entry_set(value v_obj, value v_entry)
{
        elm_entry_entry_set((Evas_Object*) v_obj, String_val(v_entry));
        return Val_unit;
}

PREFIX value ml_elm_entry_entry_get(value v_obj)
{
        return copy_string(elm_entry_entry_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_entry_append(value v_obj, value v_entry)
{
        elm_entry_entry_append((Evas_Object*) v_obj, String_val(v_entry));
        return Val_unit;
}

PREFIX value ml_elm_entry_is_empty(value v_obj)
{
        return Val_Eina_Bool(elm_entry_is_empty((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_selection_get(value v_obj)
{
        CAMLparam0();
        CAMLlocal1(v);
        const char* text = elm_entry_selection_get((Evas_Object*) v_obj);
        v = caml_alloc(1, 0);
        Store_field(v, 0, copy_string(text));
        CAMLreturn(v);
}

PREFIX value ml_elm_entry_textblock_get(value v_obj)
{
        return (value) elm_entry_textblock_get((Evas_Object*) v_obj);
}

PREFIX value ml_elm_entry_calc_force(value v_obj)
{
        elm_entry_calc_force((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_entry_insert(value v_obj, value v_entry)
{
        elm_entry_entry_insert((Evas_Object*) v_obj, String_val(v_entry));
        return Val_unit;
}

PREFIX value ml_elm_entry_line_wrap_set(value v_obj, value v_wrap)
{
        elm_entry_line_wrap_set((Evas_Object*) v_obj,
                Elm_Wrap_Type_val(v_wrap));
        return Val_unit;
}

PREFIX value ml_elm_entry_line_wrap_get(value v_obj)
{
        return Val_Elm_Wrap_Type(elm_entry_line_wrap_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_editable_set(value v_obj, value v_flag)
{
        elm_entry_editable_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_entry_editable_get(value v_obj)
{
        return Val_Eina_Bool(elm_entry_editable_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_select_none(value v_obj)
{
        elm_entry_select_none((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_select_all(value v_obj)
{
        elm_entry_select_all((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_cursor_next(value v_obj)
{
        return Val_Eina_Bool(elm_entry_cursor_next((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_cursor_prev(value v_obj)
{
        return Val_Eina_Bool(elm_entry_cursor_next((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_cursor_up(value v_obj)
{
        return Val_Eina_Bool(elm_entry_cursor_up((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_cursor_down(value v_obj)
{
        return Val_Eina_Bool(elm_entry_cursor_down((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_cursor_begin_set(value v_obj)
{
        elm_entry_cursor_begin_set((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_cursor_end_set(value v_obj)
{
        elm_entry_cursor_end_set((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_cursor_line_begin_set(value v_obj)
{
        elm_entry_cursor_line_begin_set((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_cursor_line_end_set(value v_obj)
{
        elm_entry_cursor_line_end_set((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_cursor_selection_begin(value v_obj)
{
        elm_entry_cursor_selection_begin((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_cursor_selection_end(value v_obj)
{
        elm_entry_cursor_selection_end((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_cursor_is_format_get(value v_obj)
{
        return Val_Eina_Bool(elm_entry_cursor_is_format_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_cursor_is_visible_format_get(value v_obj)
{
        return Val_Eina_Bool(elm_entry_cursor_is_visible_format_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_cursor_content_get(value v_obj)
{
        char* text = elm_entry_cursor_content_get((Evas_Object*) v_obj);
        value v = copy_string(text);
        free(text);
        return v;
}

PREFIX value ml_elm_entry_cursor_geometry_get(value v_obj)
{
        Evas_Coord x, y, w, h;
        if(!elm_entry_cursor_geometry_get((Evas_Object*) v_obj, &x, &y, &w, &h))
                caml_failwith("elm_entry_cursor_geometry_get");
        value v = caml_alloc(4, 0);
        Store_field(v, 0, Val_int(x));
        Store_field(v, 1, Val_int(y));
        Store_field(v, 2, Val_int(w));
        Store_field(v, 3, Val_int(h));
        return v;
}

PREFIX value ml_elm_entry_cursor_pos_set(value v_obj, value v_pos)
{
        elm_entry_cursor_pos_set((Evas_Object*) v_obj, Int_val(v_pos));
        return Val_unit;
}

PREFIX value ml_elm_entry_cursor_pos_get(value v_obj)
{
        return Val_int(elm_entry_cursor_pos_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_selection_cut(value v_obj)
{
        elm_entry_selection_cut((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_selection_copy(value v_obj)
{
        elm_entry_selection_copy((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_selection_paste(value v_obj)
{
        elm_entry_selection_paste((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_context_menu_clear(value v_obj)
{
        elm_entry_context_menu_clear((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_context_menu_item_add(
        value v_obj, value v_label, value v_icon_file, value v_icon_type,
        value v_fun)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_fun);
        elm_entry_context_menu_item_add(obj, String_val(v_label),
                String_val(v_icon_file), Elm_Icon_Type_val(v_icon_type),
                ml_Evas_Smart_Cb, data);
        return Val_unit;
}

PREFIX value ml_elm_entry_context_menu_disabled_set(value v_obj, value v_flag)
{
        elm_entry_context_menu_disabled_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_entry_context_menu_disabled_get(value v_obj)
{
        return Val_Eina_Bool(elm_entry_context_menu_disabled_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_item_provider_append(value v_obj, value v_fun)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_fun);
        elm_entry_item_provider_append(obj,
                ml_Elm_Entry_Item_Provider_Cb, data);
        return Val_unit;
}

PREFIX value ml_elm_entry_item_provider_prepend(value v_obj, value v_fun)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_fun);
        elm_entry_item_provider_prepend(obj, ml_Elm_Entry_Item_Provider_Cb,
                data);
        return Val_unit;
}

PREFIX value ml_elm_entry_markup_filter_append(value v_obj, value v_fun)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_fun);
        elm_entry_markup_filter_append(obj, ml_Elm_Entry_Filter_Cb, data);
        return Val_unit;
}

PREFIX value ml_elm_entry_markup_filter_prepend(value v_obj, value v_fun)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_fun);
        elm_entry_markup_filter_prepend(obj, ml_Elm_Entry_Filter_Cb, data);
        return Val_unit;
}

PREFIX value ml_elm_entry_markup_to_utf8(value v_s)
{
        char* s1 = elm_entry_markup_to_utf8(String_val(v_s));
        value v_s1 = copy_string(s1);
        free(s1);
        return v_s1;
}

PREFIX value ml_elm_entry_utf8_to_markup(value v_s)
{
        char* s1 = elm_entry_utf8_to_markup(String_val(v_s));
        value v_s1 = copy_string(s1);
        free(s1);
        return v_s1;
}

PREFIX value ml_elm_entry_file_set(value v_obj, value v_file, value v_format)
{
        return Val_Eina_Bool(elm_entry_file_set((Evas_Object*) v_obj,
                String_val(v_file), Elm_Text_Format_val(v_format)));
}

PREFIX value ml_elm_entry_file_get(value v_obj)
{
        CAMLparam0();
        CAMLlocal1(v);
        const char* file;
        Elm_Text_Format format;
        elm_entry_file_get((Evas_Object*) v_obj, &file, &format);
        v = caml_alloc(2, 0);
        Store_field(v, 0, copy_string(file));
        Store_field(v, 1, Val_Elm_Text_Format(format));
        CAMLreturn(v);
}

PREFIX value ml_elm_entry_file_save(value v_obj)
{
        elm_entry_file_save((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_autosave_set(value v_obj, value v_flag)
{
        elm_entry_autosave_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_entry_autosave_get(value v_obj, value v_flag)
{
        return Val_Eina_Bool(elm_entry_autosave_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_scrollable_set(value v_obj, value v_flag)
{
        elm_entry_scrollable_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_entry_scrollable_get(value v_obj)
{
        return Val_Eina_Bool(elm_entry_scrollable_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_icon_visible_set(value v_obj, value v_flag)
{
        elm_entry_icon_visible_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_entry_end_visible_set(value v_obj, value v_flag)
{
        elm_entry_end_visible_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_entry_input_panel_layout_set(value v_obj, value v_layout)
{
        elm_entry_input_panel_layout_set((Evas_Object*) v_obj,
                Elm_Input_Panel_Layout_val(v_layout));
        return Val_unit;
}

PREFIX value ml_elm_entry_input_panel_layout_get(value v_obj)
{
        return Val_Elm_Input_Panel_Layout(elm_entry_input_panel_layout_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_autocapital_type_set(value v_obj, value v_type)
{
        elm_entry_autocapital_type_set((Evas_Object*) v_obj,
                Elm_Autocapital_Type_val(v_type));
        return Val_unit;
}

PREFIX value ml_elm_entry_autocapital_type_get(value v_obj)
{
        return Val_Elm_Autocapital_Type(elm_entry_autocapital_type_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_input_panel_enabled_set(value v_obj, value v_flag)
{
        elm_entry_input_panel_enabled_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_entry_input_panel_enabled_get(value v_obj)
{
        return Val_Eina_Bool(elm_entry_input_panel_enabled_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_input_panel_show(value v_obj)
{
        elm_entry_input_panel_show((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_input_panel_hide(value v_obj)
{
        elm_entry_input_panel_hide((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_input_panel_language_set(value v_obj, value v_l)
{
        elm_entry_input_panel_language_set((Evas_Object*) v_obj,
                Elm_Input_Panel_Lang_val(v_l));
        return Val_unit;
}

PREFIX value ml_elm_entry_input_panel_language_get(value v_obj)
{
        return Val_Elm_Input_Panel_Lang(elm_entry_input_panel_language_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_input_panel_return_key_type_set(
        value v_obj, value v_t)
{
        elm_entry_input_panel_return_key_type_set((Evas_Object*) v_obj,
                Elm_Input_Panel_Return_Key_Type_val(v_t));
        return Val_unit;
}

PREFIX value ml_elm_entry_input_panel_return_key_type_get(value v_obj)
{
        return Val_Elm_Input_Panel_Return_Key_Type(
                elm_entry_input_panel_return_key_type_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_input_panel_return_key_disabled_set(
        value v_obj, value v_flag)
{
        elm_entry_input_panel_return_key_disabled_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_entry_input_panel_return_key_disabled_get(value v_obj)
{
        return Val_Eina_Bool(elm_entry_input_panel_return_key_disabled_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_input_panel_return_key_autoenabled_set(
        value v_obj, value v_flag)
{
        elm_entry_input_panel_return_key_autoenabled_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_entry_imf_context_reset(value v_obj)
{
        elm_entry_imf_context_reset((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_prediction_allow_set(value v_obj, value v_flag)
{
        elm_entry_prediction_allow_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_entry_prediction_allow_get(value v_obj)
{
        return Val_Eina_Bool(elm_entry_prediction_allow_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_filter_limit_size(
        value v_ls, value v_obj, value v_text)
{
        CAMLparam0();
        CAMLlocal1(v);
        char* text = caml_stat_alloc(strlen(String_val(v_text)) + 1);
        Elm_Entry_Filter_Limit_Size ls = Elm_Entry_Filter_Limit_Size_val(v_ls);
        strcpy(text, String_val(v_text));
        elm_entry_filter_limit_size(&ls, (Evas_Object*) v_obj, &text);
        if(text == NULL) v = Val_int(0);
        else {
                v = caml_alloc(1, 0);
                Store_field(v, 0, copy_string(text));
                free(text);
        }
        CAMLreturn(v);
}

PREFIX value ml_elm_entry_filter_accept_set(
        value v_as, value v_obj, value v_text)
{
        CAMLparam0();
        CAMLlocal1(v);
        char* text = caml_stat_alloc(strlen(String_val(v_text)) + 1);
        strcpy(text, String_val(v_text));
        Elm_Entry_Filter_Accept_Set as = Elm_Entry_Filter_Accept_Set_val(v_as);
        elm_entry_filter_accept_set(&as, (Evas_Object*) v_obj, &text);
        if(text == NULL) v = Val_int(0);
        else {
                v = caml_alloc(1, 0);
                Store_field(v, 0, copy_string(text));
                free(text);
        }
        CAMLreturn(v);
}

PREFIX value ml_elm_entry_cnp_mode_set(value v_obj, value v_mode)
{
        elm_entry_cnp_mode_set((Evas_Object*) v_obj, Elm_Cnp_Mode_val(v_mode));
        return Val_unit;
}

PREFIX value ml_elm_entry_cnp_mode_get(value v_obj)
{
        return Val_Elm_Cnp_Mode(elm_entry_cnp_mode_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_anchor_hover_parent_set(value v_obj, value v_parent)
{
        elm_entry_anchor_hover_parent_set((Evas_Object*) v_obj,
                (Evas_Object*) v_parent);
        return Val_unit;
}

PREFIX value ml_elm_entry_anchor_hover_parent_get(value v_obj)
{
        Evas_Object* parent = elm_entry_anchor_hover_parent_get(
                (Evas_Object*) v_obj);
        value v;
        if(parent == NULL) v = Val_int(0);
        else {
                v = caml_alloc(1, 0);
                Store_field(v, 0, (value) parent);
        }
        return v;
}

PREFIX value ml_elm_entry_anchor_hover_style_set(value v_obj, value v_style)
{
        elm_entry_anchor_hover_style_set((Evas_Object*) v_obj,
                String_val(v_style));
        return Val_unit;
}

PREFIX value ml_elm_entry_anchor_hover_style_get(value v_obj)
{
        return copy_string(elm_entry_anchor_hover_style_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_anchor_hover_end(value v_obj)
{
        elm_entry_anchor_hover_end((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_input_panel_layout_variation_set(value v_obj, value v_x)
{
        elm_entry_input_panel_layout_variation_set(
                (Evas_Object*) v_obj, Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_entry_input_panel_layout_variation_get(value v_obj)
{
        return Val_int(elm_entry_input_panel_layout_variation_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_anchor_info_of_ptr(value v_ptr)
{
        Elm_Entry_Anchor_Info* info = (Elm_Entry_Anchor_Info*) v_ptr;
        return copy_Elm_Entry_Anchor_Info(info);
}

PREFIX value ml_elm_entry_anchor_hover_info_of_ptr(value v_ptr)
{
        Elm_Entry_Anchor_Hover_Info* info =
                (Elm_Entry_Anchor_Hover_Info*) v_ptr;
        return copy_Elm_Entry_Anchor_Hover_Info(info);
}

