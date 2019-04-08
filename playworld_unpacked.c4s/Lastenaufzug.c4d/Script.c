/*-- Lastenaufzug --*/

#strict

private func BasementID() { return(GetID()); }

#include CXEC
#include ELEV

protected Incineration:
  if(pCase) RemoveObject(pCase);
  SetClrModulation (RGB(48, 32, 32));
  SetName("...",this(),0);
  if(pCase) RemoveObject(pCase);
  return(1);

Completion:
  SetClrModulation (RGB(255, 255, 255));
  SetName(GetName(,GetID(this())),this(),0);
  return(1);

protected func Initialize()
{
  pCase = CreateObject(LC0S,+0,+27,GetOwner());
  SetObjectOrder(this(), pCase);
  SetAction("LiftCase",pCase);
  return(1);
}
