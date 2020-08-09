#ifndef CryptKickerII_CPP
#define CryptKickerII_CPP

#include <IOPipeline.h>

class CryptKickerII : public IOPipeline {
	public:
		virtual void readInput() {
			cin>>numberOfTestCases_;
			string line;
			while ( getline( std::cin, line ) &&  linesOfInput_.size() <= 100 ) {
				if ( line.size() && line.length() <= 80 )
					linesOfInput_.push_back(line);
			}
		
		}
		virtual void processData() {
		
		}
		virtual void writeOutput() {
			IOLOG(numberOfTestCases_);
			for (unsigned int i=0;i<linesOfInput_.size();i++)
				IOLOG(linesOfInput_[i]);
		
		}
	
	private:
		int numberOfTestCases_;
		vector <string> linesOfInput_;

};

#endif 
