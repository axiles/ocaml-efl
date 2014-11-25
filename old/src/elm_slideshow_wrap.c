#include "include.h"

Evas_Object* ml_SlideshowItemGetFunc_0(void* data, Evas_Object* obj)
{
        CAMLparam0();
        CAMLlocal2(v_fun, v_content);
        value* v_itc = (value*) data;
        v_fun = Field(*v_itc, 0);
        v_content = caml_callback(v_fun, (value) obj);
        Evas_Object* content = Evas_Object_opt_val(v_content);
        CAMLreturnT(Evas_Object*, content);
}

void ml_SlideshowItemDelFunc_1_free(void* data, Evas_Object* obj)
{
        CAMLparam0();
        CAMLlocal1(v_fun);
        value* v_itc = (value*) data;
        v_fun = Field(*v_itc, 1);
        caml_callback(v_fun, (value) obj);
        ml_remove_value(v_itc);
        CAMLreturn0;
}

inline void ml_Elm_Slideshow_Item_Class(
        Elm_Slideshow_Item_Class* itc, void** data, value v_itc)
{
        value* v_data = ml_register_value(v_itc);
        itc->func.get = ml_SlideshowItemGetFunc_0;
        itc->func.del = ml_SlideshowItemDelFunc_1_free;
        *data = v_data;
}

PREFIX value ml_elm_slideshow_add(value v_parent)
{
        Evas_Object* slideshow = elm_slideshow_add((Evas_Object*) v_parent);
        if(slideshow == NULL) caml_failwith("elm_slideshow_add");
        return (value) slideshow;
}

PREFIX value ml_elm_slideshow_item_add(value v_obj, value v_itc)
{
        Elm_Slideshow_Item_Class itc;
        void* data;
        ml_Elm_Slideshow_Item_Class(&itc, &data, v_itc);
        Elm_Object_Item* it = elm_slideshow_item_add((Evas_Object*) v_obj, &itc,
                data);
        if(it == NULL) caml_failwith("elm_slideshow_item_add");
        return (value) it;
}

PREFIX value ml_elm_slideshow_transitions_get(value v_obj)
{
        return copy_Eina_List_string(elm_slideshow_transitions_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_slideshow_items_get(value v_obj)
{
        return copy_Eina_List_Elm_Object_Item(elm_slideshow_items_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_slideshow_item_current_get(value v_obj)
{
        return copy_Elm_Object_Item_opt(elm_slideshow_item_current_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_slideshow_item_object_get(value v_it)
{
        return copy_Evas_Object_opt(elm_slideshow_item_object_get(
                (Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_slideshow_item_nth_get(value v_obj, value v_i)
{
        return copy_Elm_Object_Item_opt(elm_slideshow_item_nth_get(
                (Evas_Object*) v_obj, Int_val(v_i)));
}

PREFIX value ml_elm_slideshow_layouts_get(value v_obj)
{
        return copy_Eina_List_string(elm_slideshow_layouts_get(
                (Evas_Object*) v_obj));
}

