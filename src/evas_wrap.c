#include "include.h"

PREFIX inline value copy_Evas_Point(Evas_Point p)
{
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_int(p.x));
        Store_field(v, 1, Val_int(p.y));
        return v;
}

PREFIX inline value copy_Evas_Coord_Point(Evas_Coord_Point p)
{
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_int(p.x));
        Store_field(v, 1, Val_int(p.y));
        return v;
}

PREFIX inline value copy_Evas_Position(Evas_Position p)
{
        CAMLparam0();
        CAMLlocal1(v);
        v = caml_alloc(2, 0);
        Store_field(v, 0, copy_Evas_Point(p.output));
        Store_field(v, 1, copy_Evas_Coord_Point(p.canvas));
        CAMLreturn(v);
}

PREFIX inline value Val_Evas_Event_Flags(Evas_Event_Flags f)
{
        switch(f) {
                case EVAS_EVENT_FLAG_NONE: return Val_none;
                case EVAS_EVENT_FLAG_ON_HOLD: return Val_on_hold;
                case EVAS_EVENT_FLAG_ON_SCROLL: return Val_on_scroll;
        }
        caml_failwith("Val_Evas_Event_Flag");
        return Val_none;
}

PREFIX inline value Val_Evas_Button_Flags(Evas_Button_Flags f)
{
        switch(f) {
                case EVAS_BUTTON_NONE: return Val_none;
                case EVAS_BUTTON_DOUBLE_CLICK: return Val_double_click;
                case EVAS_BUTTON_TRIPLE_CLICK: return Val_triple_click;
        }
        caml_failwith("Val_Evas_Button_Flag");
        return Val_none;
}

PREFIX void ml_Evas_Smart_Cb(void *data, Evas_Object *obj, void *event_info)
{
      
        value *v_fun = (value*) data;
        caml_callback2(*v_fun, (value) obj, (value) event_info);
      
}

PREFIX void ml_Evas_Smart_Cb_1_free(
        void *data, Evas_Object *obj, void *event_info)
{
      
        value* v_data = (value*) data;
        value v_fun = Field(*v_data, 1);
        caml_callback2(v_fun, (value) obj, (value) event_info);
        ml_remove_value(v_data); 
}

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

PREFIX value ml_evas_object_show(value v_obj)
{
        evas_object_show((Evas_Object*) v_obj);
        return Val_unit;
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
        caml_callback2(v_fun, (value) obj, (value) priv);
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

PREFIX value copy_Evas_Event_Mouse_In(Evas_Event_Mouse_In* e)
{
        CAMLparam0();
        CAMLlocal1(v);
        v = caml_alloc(8, 0);
        Store_field(v, 0, Val_int(e->buttons));
        Store_field(v, 1, copy_Evas_Point(e->output));
        Store_field(v, 2, copy_Evas_Coord_Point(e->canvas));
        Store_field(v, 3, (value) e->modifiers);
        Store_field(v, 4, Val_int(e->timestamp));
        Store_field(v, 5, Val_Evas_Event_Flags(e->event_flags));
        Store_field(v, 6, (value) e->dev);
        Store_field(v, 7, (value) e->event_src);
        CAMLreturn(v);
}

PREFIX value copy_Evas_Event_Mouse_Out(Evas_Event_Mouse_Out* e)
{
        CAMLparam0();
        CAMLlocal1(v);
        v = caml_alloc(8, 0);
        Store_field(v, 0, Val_int(e->buttons));
        Store_field(v, 1, copy_Evas_Point(e->output));
        Store_field(v, 2, copy_Evas_Coord_Point(e->canvas));
        Store_field(v, 3, (value) e->modifiers);
        Store_field(v, 4, Val_int(e->timestamp));
        Store_field(v, 5, Val_Evas_Event_Flags(e->event_flags));
        Store_field(v, 6, (value) e->dev);
        Store_field(v, 7, (value) e->event_src);
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

PREFIX inline value copy_Evas_Event_Mouse_Up(Evas_Event_Mouse_Up* ev)
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

PREFIX inline value copy_Evas_Event_Mouse_Move(Evas_Event_Mouse_Move* ev)
{
        CAMLparam0();
        CAMLlocal1(v);
        v = caml_alloc(7, 0);
        Store_field(v, 0, Val_int(ev->buttons));
        Store_field(v, 1, copy_Evas_Position(ev->cur));
        Store_field(v, 2, copy_Evas_Position(ev->prev));
        Store_field(v, 3, (value) ev->modifiers);
        Store_field(v, 4, Val_int(ev->timestamp));
        Store_field(v, 5, (value) ev->dev);
        Store_field(v, 6, (value) ev->event_src);
        CAMLreturn(v);
}

PREFIX inline value copy_Evas_Event_Mouse_Wheel(Evas_Event_Mouse_Wheel* ev)
{
        CAMLparam0();
        CAMLlocal1(v);
        v = caml_alloc(7, 0);
        Store_field(v, 0, Val_int(ev->direction));
        Store_field(v, 1, copy_Evas_Point(ev->output));
        Store_field(v, 2, copy_Evas_Coord_Point(ev->canvas));
        Store_field(v, 3, (value) ev->modifiers);
        Store_field(v, 4, Val_int(ev->timestamp));
        Store_field(v, 5, Val_Evas_Event_Flags(ev->event_flags));
        Store_field(v, 6, (value) ev->dev);
        CAMLreturn(v);
}

PREFIX inline value copy_Evas_Event_Key_Down(Evas_Event_Key_Down* info)
{
        CAMLparam0();
        CAMLlocal1(v);
        v = caml_alloc(6, 0);
        Store_field(v, 0, copy_string(info->keyname));
        Store_field(v, 1, (value) info->modifiers);
        Store_field(v, 2, copy_string(info->key));
        Store_field(v, 3, copy_string(info->string));
        Store_field(v, 4, copy_string(info->compose));
        Store_field(v, 5, Val_int(info->timestamp));
        CAMLreturn(v);
}

PREFIX inline Evas_Aspect_Control Evas_Aspect_Control_val(value v)
{
        switch(v) {
                case Val_none: return EVAS_ASPECT_CONTROL_NONE;
                case Val_neither: return EVAS_ASPECT_CONTROL_NEITHER;
                case Val_horizontal: return EVAS_ASPECT_CONTROL_HORIZONTAL;
                case Val_vertical: return EVAS_ASPECT_CONTROL_VERTICAL;
                case Val_both: return EVAS_ASPECT_CONTROL_BOTH;
        }
        caml_failwith("Evas_Aspect_Control_val");
        return EVAS_ASPECT_CONTROL_NONE;
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

PREFIX void ml_Evas_Object_Event_Cb_free(
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

PREFIX value ml_evas_object_event_callback_add_key_down(
        value v_obj, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_func);
        evas_object_event_callback_add(obj, EVAS_CALLBACK_KEY_DOWN,
                ml_Evas_Object_Event_Cb_key_down, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_add_free(value v_obj, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_register_value(v_func);
        evas_object_event_callback_add(obj, EVAS_CALLBACK_FREE,
                ml_Evas_Object_Event_Cb_free, data);
        return Val_unit;
}

PREFIX value ml_evas_object_visible_get(value v_obj)
{
        return Val_Eina_Bool(evas_object_visible_get((Evas_Object*) v_obj));
}

PREFIX value ml_evas_object_size_hint_aspect_set(
        value v_obj, value v_aspect, value v_w, value v_h)
{
        evas_object_size_hint_aspect_set((Evas_Object*) v_obj,
                Evas_Aspect_Control_val(v_aspect), Int_val(v_w), Int_val(v_h));
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

PREFIX value ml_evas_pointer_canvas_xy_get(value v_e)
{
        Evas_Coord x, y;
        evas_pointer_canvas_xy_get((Evas*) v_e, &x, &y);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(x));
        Store_field(v_r, 1, Val_int(y));
        return v_r;
}

PREFIX inline value copy_Evas_Event_Info(
        Evas_Callback_Type t, void* event_info)
{
        CAMLparam0();
        CAMLlocal1(v);
        switch(t) {
                case EVAS_CALLBACK_MOUSE_IN:
                        v = caml_alloc(2, 0);
                        Store_field(v, 0, Val_mouse_in);
                        Store_field(v, 1, copy_Evas_Event_Mouse_In(
                                (Evas_Event_Mouse_In*) event_info));
                        break;
                case EVAS_CALLBACK_MOUSE_OUT:
                        v = caml_alloc(2, 0);
                        Store_field(v, 0, Val_mouse_out);
                        Store_field(v, 1, copy_Evas_Event_Mouse_Out(
                                (Evas_Event_Mouse_Out*) event_info));
                        break;
                case EVAS_CALLBACK_MOUSE_DOWN:
                        v = caml_alloc(2, 0);
                        Store_field(v, 0, Val_mouse_down);
                        Store_field(v, 1, copy_Evas_Event_Mouse_Down(
                                (Evas_Event_Mouse_Down*) event_info));
                        break;
                case EVAS_CALLBACK_MOUSE_UP:
                        v = caml_alloc(2, 0);
                        Store_field(v, 0, Val_mouse_up);
                        Store_field(v, 1, copy_Evas_Event_Mouse_Up(
                                (Evas_Event_Mouse_Up*) event_info));
                        break;
                case EVAS_CALLBACK_MOUSE_MOVE:
                        v = caml_alloc(2, 0);
                        Store_field(v, 0, Val_mouse_move);
                        Store_field(v, 1, copy_Evas_Event_Mouse_Move(
                                (Evas_Event_Mouse_Move*) event_info));
                        break;
                case EVAS_CALLBACK_MOUSE_WHEEL:
                        v = caml_alloc(2, 0);
                        Store_field(v, 0, Val_mouse_wheel);
                        Store_field(v, 1, copy_Evas_Event_Mouse_Wheel(
                                (Evas_Event_Mouse_Wheel*) event_info));
                        break;
                case EVAS_CALLBACK_KEY_DOWN:
                        v = caml_alloc(2, 0);
                        Store_field(v, 0, Val_key_down);
                        Store_field(v, 1, copy_Evas_Event_Key_Down(
                                (Evas_Event_Key_Down*) event_info));
                        break;
                case EVAS_CALLBACK_FREE:
                        v = Val_free;
                        break;
                default: v = Val_other;
        }
        CAMLreturn(v);
}

PREFIX value ml_evas_smart_objects_calculate(value v_e)
{
        evas_smart_objects_calculate((Evas*) v_e);
        return Val_unit;
}

PREFIX value ml_bool_of_ptr(value v_ptr)
{
        Eina_Bool x = (Eina_Bool) v_ptr;
        return Val_bool(x);
}

PREFIX value ml_string_string_of_ptr(value v_ptr)
{
        CAMLparam1(v_ptr);
        CAMLlocal1(v_r);
        char** t = (char**) v_ptr;
        v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, copy_string(t[0]));
        Store_field(v_r, 1, copy_string(t[1]));
        CAMLreturn(v_r);
}

PREFIX value ml_store_ptr_bool(value v_ptr, value v_x)
{
        Eina_Bool* ptr = (Eina_Bool*) v_ptr;
        *ptr = Bool_val(v_x);
        return Val_unit;
}

PREFIX value ml_obj_of_ptr(value v_ptr)
{
        Evas_Object* obj = (Evas_Object*) v_ptr;
        return (value) obj;
}

PREFIX value ml_float_of_ptr(value v_ptr)
{
        double* x = (double*) x;
        return copy_double(*x);
}

PREFIX inline Evas_Load_Error Evas_Load_Error_val(value v)
{
        switch(v) {
                case Val_none: return EVAS_LOAD_ERROR_NONE;
                case Val_generic: return EVAS_LOAD_ERROR_GENERIC;
                case Val_does_not_exist: return EVAS_LOAD_ERROR_DOES_NOT_EXIST;
                case Val_permission_denied:
                        return EVAS_LOAD_ERROR_PERMISSION_DENIED;
                case Val_resource_allocation_failed:
                        return EVAS_LOAD_ERROR_RESOURCE_ALLOCATION_FAILED;
                case Val_corrupt_file: return EVAS_LOAD_ERROR_CORRUPT_FILE;
                case Val_unknown_format: return EVAS_LOAD_ERROR_UNKNOWN_FORMAT;
                default: break;
        }
        caml_failwith("Evas_Load_Error_val");
        return EVAS_LOAD_ERROR_NONE;
}

PREFIX inline value Val_Evas_Load_Error(Evas_Load_Error e)
{
        switch(e) {
                case EVAS_LOAD_ERROR_NONE: return Val_none;
                case EVAS_LOAD_ERROR_GENERIC: return Val_generic;
                case EVAS_LOAD_ERROR_DOES_NOT_EXIST:
                        return Val_does_not_exist;
                case EVAS_LOAD_ERROR_PERMISSION_DENIED:
                        return Val_permission_denied;
                case EVAS_LOAD_ERROR_RESOURCE_ALLOCATION_FAILED:
                        return Val_resource_allocation_failed;
                case EVAS_LOAD_ERROR_CORRUPT_FILE: return Val_corrupt_file;
                case EVAS_LOAD_ERROR_UNKNOWN_FORMAT: return Val_unknown_format;
        }
        caml_failwith("Val_Evas_Load_Error");
        return Val_none;
}

PREFIX value ml_evas_color_argb_premul(
        value v_a, value v_r, value v_g, value v_b)
{
        int r, g, b;
        r = Int_val(v_r);
        g = Int_val(v_g);
        b = Int_val(v_b);
        evas_color_argb_premul(Int_val(v_a), &r, &g, &b);
        value v = caml_alloc(3, 0);
        Store_field(v, 0, Val_int(r));
        Store_field(v, 1, Val_int(g));
        Store_field(v, 2, Val_int(b));
        return v;
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

PREFIX void ml_Evas_Smart_Cb_on_del(
        void* data, Evas_Object* v_obj, void* event_info)
{
        value* v_data = (value*) data;
        ml_remove_value(v_data);
}

PREFIX inline void ml_Evas_Object_gc_value(Evas_Object* obj, value* data)
{
        evas_object_event_callback_add(obj, EVAS_CALLBACK_FREE,
                ml_Evas_Object_Event_Cb_on_del, data);
}

