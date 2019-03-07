extern double result;
double Div(double operand1, double oprand2)
{
	if (oprand2 != 0)
	{
		result = (double)operand1 / oprand2;
		return 0;
	}
	return -1;
}