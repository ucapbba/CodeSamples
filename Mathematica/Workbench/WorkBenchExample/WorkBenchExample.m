(*Some Mathemtica functions*)
Add[x_, y_] := x + y
DisplayAdd[Ip1_, Ip2_] := Module[{},
  Print[StringJoin[
    StringJoin[StringJoin["Adding ",  ToString[Ip1]], " and "], 
    ToString[Ip2]]];
  Print[StringJoin["gives ", ToString[Add[1, 2]]]];
  ]


