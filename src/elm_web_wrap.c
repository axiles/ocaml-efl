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

