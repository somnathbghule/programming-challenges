#ifndef PokerHands_CPP
#define PokerHands_CPP
#include <IOPipeline.h>

class PokerHands: public IOPipeline {
		public:
			PokerHands() { }
			~PokerHands() { }
			virtual void readInput() {
				string line;
				while (getline(cin, line)) {
					inputLines_.push_back(line);
				}
			}
			virtual void processData() {
			}
			virtual void writeOutput() {
				IOLOG(inputLines_.size());	
			}
		private:
			vector <string> inputLines_;

};

#endif

