#include <stdio.h>

#define ROMSIZE 128
#define RAMSIZE 124
#define IOSIZE 4
#define ROMSTARTADR 0
#define RAMSTARTADR 128
#define IOSTARTADR 252

class Core
{
	private:
		char* memory;
		unsigned char programCounter;
		
	public:
		Core()
		{
			memory = new char[ROMSIZE + RAMSIZE + IOSIZE]; 
			programCounter = 0;
		}
		
		void Update()
		{
			memory[memory[programCounter + 1]] = memory[memory[programCounter + 1]] - memory[memory[programCounter]];
			if(memory[memory[programCounter + 1]] <= 0)
				programCounter = memory[programCounter + 2];
			else 
				programCounter ++;
		}
		
		void Reset()
		{
			programCounter = 0;	
		}
		
		void SetRom(char* fData)
		{
			for(int i = ROMSTARTADR; i < ROMSIZE + ROMSTARTADR; i++)
				memory[i] = fData[i];
		}
		
		void PrintMemory()
		{
			for( int i = ROMSTARTADR; i < ROMSTARTADR + ROMSIZE; i++)
			{
				printf("\n****ROM*****\n");
				printf("%d : %d\n", i, memory[i]);
			}
			for( int i = RAMSTARTADR; i < RAMSTARTADR + RAMSIZE; i++)
			{
				printf("\n****RAM*****\n");
				printf("%d : %d\n", i, memory[i]);
			}
			for( int i = IOSTARTADR; i < IOSTARTADR + IOSIZE; i++)
			{
				printf("\n****IO*****\n");
				printf("%d : %d\n", i, memory[i]);
			}
		}
};

int main()
{
	Core core;
	core.SetRom();
	return 0;
}