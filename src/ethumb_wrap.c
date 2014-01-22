#include "ethumb_wrap.h"

PREFIX inline Ethumb_Thumb_Aspect Ethumb_Thumb_Aspect_val(value v)
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

PREFIX inline value Val_Ethumb_Thumb_Aspect(Ethumb_Thumb_Aspect a)
{
        switch(a) {
                case ETHUMB_THUMB_KEEP_ASPECT: return Val_keep_aspect;
                case ETHUMB_THUMB_IGNORE_ASPECT: return Val_ignore_aspect;
                case ETHUMB_THUMB_CROP: return Val_crop;
        }
        caml_failwith("Val_Ethumb_Thumb_Aspect");
        return Val_keep_aspect;
}

PREFIX inline Ethumb_Thumb_FDO_Size Ethumb_Thumb_FDO_Size_val(value v)
{
        switch(v) {
                case Val_normal: return ETHUMB_THUMB_NORMAL;
                case Val_large: return ETHUMB_THUMB_LARGE;
                default: break;
        }
        caml_failwith("Ethumb_Thumb_FDO_Size_val");
        return ETHUMB_THUMB_NORMAL;
}

PREFIX inline value Val_Ethumb_Thumb_FDO_Size(Ethumb_Thumb_FDO_Size s)
{
        switch(s) {
                case ETHUMB_THUMB_NORMAL: return Val_normal;
                case ETHUMB_THUMB_LARGE: return Val_large;
        }
        caml_failwith("Val_Ethumb_Thumb_FDO_Size");
        return Val_normal;
}

PREFIX inline Ethumb_Thumb_Format Ethumb_Thumb_Format_val(value v)
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

PREFIX inline value Val_Ethumb_Thumb_Format(Ethumb_Thumb_Format f)
{
        switch(f) {
                case ETHUMB_THUMB_FDO: return Val_fdo;
                case ETHUMB_THUMB_JPEG: return Val_jpeg;
                case ETHUMB_THUMB_EET: return Val_eet;
        }
        caml_failwith("Val_Ethumb_Thumb_Format");
        return Val_fdo;
}

