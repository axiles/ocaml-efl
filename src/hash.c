#include <stdio.h>
#include <caml/mlvalues.h>
#include <caml/alloc.h>

CAMLprim value ml_get_hash_value(value v_name) {
        char s[255];
        sprintf(s, "%d", (int) caml_hash_variant(String_val(v_name)));
        return copy_string(s);
}

