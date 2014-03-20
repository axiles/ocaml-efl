let player_add = Elm.player_add

external add : Evas.obj -> Evas.obj = "ml_elm_video_add"

let addx = Elm_object.create_addx add

external file_set : Evas.obj -> string -> bool = "ml_elm_video_file_set"

external emotion_get : Evas.obj -> Evas.obj = "ml_elm_video_emotion_get"

external play : Evas.obj -> unit = "ml_elm_video_play"

external pause : Evas.obj -> unit = "ml_elm_video_pause"

external stop : Evas.obj -> unit = "ml_elm_video_stop"

external is_playing_get : Evas.obj -> bool = "ml_elm_video_is_playing_get"

external is_seekable_get : Evas.obj -> bool = "ml_elm_video_is_seekable_get"

external audio_mute_get : Evas.obj -> bool = "ml_elm_video_audio_mute_get"

external audio_mute_set : Evas.obj -> bool -> unit =
  "ml_elm_video_audio_mute_set"

external audio_level_get : Evas.obj -> float = "ml_elm_video_audio_level_get"

external audio_level_set : Evas.obj -> float -> unit =
  "ml_elm_video_audio_level_get"

external play_position_get : Evas.obj -> float =
  "ml_elm_video_play_position_get"

external play_position_set : Evas.obj -> float -> unit =
  "ml_elm_video_play_position_get"

external play_length_get : Evas.obj -> float = "ml_elm_video_play_length_get"

external remember_position_set : Evas.obj -> bool -> unit =
  "ml_elm_video_remember_position_set"

external remember_position_get : Evas.obj -> bool =
  "ml_elm_video_remember_position_get"

external title_get : Evas.obj -> string = "ml_elm_video_title_get"

