#include "include.h"

PREFIX value ml_elm_slider_add(value v_parent)
{
        Evas_Object* obj = elm_slider_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_slider_add");
        return (value) obj;
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

