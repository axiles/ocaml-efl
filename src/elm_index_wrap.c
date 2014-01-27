#include "include.h"

PREFIX value ml_elm_index_add(value v_parent)
{
        Evas_Object* obj = elm_index_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_index_add");
        return (value) obj;
}

PREFIX value ml_elm_index_autohide_disabled_set(value v_obj, value v_flag)
{
        elm_index_autohide_disabled_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value  ml_elm_index_autohide_disabled_get(value v_obj)
{
        return Val_bool(elm_index_autohide_disabled_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_index_item_level_set(value v_obj, value v_x)
{
        elm_index_item_level_set((Evas_Object*) v_obj, Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_index_item_level_get(value v_obj)
{
        return Val_int(elm_index_item_level_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_index_item_selected_set(value v_it, value v_flag)
{
        elm_index_item_selected_set((Elm_Object_Item*) v_it,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_index_selected_item_get(value v_obj, value v_level)
{
        Elm_Object_Item* item = elm_index_selected_item_get(
                (Evas_Object*) v_obj, Int_val(v_level));
        if(item == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) item);
        return v;
}

PREFIX value ml_elm_index_item_append(value v_obj, value v_letter, value v_fun)
{
        value* data = caml_stat_alloc(sizeof(data));
        *data = v_fun;
        caml_register_global_root(data);
        Elm_Object_Item* it = elm_index_item_append((Evas_Object*) v_obj,
                String_val(v_letter), ml_Evas_Smart_Cb, data);
        if(it == NULL) caml_failwith("elm_index_item_append");
        return (value) it;
}

PREFIX value ml_elm_index_item_prepend(value v_obj, value v_letter, value v_fun)
{
        value* data = caml_stat_alloc(sizeof(data));
        *data = v_fun;
        caml_register_global_root(data);
        Elm_Object_Item* it = elm_index_item_prepend((Evas_Object*) v_obj,
                String_val(v_letter), ml_Evas_Smart_Cb, data);
        if(it == NULL) caml_failwith("elm_index_item_prepend");
        return (value) it;
}

PREFIX value ml_elm_index_item_insert_after(
        value v_obj, value v_after, value v_letter, value v_fun)
{
        value* data = caml_stat_alloc(sizeof(data));
        *data = v_fun;
        caml_register_global_root(data);
        Elm_Object_Item* it = elm_index_item_insert_after((Evas_Object*) v_obj,
                (Elm_Object_Item*) v_after, String_val(v_letter),
                ml_Evas_Smart_Cb, data);
        if(it == NULL) caml_failwith("elm_index_item_insert_after");
        return (value) it;
}

PREFIX value ml_elm_index_item_insert_before(
        value v_obj, value v_before, value v_letter, value v_fun)
{
        value* data = caml_stat_alloc(sizeof(data));
        *data = v_fun;
        caml_register_global_root(data);
        Elm_Object_Item* it = elm_index_item_insert_before((Evas_Object*) v_obj,
                (Elm_Object_Item*) v_before, String_val(v_letter),
                ml_Evas_Smart_Cb, data);
        if(it == NULL) caml_failwith("elm_index_item_insert_before");
        return (value) it;
}

PREFIX value ml_elm_index_item_clear(value v_obj)
{
        elm_index_item_clear((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_index_level_go(value v_obj, value v_level)
{
        elm_index_level_go((Evas_Object*) v_obj, Int_val(v_level));
        return Val_unit;
}

PREFIX value ml_elm_index_item_letter_get(value v_it)
{
        return copy_string(elm_index_item_letter_get((Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_index_indicator_disabled_set(value v_obj, value v_flag)
{
        elm_index_indicator_disabled_set((Evas_Object*) v_obj,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value  ml_elm_index_indicator_disabled_get(value v_obj)
{
        return Val_bool(elm_index_indicator_disabled_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_index_horizontal_set(value v_obj, value v_flag)
{
        elm_index_horizontal_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value  ml_elm_index_horizontal_get(value v_obj)
{
        return Val_bool(elm_index_horizontal_get((Evas_Object*) v_obj));
}

