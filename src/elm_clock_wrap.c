#include "include.h"

PREFIX value ml_elm_clock_add(value v_parent)
{
        Evas_Object* obj = elm_clock_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_clock_add");
        return (value) obj;
}

PREFIX value ml_elm_clock_time_set(value v_obj, value v_h, value v_m, value v_s)
{
        elm_clock_time_set((Evas_Object*) v_obj, Int_val(v_h), Int_val(v_m),
                Int_val(v_s));
        return Val_unit;
}

PREFIX value ml_elm_clock_time_get(value v_obj)
{
        int h, m, s;
        elm_clock_time_get((Evas_Object*) v_obj, &h, &m, &s);
        value v = caml_alloc(3, 0);
        Store_field(v, 0, Val_int(h));
        Store_field(v, 1, Val_int(m));
        Store_field(v, 2, Val_int(s));
        return v;
}

PREFIX value ml_elm_clock_edit_set(value v_obj, value v_flag)
{
        elm_clock_edit_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_clock_edit_get(value v_obj)
{
        return Val_bool(elm_clock_edit_get((Evas_Object*) v_obj));
}

