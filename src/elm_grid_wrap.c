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

PREFIX value ml_elm_grid_pack_native(
        value v_obj, value v_subobj, value v_x, value v_y, value v_w, value v_h)
{
        elm_grid_pack((Evas_Object*) v_obj, (Evas_Object*) v_subobj,
                Int_val(v_x), Int_val(v_y), Int_val(v_w), Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_elm_grid_pack_bytecode(value* argv, int argn)
{
        return ml_elm_grid_pack_native(argv[0], argv[1], argv[2], argv[3],
                argv[4], argv[5]);
}

PREFIX value ml_elm_grid_unpack(value v_obj, value v_subobj)
{
        elm_grid_unpack((Evas_Object*) v_obj, (Evas_Object*) v_subobj);
        return Val_unit;
}

PREFIX value ml_elm_grid_clear(value v_obj, value v_flag)
{
        elm_grid_clear((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_grid_pack_set(
        value v_obj, value v_x, value v_y, value v_w, value v_h)
{
        elm_grid_pack_set((Evas_Object*) v_obj, Int_val(v_x), Int_val(v_y),
                Int_val(v_w), Int_val(v_h));
        return Val_unit;
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

