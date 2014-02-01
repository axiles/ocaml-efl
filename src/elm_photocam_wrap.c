#include "include.h"

PREFIX inline Elm_Photocam_Zoom_Mode Elm_Photocam_Zoom_Mode_val(value v)
{
        switch(v) {
                case Val_manual: return ELM_PHOTOCAM_ZOOM_MODE_MANUAL;
                case Val_auto_fit: return ELM_PHOTOCAM_ZOOM_MODE_AUTO_FIT;
                case Val_auto_fill: return ELM_PHOTOCAM_ZOOM_MODE_AUTO_FILL;
                case Val_auto_fit_in: return ELM_PHOTOCAM_ZOOM_MODE_AUTO_FIT_IN;
                case Val_last: return ELM_PHOTOCAM_ZOOM_MODE_LAST;
                default: break;
        }
        caml_failwith("Elm_Photocam_Zoom_Mode_val");
        return ELM_PHOTOCAM_ZOOM_MODE_MANUAL;
}

PREFIX inline value Val_Elm_Photocam_Zoom_Mode(Elm_Photocam_Zoom_Mode m)
{
        switch(m) {
                case ELM_PHOTOCAM_ZOOM_MODE_MANUAL: return Val_manual;
                case ELM_PHOTOCAM_ZOOM_MODE_AUTO_FIT: return Val_auto_fit;
                case ELM_PHOTOCAM_ZOOM_MODE_AUTO_FILL: return Val_auto_fill;
                case ELM_PHOTOCAM_ZOOM_MODE_AUTO_FIT_IN: return Val_auto_fit_in;
                case ELM_PHOTOCAM_ZOOM_MODE_LAST: return Val_last;
        }
        caml_failwith("Val_Elm_Photocam_Zoom_Mode");
        return Val_manual;
}

PREFIX value ml_elm_photocam_add(value v_parent)
{
        Evas_Object* photocam = elm_photocam_add((Evas_Object*) v_parent);
        if(photocam == NULL) caml_failwith("elm_photocam_add");
        return (value) photocam;
}

PREFIX value ml_elm_photocam_file_set(value v_obj, value v_file)
{
        return Val_Evas_Load_Error(elm_photocam_file_set(
                (Evas_Object*) v_obj, String_val(v_file)));
}

PREFIX value ml_elm_photocam_file_get(value v_obj)
{
        const char* file = elm_photocam_file_get((Evas_Object*) v_obj);
        if(file == NULL) caml_failwith("elm_photocam_file_get");
        return copy_string(file);
}

PREFIX value ml_elm_photocam_zoom_set(value v_obj, value v_x)
{
        elm_photocam_zoom_set((Evas_Object*) v_obj, Double_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_photocam_zoom_get(value v_obj)
{
        return copy_double(elm_photocam_zoom_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_photocam_zoom_mode_set(value v_obj, value v_mode)
{
        elm_photocam_zoom_mode_set((Evas_Object*) v_obj,
                Elm_Photocam_Zoom_Mode_val(v_mode));
        return Val_unit;
}

PREFIX value ml_elm_photocam_zoom_mode_get(value v_obj)
{
        return Val_Elm_Photocam_Zoom_Mode(elm_photocam_zoom_mode_get(
                (Evas_Object*) v_obj));
}

