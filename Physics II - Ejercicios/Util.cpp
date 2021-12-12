#include"Util.h"

namespace E3D {
	ofstream* GLogStream = NULL;
	bool InitLog(const EString& fileName) {
		if (GLogStream = NULL) {
			GLogStream = new ofstream;
			GLogStream->open(fileName.c_str());
			if (GLogStream->good()) {
				return true;
			}
			return false;
		}
		return true;
	}
	void Log(const EChar* string, ...) {
		if (GLogStream == NULL) {
			return;
		}
		EChar buffer[256];
		if (!string || !GLogStream) {
			return;
		}
		va_list arglist;
		va_start(arglist, string);
		vsprintf(buffer, string, arglist);
		va_end(arglist);
		EString info(buffer);
		*GLogStream << info << endl;
		GLogStream->flush();
		
	}
	void CloseLog() {
		GLogStream->close();
		SafeDelete(GLogStream);
	}
}