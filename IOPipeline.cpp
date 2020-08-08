#include <02_08_01_JollyJumper.cpp>
#include <02_08_05_StackThemUp.cpp>
#include <2_8_6_ErdosNumbers.cpp>
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
	IOPipeline *io=new ErdosNumbers();
	io->run();
	return 0;
}
