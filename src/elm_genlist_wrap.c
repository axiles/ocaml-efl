#include "include.h"

PREFIX void ml_Elm_Genlist_Item_Class(
        Elm_Gen_Item_Class** class, void** data, value v)
{
        Elm_Gen_Item_Class* c = elm_genlist_item_class_new();
        if(c == NULL) caml_raise_out_of_memory();

        c->item_style = String_val(Field(v, 0));
        c->func.text_get = ml_Elm_Gen_Item_Text_Get_Cb;
        c->func.content_get = ml_Elm_Gen_Item_Content_Get_Cb;
        c->func.state_get = ml_Elm_Gen_Item_State_Get_Cb;
        c->func.del = ml_Elm_Gen_Item_Del_Cb;

        value* v_data = caml_stat_alloc(sizeof(value));
        *v_data = v;
        caml_register_global_root(v_data);

        *class = c;
        *data = v_data;
}

PREFIX inline Elm_Genlist_Item_Type Elm_Genlist_Item_Type_val(value v)
{
        switch(v) {
                case Val_none: return ELM_GENLIST_ITEM_NONE;
                case Val_tree: return ELM_GENLIST_ITEM_TREE;
                case Val_group: return ELM_GENLIST_ITEM_GROUP;
        }
        caml_failwith("Elm_Genlist_Item_Type_val");
        return ELM_GENLIST_ITEM_NONE;
}

PREFIX value ml_elm_genlist_add(value v_parent)
{
        Evas_Object* obj = elm_genlist_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_genlist_add");
        return (value) obj;
}

PREFIX value ml_elm_genlist_clear(value v_obj)
{
        elm_genlist_clear((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_genlist_multi_select_set(value v_obj, value v_flag)
{
        elm_genlist_multi_select_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_genlist_multi_select_get(value v_obj)
{
        return Val_Eina_Bool(elm_genlist_multi_select_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_genlist_mode_set(value v_obj, value v_mode)
{
        elm_genlist_mode_set((Evas_Object*) v_obj, Elm_List_Mode_val(v_mode));
        return Val_unit;
}

PREFIX value ml_elm_genlist_mode_get(value v_obj)
{
        return Val_Elm_List_Mode(elm_genlist_mode_get((Evas_Object*) v_obj));
}

