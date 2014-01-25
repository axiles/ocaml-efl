#include "include.h"

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

