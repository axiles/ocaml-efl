#include "include.h"

PREFIX value ml_elm_table_add(value v_parent)
{
        Evas_Object* obj = elm_table_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_table_add");
        return (value) obj;
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

PREFIX value ml_elm_table_pack_get(value v_obj)
{
        Evas_Coord x, y, w, h;
        elm_table_pack_get((Evas_Object*) v_obj, &x, &y, &w, &h);
        value v_r = caml_alloc(4, 0);
        Store_field(v_r, 0, Val_int(x));
        Store_field(v_r, 1, Val_int(y));
        Store_field(v_r, 2, Val_int(w));
        Store_field(v_r, 3, Val_int(h));
        return v_r;
}

PREFIX value ml_elm_table_child_get(value v_obj, value v_col, value v_row)
{
        Evas_Object* child = elm_table_child_get((Evas_Object*) v_obj,
                Int_val(v_col), Int_val(v_row));
        if(child == NULL) return Val_int(0);
        value v_r = caml_alloc(1, 0);
        Store_field(v_r, 0, (value) child);
        return v_r;
}

