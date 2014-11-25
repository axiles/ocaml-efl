#include "include.h"

PREFIX value ml_elm_grid_add(value v_parent)
{
        Evas_Object* obj = elm_grid_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_grid_add");
        return (value) obj;
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

PREFIX value ml_elm_grid_pack_get(value v_obj)
{
        Evas_Coord x, y, w, h;
        elm_grid_pack_get((Evas_Object*) v_obj, &x, &y, &w, &h);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(x));
        Store_field(v_r, 1, Val_int(y));
        Store_field(v_r, 2, Val_int(w));
        Store_field(v_r, 3, Val_int(h));
        return v_r;
}

PREFIX value ml_elm_grid_children_get(value v_obj)
{
        return copy_Eina_List_Evas_Object(elm_grid_children_get(
                (Evas_Object*) v_obj));
}

