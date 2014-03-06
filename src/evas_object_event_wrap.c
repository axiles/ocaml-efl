#include "include.h"

void ml_Evas_Object_Event_Cb_mouse_in(
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

void ml_Evas_Object_Event_Cb_mouse_out(
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

void ml_Evas_Object_Event_Cb_mouse_down(
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

void ml_Evas_Object_Event_Cb_mouse_up(
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

void ml_Evas_Object_Event_Cb_mouse_move(
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

void ml_Evas_Object_Event_Cb_mouse_wheel(
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

void ml_Evas_Object_Event_Cb_multi_down(
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

void ml_Evas_Object_Event_Cb_multi_up(
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

void ml_Evas_Object_Event_Cb_multi_move(
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

void ml_Evas_Object_Event_Cb_unit(
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

void ml_Evas_Object_Event_Cb_key_down(
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

void ml_Evas_Object_Event_Cb_key_up(
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

void ml_Evas_Object_Event_Cb_hold(
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

PREFIX value ml_evas_object_event_callback_priority_add_mouse_in(
        value v_obj, value v_p, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_func);
        evas_object_event_callback_priority_add(obj, EVAS_CALLBACK_MOUSE_IN,
                Evas_Callback_Priority_val(v_p),
                ml_Evas_Object_Event_Cb_mouse_in, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_priority_add_mouse_out(
        value v_obj, value v_p, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_func);
        evas_object_event_callback_priority_add(obj, EVAS_CALLBACK_MOUSE_OUT,
                Evas_Callback_Priority_val(v_p),
                ml_Evas_Object_Event_Cb_mouse_out, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_priority_add_mouse_down(
        value v_obj, value v_p, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_func);
        evas_object_event_callback_priority_add(obj, EVAS_CALLBACK_MOUSE_DOWN,
                Evas_Callback_Priority_val(v_p),
                ml_Evas_Object_Event_Cb_mouse_down, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_priority_add_mouse_up(
        value v_obj, value v_p, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_func);
        evas_object_event_callback_priority_add(obj, EVAS_CALLBACK_MOUSE_UP,
                Evas_Callback_Priority_val(v_p),
                ml_Evas_Object_Event_Cb_mouse_up, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_priority_add_mouse_move(
        value v_obj, value v_p, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_func);
        evas_object_event_callback_priority_add(obj, EVAS_CALLBACK_MOUSE_MOVE,
                Evas_Callback_Priority_val(v_p),
                ml_Evas_Object_Event_Cb_mouse_move, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_priority_add_mouse_wheel(
        value v_obj, value v_p, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_func);
        evas_object_event_callback_priority_add(obj, EVAS_CALLBACK_MOUSE_WHEEL,
                Evas_Callback_Priority_val(v_p),
                ml_Evas_Object_Event_Cb_mouse_wheel, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_priority_add_multi_down(
        value v_obj, value v_p, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_func);
        evas_object_event_callback_priority_add(obj, EVAS_CALLBACK_MULTI_DOWN,
                Evas_Callback_Priority_val(v_p),
                ml_Evas_Object_Event_Cb_multi_down, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_priority_add_multi_up(
        value v_obj, value v_p, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_func);
        evas_object_event_callback_priority_add(obj, EVAS_CALLBACK_MULTI_UP,
                Evas_Callback_Priority_val(v_p),
                ml_Evas_Object_Event_Cb_multi_up, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_priority_add_multi_move(
        value v_obj, value v_p, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_func);
        evas_object_event_callback_priority_add(obj, EVAS_CALLBACK_MULTI_MOVE,
                Evas_Callback_Priority_val(v_p),
                ml_Evas_Object_Event_Cb_multi_move, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_priority_add_free(value v_obj, value v_p, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_register_value(v_func);
        evas_object_event_callback_priority_add(obj, EVAS_CALLBACK_FREE,
                Evas_Callback_Priority_val(v_p),
                ml_Evas_Object_Event_Cb_unit, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_priority_add_key_down(
        value v_obj, value v_p, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_func);
        evas_object_event_callback_priority_add(obj, EVAS_CALLBACK_KEY_DOWN,
                Evas_Callback_Priority_val(v_p),
                ml_Evas_Object_Event_Cb_key_down, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_priority_add_key_up(
        value v_obj, value v_p, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_func);
        evas_object_event_callback_priority_add(obj, EVAS_CALLBACK_KEY_UP,
                Evas_Callback_Priority_val(v_p),
                ml_Evas_Object_Event_Cb_key_up, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_priority_add_focus_in(
        value v_obj, value v_p, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_register_value(v_func);
        evas_object_event_callback_priority_add(obj, EVAS_CALLBACK_FOCUS_IN,
                Evas_Callback_Priority_val(v_p),
                ml_Evas_Object_Event_Cb_unit, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_priority_add_focus_out(
        value v_obj, value v_p, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_register_value(v_func);
        evas_object_event_callback_priority_add(obj, EVAS_CALLBACK_FOCUS_OUT,
                Evas_Callback_Priority_val(v_p),
                ml_Evas_Object_Event_Cb_unit, data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_priority_add_show(
        value v_obj, value v_p, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_register_value(v_func);
        evas_object_event_callback_priority_add(obj, EVAS_CALLBACK_SHOW,
                Evas_Callback_Priority_val(v_p), ml_Evas_Object_Event_Cb_unit,
                data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_priority_add_hide(
        value v_obj, value v_p, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_register_value(v_func);
        evas_object_event_callback_priority_add(obj, EVAS_CALLBACK_HIDE,
                Evas_Callback_Priority_val(v_p), ml_Evas_Object_Event_Cb_unit,
                data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_priority_add_move(
        value v_obj, value v_p, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_register_value(v_func);
        evas_object_event_callback_priority_add(obj, EVAS_CALLBACK_MOVE,
                Evas_Callback_Priority_val(v_p), ml_Evas_Object_Event_Cb_unit,
                data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_priority_add_resize(
        value v_obj, value v_p, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_register_value(v_func);
        evas_object_event_callback_priority_add(obj, EVAS_CALLBACK_RESIZE,
                Evas_Callback_Priority_val(v_p), ml_Evas_Object_Event_Cb_unit,
                data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_priority_add_restack(
        value v_obj, value v_p, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_register_value(v_func);
        evas_object_event_callback_priority_add(obj, EVAS_CALLBACK_RESTACK,
                Evas_Callback_Priority_val(v_p), ml_Evas_Object_Event_Cb_unit,
                data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_priority_add_del(
        value v_obj, value v_p, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_register_value(v_func);
        evas_object_event_callback_priority_add(obj, EVAS_CALLBACK_DEL,
                Evas_Callback_Priority_val(v_p), ml_Evas_Object_Event_Cb_unit,
                data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_priority_add_hold(
        value v_obj, value v_p, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_func);
        evas_object_event_callback_priority_add(obj, EVAS_CALLBACK_HOLD,
                Evas_Callback_Priority_val(v_p), ml_Evas_Object_Event_Cb_hold,
                data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_priority_add_changed_size_hints(
        value v_obj, value v_p, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_register_value(v_func);
        evas_object_event_callback_priority_add(obj,
                EVAS_CALLBACK_CHANGED_SIZE_HINTS,
                Evas_Callback_Priority_val(v_p), ml_Evas_Object_Event_Cb_unit,
                data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_priority_add_image_preloaded(
        value v_obj, value v_p, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_register_value(v_func);
        evas_object_event_callback_priority_add(obj,
                EVAS_CALLBACK_IMAGE_PRELOADED,
                Evas_Callback_Priority_val(v_p), ml_Evas_Object_Event_Cb_unit,
                data);
        return Val_unit;
}

PREFIX value ml_evas_object_event_callback_priority_add_image_unloaded(
        value v_obj, value v_p, value v_func)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_register_value(v_func);
        evas_object_event_callback_priority_add(obj,
                EVAS_CALLBACK_IMAGE_UNLOADED,
                Evas_Callback_Priority_val(v_p), ml_Evas_Object_Event_Cb_unit,
                data);
        return Val_unit;
}

PREFIX value ml_evas_object_pass_events_set(value v_obj, value v_flag)
{
        evas_object_pass_events_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_evas_object_pass_events_get(value v_obj)
{
        return Val_bool(evas_object_pass_events_get((Evas_Object*) v_obj));
}

PREFIX value ml_evas_object_repeat_events_set(value v_obj, value v_flag)
{
        evas_object_repeat_events_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_evas_object_repeat_events_get(value v_obj)
{
        return Val_bool(evas_object_repeat_events_get((Evas_Object*) v_obj));
}

PREFIX value ml_evas_object_propagate_events_set(value v_obj, value v_flag)
{
        evas_object_propagate_events_set((Evas_Object*) v_obj,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_evas_object_propagate_events_get(value v_obj)
{
        return Val_bool(evas_object_propagate_events_get((Evas_Object*) v_obj));
}

PREFIX value ml_evas_object_freeze_events_set(value v_obj, value v_flag)
{
        evas_object_freeze_events_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_evas_object_freeze_events_get(value v_obj)
{
        return Val_bool(evas_object_freeze_events_get((Evas_Object*) v_obj));
}

