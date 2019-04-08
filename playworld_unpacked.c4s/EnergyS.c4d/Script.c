/*-- EnergySammler --*/

#strict
   local energie;
   local aus;
#include BAS4

protected Incineration:
  SetClrModulation (RGB(48, 32, 32));
  SetName(Format("%s (Verbrannt)",GetName(,GetID(this)) ),this);
  return(1);

Completion:
  SetClrModulation (RGB(255, 255, 255));
  SetName(GetName(,GetID(this)),this);
  return(1);

public func GetResearchPriority() { return(2); }

/* Initialisierung */


private func Initialize(){
   SetAction("Energi1");
   }

private func setenergie(tmp){
   energie=tmp;
   }
   
private func Energie(){
   EnerieStatus();
   if(aus==0)
   if(GetMaterial( 0, 0) == Material("Water")) Kurtzer();
   //Log("abc");
   if(GetMaterial( 0, 0) != Material("Water")) aus=0;
   
   if(aus>=1) return(0);
  //Message("%d||||",this(),GetEnergy());
  
   //aufladen
   //wen genug Energie da ist etwas Speichern
  if(energie <= 500000)
    if(GetEnergy()>=70)
       if(DoEnergy(-40))
         energie+=1;

    //wenn zu wenig Energie da ist wieder was abgeben
    if(GetEnergy()<=50)
         if(energie>=1)
          if(DoEnergy(+40))
            energie-=1;

       }

private func EnerieStatus(){

  if(energie <= 1500)
     SetAction("Energi1");

  if(energie >= 1500 && energie < 3000)
     SetAction("Energi2");

  if(energie >= 3000 && energie < 6000)
     SetAction("Energi3");

  if(energie >= 6000 && energie < 10000)
     SetAction("Energi4");

  if(energie >= 10000)
     SetAction("Energi5");

  // Ab und zu mal
  
  // eben nicht da sinlos TF
  /*
  if(energie >= ((maximum/4)*2)) {

  if (!Random(450))
    if(Sound("Electrify"))
      CastParticles("MSpark", 10, 10, -10, -7, 10, 50, RGB(RandomX(100, 150), RandomX(200, 255), 255), RGB(RandomX(100, 150), RandomX(200, 255), 255));
   
  if (!Random(595))
    if(Sound("Electrify"))
      CastParticles("MSpark", 10, 10, +10, -9, 10, 50, RGB(RandomX(100, 150), RandomX(200, 255), 255), RGB(RandomX(100, 150), RandomX(200, 255), 255));
   }
   */
}

private func Kurtzer(){
   aus = 5;
   energie = 0;
    Sound("Electrify");
      CastParticles("MSpark", 10, 10, -10, -9, 10, 50, RGB(RandomX(100, 150), RandomX(200, 255), 255), RGB(RandomX(100, 150), RandomX(200, 255), 255));
   
      CastParticles("MSpark", 10, 10, +10, -9, 10, 50, RGB(RandomX(100, 150), RandomX(200, 255), 255), RGB(RandomX(100, 150), RandomX(200, 255), 255));
   
      CastParticles("MSpark", 10, 10, -13, +9, 10, 50, RGB(RandomX(100, 150), RandomX(200, 255), 255), RGB(RandomX(100, 150), RandomX(200, 255), 255));
   
      CastParticles("MSpark", 10, 10, +8, +9, 10, 50, RGB(RandomX(100, 150), RandomX(200, 255), 255), RGB(RandomX(100, 150), RandomX(200, 255), 255));
   
 var pClonk;

 /*
 while(pClonk=FindObject(0, -100,-100,200,200, OCF_CrewMember(), 0,0, NoContainer(),pClonk))
  {
    Punch(pClonk,5);
   // Blitze!!!
    CastParticles("MSpark", 20, 30, AbsX(GetX(pClonk)), AbsY(GetY(pClonk)), 10, 50, RGB(RandomX(100, 150), RandomX(200, 255), 255), RGB(RandomX(100, 150), RandomX(200, 255), 255));
  }
  
 
 while(pClonk=FindObject(0, -200,-200,400,400, OCF_CrewMember(), 0,0, NoContainer(),pClonk))
  {
    Punch(pClonk,5);
   // Blitze!!!
    CastParticles("MSpark", 20, 30, AbsX(GetX(pClonk)), AbsY(GetY(pClonk)), 10, 50, RGB(RandomX(100, 150), RandomX(200, 255), 255), RGB(RandomX(100, 150), RandomX(200, 255), 255));
  }
  
 
 while(pClonk=FindObject(0, -300,-300,600,600, OCF_CrewMember(), 0,0, NoContainer(),pClonk))
  {
    Punch(pClonk,5);
   // Blitze!!!
    CastParticles("MSpark", 20, 30, AbsX(GetX(pClonk)), AbsY(GetY(pClonk)), 10, 50, RGB(RandomX(100, 150), RandomX(200, 255), 255), RGB(RandomX(100, 150), RandomX(200, 255), 255));
  }
   */

}




/*
ABC:
var pClonk;
 while(pClonk=FindObject(0, -400,-400,800,800, OCF_CrewMember(), 0,0, NoContainer(),pClonk))
  {
    //Punch(pClonk,20);
   // Blitze!!!
    
    CastParticles("MSpark", 20, 40, AbsX(GetX(pClonk)), AbsY(GetY(pClonk)), 10, 50, RGB(RandomX(100, 150), RandomX(200, 255), 255), RGB(RandomX(100, 150), RandomX(200, 255), 255));
   }
  return();
*/


private func IsBigPowerSupplier() { return(1); }
private func IsBigPowerSaver() { return(1); }
private func GetBigPower() { return(energie); }
private func DoBigPower(int ichange) { energie += ichange; return(1); }






