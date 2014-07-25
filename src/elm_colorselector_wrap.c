#include "include.h"

PREFIX value ml_elm_colorselector_add(value v_parent)
{
        Evas_Object* colorselector = elm_colorselector_add(
                (Evas_Object*) v_parent);
        if(colorselector == NULL) caml_failwith("elm_colorselector_add");
        return (value) colorselector;
}

PREFIX value ml_elm_colorselector_color_get(value v_obj)
{
        int r, g, b, a;
        elm_colorselector_color_get((Evas_Object*) v_obj, &r, &g, &b, &a);
        value v = caml_alloc(4, 0);
        Store_field(v, 0, Val_int(r));
        Store_field(v, 1, Val_int(g));
        Store_field(v, 2, Val_int(b));
        Store_field(v, 3, Val_int(a));
        return v;
}

PREFIX value ml_elm_colorselector_palette_item_color_get(value v_it)
{
        int r, g, b, a;
        elm_colorselector_palette_item_color_get((Elm_Object_Item*) v_it, &r,
                &g, &b, &a);
        value v = caml_alloc(4, 0);
        Store_field(v, 0, Val_int(r));
        Store_field(v, 1, Val_int(g));
        Store_field(v, 2, Val_int(b));
        Store_field(v, 3, Val_int(a));
        return v;
}

PREFIX value ml_elm_colorselector_palette_color_add(
        value v_obj, value v_r, value v_g, value v_b, value v_a)
{
        Elm_Object_Item* it = elm_colorselector_palette_color_add(
                (Evas_Object*) v_obj, Int_val(v_r), Int_val(v_g), Int_val(v_b),
                Int_val(v_a));
        if(it == NULL) caml_failwith("elm_colorselector_palette_color_add");
        return (value) it;
}

