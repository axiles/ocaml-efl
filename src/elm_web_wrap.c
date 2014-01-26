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

