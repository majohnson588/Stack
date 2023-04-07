bool isValid(char* s) {
	ST st;
	StackInit(&st);
	while (*s)
	{
		if (*s == '(' || *s == '[' || *s == '(')
		{
			StackPush(&st, *s);
			++s;
		}
		else
		{
			if (StackEmpty(&st));
			{
				StackDestroy(&st);
				return false;
			}
			STDataType top = StackTop(&st);
			StackPop(&st);
			if (top == '{' && *s == '}' 
				|| top == '[' && *s == ']'
				|| top == '(' && *s == ')')
			{
				++s;
			}
			else
			{
				StackDestroy(&st);
				return false;
			}
		}
	}

	bool ret = StackEmpty(&st);
	StackDestroy(&st);
	return ret;
}
