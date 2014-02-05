#include "include.h"

PREFIX inline Elm_GLView_Mode Elm_GLView_Mode_val(value v)
{
        switch(v) {
                case Val_none: return ELM_GLVIEW_NONE;
                case Val_alpha: return ELM_GLVIEW_ALPHA;
                case Val_depth: return ELM_GLVIEW_DEPTH;
                case Val_stencil: return ELM_GLVIEW_STENCIL;
                case Val_direct: return ELM_GLVIEW_DIRECT;
                default: break;
        }
        caml_failwith("Elm_GLView_Mode_val");
        return ELM_GLVIEW_NONE;
}

PREFIX inline Elm_GLView_Mode Elm_GLView_Mode_val_list(value v)
{
        value v_tmp = v;
        Elm_GLView_Mode m = ELM_GLVIEW_NONE;
        while(v_tmp != Val_int(0)) {
                m = m | Elm_GLView_Mode_val(Field(v_tmp, 0));
                v_tmp = Field(v_tmp, 1);
        }
        return m;
}

PREFIX inline Elm_GLView_Resize_Policy Elm_GLView_Resize_Policy_val(value v)
{
        switch(v) {
                case Val_recreate: return ELM_GLVIEW_RESIZE_POLICY_RECREATE;
                case Val_scale: return ELM_GLVIEW_RESIZE_POLICY_SCALE;
                default: break;
        }
        caml_failwith("Elm_GLView_Resize_Policy_val");
        return ELM_GLVIEW_RESIZE_POLICY_RECREATE;
}

PREFIX inline Elm_GLView_Render_Policy Elm_GLView_Render_Policy_val(value v)
{
        switch(v) {
                case Val_on_demand: return ELM_GLVIEW_RENDER_POLICY_ON_DEMAND;
                case Val_always: return ELM_GLVIEW_RENDER_POLICY_ALWAYS;
                default: break;
        }
        caml_failwith("Elm_GLView_Render_Policy_val");
        return ELM_GLVIEW_RENDER_POLICY_ON_DEMAND;
}

void ml_Elm_GLView_Func_Cb_init(Evas_Object* obj)
{
        static value* v_fun = NULL;
        if(v_fun == NULL) v_fun = caml_named_value("Elm_GLView_Func_Cb_init");
        caml_callback(*v_fun, (value) obj);
}

void ml_Elm_GLView_Func_Cb_del(Evas_Object* obj)
{
        static value* v_fun = NULL;
        if(v_fun == NULL) v_fun = caml_named_value("Elm_GLView_Func_Cb_del");
        caml_callback(*v_fun, (value) obj);
}

void ml_Elm_GLView_Func_Cb_resize(Evas_Object* obj)
{
        static value* v_fun = NULL;
        if(v_fun == NULL) v_fun = caml_named_value("Elm_GLView_Func_Cb_resize");
        caml_callback(*v_fun, (value) obj);
}

void ml_Elm_GLView_Func_Cb_render(Evas_Object* obj)
{
        static value* v_fun = NULL;
        if(v_fun == NULL) v_fun = caml_named_value("Elm_GLView_Func_Cb_render");
        caml_callback(*v_fun, (value) obj);
}

PREFIX value ml_elm_glview_add(value v_parent)
{
        Evas_Object* obj = elm_glview_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_glview_add");
        elm_glview_init_func_set(obj , ml_Elm_GLView_Func_Cb_init);
        elm_glview_del_func_set(obj , ml_Elm_GLView_Func_Cb_del);
        elm_glview_resize_func_set(obj , ml_Elm_GLView_Func_Cb_resize);
        elm_glview_render_func_set(obj , ml_Elm_GLView_Func_Cb_render);
        return (value) obj;
}

PREFIX value ml_elm_glview_size_set(value v_obj, value v_w, value v_h)
{
        elm_glview_size_set((Evas_Object*) v_obj, Int_val(v_w), Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_elm_glview_size_get(value v_obj)
{
        Evas_Coord w, h;
        elm_glview_size_get((Evas_Object*) v_obj, &w, &h);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(w));
        Store_field(v_r, 1, Val_int(h));
        return v_r;
}

PREFIX value ml_elm_glview_gl_api_get(value v_obj)
{
        return (value) elm_glview_gl_api_get((Evas_Object*) v_obj);
}

PREFIX value ml_elm_glview_mode_set(value v_obj, value v_m)
{
        elm_glview_mode_set((Evas_Object*) v_obj,
                Elm_GLView_Mode_val_list(v_m));
        return Val_unit;
}

PREFIX value ml_elm_glview_resize_policy_set(value v_obj, value v_p)
{
        return Val_bool(elm_glview_resize_policy_set((Evas_Object*) v_obj,
                Elm_GLView_Resize_Policy_val(v_p)));
}

PREFIX value ml_elm_glview_render_policy_set(value v_obj, value v_p)
{
        return Val_bool(elm_glview_render_policy_set((Evas_Object*) v_obj,
                Elm_GLView_Render_Policy_val(v_p)));
}

PREFIX value ml_elm_glview_changed_set(value v_obj)
{
        elm_glview_changed_set((Evas_Object*) v_obj);
        return Val_unit;
}

