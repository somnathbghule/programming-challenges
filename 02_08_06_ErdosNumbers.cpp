#include <IOPipeline.h>

class ErdosNumbers : public IOPipeline {
		
		public:
			ErdosNumbers() {}
			~ErdosNumbers() {
				delete names_;
			}
			
			void processLine( string &line , int ind ) {
				string erdos="Erdos, P.";
				int len=line.length();
				string nameSegment;
				bool isFirstErdos=false;	
				bool isSecondErdos=false;	
				if ( line.find(erdos) != std::string::npos ) {
					isFirstErdos=true;
				}

				for ( int i=0; i< len; i++ ) {
					if ( line.at(i) == '.' && ( line.at(i+1)== ',' || line.at(i+1)== ':' ) ) {
						if ( line.at(i+1) == ',' || line.at(i+1)== ':' ) { //this is name segment
							nameSegment.push_back(line.at(i));
							//cout <<"nameSegment: "<<nameSegment<<endl;	
							names_[ind].push_back(nameSegment);
							if ( isFirstErdos && nameSegment != erdos ) {
								namesMap_.insert( {nameSegment, 1} );	
							} else if ( nameSegment != erdos ) {
								if ( isSecondErdos ) {
									namesMap_.insert( {nameSegment, 2} );
								}
								if ( namesMap_[ nameSegment ]  ) {
									isSecondErdos=true;
								}
							} 
							nameSegment.clear();
							i+=2; //next spaces  and ,
							continue;
						}	
					}
					nameSegment.push_back(line.at(i));					
				}
					
			}	
			virtual void readInput() {
				cin>>numberOfScenarios_;	
				cin>>numPaperDatabase_;
				cin>>numNames_;
				
				names_=new  vector <string> [ numPaperDatabase_ ];
				for ( int i=0;i<numPaperDatabase_;i++ ) {
					string line; //per line
					std::getline (std::cin, line);
					if ( line.length()==0 )
						std::getline (std::cin, line);
					processLine(line, i);
				}
				for ( int i=0; i<numNames_;i++ ) {
					string input;
					std::getline (std::cin, input);
					if ( namesMap_[ input ] ){
						cout <<input<<" "<<namesMap_[ input ]<<endl;
					} else {
						cout <<input <<" infinity"<<endl;
					}
				}

			}
			virtual void processData() {

			
			}
			virtual void writeOutput() {
				//cout <<"numberOfScenarios_: "<<numberOfScenarios_<<endl;
				//cout <<"numPaperDatabase_: "<<numPaperDatabase_<<endl;
				//cout <<"numNames_: "<<numNames_<<endl;
				//for (auto itr = namesMap_.begin(); itr != namesMap_.end(); ++itr) {
				//	cout <<"Names_: "<< "\""<<itr->first <<"\""<< '\t' << itr->second << '\n';
				//}
			}
		private:
			int numberOfScenarios_;
			int numPaperDatabase_;
			int numNames_;
			vector <string> *names_;
			map <string, int> namesMap_;
			vector <string> inputNames_;

};
