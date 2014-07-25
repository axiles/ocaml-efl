#include "include.h"

PREFIX value ml_elm_diskselector_add(Evas_Object* v_parent)
{
        Evas_Object* diskselector = elm_diskselector_add(
                (Evas_Object*) v_parent);
        if(diskselector == NULL) caml_failwith("elm_diskselector_add");
        return (value) diskselector;
}

PREFIX value ml_elm_diskselector_items_get(value v_obj)
{
        return copy_Eina_List_Elm_Object_Item(elm_diskselector_items_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_diskselector_item_append(
        value v_obj, value v_label, value v_icon, value v_func, value v_unit)
{
        const char* label;
        if(v_label == Val_int(0)) label = NULL;
        else label = String_val(Field(v_label, 0));
        Evas_Object* icon;
        if(v_icon == Val_int(0)) icon = NULL;
        else icon = (Evas_Object*) Field(v_icon, 0);
        Evas_Smart_Cb func;
        value* data;
        if(v_func == Val_int(0)) {
                func = NULL;
                data = NULL;
        } else {
                func = ml_Evas_Smart_Cb;
                data = ml_register_value(Field(v_func, 0));
        }
        Elm_Object_Item* item = elm_diskselector_item_append(
                (Evas_Object*) v_obj, label, icon, func, data);
        if(item == NULL) {
                if(data != NULL) ml_remove_value(data);
                caml_failwith("elm_diskselector_item_append");
        }
        if(data != NULL)
                elm_object_item_del_cb_set(item, ml_Evas_Smart_Cb_on_del);
        return (value) item;
}

PREFIX value ml_elm_diskselector_selected_item_get(value v_obj)
{
        Elm_Object_Item* item =
                elm_diskselector_selected_item_get((Evas_Object*) v_obj);
        if(item == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) item);
        return v;
}

PREFIX value ml_elm_diskselector_first_item_get(value v_obj)
{
        Elm_Object_Item *it = elm_diskselector_first_item_get(
                (Evas_Object*) v_obj);
        if(it == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) it);
        return v;
}

PREFIX value ml_elm_diskselector_last_item_get(value v_obj)
{
        Elm_Object_Item *it = elm_diskselector_last_item_get(
                (Evas_Object*) v_obj);
        if(it == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) it);
        return v;
}

PREFIX value ml_elm_diskselector_item_prev_get(value v_it)
{
        Elm_Object_Item* prev = elm_diskselector_item_prev_get(
                (Elm_Object_Item*) v_it);
        if(prev == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) prev);
        return v;
}

PREFIX value ml_elm_diskselector_item_next_get(value v_it)
{
        Elm_Object_Item* next = elm_diskselector_item_next_get(
                (Elm_Object_Item*) v_it);
        if(next == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) next);
        return v;
}

