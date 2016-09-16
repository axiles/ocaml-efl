#include "include.h"

PREFIX value ml_elm_menu_add(value v_parent)
{
        Evas_Object* obj = elm_menu_add(Evas_Object_val(v_parent));
        if(obj == NULL) caml_failwith("elm_menu_add");
        return copy_Evas_Object(obj);
}

PREFIX value ml_elm_menu_items_get(value v_obj)
{
        return copy_Eina_List_Elm_Object_Item(elm_menu_items_get(
                Evas_Object_val(v_obj)));
}

PREFIX value ml_elm_menu_item_add_native(
        value v_obj, value v_parent, value v_icon, value v_label, value v_func,
        value v_unit)
{
        Elm_Object_Item* parent = Elm_Object_Item_opt_val(v_parent);
        const char* icon;
        if(v_icon == Val_int(0)) icon = NULL;
        else icon = String_val(Field(v_icon, 0));
        const char* label;
        if(v_label == Val_int(0)) label = NULL;
        else label = String_val(Field(v_label, 0));
        Evas_Smart_Cb func;
        value* data;
        if(v_func == Val_int(0)) {
                func = NULL;
                data = NULL;
        } else {
                func = ml_Evas_Smart_Cb;
                data = ml_register_value(Field(v_func, 0));
        }
        Elm_Object_Item* item = elm_menu_item_add(Evas_Object_val(v_obj),
                parent, icon, label, func, data);
        if(item == NULL) {
                if(data != NULL) ml_remove_value(data);
                caml_failwith("elm_menu_item_add");
        }
        if(data != NULL)
                elm_object_item_del_cb_set(item, ml_Evas_Smart_Cb_on_del);
        return copy_Elm_Object_Item(item);
}

PREFIX value ml_elm_menu_item_add_byte(value* argv, int argn)
{
        return ml_elm_menu_item_add_native(argv[0], argv[1], argv[2], argv[3],
                argv[4], argv[5]);
}

PREFIX value ml_elm_menu_item_icon_name_get(value v_it)
{
        CAMLparam0();
        CAMLlocal1(v);
        const char* icon = elm_menu_item_icon_name_get(
                Elm_Object_Item_val(v_it));
        if(icon == NULL) CAMLreturn(Val_int(0));
        v = caml_alloc(1, 0);
        Store_field(v, 0, copy_string(icon));
        CAMLreturn(v);
}

PREFIX value ml_elm_menu_item_separator_add(value v_obj, value v_parent)
{
        Elm_Object_Item* it = elm_menu_item_separator_add(
                Evas_Object_val(v_obj),
                Elm_Object_Item_val(v_parent));
        return copy_Elm_Object_Item_opt(it);
}

PREFIX value ml_elm_menu_item_subitems_get(value v_it)
{
        return copy_Eina_List_Elm_Object_Item(elm_menu_item_subitems_get(
                Elm_Object_Item_val(v_it)));
}

PREFIX value ml_elm_menu_selected_item_get(value v_obj)
{
        Elm_Object_Item* it = elm_menu_selected_item_get(
                Evas_Object_val(v_obj));
        return copy_Elm_Object_Item_opt(it);
}

PREFIX value ml_elm_menu_last_item_get(value v_obj)
{
        Elm_Object_Item* it = elm_menu_last_item_get(
                Evas_Object_val(v_obj));
        return copy_Elm_Object_Item_opt(it);
}

PREFIX value ml_elm_menu_first_item_get(value v_obj)
{
        Elm_Object_Item* it = elm_menu_first_item_get(Evas_Object_val(v_obj));
        return copy_Elm_Object_Item_opt(it);
}

PREFIX value ml_elm_menu_item_next_get(value v_it)
{
        Elm_Object_Item* next = elm_menu_item_next_get(
                  Elm_Object_Item_val(v_it));
        return copy_Elm_Object_Item_opt(next);
}

PREFIX value ml_elm_menu_item_prev_get(value v_it)
{
        Elm_Object_Item* prev = elm_menu_item_prev_get(
                Elm_Object_Item_val(v_it));
        return copy_Elm_Object_Item_opt(prev);
}

