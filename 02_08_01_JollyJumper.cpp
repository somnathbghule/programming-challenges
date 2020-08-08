#include <IOPipeline.h>

class JollyJumper: public IOPipeline {
	public:
		JollyJumper():numInput_(0), inputArray_(nullptr), isJolly_(false) {

		}
		~JollyJumper () {
			delete inputArray_;
		}
		void readInput() {
			cin>>numInput_;
			inputArray_ = new int [numInput_];
			for ( int i=0;i<numInput_;i++ ) {
				 cin >> inputArray_[i];
			}
		}
		void processData () {
			bool exists[numInput_]={false};
			isJolly_=true;
			for ( int i=0; i<numInput_-1; i++ ) {
				int absDiff=abs( inputArray_[i]-inputArray_[i+1] );
				if ( absDiff <= 0 || absDiff >=numInput_ || exists[absDiff]==true )
					isJolly_ = false;
				exists[absDiff]=true;
			}
		
		}
		void writeOutput () {
			
			cout << numInput_<<" ";
			for ( int i=0;i<numInput_;i++ ) {
				cout<<inputArray_[i]<<" ";
			}
			cout<<endl;
			
			if ( isJolly_ )
				cout <<"Jolly"<<endl;
			else
				cout <<"Not Jolly"<<endl;
		}
	private:
		int numInput_;
		int *inputArray_;
		bool isJolly_;
};
