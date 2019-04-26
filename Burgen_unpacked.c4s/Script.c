/*-- Neues Szenario --*/

#strict

func Initialize() {
  return(1);
}

func Money() {
  SetWealth(GetPlayerByIndex(0), 7000);
  SetWealth(GetPlayerByIndex(1), 7000);
  SetWealth(GetPlayerByIndex(2), 7000);
  SetWealth(GetPlayerByIndex(3), 7000);
  SetWealth(GetPlayerByIndex(4), 7000);
  SetWealth(GetPlayerByIndex(5), 7000);
  SetWealth(GetPlayerByIndex(6), 7000);
  SetWealth(GetPlayerByIndex(7), 7000);
  SetWealth(GetPlayerByIndex(8), 7000);
  SetWealth(GetPlayerByIndex(9), 7000);
  SetWealth(GetPlayerByIndex(10), 7000);
  SetWealth(GetPlayerByIndex(11), 7000);
  return(1);
}


func Geld() {
  SetWealth(GetPlayerByIndex(0), GetWealth(GetPlayerByIndex(0)) + 7000);
  Message("Und noch mehr Gold");
  return(0);
}
