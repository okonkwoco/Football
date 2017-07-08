#include <random>
class PlayerAttributes {
protected:
	int Strength;
	int Agility;
	int Speed;
	int Acceleration;
	int Stamina;
	int Awareness;
	int Jumping;
	int Injury;
	int Toughness;
	
	int ThrowPower;
	int ThrowAccuracy;
	int ShortThrowAccuracy;
	int MediumThrowAccuracy;
	int DeepThrowAccuracy;
	int ThrowOnTheRun;
	int PlayAction;

	int Trucking;
	int Elusiveness;
	int BallCarrierVision;
	int StiffArm;
	int SpinMove;
	int JukeMove;
	int Carrying;
	
	int Catching;
	int CatchInTraffic;
	int RouteRunning;
	int SpectacularCatch;
	int Release;

	int Tackle;
	int HitPower;
	int FinesseMoves;
	int PowerMoves;
	int BlockShedding;
	int Pursuit;
	int ManCoverage;
	int ZoneCoverage;
	int PlayRecognition;
	int Press;
	
	int PassBlock;
	int RunBlock;
	int ImpactBlock;

	int KickPower;
	int KickAccuracy;

	int Return;
	int Potential;
	std::default_random_engine generator;
	std::uniform_real_distribution<double> PotentialModifier{ Potential*.01 - .05, Potential*.01 + .05 };
	double potmod = PotentialModifier(generator);

};

class Quarterback : public PlayerAttributes {
	virtual int overall() {
		return (Agility * .03 + Speed * .05 + Acceleration * .01 + Awareness * .12 + ThrowPower * .26 + ShortThrowAccuracy * .18 + MediumThrowAccuracy * .18 + DeepThrowAccuracy * .12 + ThrowOnTheRun * .02 + PlayAction * .04);
	}
	virtual void youngDevelopment() {

		if (overall() < Potential) {
			Agility = Agility * (1 + PotentialModifier(generator)) *1.015;
			Speed = Speed * (1 + PotentialModifier(generator)) *1.025;
			Acceleration = Acceleration * (1 + PotentialModifier(generator)) *1.005;
			Awareness = Awareness * (1 + PotentialModifier(generator)) *1.36;
			ThrowPower = ThrowPower * (1 + PotentialModifier(generator)) *1.12;
			ShortThrowAccuracy = ShortThrowAccuracy * (1 + PotentialModifier(generator)) *1.36;
			MediumThrowAccuracy = MediumThrowAccuracy * (1 + PotentialModifier(generator)) *1.36;
			DeepThrowAccuracy = DeepThrowAccuracy * (1 + PotentialModifier(generator)) *1.18;
			ThrowOnTheRun = ThrowOnTheRun * (1 + PotentialModifier(generator)) *1.04;
			PlayAction = PlayAction * (1 + PotentialModifier(generator)) *1.08;
		}
	}
	virtual void primeDevelopment() {
		//later
	}
};