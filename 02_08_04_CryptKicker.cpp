#ifndef CryptKicker_CPP
#define CryptKicker_CPP
#include <IOPipeline.h>
class CryptKicker : public IOPipeline {
	public:
		CryptKicker() { } 
		~CryptKicker() { } 
		virtual void readInput() { 
			cin >> numLowerCaseWords_;
			int i=0;
			while ( i < numLowerCaseWords_ ){
				string word;
				cin >> word;
				decryptedWords_.push_back( word );
				i++;
			}
			string line;
			while ( getline( std::cin, line) ) {
				if ( line.empty() )
					continue;
				encryptedLines_.push_back(line);
			}
		}
		virtual void processData() { }
		virtual void writeOutput() { }
	private:
		int numLowerCaseWords_;
		vecs decryptedWords_;
		vecs encryptedLines_;

};
#endif
