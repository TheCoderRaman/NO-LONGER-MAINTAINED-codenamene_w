#pragma once

//random interval clock?

class clocks
{
	public:
		int frameCount;
		int interval;

		clocks()
		{
			frameCount = 0;
			interval = 0;
		}

		clocks(int i) //interval constructor
		{
			frameCount = 0;
			interval = i;
		}

		void increment()
		{
			if (frameCount == interval && interval != 0)
				reset();
			else
				frameCount++;
		}

		void reset()
		{
			frameCount = 0;
		}

		void set(int frame)
		{
			frameCount = frame;
		}

	private:
};