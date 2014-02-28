#include "ethumb_wrap.h"

inline Ethumb_Thumb_Aspect Ethumb_Thumb_Aspect_val(value v)
{
        switch(v) {
                case Val_keep_aspect: return ETHUMB_THUMB_KEEP_ASPECT;
                case Val_ignore_aspect: return ETHUMB_THUMB_IGNORE_ASPECT;
                case Val_crop: return ETHUMB_THUMB_CROP;
                default: break;
        }
        caml_failwith("Ethumb_Thumb_Aspect_val");
        return ETHUMB_THUMB_KEEP_ASPECT;
}

inline value Val_Ethumb_Thumb_Aspect(Ethumb_Thumb_Aspect a)
{
        switch(a) {
                case ETHUMB_THUMB_KEEP_ASPECT: return Val_keep_aspect;
                case ETHUMB_THUMB_IGNORE_ASPECT: return Val_ignore_aspect;
                case ETHUMB_THUMB_CROP: return Val_crop;
        }
        caml_failwith("Val_Ethumb_Thumb_Aspect");
        return Val_keep_aspect;
}

inline Ethumb_Thumb_FDO_Size Ethumb_Thumb_FDO_Size_val(value v)
{
        switch(v) {
                case Val_normal: return ETHUMB_THUMB_NORMAL;
                case Val_large: return ETHUMB_THUMB_LARGE;
                default: break;
        }
        caml_failwith("Ethumb_Thumb_FDO_Size_val");
        return ETHUMB_THUMB_NORMAL;
}

inline value Val_Ethumb_Thumb_FDO_Size(Ethumb_Thumb_FDO_Size s)
{
        switch(s) {
                case ETHUMB_THUMB_NORMAL: return Val_normal;
                case ETHUMB_THUMB_LARGE: return Val_large;
        }
        caml_failwith("Val_Ethumb_Thumb_FDO_Size");
        return Val_normal;
}

inline Ethumb_Thumb_Format Ethumb_Thumb_Format_val(value v)
{
        switch(v) {
                case Val_fdo : return ETHUMB_THUMB_FDO;
                case Val_jpeg: return ETHUMB_THUMB_JPEG;
                case Val_eet: return ETHUMB_THUMB_EET;
                default: break;
        }
        caml_failwith("Ethumb_Thumb_Format_val");
        return ETHUMB_THUMB_FDO;
}

inline value Val_Ethumb_Thumb_Format(Ethumb_Thumb_Format f)
{
        switch(f) {
                case ETHUMB_THUMB_FDO: return Val_fdo;
                case ETHUMB_THUMB_JPEG: return Val_jpeg;
                case ETHUMB_THUMB_EET: return Val_eet;
        }
        caml_failwith("Val_Ethumb_Thumb_Format");
        return Val_fdo;
}

inline Ethumb_Thumb_Orientation Ethumb_Thumb_Orientation_val(value v)
{
        switch(v) {
                case Val_orient_none: return ETHUMB_THUMB_ORIENT_NONE;
                case Val_rotate_90_cw: return ETHUMB_THUMB_ROTATE_90_CW;
                case Val_rotate_180: return ETHUMB_THUMB_ROTATE_180;
                case Val_rotate_90_ccw: return ETHUMB_THUMB_ROTATE_90_CCW;
                case Val_flip_horizontal: return ETHUMB_THUMB_FLIP_HORIZONTAL;
                case Val_flip_vertical: return ETHUMB_THUMB_FLIP_VERTICAL;
                case Val_flip_transpose: return ETHUMB_THUMB_FLIP_TRANSPOSE;
                case Val_flip_transverse: return ETHUMB_THUMB_FLIP_TRANSVERSE;
                case Val_orient_original: return ETHUMB_THUMB_ORIENT_ORIGINAL;
                default: break;
        }
        caml_failwith("Ethumb_Thumb_Orientation_val");
        return ETHUMB_THUMB_ORIENT_NONE;
}

inline value Val_Ethumb_Thumb_Orientation(Ethumb_Thumb_Orientation o)
{
        switch(o) {
                case ETHUMB_THUMB_ORIENT_NONE: return Val_orient_none;
                case ETHUMB_THUMB_ROTATE_90_CW: return Val_rotate_90_cw;
                case ETHUMB_THUMB_ROTATE_180: return Val_rotate_180;
                case ETHUMB_THUMB_ROTATE_90_CCW: return Val_rotate_90_ccw;
                case ETHUMB_THUMB_FLIP_HORIZONTAL: return Val_flip_horizontal;
                case ETHUMB_THUMB_FLIP_VERTICAL: return Val_flip_vertical;
                case ETHUMB_THUMB_FLIP_TRANSPOSE: return Val_flip_transpose;
                case ETHUMB_THUMB_FLIP_TRANSVERSE: return Val_flip_transverse;
                case ETHUMB_THUMB_ORIENT_ORIGINAL: return Val_orient_original;
        }
        caml_failwith("Val_Ethumb_Thumb_Orientation");
        return Val_orient_none;
}

