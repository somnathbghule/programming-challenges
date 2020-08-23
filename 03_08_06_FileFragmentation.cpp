#ifndef FileFragmentation_CPP
#define FileFragmentation_CPP
#include <IOPipeline.h>
class FileFragmentation: public IOPipeline {
	public:
		virtual void readInput() {
			cin>>numberOfTestCases_;
			int i=0;
			while ( i < numberOfTestCases_ ) { 
				vector <string> testCase;
				string line;
				while ( getline( std::cin, line ) ) {
					if ( i == 0 && line.empty() && testCase.size() == 0 ) continue;
					if ( line.empty() ) break;
					testCase.push_back( line );
				}
				testCases_.push_back( testCase );
				i++;
			}
		}
                virtual void processData() {
		}
                virtual void writeOutput() {
		}
	private:
		int numberOfTestCases_;
		vector < vector <string> > testCases_; 
};
 
#endif
