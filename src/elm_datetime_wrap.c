#include "include.h"

PREFIX value ml_elm_datetime_add(value v_parent)
{
        Evas_Object* datetime = elm_datetime_add((Evas_Object*) v_parent);
        if(datetime == NULL) caml_failwith("elm_datetime_add");
        return (value) datetime;
}

PREFIX value ml_elm_datetime_format_set(value v_obj, value v_s)
{
        elm_datetime_format_set((Evas_Object*) v_obj, String_val(v_s));
        return Val_unit;
}

PREFIX value ml_elm_datetime_format_get(value v_obj)
{
        return copy_string(elm_datetime_format_get((Evas_Object*) v_obj));
}

