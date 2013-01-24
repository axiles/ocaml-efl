#include "include.h"

PREFIX value ml_elm_spinner_add(value v_parent)
{
        Evas_Object* obj = elm_spinner_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_spinner_add");
        return (value) obj;
}

PREFIX value ml_elm_spinner_min_max_set(value v_obj, value v_min, value v_max)
{
        elm_spinner_min_max_set((Evas_Object*) v_obj, Double_val(v_min),
                Double_val(v_max));
        return Val_unit;
}

