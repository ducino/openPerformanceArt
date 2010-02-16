#ifndef _OUTPUT_H
#define _OUTPUT_H

class Output {

	public:
		Output();
		~Output();

		virtual void trigger()=0;
};

#endif
