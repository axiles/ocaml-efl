#include "include.h"

PREFIX inline Eina_Bool Eina_Bool_val(value v) {
        return (Eina_Bool) Int_val(v);
}

PREFIX inline value Val_Eina_Bool(Eina_Bool b) {
        return Val_int (b);
}

