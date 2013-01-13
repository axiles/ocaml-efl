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

PREFIX value ml_elm_box_padding_get(value v_obj)
{
        Evas_Coord x, y;
        elm_box_padding_get((Evas_Object*) v_obj, &x, &y);
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_int(x));
        Store_field(v, 1, Val_int(y));
        return v;
}

PREFIX value ml_elm_box_align_set(value v_obj, value v_h, value v_v)
{
        elm_box_align_set((Evas_Object*) v_obj, Double_val(v_h),
                Double_val(v_v));
        return Val_unit;
}

PREFIX value ml_elm_box_align_get(value v_obj)
{
        CAMLparam0();
        CAMLlocal1(v);
        double x, y;
        elm_box_align_get((Evas_Object*) v_obj, &x, &y);
        v = caml_alloc(2, 0);
        Store_field(v, 0, copy_double(x));
        Store_field(v, 1, copy_double(y));
        CAMLreturn(v);
}

PREFIX value ml_elm_box_recalculate(value v_obj)
{
        elm_box_recalculate((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_box_layout_set(value v_obj, value v_cb, value v_free_data)
{
        CAMLparam3(v_obj, v_cb, v_free_data);
        CAMLlocal1(v);
        v = caml_alloc(2, 0);
        Store_field(v, 0, v_cb);
        Store_field(v, 1, v_free_data);
        value* data = caml_stat_alloc(sizeof(value));
        *data = v;
        caml_register_global_root(data);
        elm_box_layout_set((Evas_Object*) v_obj, ml_Evas_Object_Box_Layout_0,
                data, ml_Ecore_Cb_1);
        CAMLreturn(Val_unit);
}

