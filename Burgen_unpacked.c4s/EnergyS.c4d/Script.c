/*-- EnergySammler --*/

#strict
	local energie;
 
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

private func Initialize() {
	SetAction("Energi1");
}

private func Setenergie(tmp) {
	energie=tmp;
}
 
private func AddEnergie(pClonk) {
	
	var iPlr= GetOwner(pClonk);
	var derzeitigesgeld= GetWealth(iPlr);
  
	if(GetWealth(iPlr)< 150) {
		Message("150 Gold noetig",this());
		Sound("Error");		
	}	
	else {
		SetWealth(iPlr,derzeitigesgeld - 150);
		Sound("uncash");
		Setenergie(energie+1503);
	}
}

private func GetEnergyStatus() {
	Message("Es ist %d Energie geladen", this(), energie);
}

private func Energie() {
	EnerieStatus();

	if(GetMaterial( 0, 0) == Material("Water"))
		Kurtzer();

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

private func EnerieStatus() {

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
}

private func Kurtzer() {
	energie = 0;
	Sound("Electrify");
	CastParticles("MSpark", 10, 10, -10, -9, 10, 50, RGB(RandomX(100, 150), RandomX(200, 255), 255), RGB(RandomX(100, 150), RandomX(200, 255), 255));
	CastParticles("MSpark", 10, 10, +10, -9, 10, 50, RGB(RandomX(100, 150), RandomX(200, 255), 255), RGB(RandomX(100, 150), RandomX(200, 255), 255));
	CastParticles("MSpark", 10, 10, -13, +9, 10, 50, RGB(RandomX(100, 150), RandomX(200, 255), 255), RGB(RandomX(100, 150), RandomX(200, 255), 255));
	CastParticles("MSpark", 10, 10, +8, +9, 10, 50, RGB(RandomX(100, 150), RandomX(200, 255), 255), RGB(RandomX(100, 150), RandomX(200, 255), 255));
	var pClonk;
}

private func IsBigPowerSupplier() { 
	return(1);
}

private func IsBigPowerSaver() {
	return(1);
}

private func GetBigPower() {
	return(energie);
}
	
private func DoBigPower(int ichange) {
	energie += ichange; return(1);
}

/*Menue*/
/*Energie kaufen*/
public func ContextBuyEngergy(pClonk) {
  ["Energie kaufen (150)"|Image=ENSS:0|Condition=IsBuilt]
  AddCommand(pClonk,"Call",this(),pClonk,0,0,0,"AddEnergie");
}

//Energie abfragen

public func ContextGetEngergieStatus(pClonk) {
  ["Energie status"|Image=ENSS:1|Condition=IsBuilt]
  AddCommand(pClonk,"Call",this(),0,0,0,0,"GetEnergyStatus");
}
