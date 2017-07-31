#import <iostream>
#import <string>

using namespace std;

const int RAM_SIZE = 1000;
const int REGISTER_SIZE = 10;

void ram_init(string []);
void register_init(string []);

void display_array(string [], int size);

int main()
{

	int case_numbers; // the number of cases
	int instruction_numbers; // the number of instructions
	string instruction = "000";
	string ram[RAM_SIZE]; // use string to determine leading 0 
	string registers[REGISTER_SIZE];

	scanf("%d", &case_numbers);

	//printf("case_numbers %d\n", case_numbers);


	cin.ignore(10, '\n'); // ignore a new line.
	cin.ignore(10, '\n');

	for (int i = 0; i < case_numbers; i++)
	{
		// init insturuction_number,  ram and register for each case
		instruction_numbers = 0;
		ram_init(ram);
		register_init(registers);
	
		getline(cin, instruction);
		while (instruction != "")
		{
			ram[instruction_numbers] = instruction;
			instruction_numbers++;	
		
			getline(cin, instruction);
		}

		cout << "test case is " << case_numbers << endl;
		display_array(ram, instruction_numbers);
		display_array(registers, REGISTER_SIZE);

	}

	return 0;

}

void ram_init(string ram[])
{
	for (int i = 0; i < RAM_SIZE; i++)
		ram[i] = "000";

}

void register_init(string registers[])
{
	for (int i = 0; i < REGISTER_SIZE; i++)
		registers[i] = "000";
}

void display_array(string array[], int size)
{
	for (int i = 0; i < size; i++)
		cout << array[i] << endl;

}

