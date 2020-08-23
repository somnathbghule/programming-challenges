#ifndef AutomatedJudgeScript_CPP
#define AutomatedJudgeScript_CPP
#include <IOPipeline.h>

class AutomatedJudgeScript : public IOPipeline  {
		struct Input {
					Input():numCorrectSolution_( 0 ),numSubmittedSolution_( 0 ) {
				
				}
				int numCorrectSolution() { return numCorrectSolution_; }
				void numCorrectSolution( int numCorrectSolution ) { numCorrectSolution_=numCorrectSolution; }
				vector <string> correctSolution() { return correctSolution_; }
				void correctSolution( vector <string> correctSolution ) { correctSolution_=correctSolution; }

				int numSubmittedSolution() { return numSubmittedSolution_; }
				void numSubmittedSolution( int numSubmittedSolution ) { numSubmittedSolution_=numSubmittedSolution; }
				vector <string> submittedSolution() { return submittedSolution_; }
				void submittedSolution( vector <string> submittedSolution ) { submittedSolution_=submittedSolution; }
			private:
				int numCorrectSolution_;
				vector <string> correctSolution_;
				int numSubmittedSolution_;
				vector <string> submittedSolution_;
		};
	public:
                virtual void readInput() {
			        
			while ( 1  ) {
					int i=0;
					int numCorrectSolution;
					cin >> numCorrectSolution;
					if ( !numCorrectSolution ) 
						break;
                                	vector <string> correctSolution;
					while ( i < numCorrectSolution ){
						string line;
						getline( std::cin, line );
						if ( line.empty() )
							continue;
						correctSolution.push_back( line );
						i++;
					}
                                	
					int numSubmittedSolution;
                                	vector <string> submittedSolution;
					cin >> numSubmittedSolution;
					i=0;
					while ( i < numSubmittedSolution ){
						string line;
						getline( std::cin, line );
						if ( line.empty() )
							continue;
						submittedSolution.push_back( line );
						i++;
					}
					Input in;
					in.numSubmittedSolution( numSubmittedSolution );
					in.submittedSolution( submittedSolution );
					in.numCorrectSolution( numCorrectSolution );
					in.correctSolution( correctSolution );
					inputs_.push_back( in );
				}

		}
                virtual void processData() {
		
		}
                virtual void writeOutput() {
		
		}
	private:
		vector <Input> inputs_;
		vector <string> output_;

};

#endif
