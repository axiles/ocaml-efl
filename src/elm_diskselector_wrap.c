#include "include.h"

PREFIX value ml_elm_diskselector_add(value v_parent)
{
        Evas_Object* diskselector = elm_diskselector_add(
                Evas_Object_val(v_parent));
        if(diskselector == NULL) caml_failwith("elm_diskselector_add");
        return copy_Evas_Object(diskselector);
}

PREFIX value ml_elm_diskselector_items_get(value v_obj)
{
        return copy_Eina_List_Elm_Object_Item(elm_diskselector_items_get(
                Evas_Object_val(v_obj)));
}

PREFIX value ml_elm_diskselector_item_append(
        value v_obj, value v_label, value v_icon, value v_func, value v_unit CAMLunused)
{
        const char* label = String_opt_val(v_label);
        Evas_Object* icon = Evas_Object_opt_val(v_icon);
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
                Evas_Object_val(v_obj), label, icon, func, data);
        if(item == NULL) {
                if(data != NULL) ml_remove_value(data);
                caml_failwith("elm_diskselector_item_append");
        }
        if(data != NULL)
                elm_object_item_del_cb_set(item, ml_Evas_Smart_Cb_on_del);
        return copy_Elm_Object_Item(item);
}

PREFIX value ml_elm_diskselector_selected_item_get(value v_obj)
{
        Elm_Object_Item* item =
                elm_diskselector_selected_item_get(Evas_Object_val(v_obj));
        return copy_Elm_Object_Item_opt(item);
}

PREFIX value ml_elm_diskselector_first_item_get(value v_obj)
{
        Elm_Object_Item *it = elm_diskselector_first_item_get(
                Evas_Object_val(v_obj));
        return copy_Elm_Object_Item_opt(it);
}

PREFIX value ml_elm_diskselector_last_item_get(value v_obj)
{
        Elm_Object_Item *it = elm_diskselector_last_item_get(
                Evas_Object_val(v_obj));
        return copy_Elm_Object_Item_opt(it);
}

PREFIX value ml_elm_diskselector_item_prev_get(value v_it)
{
        Elm_Object_Item* prev = elm_diskselector_item_prev_get(
                Elm_Object_Item_val(v_it));
        return copy_Elm_Object_Item_opt(prev);
}

PREFIX value ml_elm_diskselector_item_next_get(value v_it)
{
        Elm_Object_Item* next = elm_diskselector_item_next_get(
                Elm_Object_Item_val(v_it));
        return copy_Elm_Object_Item_opt(next);
}

