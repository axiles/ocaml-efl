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

