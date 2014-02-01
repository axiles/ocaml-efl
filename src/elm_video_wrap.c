#include "include.h"

PREFIX value ml_elm_player_add(value v_parent)
{
        Evas_Object* player = elm_player_add((Evas_Object*) v_parent);
        if(player == NULL) caml_failwith("elm_player_add");
        return (value) player;
}

PREFIX value ml_elm_video_add(value v_parent)
{
        Evas_Object* video = elm_video_add((Evas_Object*) v_parent);
        if(video == NULL) caml_failwith("elm_video_add");
        return (value) video;
}

PREFIX value ml_elm_video_file_set(value v_obj, value v_file)
{
        return Val_bool(elm_video_file_set((Evas_Object*) v_obj,
                String_val(v_file)));
}

PREFIX value ml_elm_video_emotion_get(value v_obj)
{
        return (value) elm_video_emotion_get((Evas_Object*) v_obj);
}

PREFIX value ml_elm_video_play(value v_obj)
{
        elm_video_play((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_video_pause(value v_obj)
{
        elm_video_pause((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_video_stop(value v_obj)
{
        elm_video_stop((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_video_is_playing_get(value v_obj)
{
        return Val_bool(elm_video_is_playing_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_video_is_seekable_get(value v_obj)
{
        return Val_bool(elm_video_is_seekable_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_video_audio_mute_get(value v_obj)
{
        return Val_bool(elm_video_audio_mute_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_video_audio_mute_set(value v_obj, value v_flag)
{
        elm_video_audio_mute_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

