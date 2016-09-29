#include "include.h"

PREFIX value ml_elm_progressbar_add(value v_parent)
{
        Evas_Object* obj = elm_progressbar_add(Evas_Object_val(v_parent));
        if(obj == NULL) caml_failwith("elm_progressbar_add");
        return copy_Evas_Object(obj);
}

PREFIX value ml_elm_progressbar_unit_format_set(value v_obj, value v_fmt)
{
        elm_progressbar_unit_format_set(Evas_Object_val(v_obj),
                String_val(v_fmt));
        return Val_unit;
}

PREFIX value ml_elm_progressbar_part_value_set(
        value v_obj, value v_part, value v_x)
{
        const char* part;
        if(v_part == Val_int(0)) part = NULL;
        else part = String_val(Field(v_part, 0));
        elm_progressbar_part_value_set(Evas_Object_val(v_obj), part,
                Double_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_progressbar_part_value_get(
        value v_obj, value v_part, value v_unit CAMLunused)
{
        const char* part;
        if(v_part == Val_int(0)) part = NULL;
        else part = String_val(Field(v_part, 0));
        return copy_double(elm_progressbar_part_value_get(
                Evas_Object_val(v_obj), part));
}


