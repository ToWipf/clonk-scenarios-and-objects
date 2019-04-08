/*-- Fahrstuhlkorb --*/

#strict
#include ELEC


protected func Timer() 
{
  timer = (++timer) % 30;
  // Lore fassen
  GrabObjects();
  // Clonks umgreifen lassen
  ChangeClonkGrabs();
  // Feststecken -> Schachtbohrung
  if (Stuck() && GetComDir() != COMD_Stop())
    if (!NoEnergy())
      DigFreeRect(GetX() - 30, GetY() - 13, 60, 26);
  if (!timer) Activity();
}

private func FindWaitingClonk()
{
  var clnk, best, proc;
  while(clnk = FindObject(0, -45, RangeTop - GetY(), 150, 6000, OCF_CrewMember, 0, 0, NoContainer(), clnk) )
  {
    proc = GetProcedure(clnk);
    if(GetComDir(clnk) == COMD_Stop || (proc eq "SWIM" && Inside(GetXDir(clnk), -5, 5)) )
    {
      if(proc eq "WALK" || proc eq "PUSH" || proc eq "SCALE" || proc eq "HANGLE" || proc eq "SWIM")
        if(!Hostile(GetController(clnk), GetOwner()) )
        {
          // Nicht erreichbar?
          if(GetY(clnk) < GetY() - 7) if(!PathFree(GetX(), GetY(), GetX(), GetY(clnk)) ) continue;
          if(GetY(clnk) > GetY() + 7) if(!PathFree(GetX(), GetY() + 16, GetX(), GetY(clnk)) ) continue;
          // Priorität prüfen (Cursor hat Priorität, sonst nächster Clonk)
          if(!best)
            best = clnk;
          else if(GetCursor(GetController(clnk)) == clnk)
            best = clnk;
          else if(GetCursor(GetController(best)) != best)
            if(ObjectDistance(clnk) < ObjectDistance(best))
              best = clnk;
        }
    }
  }
  return best;
}

private func FitsInElevator(pObject)
{
  // Alle (ungedrehten) Vertices des Objekts prüfen
  var vertexCount = GetDefCoreVal("Vertices", "DefCore", pObject->GetID());
  for (var i = 0; i < vertexCount; i++) 
  {
    var vertexX = GetDefCoreVal("VertexX", "DefCore", pObject->GetID(), i);
    var vertexY = GetDefCoreVal("VertexY", "DefCore", pObject->GetID(), i);
    // Passt nicht
    if (!Inside(vertexX, -30, 11) || !Inside(vertexY, -20, 15)) return(0);
  }
  // Passt
  return(1);  
}

private func Passenger()
{
  // Clonk finden
  var clnk = FindObject(0, -30,-13,60,20, OCF_CrewMember(),0,0,NoContainer());
  if(!clnk) return (0);
  // steht wirklich auf dem Fahrstuhl?
  if(GetProcedure(clnk) ne "WALK") return (0);
  return (clnk);
}

protected func UpdateTransferZone()
{         
  if (!Elevator()) return(SetTransferZone());
  SetTransferZone(-30, GetY(oElev) - GetY(), 60, RangeBottom - GetY(oElev) + 12);
  return(1);
}


private func Drilling()
{
  // Steuermann verloren? Suche schiebenden Clonk selbst wenn er ein Fahrzeug im Fahrstuhlkorb schiebt (->Lore)
  var elev = Elevator();
  if (!elev) return Halt();
  if (!FindObject2(Find_InRect(-30,-12,60,24), Find_Action("Push")))
    return Halt();
  // Energieverbrauch
  if (ObjectCount(ENRG))
    if (EnergyCheck(10000, elev))
      DoEnergy(-10000, elev, true);
    else
      Halt();
  return(1);
}

