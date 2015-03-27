#include "include.h"

PREFIX value ml_elm_box_add(value v_parent)
{
        Evas_Object* box = elm_box_add(Evas_Object_val(v_parent));
        if(box == NULL) caml_failwith("elm_box_add");
        return copy_Evas_Object(box);
}

PREFIX value ml_elm_box_children_get(value v_obj)
{
        Eina_List* list = elm_box_children_get(Evas_Object_val(v_obj));
        value v = copy_Eina_List_Evas_Object(list);
        eina_list_free(list);
        return v;
}

PREFIX value ml_elm_box_padding_get(value v_obj)
{
        Evas_Coord x, y;
        elm_box_padding_get(Evas_Object_val(v_obj), &x, &y);
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_int(x));
        Store_field(v, 1, Val_int(y));
        return v;
}

PREFIX value ml_elm_box_align_get(value v_obj)
{
        CAMLparam0();
        CAMLlocal1(v);
        double x, y;
        elm_box_align_get(Evas_Object_val(v_obj), &x, &y);
        v = caml_alloc(2, 0);
        Store_field(v, 0, copy_double(x));
        Store_field(v, 1, copy_double(y));
        CAMLreturn(v);
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
        caml_register_generational_global_root(data);
        elm_box_layout_set(Evas_Object_val(v_obj), ml_Evas_Object_Box_Layout_0,
                data, ml_Ecore_Cb_1_free);
        CAMLreturn(Val_unit);
}

PREFIX value ml_elm_box_layout_transition(value v_t, value v_obj, value v_priv)
{
        elm_box_layout_transition(Evas_Object_val(v_obj),
                Evas_Object_Box_Data_val(v_priv), Elm_Box_Transition_val(v_t));
        return Val_unit;
}

PREFIX value ml_elm_box_transition_new_native(
        value v_duration, value v_start_layout, value v_start_layout_free,
        value v_end_layout, value v_end_layout_free, value v_transition_end_cb)
{
        CAMLparam5(v_duration, v_start_layout, v_start_layout_free,
                v_end_layout, v_end_layout_free);
        CAMLxparam1(v_transition_end_cb);
        CAMLlocal2(v1, v2);
        v1 = caml_alloc(2, 0);
        Store_field(v1, 0, v_start_layout);
        Store_field(v1, 1, v_start_layout_free);
        v2 = caml_alloc(2, 0);
        Store_field(v2, 0, v_end_layout);
        Store_field(v2, 1, v_end_layout_free);
        value* data1 = caml_stat_alloc(sizeof(value));
        *data1 = v1;
        caml_register_generational_global_root(data1);
        value* data2 = caml_stat_alloc(sizeof(value));
        *data2 = v2;
        caml_register_generational_global_root(data2);
        value* data3 = caml_stat_alloc(sizeof(value));
        *data3 = v_transition_end_cb;
        caml_register_generational_global_root(data3);
        Elm_Box_Transition* t = elm_box_transition_new(Double_val(v_duration),
                ml_Evas_Object_Box_Layout_0, data1, ml_Ecore_Cb_1_free,
                ml_Evas_Object_Box_Layout_0, data2, ml_Ecore_Cb_1_free,
                ml_Ecore_Cb_free, data3);
        CAMLreturn(copy_Elm_Box_Transition(t));
}

PREFIX value ml_elm_box_transition_new_byte(value* argv, int argc)
{
        return ml_elm_box_transition_new_native(argv[0], argv[1], argv[2],
                argv[3], argv[4], argv[5]);
}

PREFIX value ml_elm_box_transition_free(value v_t, value v_unit)
{
        elm_box_transition_free(Elm_Box_Transition_val(v_t));
	      return Val_unit;
}

