#include <02_08_01_JollyJumper.cpp>
#include <02_08_05_StackThemUp.cpp>
#include <02_08_06_ErdosNumbers.cpp>
#include <03_08_01_WERTYU.cpp>
#include <03_08_02_Where_s_Waldorf.cpp>
#include <03_08_03_CommonPermutation.cpp>
#include <03_08_04_CryptKickerII.cpp>
#include <02_08_02_PokerHands.cpp>
#include <02_08_03_Hartals.cpp>
#include <03_08_05_AutomatedJudgeScript.cpp>
#include <03_08_06_FileFragmentation.cpp>
#include <03_08_07_Doublets.cpp>
#include <02_08_04_CryptKicker.cpp>
IOPipeline::IOPipeline () {}
IOPipeline::~IOPipeline () {}
void IOPipeline::readInput() {}
void IOPipeline::processData() {}
void IOPipeline::writeOutput() {}
void IOPipeline::run() {
	readInput();
	processData();
	writeOutput();
}
int main (int argc , char **argv) {
	IOPipeline *io=new CryptKicker();
	io->run();
	return 0;
}
