#include "include.h"

PREFIX value ml_elm_grid_add(value v_parent)
{
        Evas_Object* obj = elm_grid_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_grid_add");
        return (value) obj;
}

PREFIX value ml_elm_grid_size_set(value v_obj, value v_w, value v_h)
{
        elm_grid_size_set((Evas_Object*) v_obj, Int_val(v_w), Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_elm_grid_size_get(value v_obj)
{
        Evas_Coord w, h;
        elm_grid_size_get((Evas_Object*) v_obj, &w, &h);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(w));
        Store_field(v_r, 1, Val_int(h));
        return v_r;
}

