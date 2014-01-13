#include "include.h"

PREFIX void ml_Elm_Transit_Effect_Transition_Cb(
        Elm_Transit_Effect* effect, Elm_Transit* tr, double progress)
{
        CAMLparam0();
        CAMLlocal1(v_progress);
        value* v_fun = (value*) effect;
        v_progress = copy_double(progress);
        caml_callback2(*v_fun, (value) tr, v_progress);
        CAMLreturn0;
}

PREFIX void ml_Elm_Transit_Effect_End_Cb_free_only(
        Elm_Transit_Effect* effect, Elm_Transit* tr)
{
        value* v_fun = (value*) effect;
        caml_remove_global_root(v_fun);
        free(v_fun);
}

PREFIX void ml_Elm_Transit_Del_Cb(void* data, Elm_Transit* tr)
{
        value* v_fun = (value*) data;
        caml_callback(*v_fun, (value) tr);
        caml_remove_global_root(v_fun);
        free(v_fun);
}

PREFIX value ml_elm_transit_add(value v_unit)
{
        Elm_Transit* tr = elm_transit_add();
        if(tr == NULL) caml_failwith("elm_transit_add");
        return (value) tr;
}

PREFIX value ml_elm_transit_del(value v_tr)
{
        elm_transit_del((Elm_Transit*) v_tr);
        return Val_unit;
}

PREFIX value ml_elm_transit_effect_add(value v_tr, value v_fun)
{
        CAMLparam2(v_tr, v_fun);
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_fun;
        elm_transit_effect_add((Elm_Transit*) v_tr,
                ml_Elm_Transit_Effect_Transition_Cb, data,
                ml_Elm_Transit_Effect_End_Cb_free_only);
        CAMLreturn(Val_unit);
}

PREFIX value ml_elm_transit_object_add(value v_tr, value v_obj)
{
        elm_transit_object_add((Elm_Transit*) v_tr, (Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_transit_object_remove(value v_tr, value v_obj)
{
        elm_transit_object_remove((Elm_Transit*) v_tr, (Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_transit_objects_get(value v_tr)
{
        return copy_Eina_List_Evas_Object(elm_transit_objects_get(
                (Elm_Transit*) v_tr));
}

PREFIX value ml_elm_transit_objects_final_state_keep_set(
        value v_tr, value v_flag)
{
        elm_transit_objects_final_state_keep_set((Elm_Transit*) v_tr,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_transit_objects_final_state_keep_get(value v_tr)
{
        return Val_bool(elm_transit_objects_final_state_keep_get(
                (Elm_Transit*) v_tr));
}

PREFIX value ml_elm_transit_event_enabled_set(value v_tr, value v_flag)
{
        elm_transit_event_enabled_set((Elm_Transit*) v_tr, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_transit_event_enabled_get(value v_tr)
{
        return Val_bool(elm_transit_event_enabled_get((Elm_Transit*) v_tr));
}

PREFIX value ml_elm_transit_del_cb_set(value v_tr, value v_fun)
{
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_fun;
        caml_register_global_root(data);
        elm_transit_del_cb_set((Elm_Transit*) v_tr, ml_Elm_Transit_Del_Cb,
                data);
        return Val_unit;
}

PREFIX value ml_elm_transit_auto_reverse_set(value v_tr, value v_flag)
{
        elm_transit_auto_reverse_set((Elm_Transit*) v_tr, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_transit_auto_reverse_get(value v_tr)
{
        return Val_bool(elm_transit_auto_reverse_get((Elm_Transit*) v_tr));
}

PREFIX value ml_elm_transit_repeat_times_set(value v_tr, value v_num)
{
        elm_transit_repeat_times_set((Elm_Transit*) v_tr, Int_val(v_num));
        return Val_unit;
}

PREFIX value ml_elm_transit_repeat_times_get(value v_tr)
{
        return Val_int(elm_transit_repeat_times_get((Elm_Transit*) v_tr));
}

