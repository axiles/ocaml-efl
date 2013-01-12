#include "include.h"

PREFIX void ml_Evas_Smart_Cb(void *data, Evas_Object *obj, void *event_info)
{
        value *v_fun = (value*) data;
        caml_callback2(*v_fun, (value) obj, (value) event_info);
}

PREFIX value ml_evas_object_smart_callback_add(
        value v_obj, value v_event, value v_func)
{
        CAMLparam3(v_obj, v_event, v_func);
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_func;
        caml_register_global_root(data);
        const char* event = String_val(v_event);
        evas_object_smart_callback_add((Evas_Object*) v_obj, event,
	ml_Evas_Smart_Cb, data);
        CAMLreturn(Val_unit);
}

PREFIX value ml_evas_object_show(value v_obj)
{
        evas_object_show((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_evas_object_size_hint_weight_set(value v_obj, value v_x, value v_y)
{
        evas_object_size_hint_weight_set((Evas_Object*) v_obj, Double_val(v_x),
                Double_val(v_y));
        return Val_unit;
}

PREFIX value ml_evas_object_size_hint_align_set(value v_obj, value v_x, value v_y)
{
        evas_object_size_hint_align_set((Evas_Object*) v_obj, Double_val(v_x),
                Double_val(v_y));
        return Val_unit;
}

PREFIX value ml_evas_object_resize(value v_obj, value v_x, value v_y)
{
        evas_object_resize((Evas_Object*) v_obj, Int_val(v_x), Int_val(v_y));
        return Val_unit;
}

PREFIX value ml_evas_object_move(value v_obj, value v_x, value v_y)
{
        evas_object_move((Evas_Object*) v_obj, Int_val(v_x), Int_val(v_y));
        return Val_unit;
}

PREFIX value ml_evas_object_size_hint_align_get(value v_obj)
{
        CAMLparam0();
        CAMLlocal1(v);
        double x, y;
        evas_object_size_hint_align_get((Evas_Object*) v_obj, &x, &y);
        v = caml_alloc(2, 0);
        Store_field(v, 0, copy_double(x));
        Store_field(v, 1, copy_double(y));
        CAMLreturn(v);
}

PREFIX value ml_evas_object_hide(value v_obj)
{
        evas_object_hide((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_evas_object_color_set(
        value v_obj, value v_r, value v_g, value v_b, value v_a)
{
        evas_object_color_set((Evas_Object*) v_obj, Int_val(v_r), Int_val(v_g),
                Int_val(v_b), Int_val(v_a));
        return Val_unit;
}

PREFIX value ml_evas_object_del(value v_obj)
{
        evas_object_del((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_evas_object_evas_get(value v_obj)
{
        return (value) evas_object_evas_get((Evas_Object*) v_obj);
}

PREFIX value ml_evas_object_rectangle_add(value v_e)
{
        return (value) evas_object_rectangle_add((Evas*) v_e);
}

