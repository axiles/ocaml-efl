#include "include.h"

PREFIX value ml_elm_slider_add(value v_parent)
{
        Evas_Object* obj = elm_slider_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_slider_add");
        return (value) obj;
}

PREFIX value ml_elm_slider_span_size_set(value v_obj, value v_size)
{
        elm_slider_span_size_set((Evas_Object*) v_obj, Int_val(v_size));
        return Val_unit;
}

PREFIX value ml_elm_slider_span_size_get(value v_obj)
{
        return Val_int(elm_slider_span_size_get((Evas_Object*) v_obj));
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

PREFIX value ml_elm_slider_min_max_set(value v_obj, value v_min, value v_max)
{
        elm_slider_min_max_set((Evas_Object*) v_obj, Double_val(v_min),
                Double_val(v_max));
        return Val_unit;
}

PREFIX value ml_elm_slider_min_max_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_r);
        double min, max;
        elm_slider_min_max_get((Evas_Object*) v_obj, &min, &max);
        v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, copy_double(min));
        Store_field(v_r, 1, copy_double(max));
        CAMLreturn(v_r);
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

PREFIX value ml_elm_slider_inverted_set(value v_obj, value v_flag)
{
        elm_slider_inverted_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_slider_inverted_get(value v_obj)
{
        return Val_Eina_Bool(elm_slider_inverted_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_slider_indicator_show_set(value v_obj, value v_flag)
{
        elm_slider_indicator_show_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_slider_indicator_show_get(value v_obj)
{
        return Val_Eina_Bool(elm_slider_indicator_show_get(
                (Evas_Object*) v_obj));
}

