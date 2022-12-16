std::string TransferDecimalToAny(long long int number, const unsigned int& base)
{
	const char* DIGITS = "0123456789abcdefghijklmnopqrstuvwxyz";
	bool FlagInverse = false;
	std::string reversString, stringInBase;

	if (base < 2 || base > 36)
	{
		std::cout << "Error: основание должно быть от 2 до 36." << std::endl;
		return "-1";
	}
	if (number < 0)
	{
		FlagInverse = true;
		number *= -1;
	}

	stringInBase += DIGITS[number % base];
	number = number / base;
	while (number)
	{
		stringInBase += DIGITS[number % base];
		number = number / base;
	}

	if (FlagInverse == true)
		reversString = "-";

	for (int i = stringInBase.length() - 1; i >= 0; i--)
		reversString += stringInBase[i];

	return reversString;
}

int TransferBinaryToDecimal(string binary) 
{
	int count = 1;
	int digit = 0;
	for (int i = binary.size(); i > 0; i--, count *= 2)
	{
		if ((binary[i - 1] != '0') && (binary[i - 1] != '1'))
		{
			cout << "Ошибка ввода числа, не правильный формат" << endl;
			break;
		}
		if (binary[i - 1] == '1')
		{
			digit += count;
		}
	}
	return digit;
}

int encode(string num1c, string num2c, string num3c, string num4c)
{
	num1c = string(5 - num1c.size(), '0') + num1c;
	num2c = string(5 - num2c.size(), '0') + num2c;
	num3c = string(5 - num3c.size(), '0') + num3c;
	num4c = string(5 - num4c.size(), '0') + num4c;
	string numc = num1c + num2c + num3c + num4c;
	return TransferBinaryToDecimal(numc);
}

string decode(int decimal) 
{
	string numc = TransferDecimalToAny(decimal, 2);
	numc = string(20 - numc.size(), '0') + numc;
	return numc;
}


int main(void)
{
	
	int num1 = 13;
	int num2 = 21;
	int num3 = 12;
	int num4 = 15;
	string num1c = TransferDecimalToAny(num1, 2).c_str();
	string num2c = TransferDecimalToAny(num2, 2).c_str();
	string num3c = TransferDecimalToAny(num3, 2).c_str();
	string num4c = TransferDecimalToAny(num4, 2).c_str();
	int num = encode(num1c, num2c, num3c, num4c);
	cout << num << endl;
	string numc = decode(num);
	cout << numc << endl;
	string buffer;
	for (int i = 0; i < numc.size(); i++) 
	{
		buffer = buffer + numc[i];
		if ((i + 1) % 5 == 0) 
		{
			cout << TransferBinaryToDecimal(buffer) << endl;
			buffer = string();
		}
	}

	return 0;
}
