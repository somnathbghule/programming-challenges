#ifndef Doublets_CPP
#define Doublets_CPP
#include <IOPipeline.h>
class Doublets : public IOPipeline {
	public:	
		Doublets() { }
		~Doublets() { }
		virtual void readInput() {
			string line;
			while ( getline(std::cin, line) ){
				if ( line.empty() )
					break;
				numberOfWords_.push_back(line);
			}
			while ( cin>>line )
				pairOfWords_.push_back(line);
		}
		virtual void processData() {
		}
		virtual void writeOutput() {
		}
	private:
		vector <string> numberOfWords_;
		vector <string> pairOfWords_;
};

#endif
