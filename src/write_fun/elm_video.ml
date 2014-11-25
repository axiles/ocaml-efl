open Common

let funs = [
  simple "file_set" [evas_object; safe_string] bool;
  simple "emotion_get" [evas_object] evas_object;
  simple_unit "play" [evas_object];
  simple_unit "pause" [evas_object];
  simple_unit "stop" [evas_object];
  simple "is_playing_get" [evas_object] bool;
  simple "is_seekable_get" [evas_object] bool;
  prop "audio_mute" bool;
  prop "audio_level" double;
  prop "play_position" double;
  simple "play_length_get" [evas_object] double;
  prop "remember_position" bool;
  simple "title_get" [evas_object] safe_string;
]

