#include "include.h"

PREFIX inline Elm_Datetime_Field_Type Elm_Datetime_Field_Type_val(value v)
{
        switch(v) {
                case Val_year: return ELM_DATETIME_YEAR;
                case Val_month: return ELM_DATETIME_MONTH;
                case Val_date: return ELM_DATETIME_DATE;
                case Val_hour: return ELM_DATETIME_HOUR;
                case Val_minute: return ELM_DATETIME_MINUTE;
                case Val_ampm: return ELM_DATETIME_AMPM;
                default: break;
        }
        caml_failwith("Elm_Datetime_Field_Type_val");
        return ELM_DATETIME_YEAR;
}

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

PREFIX value ml_elm_datetime_field_limit_set(
        value v_obj, value v_t, value v_min, value v_max)
{
        elm_datetime_field_limit_set((Evas_Object*) v_obj,
                Elm_Datetime_Field_Type_val(v_t), Int_val(v_min),
                Int_val(v_max));
        return Val_unit;
}

