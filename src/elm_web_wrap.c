#include "include.h"

inline value copy_Elm_Web_Download(Elm_Web_Download* d)
{
        CAMLparam0();
        CAMLlocal1(v_r);
        v_r = caml_alloc(1, 0);
        const char* url;
        if(d->url == NULL) url = "";
        else url = d->url;
        Store_field(v_r, 0, copy_string(url));
        CAMLreturn(v_r);
}

inline value copy_Elm_Web_Frame_Load_Error(Elm_Web_Frame_Load_Error* fle)
{
        CAMLparam0();
        CAMLlocal1(v_r);
        v_r = caml_alloc(6, 0);
        Store_field(v_r, 0, Val_int(fle->code));
        Store_field(v_r, 1, Val_bool(fle->is_cancellation));
        const char* domain;
        if(fle->domain == NULL) domain = "";
        else domain = fle->domain;
        Store_field(v_r, 2, copy_string(domain));
        const char* description;
        if(fle->description == NULL) description = "";
        else description = fle->description;
        Store_field(v_r, 3, copy_string(description));
        const char* failing_url;
        if(fle->failing_url == NULL) failing_url = "";
        else failing_url = fle->failing_url;
        Store_field(v_r, 4, copy_string(failing_url));
        Store_field(v_r, 5, (value) fle->frame);
        CAMLreturn(v_r);
}

inline value copy_Elm_Web_Frame_Load_Error_opt(Elm_Web_Frame_Load_Error* fle)
{
        CAMLparam0();
        CAMLlocal1(v);
        if(fle == NULL) v = Val_int(0);
        else {
                v = caml_alloc(1, 0);
                Store_field(v, 0, copy_Elm_Web_Frame_Load_Error(fle));
        }
        CAMLreturn(v);
}

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

inline value copy_Elm_Web_Menu_Item(Elm_Web_Menu_Item* mit)
{
        CAMLparam0();
        CAMLlocal1(v_r);
        v_r = caml_alloc(2, 0);
        const char* text;
        if(mit->text == NULL) text = "";
        else text = mit->text;
        Store_field(v_r, 0, copy_string(text));
        Store_field(v_r, 1, Val_Elm_Web_Menu_Item_Type(mit->type));
        CAMLreturn(v_r);
}

inline value copy_Eina_List_Elm_Web_Menu_Item(const Eina_List* list)
{
        CAMLparam0();
        CAMLlocal3(v, v1, v_i);
        Eina_List* it;
        Elm_Web_Menu_Item* i;
        v = Val_int(0);
        EINA_LIST_REVERSE_FOREACH(list, it, i) {
                v1 = v;
                v_i = copy_Elm_Web_Menu_Item(i);
                v = caml_alloc(2, 0);
                Store_field(v, 0, v_i);
                Store_field(v, 1, v1);
        }
        CAMLreturn(v);
}

inline value copy_Elm_Web_Menu(Elm_Web_Menu* m)
{
        CAMLparam0();
        CAMLlocal1(v_r);
        v_r = caml_alloc(6, 0);
        Store_field(v_r, 0, copy_Eina_List_Elm_Web_Menu_Item(m->items));
        Store_field(v_r, 1, Val_int(m->x));
        Store_field(v_r, 2, Val_int(m->y));
        Store_field(v_r, 3, Val_int(m->width));
        Store_field(v_r, 4, Val_int(m->height));
        Store_field(v_r, 5, Val_bool(m->handled));
        CAMLreturn(v_r);
}

PREFIX value ml_elm_web_add(Evas_Object* v_parent)
{
        Evas_Object* web = elm_web_add((Evas_Object*) v_parent);
        if(web == NULL) caml_failwith("elm_web_add");
        return (value) web;
}

PREFIX value ml_elm_web_window_create_hook_set(value v_obj, value v_fun)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_fun);
        elm_web_window_create_hook_set(obj, ml_Elm_Web_Window_Open, data);
        return Val_unit;
}

PREFIX value ml_elm_web_dialog_alert_hook_set(value v_obj, value v_fun)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_fun);
        elm_web_dialog_alert_hook_set(obj, ml_Elm_Web_Dialog_Alert, data);
        return Val_unit;
}

PREFIX value ml_elm_web_dialog_confirm_hook_set(value v_obj, value v_fun)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_fun);
        elm_web_dialog_confirm_hook_set(obj, ml_Elm_Web_Dialog_Confirm, data);
        return Val_unit;
}

PREFIX value ml_elm_web_dialog_prompt_hook_set(value v_obj, value v_fun)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_fun);
        elm_web_dialog_prompt_hook_set(obj, ml_Elm_Web_Dialog_Prompt, data);
        return Val_unit;
}

PREFIX value ml_elm_web_dialog_file_selector_hook_set(value v_obj, value v_fun)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_fun);
        elm_web_dialog_file_selector_hook_set(obj,
                ml_Elm_Web_Dialog_File_Selector, data);
        return Val_unit;
}

PREFIX value ml_elm_web_console_message_hook_set(value v_obj, value v_fun)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_fun);
        elm_web_console_message_hook_set(obj, ml_Elm_Web_Console_Message, data);
        return Val_unit;
}

PREFIX value ml_elm_web_html_string_load(
        value v_obj, value v_html, value v_base, value v_unreachable,
        value v_unit)
{
        return Val_bool(elm_web_html_string_load((Evas_Object*) v_obj,
                String_val(v_html), String_opt_val(v_base),
                String_opt_val(v_unreachable)));
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

PREFIX value ml_elm_web_window_features_region_get(value v_wf)
{
        Evas_Coord x, y, w, h;
        elm_web_window_features_region_get((Elm_Web_Window_Features*) v_wf, &x,
                &y, &w, &h);
        value v = caml_alloc(4, 0);
        Store_field(v, 0, Val_int(x));
        Store_field(v, 1, Val_int(y));
        Store_field(v, 2, Val_int(w));
        Store_field(v, 3, Val_int(h));
        return v;
}

PREFIX value ml_Elm_Web_Frame_Load_Error_of_ptr(value v_ptr)
{
        Elm_Web_Frame_Load_Error* fle = (Elm_Web_Frame_Load_Error*) v_ptr;
        return copy_Elm_Web_Frame_Load_Error(fle);
}

PREFIX value ml_Elm_Web_Menu_of_ptr(value v_ptr)
{
        Elm_Web_Menu* m = (Elm_Web_Menu*) v_ptr;
        return copy_Elm_Web_Menu(m);
}

PREFIX value ml_Elm_Web_Download_of_ptr(value v_ptr)
{
        Elm_Web_Download* d = (Elm_Web_Download*) v_ptr;
        return copy_Elm_Web_Download(d);
}

