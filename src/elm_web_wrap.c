#include "include.h"

Evas_Object* ml_Elm_Web_Window_Open(
        void* data, Evas_Object* obj, Eina_Bool js,
        const Elm_Web_Window_Features* window_features)
{
        CAMLparam0();
        CAMLlocal1(v_r);
        value* v_fun = (value*) data;
        v_r = caml_callback3(*v_fun, (value) obj, Val_bool(js),
                (value) window_features);
        Evas_Object* r;
        if(v_r == Val_int(0)) r = NULL;
        else r = (Evas_Object*) Field(v_r, 0);
        CAMLreturnT(Evas_Object*, r);
}

Evas_Object* ml_Elm_Web_Dialog_Alert(
        void* data,  Evas_Object* obj, const char* message)
{
        CAMLparam0();
        CAMLlocal2(v_message, v_r);
        value* v_fun = (value*) data;
        v_message = copy_string(message);
        v_r = caml_callback2(*v_fun, (value) obj, v_message);
        Evas_Object* r;
        if(v_r == Val_int(0)) r = NULL;
        else r = (Evas_Object*) Field(v_r, 0);
        CAMLreturnT(Evas_Object*, r);
}

Evas_Object* ml_Elm_Web_Dialog_Confirm(
        void* data, Evas_Object* obj, const char* message, Eina_Bool* ret)
{
        CAMLparam0();
        CAMLlocal3(v_message, v_r, v_r_obj);
        value* v_fun = (value*) data;
        v_message = copy_string(message);
        v_r = caml_callback2(*v_fun, (value) obj, v_message);
        v_r_obj = Field(v_r, 0);
        Evas_Object* r_obj;
        if(v_r_obj == Val_int(0)) r_obj = NULL;
        else r_obj = (Evas_Object*) Field(v_r_obj, 0);
        *ret = Bool_val(Field(v_r, 1));
        CAMLreturnT(Evas_Object*, r_obj);
}

Evas_Object* ml_Elm_Web_Dialog_Prompt(
        void* data, Evas_Object* obj, const char* message,
        const char* def_value, const char** val, Eina_Bool* ret)
{
        CAMLparam0();
        CAMLlocal5(v_message, v_def_value, v_r, v_r_obj, v_r_val);
        value* v_fun = (value*) data;
        v_message = copy_string(message);
        if(def_value == NULL) v_def_value = copy_string("");
        else v_def_value = copy_string(def_value);
        v_r = caml_callback3(*v_fun, (value) obj, v_message, v_def_value);
        v_r_obj = Field(v_r, 0);
        Evas_Object* r_obj;
        if(v_r_obj == Val_int(0)) r_obj = NULL;
        else r_obj = (Evas_Object*) Field(v_r_obj, 0);
        v_r_val = Field(v_r, 1);
        if(v_r_val == Val_int(0)) val = NULL;
        *val = strdup(String_val(Field(v_r_val, 0)));
        *ret = Bool_val(Field(v_r, 2));
        CAMLreturnT(Evas_Object*, r_obj);
}

Evas_Object* ml_Elm_Web_Dialog_File_Selector(
        void* data, Evas_Object* obj, Eina_Bool allows_multiple,
        Eina_List *accept_types, Eina_List** selected, Eina_Bool* ret)
{
        CAMLparam0();
        CAMLlocal3(v_accept_types, v_r, v_r_obj);
        value* v_fun = (value*) data;
        v_accept_types = copy_Eina_List_string(accept_types);
        v_r = caml_callback3(*v_fun, (value) obj, Val_bool(allows_multiple),
                v_accept_types);
        v_r_obj = Field(v_r, 0);
        Evas_Object* r_obj;
        if(v_r_obj == Val_int(0)) r_obj = NULL;
        *selected = Eina_List_string_malloc_val(Field(v_r, 1));
        *ret = Bool_val(Field(v_r, 2));
        CAMLreturnT(Evas_Object*, r_obj);
}

void ml_Elm_Web_Console_Message(
        void* data, Evas_Object* obj, const char* message,
        unsigned int line_number, const char* source_id)
{
        CAMLparam0();
        CAMLlocal2(v_message, v_source_id);
        value* v_fun = (value*) data;
        if(message == NULL) v_message = copy_string("");
        else v_message = copy_string(message);
        if(source_id == NULL) v_source_id = copy_string("");
        else v_source_id = copy_string(source_id);
        value args[] = {(value) obj, v_message, Val_int(line_number),
                v_source_id};
        caml_callbackN(*v_fun, 4, args);
        CAMLreturn0;
}

PREFIX inline Elm_Web_Zoom_Mode Elm_Web_Zoom_Mode_val(value v)
{
        switch(v) {
                case Val_manual: return ELM_WEB_ZOOM_MODE_MANUAL;
                case Val_auto_fit: return ELM_WEB_ZOOM_MODE_AUTO_FIT;
                case Val_auto_fill: return ELM_WEB_ZOOM_MODE_AUTO_FILL;
                case Val_last: return ELM_WEB_ZOOM_MODE_LAST;
                default: break;
        }
        caml_failwith("Elm_Web_Zoom_Mode_val");
        return ELM_WEB_ZOOM_MODE_MANUAL;
}

PREFIX inline value Val_Elm_Web_Zoom_Mode(Elm_Web_Zoom_Mode m)
{
        switch(m) {
                case ELM_WEB_ZOOM_MODE_MANUAL: return Val_manual;
                case ELM_WEB_ZOOM_MODE_AUTO_FIT: return Val_auto_fit;
                case ELM_WEB_ZOOM_MODE_AUTO_FILL: return Val_auto_fill;
                case ELM_WEB_ZOOM_MODE_LAST: return Val_last;
        }
        caml_failwith("Val_Elm_Web_Zoom_Mode");
        return Val_manual;
}

PREFIX value ml_elm_web_add(Evas_Object* v_parent)
{
        Evas_Object* web = elm_web_add((Evas_Object*) v_parent);
        if(web == NULL) caml_failwith("elm_web_add");
        return (value) web;
}

PREFIX value ml_elm_web_useragent_set(value v_obj, value v_s)
{
        elm_web_useragent_set((Evas_Object*) v_obj, String_val(v_s));
        return Val_unit;
}

PREFIX value ml_elm_web_useragent_get(value v_obj)
{
        return copy_string(elm_web_useragent_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_web_webkit_view_get(value v_obj)
{
        return (value) elm_web_webkit_view_get((Evas_Object*) v_obj);
}

PREFIX value ml_elm_web_window_create_hook_set(value v_obj, value v_fun)
{
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_fun;
        caml_register_global_root(data);
        elm_web_window_create_hook_set((Evas_Object*) v_obj,
                ml_Elm_Web_Window_Open, data);
        return Val_unit;
}

PREFIX value ml_elm_web_dialog_alert_hook_set(value v_obj, value v_fun)
{
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_fun;
        caml_register_global_root(data);
        elm_web_dialog_alert_hook_set((Evas_Object*) v_obj,
                ml_Elm_Web_Dialog_Alert, data);
        return Val_unit;
}

PREFIX value ml_elm_web_dialog_confirm_hook_set(value v_obj, value v_fun)
{
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_fun;
        caml_register_global_root(data);
        elm_web_dialog_confirm_hook_set((Evas_Object*) v_obj,
                ml_Elm_Web_Dialog_Confirm, data);
        return Val_unit;
}

PREFIX value ml_elm_web_dialog_prompt_hook_set(value v_obj, value v_fun)
{
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_fun;
        caml_register_global_root(data);
        elm_web_dialog_prompt_hook_set((Evas_Object*) v_obj,
                ml_Elm_Web_Dialog_Prompt, data);
        return Val_unit;
}

PREFIX value ml_elm_web_dialog_file_selector_hook_set(value v_obj, value v_fun)
{
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_fun;
        caml_register_global_root(data);
        elm_web_dialog_file_selector_hook_set((Evas_Object*) v_obj,
                ml_Elm_Web_Dialog_File_Selector, data);
        return Val_unit;
}

PREFIX value ml_elm_web_console_message_hook_set(value v_obj, value v_fun)
{
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_fun;
        caml_register_global_root(data);
        elm_web_console_message_hook_set((Evas_Object*) v_obj,
                ml_Elm_Web_Console_Message, data);
        return Val_unit;
}

PREFIX value ml_elm_web_tab_propagate_get(value v_obj)
{
        return Val_bool(elm_web_tab_propagate_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_web_tab_propagate_set(value v_obj, value v_flag)
{
        elm_web_tab_propagate_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_web_url_set(value v_obj, value v_s)
{
        elm_web_url_set((Evas_Object*) v_obj, String_val(v_s));
        return Val_unit;
}

PREFIX value ml_elm_web_url_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_s);
        const char* s = elm_web_url_get((Evas_Object*) v_obj);
        if(s == NULL) v_s = Val_int(0);
        else {
                v_s = caml_alloc(1, 0);
                Store_field(v_s, 0, copy_string(s));
        }
        CAMLreturn(v_s);
}

PREFIX value ml_elm_web_title_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_s);
        const char* s = elm_web_title_get((Evas_Object*) v_obj);
        if(s == NULL) v_s = Val_int(0);
        else {
                v_s = caml_alloc(1, 0);
                Store_field(v_s, 0, copy_string(s));
        }
        CAMLreturn(v_s);
}

PREFIX value ml_elm_web_bg_color_set(
        value v_obj, value v_r, value v_g, value v_b, value v_a)
{
        elm_web_bg_color_set((Evas_Object*) v_obj, Int_val(v_r), Int_val(v_g),
                Int_val(v_b), Int_val(v_a));
        return Val_unit;
}

PREFIX value ml_elm_web_bg_color_get(value v_obj)
{
        int r, g, b, a;
        elm_web_bg_color_get((Evas_Object*) v_obj, &r, &g, &b, &a);
        value v_r = caml_alloc(4, 0);
        Store_field(v_r, 0, Val_int(r));
        Store_field(v_r, 1, Val_int(g));
        Store_field(v_r, 2, Val_int(b));
        Store_field(v_r, 3, Val_int(a));
        return v_r;
}

PREFIX value ml_elm_web_selection_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_s);
        const char* s = elm_web_selection_get((Evas_Object*) v_obj);
        if(s == NULL) v_s = Val_int(0);
        else {
                v_s = caml_alloc(1, 0);
                Store_field(v_s, 0, copy_string(s));
        }
        CAMLreturn(v_s);
}

PREFIX value ml_elm_web_popup_selected_set(value v_obj, value v_x)
{
        elm_web_popup_selected_set((Evas_Object*) v_obj, Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_web_popup_destroy(value v_obj)
{
        return Val_bool(elm_web_popup_destroy((Evas_Object*) v_obj));
}

PREFIX value ml_elm_web_text_search(
        value v_obj, value v_s, value v_cs, value v_fwd, value v_wrp)
{
        return Val_bool(elm_web_text_search((Evas_Object*) v_obj,
                String_val(v_s), Bool_val(v_cs), Bool_val(v_fwd),
                Bool_val(v_wrp)));
}

PREFIX value ml_elm_web_text_matches_mark(
        value v_obj, value v_s, value v_cs, value v_hl, value v_limit)
{
        return Val_int(elm_web_text_matches_mark((Evas_Object*) v_obj,
                String_val(v_s), Bool_val(v_cs), Bool_val(v_hl),
                Int_val(v_limit)));
}

PREFIX value ml_elm_web_text_matches_unmark_all(value v_obj)
{
        return Val_bool(elm_web_text_matches_unmark_all((Evas_Object*) v_obj));
}

PREFIX value ml_elm_web_text_matches_highlight_set(value v_obj, value v_flag)
{
        return Val_bool(elm_web_text_matches_highlight_set((Evas_Object*) v_obj,
                Bool_val(v_flag)));
}

PREFIX value ml_elm_web_text_matches_highlight_get(value v_obj)
{
        return Val_bool(elm_web_text_matches_highlight_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_web_load_progress_get(value v_obj)
{
        return copy_double(elm_web_load_progress_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_web_stop(value v_obj)
{
        return Val_bool(elm_web_stop((Evas_Object*) v_obj));
}

PREFIX value ml_elm_web_reload(value v_obj)
{
        return Val_bool(elm_web_reload((Evas_Object*) v_obj));
}

PREFIX value ml_elm_web_reload_full(value v_obj)
{
        return Val_bool(elm_web_reload_full((Evas_Object*) v_obj));
}

PREFIX value ml_elm_web_back(value v_obj)
{
        return Val_bool(elm_web_back((Evas_Object*) v_obj));
}

PREFIX value ml_elm_web_forward(value v_obj)
{
        return Val_bool(elm_web_forward((Evas_Object*) v_obj));
}

PREFIX value ml_elm_web_navigate(value v_obj, value v_n)
{
        return Val_bool(elm_web_navigate((Evas_Object*) v_obj, Int_val(v_n)));
}

PREFIX value ml_elm_web_back_possible_get(value v_obj)
{
        return Val_bool(elm_web_back_possible_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_web_forward_possible_get(value v_obj)
{
        return Val_bool(elm_web_forward_possible_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_web_navigate_possible_get(value v_obj, value v_n)
{
        return Val_bool(elm_web_navigate_possible_get(
                (Evas_Object*) v_obj, Int_val(v_n)));
}

PREFIX value ml_elm_web_history_enabled_get(value v_obj)
{
        return Val_bool(elm_web_history_enabled_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_web_history_enabled_set(value v_obj, value v_flag)
{
        elm_web_history_enabled_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_web_zoom_set(value v_obj, value v_x)
{
        elm_web_zoom_set((Evas_Object*) v_obj, Double_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_web_zoom_get(value v_obj)
{
        return copy_double(elm_web_zoom_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_web_zoom_mode_set(value v_obj, value v_mode)
{
        elm_web_zoom_mode_set((Evas_Object*) v_obj,
                Elm_Web_Zoom_Mode_val(v_mode));
        return Val_unit;
}

PREFIX value ml_elm_web_zoom_mode_get(value v_obj)
{
        return Val_Elm_Web_Zoom_Mode(elm_web_zoom_mode_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_web_region_show(
        value v_obj, value v_x, value v_y, value v_w, value v_h)
{
        elm_web_region_show((Evas_Object*) v_obj, Int_val(v_x), Int_val(v_y),
                Int_val(v_w), Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_elm_web_region_bring_in(
        value v_obj, value v_x, value v_y, value v_w, value v_h)
{
        elm_web_region_bring_in((Evas_Object*) v_obj, Int_val(v_x),
                Int_val(v_y), Int_val(v_w), Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_elm_web_inwin_mode_set(
        value v_obj, value v_flag)
{
        elm_web_inwin_mode_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_web_inwin_mode_get(value v_obj)
{
        return Val_bool(elm_web_inwin_mode_get((Evas_Object*) v_obj));
}

