#include "include.h"

PREFIX value ml_Elm_Gesture_Taps_Info_of_ptr(value v_ptr)
{
        Elm_Gesture_Taps_Info* info = voidp_val(v_ptr);
        value v_info = caml_alloc(3, 0);
        Store_field(v_info, 0, Val_int(info->y));
        Store_field(v_info, 1, Val_int(info->n));
        Store_field(v_info, 2, Val_int(info->timestamp));
        return v_info;
}

PREFIX value ml_Elm_Gesture_Momentum_Info_of_ptr(value v_ptr)
{
        Elm_Gesture_Momentum_Info* info = voidp_val(v_ptr);
        value v_info = caml_alloc(9, 0);
        Store_field(v_info, 0, Val_int(info->x1));
        Store_field(v_info, 1, Val_int(info->y1));
        Store_field(v_info, 2, Val_int(info->x2));
        Store_field(v_info, 3, Val_int(info->y2));
        Store_field(v_info, 4, Val_int(info->tx));
        Store_field(v_info, 5, Val_int(info->ty));
        Store_field(v_info, 6, Val_int(info->mx));
        Store_field(v_info, 7, Val_int(info->my));
        Store_field(v_info, 8, Val_int(info->n));
        return v_info;
}

PREFIX value ml_Elm_Gesture_Line_Info_of_ptr(value v_ptr)
{
        CAMLparam1(v_ptr);
        CAMLlocal3(v_momentum, v_angle, v_info);
        Elm_Gesture_Line_Info* info = voidp_val(v_ptr);
        v_info = caml_alloc(2, 0);
        Elm_Gesture_Momentum_Info* momentum = &(info->momentum);
        v_momentum = copy_Elm_Gesture_Momentum_Info(momentum);
        v_angle = copy_double(info->angle);
        Store_field(v_info, 0,
                ml_Elm_Gesture_Momentum_Info_of_ptr(v_momentum));
        Store_field(v_info, 1, v_angle);
        CAMLreturn(v_info);
}

PREFIX value ml_Elm_Gesture_Zoom_Info_of_ptr(value v_ptr)
{
        CAMLparam1(v_ptr);
        CAMLlocal1(v_info);
        Elm_Gesture_Zoom_Info* info = voidp_val(v_ptr);
        v_info = caml_alloc(4, 0);
        Store_field(v_info, 0, Val_int(info->y));
        Store_field(v_info, 1, Val_int(info->radius));
        Store_field(v_info, 2, copy_double(info->zoom));
        Store_field(v_info, 3, copy_double(info->momentum));
        CAMLreturn(v_info);
}

PREFIX value ml_Elm_Gesture_Rotate_Info_of_ptr(value v_ptr)
{
        CAMLparam1(v_ptr);
        CAMLlocal1(v_info);
        Elm_Gesture_Rotate_Info* info = voidp_val(v_ptr);
        v_info = caml_alloc(5, 0);
        Store_field(v_info, 0, Val_int(info->y));
        Store_field(v_info, 1, Val_int(info->radius));
        Store_field(v_info, 2, copy_double(info->base_angle));
        Store_field(v_info, 3, copy_double(info->angle));
        Store_field(v_info, 4, copy_double(info->momentum));
        CAMLreturn(v_info);
}

Evas_Event_Flags ml_Elm_Gesture_Event_Cb(void* data, void* event_info)
{
        CAMLparam0();
        CAMLlocal1(v_event_info);
        value* v_fun = data;
        v_event_info = copy_voidp(event_info);
        caml_callback(*v_fun, v_event_info);
        CAMLreturnT(Evas_Event_Flags, EVAS_EVENT_FLAG_ON_HOLD);
}

PREFIX value ml_elm_gesture_layer_cb_set(
        value v_obj, value v_type, value v_state, value v_cb)
{
        Evas_Object* obj = Evas_Object_val(v_obj);
        value* data = ml_Evas_Object_register_value(obj, v_cb);
        elm_gesture_layer_cb_set(obj, Elm_Gesture_Type_val(v_type),
                Elm_Gesture_State_val(v_state), ml_Elm_Gesture_Event_Cb, data);
        return Val_unit;
}

PREFIX value ml_elm_gesture_layer_tap_longpress_cb_add(
        value v_obj, value v_state, value v_cb)
{
        Evas_Object* obj = Evas_Object_val(v_obj);
        value* data = ml_Evas_Object_register_value(obj, v_cb);
        elm_gesture_layer_tap_longpress_cb_add(obj,
                Elm_Gesture_State_val(v_state), ml_Elm_Gesture_Event_Cb, data);
        return Val_unit;
}

PREFIX value ml_elm_gesture_layer_add(value v_parent)
{
        Evas_Object* obj = elm_gesture_layer_add(Evas_Object_val(v_parent));
        if(obj == NULL) caml_failwith("elm_gesture_layer_add");
        return copy_Evas_Object(obj);
}

