#include "include.h"

PREFIX inline value Val_Elm_Map_Overlay_Type(Elm_Map_Overlay_Type t)
{
        switch(t) {
                case ELM_MAP_OVERLAY_TYPE_NONE: return Val_none;
                case ELM_MAP_OVERLAY_TYPE_DEFAULT: return Val_default;
                case ELM_MAP_OVERLAY_TYPE_CLASS: return Val_class;
                case ELM_MAP_OVERLAY_TYPE_GROUP: return Val_group;
                case ELM_MAP_OVERLAY_TYPE_BUBBLE: return Val_bubble;
                case ELM_MAP_OVERLAY_TYPE_ROUTE: return Val_route;
                case ELM_MAP_OVERLAY_TYPE_LINE: return Val_line;
                case ELM_MAP_OVERLAY_TYPE_POLYGON: return Val_polygon;
                case ELM_MAP_OVERLAY_TYPE_CIRCLE: return Val_circle;
                case ELM_MAP_OVERLAY_TYPE_SCALE: return Val_scale;
        }
        caml_failwith("Val_elm_Map_Overlay_Type");
        return Val_none;
}

PREFIX inline Elm_Map_Zoom_Mode Elm_Map_Zoom_Mode_val(value v)
{
        switch(v) {
                case Val_manual: return ELM_MAP_ZOOM_MODE_MANUAL;
                case Val_auto_fit: return ELM_MAP_ZOOM_MODE_AUTO_FIT;
                case Val_auto_fill: return ELM_MAP_ZOOM_MODE_AUTO_FILL;
                case Val_last: return ELM_MAP_ZOOM_MODE_LAST;
                default: break;
        }
        caml_failwith("Elm_Map_Zoom_Mode_val");
        return ELM_MAP_ZOOM_MODE_MANUAL;
}

PREFIX inline value Val_Elm_Map_Zoom_Mode(Elm_Map_Zoom_Mode m)
{
        switch(m) {
                case ELM_MAP_ZOOM_MODE_MANUAL: return Val_manual;
                case ELM_MAP_ZOOM_MODE_AUTO_FIT: return Val_auto_fit;
                case ELM_MAP_ZOOM_MODE_AUTO_FILL: return Val_auto_fill;
                case ELM_MAP_ZOOM_MODE_LAST: return Val_last;
        }
        caml_failwith("Val_Elm_Map_Zoom_Mode");
        return Val_manual;
}

PREFIX inline value copy_Eina_List_Elm_Map_Overlay(const Eina_List* list)
{
        CAMLparam0();
        CAMLlocal2(v, v1);
        Eina_List* it;
        Elm_Map_Overlay* obj;
        v = Val_int(0);
        EINA_LIST_REVERSE_FOREACH(list, it, obj) {
                v1 = v;
                v = caml_alloc(2, 0);
                Store_field(v, 0, (value) obj);
                Store_field(v, 1, v1);
        }
        CAMLreturn(v);
}

PREFIX value ml_elm_map_add(Evas_Object* v_parent)
{
        Evas_Object* map = elm_map_add((Evas_Object*) v_parent);
        if(map == NULL) caml_failwith("elm_map_add");
        return (value) map;
}

PREFIX value ml_elm_map_zoom_set(value v_obj, value v_x)
{
        elm_map_zoom_set((Evas_Object*) v_obj, Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_map_zoom_get(value v_obj)
{
        return Val_int(elm_map_zoom_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_map_zoom_mode_set(value v_obj, value v_mode)
{
        elm_map_zoom_mode_set((Evas_Object*) v_obj,
                Elm_Map_Zoom_Mode_val(v_mode));
        return Val_unit;
}

PREFIX value ml_elm_map_zoom_mode_get(value v_obj)
{
        return Val_Elm_Map_Zoom_Mode(elm_map_zoom_mode_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_map_zoom_min_set(value v_obj, value v_x)
{
        elm_map_zoom_min_set((Evas_Object*) v_obj, Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_map_zoom_min_get(value v_obj)
{
        return Val_int(elm_map_zoom_min_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_map_zoom_max_set(value v_obj, value v_x)
{
        elm_map_zoom_max_set((Evas_Object*) v_obj, Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_map_zoom_max_get(value v_obj)
{
        return Val_int(elm_map_zoom_max_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_map_region_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_r);
        double lon, lat;
        elm_map_region_get((Evas_Object*) v_obj, &lon, &lat);
        v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, copy_double(lon));
        Store_field(v_r, 1, copy_double(lat));
        CAMLreturn(v_r);
}

PREFIX value ml_elm_map_region_bring_in(value v_obj, value v_lon, value v_lat)
{
        elm_map_region_bring_in((Evas_Object*) v_obj, Double_val(v_lon),
                Double_val(v_lat));
        return Val_unit;
}

PREFIX value ml_elm_map_region_show(value v_obj, value v_lon, value v_lat)
{
        elm_map_region_show((Evas_Object*) v_obj, Double_val(v_lon),
                Double_val(v_lat));
        return Val_unit;
}

PREFIX value ml_elm_map_canvas_to_region_convert(
        value v_obj, value v_x, value v_y)
{
        CAMLparam3(v_obj, v_x, v_y);
        CAMLlocal1(v_r);
        double lon, lat;
        elm_map_canvas_to_region_convert((Evas_Object*) v_obj, Int_val(v_x),
                Int_val(v_y), &lon, &lat);
        v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, copy_double(lon));
        Store_field(v_r, 1, copy_double(lat));
        CAMLreturn(v_r);
}

PREFIX value ml_elm_map_region_to_canvas_convert(
        value v_obj, value v_lon, value v_lat)
{
        Evas_Coord x, y;
        elm_map_region_to_canvas_convert((Evas_Object*) v_obj,
                Double_val(v_lon), Double_val(v_lat), &x, &y);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(x));
        Store_field(v_r, 1, Val_int(y));
        return v_r;
}

PREFIX value ml_elm_map_paused_set(value v_obj, value v_flag)
{
        elm_map_paused_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_map_paused_get(value v_obj)
{
        return Val_bool(elm_map_paused_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_map_rotate_set(value v_obj, value v_a, value v_x, value v_y)
{
        elm_map_rotate_set((Evas_Object*) v_obj, Double_val(v_a), Int_val(v_x),
                Int_val(v_y));
        return Val_unit;
}

PREFIX value ml_elm_map_rotate_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_r);
        double a;
        Evas_Coord x, y;
        elm_map_rotate_get((Evas_Object*) v_obj, &a, &x, &y);
        v_r = caml_alloc(3, 0);
        Store_field(v_r, 0, copy_double(a));
        Store_field(v_r, 1, Val_int(x));
        Store_field(v_r, 2, Val_int(y));
        CAMLreturn(v_r);
}

PREFIX value ml_elm_map_wheel_disabled_set(value v_obj, value v_flag)
{
        elm_map_wheel_disabled_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_map_wheel_disabled_get(value v_obj)
{
        return Val_bool(elm_map_wheel_disabled_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_map_user_agent_set(value v_obj, value v_s)
{
        elm_map_user_agent_set((Evas_Object*) v_obj, String_val(v_s));
        return Val_unit;
}

PREFIX value ml_elm_map_user_agent_get(value v_obj)
{
        return copy_string(elm_map_user_agent_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_map_overlay_add(value v_obj, value v_lon, value v_lat)
{
        Elm_Map_Overlay* ov = elm_map_overlay_add((Evas_Object*) v_obj,
                Double_val(v_lon), Double_val(v_lat));
        if(ov == NULL) caml_failwith("elm_map_overlay_add");
        return (value) ov;
}

PREFIX value ml_elm_map_overlays_get(value v_obj)
{
        return copy_Eina_List_Elm_Map_Overlay(elm_map_overlays_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_map_overlay_del(value v_ov)
{
        elm_map_overlay_del((Elm_Map_Overlay*) v_ov);
        return Val_unit;
}

PREFIX value ml_elm_map_overlay_type_get(value v_ov)
{
        return Val_Elm_Map_Overlay_Type(elm_map_overlay_type_get(
                (Elm_Map_Overlay*) v_ov));
}

PREFIX value ml_elm_map_overlay_hide_set(value v_ov, value v_flag)
{
        elm_map_overlay_hide_set((Elm_Map_Overlay*) v_ov, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_map_overlay_hide_get(value v_ov, value v_flag)
{
        return Val_bool(elm_map_overlay_hide_get((Elm_Map_Overlay*) v_ov));
}

