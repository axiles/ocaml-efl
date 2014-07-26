#include "include.h"

PREFIX value ml_elm_index_add(value v_parent)
{
        Evas_Object* obj = elm_index_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_index_add");
        return (value) obj;
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
        value* data = ml_register_value(v_fun);
        Elm_Object_Item* it = elm_index_item_append((Evas_Object*) v_obj,
                String_val(v_letter), ml_Evas_Smart_Cb, data);
        if(it == NULL) {
                ml_remove_value(data);
                caml_failwith("elm_index_item_append");
        }
        elm_object_item_del_cb_set(it, ml_Evas_Smart_Cb_on_del);
        return (value) it;
}

PREFIX value ml_elm_index_item_prepend(value v_obj, value v_letter, value v_fun)
{
        value* data = ml_register_value(v_fun);
        Elm_Object_Item* it = elm_index_item_prepend((Evas_Object*) v_obj,
                String_val(v_letter), ml_Evas_Smart_Cb, data);
        if(it == NULL) {
                ml_remove_value(data);
                caml_failwith("elm_index_item_prepend");
        }
        elm_object_item_del_cb_set(it, ml_Evas_Smart_Cb_on_del);
        return (value) it;
}

PREFIX value ml_elm_index_item_insert_after(
        value v_obj, value v_after, value v_letter, value v_fun)
{
        value* data = ml_register_value(v_fun);
        Elm_Object_Item* it = elm_index_item_insert_after((Evas_Object*) v_obj,
                (Elm_Object_Item*) v_after, String_val(v_letter),
                ml_Evas_Smart_Cb, data);
        if(it == NULL) {
                ml_remove_value(data);
                caml_failwith("elm_index_item_prepend");
        }
        elm_object_item_del_cb_set(it, ml_Evas_Smart_Cb_on_del);
        return (value) it;
}

PREFIX value ml_elm_index_item_insert_before(
        value v_obj, value v_before, value v_letter, value v_fun)
{
        value* data = ml_register_value(v_fun);
        Elm_Object_Item* it = elm_index_item_insert_before((Evas_Object*) v_obj,
                (Elm_Object_Item*) v_before, String_val(v_letter),
                ml_Evas_Smart_Cb, data);
        if(it == NULL) {
                ml_remove_value(data);
                caml_failwith("elm_index_item_prepend");
        }
        elm_object_item_del_cb_set(it, ml_Evas_Smart_Cb_on_del);
        return (value) it;
}

