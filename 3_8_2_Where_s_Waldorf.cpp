#ifndef Waldorf_CPP
#define Waldorf_CPP
#include <IOPipeline.h>

class Waldorf : public IOPipeline {
	public:
		Waldorf():numberOfCases_(0) {
		}
		~Waldorf() {
		}
		virtual void readInput() {
			cin>>numberOfCases_;
			//IOLOG(numberOfCases_);
			//1 ≤ m, n ≤ 50
			cin>>row_;
			if ( row_ < 1 )
				cout<<"row is invalid."<<endl;
			cin>>col_;
			if ( col_ > 50 )
				cout<<"col is invalid."<<endl;
			gridOfLetters_ = new char* [ row_ ];
			for ( int r=0; r<row_; r++ ) {
				gridOfLetters_ [r] = new char [col_];
				for ( int c=0; c<col_; c++ ){
					cin>>gridOfLetters_[r][c];
				}
			}

			//1 ≤ k ≤ 20
			cin>>numOfWords_;
			
			if ( numOfWords_ < 1 && numOfWords_ > 20 )
				cout <<" numOfWords_ is invalid."<<endl;

			listOfWords_=new string[ numOfWords_ ];
			for ( int i=0;i<numOfWords_;i++ ){
				cin>>listOfWords_[i];
			}
		}
		virtual void processData() {
		
		}
		virtual void writeOutput() {
		
		}
	private:
		int numberOfCases_;
		int row_; //m
		int col_; //n
		char **gridOfLetters_;
		int numOfWords_;
		string *listOfWords_;
};

#endif
