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

PREFIX void ml_Evas_Object_Box_Layout_0(
        Evas_Object* obj, Evas_Object_Box_Data* priv, void* user_data)
{
        CAMLparam0();
        CAMLlocal1(v_fun);
        value* v_user_data = (value*) user_data;
        v_fun = Field(*v_user_data, 0);
        caml_callback(v_fun, (value) priv);
        CAMLreturn0;
}

PREFIX value ml_evas_object_size_hint_min_set(value v_obj, value v_w, value v_h)
{
        evas_object_size_hint_min_set((Evas_Object*) v_obj, Int_val(v_w),
                Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_string_of_ptr(value v_ptr)
{
        const char* ptr = (const char*) v_ptr;
        if(ptr == NULL) caml_failwith("string_of_ptr");
        return copy_string(ptr);
}

PREFIX value ml_string_opt_of_ptr(value v_ptr)
{
        CAMLparam0();
        CAMLlocal1(v);
        const char* ptr = (const char*) v_ptr;
        if(ptr == NULL) v = Val_int(0);
        else {
                v = caml_alloc(1, 0);
                Store_field(v, 0, copy_string(ptr));
        }
        CAMLreturn(v);
}

PREFIX inline value copy_Evas_Event_Mouse_Down(Evas_Event_Mouse_Down* ev)
{
        value v = caml_alloc(8, 0);
        Store_field(v, 0, Val_int(ev->button));
        Store_field(v, 1, Val_int(ev->output.x));
        Store_field(v, 2, Val_int(ev->output.y));
        Store_field(v, 3, Val_int(ev->canvas.x));
        Store_field(v, 4, Val_int(ev->canvas.y));
        Store_field(v, 5, (value) ev->modifiers);
        Store_field(v, 6, Val_bool(ev->flags & EVAS_BUTTON_DOUBLE_CLICK));
        Store_field(v, 7, Val_bool(ev->flags & EVAS_BUTTON_TRIPLE_CLICK));
        return v;
}

PREFIX void ml_Evas_Object_Event_Cb_mouse_down(
        void* data, Evas* e, Evas_Object *obj, void* event_info)
{
        CAMLparam0();
        CAMLlocal2(v_fun, v_ev);
        value* d = (value*) data;
        v_fun = *d;
        v_ev = copy_Evas_Event_Mouse_Down((Evas_Event_Mouse_Down*) event_info);
        caml_callback3(v_fun, (value) e, (value) obj, v_ev);
	CAMLreturn0;
}

PREFIX value ml_evas_object_event_callback_add_mouse_down(
        value v_obj, value v_func)
{
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_func;
        caml_register_global_root(data);
        evas_object_event_callback_add((Evas_Object*) v_obj,
                EVAS_CALLBACK_MOUSE_DOWN, ml_Evas_Object_Event_Cb_mouse_down,
                data);
        return Val_unit;
}

PREFIX value ml_evas_object_visible_get(value v_obj)
{
        return Val_Eina_Bool(evas_object_visible_get((Evas_Object*) v_obj));
}

