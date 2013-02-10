#include "include.h"

PREFIX value ml_elm_progressbar_add(value v_parent)
{
        Evas_Object* obj = elm_progressbar_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_progressbar_add");
        return (value) obj;
}

PREFIX value ml_elm_progressbar_pulse_set(value v_obj, value v_flag)
{
        elm_progressbar_pulse_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

