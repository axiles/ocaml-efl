#include "include.h"

PREFIX inline Elm_List_Mode Elm_List_Mode_val(value v_m)
{
        switch(v_m) {
                case Val_compress: return ELM_LIST_COMPRESS;
                case Val_scroll: return ELM_LIST_SCROLL;
                case Val_limit: return ELM_LIST_LIMIT;
                case Val_expand: return ELM_LIST_EXPAND;
                case Val_last: return ELM_LIST_LAST;
        }
        caml_failwith("Elm_List_Mode_val");
        return ELM_LIST_COMPRESS;
}

PREFIX inline value Val_Elm_List_Mode(Elm_List_Mode m)
{
        switch(m) {
                case ELM_LIST_COMPRESS: return Val_compress;
                case ELM_LIST_SCROLL: return Val_scroll;
                case ELM_LIST_LIMIT: return Val_limit;
                case ELM_LIST_EXPAND: return Val_expand;
                case ELM_LIST_LAST: return Val_last;
        }
        caml_failwith("Val_Elm_List_Mode");
        return Val_compress;
}

PREFIX value ml_elm_list_add(value v_parent)
{
        Evas_Object* obj = elm_list_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_list_add");
        return (value) obj;
}

PREFIX value ml_elm_list_go(value v_obj)
{
        elm_list_go((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_list_multi_select_set(value v_obj, value v_flag)
{
        elm_list_multi_select_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_list_multi_select_get(value v_obj)
{
        return Val_Eina_Bool(elm_list_multi_select_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_list_mode_set(value v_obj, value v_mode)
{
        elm_list_mode_set((Evas_Object*) v_obj, Elm_List_Mode_val(v_mode));
        return Val_unit;
}

PREFIX value ml_elm_list_mode_get(value v_obj)
{
        return Val_Elm_List_Mode(elm_list_mode_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_list_horizontal_set(value v_obj, value v_flag)
{
        elm_list_horizontal_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_list_horizontal_get(value v_obj)
{
        return Val_Eina_Bool(elm_list_horizontal_get((Evas_Object*) v_obj));
}

