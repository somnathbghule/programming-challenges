#ifndef StackThemUp_CPP
#define StackThemUp_CPP

#include <IOPipeline.h>
#define TOTAL_CARDS 52
#define NUM_OF_SUITS 4 //CLUBS DIAMONDS HEARTS SPADES  
#define NUM_OF_CARDS_PER_SUIT 13
static string suits[] = { " CLUBS",  "DIAMONDS", "HEARTS", "SPADES " };
static string  cardsPerSuit[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
class StackThemUp: public IOPipeline {
	public:
		StackThemUp( ): nTestCases_( 0 ), nShuffles_( 0 ) {
			initDeck();
		}
		virtual void readInput() {

			cin>>nTestCases_;
			cin>>nShuffles_;
			vShuffles_.push_back(*(new vector<int>));
			//1--52
			for ( int j=1; j<=nShuffles_; j++ ){
				vShuffles_.push_back(*(new vector<int>));
				vShuffles_[j].push_back(0);
				for( int i=1;i<=TOTAL_CARDS;i++ ) {
					int cardNumber=0;
					cin>>cardNumber;
					vShuffles_[j].push_back(cardNumber);
				}
			}
			//shuffles input
			for ( int j=0;j<nShuffles_;j++ ){
				int shuffles=0;
				cin>>shuffles;
				shuffles_.push_back(shuffles);
			}
			//cout<<shuffles_[0]<<endl;
			//cout<<shuffles_[1]<<endl;
		}

		void map(string destDeck[], int shuffle ){

			for ( int i=1;i<=TOTAL_CARDS; i++ ) {
				destDeck[i]=orgDeck_[vShuffles_[shuffle][i]];
			}
		}

		virtual void processData() {
			//map the data with input
			 string tempDeck[53];
			 for ( int j=0;j<nShuffles_;j++ ) {
			 	map(tempDeck, shuffles_[j]);
				for( int i=1;i<=TOTAL_CARDS;i++ ) orgDeck_[i]=tempDeck[i];
			 }

		}
		virtual void writeOutput() {
			//cout <<"nTestCases_: "<<nTestCases_<<endl;	
			//cout <<"nShuffles_: "<<nShuffles_<<endl;	
			showDeck();
		}
		void initDeck ()  {
			for ( int i=1; i<=TOTAL_CARDS; i++ ) {
				orgDeck_[i] = cardsPerSuit [ (i-1) % NUM_OF_CARDS_PER_SUIT ] + " of " + suits[  (i-1) / NUM_OF_CARDS_PER_SUIT ];
			}
		}
		void showDeck() {
			for ( int i=1;i<=TOTAL_CARDS;i++ )
				cout <<orgDeck_[i]<<endl;
		}
		~StackThemUp() {

		}
	private:
		string orgDeck_[53];
		int nTestCases_;
		int nShuffles_;
		vector <vector <int>> vShuffles_;
		vector <int> shuffles_;


};

#endif /* StackThemUp_cpp */
