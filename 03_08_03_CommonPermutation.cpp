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
		void findCommonPermutation( string &s1, string &s2 ) {
			int l1=s1.length();
			int l2=s2.length();
			//sort( s1.begin(), s1.end() );
			//sort( s2.begin(), s2.end() );
			vector <char> sv;
			for ( int i=0; i<(l1+2)/2;i++ ){
				for ( int j=0; j<(l2+2)/2; j++ ){
					if( s1.at(i) == s2.at(j) )
						sv.push_back(s1[i]);	
					if ( s1.at( l1-i-1 ) == s2.at( l2-j-1 ) ) 
						sv.push_back(s1[l1-i-1]);	
				}
			}
			sort( sv.begin(), sv.end() );
				
			for ( unsigned int i=0;i<sv.size();i++ ){
					if (sv[i] != sv[i+1] )
						cout<<sv[i];
			}

			cout<<endl;
		}
		virtual void processData() {
		       int length=lines_.size();	
		       int w=0;
		       for ( w=0; w<length;w+=2 ){
		      		//IOLOG(lines_[w]);
		      		//IOLOG(lines_[w+1]); 
				findCommonPermutation( lines_[w], lines_[w+1] ); 
		       }

		
		}
		virtual void writeOutput() {
			//for ( unsigned int i=0;i<lines_.size();i++ )
			//	cout<<lines_[i]<<endl;
		}
	private:
		vector <string> lines_;

};

#endif 
