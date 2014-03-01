#include "include.h"

PREFIX value ml_elm_mapbuf_add(value v_parent)
{
        Evas_Object* mapbuf = elm_mapbuf_add((Evas_Object*) v_parent);
        if(mapbuf == NULL) caml_failwith("elm_mapbuf_add");
        return (value) mapbuf;
}

PREFIX value ml_elm_mapbuf_enabled_set(value v_obj, value v_flag)
{
        elm_mapbuf_enabled_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_mapbuf_enabled_get(value v_obj)
{
        return Val_bool(elm_mapbuf_enabled_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_mapbuf_smooth_set(value v_obj, value v_flag)
{
        elm_mapbuf_smooth_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_mapbuf_smooth_get(value v_obj)
{
        return Val_bool(elm_mapbuf_smooth_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_mapbuf_alpha_set(value v_obj, value v_flag)
{
        elm_mapbuf_alpha_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_mapbuf_alpha_get(value v_obj)
{
        return Val_bool(elm_mapbuf_alpha_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_mapbuf_auto_set(value v_obj, value v_flag)
{
        elm_mapbuf_auto_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_mapbuf_auto_get(value v_obj)
{
        return Val_bool(elm_mapbuf_auto_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_mapbuf_point_color_set_native(
        value v_obj, value v_idx, value v_r, value v_g, value v_b, value v_a)
{
        elm_mapbuf_point_color_set((Evas_Object*) v_obj, Int_val(v_idx),
                Int_val(v_r), Int_val(v_g), Int_val(v_b), Int_val(v_a));
        return Val_unit;
}

PREFIX value ml_elm_mapbuf_point_color_set_byte(value* argv, int argn)
{
        return ml_elm_mapbuf_point_color_set_native(argv[0], argv[1], argv[2],
                argv[3], argv[4], argv[5]);
}

PREFIX value ml_elm_mapbuf_point_color_get(value v_obj, value v_idx)
{
        int r, g, b, a;
        elm_mapbuf_point_color_get((Evas_Object*) v_obj, Int_val(v_idx), &r, &g,
                &b, &a);
        value v = caml_alloc(4, 0);
        Store_field(v, 0, r);
        Store_field(v, 1, g);
        Store_field(v, 2, b);
        Store_field(v, 3, a);
        return v;
}

