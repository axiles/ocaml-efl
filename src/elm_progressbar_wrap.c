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

PREFIX value ml_elm_progressbar_pulse_get(value v_obj)
{
        return Val_Eina_Bool(elm_progressbar_pulse_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_progressbar_pulse(value v_obj, value v_flag)
{
        elm_progressbar_pulse((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_progressbar_value_set(value v_obj, value v_v)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        double x = Double_val(v_v);
        caml_release_runtime_system();
        elm_progressbar_value_set(obj, x);
        caml_acquire_runtime_system();
        return Val_unit;
}

PREFIX value ml_elm_progressbar_value_get(value v_obj)
{
        return copy_double(elm_progressbar_value_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_progressbar_span_size_set(value v_obj, value v_v)
{
        elm_progressbar_span_size_set((Evas_Object*) v_obj, Int_val(v_v));
        return Val_unit;
}

PREFIX value ml_elm_progressbar_span_size_get(value v_obj)
{
        return Val_int(elm_progressbar_span_size_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_progressbar_horizontal_set(value v_obj, value v_flag)
{
        elm_progressbar_horizontal_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_progressbar_horizontal_get(value v_obj)
{
        return Val_Eina_Bool(elm_progressbar_horizontal_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_progressbar_inverted_set(value v_obj, value v_flag)
{
        elm_progressbar_inverted_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_progressbar_inverted_get(value v_obj)
{
        return Val_Eina_Bool(elm_progressbar_inverted_get(
                (Evas_Object*) v_obj));
}

