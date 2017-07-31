#import <iostream>
#import <string>

using namespace std;

const int RAM_SIZE = 1000;
const int REGISTER_SIZE = 10;

void ram_init(string []);
void register_init(string []);

int process_instuructions(string [], string []);
string int_to_string(int);
int string_to_int(string);


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

		//cout << "test case is " << case_numbers << endl;
		//display_array(ram, instruction_numbers);
		//display_array(registers, REGISTER_SIZE);

		int processed_number =  process_instuructions(ram, registers);

		cout << processed_number << endl;
		if (i < case_numbers-1)
			cout << endl; // make blank line if it's not last case
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

// to adjust with leading 0s
string int_to_string(int x)
{
	string str = "000";

	str[2] = x % 10 + '0'; // +'0' is to make char type
	x /= 10; // chop off last digit
	str[1] = x % 10 + '0';
	x /= 10;
	str[0] = x % 10 + '0';

	return str;
}

int string_to_int(string str)
{
	int num;

	num = (str[0] - '0') * 100;
	num += (str[1] - '0') * 10;
	num += (str[2] - '0') * 1;
		
	return num;
}
int process_instuructions(string ram[], string registers[])
{
	int processed_count = 0; // indicate the number of processed instruction
	int processing_number = 0; // indicate the number of processing instruction
	bool halt = false;

	while (!halt)
	{
		processed_count++;

		// I prefer if instend of using swich

		if (ram[processing_number][0] == '1')
		{
			halt = true;
			continue; // to skip rest of case
		}

		if (ram[processing_number][0] == '2')
		{
			int reg = ram[processing_number][1] - '0';
			int num = ram[processing_number][2] - '0';

			registers[reg] = int_to_string(num);

			processing_number++; // process next instruction
			continue;
		}

		if (ram[processing_number][0] == '3')
		{
			int reg = ram[processing_number][1] - '0';
			int num = ram[processing_number][2] - '0';
			
			registers[reg] = int_to_string((string_to_int(registers[reg]) + num) % 1000);

			processing_number++;
			continue;
		}

		if (ram[processing_number][0] == '4')
		{
			int reg = ram[processing_number][1] - '0';
			int num = ram[processing_number][2] - '0';

			registers[reg] = int_to_string((string_to_int(registers[reg]) * num) % 1000);

			processing_number++;
			continue;
		}

		if (ram[processing_number][0] == '5')
		{
			int reg1 = ram[processing_number][1] - '0';
			int reg2 = ram[processing_number][2] - '0';

			registers[reg1] = registers[reg2];
			processing_number++;
			continue;
		}
		if (ram[processing_number][0] == '6')
		{
			int reg1 = ram[processing_number][1] - '0';
			int reg2 = ram[processing_number][2] - '0';

			registers[reg1] = int_to_string((string_to_int(registers[reg1]) + string_to_int(registers[reg2])) % 1000);
			
			processing_number++;
			continue;
		}


		if (ram[processing_number][0] == '7')
		{
			int reg1 = ram[processing_number][1] - '0';
			int reg2 = ram[processing_number][2] - '0';

			registers[reg1] = int_to_string((string_to_int(registers[reg1]) * string_to_int(registers[reg2])) % 1000);
			
			processing_number++;
			continue;
	
		}
		if (ram[processing_number][0] == '8')
		{
			int reg1 = ram[processing_number][1] - '0';
			int reg2 = ram[processing_number][2] - '0';

			registers[reg1] = ram[string_to_int(registers[reg2])];
			processing_number++;
			continue;
		}


		if (ram[processing_number][0] == '9')
		{
			int reg1 = ram[processing_number][1] - '0';
			int reg2 = ram[processing_number][2] - '0';

			ram[string_to_int(registers[reg2])] = registers[reg1];

			processing_number++;
			continue;
		}
		if (ram[processing_number][0] == '0')
		{
			int reg1 = ram[processing_number][1] - '0';
			int reg2 = ram[processing_number][2] - '0';

			if (string_to_int(registers[reg2]) != 0)	
				processing_number = string_to_int(registers[reg1]);
			else	
				processing_number++;	
			continue;
		}
	}

	return processed_count;
}
