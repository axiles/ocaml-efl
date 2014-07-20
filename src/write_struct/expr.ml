module Field = struct
  type t = {
    name : string;
    ty : string;
  }
end

type field = Field.t

module St = struct
  type t = {
    ml_name : string;
    c_name : string;
    modu : bool;
    ptr : bool;
    fields : field list;
  }
end

type st = St.t

module Section = struct
  type t = {
    name : string;
    sts : st list;
  }
end

type section = Section.t

type t = section list

