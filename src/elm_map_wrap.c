#include "include.h"

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

