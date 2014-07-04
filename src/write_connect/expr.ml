module Signal = struct
  type ty = Unit | Arg of string | Ref of string
  type t = {name : string; ty : ty}
end

type t = {name : string; signals : Signal.t list}

