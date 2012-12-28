#include "include.h"

PREFIX value ml_elm_label_add(value v_parent)
{
        Evas_Object* lb = elm_label_add((Evas_Object*) v_parent);
        if(lb == NULL) caml_failwith("elm_label_add");
        return (value) lb;
}

PREFIX value ml_elm_label_line_wrap_set(value v_obj, value v_wrap)
{
        elm_label_line_wrap_set((Evas_Object*) v_obj,
                Elm_Wrap_Type_val(v_wrap));
        return Val_unit;
}

PREFIX value ml_elm_label_line_wrap_get(value v_obj)
{
        return Val_Elm_Wrap_Type(elm_label_line_wrap_get((Evas_Object*) v_obj));
}

