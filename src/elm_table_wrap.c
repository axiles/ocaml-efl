#include "include.h"

PREFIX value ml_elm_table_add(value v_parent)
{
        Evas_Object* obj = elm_table_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_table_add");
        return (value) obj;
}

PREFIX value ml_elm_table_homogeneous_set(value v_table, value v_flag)
{
        elm_table_homogeneous_set((Evas_Object*) v_table, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_table_homogeneous_get(value v_obj)
{
        return Val_bool(elm_table_homogeneous_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_table_padding_set(value v_obj, value v_h, value v_v)
{
        elm_table_padding_set((Evas_Object*) v_obj, Int_val(v_h), Int_val(v_v));
        return Val_unit;
}

PREFIX value ml_elm_table_padding_get(value v_obj)
{
        Evas_Coord h, v;
        elm_table_padding_get((Evas_Object*) v_obj, &h, &v);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(h));
        Store_field(v_r, 1, Val_int(v));
        return v_r;
}

