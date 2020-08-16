#ifndef Waldorf_CPP
#define Waldorf_CPP
#include <IOPipeline.h>

#define CMP_CHAR(c1, c2) ( toupper(c1)==c2 || tolower(c1)==c2 )

enum directions {
	NORTH,
	NORTH_EAST,
	EAST,
	EAST_SOUTH,
	SOUTH,
	SOUTH_WEST,
	WEST,
	WEST_NORTH,
	DIRECTIONS_MAX		
};
int dir[DIRECTIONS_MAX][2][2]={ {-1, 0}, {-1, 1}, {0, 1}, {1,1}, {1,0}, { 1,-1 }, {0, -1}, {-1,-1} };
class Waldorf : public IOPipeline {
	public:
		Waldorf():numberOfCases_(0) {
		}
		~Waldorf() {
		}
		virtual void readInput() {
			cin>>numberOfCases_;
			//IOLOG(numberOfCases_);
			//1 ≤ m, n ≤ 50
			cin>>row_;
			if ( row_ < 1 )
				cout<<"row is invalid."<<endl;
			cin>>col_;
			if ( col_ > 50 )
				cout<<"col is invalid."<<endl;
			gridOfLetters_ = new char* [ row_ ];
			for ( int r=0; r<row_; r++ ) {
				gridOfLetters_ [r] = new char [col_];
				for ( int c=0; c<col_; c++ ){
					cin>>gridOfLetters_[r][c];
				}
			}

			//1 ≤ k ≤ 20
			cin>>numOfWords_;
			
			if ( numOfWords_ < 1 && numOfWords_ > 20 )
				cout <<" numOfWords_ is invalid."<<endl;

			listOfWords_=new string[ numOfWords_ ];
			for ( int i=0;i<numOfWords_;i++ ){
				cin>>listOfWords_[i];
			}
		}

		bool visitGridByDirection( int row=0, int col=0, directions d=SOUTH, int w=0 ) {
			int r=dir[d][0][0];				
			int c=dir[d][0][1];				
			int i=row;
			int j=col;
			unsigned int ind=0;

			do {
				do {
					if ( ind == (listOfWords_[w]).length() )
						return true;
					if ( !CMP_CHAR( gridOfLetters_[i][j] , listOfWords_[w].at(ind)) ){
						return false;
					}
					ind++;
					j+=c;
				} while ( j<col_ && j!=-1 && r!=c && r!=-1 && c!=0 ); //col
				i+=r;
			} while ( i < row_ && j<col_  && i!=-1 ); //row
		
			return ( ind == (listOfWords_[w]).length() );
		}

		virtual void processData() {
			
			bool result=false;
			for ( int w=0; w<numOfWords_; w++ ){ //number of words;
				result=false;
				for ( int i=0;i<row_ && !result ;i++ ){ //grid row
					for ( int j=0; j< col_ && !result ;j++){ //grid col
						for ( int dir=0;!result && dir<DIRECTIONS_MAX && CMP_CHAR(gridOfLetters_[i][j], (listOfWords_[w]).at(0))   ;dir++ ) {	//directions							
							directions d=(directions)dir;
							result=visitGridByDirection( i, j, d, w );
							if ( result ) {
								cout<<i+1<<" "<<j+1<<endl;
							}
						}
					}
				}
			}
			
		}
		virtual void writeOutput() {
		}
	private:
		int numberOfCases_;
		int row_; //m
		int col_; //n
		char **gridOfLetters_;
		int numOfWords_;
		string *listOfWords_;
};

#endif
