#include "evas_object_wrap.h"

PREFIX value ml_evas_object_smart_callback_add(
        value v_obj, value v_event, value v_func)
{
        CAMLparam3(v_obj, v_event, v_func);
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_func);
        const char* event = String_val(v_event);
        evas_object_smart_callback_add(obj, event, ml_Evas_Smart_Cb, data);
        CAMLreturn(Val_unit);
}

PREFIX value ml_evas_object_size_hint_weight_set(
        value v_obj, value v_x, value v_y)
{
        evas_object_size_hint_weight_set((Evas_Object*) v_obj, Double_val(v_x),
                Double_val(v_y));
        return Val_unit;
}

PREFIX value ml_evas_object_size_hint_align_set(
        value v_obj, value v_x, value v_y)
{
        evas_object_size_hint_align_set((Evas_Object*) v_obj, Double_val(v_x),
                Double_val(v_y));
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
        caml_callback2(v_fun, (value) obj, (value) priv);
        CAMLreturn0;
}

PREFIX value ml_evas_object_size_hint_min_set(value v_obj, value v_w, value v_h)
{
        evas_object_size_hint_min_set((Evas_Object*) v_obj, Int_val(v_w),
                Int_val(v_h));
        return Val_unit;
}

PREFIX void ml_Evas_Object_Event_Cb_mouse_in(
        void* data, Evas* e, Evas_Object *obj, void* event_info)
{
        CAMLparam0();
        CAMLlocal2(v_fun, v_ev);
        value* d = (value*) data;
        v_fun = *d;
        v_ev = copy_Evas_Event_Mouse_In((Evas_Event_Mouse_In*) event_info);
        caml_callback3(v_fun, (value) e, (value) obj, v_ev);
	CAMLreturn0;
}

PREFIX void ml_Evas_Object_Event_Cb_mouse_out(
        void* data, Evas* e, Evas_Object *obj, void* event_info)
{
        CAMLparam0();
        CAMLlocal2(v_fun, v_ev);
        value* d = (value*) data;
        v_fun = *d;
        v_ev = copy_Evas_Event_Mouse_Out((Evas_Event_Mouse_Out*) event_info);
        caml_callback3(v_fun, (value) e, (value) obj, v_ev);
	CAMLreturn0;
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

PREFIX void ml_Evas_Object_Event_Cb_mouse_up(
        void* data, Evas* e, Evas_Object *obj, void* event_info)
{
        CAMLparam0();
        CAMLlocal2(v_fun, v_ev);
        value* d = (value*) data;
        v_fun = *d;
        v_ev = copy_Evas_Event_Mouse_Up((Evas_Event_Mouse_Up*) event_info);
        caml_callback3(v_fun, (value) e, (value) obj, v_ev);
	CAMLreturn0;
}

PREFIX void ml_Evas_Object_Event_Cb_mouse_move(
        void* data, Evas* e, Evas_Object *obj, void* event_info)
{
        CAMLparam0();
        CAMLlocal2(v_fun, v_ev);
        value* d = (value*) data;
        v_fun = *d;
        v_ev = copy_Evas_Event_Mouse_Move((Evas_Event_Mouse_Move*) event_info);
        caml_callback3(v_fun, (value) e, (value) obj, v_ev);
	CAMLreturn0;
}

PREFIX void ml_Evas_Object_Event_Cb_mouse_wheel(
        void* data, Evas* e, Evas_Object *obj, void* event_info)
{
        CAMLparam0();
        CAMLlocal2(v_fun, v_ev);
        value* d = (value*) data;
        v_fun = *d;
        v_ev = copy_Evas_Event_Mouse_Wheel(
                (Evas_Event_Mouse_Wheel*) event_info);
        caml_callback3(v_fun, (value) e, (value) obj, v_ev);
	CAMLreturn0;
}

PREFIX void ml_Evas_Object_Event_Cb_multi_down(
        void* data, Evas* e, Evas_Object *obj, void* event_info)
{
        CAMLparam0();
        CAMLlocal2(v_fun, v_ev);
        value* d = (value*) data;
        v_fun = *d;
        v_ev = copy_Evas_Event_Multi_Down(
                (Evas_Event_Multi_Down*) event_info);
        caml_callback3(v_fun, (value) e, (value) obj, v_ev);
	CAMLreturn0;
}

PREFIX void ml_Evas_Object_Event_Cb_multi_up(
        void* data, Evas* e, Evas_Object *obj, void* event_info)
{
        CAMLparam0();
        CAMLlocal2(v_fun, v_ev);
        value* d = (value*) data;
        v_fun = *d;
        v_ev = copy_Evas_Event_Multi_Up(
                (Evas_Event_Multi_Up*) event_info);
        caml_callback3(v_fun, (value) e, (value) obj, v_ev);
	CAMLreturn0;
}

PREFIX void ml_Evas_Object_Event_Cb_multi_move(
        void* data, Evas* e, Evas_Object *obj, void* event_info)
{
        CAMLparam0();
        CAMLlocal2(v_fun, v_ev);
        value* d = (value*) data;
        v_fun = *d;
        v_ev = copy_Evas_Event_Multi_Move(
                (Evas_Event_Multi_Move*) event_info);
        caml_callback3(v_fun, (value) e, (value) obj, v_ev);
	CAMLreturn0;
}

PREFIX void ml_Evas_Object_Event_Cb_unit(
        void* data, Evas* e, Evas_Object *obj, void* event_info)
{
        CAMLparam0();
        CAMLlocal1(v_fun);
        value* d = (value*) data;
        v_fun = *d;
        caml_callback3(v_fun, (value) e, (value) obj, Val_unit);
        ml_remove_value(d);
	CAMLreturn0;
}

PREFIX void ml_Evas_Object_Event_Cb_key_down(
        void* data, Evas* e, Evas_Object* obj, void* event_info)
{
        CAMLparam0();
        CAMLlocal2(v_fun, v_ev);
        value* d = (value*) data;
        v_fun = *d;
        v_ev = copy_Evas_Event_Key_Down((Evas_Event_Key_Down*) event_info);
        caml_callback3(v_fun, (value) e, (value) obj, v_ev);
        CAMLreturn0;
}

PREFIX void ml_Evas_Object_Event_Cb_key_up(
        void* data, Evas* e, Evas_Object* obj, void* event_info)
{
        CAMLparam0();
        CAMLlocal2(v_fun, v_ev);
        value* d = (value*) data;
        v_fun = *d;
        v_ev = copy_Evas_Event_Key_Up((Evas_Event_Key_Up*) event_info);
        caml_callback3(v_fun, (value) e, (value) obj, v_ev);
        CAMLreturn0;
}

PREFIX void ml_Evas_Object_Event_Cb_hold(
        void* data, Evas* e, Evas_Object* obj, void* event_info)
{
        CAMLparam0();
        CAMLlocal2(v_fun, v_ev);
        value* d = (value*) data;
        v_fun = *d;
        v_ev = copy_Evas_Event_Hold((Evas_Event_Hold*) event_info);
        caml_callback3(v_fun, (value) e, (value) obj, v_ev);
        CAMLreturn0;
}

PREFIX value ml_evas_object_event_callback_add_mouse_in(
        value v_obj, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_func);
        evas_object_event_callback_add(obj, EVAS_CALLBACK_MOUSE_IN,
                ml_Evas_Object_Event_Cb_mouse_in, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_add_mouse_out(
        value v_obj, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_func);
        evas_object_event_callback_add(obj, EVAS_CALLBACK_MOUSE_OUT,
                ml_Evas_Object_Event_Cb_mouse_out, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_add_mouse_down(
        value v_obj, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_func);
        evas_object_event_callback_add(obj, EVAS_CALLBACK_MOUSE_DOWN,
                ml_Evas_Object_Event_Cb_mouse_down, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_add_mouse_up(
        value v_obj, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_func);
        evas_object_event_callback_add(obj, EVAS_CALLBACK_MOUSE_UP,
                ml_Evas_Object_Event_Cb_mouse_up, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_add_mouse_move(
        value v_obj, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_func);
        evas_object_event_callback_add(obj, EVAS_CALLBACK_MOUSE_MOVE,
                ml_Evas_Object_Event_Cb_mouse_move, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_add_mouse_wheel(
        value v_obj, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_func);
        evas_object_event_callback_add(obj, EVAS_CALLBACK_MOUSE_WHEEL,
                ml_Evas_Object_Event_Cb_mouse_wheel, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_add_multi_down(
        value v_obj, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_func);
        evas_object_event_callback_add(obj, EVAS_CALLBACK_MULTI_DOWN,
                ml_Evas_Object_Event_Cb_multi_down, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_add_multi_up(
        value v_obj, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_func);
        evas_object_event_callback_add(obj, EVAS_CALLBACK_MULTI_UP,
                ml_Evas_Object_Event_Cb_multi_up, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_add_multi_move(
        value v_obj, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_func);
        evas_object_event_callback_add(obj, EVAS_CALLBACK_MULTI_MOVE,
                ml_Evas_Object_Event_Cb_multi_move, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_add_free(value v_obj, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_register_value(v_func);
        evas_object_event_callback_add(obj, EVAS_CALLBACK_FREE,
                ml_Evas_Object_Event_Cb_unit, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_add_key_down(
        value v_obj, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_func);
        evas_object_event_callback_add(obj, EVAS_CALLBACK_KEY_DOWN,
                ml_Evas_Object_Event_Cb_key_down, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_add_key_up(
        value v_obj, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_func);
        evas_object_event_callback_add(obj, EVAS_CALLBACK_KEY_UP,
                ml_Evas_Object_Event_Cb_key_up, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_add_focus_in(
        value v_obj, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_register_value(v_func);
        evas_object_event_callback_add(obj, EVAS_CALLBACK_FOCUS_IN,
                ml_Evas_Object_Event_Cb_unit, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_add_focus_out(
        value v_obj, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_register_value(v_func);
        evas_object_event_callback_add(obj, EVAS_CALLBACK_FOCUS_OUT,
                ml_Evas_Object_Event_Cb_unit, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_add_show(value v_obj, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_register_value(v_func);
        evas_object_event_callback_add(obj, EVAS_CALLBACK_SHOW,
                ml_Evas_Object_Event_Cb_unit, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_add_hide(value v_obj, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_register_value(v_func);
        evas_object_event_callback_add(obj, EVAS_CALLBACK_HIDE,
                ml_Evas_Object_Event_Cb_unit, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_add_move(value v_obj, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_register_value(v_func);
        evas_object_event_callback_add(obj, EVAS_CALLBACK_MOVE,
                ml_Evas_Object_Event_Cb_unit, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_add_resize(value v_obj, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_register_value(v_func);
        evas_object_event_callback_add(obj, EVAS_CALLBACK_RESIZE,
                ml_Evas_Object_Event_Cb_unit, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_add_restack(
        value v_obj, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_register_value(v_func);
        evas_object_event_callback_add(obj, EVAS_CALLBACK_RESTACK,
                ml_Evas_Object_Event_Cb_unit, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_add_del(value v_obj, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_register_value(v_func);
        evas_object_event_callback_add(obj, EVAS_CALLBACK_DEL,
                ml_Evas_Object_Event_Cb_unit, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_add_hold(
        value v_obj, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_func);
        evas_object_event_callback_add(obj, EVAS_CALLBACK_HOLD,
                ml_Evas_Object_Event_Cb_hold, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_add_changed_size_hints(
        value v_obj, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_register_value(v_func);
        evas_object_event_callback_add(obj, EVAS_CALLBACK_CHANGED_SIZE_HINTS,
                ml_Evas_Object_Event_Cb_unit, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_add_image_preloaded(
        value v_obj, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_register_value(v_func);
        evas_object_event_callback_add(obj, EVAS_CALLBACK_IMAGE_PRELOADED,
                ml_Evas_Object_Event_Cb_unit, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_add_image_unloaded(
        value v_obj, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_register_value(v_func);
        evas_object_event_callback_add(obj, EVAS_CALLBACK_IMAGE_UNLOADED,
                ml_Evas_Object_Event_Cb_unit, data);
        return Val_unit;
}

PREFIX value ml_evas_object_size_hint_aspect_set(
        value v_obj, value v_aspect, value v_w, value v_h)
{
        evas_object_size_hint_aspect_set((Evas_Object*) v_obj,
                Evas_Aspect_Control_val(v_aspect), Int_val(v_w), Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_evas_object_box_layout_flow_horizontal(
        value v_obj, value v_priv)
{
        evas_object_box_layout_flow_horizontal((Evas_Object*) v_obj,
                (Evas_Object_Box_Data*) v_priv, NULL);
        return Val_unit;
}

PREFIX value ml_evas_object_box_layout_horizontal(
        value v_obj, value v_priv)
{
        evas_object_box_layout_horizontal((Evas_Object*) v_obj,
                (Evas_Object_Box_Data*) v_priv, NULL);
        return Val_unit;
}

PREFIX value ml_evas_object_box_layout_vertical(
        value v_obj, value v_priv)
{
        evas_object_box_layout_vertical((Evas_Object*) v_obj,
                (Evas_Object_Box_Data*) v_priv, NULL);
        return Val_unit;
}

PREFIX value ml_evas_object_box_layout_homogeneous_vertical(
        value v_obj, value v_priv)
{
        evas_object_box_layout_homogeneous_vertical((Evas_Object*) v_obj,
                (Evas_Object_Box_Data*) v_priv, NULL);
        return Val_unit;
}

PREFIX value ml_evas_object_box_layout_homogeneous_horizontal(
        value v_obj, value v_priv)
{
        evas_object_box_layout_homogeneous_horizontal((Evas_Object*) v_obj,
                (Evas_Object_Box_Data*) v_priv, NULL);
        return Val_unit;
}

PREFIX value ml_evas_object_box_layout_flow_vertical(
        value v_obj, value v_priv)
{
        evas_object_box_layout_flow_vertical((Evas_Object*) v_obj,
                (Evas_Object_Box_Data*) v_priv, NULL);
        return Val_unit;
}

PREFIX value ml_evas_object_box_layout_stack(
        value v_obj, value v_priv)
{
        evas_object_box_layout_stack((Evas_Object*) v_obj,
                (Evas_Object_Box_Data*) v_priv, NULL);
        return Val_unit;
}

void ml_Evas_Object_Event_Cb_on_del(
        void* data, Evas* e, Evas_Object* obj, void* event_info)
{
        value* v_fun = (value*) data;
        ml_remove_value(v_fun);
}

PREFIX inline value* ml_Evas_Object_register_value(Evas_Object* obj, value v)
{
        value* data = ml_register_value(v);
        evas_object_event_callback_add(obj, EVAS_CALLBACK_FREE,
                ml_Evas_Object_Event_Cb_on_del, data);
        return data;
}

PREFIX inline void ml_Evas_Object_gc_value(Evas_Object* obj, value* data)
{
        evas_object_event_callback_add(obj, EVAS_CALLBACK_FREE,
                ml_Evas_Object_Event_Cb_on_del, data);
}

/* Basic Object Manipulation */

PREFIX value ml_evas_object_clip_set(value v_obj, value v_clip)
{
        evas_object_clip_set((Evas_Object*) v_obj, (Evas_Object*) v_clip);
        return Val_unit;
}

PREFIX value ml_evas_object_ref(value v_obj)
{
        evas_object_ref((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_evas_object_unref(value v_obj)
{
        evas_object_unref((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_evas_object_ref_get(value v_obj)
{
        return Val_int(evas_object_ref_get((Evas_Object*) v_obj));
}

PREFIX value ml_evas_object_del(value v_obj)
{
        evas_object_del((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_evas_object_move(value v_obj, value v_x, value v_y)
{
        evas_object_move((Evas_Object*) v_obj, Int_val(v_x), Int_val(v_y));
        return Val_unit;
}

PREFIX value ml_evas_object_resize(value v_obj, value v_x, value v_y)
{
        evas_object_resize((Evas_Object*) v_obj, Int_val(v_x), Int_val(v_y));
        return Val_unit;
}

PREFIX value ml_evas_object_geometry_get(value v_obj)
{
        Evas_Coord x, y, w, h;
        evas_object_geometry_get((Evas_Object*) v_obj, &x, &y, &w, &h);
        value v = caml_alloc(4, 0);
        Store_field(v, 0, Val_int(x));
        Store_field(v, 1, Val_int(y));
        Store_field(v, 2, Val_int(w));
        Store_field(v, 3, Val_int(h));
        return v;
}

PREFIX value ml_evas_object_geometry_set(
        value v_obj, value v_x, value v_y, value v_w, value v_h)
{
        evas_object_geometry_set((Evas_Object*) v_obj, Int_val(v_x),
                Int_val(v_y), Int_val(v_w), Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_evas_object_show(value v_obj)
{
        evas_object_show((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_evas_object_hide(value v_obj)
{
        evas_object_hide((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_evas_object_visible_get(value v_obj)
{
        return Val_Eina_Bool(evas_object_visible_get((Evas_Object*) v_obj));
}

PREFIX value ml_evas_object_color_set(
        value v_obj, value v_r, value v_g, value v_b, value v_a)
{
        evas_object_color_set((Evas_Object*) v_obj, Int_val(v_r), Int_val(v_g),
                Int_val(v_b), Int_val(v_a));
        return Val_unit;
}

PREFIX value ml_evas_object_color_get(value v_obj)
{
        int r, g, b, a;
        evas_object_color_get((Evas_Object*) v_obj, &r, &g, &b, &a);
        value v_r = caml_alloc(4, 0);
        Store_field(v_r, 0, Val_int(r));
        Store_field(v_r, 1, Val_int(g));
        Store_field(v_r, 2, Val_int(b));
        Store_field(v_r, 3, Val_int(a));
        return v_r;
}

PREFIX value ml_evas_object_evas_get(value v_obj)
{
        return (value) evas_object_evas_get((Evas_Object*) v_obj);
}

PREFIX value ml_evas_object_clip_get(value v_obj)
{
        return copy_Evas_Object_opt(evas_object_clip_get((Evas_Object*) v_obj));
}

PREFIX value ml_evas_object_clip_unset(value v_obj)
{
        evas_object_clip_unset((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_evas_object_clipees_get(value v_obj)
{
        return copy_Eina_List_Evas_Object(evas_object_clipees_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_evas_object_clipees_has(value v_obj)
{
        return Val_bool(evas_object_clipees_has((Evas_Object*) v_obj));
}

PREFIX value ml_evas_object_focus_set(value v_obj, value v_flag)
{
        evas_object_focus_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_evas_object_focus_get(value v_obj)
{
        return Val_bool(evas_object_focus_get((Evas_Object*) v_obj));
}

PREFIX value ml_evas_object_layer_set(value v_obj, value v_l)
{
        evas_object_layer_set((Evas_Object*) v_obj, Int_val(v_l));
        return Val_unit;
}

PREFIX value ml_evas_object_layer_get(value v_obj)
{
        return Val_int(evas_object_layer_get((Evas_Object*) v_obj));
}

PREFIX value ml_evas_object_name_set(value v_obj, value v_s)
{
        evas_object_name_set((Evas_Object*) v_obj, String_val(v_s));
        return Val_unit;
}

PREFIX value ml_evas_object_name_get(value v_obj)
{
        return copy_string(evas_object_name_get((Evas_Object*) v_obj));
}

PREFIX value ml_evas_object_type_get(value v_obj)
{
        return copy_string(evas_object_type_get((Evas_Object*) v_obj));
}

PREFIX value ml_evas_object_raise(value v_obj)
{
        evas_object_raise((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_evas_object_lower(value v_obj)
{
        evas_object_lower((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_evas_object_stack_above(value v_obj, value v_above)
{
        evas_object_stack_above((Evas_Object*) v_obj, (Evas_Object*) v_above);
        return Val_unit;
}

PREFIX value ml_evas_object_stack_below(value v_obj, value v_below)
{
        evas_object_stack_below((Evas_Object*) v_obj, (Evas_Object*) v_below);
        return Val_unit;
}

PREFIX value ml_evas_object_above_get(value v_obj)
{
        return copy_Evas_Object_opt(evas_object_above_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_evas_object_below_get(value v_obj)
{
        return copy_Evas_Object_opt(evas_object_below_get(
                (Evas_Object*) v_obj));
}

