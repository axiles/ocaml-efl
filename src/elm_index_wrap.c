#include "include.h"

PREFIX value ml_elm_index_add(value v_parent)
{
        Evas_Object* obj = elm_index_add(Evas_Object_val(v_parent));
        if(obj == NULL) caml_failwith("elm_index_add");
        return copy_Evas_Object(obj);
}

PREFIX value ml_elm_index_selected_item_get(value v_obj, value v_level)
{
        Elm_Object_Item* item = elm_index_selected_item_get(
                Evas_Object_val(v_obj), Int_val(v_level));
        return copy_Elm_Object_Item_opt(item);
}

PREFIX value ml_elm_index_item_append(value v_obj, value v_letter, value v_fun)
{
        value* data = ml_register_value(v_fun);
        Elm_Object_Item* it = elm_index_item_append(Evas_Object_val(v_obj),
                String_val(v_letter), ml_Evas_Smart_Cb, data);
        if(it == NULL) {
                ml_remove_value(data);
                caml_failwith("elm_index_item_append");
        }
        elm_object_item_del_cb_set(it, ml_Evas_Smart_Cb_on_del);
        return copy_Elm_Object_Item(it);
}

PREFIX value ml_elm_index_item_prepend(value v_obj, value v_letter, value v_fun)
{
        value* data = ml_register_value(v_fun);
        Elm_Object_Item* it = elm_index_item_prepend(Evas_Object_val(v_obj),
                String_val(v_letter), ml_Evas_Smart_Cb, data);
        if(it == NULL) {
                ml_remove_value(data);
                caml_failwith("elm_index_item_prepend");
        }
        elm_object_item_del_cb_set(it, ml_Evas_Smart_Cb_on_del);
        return copy_Elm_Object_Item(it);
}

PREFIX value ml_elm_index_item_insert_after(
        value v_obj, value v_after, value v_letter, value v_fun)
{
        value* data = ml_register_value(v_fun);
        Elm_Object_Item* it = elm_index_item_insert_after(
                Evas_Object_val(v_obj), Elm_Object_Item_val(v_after),
                String_val(v_letter), ml_Evas_Smart_Cb, data);
        if(it == NULL) {
                ml_remove_value(data);
                caml_failwith("elm_index_item_prepend");
        }
        elm_object_item_del_cb_set(it, ml_Evas_Smart_Cb_on_del);
        return copy_Elm_Object_Item(it);
}

PREFIX value ml_elm_index_item_insert_before(
        value v_obj, value v_before, value v_letter, value v_fun)
{
        value* data = ml_register_value(v_fun);
        Elm_Object_Item* it = elm_index_item_insert_before(
                Evas_Object_val(v_obj),
                Elm_Object_Item_val(v_before), String_val(v_letter),
                ml_Evas_Smart_Cb, data);
        if(it == NULL) {
                ml_remove_value(data);
                caml_failwith("elm_index_item_prepend");
        }
        elm_object_item_del_cb_set(it, ml_Evas_Smart_Cb_on_del);
        return copy_Elm_Object_Item(it);
}

