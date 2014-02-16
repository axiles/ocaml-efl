#include "evas_event_wrap.h"

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

PREFIX inline value copy_Evas_Event_Mouse_In(Evas_Event_Mouse_In* e)
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

PREFIX inline value copy_Evas_Event_Mouse_Out(Evas_Event_Mouse_Out* e)
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
        value v = caml_alloc(9, 0);
        Store_field(v, 0, Val_int(ev->button));
        Store_field(v, 1, copy_Evas_Point(ev->output));
        Store_field(v, 2, copy_Evas_Coord_Point(ev->canvas));
        Store_field(v, 3, (value) ev->modifiers);
        Store_field(v, 4, Val_Evas_Button_Flags(ev->flags));
        Store_field(v, 5, Val_int(ev->timestamp));
        Store_field(v, 6, Val_Evas_Event_Flags(ev->flags));
        Store_field(v, 7, (value) ev->dev);
        Store_field(v, 8, (value) ev->event_src);
        return v;
}

PREFIX inline value copy_Evas_Event_Mouse_Up(Evas_Event_Mouse_Up* ev)
{
        value v = caml_alloc(9, 0);
        Store_field(v, 0, Val_int(ev->button));
        Store_field(v, 1, copy_Evas_Point(ev->output));
        Store_field(v, 2, copy_Evas_Coord_Point(ev->canvas));
        Store_field(v, 3, (value) ev->modifiers);
        Store_field(v, 4, Val_Evas_Button_Flags(ev->flags));
        Store_field(v, 5, Val_int(ev->timestamp));
        Store_field(v, 6, Val_Evas_Event_Flags(ev->flags));
        Store_field(v, 7, (value) ev->dev);
        Store_field(v, 8, (value) ev->event_src);
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

PREFIX inline value copy_Evas_Event_Multi_Down(Evas_Event_Multi_Down* ev)
{
        CAMLparam0();
        CAMLlocal1(v);
        v = caml_alloc(13, 0);
        Store_field(v, 0, Val_int(ev->device));
        Store_field(v, 1, copy_double(ev->radius));
        Store_field(v, 2, copy_double(ev->radius_x));
        Store_field(v, 3, copy_double(ev->radius_y));
        Store_field(v, 4, copy_double(ev->pressure));
        Store_field(v, 5, copy_double(ev->angle));
        Store_field(v, 6, copy_Evas_Point(ev->output));
        Store_field(v, 7, copy_Evas_Coord_Precision_Point(ev->canvas));
        Store_field(v, 8, (value) ev->modifiers);
        Store_field(v, 9, Val_Evas_Button_Flags(ev->flags));
        Store_field(v, 10, Val_int(ev->timestamp));
        Store_field(v, 11, Val_Evas_Event_Flags(ev->event_flags));
        Store_field(v, 12, (value) ev->dev);
        CAMLreturn(v);
}

PREFIX inline value copy_Evas_Event_Multi_Up(Evas_Event_Multi_Up* ev)
{
        CAMLparam0();
        CAMLlocal1(v);
        v = caml_alloc(13, 0);
        Store_field(v, 0, Val_int(ev->device));
        Store_field(v, 1, copy_double(ev->radius));
        Store_field(v, 2, copy_double(ev->radius_x));
        Store_field(v, 3, copy_double(ev->radius_y));
        Store_field(v, 4, copy_double(ev->pressure));
        Store_field(v, 5, copy_double(ev->angle));
        Store_field(v, 6, copy_Evas_Point(ev->output));
        Store_field(v, 7, copy_Evas_Coord_Precision_Point(ev->canvas));
        Store_field(v, 8, (value) ev->modifiers);
        Store_field(v, 9, Val_Evas_Button_Flags(ev->flags));
        Store_field(v, 10, Val_int(ev->timestamp));
        Store_field(v, 11, Val_Evas_Event_Flags(ev->event_flags));
        Store_field(v, 12, (value) ev->dev);
        CAMLreturn(v);
}

PREFIX inline value copy_Evas_Event_Multi_Move(Evas_Event_Multi_Move* ev)
{
        CAMLparam0();
        CAMLlocal1(v);
        v = caml_alloc(11, 0);
        Store_field(v, 0, Val_int(ev->device));
        Store_field(v, 1, copy_double(ev->radius));
        Store_field(v, 2, copy_double(ev->radius_x));
        Store_field(v, 3, copy_double(ev->radius_y));
        Store_field(v, 4, copy_double(ev->pressure));
        Store_field(v, 5, copy_double(ev->angle));
        Store_field(v, 6, copy_Evas_Precision_Position(ev->cur));
        Store_field(v, 7, (value) ev->modifiers);
        Store_field(v, 8, Val_int(ev->timestamp));
        Store_field(v, 9, Val_Evas_Event_Flags(ev->event_flags));
        Store_field(v, 10, (value) ev->dev);
        CAMLreturn(v);
}

PREFIX inline value copy_Evas_Event_Key_Down(Evas_Event_Key_Down* info)
{
        CAMLparam0();
        CAMLlocal1(v);
        v = caml_alloc(8, 0);
        Store_field(v, 0, copy_string(info->keyname));
        Store_field(v, 1, (value) info->modifiers);
        Store_field(v, 2, copy_string(info->key));
        Store_field(v, 3, copy_string(info->string));
        Store_field(v, 4, copy_string(info->compose));
        Store_field(v, 5, Val_int(info->timestamp));
        Store_field(v, 6, Val_Evas_Event_Flags(info->event_flags));
        Store_field(v, 7, (value) info->dev);
        CAMLreturn(v);
}

PREFIX inline value copy_Evas_Event_Key_Up(Evas_Event_Key_Up* info)
{
        CAMLparam0();
        CAMLlocal1(v);
        v = caml_alloc(8, 0);
        Store_field(v, 0, copy_string(info->keyname));
        Store_field(v, 1, (value) info->modifiers);
        Store_field(v, 2, copy_string(info->key));
        Store_field(v, 3, copy_string(info->string));
        Store_field(v, 4, copy_string(info->compose));
        Store_field(v, 5, Val_int(info->timestamp));
        Store_field(v, 6, Val_Evas_Event_Flags(info->event_flags));
        Store_field(v, 7, (value) info->dev);
        CAMLreturn(v);
}

PREFIX inline value copy_Evas_Event_Hold(Evas_Event_Hold* ev)
{
        value v = caml_alloc(4, 0);
        Store_field(v, 0, Val_int(ev->hold));
        Store_field(v, 1, Val_int(ev->timestamp));
        Store_field(v, 2, Val_Evas_Event_Flags(ev->event_flags));
        Store_field(v, 3, (value) ev->dev);
        return v;
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

