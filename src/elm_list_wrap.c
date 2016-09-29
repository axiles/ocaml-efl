#include "include.h"

PREFIX value ml_elm_list_add(value v_parent)
{
        Evas_Object* obj = elm_list_add(Evas_Object_val(v_parent));
        if(obj == NULL) caml_failwith("elm_list_add");
        return copy_Evas_Object(obj);
}

PREFIX value ml_elm_list_item_append_native(
        value v_obj, value v_label, value v_icon, value v_end, value v_func,
        value v_unit CAMLunused)
{
        const char* label;
        if(v_label == Val_int(0)) label = NULL;
        else label = String_val(Field(v_label, 0));
        Evas_Object* icon;
        if(v_icon == Val_int(0)) icon = NULL;
        else icon = Evas_Object_val(Field(v_icon, 0));
        Evas_Object* end;
        if(v_end == Val_int(0)) end = NULL;
        else end = Evas_Object_val(Field(v_end, 0));
        Evas_Smart_Cb func;
        value* data;
        if(v_func == Val_int(0)) {
                func = NULL;
                data = NULL;
        } else {
                func = ml_Evas_Smart_Cb;
                data = ml_register_value(Field(v_func, 0));
        }
        Elm_Object_Item* item = elm_list_item_append(Evas_Object_val(v_obj),
                label, icon, end, func, data);
        if(item == NULL) {
                if(data != NULL) ml_remove_value(data);
                caml_failwith("elm_list_item_append");
        }
        if(data != NULL)
                elm_object_item_del_cb_set(item, ml_Evas_Smart_Cb_on_del);
        return copy_Elm_Object_Item(item);
}

PREFIX value ml_elm_list_item_append_byte(value* argv, int argn CAMLunused)
{
        return ml_elm_list_item_append_native(argv[0], argv[1], argv[2],
                argv[3], argv[4], argv[5]);
}

PREFIX value ml_elm_list_item_prepend_native(
        value v_obj, value v_label, value v_icon, value v_end, value v_func,
        value v_unit CAMLunused)
{
        const char* label;
        if(v_label == Val_int(0)) label = NULL;
        else label = String_val(Field(v_label, 0));
        Evas_Object* icon;
        if(v_icon == Val_int(0)) icon = NULL;
        else icon = Evas_Object_val(Field(v_icon, 0));
        Evas_Object* end;
        if(v_end == Val_int(0)) end = NULL;
        else end = Evas_Object_val(Field(v_end, 0));
        Evas_Smart_Cb func;
        value* data;
        if(v_func == Val_int(0)) {
                func = NULL;
                data = NULL;
        } else {
                func = ml_Evas_Smart_Cb;
                data = ml_register_value(Field(v_func, 0));
        }
        Elm_Object_Item* item = elm_list_item_prepend(Evas_Object_val(v_obj),
                label, icon, end, func, data);
        if(item == NULL) {
                if(data != NULL) ml_remove_value(data);
                caml_failwith("elm_list_item_prepend");
        }
        if(data != NULL)
                elm_object_item_del_cb_set(item, ml_Evas_Smart_Cb_on_del);
        return copy_Elm_Object_Item_opt(item);
}

PREFIX value ml_elm_list_item_prepend_byte(value* argv, int argn CAMLunused)
{
        return ml_elm_list_item_prepend_native(argv[0], argv[1], argv[2],
                argv[3], argv[4], argv[5]);
}

PREFIX value ml_elm_list_item_insert_before_native(
        value v_obj, value v_before, value v_label, value v_icon, value v_end,
        value v_func, value v_unit CAMLunused)
{
        const char* label;
        if(v_label == Val_int(0)) label = NULL;
        else label = String_val(Field(v_label, 0));
        Evas_Object* icon;
        if(v_icon == Val_int(0)) icon = NULL;
        else icon = Evas_Object_val(Field(v_icon, 0));
        Evas_Object* end;
        if(v_end == Val_int(0)) end = NULL;
        else end = Evas_Object_val(Field(v_end, 0));
        Evas_Smart_Cb func;
        value* data;
        if(v_func == Val_int(0)) {
                func = NULL;
                data = NULL;
        } else {
                func = ml_Evas_Smart_Cb;
                data = ml_register_value(Field(v_func, 0));
        }
        Elm_Object_Item* item = elm_list_item_insert_before(
                Evas_Object_val(v_obj), Elm_Object_Item_val(v_before), label,
                icon, end, func, data);
        if(item == NULL) {
                if(data != NULL) ml_remove_value(data);
                caml_failwith("elm_list_item_insert_before");
        }
        if(data != NULL)
                elm_object_item_del_cb_set(item, ml_Evas_Smart_Cb_on_del);
        return copy_Elm_Object_Item(item);
}

PREFIX value ml_elm_list_item_insert_before_byte(value* argv, int argn CAMLunused)
{
        return ml_elm_list_item_insert_before_native(argv[0], argv[1], argv[2],
                argv[3], argv[4], argv[5], argv[6]);
}

PREFIX value ml_elm_list_item_insert_after_native(
        value v_obj, value v_after, value v_label, value v_icon, value v_end,
        value v_func, value v_unit CAMLunused)
{
        const char* label;
        if(v_label == Val_int(0)) label = NULL;
        else label = String_val(Field(v_label, 0));
        Evas_Object* icon;
        if(v_icon == Val_int(0)) icon = NULL;
        else icon = Evas_Object_val(Field(v_icon, 0));
        Evas_Object* end;
        if(v_end == Val_int(0)) end = NULL;
        else end = Evas_Object_val(Field(v_end, 0));
        Evas_Smart_Cb func;
        value* data;
        if(v_func == Val_int(0)) {
                func = NULL;
                data = NULL;
        } else {
                func = ml_Evas_Smart_Cb;
                data = ml_register_value(Field(v_func, 0));
        }
        Elm_Object_Item* item = elm_list_item_insert_after(
                Evas_Object_val(v_obj),
                Elm_Object_Item_val(v_after), label, icon, end, func, data);
        if(item == NULL) {
                if(data != NULL) ml_remove_value(data);
                caml_failwith("elm_list_item_insert_after");
        }
        if(data != NULL)
                elm_object_item_del_cb_set(item, ml_Evas_Smart_Cb_on_del);
        return copy_Elm_Object_Item(item);
}

PREFIX value ml_elm_list_item_insert_after_byte(value* argv, int argn CAMLunused)
{
        return ml_elm_list_item_insert_after_native(argv[0], argv[1], argv[2],
                argv[3], argv[4], argv[5], argv[6]);
}

PREFIX value ml_elm_list_items_get(value v_obj)
{
        return copy_Eina_List_Elm_Object_Item(elm_list_items_get(
                Evas_Object_val(v_obj)));
}

PREFIX value ml_elm_list_selected_item_get(value v_obj)
{
        Elm_Object_Item* item =
                elm_list_selected_item_get(Evas_Object_val(v_obj));
        return copy_Elm_Object_Item_opt(item);
}

PREFIX value ml_elm_list_selected_items_get(value v_obj)
{
        return copy_Eina_List_Elm_Object_Item(elm_list_selected_items_get(
                Evas_Object_val(v_obj)));
}

PREFIX value ml_elm_list_item_prev(value v_it)
{
        Elm_Object_Item* it1 = elm_list_item_prev(Elm_Object_Item_val(v_it));
        return copy_Elm_Object_Item_opt(it1);
}

PREFIX value ml_elm_list_item_next(value v_it)
{
        Elm_Object_Item* it1 = elm_list_item_next(Elm_Object_Item_val(v_it));
        return copy_Elm_Object_Item_opt(it1);
}

PREFIX value ml_elm_list_first_item_get(value v_obj)
{
        Elm_Object_Item *it = elm_list_first_item_get(Evas_Object_val(v_obj));
        return copy_Elm_Object_Item_opt(it);
}

PREFIX value ml_elm_list_last_item_get(value v_obj)
{
        Elm_Object_Item *it = elm_list_last_item_get(Evas_Object_val(v_obj));
        return copy_Elm_Object_Item_opt(it);
}

