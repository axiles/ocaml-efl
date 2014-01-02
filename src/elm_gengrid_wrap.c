#include "include.h"

PREFIX void ml_Elm_Gengrid_Item_Class(
        Elm_Gen_Item_Class** class, void** data, value v)
{
        Elm_Gen_Item_Class* c = elm_gengrid_item_class_new();
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

/*PREFIX inline Elm_Gengrid_Item_Type Elm_Gengrid_Item_Type_val(value v)
{
        switch(v) {
                case Val_none: return ELM_GENGRID_ITEM_NONE;
                case Val_tree: return ELM_GENGRID_ITEM_TREE;
                case Val_group: return ELM_GENGRID_ITEM_GROUP;
        }
        caml_failwith("Elm_Gengrid_Item_Type_val");
        return ELM_GENGRID_ITEM_NONE;
}

PREFIX inline value Val_Elm_Gengrid_Item_Type(Elm_Gengrid_Item_Type t)
{
        switch(t) {
                case ELM_GENGRID_ITEM_NONE: return Val_none;
                case ELM_GENGRID_ITEM_TREE: return Val_tree;
                case ELM_GENGRID_ITEM_GROUP: return Val_group;
                default: break;
        }
        caml_failwith("Val_Elm_Gengrid_Item_Type_val");
        return Val_none;
}*/

PREFIX inline Elm_Gengrid_Item_Scrollto_Type
Elm_Gengrid_Item_Scrollto_Type_val(value v)
{
        switch(v) {
                case Val_none: return ELM_GENGRID_ITEM_SCROLLTO_NONE;
                case Val_in: return ELM_GENGRID_ITEM_SCROLLTO_IN;
                case Val_top: return ELM_GENGRID_ITEM_SCROLLTO_TOP;
                case Val_middle: return ELM_GENGRID_ITEM_SCROLLTO_MIDDLE;
        }
        caml_failwith("Elm_Gengrid_Item_Scrollto_Type_val");
        return ELM_GENGRID_ITEM_SCROLLTO_NONE;
}

PREFIX value ml_elm_gengrid_add(value v_parent)
{
        Evas_Object* obj = elm_gengrid_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_gengrid_add");
        return (value) obj;
}

PREFIX value ml_elm_gengrid_clear(value v_obj)
{
        elm_gengrid_clear((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_gengrid_multi_select_set(value v_obj, value v_flag)
{
        elm_gengrid_multi_select_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_gengrid_multi_select_get(value v_obj)
{
        return Val_Eina_Bool(elm_gengrid_multi_select_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_gengrid_horizontal_set(value v_obj, value v_flag)
{
        elm_gengrid_horizontal_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_gengrid_horizontal_get(value v_obj)
{
        return Val_bool(elm_gengrid_horizontal_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_gengrid_item_append(
        value v_obj, value v_class, value v_func)
{
        Elm_Gengrid_Item_Class* class;
        void* data;
        ml_Elm_Gengrid_Item_Class(&class, &data, v_class);

        value* data_func = caml_stat_alloc(sizeof(value));
        *data_func = v_func;
        caml_register_global_root(data_func);

        Elm_Object_Item* item = elm_gengrid_item_append((Evas_Object*) v_obj,
                class, data, ml_Evas_Smart_Cb, data_func);
        elm_gengrid_item_class_free(class);

        if(item == NULL) caml_failwith("elm_gengrid_item_append");
        return (value) item;
}

PREFIX value ml_elm_gengrid_item_prepend(
        value v_obj, value v_class, value v_func)
{
        Elm_Gengrid_Item_Class* class;
        void* data;
        ml_Elm_Gengrid_Item_Class(&class, &data, v_class);

        value* data_func = caml_stat_alloc(sizeof(value));
        *data_func = v_func;
        caml_register_global_root(data_func);

        Elm_Object_Item* item = elm_gengrid_item_prepend((Evas_Object*) v_obj,
                class, data, ml_Evas_Smart_Cb, data_func);
        elm_gengrid_item_class_free(class);

        if(item == NULL) caml_failwith("elm_gengrid_item_prepend");
        return (value) item;
}

PREFIX value ml_elm_gengrid_item_insert_before(
        value v_obj, value v_class, value v_rel, value v_func)
{
        Elm_Gengrid_Item_Class* class;
        void* data;
        ml_Elm_Gengrid_Item_Class(&class, &data, v_class);

        value* data_func = caml_stat_alloc(sizeof(value));
        *data_func = v_func;
        caml_register_global_root(data_func);

        Elm_Object_Item* item = elm_gengrid_item_insert_before(
                (Evas_Object*) v_obj, class, data, (Elm_Object_Item*) v_rel,
                ml_Evas_Smart_Cb, data_func);
        elm_gengrid_item_class_free(class);

        if(item == NULL) caml_failwith("elm_gengrid_item_insert_before");
        return (value) item;
}

PREFIX value ml_elm_gengrid_item_insert_after(
        value v_obj, value v_class, value v_rel, value v_func)
{
        Elm_Gengrid_Item_Class* class;
        void* data;
        ml_Elm_Gengrid_Item_Class(&class, &data, v_class);

        value* data_func = caml_stat_alloc(sizeof(value));
        *data_func = v_func;
        caml_register_global_root(data_func);

        Elm_Object_Item* item = elm_gengrid_item_insert_after(
                (Evas_Object*) v_obj, class, data, (Elm_Object_Item*) v_rel,
                ml_Evas_Smart_Cb, data_func);
        elm_gengrid_item_class_free(class);

        if(item == NULL) caml_failwith("elm_gengrid_item_insert_after");
        return (value) item;
}

PREFIX value ml_elm_gengrid_selected_item_get(value v_obj)
{
        Elm_Object_Item* item = elm_gengrid_selected_item_get(
                (Evas_Object*) v_obj);
        if(item == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) item);
        return v;
}

PREFIX value ml_elm_gengrid_selected_items_get(value v_obj)
{
        return copy_Eina_List_Elm_Object_Item(elm_gengrid_selected_items_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_gengrid_realized_items_get(value v_obj)
{
        Eina_List* list = elm_gengrid_realized_items_get((Evas_Object*) v_obj);
        value v = copy_Eina_List_Elm_Object_Item(list);
        eina_list_free(list);
        return v;
}

PREFIX value ml_elm_gengrid_first_item_get(value v_obj)
{
        Elm_Object_Item* item = elm_gengrid_first_item_get(
                (Evas_Object*) v_obj);
        if(item == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) item);
        return v;
}

PREFIX value ml_elm_gengrid_last_item_get(value v_obj)
{
        Elm_Object_Item* item = elm_gengrid_last_item_get(
                (Evas_Object*) v_obj);
        if(item == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) item);
        return v;
}

PREFIX value ml_elm_gengrid_item_next_get(value v_it)
{
        Elm_Object_Item* next = elm_gengrid_item_next_get(
                (Elm_Object_Item*) v_it);
        if(next == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) next);
        return v;
}

PREFIX value ml_elm_gengrid_item_prev_get(value v_it)
{
        Elm_Object_Item* prev = elm_gengrid_item_prev_get(
                (Elm_Object_Item*) v_it);
        if(prev == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) prev);
        return v;
}

PREFIX value ml_elm_gengrid_item_selected_set(value v_it, value v_flag)
{
        elm_gengrid_item_selected_set((Elm_Object_Item*) v_it,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_gengrid_item_selected_get(value v_it)
{
        return Val_Eina_Bool(elm_gengrid_item_selected_get(
                (Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_gengrid_item_show(value v_it, value v_type)
{
        elm_gengrid_item_show((Elm_Object_Item*) v_it,
                Elm_Gengrid_Item_Scrollto_Type_val(v_type));
        return Val_unit;
}

PREFIX value ml_elm_gengrid_item_bring_in(value v_it, value v_type)
{
        elm_gengrid_item_bring_in((Elm_Object_Item*) v_it,
                Elm_Gengrid_Item_Scrollto_Type_val(v_type));
        return Val_unit;
}

PREFIX value ml_elm_gengrid_item_update(value v_it)
{
        elm_gengrid_item_update((Elm_Object_Item*) v_it);
        return Val_unit;
}

PREFIX value ml_elm_gengrid_item_index_get(value v_it)
{
        return Val_int(elm_gengrid_item_index_get((Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_gengrid_item_size_set(value v_obj, value v_w, value v_h)
{
        elm_gengrid_item_size_set((Evas_Object*) v_obj, Int_val(v_w),
                Int_val(v_h));
        return Val_unit;
}
