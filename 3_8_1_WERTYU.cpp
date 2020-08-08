#ifndef WERTYU_CPP
#define WERTYU_CPP
#include <IOPipeline.h>
class WERTYU : public IOPipeline {
	public:
	void readInput() {
		getline(std::cin, input_);	
	}
	void processData() {
	}
	void writeOutput() {
		cout<<"input_ "<<input_<<endl;
	}
	private:
		string input_;
		string output_;
};
#endif
