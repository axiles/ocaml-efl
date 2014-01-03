#include "include.h"

PREFIX inline value copy_Elm_Font_Properties(Elm_Font_Properties* p)
{
        CAMLparam0();
        CAMLlocal1(v);
        Store_field(v, 0, copy_string(p->name));
        Store_field(v, 1, copy_Eina_List_string(p->styles));
        CAMLreturn(v);
}

