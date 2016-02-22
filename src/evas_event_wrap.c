#include "evas_event_wrap.h"

 value Val_Evas_Event_Flags(Evas_Event_Flags f)
{
        switch(f) {
                case EVAS_EVENT_FLAG_NONE: return Val_none;
                case EVAS_EVENT_FLAG_ON_HOLD: return Val_on_hold;
                case EVAS_EVENT_FLAG_ON_SCROLL: return Val_on_scroll;
        }
        caml_failwith("Val_Evas_Event_Flag");
        return Val_none;
}

 value copy_Evas_Event_Info(
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
                case EVAS_CALLBACK_MULTI_DOWN:
                        v = caml_alloc(2, 0);
                        Store_field(v, 0, Val_multi_down);
                        Store_field(v, 1, copy_Evas_Event_Multi_Down(
                                (Evas_Event_Multi_Down*) event_info));
                        break;
                case EVAS_CALLBACK_MULTI_UP:
                        v = caml_alloc(2, 0);
                        Store_field(v, 0, Val_multi_up);
                        Store_field(v, 1, copy_Evas_Event_Multi_Up(
                                (Evas_Event_Multi_Up*) event_info));
                        break;
                case EVAS_CALLBACK_MULTI_MOVE:
                        v = caml_alloc(2, 0);
                        Store_field(v, 0, Val_multi_move);
                        Store_field(v, 1, copy_Evas_Event_Multi_Move(
                                (Evas_Event_Multi_Move*) event_info));
                        break;
                case EVAS_CALLBACK_FREE:
                        v = Val_free;
                        break;
                case EVAS_CALLBACK_KEY_DOWN:
                        v = caml_alloc(2, 0);
                        Store_field(v, 0, Val_key_down);
                        Store_field(v, 1, copy_Evas_Event_Key_Down(
                                (Evas_Event_Key_Down*) event_info));
                        break;
                case EVAS_CALLBACK_KEY_UP:
                        v = caml_alloc(2, 0);
                        Store_field(v, 0, Val_key_up);
                        Store_field(v, 1, copy_Evas_Event_Key_Up(
                                (Evas_Event_Key_Up*) event_info));
                        break;
                case EVAS_CALLBACK_FOCUS_IN:
                        v = Val_focus_in;
                        break;
                case EVAS_CALLBACK_FOCUS_OUT:
                        v = Val_focus_out;
                        break;
                case EVAS_CALLBACK_SHOW:
                        v = Val_show;
                        break;
                case EVAS_CALLBACK_HIDE:
                        v = Val_hide;
                        break;
                case EVAS_CALLBACK_MOVE:
                        v = Val_move;
                        break;
                case EVAS_CALLBACK_RESIZE:
                        v = Val_resize;
                        break;
                case EVAS_CALLBACK_RESTACK:
                        v = Val_restack;
                        break;
                case EVAS_CALLBACK_DEL:
                        v = Val_del;
                        break;
                case EVAS_CALLBACK_HOLD:
                        v = caml_alloc(2, 0);
                        Store_field(v, 0, Val_hold);
                        Store_field(v, 1, copy_Evas_Event_Hold(
                                (Evas_Event_Hold*) event_info));
                        break;
                case EVAS_CALLBACK_CHANGED_SIZE_HINTS:
                        v = Val_changed_size_hints;
                        break;
                case EVAS_CALLBACK_IMAGE_PRELOADED:
                        v = Val_image_preloaded;
                        break;
                case EVAS_CALLBACK_CANVAS_FOCUS_IN:
                        v = Val_canvas_focus_in;
                        break;
                case EVAS_CALLBACK_CANVAS_FOCUS_OUT:
                        v = Val_canvas_focus_out;
                        break;
                case EVAS_CALLBACK_RENDER_FLUSH_PRE:
                        v = Val_render_flush_pre;
                        break;
                case EVAS_CALLBACK_RENDER_FLUSH_POST:
                        v = Val_render_flush_post;
                        break;
                case EVAS_CALLBACK_CANVAS_OBJECT_FOCUS_IN:
                        v = Val_canvas_object_focus_in;
                        break;
                case EVAS_CALLBACK_CANVAS_OBJECT_FOCUS_OUT:
                        v = Val_canvas_object_focus_out;
                        break;
                case EVAS_CALLBACK_IMAGE_UNLOADED:
                        v = Val_image_unloaded;
                        break;
                case EVAS_CALLBACK_RENDER_PRE:
                        v = Val_render_pre;
                        break;
                case EVAS_CALLBACK_RENDER_POST:
                        v = Val_render_post;
                        break;
                case EVAS_CALLBACK_IMAGE_RESIZE:
                        v = Val_image_resize;
                        break;
                case EVAS_CALLBACK_DEVICE_CHANGED:
                        v = Val_device_changed;
                        break;
                default: v = Val_last;
        }
        CAMLreturn(v);
}

/* Canvas Events */

void ml_Evas_Event_Cb_unit(void* data, Evas* e, void* event_info)
{
        CAMLparam0();
        value* v_fun = (value*) data;
        caml_callback2(*v_fun, (value) e, Val_unit);
        CAMLreturn0;
}

Eina_Bool ml_Evas_Object_Post_Event_Cb(void* data, Evas* e)
{
        CAMLparam0();
        CAMLlocal1(v_r);
        value* v_fun = (value*) data;
        v_r = caml_callback(*v_fun, (value) e);
        CAMLreturnT(Eina_Bool, Bool_val(v_r));
}

void ml_Evas_Event_Cb_value(void* data, Evas* e, void* event_info)
{
        CAMLparam0();
        value* v_fun = (value*) data;
        caml_callback2(*v_fun, (value) e, (value) event_info);
        CAMLreturn0;
}

PREFIX value ml_evas_event_callback_add_render_flush_pre(value v_e, value v_cb)
{
        value* data = ml_Evas_register_value(v_cb);
        evas_event_callback_add((Evas*) v_e, EVAS_CALLBACK_RENDER_FLUSH_PRE,
                ml_Evas_Event_Cb_unit, data);
        return Val_unit;
}

PREFIX value ml_evas_event_callback_add_render_flush_post(value v_e, value v_cb)
{
        value* data = ml_Evas_register_value(v_cb);
        evas_event_callback_add((Evas*) v_e, EVAS_CALLBACK_RENDER_FLUSH_POST,
                ml_Evas_Event_Cb_unit, data);
        return Val_unit;
}

PREFIX value ml_evas_event_callback_add_canvas_focus_in(value v_e, value v_cb)
{
        value* data = ml_Evas_register_value(v_cb);
        evas_event_callback_add((Evas*) v_e, EVAS_CALLBACK_CANVAS_FOCUS_IN,
                ml_Evas_Event_Cb_unit, data);
        return Val_unit;
}

PREFIX value ml_evas_event_callback_add_canvas_focus_out(value v_e, value v_cb)
{
        value* data = ml_Evas_register_value(v_cb);
        evas_event_callback_add((Evas*) v_e, EVAS_CALLBACK_CANVAS_FOCUS_OUT,
                ml_Evas_Event_Cb_unit, data);
        return Val_unit;
}

PREFIX value ml_evas_event_callback_add_canvas_object_focus_in(
        value v_e, value v_cb)
{
        value* data = ml_Evas_register_value(v_cb);
        evas_event_callback_add((Evas*) v_e,
                EVAS_CALLBACK_CANVAS_OBJECT_FOCUS_IN, ml_Evas_Event_Cb_value,
                data);
        return Val_unit;
}

PREFIX value ml_evas_event_callback_add_canvas_object_focus_out(
        value v_e, value v_cb)
{
        value* data = ml_Evas_register_value(v_cb);
        evas_event_callback_add((Evas*) v_e,
                EVAS_CALLBACK_CANVAS_OBJECT_FOCUS_OUT, ml_Evas_Event_Cb_value,
                data);
        return Val_unit;
}

PREFIX value ml_evas_event_callback_priority_add_render_flush_pre(
        value v_e, value v_p, value v_cb)
{
        value* data = ml_Evas_register_value(v_cb);
        evas_event_callback_priority_add((Evas*) v_e,
                Evas_Callback_Priority_val(v_p),EVAS_CALLBACK_RENDER_FLUSH_PRE,
                ml_Evas_Event_Cb_unit, data);
        return Val_unit;
}

PREFIX value ml_evas_event_callback_priority_add_render_flush_post(
        value v_e, value v_p, value v_cb)
{
        value* data = ml_Evas_register_value(v_cb);
        evas_event_callback_priority_add((Evas*) v_e,
                Evas_Callback_Priority_val(v_p),
                EVAS_CALLBACK_RENDER_FLUSH_POST, ml_Evas_Event_Cb_unit, data);
        return Val_unit;
}

PREFIX value ml_evas_event_callback_priority_add_canvas_focus_in(
        value v_e, value v_p, value v_cb)
{
        value* data = ml_Evas_register_value(v_cb);
        evas_event_callback_priority_add((Evas*) v_e,
                Evas_Callback_Priority_val(v_p), EVAS_CALLBACK_CANVAS_FOCUS_IN,
                ml_Evas_Event_Cb_unit, data);
        return Val_unit;
}

PREFIX value ml_evas_event_callback_priority_add_canvas_focus_out(
        value v_e, value v_p, value v_cb)
{
        value* data = ml_Evas_register_value(v_cb);
        evas_event_callback_priority_add((Evas*) v_e,
                Evas_Callback_Priority_val(v_p), EVAS_CALLBACK_CANVAS_FOCUS_OUT,
                ml_Evas_Event_Cb_unit, data);
        return Val_unit;
}

PREFIX value ml_evas_event_callback_priority_add_canvas_object_focus_in(
        value v_e, value v_p, value v_cb)
{
        value* data = ml_Evas_register_value(v_cb);
        evas_event_callback_priority_add((Evas*) v_e,
                Evas_Callback_Priority_val(v_p),
                EVAS_CALLBACK_CANVAS_OBJECT_FOCUS_IN, ml_Evas_Event_Cb_value,
                data);
        return Val_unit;
}

PREFIX value ml_evas_event_callback_priority_add_canvas_object_focus_out(
        value v_e, value v_p, value v_cb)
{
        value* data = ml_Evas_register_value(v_cb);
        evas_event_callback_priority_add((Evas*) v_e,
                Evas_Callback_Priority_val(v_p),
                EVAS_CALLBACK_CANVAS_OBJECT_FOCUS_OUT, ml_Evas_Event_Cb_value,
                data);
        return Val_unit;
}

PREFIX value ml_evas_post_event_callback_push(value v_e, value v_cb)
{
        value* data = ml_Evas_register_value(v_cb);
        evas_post_event_callback_push((Evas*) v_e, ml_Evas_Object_Post_Event_Cb,
                data);
        return Val_unit;
}

/* Input Events Freezing/Feeding */

PREFIX value ml_evas_event_freeze(value v_e)
{
        evas_event_freeze((Evas*) v_e);
        return Val_unit;
}

PREFIX value ml_evas_event_thaw(value v_e)
{
        evas_event_thaw((Evas*) v_e);
        return Val_unit;
}

