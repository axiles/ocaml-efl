#include "include.h"

PREFIX value ml_elm_separator_add(value v_parent)
{
        Evas_Object* obj = elm_separator_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_separator_add");
        return (value) obj;
}

PREFIX value ml_elm_separator_horizontal_set(value v_obj, value v_flag)
{
        elm_separator_horizontal_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

