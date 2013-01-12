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

PREFIX value ml_elm_box_horizontal_get(value v_obj)
{
        return Val_Eina_Bool(elm_box_horizontal_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_box_homogeneous_set(value v_box, value v_flag)
{
        elm_box_homogeneous_set((Evas_Object*) v_box, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_box_homogeneous_get(value v_obj)
{
        return Val_Eina_Bool(elm_box_homogeneous_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_box_pack_start(value v_obj, value v_subobj)
{
        elm_box_pack_start((Evas_Object*) v_obj, (Evas_Object*) v_subobj);
        return Val_unit;
}

PREFIX value ml_elm_box_pack_end(value v_obj, value v_subobj)
{
        elm_box_pack_end((Evas_Object*) v_obj, (Evas_Object*) v_subobj);
        return Val_unit;
}

PREFIX value ml_elm_box_pack_before(value v_obj, value v_subobj, value v_before)
{
        elm_box_pack_before((Evas_Object*) v_obj, (Evas_Object*) v_subobj,
                (Evas_Object*) v_before);
        return Val_unit;
}

PREFIX value ml_elm_box_pack_after(value v_obj, value v_subobj, value v_after)
{
        elm_box_pack_after((Evas_Object*) v_obj, (Evas_Object*) v_subobj,
                (Evas_Object*) v_after);
        return Val_unit;
}

PREFIX value ml_elm_box_clear(value v_obj)
{
        elm_box_clear((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_box_unpack(value v_obj, value v_subobj)
{
        elm_box_unpack((Evas_Object*) v_obj, (Evas_Object*) v_subobj);
        return Val_unit;
}

PREFIX value ml_elm_box_unpack_all(value v_obj)
{
        elm_box_unpack_all((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_box_children_get(value v_obj)
{
        Eina_List* list = elm_box_children_get((Evas_Object*) v_obj);
        value v = copy_Eina_List_Evas_Object(list);
        eina_list_free(list);
        return v;
}

PREFIX value ml_elm_box_padding_set(value v_obj, value v_h, value v_v)
{
        elm_box_padding_set((Evas_Object*) v_obj, Int_val(v_h), Int_val(v_v));
        return Val_unit;
}

