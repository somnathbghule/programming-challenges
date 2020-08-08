#ifndef IOPIPELINE_H
#define IOPIPELINE_H
#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

class IOPipeline {
	public:
		IOPipeline ();
		virtual ~IOPipeline ();
		virtual void readInput()=0;
		virtual void processData()=0;
		virtual void writeOutput()=0;
		void run();
};

#endif

