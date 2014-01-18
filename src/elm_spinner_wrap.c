#include "include.h"

PREFIX value ml_elm_spinner_add(value v_parent)
{
        Evas_Object* obj = elm_spinner_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_spinner_add");
        return (value) obj;
}

PREFIX value ml_elm_spinner_label_format_set(value v_obj, value v_fmt)
{
        elm_spinner_label_format_set((Evas_Object*) v_obj, String_val(v_fmt));
        return Val_unit;
}

PREFIX value ml_elm_spinner_min_max_set(value v_obj, value v_min, value v_max)
{
        elm_spinner_min_max_set((Evas_Object*) v_obj, Double_val(v_min),
                Double_val(v_max));
        return Val_unit;
}

PREFIX value ml_elm_spinner_min_max_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_r);
        double min, max;
        elm_spinner_min_max_get((Evas_Object*) v_obj, &min, &max);
        v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, copy_double(min));
        Store_field(v_r, 1, copy_double(max));
        CAMLreturn(v_r);
}

PREFIX value ml_elm_spinner_step_set(value v_obj, value v_x)
{
        elm_spinner_step_set((Evas_Object*) v_obj, Double_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_spinner_step_get(value v_obj)
{
        return copy_double(elm_spinner_step_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_spinner_value_set(value v_obj, value v_v)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        double x = Double_val(v_v);
      
        elm_spinner_value_set(obj, x);
      
        return Val_unit;
}

PREFIX value ml_elm_spinner_value_get(value v_obj)
{
        return copy_double(elm_spinner_value_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_spinner_editable_set(value v_obj, value v_flag)
{
        elm_spinner_editable_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_spinner_special_value_add(value v_obj, value v_x, value v_s)
{
        elm_spinner_special_value_add((Evas_Object*) v_obj, Double_val(v_x),
                String_val(v_s));
        return Val_unit;
}

