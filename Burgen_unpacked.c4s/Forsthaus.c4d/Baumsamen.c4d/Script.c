/*-- Samen --*/

#strict

local idTree;

protected func Hit()
{
  if(ActIdle(this)) SetAction("Decay");
  Sound("WoodHit*");
}

protected func Initialize()
{
  SetAction("Decay");
  return(1);
}

protected func Activate(pObj)
{
  var ID= idTree,i= Random(4);
  if(ID== RMMG)
    {
    if(i== 0) ID= TRE1;
    if(i== 1) ID= TRE2;
    if(i== 2) ID= TRE3;
    if(i== 3) ID= TRE4;
    }
  // Ist noch Platz für einen Baum?
  var iSize= DefinitionCall(ID,"ReproductionAreaSize"),iOffset= iSize/ -2;
  if(!(pObj-> ObjectCount(0,iOffset,iOffset,iSize,iSize,OCF_Chop())< DefinitionCall(ID,"MaxTreeCount")))
   return(Message("Hier hat kein Baum mehr Platz!",pObj));
  ObjectSetAction(pObj,"Bridge");
  pObj-> CreateConstruction(ID,0,+15,-1,5);
  RemoveObject();
  return(1);
}


/* Vertrocknung */

private func Decaying()
{
  DoCon(-1);
}
