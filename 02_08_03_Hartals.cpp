#ifndef Hartals_CPP
#define Hartals_CPP
class Hartals:public IOPipeline {
	public:
		struct HartalsInput {
			int numberOfDays_;
			int numberOfPoliticalParties_;
			vector <int> hartalsPerParty_;
		};
		Hartals() {}
		~Hartals() {}
		virtual void readInput() {
			cin>>numberOfTestCases_;
			int i=0;
			while ( i < numberOfTestCases_ ) {
				i++;
				HartalsInput hartalsInput;
				int numberOfDays;
				cin >> numberOfDays;
				if ( numberOfDays < 7 || numberOfDays > 3650 )
		       			cout<<"numberOfDays invalid"<<endl;	
				hartalsInput.numberOfDays_=numberOfDays;
				int numberOfPoliticalParties;
				cin>>numberOfPoliticalParties;
				if ( numberOfPoliticalParties < 1 || numberOfPoliticalParties > 100 )
		       			cout<<"numberOfPoliticalParties invalid"<<endl;	
				hartalsInput.numberOfPoliticalParties_=numberOfPoliticalParties;
				int j=0;
				while ( j<numberOfPoliticalParties ) {
					j++;	
					int hartalsPerParty;
					cin>>hartalsPerParty;
					hartalsInput.hartalsPerParty_.push_back(hartalsPerParty);
				}
			   	hartalsInput_.push_back(hartalsInput);     	
			}
		}
		virtual void processData() {
		}
		virtual void writeOutput() {
			IOLOG(hartalsInput_.size());
		}
	private:
		int numberOfTestCases_;
		vector < HartalsInput > hartalsInput_;
};
#endif
