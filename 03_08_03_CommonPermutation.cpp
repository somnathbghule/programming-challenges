#ifndef CommonPermutation_CPP
#define CommonPermutation_CPP
#include <IOPipeline.h>
class CommonPermutation: public IOPipeline {
	public:
		CommonPermutation() {}
		~CommonPermutation(){}
		virtual void readInput() {
			string line;
			while ( cin>>line  ) lines_.push_back(line);
			
		}
		virtual void processData() { }
		virtual void writeOutput() {
			for ( unsigned int i=0;i<lines_.size();i++ )
				cout<<lines_[i]<<endl;
		}
	private:
		vector <string> lines_;

};

#endif 
