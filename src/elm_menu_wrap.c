#include "include.h"

PREFIX value ml_elm_menu_add(value v_parent)
{
        Evas_Object* obj = elm_menu_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_menu_add");
        return (value) obj;
}

PREFIX value ml_elm_menu_parent_set(value v_obj, value v_parent)
{
        elm_menu_parent_set((Evas_Object*) v_obj, (Evas_Object*) v_parent);
        return Val_unit;
}

PREFIX value ml_elm_menu_parent_get(value v_obj)
{
        return (value) elm_menu_parent_get((Evas_Object*) v_obj);
}

PREFIX value ml_elm_menu_move(value v_obj, value v_x, value v_y)
{
        elm_menu_move((Evas_Object*) v_obj, Int_val(v_x), Int_val(v_y));
        return Val_unit;
}

PREFIX value ml_elm_menu_close(value v_obj)
{
        elm_menu_close((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_menu_items_get(value v_obj)
{
        return copy_Eina_List_Elm_Object_Item(elm_menu_items_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_menu_item_object_get(value v_item)
{
        return (value) elm_menu_item_object_get((Elm_Object_Item*) v_item);
}

