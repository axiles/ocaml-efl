#include "include.h"

PREFIX value ml_elm_box_add(value v_parent)
{
        Evas_Object* box = elm_box_add((Evas_Object*) v_parent);
        if(box == NULL) caml_failwith("elm_box_add");
        return (value) box;
}

PREFIX value ml_elm_box_horizontal_set(value v_box, value v_flag)
{
        elm_box_horizontal_set((Evas_Object*) v_box, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_box_homogeneous_set(value v_box, value v_flag)
{
        elm_box_homogeneous_set((Evas_Object*) v_box, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_box_pack_end(value v_obj, value v_subobj)
{
        elm_box_pack_end((Evas_Object*) v_obj, (Evas_Object*) v_subobj);
        return Val_unit;
}

