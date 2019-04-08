/*-- Neues Szenario --*/

#strict

func Initialize() {
   
  return(1);
}


func Geld() {
  SetWealth(GetPlayerByIndex(0), GetWealth(GetPlayerByIndex(0)) + 7000);
  Message("Und noch mehr Gold");
  return(0);
}
