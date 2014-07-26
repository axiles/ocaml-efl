#include "include.h"

PREFIX value ml_elm_datetime_add(value v_parent)
{
        Evas_Object* datetime = elm_datetime_add((Evas_Object*) v_parent);
        if(datetime == NULL) caml_failwith("elm_datetime_add");
        return (value) datetime;
}

PREFIX value ml_elm_datetime_value_max_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_t);
        struct tm t;
        Eina_Bool flag = elm_datetime_value_max_get((Evas_Object*) v_obj, &t);
        if(flag) {
                v_t = caml_alloc(1, 0);
                Store_field(v_t, 0, copy_tm(t));
        } else v_t = Val_int(0);
        CAMLreturn(v_t);
}

PREFIX value ml_elm_datetime_value_max_set(value v_obj, value v_t)
{
        struct tm t = Tm_val(v_t);
        return Val_bool(elm_datetime_value_max_set((Evas_Object*) v_obj, &t));
}

PREFIX value ml_elm_datetime_value_min_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_t);
        struct tm t;
        Eina_Bool flag = elm_datetime_value_min_get((Evas_Object*) v_obj, &t);
        if(flag) {
                v_t = caml_alloc(1, 0);
                Store_field(v_t, 0, copy_tm(t));
        } else v_t = Val_int(0);
        CAMLreturn(v_t);
}

PREFIX value ml_elm_datetime_value_min_set(value v_obj, value v_t)
{
        struct tm t = Tm_val(v_t);
        return Val_bool(elm_datetime_value_min_set((Evas_Object*) v_obj, &t));
}

PREFIX value ml_elm_datetime_field_limit_get(value v_obj, value v_t)
{
        int min, max;
        elm_datetime_field_limit_get((Evas_Object*) v_obj,
                Elm_Datetime_Field_Type_val(v_t), &min, &max);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(min));
        Store_field(v_r, 1, Val_int(max));
        return v_r;
}

PREFIX value ml_elm_datetime_value_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_t);
        struct tm t;
        Eina_Bool flag = elm_datetime_value_get((Evas_Object*) v_obj, &t);
        if(flag) {
                v_t = caml_alloc(1, 0);
                Store_field(v_t, 0, copy_tm(t));
        } else v_t = Val_int(0);
        CAMLreturn(v_t);
}

PREFIX value ml_elm_datetime_value_set(value v_obj, value v_t)
{
        struct tm t = Tm_val(v_t);
        return Val_bool(elm_datetime_value_set((Evas_Object*) v_obj, &t));
}

