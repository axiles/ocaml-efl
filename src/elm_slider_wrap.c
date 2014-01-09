#include "include.h"

PREFIX value ml_elm_slider_add(value v_parent)
{
        Evas_Object* obj = elm_slider_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_slider_add");
        return (value) obj;
}

PREFIX value ml_elm_slider_horizontal_set(value v_obj, value v_flag)
{
        elm_slider_horizontal_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_slider_horizontal_get(value v_obj)
{
        return Val_Eina_Bool(elm_slider_horizontal_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_slider_value_set(value v_obj, value v_v)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        double x = Double_val(v_v);
      
        elm_slider_value_set(obj, x);
      
        return Val_unit;
}

PREFIX value ml_elm_slider_value_get(value v_obj)
{
        return copy_double(elm_slider_value_get((Evas_Object*) v_obj));
}

