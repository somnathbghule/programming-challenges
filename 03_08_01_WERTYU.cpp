#ifndef WERTYU_CPP
#define WERTYU_CPP
#include <IOPipeline.h>

class WERTYU : public IOPipeline {
	public:
	WERTYU() {
		fstream KeyboardFile;
		KeyboardFile.open("WERTYU_Keyboard.txt", ios::in);
		if ( KeyboardFile.is_open() ) {
			string keys;
			while ( getline( KeyboardFile, keys )) {
				for ( unsigned int i=0; i<keys.length(); i++ ) {
					if( !isspace(keys.at(i) ) ) {
							keyboardWERTYU_.push_back( keys.at(i) );
					}
				}		
			}
		}
	}
	~WERTYU() { }
	void readInput() {
		getline(std::cin, input_);	
	}
	// Function to get the
	// index of an element
	int getIndex( vector<char> v, char K ) {
    		auto it = find(v.begin(),
                   v.end(), K);

    		// If element was found
    		if (it != v.end()) {
        		// calculating the index
        		// of K
        		int index = distance(v.begin(),
                             it);
			return index;
    		}
    		else {
       		 	// If the element is not
        		// present in the vector
			return -1;
    		}
	}
	void processData() {
		for ( unsigned ind=0; ind<input_.length(); ind++ ) {
			 int index=getIndex( keyboardWERTYU_, input_.at( ind ));
			 if ( index != -1 ) {
				output_.push_back(keyboardWERTYU_[index-1]);	 
			 }
			 if ( isspace ( input_.at( ind ) ) )
				 output_.push_back( ' ' );

		}

	}
	void writeOutput() {
		IOLOG(input_);
		IOLOG(output_);
	}
	private:
		string input_;
		string output_;
		vector <char> keyboardWERTYU_;
};
#endif
